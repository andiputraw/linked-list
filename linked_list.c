#include "linked_list.h"
#include <stdlib.h>
#include <stdio.h>

void node_create(NodeAddress* node){
    NodeAddress new = malloc(sizeof(Node));
    *node = new;
}
void node_init(NodeAddress* node, NodeInfoType value){
    (*node)->info = value;
    (*node)->next = NULL;
}
void node_show(NodeAddress head){
    if(head == NULL) {
        printf("NULL\n");
        return;
    }
    printf("%d -> ", head->info);
    node_show(head->next);
}
void node_prepend(NodeAddress* head, NodeInfoType value){
    NodeAddress new;
    node_create(&new);

    node_init(&new, value);

    new->next = *head;
    (*head) = new;
}
void node_append(NodeAddress* head, NodeInfoType value){
    NodeAddress new;
    node_create(&new);

    node_init(&new, value);

    if (head == NULL) {
        *head = new;
    }else {
        NodeAddress cur = *head;
    
        while(cur->next != NULL) {
            cur = cur->next;
        }
    
        cur->next = new;
    }

}
void node_insert_at(NodeAddress* head, NodeInfoType value, int at){
    NodeAddress new;
    node_create(&new);

    node_init(&new, value);
    // 3 -> 2 -> 1
    //      2 -> 4 -> 1
    //      ^
    
    if(at == 0) {
        node_prepend(head, value);
        return;
    }

    NodeAddress cur = *head;
    
    for(int i = 0; i < at - 1; i++) {
        if (cur == NULL) {
            printf("ERROR(node_insert_at): panjang node hanya %d\n", i);
            return;
        }

        cur = cur->next;
    }

    new->next = cur->next;
    cur->next = new;
}
NodeAddress node_find(NodeAddress* head, NodeInfoType value){
    
    if(head == NULL) {
        printf("ERROR(node_find): linkedlist kosong\n");
        return NULL;
    }

    NodeAddress cur = *head;

    do{
        if(cur->info == value){
            break;
        }
        cur = cur->next;
    }while(cur->next != NULL);

    return cur;
}
void node_remove_first(NodeAddress* head){
    if(head == NULL) {
        printf("ERROR(node_find): linked list kosong\n");
        return;
    }

    NodeAddress cur = *head;
    (*head) = cur->next;
    
    free(cur);
}
void node_remove_last(NodeAddress* head){
    if(head == NULL) {
        printf("ERROR(node_find): linked list kosong\n");
        return;
    }
    // 3 -> 2 -> 1 -> NULL
    //      ^    ^
    // 3 -> 2 -> NULL
    //      ^    ^

    NodeAddress cur = *head;
    NodeAddress prev = NULL;
    while(cur->next != NULL) {
        prev = cur;
        cur = cur->next;
    }

    prev->next = NULL;
    free(cur);
    
}
void node_remove_at(NodeAddress* head, int at){
    if(at == 0) {
        node_remove_first(head);
        return;
    }

    NodeAddress cur = *head;
    NodeAddress prev = NULL;

    for(int i = 0; i < at; i++) {
        if (cur == NULL) {
            printf("ERROR(node_insert_at): panjang node hanya %d\n", i);
            return;
        }
        prev = cur;
        cur = cur->next;
    }

    // 3 -> 2 -> 1 -> NULL
    // ^    ^
    // 3 -> 1 -> NULL
    // ^

    prev->next = cur->next;
    free(cur);
}
void node_reverse(NodeAddress* head){
    NodeAddress cur = *head;
    NodeAddress prev = NULL;
    NodeAddress tmp;

    // 2 -> 1 | 1 -> NULL
    // NULL | 3 -> 2 | 3 -> NULL | 2 -> 1 | 2 -> 3
    // ? | NULL | 3 -> NULL

    // 3 -> 2 -> 1 -> NULL
    // 
    // 3 -> 1 -> NULL
    // ^

    while(cur->next != NULL) {
        tmp = prev;
        prev = cur;
        cur = cur->next;

        prev->next = tmp;
    }
    cur->next = prev;
    *head = cur;
}

// integer operation
int node_sum(NodeAddress head){
    if(head == NULL) {
        printf("ERROR(node_sum): linked list kosong\n");
        return;
    }
    NodeAddress cur = head;
    int sum = 0;

    while(cur != NULL) {
        sum += cur->info; 
        cur = cur->next;
    }

    return sum;
}
int node_max(NodeAddress head){
    if(head == NULL) {
        printf("ERROR(node_sum): linked list kosong\n");
        return;
    }
    NodeAddress cur = head;
    int max = 0;

    while(cur != NULL) {
        max = cur->info > max ? cur->info : max; 
        cur = cur->next;
    }

    return max;
}
float node_avg(NodeAddress head){
    if(head == NULL) {
        printf("ERROR(node_sum): linked list kosong\n");
        return;
    }
    NodeAddress cur = head;
    int sum = 0;
    int total = 0;

    while(cur != NULL) {
        sum += cur->info; 
        total++;
        cur = cur->next;
    }


    return (float)sum / (float)total;

}