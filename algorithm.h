#ifndef HEADER_97E6FE8D8222321F
#define HEADER_97E6FE8D8222321F

using namespace std;

namespace mvc_utils
{
   namespace algorithm
   {
      template <typename T, typename T2>
      T& find_n_replace (T &&cont, const T2 &target, const T2 &replacement)
      {
         for (auto && c : cont)
            if (c == target)
               c = replacement;
         return cont;
      }

      template <typename T, typename T2>
      T& find_n_replace (T &cont, const T2 &target, const T2 &replacement)
      {
         return find_n_replace (std::forward < T && > (cont), target, replacement);
      }

      template <typename Iter, typename T2>
      void find_n_replace (Iter b, Iter e, const T2 &target, const T2 &replacement)
      {
         while (b != e)
         {
            if (*b == target)
               *b = replacement;
            ++b;
         }
      }

      template <typename T, typename T2>
      void push_back (T &cont, T2 b, T2 e)
      {
         while (b++ != e)
            cont.push_back (*b);
         }

      template <typename T, typename T2>
      void push_back (T &cont, const T2 &cont2)
      {
         auto iter = cont2.begin();
         while (iter++ != cont2.end() )
            cont.push_back (*iter);
      }

      template <typename T>
      void pop_back (T &cont, uint times)
      {
         int i = 0;
         while (i < times)
         {
            cont.pop;
            ++i;
         }
      }

      template <typename T>
      void fill_w_int(T &cont, int from, int to)
      {
         for (; from < to; ++from)
            cont.push_back(from);
      }

      template <class ContainerType>
      auto splice(ContainerType& cont, int start, int step) -> ContainerType&
      {
         typename remove_const<ContainerType>::type res;
         for (uint i = start; i < cont.size(); i += step)
            res.push_back(cont[i]);

         return res;
      }

      template <class ContainerType>
      auto rsplice(ContainerType& cont, int start, int step) -> ContainerType&
      {
         ContainerType res = splice(cont, start, step);
         reverse(res.begin(), res.end());
         return res;
      }
   }
}

#endif // header guard
