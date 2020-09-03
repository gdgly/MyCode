
#include "ninebot_protocol.h"

const unsigned char AUTH_PARAM[16] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

PARSE_RETURN parse_to_frame_struct(PARSE_STRUCT *parse_s);
int check_frame(PARSE_STRUCT *parse_s, uint8_t *frame_buffer, uint16_t frame_len);

void set_id(PARSE_STRUCT *parse_s, uint8_t local, uint8_t target)
{
    parse_s->id_local = local;
    parse_s->id_target = target;
}
PARSE_RETURN parse_struct_init(PARSE_STRUCT *parse_s)
{
    parse_s->sta = NOHEAD;
    parse_s->frame_cnt = 0;
    parse_s->frame_data_len = 0;
    parse_s->frame_len = 0;
    parse_s->version = 0;
    parse_s->rec_frame_cb = NULL;
    //parse_s->frame_buffer = NULL;

#ifdef SUPPORT_TO_CRYPTO

    parse_s->crypto_param_tx.param1 = NULL;
    parse_s->crypto_param_tx.param2 = NULL;

    parse_s->crypto_param_rx.param1 = NULL;
    parse_s->crypto_param_rx.param2 = NULL;

    nb_crypto_board_init(&parse_s->crypto_param_tx, (unsigned char *)AUTH_PARAM);
    nb_crypto_board_init(&parse_s->crypto_param_rx, (unsigned char *)AUTH_PARAM);

#ifdef ENABLE_ANTI_REPLAY

    nb_crypto_board_start_once_sn(&parse_s->crypto_param_tx);
    nb_crypto_board_start_once_sn(&parse_s->crypto_param_rx);

#endif

#endif

    return PARSE_OK;
}

void parse_set_send_fun(PARSE_STRUCT *parse_s, send_frame_fun send_frame_fun)
{
    parse_s->frame_s.send_frame_fun = send_frame_fun;
}

void frame_set_send_fun(FRAME_STRUCT *frame_s, send_frame_fun send_frame_fun)
{
    frame_s->send_frame_fun = send_frame_fun;
}

void parse_set_rec_callback(PARSE_STRUCT *parse_s, rec_frame_callback rec_frame_cb)
{
    parse_s->rec_frame_cb = rec_frame_cb;
}

void reset_frame(PARSE_STRUCT *parse_s, uint8_t recv)
{
    if (recv == VERSION_HEAD)
    {
        parse_s->sta = GETHEAD;
        parse_s->frame_cnt = 0;
        parse_s->frame_data_len = 0;
        parse_s->version = 0;
    }
    else
    {
        parse_s->sta = NOHEAD;
    }
}

void parse_data(PARSE_STRUCT *parse_s, uint8_t *receive_buffer, uint16_t receive_len)
{
    uint16_t data_cnt = 0;
    uint8_t is_tracker_version = 0;
    for (; data_cnt < receive_len; data_cnt++)
    {
        switch (parse_s->sta)
        {
        //NOHEAD
        case NOHEAD:
            if (receive_buffer[data_cnt] == VERSION_HEAD)
            {
                parse_s->sta = GETHEAD;
                parse_s->frame_cnt = 0;
                parse_s->frame_data_len = 0;
                parse_s->version = 0;
            }

            break;
        //GETHEAD
        case GETHEAD:
#ifdef SUPPORT_TO_OLD
            if (receive_buffer[data_cnt] == OLD_PROTOCOL_VERSION)
            {
                parse_s->sta = GETVERSION;
                parse_s->version = OLD_PROTOCOL_VERSION;
            }
            else
#endif
#ifdef SUPPORT_TO_TWO_BYTES_LENGTH
			if (receive_buffer[data_cnt] == NEW_PROTOCOL_VERSION)
            {
                parse_s->sta = GETVERSION;
                parse_s->version = NEW_PROTOCOL_VERSION;
            }
            else
#endif
#ifdef SUPPORT_TO_CRYPTO
			if (receive_buffer[data_cnt] == CRYPTO_PROTOCOL_VERSION)
			{
                parse_s->sta = GETVERSION;
                parse_s->version = CRYPTO_PROTOCOL_VERSION;
            }
            else
#endif

            {
                reset_frame(parse_s, receive_buffer[data_cnt]);
            }
            break;
        //GETVERSION
        case GETVERSION:
#if defined(SUPPORT_TO_OLD) || defined(SUPPORT_TO_CRYPTO)
            if (parse_s->version == OLD_PROTOCOL_VERSION || parse_s->version == CRYPTO_PROTOCOL_VERSION)
            {
                parse_s->frame_data_len = receive_buffer[data_cnt];

                if ((parse_s->frame_data_len + 11) <= sizeof(parse_s->frame_buffer))
                {
                    *(parse_s->frame_buffer + 0) = VERSION_HEAD;
                    *(parse_s->frame_buffer + 1) = parse_s->version;
                    *(parse_s->frame_buffer + 2) = receive_buffer[data_cnt];
                    parse_s->sta = GETLEN;
                }
                else
                {
                    parse_s->sta = NOHEAD;
                }
            }
            else
#endif

#ifdef SUPPORT_TO_TWO_BYTES_LENGTH
			if (parse_s->version == NEW_PROTOCOL_VERSION)
            {
                parse_s->frame_data_len = receive_buffer[data_cnt];
                parse_s->sta = GETLENHALF;
            }
            else
#endif
            {
                reset_frame(parse_s, receive_buffer[data_cnt]);
            }
            break;
        //GETLENHALF
        case GETLENHALF:
#ifdef SUPPORT_TO_TWO_BYTES_LENGTH
            if (parse_s->version == NEW_PROTOCOL_VERSION)
            {
                parse_s->frame_data_len |= (uint16_t)(receive_buffer[data_cnt] << 8);

                if (parse_s->frame_data_len > FRAME_MAX)
                {
                    parse_s->sta = NOHEAD;
                }
                else
                {
                    if ((parse_s->frame_data_len + 11) <= sizeof(parse_s->frame_buffer))
                    {
                        *(parse_s->frame_buffer + 0) = VERSION_HEAD;
                        *(parse_s->frame_buffer + 1) = NEW_PROTOCOL_VERSION;
                        *(parse_s->frame_buffer + 2) = (uint8_t)(parse_s->frame_data_len);
                        *(parse_s->frame_buffer + 3) = receive_buffer[data_cnt];

                        parse_s->sta = GETLEN;
                    }
                    else
                    {
                        parse_s->sta = NOHEAD;
                    }
                }
            }
            else
#endif
            {
                reset_frame(parse_s, receive_buffer[data_cnt]);
            }
            break;
        //GETLEN
        case GETLEN:

#if defined(SUPPORT_TO_OLD) || defined(SUPPORT_TO_CRYPTO)
            if (parse_s->version == OLD_PROTOCOL_VERSION || parse_s->version == CRYPTO_PROTOCOL_VERSION || parse_s->version == TRACKER_VERSION)
            {

                *(parse_s->frame_buffer + 3 + parse_s->frame_cnt) = receive_buffer[data_cnt];
                parse_s->frame_cnt++;

                if (parse_s->frame_cnt >= (parse_s->frame_data_len + 6 - is_tracker_version))
                {

                    if (check_frame(parse_s, parse_s->frame_buffer + 2, (parse_s->frame_data_len + 7 - is_tracker_version)) == 0)
                    {

                        parse_s->frame_len = parse_s->frame_data_len + 9 - is_tracker_version;
                        parse_to_frame_struct(parse_s);

                        if (parse_s->rec_frame_cb != NULL)
                        {

                            parse_s->rec_frame_cb();
                        }
                        parse_s->sta = NOHEAD;
                    }
                    else
                    {
                        reset_frame(parse_s, receive_buffer[data_cnt]);
                    }
                }
            }
            else
#endif
#ifdef SUPPORT_TO_TWO_BYTES_LENGTH
			if (parse_s->version == NEW_PROTOCOL_VERSION)
            {
                *(parse_s->frame_buffer + 4 + parse_s->frame_cnt) = receive_buffer[data_cnt];
                parse_s->frame_cnt++;

                if (parse_s->frame_cnt >= parse_s->frame_data_len + 7)
                {

                    if (check_frame(parse_s, parse_s->frame_buffer + 2, parse_s->frame_data_len + 9) == 0)
                    {

                        parse_s->frame_len = parse_s->frame_data_len + 11;
                        parse_to_frame_struct(parse_s);

                        if (parse_s->rec_frame_cb != NULL)
                        {
                            parse_s->rec_frame_cb(NULL);
                        }

                        parse_s->sta = NOHEAD;
                    }
                    else
                    {
                        reset_frame(parse_s, receive_buffer[data_cnt]);
                    }
                }
            }
            else
#endif
            {
                reset_frame(parse_s, receive_buffer[data_cnt]);
            }

            break;

        default:
            reset_frame(parse_s, receive_buffer[data_cnt]);
            break;
        }
    }
}

int check_frame(PARSE_STRUCT *parse_s, uint8_t *frame_buffer, uint16_t frame_len)
{
    uint16_t frame_cnt = 0;
    uint16_t check_sum = 0;
    uint8_t check_sum_low = 0, check_sum_high = 0;

    {
        for (frame_cnt = 0; frame_cnt < frame_len - 2; frame_cnt++)
        {
            check_sum += frame_buffer[frame_cnt];
        }

        check_sum = ~check_sum;

        check_sum_low = (uint8_t)check_sum;
        check_sum_high = (uint8_t)(check_sum >> 8);

        if (check_sum_low == frame_buffer[frame_len - 2] && check_sum_high == frame_buffer[frame_len - 1])
        {
            return 0;
        }
        else
        {
            return -1;
        }
    }
}

PARSE_RETURN parse_to_frame_struct(PARSE_STRUCT *parse_s)
{
    uint16_t count = 3;

    parse_s->frame_s.Version = parse_s->version;
    parse_s->frame_s.FrameDataLen = parse_s->frame_data_len;

    if (parse_s->version == NEW_PROTOCOL_VERSION)
    {
        count++;
    }

    {
        parse_s->frame_s.SourceID = parse_s->frame_buffer[count++];
        parse_s->frame_s.TargetID = parse_s->frame_buffer[count++];
    }
    parse_s->frame_s.Cmd = parse_s->frame_buffer[count++];
    parse_s->frame_s.DataIndex = parse_s->frame_buffer[count++];

    if (parse_s->version == NEW_PROTOCOL_VERSION)
    {
        parse_s->frame_s.DataIndex |= (parse_s->frame_buffer[count++] << 8);
    }

#ifdef SUPPORT_TO_CRYPTO
    if (parse_s->frame_s.Version == CRYPTO_PROTOCOL_VERSION)
    {
#ifndef DECRYPTO_ALL_PACKAGE
        if (parse_s->frame_s.TargetID == parse_s->id_local)
#endif
        {
            uint8_t ret = nb_crypto_board_decrypt(&parse_s->crypto_param_rx,
                                                  &(parse_s->frame_buffer[5]),
                                                  parse_s->frame_s.FrameDataLen + 2,
                                                  parse_s->crypto_buf_rx,
                                                  (uint8_t *)&parse_s->frame_s.FrameDataLen);
            if (ret == 0)
            {
                memcpy(parse_s->frame_buffer + count - 2, parse_s->crypto_buf_rx, parse_s->frame_s.FrameDataLen);
                parse_s->frame_s.FrameDataLen -= 2;
                parse_s->frame_s.Cmd = parse_s->frame_buffer[count - 2];
                parse_s->frame_s.DataIndex = parse_s->frame_buffer[count - 1];
            }
            else if (ret == 1)
            {
                //Log("N_CRYPTO_AUTH_ERR\r\n");
                return PARSE_FAIL;
            }
            else if (ret == 2)
            {
                //Log("N_CRYPTO_ONCE_SN_ERR\r\n");
                return PARSE_FAIL;
            }
        }
    }
#endif
    parse_s->frame_s.frame_data = parse_s->frame_buffer + count;

    return PARSE_OK;
}
