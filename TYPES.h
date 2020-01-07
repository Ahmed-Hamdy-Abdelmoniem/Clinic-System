#ifndef TYPES_h
#define TYPES_h

typedef unsigned long u32;
typedef unsigned char u8;
typedef struct node
{
	u32 id ; 
	u8 name[10] ;
	u32 age ; 
	u8 gender ;
	struct node * ptr_T1 ;
}PATEINT_T1;
typedef struct time
{
	u32 id ;  
	u32 time ;
	struct time * ptr_T2 ;
}PATEINT_T2;
typedef enum check
{
	ok,
	notok,
}checks;
#endif