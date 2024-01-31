#ifndef CRYPT_H_
#define CRYPT_H_

#include "types.h"

extern void begin_crypt_async(u32 seed);
extern void end_crypt_async(void);
extern char crypt_single(char c);
extern int crypt(char *dst, size_t len, char *src, u32 seed);

#endif // CRYPT_H_
