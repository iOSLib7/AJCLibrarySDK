#if !defined(INC_HY_BASE_TYPE_H)
#define INC_HY_BASE_TYPE_H

#ifdef LINUX
	#include  <unistd.h>
	#include  <stdint.h>
	#include  <stdlib.h>
	#include  <stdio.h>
	#include  <semaphore.h>
	#include  <errno.h>
	#include  <sys/types.h>
	#include  <sys/wait.h>
	#include  <pthread.h>
	#include  <string.h>
	#ifndef LINUX_iOS_64
		#include <sys/prctl.h>
	#endif
	#include  <sys/time.h>
	#include  <time.h>
#endif

typedef int						HINT32;
typedef unsigned int			HUINT32;
typedef signed short			HINT16;
typedef unsigned short			HUINT16;
typedef			char			HCHAR;
typedef unsigned char			HUCHAR;
typedef signed char				HSCHAR;

#if defined(WIN32)
    typedef unsigned __int64   HUINT64;
#elif defined(LINUX)
	typedef unsigned long long int HUINT64;
	typedef int64_t				   HINT64;
#else
    typedef unsigned long long  HUINT64;
#endif

typedef float					HFLOAT;
typedef double					HDOUBLE;
typedef unsigned char			HBOOL;
typedef void					HVOID;
typedef unsigned long			HULONG;
typedef long					HLONG;
typedef HVOID*					HHANDLE;
#define HTRUE					(HBOOL)1
#define HFALSE					(HBOOL)0

//#define MAKE_FOURCC(ch0,ch1,ch2,ch3) ((HUINT32)(HUCHAR)(ch0)|((HUINT32)(HUCHAR)(ch1)<<8)|((HUINT32)(HUCHAR)(ch2)<<16) | ((HUINT32)(HUCHAR)(ch3)<<24))

//#define MY_PRINTF 	printf 
#define MY_PRINTF 

#endif  


