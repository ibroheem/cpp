#ifndef MEMORY_H
#define MEMORY_H

namespace mvc_utils
{
   namespace memory
   {
      template <class T>
      void delete_n_construct(T *&obj)
      {
         delete obj;
         obj = new T;
      }
   }
}

#endif//MEMORY_H
