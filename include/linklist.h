#ifndef __LINKLIST_H__
#define __LINKLIST_H__

#include<iostream>

//define the linknode structure
template<class T>
struct LinkNode{
	T data;
	LinkNode<T> *link;
	//initialize
	LinkNode(LinkNode<T> *ptr=NULL){link=ptr;}
	LinkNode(const T& item,LinkNode<T> *ptr=NULL)
		{data=item;link=ptr;}
};


//define the linklist class
template<class T>
class LinkList{
public:
	LinkList(){first=new LinkNode<T>;}
	LinkList(const T&x){first=new LinkNode<T>(x);}
	LinkList(LinkList<T> &L);//copy constructor function
	~LinkList(){makeempty();}
	void makeempty();
	int Length();
	LinkNode<T> *search(T x);
	LinkNode<T> *gethead(){return first;}
	void insert(T x);
	void output();
	void partition(LinkNode<T> *start,LinkNode<T> *end);
	void sort();
private:
	LinkNode<T> *first;
};

#include "linklist.cpp"

#endif
