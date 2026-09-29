//m-строк, n-столбцов

#include <iostream>

int ** makeMtx(size_t m, size_t n)
{
  int ** mtxR = new int * [m];
  
  try
  {
    for (size_t i = 0; i < m; ++i)
    {
      mtxR[i] = new int [n];
    }
  }
    catch (const std::bad_alloc & e)
    {
      rmMtx(mtxR, m);
      throw;
    }
  return mtxR;
}

int ** transpose(int ** mtx, size_t m, size_t n);

void rmMtx(int ** mtx, size_t m)
{
  for (size_t i = 0; i < m; ++i)
  {
    delete [] mtx[i];
  }
  delete [] mtx;  
}

void printMtx(int ** mtx, size_t m, size_t n)
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
    return 1;
  }

  int ** mtx = nullptr;
  try
  {
    mtx = makeMtx(m, n);
  }
  catch (const std::bad_alloc &)
  {
    return 2;
  }

  for (size_t i = 0; i < m * n; ++i)
  {
    if (!(std::cin >> mtx[i / n][i % n])) // переход на строку через n шагов
    {
      rmMtx(mtx, m);
      return 1;
    }
  }

  printMtx(mtx, m, n);
  
  rmMtx(mtx, m);
  return 0;
}