template<typename... Args>
struct mem_func
{
  template<typename C, typename R>
  static constexpr auto overload( R (C::*pmf)(Args...) )  -> decltype(pmf)
  {
    return pmf;
  }
};

//connect(spinbox, mem_func_overload<int>(&QSpinBox::valueChanged), ...)

template <typename... Args>
struct SELECT
{
  template<typename C, typename R>
  static constexpr auto OVERLOAD_OF( R (C::*pmf)(Args...) ) -> decltype(pmf)
  {
    return pmf;
  }
};

//connect(spinbox, SELECT<int>::OVERLOAD_OF(&QSpinBox::valueChanged), ...)
