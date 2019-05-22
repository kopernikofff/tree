#include "Tree.h"

int main()
{
	Tree<char> tree; //Тип можно менять 

	int n;
	cout << "Enter n: ";
	cin >> n;
	char x; //Тип можно менять 
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		tree.insert(x);
	}
	tree.print();
	
	cout << "Enter x to check exist: ";
	cin >> x;
	if (tree.exists(x))
		cout << "Exist" << endl;
	else cout << "Not exist" << endl;
	cout << endl;

	cout << "Enter x to remove: ";
	cin >> x;
	tree.remove(x);
	tree.print();

	system("pause");
	return 0;
};