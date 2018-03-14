#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>

using namespace std;

int main()
{
  double x[4];
  double y[4];

  int num_of_cases;
  string CASE;
  vector<string> CASES;

  cin >> num_of_cases;
 
  //Input
  for(int ctr=0; ctr<=num_of_cases; ++ctr)
  {
    getline(cin, CASE);
    CASES.push_back(CASE);
    cout << CASE << "\n";
  }

  //Run each case thru this
  sscanf(CASE, "%d %d %d %d %d %d %d %d", x[0], y[0], x[1], y[1], x[2], y[2], x[3], y[3]);

  int idx=0;
  bool checkForSolution=false;
  while(idx<4 && !checkForSolution)
  {
    if(count(x, x+4, x[idx]) > 1){ cout << "no solution\n"; checkForSolution=true; }
    if(count(y, y+4, y[idx]) > 1 && !checkForSolution){ cout << "no solution\n"; checkForSolution=true;}
    ++idx;
  }

  double max_x = *max_element(x, x+4);
  double min_x = *min_element(x, x+4);

  max_x = max_x + 5.0;
  min_x = min_x - 5.0;

  double result;
  result = max_x - min_x;
  cout.precision(2);
  cout << fixed << result << "\n";

  return 0;
}
