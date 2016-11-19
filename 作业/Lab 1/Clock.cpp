#include "iostream" 
#include "clock.h"
using namespace std;
/*ostream& operator<<(ostream &out, const clockType &C)
{
	out << "hour:" << C.hr << endl
		<< "minute:" << C.min << endl
		<< "second:" << C.sec << endl;
	return out;
}*/
ostream & operator<<(ostream &output,clockType &c)
{

	output<<c.hr<<":"<<c.min<<":"<<c.sec<<endl; 
     return output;
} 

clockType operator+(clockType & a, clockType & b)
{
	clockType temp;
	temp.hr=a.hr + b.hr;
	temp.min=a.min + b.min;
	if (temp.min >= 60) {
		temp.min -= 60;
		temp.hr += 1;
	}
	temp.sec=a.sec + b.sec;
	if (temp.sec >= 60) {
		temp.sec -= 60;
		temp.min += 1;
	}
	if (temp.min >= 60) {
		temp.min -= 60;
		temp.hr += 1;
	}
	return temp;
}

