#ifndef MIB_TUPLES_H
#define MIB_TUPLES_H


namespace my_tuples
{
  template <class T1, class T2, class T3, class T4>
  struct tuples4
  {
      typedef tuples4<T1, T2, T3, T4> tuple_type;
    public:
      tuples4() : first(), second(), third(), fourth() { }
      tuples4(const T1& _first, const T2& _second, const T3& _third, const T4& _fourth)
        : first(_first), second(_second), third(_third), fourth(_fourth)  { }

      tuples4(tuples4<T1, T2, T3, T4>&& rhs)
        : first(std::move(rhs.first)), second(std::move(rhs.second)), third(std::move(rhs.third)),
          fourth(std::move(rhs.fourth))  { }

      tuples4(const tuples4<T1, T2, T3, T4>& rhs)
        : first(rhs.first), second(rhs.second), third(rhs.third), fourth(rhs.fourth)  { }

      tuples4& operator=(const tuples4<T1, T2, T3, T4>& rhs)
      {
        first = rhs.first;
        second = rhs.second;
        third = rhs.third;
        fourth = rhs.fourth;
        return *this;
      }

      tuples4& operator=(tuples4<T1, T2, T3, T4>&& rhs)
      {
        first  = std::move(rhs.first);
        second = std::move(rhs.second);
        third  = std::move(rhs.third);
        fourth = std::move(rhs.fourth);
        return *this;
      }

      ~tuples4() {}

      void swap(tuples4<T1, T2, T3, T4>& rhs)
      {
        auto tmp = rhs;
        rhs  = *this;
        *this = tmp;
      }
    public:
      T1 first;
      T2 second;
      T3 third;
      T4 fourth;

  };

  template <class T1, class T2, class T3>
  struct tuple3 : public tuples4<T1, T2, T3, T3>
  {

  };
}

namespace experimental
{
  namespace my_tuples
  {
    template <class T1, class T2, class T3>
    struct tuples3
    {
        typedef tuples3<T1, T2, T3> tuple_type;
        typedef T1 first_type;
        typedef T2 second_type;
        typedef T3 third_type;
      public:
        tuples3() : first(), second(), third() { }
        tuples3(const T1& _first, const T2& _second, const T3& _third)
          : first(_first), second(_second), third(_third) { }

        tuples3(T1& _first, T2&& _second, T3&& _third)
          : first(std::move(_first)), second(std::move(_second)), third(std::move(_third)) { }

        tuples3(tuples3<T1, T2, T3>&& rhs)
          : first(std::move(rhs.first)), second(std::move(rhs.second)), third(std::move(rhs.third))
        { }

        tuples3(const tuples3<T1, T2, T3>& rhs)
          : first(rhs.first), second(rhs.second), third(rhs.third) { }

        tuples3& operator=(const tuples3<T1, T2, T3>& rhs)
        {
          first = rhs.first;
          second = rhs.second;
          third = rhs.third;
          return *this;
        }

        tuples3& operator=(tuples3<T1, T2, T3>&& rhs)
        {
          first  = std::move(rhs.first);
          second = std::move(rhs.second);
          third  = std::move(rhs.third);
          return *this;
        }

        ~tuples3() {}

        void swap(tuples3<T1, T2, T3>& rhs)
        {
          auto tmp = rhs;
          rhs  = *this;
          *this = tmp;
        }

      public:
        T1 first;
        T2 second;
        T3 third;
    };

    template <class T1, class T2, class T3>
    bool operator<(const tuples3<T1, T2, T3>& tp1, const tuples3<T1, T2, T3>& tp2)
    {
      //return tp1.first < tp2.first || (!(tp2.first < tp1.first) && tp1.second < tp2.second);
      return tp1.first < tp2.first;
    }

    template <class T1, class T2, class T3>
    bool operator>(tuples3<T1, T2, T3>& tp1, tuples3<T1, T2, T3>& tp2)
    {
      return tp2 < tp1;
    }

    template <class T1, class T2, class T3, class T4>
    struct tuples4 : public tuples3<T1, T2, T3>
    {
        typedef tuples4<T1, T2, T3, T4> tuples4_type;
      public:
        tuples4() : tuples3<T1, T2, T3>(), fourth() { }
        tuples4(T1&& _first, T2&& _second, T3&& _third, T4&& _fourth)
          : tuples3<T1, T2, T3>(std::move(_first), std::move(_second), std::move(_third)), fourth(std::move(_fourth))
        {  }

        tuples4(const T1& _first, const T2& _second, const T3& _third, const T4& _fourth)
          : tuples3<T1, T2, T3>(_first, _second, _third), fourth(_fourth)  {  }

        tuples4(tuples4<T1, T2, T3, T4>&& rhs)
          : tuples3<T1, T2, T3>(std::move(rhs.first), std::move(rhs.second), std::move(rhs.third)),
            fourth(std::move(rhs.fourth))
        { }

        tuples4(const tuples4<T1, T2, T3, T4>& rhs)
          : tuples3<T1, T2, T3>(rhs.first, rhs.second, rhs.third), fourth(rhs.fourth) { }

        tuples4& operator=(const tuples4<T1, T2, T3, T4>& rhs)
        {
          tuples3<T1, T2, T3>::operator=(rhs);
          fourth = rhs.fourth;
          return *this;
        }

        tuples4& operator=(tuples4<T1, T2, T3, T4>&& rhs)
        {
          tuples3<T1, T2, T3>::operator=(std::move(rhs));
          fourth  = std::move(rhs.fourth);
          return *this;
        }

        void swap(tuples4<T1, T2, T3, T4> &rhs)
        {
          tuples3<T1, T2, T3>::swap(rhs);
          auto tmp = fourth;
          fourth = rhs.fourth;
          rhs.fourth = tmp;
        }

      public:
        T4 fourth;
    };
  }
}

#endif //MIB_TUPLES_H
