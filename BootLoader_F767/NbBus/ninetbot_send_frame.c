
#include "ninebot_protocol.h"

PARSE_RETURN send_frame_creat(PARSE_STRUCT *parse_s, FRAME_STRUCT *frame_s, uint8_t *frame_buffer, uint16_t *length)
{
    uint16_t check_sum = 0;
    uint16_t temp_cnt = 2;
    uint16_t count = 0;
    uint16_t frame_flag;


    if(frame_s->FrameDataLen > 255)
    {
        return PARSE_FAIL;
    }

    if(frame_s->Version == CRYPTO_PROTOCOL_VERSION)
    {
        if(frame_s->FrameDataLen > 255 - 8)
        {
            return PARSE_FAIL;
        }
    }


    {
        frame_buffer[count++] = VERSION_HEAD;
    }


    frame_buffer[count++] = frame_s->Version;

    frame_buffer[count++] = (uint8_t)frame_s->FrameDataLen;

    if(frame_s->Version == NEW_PROTOCOL_VERSION)
    {
        frame_buffer[count++] = (uint8_t)(frame_s->FrameDataLen >> 8);
    }


    {
        frame_buffer[count++] = frame_s->SourceID;
        frame_buffer[count++] = frame_s->TargetID;
    }

    frame_buffer[count++] = frame_s->Cmd;

    frame_buffer[count++] = (uint8_t)frame_s->DataIndex;

    if (frame_s->Version == NEW_PROTOCOL_VERSION)
    {
        frame_buffer[count++] = (uint8_t)(frame_s->DataIndex >> 8);
    }
#ifdef SUPPORT_TO_CRYPTO
    if(frame_s->Version == CRYPTO_PROTOCOL_VERSION)
    {
        memcpy(frame_buffer + count, frame_s->frame_data, frame_s->FrameDataLen);

        if(nb_crypto_board_encrypt(&parse_s->crypto_param_tx,
                                   frame_buffer + 5,
                                   frame_s->FrameDataLen + 2,
                                   parse_s->crypto_buf_tx) == (frame_s->FrameDataLen + 2 + 8))
        {
            frame_s->FrameDataLen = frame_s->FrameDataLen + 8;
            frame_buffer[2] = frame_s->FrameDataLen;
            memcpy(frame_buffer + count - 2, parse_s->crypto_buf_tx, frame_s->FrameDataLen + 2);
        } else {
            return PARSE_FAIL;
        }
    } else
#endif
    {
        memcpy(frame_buffer + count, frame_s->frame_data, frame_s->FrameDataLen);
    }

    if (frame_s->Version == OLD_PROTOCOL_VERSION || frame_s->Version == CRYPTO_PROTOCOL_VERSION)
    {
        frame_flag = frame_s->FrameDataLen + 7;
    } else if (frame_s->Version == NEW_PROTOCOL_VERSION)
    {
        frame_flag = frame_s->FrameDataLen + 9;
    }



    {
        for (temp_cnt = 2; temp_cnt < frame_flag; temp_cnt++)
        {
            check_sum += frame_buffer[temp_cnt];
        }

        check_sum = ~check_sum;

        frame_buffer[frame_flag++] = (uint8_t)check_sum;
        frame_buffer[frame_flag++] = (uint8_t)(check_sum >> 8);
    }

    *length = frame_flag;
    return PARSE_OK;
}

PARSE_RETURN creat_send_cmd(PARSE_STRUCT *parse_s, FRAME_STRUCT *frame_s)
{
    uint16_t frame_len = 0;
    uint8_t frame_buffer[256 + 11];

    if(send_frame_creat(parse_s, frame_s, frame_buffer, &frame_len) != PARSE_OK)
    {
        return PARSE_FAIL;
    }

    if (frame_s->send_frame_fun != NULL && frame_len > 0)
    {
        frame_s->send_frame_fun(frame_buffer, frame_len);
    }

    return PARSE_OK;
}

