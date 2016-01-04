#ifndef HEADER_A76A2EE3D7C9CC27
#define HEADER_A76A2EE3D7C9CC27


#include <iostream>
#include "macros.h"
#include "typedefs.h"

using namespace std;

namespace mvc_utils
{
  namespace io
  {
    template <typename F>
    ostream& print(const F &first) { return cout<<first; }

    template <typename F, typename ...R>
    ostream& print(const F &first, const R ...rest)
    {
      cout<<first;
      return print((rest)...);
    }

    template <typename F>
    ostream& print_ln(const F &first) { return cout<<first <<endl; }

    template <typename F, typename ...R>
    ostream& print_ln(const F &first, const R ...rest)
    {
      cout<<first <<endl;
      return print_ln((rest)...);
    }

    template <typename T>
    ostream& print_w_tab(const T &val) { return cout<<val <<'\t'; }

    template <typename F, typename ...R>
    ostream& print_w_tab(const F &first, const R ...rest)
    {
      cout<<first <<'\t';
      return print_w_tab((rest)...);
    }

    template <typename T>
    ostream& print_w_tab_ln(const T &val) { return cout<<val <<'\t' <<endl; }

    template <typename F, typename ...R>
    ostream& print_w_tab_ln(const F &first, const R ...rest)
    {
      cout<<first <<'\t' <<endl;
      return print_w_tab_ln((rest)...);
    }

    template <typename T>
    void print_cont(const T &cont, string seperator = "")
    {
      auto iter = cont.begin();
      while (iter != cont.end())
        print(*iter++, seperator);
    }

    template <typename Iter>
    void print_iter(Iter b, Iter e)
    {
      while (b != e)
        cout<<*b++;
    }
  }
}


#endif // header guard
