/**
 * @file heapsort_cs.c
 * @author okami (xiaokenai@outlook.com)
 * @brief 堆排序王道版
 * @version 0.1
 * @date 2023-08-15 08:51:56
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "stdio.h"
#include "swap.h"
#include "commonstruct.h"

// 将以k为根的子树调整为大根堆
void HeadAdjust(int A[], int k, int len) {
    A[0] = A[k];                            // A[0]暂存子树的根节点
    for (int i = 2 * k; i <= len; i *= 2) { // 沿key较大的子节点向下筛选
        if (i < len && A[i] < A[i + 1]) {
            i++; // 取key较大的子节点下标
        }
        if (A[0] >= A[i]) {
            break; // 筛选结束
        } else {
            A[k] = A[i]; // 将A[i]调整到双亲结点上
            k = i;
        }
    }
    A[k] = A[0]; // 将被筛选节点的值放入最终位置
}

// 建立大根堆
void BuildMaxHeap(int A[], int len) {
    for (int i = len / 2; i > 0; i--) { // 从后往前调整所有非终端节点
        HeadAdjust(A, i, len);
    }
}

// 堆排序的完整逻辑
void HeapSort(int A[], int len) {
    BuildMaxHeap(A, len);           // 初始建堆
    for (int i = len; i > 1; i--) { // n-1趟交换和建堆过程
        SWAP(A[i], A[1]);           // 堆顶元素和堆底元素交换
        HeadAdjust(A, 1, i - 1);    // 把剩余待排元素整理成堆
    }
}