#include <iostream>

using namespace std;

int main()
{
  int A[5] = { 1, 1, 9, 4, 3 };
  for(int idx=0; idx<5; ++idx)
    cout << A[idx];
  cout << "\n";

  int v;
  int found=0;
  cout << "Enter value to find:\n";
  cin >> v;

  for(int i=0; i<5; ++i)
    if(A[i]==v) { cout << "Found at: " << i+1 << "\n"; ++found; }
  
  if(found==0){ cout << "NIL\n"; }

  return 0;
}
