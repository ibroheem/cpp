#ifndef TYPE_INDEX_H
#define TYPE_INDEX_H

#include <boost/type_index.hpp>
using namespace boost;
namespace mvc_utils
{
  namespace type_index
  {


    /** Types Needed in calling e.g
    cout <<equal_type<int, int *>() <<endl;
    cout <<equal_type<int, int >() <<endl;
    **/
    template <typename T1, typename T2>
    bool equal_type()
    {
      return (boost::typeindex::type_id<T1>().pretty_name() == boost::typeindex::type_id<T2>().pretty_name() );
    }

    /** Variables used during call
        cout <<equal_type("l", "y") <<endl;
        cout <<equal_type(2, 4) <<endl;
     **/
    template <typename T1, typename T2>
    bool equal_type_vars (const T1 &var1_t = T1(), const T2 &var2_t = T2() )
    {
      return (boost::typeindex::type_id<T1>().pretty_name() == boost::typeindex::type_id<T2>().pretty_name() );
    }

    template <typename T1>
    string type_name(const T1 &var)
    {
      //return typeindex::type_id_runtime<T1>().pretty_name();
      return typeindex::type_id_with_cvr<T1>().pretty_name();
      //return typeindex::type_id<T1>().pretty_name();
    }

    template <typename T1>
    string type_name()
    {
      //return typeindex::type_id_runtime<T1>().pretty_name();
      return typeindex::type_id_with_cvr<T1>().pretty_name();
      //return typeindex::type_id<T1>().pretty_name();
    }
  }
}


#endif//TYPE_INDEX_H
