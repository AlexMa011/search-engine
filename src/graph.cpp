#include <iostream>
#include "linklist.h"
#include "graph.h"

using namespace std;


Graph::Graph(int sz){
	maxVertices=sz;
	VerticesNumber=0;
	EdgesNumber=0;
	NodeTable=new vertex[maxVertices];
};

Graph::~Graph(){
	for(int i=0;i<=VerticesNumber;i++){
		NodeTable[i].connected.makeempty();
	}
	delete []NodeTable;
}

bool Graph::insertVertex(int vertex){
	if(VerticesNumber==maxVertices) return false;
	NodeTable[vertex].data=0;
	VerticesNumber++;
	return true;
}

bool Graph::insertEdge(int v1,int v2){
	if(v1>=0 && v2>=0){
		NodeTable[v1].connected.insert(v2);
		EdgesNumber++;
		return true;
	}
	return false;
}

void Graph::calref(){
	for(int i=1;i<=VerticesNumber;i++){
		NodeTable[i].data=NodeTable[i].connected.Length();
	}
}

void Graph::output(){
	for(int i=1;i<=VerticesNumber;i++){
		cout<<i<<":"<<NodeTable[i].data<<":";
		cout<<NodeTable[i].connected;
	}
}
