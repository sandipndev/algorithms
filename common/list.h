/* This file includes some basic C functions on an integer type Singly Linked List
 * @author Sandipan Dey
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *link;
} node;

node *__create_node(int data) {
    node *new_node = (node *) calloc(1, sizeof(node));
    new_node -> data = data;
    new_node -> link = NULL;
    return new_node;
}

node *insert_last(node *head, int data) {
    node *last_node = __create_node(data);
    if (head == NULL)
        return last_node;

    node *head_copy = head;
    while (head -> link != NULL)
        head = head -> link;
    head -> link = last_node;

    return head_copy;
}