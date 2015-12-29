#ifndef __INDEX_H__
#define __INDEX_H__

#include<iostream>
#include"linklist.h"

template<class T,class E>
struct invertedindex{
	T key;
	LinkList<E> page;
};

template<class T,class E>
class HashTable{
public:
	HashTable(int d,int sz);
	HashTable(HashTable &L);
	~HashTable(){delete []Table;}
	void addpage(T key,E newpage);
	bool search(T key);
private:
	int divisor;
	int tablesize;
	invertedindex<T,E> **Table;
};

#endif
