#include <iostream>
#include <new>

int ** convert(const int * t, size_t n, const size_t * lns, size_t rows)
{
  if (t == nullptr || lns == nullptr || rows == 0)
  {
    return nullptr;
  }
  size_t sum_lns = 0;
  for (size_t i = 0; i < rows; ++i)
  {
    sum_lns += lns[i];
  }
  if (n != sum_lns)
  {
    return nullptr;
  }
  int ** result = new int*[rows]();
  try
  {
    size_t t_index = 0;
    for (size_t i = 0; i < rows; ++i)
    {
      result[i] = new int[lns[i]];
      for (size_t j = 0; j < lns[i]; ++j)
      {
        result[i][j] = t[t_index++];
      }
    }
  }
  catch (const std::bad_alloc &)
  {
    for (size_t i = 0; i < rows; ++i)
    {
      delete[] result[i];
    }
    delete[] result;
    return nullptr;
  }
  return result;
}

int main()
{
  return 0;
}

