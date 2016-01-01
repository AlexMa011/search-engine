#ifndef __INDEX_H__
#define __INDEX_H__

#include<iostream>
#include<cstring>
#include"linklist.h"

struct edgeelement{
	int vertexnum;
	int refnum;
	edgeelement(int vertexnumg,int refnumg):vertexnum(vertexnumg),refnum(refnumg){}
};

template<class E>
struct invertedindex{
	string key;
	LinkList<E> page;
	invertedindex(){page=LinkList<E>();}
	invertedindex(string word):key(word){page=LinkList<E>();}
	invertedindex(string word,E newpage):key(word){page=LinkList<E>(newpage);}
	bool operator==(invertedindex &L){
		if(L.key==key)
			return true;
		else
			return false;
	}
	friend ostream &operator<<(ostream &out,invertedindex &L){
		return out<<L.key<<" ";
	}
};

template<class E>
struct slot{
	int content;
	LinkList< invertedindex<E> > chain;
};

template<class E>
class HashTable{
public:
	HashTable(int d,int sz);
	HashTable(HashTable &L);
	~HashTable();
	int hashfunc(string key);
	void addpage(string key,E newpage);
	LinkNode<E> *search(string key);
	void output();
private:
	int divisor;
	int tablesize;
	slot<E> *table;
};

#include"index.cpp"

#endif
