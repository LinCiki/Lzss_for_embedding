#ifndef __included__lzss_h__
#define __included__lzss_h__

#include "std_type.h"

typedef unsigned char lzss_byte; /* definition of a byte...adjust when needed */

typedef int (*lzss_read_func_t)(void *);
typedef int (*lzss_write_func_t)(int, void *);

/** Input/Output interface to perform encoding/decoding operations */
struct lzss_io {
	lzss_read_func_t rd;                /**< function to read a character */
	lzss_write_func_t wr;                /**< function to write a character */
	void *i;                     /**< input context passed to rd */
	void *o;                     /**< output context passed to wr */
};

int lzss_encode(struct lzss_io *io, unsigned int initial_buffer_byte_values);

int lzss_decode(struct lzss_io *io, unsigned int initial_buffer_byte_values);

#endif /* __included__lzss_h__ */
