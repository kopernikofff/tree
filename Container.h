template <class T>
class Container
{
public:
	// Виртуальные методы, будут реализованы далее 
	virtual void insert(T x) = 0;
	virtual bool exists(T x) = 0;
	virtual void remove(T x) = 0;
	// Это потом заменим на перегруженный оператор <<
	virtual void print() = 0;

	// Виртуальный деструктор
	virtual ~Container();
};

template <class T>
Container<T>::~Container() { }