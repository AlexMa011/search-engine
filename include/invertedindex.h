#ifndef __INVERTEDINDEX_H__
#define __INVERTEDINDEX_H__

#include<iostream>
#include<cstring>
#include"linklist.h"

using namespace std;

struct locinfo{
	int vertexnum;//the serial number
	int refnum;//the referrence number
	locinfo(){}
	locinfo(int vertexnumg,int refnumg):vertexnum(vertexnumg),refnum(refnumg){}
	bool operator<(locinfo &L){
		if(refnum<L.refnum)
			return true;
		else if(refnum==L.refnum && vertexnum>L.vertexnum)
			return true;
		else
			return false;
	}
	bool operator>(locinfo &L){
		if(refnum>L.refnum)
			return true;
		else if(refnum==L.refnum && vertexnum<L.vertexnum)
			return true;
		else
			return false;
	}
	friend ostream &operator<<(ostream &out,locinfo &L){
		return out<<L.vertexnum<<":cited by "<<L.refnum<<" articles: "<<endl;;
	}
};

class invertedindex{
public:
	invertedindex(){page=LinkList<locinfo>();}
	invertedindex(string word):key(word){page=LinkList<locinfo>();}
	invertedindex(string word,locinfo newpage):key(word){page=LinkList<locinfo>(newpage);}
	bool operator==(invertedindex &L){
		if(L.key==key)
			return true;
		else
			return false;
	}
	friend ostream &operator<<(ostream &out,invertedindex &L){
		return out<<L.key<<L.page;
	}
	string key;
	LinkList<locinfo> page;
};

#endif
