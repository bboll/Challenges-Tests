// Author: Brian Boll
//
// 7-digit display (output), buttons 0-9 and A-F (input/menu), check base input
// of 2 through 16.

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
  int inum, ibase, dbase;
  vector<int> onum;

  //Receive input
  cout << "Please input number to be converted:\n";
  cin >> inum;
  cout << "Please input base to be converted:\n";
  cin >> ibase;
  cout << "Please input desired base:\n";
  cin >> dbase;
 

  //logb(x) = logd(x) / logd(b)
  //log3(12) = log5(12)/log5(3)
  //Changes log3(12) base to 5


  //Calculate needed places
  //need to use input base somehow. NEED TO USE CHANGE OF BASE TWICE! Maybe or maybe it still doesn't matter and ibase decides max_per_place
  int needed_places = floor( (log(inum) / log(dbase)) + 1 );
  int max_per_place = dbase - 1;
  //cout << needed_places;
  
  //Something is off here, only thinking about going from 10 to new base
  //Think it's going wrong way, 10 under base 3 to base 5 is 3 but gives 20.
  int remainder=inum;
  for(int ctr=needed_places-1; ctr>=0; --ctr)
  { 
    if(remainder>=(pow(dbase, ctr)))
    {
      int ctr2=0;
      while(remainder>=(pow(dbase, ctr)) && ctr2<max_per_place)
      {
        remainder = remainder - (pow(dbase, ctr));
        ++ctr2;
      }
      onum.push_back(ctr2);
    }
    else { onum.push_back(0); }

  }
  
  for(int idx=0; idx<onum.size(); ++idx)
  {
    cout << onum[idx];
  }

  cout << "\n";
  
  return 0;
}
