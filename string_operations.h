
#ifndef STRING_OPERATIONS_H
#define STRING_OPERATIONS_H

namespace mvc_utils
{
  namespace string_operations
  {

    inline string file_ext(const string &fname, char seperator = '.')
    {
      size_t i = fname.find_last_of(seperator) + 1;
      return string(fname.begin() + i, fname.end());
    }

    inline string file_name_w_ext(string &&fname, char seperator = '/')
    {
      size_t i = fname.find_last_of(seperator) + 1;
      return string(fname.begin() + i, fname.end());
    }

    inline string file_name_w_ext(const string &fname, char seperator = '/')
    {
      size_t i = fname.find_last_of(seperator) + 1;
      return string(fname.begin() + i, fname.end());
    }

    inline string file_name_wo_ext(const string &fname, char seperator = '/')
    {
      string stemp = file_name_w_ext(fname, seperator);
      size_t i = stemp.find_last_of('.');
      //string s = string(stemp.begin(), stemp.begin() + i);
      return (i >= stemp.size() ? stemp : string(stemp.begin(), stemp.begin() + i));
    }

    inline string file_name_wo_ext(string &&fname, char seperator = '/')
    {
      string stemp = file_name_w_ext(fname, seperator);
      size_t i = stemp.find_last_of('.');
      return (i >= stemp.size() ? stemp : string(stemp.begin(), stemp.begin() + i));
    }

    string& to_upper(string &s)
    {
      for (auto && c : s)
        c = toupper(c);
      return s;
    }

    string& to_lower(string &s)
    {
      for (auto && c : s)
        c = tolower(c);
      return s;
    }
  }

}

using namespace mvc_utils::string_operations;


#endif//STRING_OPERATIONS_H
