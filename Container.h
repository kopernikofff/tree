template <class T>
class Container
{
public:
	// ����������� ������, ����� ����������� ����� 
	virtual void insert(T x) = 0;
	virtual bool exists(T x) = 0;
	virtual void remove(T x) = 0;
	// ��� ����� ������� �� ������������� �������� <<
	virtual void print() = 0;

	// ����������� ����������
	virtual ~Container();
};

template <class T>
Container<T>::~Container() { }