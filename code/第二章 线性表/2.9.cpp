

//9.设计一个高效算法,将顺序表L所有的元素逆置,要求算法的空间复杂度为O(1)

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
