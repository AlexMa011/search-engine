#include<iostream>
#include<cstring>
#include"hashtable.h"

using namespace std;

HashTable::HashTable(int d,int sz){
	divisor=d;
	tablesize=sz;
	table=new slot[tablesize];
};


HashTable::~HashTable(){
	for(int i=0;i<tablesize;i++){
		table[i].chain.makeempty();
	}
	delete []table;
};

int HashTable::hashfunc(string key){
	unsigned long hash=5381;
	for(int i=0;i<key.length();i++){
		hash=((hash<<5)+hash)+key[i];
	}
	return hash%divisor;
}

void HashTable::addpage(string key,locinfo newpage){
	invertedindex newword(key,newpage);
	int hashval=hashfunc(key);
	if(table[hashval].chain.search(newword)!=NULL){
		if(table[hashval].chain.search(newword)->data.page.gethead()->link->data.vertexnum!=newpage.vertexnum)
			table[hashval].chain.search(newword)->data.page.insert(newpage);
	}
	else{
		table[hashval].chain.insert(newword);
		table[hashval].chain.search(newword)->data.page.insert(newpage);
		table[hashval].content++;
	}
};

LinkList<locinfo> HashTable::search(string key){
	LinkList<locinfo> nulllist;
	invertedindex newword(key);
	int hashval=hashfunc(key);
	if(table[hashval].chain.search(newword)!=NULL){
		return table[hashval].chain.search(newword)->data.page;
	}
	else{
		return nulllist;
	}
}

//rank the pages according to their referrence number
void HashTable::rank(){
	for(int i=0;i<tablesize;i++){
		LinkNode<invertedindex> *p=table[i].chain.gethead()->link;
		while(p!=NULL){
			//cout<<p->data.key<<endl;
			p->data.page.sort();
			p=p->link;
		}
	}
}


//output the whole hash table
ostream& operator<<(ostream& out,HashTable &L){
	for(int i=0;i<L.tablesize;i++){
		out<<L.table[i].chain;
	}
	return out;
}

