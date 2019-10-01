#include<iostream>
#include<map>
using namespace std;

struct node{
	long data;
	long rank;
	node* parent;
};

void makeSet(map<long,node*> &mp,long data){
	node* temp=new node;
	temp->data=data;
	temp->rank=0;
	temp->parent=temp;
	mp[data]=temp;
}

node* findRoot(map<long,node*> &mp,long data){
	auto it=mp.find(data);
	if(it==mp.end())
		return NULL;
	node* temp=it->second;
	if(temp->parent==temp)
		return temp;
	temp->parent=findRoot(mp,temp->parent->data);
	return temp->parent;
}

void Union(map<long,node*> &mp,long data1,long data2){
	auto it1=mp.find(data1);
	auto it2=mp.find(data2);
	if(it1==mp.end() || it2==mp.end())
		return;
	node* a=findRoot(mp,data1);
	node* b=findRoot(mp,data2);
	if(a==b)
		return;
	if(a->rank==b->rank){
		b->parent=a;
		a->rank++;
	}
	else if(a->rank>b->rank)
		b->parent=a;
	else
		a->parent=b;
}

bool Find(map<long,node*> &mp,long data1,long data2){
	auto it1=mp.find(data1);
	auto it2=mp.find(data2);
	if(it1==mp.end() || it2==mp.end())
		return 0;
	node* a=findRoot(mp,data1);
	node* b=findRoot(mp,data2);
	if(a==b)
		return 1;
	return 0;
}

int main(){
	map<long,node*> mp;
	for(long i=1;i<=10;++i){
		makeSet(mp,i);
	}
	Union(mp,1,2);
	Union(mp,2,3);
	Union(mp,1,3);
	Union(mp,8,5);
	Union(mp,5,6);
	node* x=findRoot(mp,3);
	node* y=findRoot(mp,5);
	cout<<x->data<<" "<<y->data;
	Union(mp,3,6);
	x=findRoot(mp,3);
	cout<<" "<<x->data;
}