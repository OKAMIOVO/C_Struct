/**
 * @file heapsort.c
 * @author okami (xiaokenai@outlook.com)
 * @brief 堆排序
 * @version 0.1
 * @date 2023-08-14 11:08:05
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "stdio.h"
#include "commonstruct.h"
#include "swap.h"

void swap(int *a ,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * @brief 建堆
 *
 * @param arr 存储堆的数组
 * @param len 数组长度
 * @param i 当前节点下标
 */
void heapify(int arr[], int len, int i) {
    int largest = i;      // 堆顶元素
    int lson = i * 2 + 1; // 左孩子节点
    int rson = i * 2 + 2; // 右孩子节点

    if (lson < len && arr[largest] < arr[lson]) {
        largest = lson;
    }
    if (rson < len && arr[largest] < arr[rson]) {
        largest = rson;
    }
    if (largest != i) {
        SWAP(arr[largest], arr[i]);
        // swap(&arr[largest], &arr[i]);
        heapify(arr, len, largest);
    }
}

void heap_sort(int arr[], int len) {
    int i;
    // 建堆
    for (i = len / 2 - 1; i >= 0; i--) {
        heapify(arr, len, i);
    }

    // 排序
    for (i = len - 1; i > 0; i--) {
        SWAP(arr[i], arr[0]);
        // swap(&arr[i], &arr[0]);
        heapify(arr, i, 0);
    }
}

void HeapSortEx(){
    int arr[] = {1,3,8,1,4,9,10,7,16,14};
    // heap_sort(arr,10);
    HeapSort(arr,10);
    for(int i = 1; i < 10; i++){
        printf("arr[%d] = %d\n",i,arr[i]);
    }
}