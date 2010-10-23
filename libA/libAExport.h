#ifndef LIBA_EXPORTS_H
#define LIBA_EXPORTS_H
  #if defined(WIN32)
    #ifdef libA_EXPORTS
	  #define LIB_A_EXPORT __declspec(dllexport)
    #else
	  #define LIB_A_EXPORT __declspec(dllimport)
    #endif
  #else
    #define LIB_A_EXPORT
  #endif
#endif
