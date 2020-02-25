#ifndef STD_TYPES_H
#define STD_TYPES_H

typedef unsigned char u8;
typedef short unsigned int u16;
typedef long  unsigned int u32;

typedef  signed char s8;
typedef  short signed int s16;
typedef  long signed int s32;

typedef  float  f32;
typedef  double f64;
typedef  long double f96;

/*Error status*/
#define ERROR_OK 								0
#define ERROR_NOK 								1
	
/*Error Status Type*/
typedef u8   ERROR_S;

#define   NULL        ((void*)0)


#endif
