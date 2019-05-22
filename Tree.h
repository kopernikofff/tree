#include "Node.h"
#include "Container.h"
#include <iostream>

using namespace std;

template <class T>
class Tree : public Container<T> {
public:
	Tree() : root(NULL) {};

	void insert(T x)
	{
		root = insert(root, x);
	};
	bool exists(T x)
	{
		return exists(root, x) != NULL;
	};
	void remove(T x)
	{
		root = remove(root, x);
	};
	void print()
	{
		cout << endl;
		print(root, 0);
		cout << endl;
	};

	~Tree()
	{
		clear(root);
	};

private:
	Node<T>* root;

	Node<T>* insert(Node<T>* p, T x)
	{
		if (p == NULL)
			return new Node<T>(x);
		if (x > p->data) 
			p->right = insert(p->right, x);
		else if (x < p->data)
			p->left = insert(p->left, x);
		return balance(p);
	}
	Node<T>* exists(Node<T>* p, T x)
	{
		if (p == NULL)
			return NULL;
		if (x == p->data)
			return p;
		if (x > p->data)
			return exists(p->right, x);
		if (x < p->data)
			return exists(p->left, x);
	}
	void print(Node<T>* p, int depth)
	{
		if (p == NULL)
			return;
		print(p->right, depth + 1);
		for (int i = 0; i < depth; i++) 
		{
			cout << "--";
		}
		cout << p->data << "\n";
		print(p->left, depth + 1);
	}
	void clear(Node<T>* p)
	{
		if (p == NULL)
			return;
		clear(p->left);
		clear(p->right);
		delete p;
	}

	Node<T>* find_min(Node<T> * p) // Поиск узла с минимальным ключом в дереве p
	{
		return p->left ? find_min(p->left) : p;
	}
	Node<T>* remove_min(Node<T> * p) // Удаление узла с минимальным ключом из дерева p
	{
		if (p->left == NULL)
			return p->right;
		p->left = remove_min(p->left);
		return balance(p);
	}
	Node<T>* remove(Node<T> * p, T x)
	{
		if (p == NULL)
			return NULL;
		if (x < p->data)
			p->left = remove(p->left, x);
		else if (x > p->data)
			p->right = remove(p->right, x);
		else //  x == p->data
		{
			Node<T>* l = p->left;
			Node<T>* r = p->right;
			delete p;
			if (!r) return l;
			Node<T>* min = find_min(r);
			min->right = remove_min(r);
			min->left = l;
			return balance(min);
		}
		return balance(p);
	}

	unsigned char height(Node<T> * p)
	{
		return p ? p->height : 0;
	}
	signed char balance_factor(Node<T>* p) // Разница высот правого и левого поддеревьев
	{
		return height(p->right) - height(p->left);
	}
	void fix_height(Node<T>* p) // Восстанавливает корректное значение поля height заданного узла
	{
		unsigned char hl = height(p->left);
		unsigned char hr = height(p->right);
		p->height = ((hl > hr) ? hl : hr) + 1;
	}
	Node<T>* left_rotate(Node<T> * p) // Левый поворот вокруг р
	{
		Node<T>* q = p->right;
		p->right = q->left;
		q->left = p;
		fix_height(p);
		fix_height(q);
		return q;
	}
	Node<T>* right_rotate(Node<T> * p) // Правый поворот вокруг p
	{
		Node<T>* q = p->left;
		p->left = q->right;
		q->right = p;
		fix_height(p);
		fix_height(q);
		return q;
	}
	Node<T>* balance(Node<T>* p)
	{
		fix_height(p);
		if (balance_factor(p) == 2) 
		{
			if (balance_factor(p->right) < 0)
				p->right = right_rotate(p->right);
			return left_rotate(p);
		}
		if (balance_factor(p) == -2) 
		{
			if (balance_factor(p->left) > 0)
				p->left = left_rotate(p->left);
			return right_rotate(p);
		}
		return p;
	}
};
