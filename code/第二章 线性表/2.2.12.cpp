//12.������˳�����ɾ������ֵ�ظ���ֵ,ʹ�������е�ֵ����ͬ

#include<iostream>
using namespace std;

typedef struct{
	int *data;
	int length;
}SqList;

//���ÿ���ָ����
bool Delete_same(SqList &L){
	if(L.length==0) return false;//�ж����Ա�ĳ����Ƿ���ȷ
	int i,j=0;//jΪ��ָ��,iΪ��ָ��
	for(i=1;i<L.length;i++){//����
		if(L.data[i]!=L.data[j]){//�����ָ���ֵ��������ָ���ֵ 
			L.data[++j]=L.data[i];//�ƶ���ָ��,������ָ���Ӧ��Ԫ�ظ�ֵ����ָ��
		}		
	}
	L.length=j+1;//�������Ա�ĳ���
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


