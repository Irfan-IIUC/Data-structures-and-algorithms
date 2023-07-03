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

int main()
{
    int n;
    struct node* head;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    head = create_node(n);
    traverse(head);

    return 0;
}
