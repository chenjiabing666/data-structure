#include <iostream>
#include "stack.h" 
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	stack app(99);
	double node;
	cout<<"请输入转化的数：";
	cin>>node; 
	cout<<"转化后的二进制："; 
	app.Convert(node); 
	return 0;
}
