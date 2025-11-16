# Lzss_for_embedding
适用于嵌入式MCU的压缩和解压缩LZSS API

## 1.HAL_LZSS_Compress
压缩函数，将字节数据（void* src）压缩后写入目的地址（void* dst）
返回压缩后的长度（uint32 dst_size）

## 2.HAL_LZSS_DeCompress
解压函数，压缩函数的逆过程

## 3.DEMO
见main函数中的lzss_test即可
