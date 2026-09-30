#include <iostream>

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
  int ** result = new int*[rows];
  return nullptr;
}

int main()
{
  return 0;
}

