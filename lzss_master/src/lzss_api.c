#include "lzss_api.h"

uint32 g_io_read_flag  = 0U;
uint32 g_io_write_flag = 0U;
uint32 g_io_input_size  = 0U;
uint32 g_io_output_size  = 0U;

struct lzss_io lzss_config = {
    .rd = io_read,
    .wr = io_write,
    .i = NULL_PTR,
    .o = NULL_PTR,
};

int io_read(void* bytes)
{
    if (bytes != NULL_PTR && g_io_read_flag < g_io_input_size) {
        uint8* data_ptr = (uint8*)bytes;
        uint8 ret = data_ptr[g_io_read_flag];
        g_io_read_flag++;
        return ret;
    } else {
        return -1;
    }
}

int io_write(int c, void* bytes)
{
    if (bytes != NULL_PTR && g_io_write_flag < g_io_output_size) {
        uint8* data_ptr = (uint8*)bytes;
        data_ptr[g_io_write_flag] = (uint8)c;
        g_io_write_flag++;
        return 0;
    } else {
        return -1;
    }
}

static HAL_LZSS_Init(uint8* i, uint8* o, uint32 i_size, uint32 o_size)
{
    lzss_config.i = i;
    lzss_config.o = o;
    g_io_read_flag = 0U;
    g_io_write_flag = 0U;
    g_io_input_size = i_size;
    g_io_output_size = o_size;
}

uint32 HAL_LZSS_Compress(uint8* src, uint32 src_size, uint8* dst, uint32 dst_size)
{
    HAL_LZSS_Init(src, dst, src_size, dst_size);
    int code_len = lzss_encode(&lzss_config, src_size);
    return (uint32)code_len;
}

uint32 HAL_LZSS_DeCompress(uint8* src, uint32 src_size, uint8* dst, uint32 dst_size)
{
    HAL_LZSS_Init(src, dst, src_size, dst_size);
    lzss_decode(&lzss_config, dst_size);
    return g_io_write_flag;
}
