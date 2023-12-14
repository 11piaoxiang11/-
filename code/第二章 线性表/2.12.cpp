//12.从有序顺序表中删除所有值重复的值,使表中所有的值均不同

#include<iostream>
using namespace std;

typedef struct{
	int *data;
	int length;
}SqList;

//利用快慢指针解决
bool Delete_same(SqList &L){
	if(L.length==0) return false;//判断线性表的长度是否正确
	int i,j=0;//j为慢指针,i为快指针
	for(i=1;i<L.length;i++){//遍历
		if(L.data[i]!=L.data[j]){//如果快指针的值不等于慢指针的值 
			L.data[++j]=L.data[i];//移动快指针,并将快指针对应的元素赋值给慢指针
		}		
	}
	L.length=j+1;//更新线性表的长度
	return true;
}

int main(){
	SqList L;
	L.data=new int[10];
	int arr[10]={1,2,3,4,4,5,5,5,6,7};
	L.data=arr;
	L.length=10;
	for(int i=0;i<L.length;i++){
		cout<<L.data[i];
	}
	cout<<endl;
	cout<<L.length<<endl;
	if(Delete_same(L)){
		for(int i=0;i<L.length;i++){
			cout<<L.data[i];
		}
		cout<<endl;
		cout<<L.length<<endl;
	}
	
	
	
	delete[] L.data;
	return 0;
	
	
} 


