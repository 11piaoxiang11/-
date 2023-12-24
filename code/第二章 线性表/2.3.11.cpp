#include <iostream>
using namespace std;


typedef struct LNode{
	int data;
	struct LNode* next;
}LNode,*LinkList;

void InitList(LinkList &L){
	L=(LinkList)malloc(sizeof(LNode));
	L->next=NULL;
} 

void ListInsert(LinkList& L,int i,int x){
	LNode* p=L;
	int j=0;
	while(p&&j<i-1){
		p=p->next;
		j++; 
	}
	if(!p||j>i-1) return;
	LinkList s=(LinkList)malloc(sizeof(LNode));
	s->data=x;
	s->next=p->next;
	p->next=s;
}

void PrintList(LinkList L){
	LinkList p=L->next;
	while(p){
		cout<<p->data;
		p=p->next;
	}
	cout<<endl;
}

void Del_X_1(LinkList &L,int x){
	LinkList p=L->next,pre=L,q;
	while(p!=NULL){
		if(p->data==x){
			q=p;
			p=p->next;
			pre->next=p;
			free(q);
		}else{
			pre=p;
			p=p->next;
		}
	}
}

int main(){
	LinkList L;
	InitList(L);
	for(int i=0;i<=10;i++){
		ListInsert(L,i,i);
	}
	PrintList(L);
	Del_X_1(L,5);
	PrintList(L);
	
	return 0;
}
