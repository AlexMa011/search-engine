#include<iostream>
#include<fstream>
#include<sstream>
#include<cstring>
#include<cassert>
#include"graph.h"
#include"index.h"

using namespace std;

extern Graph ref;

void hashtable_init(){
	ofstream interesting("haha.txt");
	//construct the inverted-index hash table
	fstream doc("documents.txt");
	HashTable<edgeelement> index(19997,20000);
	string serial;//the serial number of the article
	string title;//the title of the article
	string abstract;//the abstract of the article
	string blank;//for blank line
	while(getline(doc,serial)){
		getline(doc,title);
		getline(doc,abstract);
		getline(doc,blank);
		stringstream serialstream(serial);
		serialstream.ignore();
		serialstream.ignore();//ignore the two #
		int serialnum;
		serialstream>>serialnum;
		int refnum=ref.getvalue(serialnum);
		edgeelement article(serialnum,refnum);
		stringstream titlestream(title);
		stringstream abstractstream(abstract);
		string word;
		titlestream>>word;//ignore the word "title"
		while(titlestream>>word){
			interesting<<word<<" ";
			index.addpage(word,article);
		}
		interesting<<endl;
		abstractstream>>word;//ignore the word "abstract"
		while(abstractstream>>word){
			interesting<<word<<" ";
			index.addpage(word,article);
		}
		interesting<<endl;
	}
}
