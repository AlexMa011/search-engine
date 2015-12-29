#include <iostream>
#include "linklist.h"

using namespace std;

//copy constrcutior function
template<class T>
LinkList<T>::LinkList(LinkList<T> &L){
	LinkNode<T> *srcptr=L.gethead()->link;
	LinkNode<T> *destptr=new LinkNode<T>;
	while(srcptr!=NULL){
		destptr->link=new LinkNode<T>(srcptr->data);
		destptr=destptr->link;
		srcptr=srcptr->link;
	}
	first=destptr;
}

//delete the whole list
template<class T>
void LinkList<T>::makeempty(){
	while(first->link!=NULL){
		LinkNode<T> *p=first->link;
		first->link=p->link;
		delete p;
	}
}

//calculate the length of the list
template<class T>
int LinkList<T>::Length(){
	int i=0;
	LinkNode<T> *p=first->link;
	while(p!=NULL){
		i++;
		p=p->link;
	}
	return i;
}

//search the element in the list
template<class T>
LinkNode<T> *LinkList<T>::search(T x){
	LinkNode<T> *p=first->link;
	while(p!=NULL){
		if(p->data==x)
			return p;
		p=p->link;
	}
	return NULL;
}

//insert an element in the list
template<class T>
void LinkList<T>::insert(T x){
	LinkNode<T> *p=new LinkNode<T>(x);
	p->link=first->link;
	first->link=p;
}

template<class T>
void LinkList<T>::output(){
	LinkNode<T> *p=first->link;
	while(p!=NULL){
		cout<<p->data<<" ";
		p=p->link;
	}
	cout<<endl;
}
