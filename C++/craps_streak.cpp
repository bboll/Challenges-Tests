#include <iostream>
#include <string>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

int main()
{
  typedef pair<string, string> spair;
  vector<spair> array;
  spair temp;
  int roll_string=0;
  string input;

  cout << "Please input craps rolls\n";
  getline(cin, input);

  string::iterator it;
  for(it = input.begin(); it < input.end(); ++it)
  {
    if (isdigit(*it))
    {
      if(roll_string==0){
        temp.first = *it;
        roll_string = 1;
      }
      else{
        temp.second = *it;
        array.push_back(make_pair(temp.first, temp.second));
        roll_string=0;
      }
    }
  }

  //Prints the array
  for(int idx=0; idx<array.size(); ++idx)
    cout << array[idx].first << " " << array[idx].second << "\n";

  int highest_payout = 0;
  int idx_high_pay = 0;
  int tmp_idx = 0;
  int endidx_high_pay = 0;
  int tmp_payout = 0;
  int roll = 0;
  int x=0;
  int y=0;

  //While payout >= 0; 
  for(int idx=0; idx<array.size(); ++idx)
  {
    //Compute roll and convert to int
    x = atoi((array[idx].first).c_str());
    y = atoi((array[idx].second).c_str());
    roll = x + y; 

    // +1
    if(roll == 3 || 4 || 9 || 10 || 11){tmp_payout += 1;} 
      
    // -1
    if(roll == 5 || 6 || 7 || 8 )
    {
      //What if they're equal? Need to store streaks in an array then
      if(tmp_payout > highest_payout)
      {
        highest_payout = tmp_payout;
        endidx_high_pay = idx;
        idx_high_pay = tmp_idx;
      }
      //Set the new tmp_idx to start of new substring
      tmp_idx = idx; 
      tmp_payout = 0;
    }
      
    // +2
    if(roll == 2){tmp_payout += 2;}
      
    // +3
    if(roll == 12){tmp_payout += 3;}
  }

  cout << "best winning streak is $" << highest_payout << " from rolls " << idx_high_pay+1 << "-" << endidx_high_pay+1 << "\n";

  return main();
}
