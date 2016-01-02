#ifndef __LINKLIST_H__
#define __LINKLIST_H__

#include<iostream>

using namespace std;

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
	void partition(LinkNode<T> *start,LinkNode<T> *end);
	void sort();
	template<class S>
	friend ostream &operator<<(ostream &out,LinkList<S> &L);
private:
	LinkNode<T> *first;
};


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
void LinkList<T>::partition(LinkNode<T> *start,LinkNode<T> *end){
	if(start==end)
		return;
	T pivot=start->data;
	LinkNode<T> *p=start;
	LinkNode<T> *q=start->link;
	while(q!=end){
		if(q->data>pivot){
			T swap=q->data;
			q->data=p->link->data;
			p->link->data=swap;
			p=p->link;
		}
		q=q->link;
	}
	start->data=p->data;
	p->data=pivot;
	partition(start,p);
	partition(p->link,end);
}

template<class T>
void LinkList<T>::sort(){
	partition(first->link,NULL);
}

template<class S>
ostream & operator<<(ostream &out,LinkList<S> &L){  
	LinkNode<S> *p=L.first->link;
	out<<" ";
	while(p!=NULL){
		out<<p->data<<" ";
		p=p->link;
	}
	out<<endl;
	return out;
}

#endif
