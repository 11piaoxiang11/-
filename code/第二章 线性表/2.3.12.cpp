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

LinkList DeleteMin(LinkList &L){
	LinkList p=L->next,pre=L,minPre=pre,min=p;
	while(p!=NULL){
		if(p->data<min->data){
			min=p;
			minPre=pre;
		}
		pre=p;
		p=p->next;
	}
    minPre->next=min->next;
    free(min);
    return L;
}

int main(){
	LinkList L;
	InitList(L);
	for(int i=0;i<=10;i++){
		ListInsert(L,i,i);
	}
	PrintList(L);
	L=DeleteMin(L);
	PrintList(L);
	
	return 0;
}
