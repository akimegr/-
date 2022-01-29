#include <iostream>

using namespace std;

struct tNode {
	int field;
	tNode* left;
	tNode* right;
};

void addnode(int x, tNode*& Ntree) {
	if (!Ntree) {	//если дерева нет - формируем
		Ntree = new tNode;
		Ntree->field = x; //поле данных
		Ntree->left = NULL;
		Ntree->right = NULL;
	}
	if (x < Ntree->field)	//для левого
	{
		if (Ntree->left != NULL) addnode(x, Ntree->left); //При помощи рекурсии заталкиваем элемент на свободный участок
		else                                          //Если элемент получил свой участок, то
		{
			Ntree->left = new tNode;                      //Выделяем память левому подзвену. Именно подзвену, а не просто звену
			Ntree->left->left = Ntree->left->right = NULL;        //У левого подзвена будут свои левое и правое подзвенья, инициализируем их пустотой
			Ntree->left->field = x;                          //Записываем в левое подзвено записываемый элемент
		}
	}
	if (x > Ntree->field)          //Если нововведенный элемент x больше чем элемент x из семечка дерева, уходим вправо
	{
		if (Ntree->right != NULL) addnode(x, Ntree->right); //При помощи рекурсии заталкиваем элемент на свободный участок
		else                                          //Если элемент получил свой участок, то
		{
			Ntree->right = new tNode;                 //Выделяем память правому подзвену. Именно подзвену, а не просто звену
			Ntree->right->left = Ntree->right->right = NULL;   //У правого подзвена будут свои левое и правое подзвенья, инициализируем их пустотой
			Ntree->right->field = x;                     //Записываем в правое подзвено записываемый элемент
		}
	}
	
}

void print(tNode* tree, int &counter) {
	if (tree==NULL)
		return;//дерева нет
	cout << tree->field <<" left: " <<tree->left << " right: " <<tree->right<< " my: "<< tree <<endl;
	print(tree->left, counter);
	print(tree->right, counter);
	if (tree->left == NULL && tree->right == NULL)
		counter++;

}

int main() {
	int counter = 0;
	tNode* root = NULL;
	int i;
	while (true) {
		cout << "Enter i: " << endl;
		cin >> i;
		if (i == 0)
			break;
		else {
			addnode(i,root);
		}
	}
	print(root, counter);
	cout << "Counter: " << counter;

}