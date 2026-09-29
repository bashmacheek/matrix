#include <iostream>

int ** makeMtx(size_t m, size_t n);
int ** transpose(int ** mtx, size_t m, size_t n);
void rmMtx(int ** mtx, size_t m);

int main()
{
  size_t m = 0;
  size_t n = 0;

  if (!(std::cin >> m >> n) || m == 0 || n == 0)
  {
    return 1;
  }

  return 0;
}