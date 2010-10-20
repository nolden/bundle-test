// #include <libA.h>
// #include <libB.h>
#include <dlfcn.h>
#include <iostream>

int main(int , char**)
{
  // A a;
  // B b;
  void * p = dlopen("/Users/engelm/bundle-test/install/plugins/core/liblibA.dylib",RTLD_NOW);
  if (p) { std::cout << "p yes" ; }

  return 0;

}

