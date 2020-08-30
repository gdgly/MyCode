
#include "ninebot_protocol.h"

const unsigned char AUTH_PARAM[16] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

PARSE_RETURN parse_to_rx_frametruct(NB_BUS_TYPE *nb_bus_t);
int check_frame(NB_BUS_TYPE *nb_bus_t, uint8_t *frame_buffer, uint16_t frame_len);


PARSE_RETURN parse_struct_init(NB_BUS_TYPE *nb_bus_t)
{
    nb_bus_t->sta = NOHEAD;
    nb_bus_t->frame_cnt = 0;
    nb_bus_t->frame_data_len = 0;
    nb_bus_t->frame_len = 0;
    nb_bus_t->version = 0;
    
    nb_bus_t->rec_frame_cb = NULL;  //后续再初始化


    return PARSE_OK;
}

void parse_set_send_fun(NB_BUS_TYPE *nb_bus_t, SEND_FREAM_FUNC_T send_frame_fun)
{
    nb_bus_t->frame.send_frame_fun = send_frame_fun;
}

void rx_frameet_send_fun(FRAME_TYPE *frame, SEND_FREAM_FUNC_T send_frame_fun)
{
    frame->send_frame_fun = send_frame_fun;
}

void parse_set_rec_callback(NB_BUS_TYPE *nb_bus_t, REC_FRAME_CB_T rec_frame_cb)
{
    nb_bus_t->rec_frame_cb = rec_frame_cb;
}

void reset_frame(NB_BUS_TYPE *nb_bus_t, uint8_t recv)
{
    if (recv == VERSION_HEAD)
    {
        nb_bus_t->sta = GETHEAD;
        nb_bus_t->frame_cnt = 0;
        nb_bus_t->frame_data_len = 0;
        nb_bus_t->version = 0;
    }
    else
    {
        nb_bus_t->sta = NOHEAD;
    }
}

void parse_data(NB_BUS_TYPE *nb_bus_t, uint8_t *receive_buffer, uint16_t receive_len)
{
    uint16_t data_cnt = 0;
    uint8_t is_tracker_version = 0;
    for (; data_cnt < receive_len; data_cnt++)
    {
        switch (nb_bus_t->sta)
        {
        //NOHEAD
        case NOHEAD:
            if (receive_buffer[data_cnt] == VERSION_HEAD)
            {
                nb_bus_t->sta = GETHEAD;
                nb_bus_t->frame_cnt = 0;
                nb_bus_t->frame_data_len = 0;
                nb_bus_t->version = 0;
            }

            break;
        //GETHEAD
        case GETHEAD:
#ifdef SUPPORT_ONE_BYTE
            if (receive_buffer[data_cnt] == OLD_PROTOCOL_VERSION)
            {
                nb_bus_t->sta = GETVERSION;
                nb_bus_t->version = OLD_PROTOCOL_VERSION;
            }
            else
#endif
#ifdef SUPPORT_TWO_BYTES
			if (receive_buffer[data_cnt] == NEW_PROTOCOL_VERSION)
            {
                nb_bus_t->sta = GETVERSION;
                nb_bus_t->version = NEW_PROTOCOL_VERSION;
            }
            else
#endif

            {
                reset_frame(nb_bus_t, receive_buffer[data_cnt]);
            }
            break;
        //GETVERSION
        case GETVERSION:
#if defined(SUPPORT_ONE_BYTE)
            if (nb_bus_t->version == OLD_PROTOCOL_VERSION)
            {
                nb_bus_t->frame_data_len = receive_buffer[data_cnt];

                if ((nb_bus_t->frame_data_len + 11) <= sizeof(nb_bus_t->frame_buffer))
                {
                    *(nb_bus_t->frame_buffer + 0) = VERSION_HEAD;
                    *(nb_bus_t->frame_buffer + 1) = nb_bus_t->version;
                    *(nb_bus_t->frame_buffer + 2) = receive_buffer[data_cnt];
                    nb_bus_t->sta = GETLEN;
                }
                else
                {
                    nb_bus_t->sta = NOHEAD;
                }
            }
            else
#endif

#ifdef SUPPORT_TWO_BYTES
			if (nb_bus_t->version == NEW_PROTOCOL_VERSION)
            {
                nb_bus_t->frame_data_len = receive_buffer[data_cnt];
                nb_bus_t->sta = GETLENHALF;
            }
            else
#endif
            {
                reset_frame(nb_bus_t, receive_buffer[data_cnt]);
            }
            break;
        //GETLENHALF
        case GETLENHALF:
#ifdef SUPPORT_TWO_BYTES
            if (nb_bus_t->version == NEW_PROTOCOL_VERSION)
            {
                nb_bus_t->frame_data_len |= (uint16_t)(receive_buffer[data_cnt] << 8);

                if (nb_bus_t->frame_data_len > FRAME_MAX)
                {
                    nb_bus_t->sta = NOHEAD;
                }
                else
                {
                    if ((nb_bus_t->frame_data_len + 11) <= sizeof(nb_bus_t->frame_buffer))
                    {
                        *(nb_bus_t->frame_buffer + 0) = VERSION_HEAD;
                        *(nb_bus_t->frame_buffer + 1) = NEW_PROTOCOL_VERSION;
                        *(nb_bus_t->frame_buffer + 2) = (uint8_t)(nb_bus_t->frame_data_len);
                        *(nb_bus_t->frame_buffer + 3) = receive_buffer[data_cnt];

                        nb_bus_t->sta = GETLEN;
                    }
                    else
                    {
                        nb_bus_t->sta = NOHEAD;
                    }
                }
            }
            else
#endif
            {
                reset_frame(nb_bus_t, receive_buffer[data_cnt]);
            }
            break;
        //GETLEN
        case GETLEN:

#if defined(SUPPORT_ONE_BYTE)
            if(nb_bus_t->version == OLD_PROTOCOL_VERSION)
            {

                *(nb_bus_t->frame_buffer + 3 + nb_bus_t->frame_cnt) = receive_buffer[data_cnt];
                nb_bus_t->frame_cnt++;

                if (nb_bus_t->frame_cnt >= (nb_bus_t->frame_data_len + 6 - is_tracker_version))
                {

                    if (check_frame(nb_bus_t, nb_bus_t->frame_buffer + 2, (nb_bus_t->frame_data_len + 7 - is_tracker_version)) == 0)
                    {

                        nb_bus_t->frame_len = nb_bus_t->frame_data_len + 9 - is_tracker_version;
                        parse_to_rx_frametruct(nb_bus_t);

                        if (nb_bus_t->rec_frame_cb != NULL)
                        {

                            nb_bus_t->rec_frame_cb();
                        }
                        nb_bus_t->sta = NOHEAD;
                    }
                    else
                    {
                        reset_frame(nb_bus_t, receive_buffer[data_cnt]);
                    }
                }
            }
#endif
            
#ifdef SUPPORT_TWO_BYTES
			if (nb_bus_t->version == NEW_PROTOCOL_VERSION)
            {
                *(nb_bus_t->frame_buffer + 4 + nb_bus_t->frame_cnt) = receive_buffer[data_cnt];
                nb_bus_t->frame_cnt++;

                if (nb_bus_t->frame_cnt >= nb_bus_t->frame_data_len + 7)
                {

                    if (check_frame(nb_bus_t, nb_bus_t->frame_buffer + 2, nb_bus_t->frame_data_len + 9) == 0)
                    {

                        nb_bus_t->frame_len = nb_bus_t->frame_data_len + 11;
                        parse_to_rx_frametruct(nb_bus_t);

                        if (nb_bus_t->rec_frame_cb != NULL)
                        {
                            nb_bus_t->rec_frame_cb(NULL);
                        }

                        nb_bus_t->sta = NOHEAD;
                    }
                    else
                    {
                        reset_frame(nb_bus_t, receive_buffer[data_cnt]);
                    }
                }
            }
#endif
            else
            {
                reset_frame(nb_bus_t, receive_buffer[data_cnt]);
            }

            break;

        default:
            reset_frame(nb_bus_t, receive_buffer[data_cnt]);
            break;
        }
    }
}

int check_frame(NB_BUS_TYPE *nb_bus_t, uint8_t *frame_buffer, uint16_t frame_len)
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

PARSE_RETURN parse_to_rx_frametruct(NB_BUS_TYPE *nb_bus_t)
{
    uint16_t count = 3;

    nb_bus_t->frame.Version = nb_bus_t->version;
    nb_bus_t->frame.FrameDataLen = nb_bus_t->frame_data_len;

    if (nb_bus_t->version == NEW_PROTOCOL_VERSION)
    {
        count++;
    }

    {
        nb_bus_t->frame.SourceID = nb_bus_t->frame_buffer[count++];
        nb_bus_t->frame.TargetID = nb_bus_t->frame_buffer[count++];
    }
    nb_bus_t->frame.Cmd = nb_bus_t->frame_buffer[count++];
    nb_bus_t->frame.DataIndex = nb_bus_t->frame_buffer[count++];

    if (nb_bus_t->version == NEW_PROTOCOL_VERSION)
    {
        nb_bus_t->frame.DataIndex |= (nb_bus_t->frame_buffer[count++] << 8);
    }

    nb_bus_t->frame.frame_data = nb_bus_t->frame_buffer + count;

    return PARSE_OK;
}
