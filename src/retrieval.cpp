#include <iostream>
#include <sstream>
#include <cstring>
#include <cassert>
#include "stack.h"
#include "graph.h"
#include "hashtable.h"

using namespace std;

const int maxwords=100;

LinkList<locinfo> unionlist(LinkList<locinfo>,LinkList<locinfo>);//get the union of two linklist
LinkList<locinfo> intersectlist(LinkList<locinfo>,LinkList<locinfo>);//get the intersection of two linklist
LinkList<locinfo> deletelist(LinkList<locinfo>,LinkList<locinfo>);//delete the second linklist from the first linklist


void retrieval(Graph &ref,HashTable &index){
	string input;
	string input_words[maxwords];//words which are searched
	string delete_words[maxwords];//words the result shouldn't contain
	string inputline;
	while(getline(cin,inputline)){
		stringstream inputstream(inputline);
		string or_symbol("OR");//identify the OR operation
		int i=0,j=0;
		while(inputstream>>input){
			if(input[0]!='-'){//identify the NOT operation
				input_words[i]=input;
				i++;
			}
			else{
				input.erase(0,1);//delete the "-"
				delete_words[j]=input;
				j++;
			}
		}
		int input_size=i;
		int delete_size=j;
		LinkList<locinfo> output;
		stack< LinkList<locinfo> > liststack;//contain the list of articles shouldreturn
		for(i=0;i<input_size;i++){
			if(input_words[i].compare(or_symbol)==0){//union the two articles around OR and put the union result into the stack
				LinkList<locinfo> newlist;
				liststack.pop(newlist);
				newlist=unionlist(newlist,index.search(input_words[i+1]));
				liststack.push(newlist);
				i++;
			}
			else{
				LinkList<locinfo> newlist=index.search(input_words[i]);
				liststack.push(newlist);
			}
		}
		liststack.pop(output);
		while(liststack.IsEmpty()!=true){//intersect all the articles in the stack
			LinkList<locinfo> newlist;
			liststack.pop(newlist);
			output=intersectlist(output,newlist);
		}
		for(j=0;j<delete_size;j++){//delete articles from the origin result
			LinkList<locinfo> dellist=index.search(delete_words[j]);
			output=deletelist(output,dellist);
		}
		LinkNode<locinfo> *p=output.gethead()->link;
		if(p==NULL){
			cout<<"No articles qualified!"<<endl;
			cout<<endl;
			continue;
		}
		while(p!=NULL){//print the output
			cout<<p->data<<ref.gettitle(p->data.vertexnum)<<endl;
			cout<<endl;
			p=p->link;
		}
	}
}

LinkList<locinfo> unionlist(LinkList<locinfo> a,LinkList<locinfo> b){
	LinkNode<locinfo> *p=a.gethead()->link;
	LinkNode<locinfo> *q=b.gethead()->link;
	LinkList<locinfo> c;
	while(p!=NULL && q!=NULL){
		if(p->data.vertexnum!=q->data.vertexnum){
			if(p->data.refnum>q->data.refnum){
				c.insert_from_rear(p->data);
				p=p->link;
			}
			else if(p->data.refnum==q->data.refnum && p->data.vertexnum<q->data.vertexnum){
				c.insert_from_rear(p->data);
				p=p->link;
			}
			else{
				c.insert_from_rear(q->data);
				q=q->link;
			}
		}
		else{
			c.insert_from_rear(p->data);
			p=p->link;
			q=q->link;
		}
	}
	if(p==NULL){
		while(q!=NULL){
			c.insert_from_rear(q->data);
			q=q->link;
		}
	}
	if(q==NULL){
		while(p!=NULL){
			c.insert_from_rear(p->data);
			p=p->link;
		}
	}
	return c;
}

LinkList<locinfo> intersectlist(LinkList<locinfo> a,LinkList<locinfo> b){
	LinkNode<locinfo> *p=a.gethead()->link;
	LinkNode<locinfo> *q=b.gethead()->link;
	LinkList<locinfo> c;
	while(p!=NULL && q!=NULL){
		if(p->data.vertexnum!=q->data.vertexnum){
			if(p->data.refnum>q->data.refnum){
				p=p->link;
			}
			else if(p->data.refnum==q->data.refnum && p->data.vertexnum<q->data.vertexnum)
				p=p->link;
			else{
				q=q->link;
			}
		}
		else{
			c.insert_from_rear(p->data);
			p=p->link;
			q=q->link;
		}
	}
	return c;
}

LinkList<locinfo> deletelist(LinkList<locinfo> a,LinkList<locinfo> b){
	LinkNode<locinfo> *p=a.gethead()->link;
	LinkNode<locinfo> *q=b.gethead()->link;
	LinkList<locinfo> c;
	while(p!=NULL && q!=NULL){
		if(p->data.vertexnum!=q->data.vertexnum){
			if(p->data.refnum>q->data.refnum){
				c.insert_from_rear(p->data);
				p=p->link;
			}
			else if(p->data.refnum==q->data.refnum && p->data.vertexnum<q->data.vertexnum){
				c.insert_from_rear(p->data);
				p=p->link;
			}
			else{
				q=q->link;
			}
		}
		else{
			p=p->link;
			q=q->link;
		}
	}
	if(q==NULL){
		while(p!=NULL){
			c.insert_from_rear(p->data);
			p=p->link;
		}
	}
	return c;
}
