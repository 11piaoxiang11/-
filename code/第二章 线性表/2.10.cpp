//10.�Գ���Ϊn��˳���L,��дһ��ʱ�临�Ӷ�ΪO(n),�ռ临�Ӷ�ΪO(1)���㷨,���㷨ɾ�����Ա�������ֵΪx������Ԫ��

#include<iostream>
using namespace std;
#define MaxSize 50

typedef struct{
	int *data;
	int length;
}SqList;

void creatList(SqList &L,int n){
	if(n<0||n>MaxSize){
		return;
	}
	L.data=new int[MaxSize];
	L.length=n;
	for(int i=0;i<L.length;i++){
		L.data[i]=i;
	}
	
}

void deleteList(SqList& L,int value){
	int a
	for(int i=0;i<)
}

int main(){
	
	return 0;
} 
