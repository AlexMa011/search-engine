#ifndef __INDEX_H__
#define __INDEX_H__

#include<iostream>
#include<cstring>
#include"linklist.h"

using namespace std;

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


template<class E>
HashTable<E>::HashTable(int d,int sz){
	divisor=d;
	tablesize=sz;
	table=new slot<E>[tablesize];
};

template<class E>
HashTable<E>::~HashTable(){
	for(int i=0;i<tablesize;i++){
		table[i].chain.makeempty();
	}
	delete []table;
};

template<class E>
int HashTable<E>::hashfunc(string key){
	unsigned long hash=5381;
	for(int i=0;i<key.length();i++){
		hash=((hash<<5)+hash)+key[i];
	}
	return hash%divisor;
}

template<class E>
void HashTable<E>::addpage(string key,E newpage){
	invertedindex<E> newword(key,newpage);
	int hashval=hashfunc(key);
	if(table[hashval].chain.search(newword)!=NULL){
			table[hashval].chain.search(newword)->data.page.insert(newpage);
	}
	else{
		table[hashval].chain.insert(newword);
		table[hashval].content++;
	}
};

template<class E>
LinkNode<E> *HashTable<E>::search(string key){
	invertedindex<E> newword(key);
	int hashval=hashfunc(key);
	if(table[hashval].chain.search(newword)!=NULL){
		return table[hashval].chain.search(newword)->data.page.gethead();
	}
	else{
		return NULL;
	}
}


template<class E>
void HashTable<E>::output(){
	for(int i=0;i<tablesize;i++){
		cout<<i<<" ";
		table[i].chain.output();
	}
}

#endif
