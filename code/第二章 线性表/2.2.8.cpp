#include <iostream>
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
	for(int i=0;i<n;i++){
		L.data[i]=i;
	} 
	
}

bool deleteMinValue(SqList &L,int &value){
	if(L.length==0) return false;
	value=L.data[0];
	int pos=0;
	for(int i=0;i<L.length;i++){
		if(L.data[i]<value){
			value=L.data[i];
			pos=i;
		}
	}
	L.data[pos]=L.data[L.length-1];
	L.length--;
	return true;
	
}


int main(){
	SqList L;
	creatList(L,10);
	int i=0;
	while(i!=L.length){
		cout<<L.data[i]<<" ";
		i++;
	}
	cout<<endl;
	int value=0;
	if(deleteMinValue(L,value))
	cout<<value<<endl; 
	return 0; 
} 
