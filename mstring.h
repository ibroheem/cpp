#ifndef HEADER_4807C003950EFA4A
#define HEADER_4807C003950EFA4A


class mstring
{
  public:
    mstring() {}
    //mstring(char *c)         : m_data(c) { }
    mstring(const char *c)   : m_data(c) { }
    mstring(string &&s)      : m_data(move(s)) { }
    mstring(const string &s) : m_data(s) { }

    template <typename Iter>
    mstring(Iter b, Iter e)  : m_data(b, e) { }

    mstring(mstring &&s)      : m_data(move(s.data())) { }
    mstring(const mstring &s) : m_data(s.data())  { }

    mstring& operator=(mstring &&rhs)      { m_data = move(rhs.data()); return *this; }
    mstring& operator=(const mstring &rhs) { m_data = rhs.data(); return *this; }

    friend ostream& operator<<(ostream &out, const mstring &rhs) { out<<rhs.data(); return out; }

    operator string()   { return m_data; }
    operator string&()  { return m_data; }
    operator string&&() { return std::move(m_data); }
    operator const char*()   { return m_data.c_str(); }

    string& data()  { return m_data; }
    const string& data() const { return m_data; }

  private:
    string m_data = "";
};

#endif // header guard
