#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "crypt.h"

void begin_crypt_async(u32 seed)
{
	if (seed == 0)
		seed = time(NULL);
	srand(seed);
}

void end_crypt_async(void) {}

char crypt_single(char c)
{
	return (c ^ (rand() & 255));
}

int crypt(char *dst, size_t len, char *src, u32 seed)
{
	size_t n = len;

	if ((dst == NULL) || (src == NULL))
		return -1;

	if (seed == 0)
		seed = time(NULL);
	srand(seed);

	for (; n > 0; --n)
		*(dst++) = *(src++) ^ (rand() & 255);

	return 0;
}
