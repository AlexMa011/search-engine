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
	LinkList(){first=new LinkNode<T>;rear=first;}
	LinkList(const T&x){first=new LinkNode<T>(x);rear=first;}
	LinkList(LinkList<T> const &L);//copy constructor function
	~LinkList(){makeempty();}
	void makeempty();
	int Length();
	LinkNode<T> *search(T x);
	LinkNode<T> *gethead() const{return first;}
	void insert(T x);
	void insert_from_rear(T x);
	void partition(LinkNode<T> *start,LinkNode<T> *end);
	void sort();
	LinkList<T>& operator=(LinkList<T> const &L);
	template<class S>
	friend ostream &operator<<(ostream &out,LinkList<S> &L);
private:
	LinkNode<T> *first,*rear;
};


//copy constrcutior function
template<class T>
LinkList<T>::LinkList(LinkList<T> const &L){
	LinkNode<T> *srcptr=L.gethead()->link;
	LinkNode<T> *destptr=new LinkNode<T>;
	first=destptr;
	while(srcptr!=NULL){
		destptr->link=new LinkNode<T>(srcptr->data);
		destptr=destptr->link;
		srcptr=srcptr->link;
	}
	rear=first;
	while(rear->link!=NULL)
		rear=rear->link;
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
void LinkList<T>::insert_from_rear(T x){
	while(rear->link!=NULL)
		rear=rear->link;
	LinkNode<T> *p=new LinkNode<T>(x);
	rear->link=p;
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

template<class T>
LinkList<T>& LinkList<T>::operator=(LinkList<T> const &L){
	LinkNode<T> *srcptr=L.gethead()->link;
	LinkNode<T> *destptr=new LinkNode<T>;
	first=destptr;
	while(srcptr!=NULL){
		destptr->link=new LinkNode<T>(srcptr->data);
		destptr=destptr->link;
		srcptr=srcptr->link;
	}
	return *this;
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
