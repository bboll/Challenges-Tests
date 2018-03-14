#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
  string input;
  vector<string> inputs;
  while(input!="#")
  { 
    if(input!="#"){
    getline(cin,input);
    inputs.push_back(input);
    }
  }

  int ctr=0;
  for(int idx=0;idx<inputs.size()-1; ++idx){
    ctr=0;
    string temp = inputs[idx];
    for(int jdx=0; jdx<temp.size(); ++jdx)
      if(temp[jdx]=='1'){ ++ctr; }

    int last = temp.length()-1;
    char lastchar = temp[last];
    if(ctr % 2 == 0)
    {
      if(lastchar == 'e')
        temp[last] = '0';
      else temp[last] = '1';
    }
    else{
      if(lastchar == 'e')
        temp[last] = '1';
      else temp[last] = '0';
    }
    inputs[idx] = temp;
  }
 
  for(int i=0; i<inputs.size()-1; ++i)
    cout << inputs[i] << "\n";
  

  return 0;
}

