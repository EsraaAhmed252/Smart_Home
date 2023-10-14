#ifndef STDTYPES_H_
#define STDTYPES_H_

typedef unsigned char u8;
typedef signed char s8;

typedef unsigned short u16;
typedef signed short s16;

typedef unsigned long u32;
typedef signed long s32;

typedef enum{
	FALSE,
	TRUE
}Bool_t;
	
typedef enum{
	OK,
	NOK,
	NULLPTR=0,
	OUTOFRANGE
}Error_t;

#define NULL_PTR ((void*)0)
#define NULL ((char)0)

#define MAX_uint8 ((u8)255)
#define MIN_uint8 ((u8)0)
#define MAX_sint8 ((s8)127)
#define MIN_sint8 ((s8)-128)
#define ZERO_sint8 ((s8)0)


#endif /* STDTYPES_H_ */
