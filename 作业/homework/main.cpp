#include <iostream>
#include "Bintree.cpp"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	BinTree<int> BT;
	BT.CreateBinTree();
	BT.PreOrder();
	cout << "preorder non recursion:"<<endl;
	BT.PreOrder_non_recursion();
	cout << "Inorder non recursion:"<<endl;
	BT.InOrder_non_recursion();
	//BT.CreateBinTree(BT.root);
	//BT.PreOrder(BT.root);
	BT.countLeaf();//р╤вс╫з╣Ц 
	BT.countnumber0f1();
	BT.countnumberoffull();
	BT.countnumber();
	
	
 
	return 0;
}
