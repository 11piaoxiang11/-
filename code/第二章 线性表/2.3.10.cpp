#include<iostream>
using namespace std;

typedef struct LNode{
	int data;
	struct LNode* next;
}LNode,*LinkList;

void Del_X_3(LinkList&L,int x){
	LNode* p;
	if(L==NULL) return;
	if(L->data==x){
		p=L;
		L=L->next;
		free(p);
		Del_X_3(L,x);
	}else{
		Del_X_3(L->next,x);
	}
}

int main(){
	  // ��������
    LinkList L = (LinkList)malloc(sizeof(LNode));
    L->data = 1;
    L->next = (LinkList)malloc(sizeof(LNode));
    L->next->data = 2;
    L->next->next = (LinkList)malloc(sizeof(LNode));
    L->next->next->data = 3;
    L->next->next->next = NULL;

    // ����ɾ�����ڵ�Ԫ��
    printf("ɾ��ǰ��");
    LinkList p = L;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
    Del_X_3(L, 2);
    printf("ɾ����");
    p = L;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");

    // ����ɾ�������ڵ�Ԫ��
    printf("ɾ��ǰ��");
    p = L;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
    Del_X_3(L, 4);
    printf("ɾ����");
    p = L;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");

    return 0;
}
