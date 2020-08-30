
#include "ninebot_protocol.h"

PARSE_RETURN send_frame_creat(NB_BUS_TYPE *nb_bus_t, FRAME_TYPE *frame, uint8_t *frame_buffer, uint16_t *length)
{
    uint16_t check_sum = 0;
    uint16_t temp_cnt = 2;
    uint16_t count = 0;
    uint16_t frame_flag;


    if(frame->FrameDataLen > 255)
    {
        return PARSE_FAIL;
    }


    {
        frame_buffer[count++] = VERSION_HEAD;
    }


    frame_buffer[count++] = frame->Version;

    frame_buffer[count++] = (uint8_t)frame->FrameDataLen;

    if(frame->Version == NEW_PROTOCOL_VERSION)
    {
        frame_buffer[count++] = (uint8_t)(frame->FrameDataLen >> 8);
    }


    {
        frame_buffer[count++] = frame->SourceID;
        frame_buffer[count++] = frame->TargetID;
    }

    frame_buffer[count++] = frame->Cmd;

    frame_buffer[count++] = (uint8_t)frame->DataIndex;

    if (frame->Version == NEW_PROTOCOL_VERSION)
    {
        frame_buffer[count++] = (uint8_t)(frame->DataIndex >> 8);
    }

    {
        memcpy(frame_buffer + count, frame->frame_data, frame->FrameDataLen);
    }

    if (frame->Version == OLD_PROTOCOL_VERSION)
    {
        frame_flag = frame->FrameDataLen + 7;
    } else if (frame->Version == NEW_PROTOCOL_VERSION)
    {
        frame_flag = frame->FrameDataLen + 9;
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

PARSE_RETURN creat_send_cmd(NB_BUS_TYPE *nb_bus_t, FRAME_TYPE *frame)
{
    uint16_t frame_len = 0;
    uint8_t frame_buffer[256 + 11];

    if(send_frame_creat(nb_bus_t, frame, frame_buffer, &frame_len) != PARSE_OK)
    {
        return PARSE_FAIL;
    }

    if (frame->send_frame_fun != NULL && frame_len > 0)
    {
        frame->send_frame_fun(frame_buffer, frame_len);
    }

    return PARSE_OK;
}

