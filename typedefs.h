#ifndef TYPEDEFS_H
#define TYPEDEFS_H

typedef  const char cchar;
typedef  const double cdouble;
typedef  const int cint;

typedef  unsigned int uint;
typedef  const unsigned int cuint;

typedef  unsigned long ulong;
typedef  const unsigned long culong;

typedef  long long lli;
typedef  unsigned long long ulli;
typedef  const unsigned long long culli;

#if __cplusplus > 201402L
template <typename T>
using  init_list = std::initializer_list<T>;
#endif // __cplusplus


typedef const std::string  c_string;
typedef std::string&       ref_string;
typedef const std::string& c_ref_string;

#ifdef QSTRING_H
   typedef QString         qstring;
   typedef const QString   c_qstring;
   typedef QString &       ref_qstring;
   typedef const QString & c_ref_qstring;
#endif // QSTRING_H

#endif//TYPEDEFS_H
