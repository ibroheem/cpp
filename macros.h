#ifndef MACROS_H
#define MACROS_H

#include <typeinfo>

#define NL std::cout<<"\n";
#define DL std::cout<<"\n\n";

#define Typename(x) typeid(x).name()

#endif//MACROS_H
