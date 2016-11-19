// BST.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "iostream"

#include "BS.h"
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	//cout << "chenjaibing" << endl;
	BST app;
	app.creat2();
	
	app.preorder();
	//app.count();
	//app.insert();
	app.deletemin();
	app.preorder();
	
	
	return 0;
}

