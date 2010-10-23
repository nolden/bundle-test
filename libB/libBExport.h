#ifndef LIBB_EXPORTS_H
#define LIBB_EXPORTS_H
  #if defined(WIN32)
    #ifdef libB_EXPORTS
	  #define LIB_B_EXPORT __declspec(dllexport)
    #else
	  #define LIB_B_EXPORT __declspec(dllimport)
    #endif
  #else
    #define LIB_B_EXPORT
  #endif
#endif


