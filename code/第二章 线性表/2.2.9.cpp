

//9.���һ����Ч�㷨,��˳���L���е�Ԫ������,Ҫ���㷨�Ŀռ临�Ӷ�ΪO(1)

#include<iostream>
using namespace std;
#define MaxSize 50

typedef struct{
	int *data;
	int length; 
}SqList;

void creatList(SqList& L,int n){
	if(n<0||n>L.length){
		return;
	}
	L.data=new int[MaxSize];
	L.length=n;
	for(int i=0;i<L.length;i++){
		L.data[i]=i;
	}
}

void reverseList(SqList& L){
	int temp=0;
	for(int i=0;i<L.length/2;i++){
		temp=L.data[i];
		L.data[i]=L.data[L.length-i-1];
		L.data[L.length-i-1]=temp;
	}
}



int main(){
	SqList L;
	creatList(L,10);
	for(int i=0;i<L.length;i++){
		cout<<L.data[i]<<" ";
	}
	cout<<endl; 
	reverseList(L);
	for(int i=0;i<L.length;i++){
		cout<<L.data[i]<<" ";
	}
	return 0; 
}
