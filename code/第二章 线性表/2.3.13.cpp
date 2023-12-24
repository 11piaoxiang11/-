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

//将头结点摘下,再按头插法顺序插入
LinkList Reverse(LinkList &L){
	LinkList p=L->next,r;//p表示当前指针,r表示后继
    L->next=NULL;//将链表的头结点断开
    while(p!=NULL){
        r=p->next;
        p->next=L->next;//插入操作
        L->next=p;
        p=r;//更新结点
    }   
    return L;
}

int main(){
	LinkList L;
	InitList(L);
	for(int i=0;i<=10;i++){
		ListInsert(L,i,i);
	}
	PrintList(L);
	L=Reverse(L);
	PrintList(L);
	
	return 0;
}

