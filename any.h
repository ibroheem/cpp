#ifndef HEADER_3EA4C51BC9A26587
#define HEADER_3EA4C51BC9A26587

#include <vector>
#include <./bits/stl_pair.h>

namespace mvc_utils
{
  namespace any
  {
    template <typename T = int>
    std::vector<T> any_to_vector (std::vector<boost::any> &from)
    {
      std::vector<T> to {};

      for (auto && c : from)
        to.push_back (any_cast<T&> (c) );

      return to;
    }

    template <typename T>
    vector<pair<string, T>> any_to_vector_pair (vector<pair<string, boost::any>> &from)
    {
      vector<pair<string, T>> to {};

      for (auto && c : from)
        to.push_back (boost::any_cast<pair<string, T&>> (c) );

      return to;
    }
  }
}


#endif // header guard
