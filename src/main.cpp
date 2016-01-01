#include<iostream>
#include<fstream>
#include<sstream>
#include<cstring>
#include<cassert>
#include"graph.h"
#include"index.h"

using namespace std;

void graph_init();

int main(){
	graph_init();

	ofstream interesting("haha.txt");
	//construct the inverted-index hash table
	fstream doc("documents.txt");
	HashTable<edgeelement> index(19997,20000);
	string number;
	string title;
	string abstract;
	string blank;
	//construct the reference graph
	while(getline(doc,number)){
		getline(doc,title);
		getline(doc,abstract);
		getline(doc,blank);
		stringstream numstream(number);
		numstream.ignore();
		numstream.ignore();//ignore the two #
		int article_num;
		numstream>>article_num;
		int ref_num=ref.getvalue(article_num);
		edgeelement article(article_num,ref_num);
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
	string input;
	while(cin>>input){
		LinkNode<edgeelement> *p=index.search(input)->link;
		while(p!=NULL){
			cout<<p->data.refnum<<endl;
			p=p->link;
		}
	}
	return 0;
}
