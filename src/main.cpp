#include "hashtable.h"
#include "graph.h"
#include <iostream>
	
using namespace std;

Graph graph_init();
void hashtable_init(Graph&);

int main(){
	Graph ref=graph_init();
	hashtable_init(ref);
	return 0;
}
