/*
There are three common types of Linked List. They are,
-> Singly Linked List
-> Doubly Linked List
-> Circular Linked List

A singly linked list is a linear data structure in which the elements are not stored in contiguous memory locations and each element is connected only to its next element using a pointer.
*/

#include<stdio.h>
#include<stdlib.h> // for memory allocation and other similar use cases

// a structure with a data field and a pointer to a structure of type node
struct node
{
    int data;
    struct node* next;
};

// traversing the nodes
void traverse(struct node* ptr)
{
    printf("The elements are: ");

    while(ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }

    printf("\n");
}

int main()
{
    // initialize nodes
    struct node* head;
    struct node* a = NULL;
    struct node* b = NULL;
    struct node* c = NULL;

    // allocate memory for all nodes
    a = (struct node*)malloc(sizeof(struct node));
    b = (struct node*)malloc(sizeof(struct node));
    c = (struct node*)malloc(sizeof(struct node));

    // store data and connect nodes
    a->data = 1;
    a->next = b;
    b->data = 2;
    b->next = c;
    c->data = 3;
    c->next = NULL;

    // save address of first node in head
    head = a;
    printf("Singly Linked List successfully created!\n");

    traverse(head);

    return 0;
}
