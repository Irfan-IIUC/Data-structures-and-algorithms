/*
Assuming index starts from 0, we can insert an element at index i>0 as follows, bring a temporary pointer
pointing to the node after the index you want to insert in the linked list.
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
    printf("\nThe elements in the linked list are: ");

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

// insert in between in the linked list
struct node* insert_between(struct node* head, int value, int index)
{
    int i=0;

    struct node* ptr = head;
    struct node* temp;

    // allocate memory for new node
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = value;

    while(i<index)
    {
        ptr = ptr->next;
        i++;
    }

    temp->next = ptr->next;
    ptr->next = temp;

    return head;
};

int main()
{
    int n;
    struct node* head;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    head = create_node(n);

    // insert 7 in between
    head = insert_between(head, 7, 2);
    traverse(head);

    return 0;
}
