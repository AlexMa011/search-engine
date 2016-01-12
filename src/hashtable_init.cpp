#include<iostream>
#include<fstream>
#include<sstream>
#include<cstring>
#include"hashtable.h"
#include"graph.h"

using namespace std;

void words_modified(string &);

void word_modified(string &);

void hashtable_init(Graph& ref,HashTable& index){
	ofstream interesting("doc/haha.txt");//store all the inverted index
	//construct the inverted-index hash table
	fstream doc("doc/documents.txt");
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
		ref.addtitle(title,serialnum);//store title in the adjancent list
		int refnum=ref.getref(serialnum);
		locinfo article(serialnum,refnum);
		stringstream titlestream(title);
		stringstream abstractstream(abstract);
		string words;
		titlestream>>words;//ignore the word "title"
		while(titlestream>>words){
			words_modified(words);
			stringstream wordstream(words);
			string word;
			while(wordstream>>word){
				word_modified(word);//make the word legal
				index.addpage(word,article);
			}
		}
		abstractstream>>words;//ignore the word "abstract"
		while(abstractstream>>words){
			words_modified(words);
			stringstream wordstream(words);
			string word;
			while(wordstream>>word){
				word_modified(word);//make the word legal
				index.addpage(word,article);
			}
		}
	}
	index.rank();//rank according to articles' ref number
	interesting<<index;
}

void words_modified(string &s){//only keep the alphabet and the number,other character is replace by " "
	for(int i=0;i<s.length();i++){
		if(s[i]>='A' && s[i]<='Z')
			s[i]=s[i]-'A'+'a';
		else if(s[i]>='a' && s[i]<= 'z')
			continue;
		else if(s[i]>='0' && s[i]<='9')
			continue;
		else
			s[i]=' ';
	}
}

void word_modified(string &s){//only keep the alphabet and the number,other character is erased
	for(int i=0;i<s.length();i++){
		if(s[i]>='A' && s[i]<='Z')
			s[i]=s[i]-'A'+'a';
		else if(s[i]>='a' && s[i]<= 'z')
			continue;
		else if(s[i]>='0' && s[i]<='9')
			continue;
		else{
			s.erase(i,1);
			i--;
		}
	}
}
