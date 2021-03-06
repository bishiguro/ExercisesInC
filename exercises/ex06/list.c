/* Example code for Exercises in C.

Based on an example from http://www.learn-c.org/en/Linked_lists

Copyright 2016 Allen Downey
License: Creative Commons Attribution-ShareAlike 3.0

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *next;
} Node;


/* Makes a new node structure.
 * 
 * val: value to store in the node.
 * next: pointer to the next node
 *
 * returns: pointer to a new node
 */
Node *make_node(int val, Node *next) {
    Node *node = malloc(sizeof(Node));
    node->val = val;
    node->next = next;
    return node;
}


/* Prints the values in a list.
 * 
 * list: pointer to pointer to Node
 */
void print_list(Node **list) {
    Node *current = *list;

    printf("[ ");
    while (current != NULL) {
        printf("%d ", current->val);
        current = current->next;
    }
    printf("]\n");
}


/* Removes and returns the first element of a list.
 * 
 * list: pointer to pointer to Node
 *
 * returns: int or -1 if the list is empty
 */
int pop(Node **list) {
    printf("pop: ");
    Node *head = *list;
    *list = head->next;
    return head -> val;
}


/* Adds a new element to the beginning of the list.
 * 
 * list: pointer to pointer to Node
 * val: value to add
 */
void push(Node **list, int val) {
    printf("push (%i): ", val);
    Node *head = make_node(val, *list);
    *list = head;
}


/* Removes the first element with the given value
 * 
 * Frees the removed node.
 *
 * list: pointer to pointer to Node
 * val: value to remove
 *
 * returns: number of nodes removed
 */
int remove_by_value(Node **list, int val) {
    printf("remove_by_value (%i): ", val);

    Node *current = *list;
    Node *current_prev = NULL; // at the head of the list

    while (current != NULL) {
        if (current->val == val) { // node to remove
            if (current_prev != NULL) { // point the previous node to the node following the current
                current_prev->next = current->next;
            }
            else { // make the next value the new head of the list
                *list = current->next;
            }
        }

        current_prev = current;
        if (current->next != NULL) { // if not at the end of the list
            current = current->next;
        }
        else {
            current = NULL;
        }   
    }

    return 0;
}


/* Reverses the elements of the list.
 *
 * Does not allocate or free nodes.
 * 
 * list: pointer to pointer to Node
 */
void reverse(Node **list) {
    printf("reverse: ");
    Node *current = *list;
    Node *current_prev = NULL;
    Node *current_next = NULL;

    while (current != NULL) {
        if (current->next != NULL) {
            current_next = current->next;
        }
        else {
            *list = current;
            current_next = NULL;
        }

        if (current_prev != NULL) {
            current->next = current_prev;
        }
        else {
            current->next = NULL;
        }
        current_prev = current;
        current = current_next;
    }
}


int main() {
    Node *head = make_node(1, NULL);
    head->next = make_node(2, NULL);
    head->next->next = make_node(3, NULL);
    head->next->next->next = make_node(4, NULL);

    Node **list = &head;
    print_list(list);

    int retval = pop(list);
    print_list(list);

    push(list, retval+10);
    print_list(list);

    remove_by_value(list, 3);
    print_list(list);

    remove_by_value(list, 7);
    print_list(list);

    reverse(list);
    print_list(list);
}
