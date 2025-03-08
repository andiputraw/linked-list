#include <stdio.h>
#include "linked_list.h"

void info();

int main()
{
    NodeAddress head;
    int input_val, sum, max;
    float avg;

    info();

    printf("TEST node baru didepan\n\n");
    for (int i = 3; i >= 1; i--)
    {
        printf("Masukan value ke %d\n", i);
        scanf("%d", &input_val);
        node_prepend(&head, input_val);
    }

    node_show(head);

    printf("TEST node baru di belakang\n\n");
    for (int i = 4; i < 7; i++)
    {

        printf("Masukan value ke %d\n", i);
        scanf("%d", &input_val);
        node_append(&head, input_val);
    }

    node_show(head);

    printf("TEST node baru ditaruh di element ke-4\n\n");

    printf("Masukan value di index ke-4\n");
    scanf("%d", &input_val);
    node_insert_at(&head, input_val, 4);

    node_show(head);

    printf("TEST hapus element pertama\n\n");
    node_remove_first(&head);
    node_show(head);
    
    printf("TEST hapus element terakhir\n\n");
    node_remove_last(&head);
    node_show(head);

    printf("TEST hapus element ke-3\n\n");
    node_remove_at(&head, 3);
    node_show(head);


    printf("TEST reverse node\n\n");
    node_reverse(&head);
    node_show(head);

    
    printf("TEST sum node\n\n");
    sum = node_sum(head);
    printf("Sum value dari node %d\n", sum);
    printf("TEST max node\n\n");
    max = node_max(head);
    printf("Max value dari node %d\n", max);
    printf("TEST avg node\n\n");
    avg = node_avg(head);
    printf("Avg value dari node %f\n", avg);

    return 0;
}

void info(){
    printf("PROGRAM LINKED-LIST\n");
    printf("Pembuat: Andi Putra Wijaya\n");
    printf("NIM    : 241511001\n");
    printf("\n");
    printf("Note   : Implementasi Linkedlist ini menggunakan index mulai dari 0 \n");
    printf("------------------------------------\n");
}