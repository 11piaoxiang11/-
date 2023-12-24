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
	  // 创建链表
    LinkList L = (LinkList)malloc(sizeof(LNode));
    L->data = 1;
    L->next = (LinkList)malloc(sizeof(LNode));
    L->next->data = 2;
    L->next->next = (LinkList)malloc(sizeof(LNode));
    L->next->next->data = 3;
    L->next->next->next = NULL;

    // 测试删除存在的元素
    printf("删除前：");
    LinkList p = L;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
    Del_X_3(L, 2);
    printf("删除后：");
    p = L;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");

    // 测试删除不存在的元素
    printf("删除前：");
    p = L;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
    Del_X_3(L, 4);
    printf("删除后：");
    p = L;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");

    return 0;
}
