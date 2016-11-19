#include "iostream" 
using namespace std;
class clockType {
private:
	int hr, min, sec;
public:
	clockType(int h=0, int m=0, int s=0):hr(h),min(m),sec(s) {}
	friend ostream & operator<<(ostream &output,clockType &c);
	friend clockType operator +(clockType&, clockType&);
};
