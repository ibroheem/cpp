#ifndef HEADER_B626E093D0DB11DF
#define HEADER_B626E093D0DB11DF

namespace mvc_utils
{
  namespace math
  {
    namespace conversion
    {
      template <class T>
      std::string itoa(T n, int base = 10)
      {
        std::string buf;
        std::div_t dv = {};
        dv.quot = n;
        do
        {
          dv = std::div(dv.quot, base);
          buf += "0123456789abcdef"[std::abs(dv.rem)];  // the type of the string literal is const char[17]
        }
        while(dv.quot);
        if(n < 0) buf += '-';
        return {buf.rbegin(), buf.rend()};
      }
    }

    namespace misc
    {
      template <class T>
      bool even(const T&  c)
      {
        return ((c % 2 == 0) ? true : false);
      }

      template <int Num>
      struct is_even
      {
        static constexpr bool value = is_even < Num % 2 >::value;
      };

      template <>
      struct is_even <1>
      {
        static constexpr bool value = false;
      };

      template <>
      struct is_even <0>
      {
        static constexpr bool value = true;
      };

      template <class T>
      bool is_prime(const T & n)
      {
        auto d = 2;
        for (; d < n; ++d)
          if (n % d == 0)
            return false;

        return true;
      }

    }

    namespace fib
    {
      template <typename T = long>
    class fibonacci
    {
      public:
        fibonacci() = default;
        fibonacci(const T &_param) : m_data(_param) { }

        T& recursive();

      private:
        T m_data = 1;
    };

    template <typename T>
    T& fibonacci<T>::recursive()
    {
      if (m_data < 1)
        return recursive(m_data - 1) - recursive(m_data - 2);
    }
    }

    namespace power
    {
      template <class T>
      auto square(const T& n) { return n * n; }

      template <class T>
      T power(const T& n, int p)
      {
        T total = 1;
        for (int i = 0; i < p; ++i)
          total *= n;
        return total;
      }
    }


  }
}

#endif // header guard
