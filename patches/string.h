
#include <sstream>

namespace mvc_utils
{
  namespace patches
  {
    template <class T>
    std::string to_string(const T& _digits)
    {
      std::ostringstream stm;
      stm << _digits;
      return stm.str();
    }

    template <class T = unsigned long long>
    T stoull(const std::string& _str)
    {
      T num;
      std::istringstream {_str} >> num;
      return num;
    }
  }
}
