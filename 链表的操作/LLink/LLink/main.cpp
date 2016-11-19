#include "iostream"
#include "Link.h"
using namespace std;
int main()
{
	LLink app;
	for (int i = 0; i < 4; i++)
	{
		int data;
		cout << "input data:";
		cin >> data;
		//app.append(data);
		app.creat(data);
	}

	app.display();
	
	//app.sort1();
	app.sort();
	//app.reverse();
	app.display();


	return 0;
}