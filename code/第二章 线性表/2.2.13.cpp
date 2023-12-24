//13.将两个有序顺序表合并为一个新的有序顺序表,并返回结果顺序表(**重点**)

#include <iostream>
using namespace std;

const int MAX_SIZE = 100; // 定义最大长度

struct SqList {
    int length; // 当前长度
    int data[MAX_SIZE]; // 存储数据的数组
};

bool Merge(SqList A, SqList B, SqList &C){
    if(A.length + B.length > C.length) return false; // 大于顺序表的最大长度
    int i = 0, j = 0, k = 0; // 三个指针,对应三个线性表
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
    // 正常情况下的测试
    SqList A = {6, {1, 3, 5, 7, 9, 11}};
    SqList B = {6, {2, 4, 6, 8, 10, 12}};
    SqList C;

    Merge(A, B, C);
    cout << "合并后的顺序表 C: ";
    for(int i = 0; i < C.length; i++) {
        cout << C.data[i] << " ";
    }
    cout << endl;

    // 边界情况下的测试
    SqList A2 = {5, {1, 3, 5, 7, 9}};
    SqList B2 = {5, {2, 4, 6, 8, 10}};
    SqList C2;

    Merge(A2, B2, C2);
    cout << "合并后的顺序表 C2: ";
    for(int i = 0; i < C2.length; i++) {
        cout << C2.data[i] << " ";
    }
    cout << endl;

    // 异常情况下的测试
    SqList A3 = {5, {1, 3, 5, 7, 9}};
    SqList B3 = {6, {2, 4, 6, 8, 10, 12}};
    SqList C3;

    if(Merge(A3, B3, C3)) {
        cout << "合并成功" << endl;
    } else {
        cout << "合并失败，超过最大长度限制" << endl;
    }

    return 0;
}

