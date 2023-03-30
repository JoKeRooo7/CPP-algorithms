#include "Lists.h"

int main() {
    SLList_t *a = new SLList_t;
    SLL_push_back(&a, 3);
    SLL_push_back(&a, 3);
    SLL_push_back(&a, 4);
    SLL_push_back(&a, 5);
    cout << SLL_pop_back(&a) << " " << SLL_pop_back(&a) << " " << SLL_pop_back(&a);
    SLL_clear(&a);
}

void SLL_push_back(SLList_t **old_list, int input_item) {
    SLList_t *new_list = new SLList_t;
    if (*new_list) {
        new_list -> item = input_item;
        new_list -> next = (*old_list);
        (*old_list) = new_list;
    } else {
        cout << "No memory allocated\n";
    }
}

int SLL_pop_back(SLList_t **list) {
    SLList_t *old_list = nullptr;
    int pop_item = 0;
    if (*list != nullptr) {
        old_list = (*list);
        pop_item = old_list -> item;
        (*list) = (*list) -> next;
        delete old_list;
    }
    return pop_item;
}

void SLL_clear(SLList_t **list) {
    SLList_t *old_list = nullptr;
    while (*list) {
        old_list = (*list);
        (*list) = (*list) -> next;
        delete old_list;
    }
}

SLList_t reverse(SLList_t **x) {
    
}