#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* nodeArray[5];

int hash_function(int value)
{
    // using hash function k mod 10
    return value%5;
}

int is_collision(int index)
{
    if(nodeArray[index] == NULL)
        return 0;
    else
        return 1;
}

int main()
{
    int key[] = {42,19,10,12,20,50}, key_size=6, i, index;

    // initialize all pointers with null
    for(i=0; i<5; i++)
        nodeArray[i] = NULL;

    // Create some nodes dynamically and store their addresses in the array
    for(i=0; i<key_size; i++)
    {
        struct Node* n = (struct Node*)malloc(sizeof(struct Node));

        n->data = key[i];
        n->next = NULL;

        index = hash_function(key[i]);

        // check for collision
        if(is_collision(index))
            n->next = nodeArray[index];

        nodeArray[index] = n; // Store the address in the array
    }

    printf("Value: %d\n", nodeArray[0]->next->next->data);

    return 0;
}
