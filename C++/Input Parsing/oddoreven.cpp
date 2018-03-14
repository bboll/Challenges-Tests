#include <iostream>
using namespace std;
 
bool isEven(int f)
{
    //one line here
    return f == ((f>>1)<<1);
}
 
int main (int argc, char * argv[])
{
    int f = static_cast<int>(argv[0]);
    cout << f << ( isEven(f)  ?  " is even" : " is odd" ) << endl;
    return 0;
}
