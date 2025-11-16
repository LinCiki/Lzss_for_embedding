#ifndef LZSS_API_H
#define LZSS_API_H

#include "lzss.h"

uint32 HAL_LZSS_Compress(uint8* src, uint32 src_size, uint8* dst, uint32 dst_size);
uint32 HAL_LZSS_DeCompress(uint8* src, uint32 src_size, uint8* dst, uint32 dst_size);

int io_read(void* bytes);
int io_write(int c, void* bytes);


#endif /* LZSS_API_H */