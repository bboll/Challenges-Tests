<br />
<font size='1'><table class='xdebug-error xe-notice' dir='ltr' border='1' cellspacing='0' cellpadding='1'>
<tr><th align='left' bgcolor='#f57900' colspan="5"><span style='background-color: #cc0000; color: #fce94f; font-size: x-large;'>( ! )</span> Notice: Undefined variable: _SESSION in C:\cygwin\home\Brian\CS-1-Web\shared_php\saveForm_conf.php on line <i>3</i></th></tr>
<tr><th align='left' bgcolor='#e9b96e' colspan='5'>Call Stack</th></tr>
<tr><th align='center' bgcolor='#eeeeec'>#</th><th align='left' bgcolor='#eeeeec'>Time</th><th align='left' bgcolor='#eeeeec'>Memory</th><th align='left' bgcolor='#eeeeec'>Function</th><th align='left' bgcolor='#eeeeec'>Location</th></tr>
<tr><td bgcolor='#eeeeec' align='center'>1</td><td bgcolor='#eeeeec' align='center'>0.0163</td><td bgcolor='#eeeeec' align='right'>286344</td><td bgcolor='#eeeeec'>{main}(  )</td><td title='C:\cygwin\home\Brian\CS-1-Web\shared_php\saveForm_conf.php' bgcolor='#eeeeec'>..\saveForm_conf.php<b>:</b>0</td></tr>
</table></font>
file<br />
<font size='1'><table class='xdebug-error xe-notice' dir='ltr' border='1' cellspacing='0' cellpadding='1'>
<tr><th align='left' bgcolor='#f57900' colspan="5"><span style='background-color: #cc0000; color: #fce94f; font-size: x-large;'>( ! )</span> Notice: Undefined variable: _SESSION in C:\cygwin\home\Brian\CS-1-Web\shared_php\saveForm_conf.php on line <i>4</i></th></tr>
<tr><th align='left' bgcolor='#e9b96e' colspan='5'>Call Stack</th></tr>
<tr><th align='center' bgcolor='#eeeeec'>#</th><th align='left' bgcolor='#eeeeec'>Time</th><th align='left' bgcolor='#eeeeec'>Memory</th><th align='left' bgcolor='#eeeeec'>Function</th><th align='left' bgcolor='#eeeeec'>Location</th></tr>
<tr><td bgcolor='#eeeeec' align='center'>1</td><td bgcolor='#eeeeec' align='center'>0.0163</td><td bgcolor='#eeeeec' align='right'>286344</td><td bgcolor='#eeeeec'>{main}(  )</td><td title='C:\cygwin\home\Brian\CS-1-Web\shared_php\saveForm_conf.php' bgcolor='#eeeeec'>..\saveForm_conf.php<b>:</b>0</td></tr>
</table></font>
<br />
<font size='1'><table class='xdebug-error xe-notice' dir='ltr' border='1' cellspacing='0' cellpadding='1'>
<tr><th align='left' bgcolor='#f57900' colspan="5"><span style='background-color: #cc0000; color: #fce94f; font-size: x-large;'>( ! )</span> Notice: Undefined variable: _SESSION in C:\cygwin\home\Brian\CS-1-Web\shared_php\saveForm_conf.php on line <i>5</i></th></tr>
<tr><th align='left' bgcolor='#e9b96e' colspan='5'>Call Stack</th></tr>
<tr><th align='center' bgcolor='#eeeeec'>#</th><th align='left' bgcolor='#eeeeec'>Time</th><th align='left' bgcolor='#eeeeec'>Memory</th><th align='left' bgcolor='#eeeeec'>Function</th><th align='left' bgcolor='#eeeeec'>Location</th></tr>
<tr><td bgcolor='#eeeeec' align='center'>1</td><td bgcolor='#eeeeec' align='center'>0.0163</td><td bgcolor='#eeeeec' align='right'>286344</td><td bgcolor='#eeeeec'>{main}(  )</td><td title='C:\cygwin\home\Brian\CS-1-Web\shared_php\saveForm_conf.php' bgcolor='#eeeeec'>..\saveForm_conf.php<b>:</b>0</td></tr>
</table></font>
//Brian Boll
//string.cpp
//CS 33001

#include "string.h"
#include <cstring>
#include <iostream>

using std::ostream;
using std::istream;
namespace cs33001
{

string::string()
{
    _capacity = 0;
    _size = 0;
    chr = new char[1];
}

string::~string()
{
    _size = 0;
    _capacity = 0;
    delete [] chr;
}

string::string(const string& rhs)
{
    _size = rhs._size;
    _capacity = rhs._capacity;
    chr = new char[_capacity];
    for(size_type idx=0; idx<_size; ++idx)
    {
	chr[idx] = rhs.chr[idx];
    }
}

string::string(const char c_string[])
{
    _capacity = strlen(c_string);
    _size = _capacity;
    chr = new char[_capacity];
    for(size_type idx=0; idx<_size; ++idx)
    {
	chr[idx] = c_string[idx];
    }
}

string::string(const size_type in_size, const char var)
{
    _capacity = in_size;
    _size = in_size;
    chr = new char[_capacity];
    for(size_type idx=0; idx<_size; ++idx)
    {
	chr[idx] = var;
    }
}

bool string::operator==(const string& rhs) const
{
    if(_size == rhs._size)
    {
	for(size_type idx=0; idx<_size; ++idx)
	{
	    if(chr[idx]!=rhs.chr[idx]){return false;} 
	}
	return true;
    }
    else {return false;}
}

bool string::operator>(const string& rhs) const
{
    if ((*this) == rhs){ return false; }
    else
    {
	for(size_type idx=0; idx<_size; ++idx)
        {
	    if(chr[idx] > rhs.chr[idx]){ return true; }
	    else 
	    { 
		if(chr[idx]!=rhs.chr[idx]) { return false; } 
	    }
	}  
    }
    return false; //Catches empty and substr
}

bool string::operator<=(const string& rhs) const
{
    if ((*this) < rhs || (*this) == rhs){ return true; }
    else { return false; }
}

bool string::operator<(const string& rhs) const
{
    if ((*this) == rhs){ return false; }
    else
    {
	for(size_type idx=0; idx<_size; ++idx)
        {
	    if(chr[idx] < rhs.chr[idx]){ return true; }
	    else 
	    { 
		if(chr[idx]!=rhs.chr[idx]) { return false; } 
	    }
	}
    }
    return true; //If it makes it here then the lhs is shorter substr of rhs
}

bool string::operator>=(const string& rhs) const
{
    if ((*this) > rhs || (*this) == rhs){ return true; }
    else { return false; }
}

bool string::operator!=(const string& rhs) const
{
    return !( (*this) == rhs );
}

string& string::increase_capacity()
{
    if(_capacity <= 0) { _capacity = 1; }
    else { _capacity = _capacity * 2; }
    char *temp;
    temp = new char[_capacity];
    for(size_type idx=0; idx < _size; ++idx)
    {
	temp[idx] = chr[idx];
    }
    delete [] chr;
    chr = temp;
    return *this;
}

char* string::c_str()
{
    if(_size == _capacity)
    {
	increase_capacity();
    }
    chr[_size] = NULL;  //null one after last element
    return chr;
}

string::size_type string::size()
{
    return _size;
}

string::size_type string::capacity()
{
    return _capacity;
}

void string::swap(string& rhs)
{
    if(chr!=rhs.chr)
    {
	string temp(rhs);			//swap size & capacity
	rhs._size = _size;
	_capacity = temp._capacity;
	_size = temp._size;
	for(size_type ctr=0; ctr < rhs._size; ++ctr)
	{
	    rhs.chr[ctr] = chr[ctr];
	}
	delete [] chr;
	chr = new char[temp._capacity];		//Allocating new memory for this object
	for(size_type ctr=0; ctr < temp._size; ++ctr)
	{
	    chr[ctr] = temp.chr[ctr];
	}
    }
}

string& string::operator=(const string& rhs)
{
    string temp(rhs);				//creates a copy of rhs because it's constant
    swap(temp);
    return *this;
}


string& string::operator+=(const char& item)
{
    if(_size == _capacity)
    {
	increase_capacity();
    }
    chr[_size] = item;
    _size = _size + 1;
    return *this;
}

string operator+(const string& lhs, const char& rhs)
{
    string result(lhs);
    result += rhs;
    return result;
}

string& string::operator+=(const string& rhs)
{
    while(_capacity <= (_size+rhs._size)) { increase_capacity(); }
    for(size_type idx=0; idx<rhs._size; ++idx)
    {
	chr[_size+idx] = rhs.chr[idx];
    }
    _size += rhs._size;
    return *this;
}

string operator+(const string& lhs, const string& rhs)
{
   string result(lhs);
   result += rhs;
   return result; 
}

//Data isn't lost, just put out of access of user
string& string::resize(const size_type new_size)
{
    while(_capacity <= new_size) { increase_capacity(); }
    _size = new_size;
    return *this;
}

string string::substr(const int& start, const int& end)
{
    string result;
    for(size_type idx=start; idx<(start + end) && idx<_size; ++idx)
    {
	result += chr[idx];
    }
    return result;
}

string::size_type string::find(const string& str, const int& start_index)
{
    size_type idx=start_index;
    size_type jdx=0;
    while(idx<_size && jdx<str._size)
    {
	if(chr[idx] == str.chr[jdx]) { ++jdx; } 	//Found char check for contiguous
	else { jdx=0; } 				//Non-contiguous reset search
	++idx;
    }
    if(jdx<str._size){ return -1; }
    else { return (idx-jdx); }   			//Returns where search stopped minus the size of str to find it's index
}

ostream& operator<<(ostream& out, const string& rhs)
{
    for(int idx=0; idx<rhs._size; ++idx)
    {
	out << rhs.chr[idx];
    }
    return out;
}

istream& operator>>(istream& in, string& rhs)
{   
    while(in)
    {
	char temp;
	in >> temp;
	if(in) { rhs += temp; }
    }
    return in;
}


istream& getline(std::istream& in, string& rhs)
{
    while(in && in.peek() != '\n')
    {
	char temp;
	in >> std::noskipws >> temp;  //Formatted to unignore white spaces
	rhs += temp; 
    }
    return in;
}





} // end namespace


			