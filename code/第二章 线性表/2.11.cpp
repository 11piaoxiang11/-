//11.从有序顺序表中删除其值在定制s到t之间(包含t和s,要求s<t)的所有元素,若s或t不合理或顺序表为空,则显示出错信息并退出运行
#include <iostream>
using namespace std;

typedef struct{
	int *data;
	int length; 
}SqList;

bool del_s_t(SqList& L,int s,int t) {
	if(s>=t||L.length==0) return false;
	int i,j;
	for(i=0;i<L.length&&L.data[i]<s;i++);
	if(i>=L.length) return false;
	for(j=0;j<L.length&&L.data[j]<=t;j++);
	for(;j<L.length;i++,j++){
		L.data[i]=L.data[j];
	}
	L.length=i;
	return true;
}



int main(){
	SqList L;
	L.data=new int[10];
	L.length=0;
	for(int i=0;i<=9;i++){
		L.data[i]=i;
		L.length++;
	} 
	for(int i=0;i<L.length;i++){
		cout<<L.data[i];
	}
	cout<<endl;
	cout<<L.length<<endl; 
	if(del_s_t(L,4,6)){
		for(int i=0;i<L.length;i++){
			cout<<L.data[i];
		}
		cout<<endl;
		cout<<L.length<<endl; 
	}
	
	delete[] L.data;
	return 0;
}
 
