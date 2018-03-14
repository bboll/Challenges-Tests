#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

const char table[] = {' ', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '\'', ',', '-', '.', '?'};

int main()
{
  string input;
  vector<string> numbers;
  string number="";
  int digit_ctr = 0;
  int spaces = 0;
  while(input!="#")
  {
    getline(cin, input);
    if(input=="*")
    {
      cout << "* entered\n";
      cout << "digit_ctr: " << digit_ctr << "\n";
      for(; digit_ctr <= 4; ++digit_ctr)
        number += "0";
        
        cout << number << "\n";
        numbers.push_back(number);
        number = "";
        
      digit_ctr = 0;
    }
    else 
    {

      //Grabs a line for input

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
      cout << "spaces: " << number << "\n";
      numbers.push_back(number);
      number = "";
      digit_ctr = 0;
      }

      }
    }

      
  } 

  vector<int> outputs;
  for(int i=0; i<numbers.size(); ++i)
  {
    //This is current binary number
    string temp = numbers[i];
    float ctr = 0;
    float n = 0;
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

  int temp=0;
  for(int i=0; i<outputs.size(); ++i)
  { 
    temp = outputs[i];
    cout << table[temp];
  }

  cout << "\n";






  return 0;
}
