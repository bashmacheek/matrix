//m-строк, n-столбцов

#include <iostream>

void rmMtx(int ** mtx, size_t m)
{
  for (size_t i = 0; i < m; ++i)
  {
    delete[] mtx[i];
  }
  delete[] mtx;  
}

int ** makeMtx(size_t m, size_t n)
{
  int ** mtxR = new int * [m];
  for (size_t i = 0; i < m; ++i)
  {
    try
    {
      mtxR[i] = new int [n];
    }
    catch (const std::bad_alloc & e)
    {
      rmMtx(mtxR, i);
      throw;
    }
  }
  return mtxR;
}

int ** transpose(const int * const * mtx, size_t m, size_t n)
{
  int ** res = makeMtx(n, m);
  for (size_t i = 0; i < m; ++i)
  {
    for (size_t j = 0; j < n; ++j)
    {
      res[j][i] = mtx[i][j];
    }
  }
  return res;
}

void printMtx(const int * const * mtx, size_t m, size_t n)
{
  for (size_t i = 0; i < m; ++i)
  {
    std::cout << mtx[i][0];
    for (size_t j = 1; j < n; ++j)
    {
      std::cout << ' ' << mtx[i][j];
    }
    std::cout << '\n';
  }
}

int main()
{
  size_t m = 0;
  size_t n = 0;

  if (!(std::cin >> m >> n) || m == 0 || n == 0)
  {
    std::cerr << "Invalid matrix dimensions\n";
    return 1;
  }

  int ** mtx = nullptr;
  try
  {
    mtx = makeMtx(m, n);
  }
  catch (const std::bad_alloc &)
  {
    std::cerr << "Out of memory\n";
    return 2;
  }

  for (size_t i = 0; i < m * n; ++i)
  {
    if (!(std::cin >> mtx[i / n][i % n])) // переход на строку через n шагов
    {
      rmMtx(mtx, m);
      std::cerr << "Invalid matrix input\n";
      return 1;
    }
  }

  int ** transposedMtx = nullptr;
  try
  {
    transposedMtx = transpose(mtx, m, n);
  }
  catch (const std::bad_alloc &)
  {
    rmMtx(mtx, m);
    std::cerr << "Out of memory\n";
    return 2;
  }

  printMtx(transposedMtx, n, m);
  rmMtx(transposedMtx, n);

  return 0;
}