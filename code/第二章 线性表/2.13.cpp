//13.����������˳���ϲ�Ϊһ���µ�����˳���,�����ؽ��˳���(**�ص�**)

#include <iostream>
using namespace std;

const int MAX_SIZE = 100; // ������󳤶�

struct SqList {
    int length; // ��ǰ����
    int data[MAX_SIZE]; // �洢���ݵ�����
};

bool Merge(SqList A, SqList B, SqList &C){
    if(A.length + B.length > C.length) return false; // ����˳������󳤶�
    int i = 0, j = 0, k = 0; // ����ָ��,��Ӧ�������Ա�
    while(i < A.length && j < B.length){
        if(A.data[i] <= B.data[j]){
            C.data[k++] = A.data[i++];
        }else{
            C.data[k++] = B.data[j++];
        }
    }
    while(i < A.length) C.data[k++] = A.data[i++];
    while(j < B.length) C.data[k++] = B.data[j++];
    C.length = k;
    return true;
}

int main() {
    // ��������µĲ���
    SqList A = {6, {1, 3, 5, 7, 9, 11}};
    SqList B = {6, {2, 4, 6, 8, 10, 12}};
    SqList C;

    Merge(A, B, C);
    cout << "�ϲ����˳��� C: ";
    for(int i = 0; i < C.length; i++) {
        cout << C.data[i] << " ";
    }
    cout << endl;

    // �߽�����µĲ���
    SqList A2 = {5, {1, 3, 5, 7, 9}};
    SqList B2 = {5, {2, 4, 6, 8, 10}};
    SqList C2;

    Merge(A2, B2, C2);
    cout << "�ϲ����˳��� C2: ";
    for(int i = 0; i < C2.length; i++) {
        cout << C2.data[i] << " ";
    }
    cout << endl;

    // �쳣����µĲ���
    SqList A3 = {5, {1, 3, 5, 7, 9}};
    SqList B3 = {6, {2, 4, 6, 8, 10, 12}};
    SqList C3;

    if(Merge(A3, B3, C3)) {
        cout << "�ϲ��ɹ�" << endl;
    } else {
        cout << "�ϲ�ʧ�ܣ�������󳤶�����" << endl;
    }

    return 0;
}

