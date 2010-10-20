// #include <libA.h>
// #include <libB.h>
#include <dlfcn.h>
#include <iostream>

int main(int , char**)
{
  // A a;
  // B b;
  void * p = dlopen("/Users/engelm/bundle-test/install/plugins/liblibA.dylib",RTLD_NOW);
  if (p) { std::cout << "libA: yes" ; }
  
  p = dlopen("/Users/engelm/bundle-test/install/plugins/liblibC.dylib",RTLD_NOW);
  if (p) { std::cout << "libC: yes" ; }

  return 0;

}

