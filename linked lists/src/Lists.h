#ifndef SRC_SINGLY_LINKED_LIST_H
#define SRC_SINGLY_LINKED_LIST_H

#include <iostream>

typedef struct node {
    int item;
    node *next;
} SLList_t;

typedef struct node2 {
    int item;
    node2 *back;
    node2 *next;
} DLList_t;

using namespace std;

void SLL_push_back(SLList_t **old_list, int input_item);
int SLL_pop_back(SLList_t **old_list);
void SLL_clear(SLList_t **list);
void SSL_sort(SLList_t **x);
SLList_t reverse(SLList_t **x);

// struct node {
//     int item;
//     node *next;
//     node(int x, node *t) {
//         item = x;
//         next = t;
//     }
// };
// typedef node *list_t;

#endif  // SRC_SINGLY_LINKED_LIST_H