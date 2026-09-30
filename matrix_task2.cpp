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
  const size_t n = 12;
  int t[n] = {5, 5, 5, 5, 6, 6, 7, 7, 7, 7, 7, 8};
  const size_t rows = 4;
  size_t lns[rows] = {4, 2, 5, 1};
  int ** result = convert(t, n, lns, rows);
  if (result != nullptr)
  {
    for (size_t i = 0; i < rows; ++i)
    {
      for (size_t j = 0; j < lns[i]; ++j)
      {
        std::cout << result[i][j] << ' ';
      }
      std::cout << '\n';
    }
    for (size_t i = 0; i < rows; ++i)
    {
      delete[] result[i];
    }
    delete[] result;
  }
  
  return 0;
}

