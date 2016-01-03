#ifndef __STACK_H__
#define __STACK_H__

template<class T>
class stack{
public:
	stack(int sz=50);
	~stack(){delete []elements;}
	void push(const T&x);
	void pop(T &x);
	bool IsEmpty(){return (top==-1)?true:false;}
private:
	T *elements;
	int top;
	int maxsize;
};

template<class T>
stack<T>::stack(int sz):top(-1),maxsize(sz){
	elements=new T[maxsize];
}

template<class T>
void stack<T>::push(const T &x){
	top++;
	elements[top]=x;
}

template<class T>
void stack<T>::pop(T &x){
	x = elements[top];
	top--;
}

#endif
