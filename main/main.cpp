// #include <libA.h>
// #include <libB.h>

#ifdef WIN32
#include <windows.h>
#else
#include <dlfcn.h>
#endif

#include <iostream>

int main(int , char**)
{
  // A a;
  // B b;
#ifdef WIN32
  HINSTANCE p = LoadLibrary("D:\\HOME\\sascha\\bundle-test-install\\plugins\\liblibA.dll");
#else
  void * p = dlopen("/Users/engelm/bundle-test/install/plugins/liblibA.dylib",RTLD_NOW);
#endif
  
  if (p) { std::cout << "libA: yes" ; }
  
#ifdef WIN32
  p = LoadLibrary("D:\\HOME\\sascha\\bundle-test-install\\plugins\\liblibC.dll");
#else
  p = dlopen("/Users/engelm/bundle-test/install/plugins/liblibC.dylib",RTLD_NOW);
#endif
  if (p) { std::cout << "libC: yes" ; }

  return 0;

}

