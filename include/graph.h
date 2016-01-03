#ifndef __GRAPH_H__
#define __GRAPH_H__

#include"linklist.h"


//the vertex element of adjancy list
struct vertex{
	int data;//store the reference number of a article
	string title;
	LinkList<int> connected;//the edges connected to the vertex
};

//the graph class represent as adadjacency list
class Graph{
public:
	Graph(int sz);
	~Graph();
	int NumofVertices(){return VerticesNumber;}
	int NumofEdges(){return EdgesNumber;}
	bool insertVertex(int vertex);
	bool insertEdge(int v1,int v2);
	void addtitle(string titieg,int vertexnum);
	void calref();//calculate the reference number of articles
	void output();//print the while graph
	int getref(int i){return (i>=0 && i<VerticesNumber)?NodeTable[i].data:0;}//read the refnum of some vertex
	string gettitle(int i){return (i>=0 && i<VerticesNumber)?NodeTable[i].title:0;}//read the title of some vertex

private:
	vertex *NodeTable;
	int VerticesNumber;
	int EdgesNumber;
	int maxVertices;
};


#endif
