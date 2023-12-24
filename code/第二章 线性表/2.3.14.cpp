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

//�����������й������ʱ,��ζ����������һ��Ԫ������ȵ�,�������ֻ��Ҫ�ֱ���������������¼�����һ�����,�Ƚ��Ƿ���ȼ���
//����
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
    // ��L2��β�ڵ�ָ��L1�ĵ�3���ڵ㣬���ɹ�������
    LNode* p = L2;
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = L1->next->next->next;
	
	PrintList(L1);
	PrintList(L2);
	
    bool result = SearchCommon(L1, L2);
    if (result) {
    	cout<<"�����������й�����"<<endl; 
    } else {
       	cout<<"����������û�й�����"<<endl;
    }

    return 0;
}
