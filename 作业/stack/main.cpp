#include <iostream>
#include "stack.h" 
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	stack app(99);
	double node;
	cout<<"������ת��������";
	cin>>node; 
	cout<<"ת����Ķ����ƣ�"; 
	app.Convert(node); 
	return 0;
}
