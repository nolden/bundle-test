#ifndef @MODULE_NAME@_EXPORTS_H
#define @MODULE_NAME@_EXPORTS_H
  #if defined(WIN32)
    #ifdef @MODULE_PROVIDES@_EXPORTS
	  #define @MODULE_EXPORT_DEFINE@ __declspec(dllexport)
    #else
	  #define @MODULE_EXPORT_DEFINE@ __declspec(dllimport)
    #endif
  #else
    #define @MODULE_EXPORT_DEFINE@
  #endif
  #ifndef _CMAKE_MODULENAME
    #ifdef @MODULE_PROVIDES@_EXPORTS
      #define _CMAKE_MODULENAME "@MODULE_NAME@"
    #endif
  #endif
#endif


