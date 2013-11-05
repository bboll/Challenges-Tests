#include <iostream>
#include <vector>
#include <string>
#include <list>

using namespace std;

int main()
{
  vector<string> input;
  vector<string> ignore_list;
  vector<int> case_end_indices;
  string in;
  
  int idx=0;
  
  while(in != "0")
  {
    getline(cin, in);

    input.push_back(in);
    
    if(in == "LAST CASE")
    {
      input.pop_back();
      case_end_indices.push_back(idx);
    }
    ++idx;
  }
  
  int ctr=0;

  
  string string_input;
  int found;

  ignore_list.push_back("and");
  ignore_list.push_back("of");
  cout << "Ignoring: " << ignore_list[0] << "\n";
  
  //Jam it back into a string
  for(int idx=0; idx<input.size(); ++idx)
    string_input += input[idx];

  cout << "Valid string: " << string_input << "\n";
  //Rip out ignores
  for(int idx=0; idx<ignore_list.size()+1; ++idx)
  {
    while(found!=string::npos)
    {
      found = 0;
      found = string_input.find(ignore_list[idx]); 
      cout << "Found at: " << found << "\n";
      int ignore_length = ignore_list[idx].length();
      if(found!=string::npos){
        string_input.erase(found, found+ignore_length);
      }
    }
  }
  cout << "Valid string: " << string_input << "\n";

/*
  //Test vectors
  for(int idx = 0; idx < input.size(); ++idx)
  {
    cout << input[idx];

    if(idx == case_end_indices[ctr]){
      cout << "\n";
      ++ctr;
    }
  }
*/

  return 0;
}
