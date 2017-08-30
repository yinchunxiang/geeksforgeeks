/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2017/08/31 00:00:15
 * @brief 
 * 
 **/ 

struct Node {
    int data;
    struct Node* next;
};

struct Node* partition(struct Node* head, struct node* end, struct Node** newHead, struct Node** newEnd) {
    struct Node* pivot = tail;
    struct Node* prev = nullptr;
    struct Node* cur = head;
    struct Node* tail = pivot;
    while (cur != pivot) {
        if (cur->data < pivot->data) {
            if ((*newHead) == nullptr) {
                (*newHead) = cur;
            }
            prev = cur;
            cur = cur->next;
        } else {
            if (prev) {
                prev->next = cur->next;
            }
            struct Node* temp = cur->next;
            cur->next = nullptr;
            tail->next = cur;
            tail = cur;
            cur = temp;
        }
    }
    if ((*newHead) == nullptr) {
        (*newHead) = pivot;
    }

    (*newEnd) = tail;
    return pivot;
}

struct Node* getTail(Node* head) {
    while (nullptr != head && nullptr != head->next) {
        head = head->next;
    }
    return head;
}
 
struct Node* quickSort(Node* head, Node* end) {
    if (null == head || head == end) {
        return head;
    }
    Node* newHead = nullptr;
    Node* newEnd = nullptr;

    struct Node* pivot = partition(head, end, &newHead, &newEnd);
    if (newHead != pivot) {
        struct Node* temp = newHead;
        while (temp->next != pivot) {
            temp = temp->next;
        }
        temp->next = nullptr;
        newHead = quickSort(head, temp);
        temp = getTail(newHead);
        temp->next = pivot;
    }
    pivot->next = quickSort(pivot->next, newEnd);
    return newHead;
}













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
