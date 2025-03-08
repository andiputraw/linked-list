#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#ifndef LINKED_LIST_TYPE
#define LINKED_LIST_TYPE int
#endif

typedef LINKED_LIST_TYPE NodeInfoType;
typedef struct NodeT* NodeAddress;

typedef struct NodeT {
    NodeInfoType info;
    NodeAddress next;
} Node;

void node_create(NodeAddress* node);
void node_init( NodeAddress* node, NodeInfoType value);
void node_show(NodeAddress head);
void node_prepend(NodeAddress* head, NodeInfoType value);
void node_append(NodeAddress* head, NodeInfoType value);
void node_insert_at(NodeAddress* head, NodeInfoType value, int at);
NodeAddress node_find(NodeAddress* head, NodeInfoType value);
void node_remove_first(NodeAddress* head);
void node_remove_last(NodeAddress* head);
void node_remove_at(NodeAddress* head, int at);
void node_reverse(NodeAddress* head);

// integer operation
int node_sum(NodeAddress head);
int node_max(NodeAddress head);
float node_avg(NodeAddress head);



#endif // LINKED_LIST_H