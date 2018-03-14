#include <iostream>

using namespace std;

int main ()
{
  int A[5] = { 4, 7, 4, 4, 0 };
  
  for(int idx=0; idx < 5; ++idx)
    cout << A[idx];
  cout << "\n";
  
  int key, ctr2;
  for (int ctr = 1; ctr < 5; ++ctr)
  {
    key = A[ctr];
    ctr2 = ctr - 1;
    while(ctr2 >= 0 && A[ctr2] < key)
    {
      A[ctr2 + 1] = A[ctr2];
      ctr2 = ctr2 - 1;
    }
    A[ctr2+1] = key;
  }

  for(int idx=0; idx < 5; ++idx)
    cout << A[idx];
  cout << "\n";

  return 0;
}
