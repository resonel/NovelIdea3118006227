#include<iostream>
using namespace std;
#define STACK_SIZE 10
template<class  T>
class stack
{
public:
	stack()
		:_size(0)
	{}

	void push(const T& data)
	{    
		if (_size == STACK_SIZE)
			return;
		_array[_size++] = data;
	}

	
 void pop()
	{
		--_size;
	}

T& Top()
 {
	 return _array[_size - 1];
 }
 const T& Top()const
 {
	 return _array[_size - 1];
 }

 
 size_t size()const
 {
	 return _size;
 }

 
 bool Empty()const
 {
	 return 0 == _size;
 }
	
private:
       T _array[STACK_SIZE];
		int _size;
};

int main()
{
	stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
cout << "The top is "<<s.Top() << endl;
	s.pop();
    s.pop();
    s.pop();
cout << "The top is "<<s.Top() << endl;

system("pause");
return 0;
}

