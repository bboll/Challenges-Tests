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
  string number;
  int digit_ctr = 0;
  int spaces = 0;
  bool counting = false;
  while(input!="#")
  {
    getline(cin, input);
    for(int idx=0; idx<input.size(); ++idx)
    {
      if(input[idx] == ' ' && !counting) { counting = true; }
      while(counting)
      {
      if(digit_ctr > 4){
        numbers.push_back(number);
        cout << "number: " << number << "\n";
        number = "";
        digit_ctr = 0;
      }
      spaces = 0; 
        if(input[idx] == ' ')
          ++spaces;
        else 
        { 
          cout << "spaces: " << spaces << "\n";
          counting = false; 
          ++digit_ctr;
          if(spaces % 2 == 0){
            number += "1";
          }
          else {
            number += "0";
          }
        }

        ++idx;
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
    cout << "Binary " << i << ": " << ctr << "\n";
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
