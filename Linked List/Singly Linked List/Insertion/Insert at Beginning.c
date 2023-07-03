/*
Insertion in the linked list can be divided into the following categories,

-> Insert at the beginning
-> Insert in between
-> Insert at the end
-> Insert after a given node

For insertion following any of the above-mentioned cases, we would first need to create that extra node. And then, we overwrite the current connection and make new connections.
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
    printf("The elements in the linked list are: ");

    while(ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }

    printf("\n");
}

// create linked list
struct node* create_node(int n)
{
    int i, value;

    struct node* head = NULL;
    struct node* ptr = NULL;
    struct node* temp = NULL;

    printf("Enter %d numbers: ", n);

    for(i=0; i<n; i++)
    {
        scanf("%d", &value);

        // allocate memory for temp node
        temp = (struct node*)malloc(sizeof(struct node));
        temp->data = value;
        temp->next = NULL;

        if(head == NULL)
            head = temp;
        else
        {
            ptr = head;

            while(ptr->next != NULL)
                ptr = ptr->next;

            ptr->next = temp;
        }
    }

    return head;
};

// insert at beginning in the linked list
struct node* insert_begin(struct node* head, int value)
{
    struct node* ptr;

    // allocate memory for new node
    ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data = value;

    ptr->next = head;
    head = ptr;

    return head;
};

int main()
{
    int n;
    struct node* head;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    head = create_node(n);

    // insert 5 at beginning
    head = insert_begin(head, 5);
    traverse(head);

    return 0;
}
