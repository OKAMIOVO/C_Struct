/**
 * @file link.c
 * @author okami (xiaokenai@outlook.com)
 * @brief 单链表，不带头节点
 * @version 0.1
 * @date 2023-08-18 11:14:10
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include "commonstruct.h"


void Init_List(LinkList* L) { *L = NULL; }

bool List_Empty(LinkList L) {
    if (L == NULL) {
        return true;
    } else {
        return false;
    }
}

void Link_insert(LinkList* L, int n, int e) {
    if (n < 1)
        return;
    if (n == 1) {
        LNode* p = (LNode*)malloc(sizeof(LNode));
        p->data = e;
        p->next = *L;
        *L = p;
        return;
    }
    LNode* s;
    int j = 1;
    s = *L;
    while (s != NULL && j < n - 1) {
        s = s->next;
        j++;
    }
    if (s == NULL)
        return;
    LNode* p = (LNode*)malloc(sizeof(LNode));
    p->data = e;
    p->next = s->next;
    s->next = p;
    return;
}

void Link_delete(LinkList* L, int n, int* e) {
    if (n < 1)
        return;
    if (n == 1) {
        LNode* p = *L;
        *e = p->data;
        *L = p->next;
        free(p);

        return;
    }
    LNode* s;
    int j = 1;
    s = *L;
    while (s != NULL && j < n - 1) {
        s = s->next;
        j++;
    }
    if (s == NULL)
        return;
    if (s->next == NULL)
        return;
    LNode* p = s->next;
    *e = p->data;
    s->next = p->next;
    free(p);
}

/* int main() {
    LinkList L;
    Init_List(&L);
    Link_insert(&L, 1, 1);
    Link_insert(&L, 2, 2);
    Link_insert(&L, 3, 3);
    Link_insert(&L, 4, 4);
    Link_insert(&L, 5, 5);
    printf("%p\n", L);
    LinkList P;
    for (P = L; P != NULL; P = P->next) {
        printf("data = %d\n", P->data);
    }

    int e = -1;

    Link_delete(&L, 1, &e);
    printf("%p\n", L);
    printf("删除元素%d\n", e);
    LinkList Q;
    for (Q = L; Q != NULL; Q = Q->next) {
        printf("data = %d\n", Q->data);
    }
    return 0;
} */