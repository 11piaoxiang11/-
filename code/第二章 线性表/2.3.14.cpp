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

//当两个链表有公共结点时,意味着链表的最后一个元素是相等的,因此我们只需要分别遍历两个单链表记录下最后一个结点,比较是否相等即可
//遍历
LinkList Ergodic(LinkList L){
	LinkList p=L->next,pre=L;
	while(p!=NULL){
		pre=p;
		p=p->next;
	}
    return pre;
}

bool SearchCommon(LinkList L1,LinkList L2){
    LinkList p1=Ergodic(L1);
    LinkList p2=Ergodic(L2);
    if(p1==p2){
        return true;
    }
    return false;
	
}

int main() {
    LinkList L1, L2;
    InitList(L1);
    InitList(L2);
    for (int i = 1; i <= 5; i++) {
        ListInsert(L1, i, i);
    }
    for (int i = 1; i <= 3; i++) {
        ListInsert(L2, i, i);
    }
    // 将L2的尾节点指向L1的第3个节点，构成公共部分
    LNode* p = L2;
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = L1->next->next->next;
	
	PrintList(L1);
	PrintList(L2);
	
    bool result = SearchCommon(L1, L2);
    if (result) {
    	cout<<"这两个链表有公共点"<<endl; 
    } else {
       	cout<<"这两个链表没有公共点"<<endl;
    }

    return 0;
}
