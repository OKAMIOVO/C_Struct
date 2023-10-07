/**
 * @file link_insert_delete.c
 * @author OKAMI (xiaomeimeiyao@163.com)
 * @brief 单链表的插入和删除
 * @version 0.1
 * @date 2023-01-11 14:01:38
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include "commonstruct.h"

// 初始化单链表(带头节点)
void InitList(LinkList* L){
    *L = (LNode*)malloc(sizeof(LNode));  //分配一个头节点
    if(*L==NULL){    //内存不足，分配失败
        return ;
    }
    (*L)->next = NULL; //头节点之后暂无结点
}

// 判断单链表是否为空
bool Empty(LinkList L){
    if(L->next == NULL){
        printf("链表为空！\n");
        return true;
    }else{
        printf("链表不为空！\n");
        return false;
    }
}

// 按位序插入，在表L中的第i个位置上插入指定元素e(带头节点)
bool ListInsert(LinkList L,int i,int e){
    if(i<1)
        return false;
    LNode * p;   //指针p指向当前扫描到的结点
    int j = 0;  //当前p指向的是第几个结点
    p = L;      //L指向头节点，头结点是第0个结点
    while(p!=NULL && j<i-1){    //循环找到第i-1个结点
        p = p->next;
        j++;
    }

    if(p==NULL)     //i值不合法
        return false;
    
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    // printf("插入元素%d成功！\n",e);
    return true;
}

// 删除表L中第i个位值的元素，并用e返回删除元素的值
bool ListDelete(LinkList L,int i,int *e){
    if(i<1)
        return false;
    LNode *p;   //指针p指向当前扫描到的结点
    int j = 0;  //当前p指向的是第几个结点
    p = L;      //L指向头节点，头结点是第0个结点
    while(p!=NULL && j<i-1){    //循环找到第i-1个结点
        p=p->next;
        j++;
    }
    if(p==NULL)     //i值不合法
        return false;
    if(p->next == NULL)     //第i-1个结点之后已无其他结点
        return false;
    
    LNode *q = p->next;     //令q指向被删除结点
    *e = q->data;           //用e返回元素的值
    p->next=q->next;        //将*q从链中断开
    free(q);           //释放结点的存储空间
    // printf("删除成功！\n");          
    return true;


}

// 按位查找（带头结点）
LNode *GetElem(LinkList L,int i){
    if(i<0){
        return NULL;
    }
    LNode *p;   // 指针p指向当前扫描到的节点
    int j = 0;  // 当前p指向的是第几个节点
    p = L;      // L指向头节点，头节点是第0个节点
    while(p != NULL && j < i){  // 循环找到第i个节点
        p = p->next;
        j++;
    }
    return p;
}

// 按值查找
LNode* LocateElem(LinkList L,int e){
    LNode *p = L->next;
    // 从第一个节点开始查找数据与为e的节点
    while(p != NULL && p->data != e){
        p = p->next;
    }
    return p;   // 找到后返回该节点指针，否则返回NULL
}

// 求表长
int LinkListLength(LinkList L){
    int len = 0;
    LNode *p = L;
    while (p->next != NULL) {
        p = p->next;
        len++;
    }
    return len;
}

/* int main(){
    LinkList L;
    L = InitList(L);
    Empty(L);
    ListInsert(L, 1, 1);
    ListInsert(L, 2, 20);
    ListInsert(L, 3, 63);

    int e = -1;
    ListDelete(L, 2, &e);
    printf("删除元素%d成功！\n",e); 
    ListDelete(L, 1, &e);
    printf("删除元素%d成功！\n",e); 

    return 0;
} */