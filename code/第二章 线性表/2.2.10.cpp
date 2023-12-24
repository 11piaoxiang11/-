//10.对长度为n的顺序表L,编写一个时间复杂度为O(n),空间复杂度为O(1)的算法,该算法删除线性表中所有值为x的数据元素

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
