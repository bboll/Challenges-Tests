#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

const char table[] = {' ', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '\'', ',', '-', '.', '?', '\n'};

int main()
{
  string input;
  vector<string> numbers;
  vector<int> outputs;
  string number="";
  int digit_ctr = 0;
  while(input!="#")
  {
    //Grabs a line for input
    getline(cin, input);
    if(input=="*")
    {
      if(digit_ctr!=0){
      for(; digit_ctr <= 4; ++digit_ctr)
        number += "0";

      numbers.push_back(number);
      number = "";
        
      digit_ctr = 0;

      }
      //Push back new line for every asterik
      numbers.push_back("x");
    }
    else 
    {


      //Find position of first space, then find position of next non-space
      //Difference of that is # of spaces
      //The set of differences is then the numbers to add
      int beg_idx=0;
      int end_idx=1;
      int num=0;
      while(input.find(' ', end_idx) != string::npos)
      {
        
        beg_idx = input.find(' ', end_idx);
        int i = beg_idx;
        end_idx = beg_idx;
        while(input[i]==' ')
        {
          ++end_idx;
          ++i;
        }
        
      num = end_idx - beg_idx;
      if(num % 2 == 0){ number += "1"; }
      if(num % 2 == 1){ number += "0"; }

      ++digit_ctr;

      if(digit_ctr > 4){
      numbers.push_back(number);
      number = "";
      digit_ctr = 0;
      }

      }
    }

      
  } 

  for(int i=0; i<numbers.size(); ++i)
  {
    //This is current binary number
    string temp = numbers[i];
    float ctr = 0;
    float n = 0;
    if(temp == "x"){ outputs.push_back(32); }
    else{
    for(int j=4; j>=0; --j){
      if(temp[j] == '1')
      {
        ctr = ctr + pow(2.0, n);
      }
      ++n;
    }
    //Converts from float to int
    outputs.push_back(ctr);
    }
  }

  int temp=0;
  //outputs.size()-1 removes the extra '\n' char
  for(int i=0; i<outputs.size()-1; ++i)
  { 
    temp = outputs[i];
    cout << table[temp];
  }

  cout << "\n";






  return 0;
}
