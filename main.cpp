#include<iostream>
#include<fstream>
#include<sstream>
#include<cstring>
#include<cassert>
#include"graph.h"

using namespace std;

const int maxVertices=20000;


int main(){
	//calculate the reference number of every article
	fstream doc("link.txt");
	Graph ref(maxVertices);
	string line;//store every line in "link.txt"
	//construct the reference graph
	while(getline(doc,line)){
		int vertex;
		int num;
		stringstream linestream(line);
		linestream.ignore();
		linestream.ignore();
		linestream>>vertex;
		assert(ref.insertVertex(vertex)==true);
		linestream.ignore();
		linestream>>num;
		linestream.ignore();
		int edge;
		while(linestream>>edge){
			assert(ref.insertEdge(vertex,edge)==true);
		}
		ref.calref();
	}

	//construct the inverted-index hash table
	return 0;
}
