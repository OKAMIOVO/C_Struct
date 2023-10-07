/**
 * @file insert_delete.c
 * @author OKAMI (xiaomeimeiyao@163.com)
 * @brief 顺序表的插入与删除
 * @version 0.1
 * @date 2023-01-06 21:08:38
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <stdio.h>
#include "stdtypedef.h"
#include "commonstruct.h"

#define bool int
#define true 1
#define false 0

// 初始化顺序表
void InitSeqList(SqList* L) {
    for (int i = 0; i < MAXSIZE; i++)
        L->data[i] = -1; //将所有数据元素设置为默认初始值
    L->length = 0;      //顺序表的初始长度为0
}

// 插入操作，在表L的第i个位值上插入指定元素e
bool SeqListInsert(SqList* L, int i, int e) {
    if (i < 1 || i > L->length + 1) //判断i的取值范围是否有效
        return false;
    if (L->length >= MAXSIZE) //存储空间已满
        return false;
    for (int j = L->length; j >= i; j--) //将第i个元素及之后的元素后移
        L->data[j] = L->data[j - 1];
    L->data[i - 1] = e; //在位值i处放入e
    L->length++;        //长度加1
    return true;
}

// 删除表L中第i个位值的元素，并用e返回删除元素的值
bool SeqListDelete(SqList* L, int i, int* e) {
    if (i < 1 || i > L->length)
        return false;
    *e = L->data[i - 1];
    for (int j = i; j < L->length; j++)
        L->data[j - 1] = L->data[j]; //将第i个元素之后的元素前移
    L->length--;

    return true;
}

int SeqGetElem(SqList* L,int i){
    return L->data[i-1];
}

// int main() {
//     SqList L;
//     InitList(&L);
//     ListInsert(&L, 1, 1);
//     ListInsert(&L, 2, 5);
//     ListInsert(&L, 3, 6);
//     ListInsert(&L, 4, 7);

//     int e = -1;
//     if (ListDelete(&L, 3, &e))
//         printf("已删除第三个元素，删除元素值为=%d\n", e);
//     else
//         printf("位序i不合法，删除失败！\n");

//     return 0;
// }