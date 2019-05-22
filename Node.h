#include <cstdlib>

template <class T>
class Node {
public:
	Node(T x) : left(NULL), right(NULL), data(x), height(1) {}

	Node* left;
	Node* right;
	T data;
	unsigned char height; // Высота поддерева с корнем в данном узле
};
