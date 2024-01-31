#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "types.h"
#include "crypt.h"

#define DEFAULT_COLORIZE FALSE
//#define DEFAULT_COLORIZE TRUE

//define BIN_FORMAT "<%02x>"
#define BIN_FORMAT "\\x%02x"

FILE *FI = NULL;
FILE *FO = NULL;


int main(int argc, char *argv[])
{
	u32 in;
	BOOL colorize = DEFAULT_COLORIZE;

	BOOL do_crypt = FALSE;
	u32 seed = 0;

	FI = stdin;
	FO = stdout;

	if (argc > 1)
		if (strcmp(argv[1], "-") != 0)
			FI = fopen(argv[1], "r");

	if (argc > 2)
		if (strcmp(argv[2], "-c") != 0)
			FO = fopen(argv[2], "w");

	if (argc > 3)
	{
		do_crypt = TRUE;
		seed = strtoul(argv[3], NULL, 0);
		begin_crypt_async(seed);
	}

	if ((FI == NULL) || (FO == NULL))
		return 1;

	while (feof(FI) == 0)
	{
		in = (u32)fgetc(FI);

		// Abort if about to print EOF
		if (in == EOF)
			break;

		// Cryptographic cipher
		//   (bi-directional, so easilly reversible if seed is known)
		if (do_crypt != FALSE)
			in = crypt_single(in);

		// Output unchanged if printable
			// No, actually, scratch that
/*		if ((in >= ' ') && (in <= '~'))
		{
			fputc(in, FO);
			continue;
		}		*/

		// Otherwise print binary representation
		if (colorize != FALSE)
			fprintf(FO, "\x1b[31m" BIN_FORMAT "\x1b[0m", (unsigned int)in);
		else
			fprintf(FO, BIN_FORMAT, (unsigned int)in);
	}

	if (do_crypt != FALSE)
		end_crypt_async();

	return 0;
}
