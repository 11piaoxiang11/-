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

//��ͷ���ժ��,�ٰ�ͷ�巨˳�����
LinkList Reverse(LinkList &L){
	LinkList p=L->next,r;//p��ʾ��ǰָ��,r��ʾ���
    L->next=NULL;//�������ͷ���Ͽ�
    while(p!=NULL){
        r=p->next;
        p->next=L->next;//�������
        L->next=p;
        p=r;//���½��
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

