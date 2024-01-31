#ifndef TYPES_H_
#define TYPES_H_

typedef   signed long  long s64;
typedef   signed       long s32;
typedef   signed      short s16;
typedef   signed       char s8;

typedef unsigned long  long u64;
typedef unsigned       long u32;
typedef unsigned      short u16;
typedef unsigned       char u8;

typedef double f64;
typedef  float f32;

typedef struct
{	f64 x;
	f64 y;
	f64 z;
} f64vec3;

typedef struct
{	f32 x;
	f32 y;
	f32 z;
} f32vec3;

#ifndef BOOL
#  define BOOL unsigned char
#  ifndef FALSE
#    define FALSE (0)
#  endif
#  ifndef TRUE
#    define TRUE (1)
#  endif
#endif

#endif // TYPES_H_
