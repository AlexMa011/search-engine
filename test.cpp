#include<iostream>
#include"linklist.h"

using namespace std;

int main(){
	LinkList<int> a;
	a.insert(2);
	a.insert(6);
	a.insert(16);
	a.output();
	return 0;
}
