#include "hashtable.h"
#include "graph.h"
#include <iostream>
	
using namespace std;

Graph graph_init();
void hashtable_init(Graph&,HashTable&);
void retrieval(Graph&,HashTable&);

int main(){
	Graph ref=graph_init();
	cout<<"step 1 is done!"<<endl;
	HashTable index(19997,20000);
	hashtable_init(ref,index);
	cout<<"step 2 is done!"<<endl<<"Let's search!"<<endl;
	retrieval(ref,index);
	return 0;
}
