#ifndef __HASHTABLE_H__
#define __HASHTABLE_H__

#include<cstring>
#include"invertedindex.h"
#include"linklist.h"

using namespace std;
 
struct slot{
	int content;
	LinkList< invertedindex > chain;
};

class HashTable{
public:
	HashTable(int d,int sz);
	HashTable(HashTable &L);
	~HashTable();
	int hashfunc(string key);
	void addpage(string key,locinfo newpage);
	LinkList<locinfo> search(string key);
	void rank();
	friend ostream& operator<<(ostream& out,HashTable &L);
private:
	int divisor;
	int tablesize;
	slot *table;
};

#endif
