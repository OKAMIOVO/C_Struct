#include "commonstruct.h"
#include <stdio.h>

// 用第一个元素将待排序列划分成左右两个部分
int Partition(int A[],int low,int high){
    int pivot = A[low];     // 第一个元素作为枢轴
    while(low < high){  // 用low,high搜索枢轴的最终位置
        while(low < high && A[high]>=pivot)
            --high;
        A[low] = A[high];   // 比枢轴小的元素移动到左端
        while(low < high && A[high]<=pivot)
            ++low;
        A[high] = A[low];   // 比枢轴大的元素移动到右端
    }
    A[low] = pivot;     // 枢轴元素存放到最终位置
    return low;         // 返回存放枢轴的最终位置
}

// 快速排序
void QuickSort(int A[],int low,int high){
    if(low < high){     // 递归跳出的条件
        int pivotpos = Partition(A, low, high); // 划分
        QuickSort(A, low, pivotpos-1);      // 划分左子表
        QuickSort(A, pivotpos+1, high);     // 划分右子表
    }
}

// int main(){
//     // SSTable L;
//     // InitList(&L);

//     // int a, i;
//     //使用for循环生成10个随机数
//     // for (i = 1; i <= 10; i++) {
//     //     srand((unsigned)time(NULL) + (unsigned)rand());
//     //     a = rand();
//     //     ListInsert(&L,i,a);
//     // }
//     int A[] = {30,21,23,52,63,59,11,59,63,89};
//     // for(int k = 0; k < 10; k++){
//     //     printf("L.data[%d] = %d\n",k,L.data[k]);
//     // }
//     // InsertSort(L.data,L.len);
//     QuickSort(A,0,sizeof(A)/sizeof(int));
//     printf("\n");
//     for(int j = 0; j < 10; j++){
//         printf("L.data[%d] = %d\n",j,A[j]);
//     }
// }