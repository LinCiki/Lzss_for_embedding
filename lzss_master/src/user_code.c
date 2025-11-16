#include "user_code.h"
#include "lzss_api.h"


uint8 raw_data[LZSS_TEST_DATA_SIZE] = {0};
uint8 compress_data[LZSS_TEST_DATA_SIZE] = {0};
uint8 decompress_data[LZSS_TEST_DATA_SIZE] = {0};

void print_array(uint8* data_addr, uint32 data_size)
{
    if (data_addr != 0U && data_size != 0U) {
        uint8* data_ptr = (uint8*)data_addr;
        shellPrint(&admin, "data:");
        for (uint32 i = 0U; i < data_size; i++) {
            shellPrint(&admin, "%x ", data_ptr[i]);
        }
        shellPrint(&admin, "\r\n");
    } else {
        shellPrint(&admin, "data_addr or size error\r\n");
    }
}

void lzss_test(uint32 test_range)
{
    if (test_range > 0U) {
        for (uint8 i = 0; i < test_range && i < LZSS_TEST_DATA_SIZE; i++) {
            raw_data[i] = i % 8U;
        }
        uint32 ret1 = HAL_LZSS_Compress(raw_data, test_range, compress_data, LZSS_TEST_DATA_SIZE);
        shellPrint(&admin, "compress_data:\r\n");
        print_array(compress_data, ret1);
        shellPrint(&admin, "size: %d\r\n", ret1);

        uint32 ret2 = HAL_LZSS_DeCompress(compress_data, ret1, decompress_data, LZSS_TEST_DATA_SIZE);
        shellPrint(&admin, "decompress_data:\r\n");
        print_array(decompress_data, ret2);
        shellPrint(&admin, "size: %d\r\n", ret2);
    } else {
        shellPrint(&admin, "test_range must large than 0\r\n");
    }
}
