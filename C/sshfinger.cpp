#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

const int REQUIRED_ARGS = 3;

int help() {
  cout << "Usage: sshfinger [host] [user]\n";

  return 1;
}

bool hostcharvalid(char x){

if(isalnum(x) || x == '.' || x == '-') { return true; }

  return false;

}



int main(int argc, char* argv[])
{
  bool error_flag = false;
  bool error_label_max = false;
  bool error_num = false;
  bool error_caps = false;

  //command line arg validation
  //argv[0] is program name sshfinger
  if (argc != REQUIRED_ARGS)
  {
    return help();
  }

  string hostname = argv[1];
  string user = argv[2];

  //HOST VALIDATION
  if(hostname.size() > 255){
    cout << "Hostname has 255 char limit.\n";
    error_flag = true;
  }

  //Check first character
  if(!isalnum(hostname[0])){
    cout << "First character of hostname must be alphanumeric.\n";
    error_flag = true;
  }

  //Check last character
  size_t hostsize = hostname.size()-1;
  if(hostname[hostsize]=='-'){
    cout << "Hostname may not end with a hyphen.\n";
    error_flag = true;
  }
  
  //Check through string
  for(int idx=1, ctr=0; idx < hostname.size(); ++idx, ++ctr)
  {
    if(ctr>63 && !error_label_max){
      cout << "Labels (between periods) must be between 1 to 63 characters.\n";
      error_flag = true;
      //Prevents multipe printouts if already found
      error_label_max = true;
    }
    //Checks for invalid input
    if(!hostcharvalid(hostname[idx])){
      cout << "Invalid char in host name, must use symbols from alphabet or hyphen.\n";
      error_flag = true;
    }

    if(hostname[idx]=='.'){
      if(idx < hostname.size()-1 && !isalnum(hostname[idx+1])){
        cout << "Must have at least one alphanumeric characters between periods.\n";
        error_flag = true;
      }
      if(hostname[idx-1]=='-'){
        cout << "Cannot end a label (before a period) with a hyphen.\n";
        error_flag = true;
      }

      //Need to reset counter
      ctr=0; 
    }
  }

  
  //USER VALIDATION
  if(user.size() > 32)
  {
    cout << "User name has 32 char limit.\n";
    error_flag = true;
  }

  if(!isalpha(user[0])){
    cout << "First char in user name must be a letter.\n";
    error_flag = true;
  }

  for(int idx=0; idx < user.size(); ++idx)
  {
    if(!isalnum(user[idx])){
      cout << "User name must be alphanumeric.\n";
      error_flag = true;
    }

    if(isdigit(user[idx]) && !error_num){
      int ctr = idx;

      if(isupper(user[0]) && !error_caps){
        cout << "First character in user name cannot be capitalised if there are numbers.\n";
        error_caps = true;
        error_flag = true;
      }

      for(; ctr < user.size(); ++ctr){
        if(isalpha(user[ctr]) && !error_num){
          cout << "Numbers in username must come at the end.\n";
          error_flag = true;
          error_num = true;
        }
      }
    }
  }

//if error_flag == false then construct the system command
  if(!error_flag)
  {
    string command;
    command += "/usr/bin/ssh ";
    command += hostname;
    command += " /usr/bin/finger ";
    command += user;
    cout << command << "\n";
    const char* command_str = command.c_str();
    int error_code = system(command_str);
    if(error_code==-1){
      cout << "Error with finger command\n";
    }
    
  }

  return 0;
}
