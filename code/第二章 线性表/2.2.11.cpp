//11.������˳�����ɾ����ֵ�ڶ���s��t֮��(����t��s,Ҫ��s<t)������Ԫ��,��s��t�������˳���Ϊ��,����ʾ������Ϣ���˳�����
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
 
