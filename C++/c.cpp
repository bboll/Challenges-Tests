#include <string>
#include <iostream>
#include <vector>
#include <stdio.h>
#include <sstream>

using namespace std;

const int MAX_SIZE = 2000;

void generateNonEs(vector<int>& list)
{
    ostringstream stream1;
    string temp;
    int i = 1,
        place_counter = 0;

    do {
        // Convert int to string
        stream1.str("");
        stream1.clear();
        stream1 << i;
        temp = stream1.str();

        place_counter = 0;
        bool found_e = false;

        for (int it = temp.length() - 1; it > 0 || !found_e; --it, ++place_counter) {
            // zeroes, thousands
            if ((place_counter % 3) == 0) {
                if ((temp[it] != '2') && (temp[it] != '4') && (temp[it] != '6') && (temp[it] != '0')) {
                    found_e = true;
                }
            }

            // tens, ten thousands
            if ((place_counter % 3) == 1) {
                if ((temp[it] != '3') && (temp[it] != '4') && (temp[it] != '5') && (temp[it] != '6') && (temp[it] != '0')) {
                    found_e = true;
                }

            }

            // hundreds, hundred thousands
            if ((place_counter % 3) == 2) {
                if (temp[it] != '0') {
                    found_e = true;
                }
            }


            if (it == 0 && !found_e) {
                list.push_back(i);
            }
        }

        ++i;
    } while (list.size() < MAX_SIZE);
}

string addCommas(int num){

  string output="";
  ostringstream stream3;

  // Convert int to string
  stream3.str("");
  stream3.clear();
  stream3 << num;
  output = stream3.str();
  int size = output.size();
  for(int idx=output.size(); idx > 0; --idx)
  {
    if(idx % 3 == 1 && idx > 3){
      string leftofcomma, rightofcomma;
      leftofcomma = output.substr(0, idx-3);
      rightofcomma = output.substr(idx-3, size);
      output = leftofcomma + "," + rightofcomma;
    }
  }
  
  return output;
}




int main()
{
    string tmp="";

    //might have to be vector of long
    vector<int> list_of_non_e, input;

    generateNonEs(list_of_non_e);
    
    int tmp_int=0;
    istringstream stream2;
    
    while(tmp!="0"){
      getline(cin, tmp);
      stream2.str("");
      stream2.clear();
      stream2.str(tmp);
      stream2 >> tmp_int;  
      input.push_back(tmp_int);
    }
    
    int current_num;
    //Offset by 1, ignore the 0
    for(int idx=0; idx<input.size()-1; ++idx)
    {
      //Offset by 1
      current_num = input[idx]-1;

      //Call insert commas on string in vector
      cout << addCommas(list_of_non_e[current_num]) << "\n";
    }

    return 0;
}

