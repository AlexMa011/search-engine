#include<iostream>
#include<fstream>
#include<sstream>
#include<cstring>
#include<cassert>
#include"graph.h"
#include"hashtable.h"

using namespace std;

const int maxVertices=20000;


Graph graph_init(){
	//calculate the reference number of every article
	fstream link("doc/link.txt");
	Graph ref(maxVertices);
	string line;//store every line in "link.txt"
	//construct the reference graph
	while(getline(link,line)){
		int vertex;//store the serial number of the article
		int num;//store the number the article is referred to
		stringstream linestream(line);
		linestream.ignore();
		linestream.ignore();//ignore the 2 #
		linestream>>vertex;
		assert(ref.insertVertex(vertex)==true);
		linestream.ignore();//ignore the :
		linestream>>num;
		linestream.ignore();//ignore the :
		int edge;//the articles referring to this article
		while(linestream>>edge){
			assert(ref.insertEdge(vertex,edge)==true);
		}
	}
	ref.calref();//calculate the referrence number of every article
	ref.output();//print the graph
	return ref;
}

