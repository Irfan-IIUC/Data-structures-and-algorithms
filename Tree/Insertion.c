#include<stdio.h>
#include<malloc.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct node* create_node(int val)
{
    struct node* n;
    n = (struct node*)malloc(sizeof(struct node));

    n->data = val;
    n->left = NULL;
    n->right = NULL;

    return n;
};

int insertion_BST(struct node* root, int key)
{
    struct node* prev = NULL;

    while(root != NULL)
    {
        prev = root;

        if(key == root->data)
            return 0;
        else if(key < root->data)
            root = root->left;
        else
            root = root->right;
    }

    struct node* n = create_node(9);

    if(key < prev->data)
        prev->left = n;
    else
        prev->right = n;

    return 1;
};

int main()
{
    /*
                  8
               /     \
              3      10
            /   \       \
           1    6       14
               / \      /
              4   7    13
    */

    struct node* root = create_node(8);

    struct node* p1 = create_node(3);
    struct node* p2 = create_node(10);

    struct node* p3 = create_node(1);
    struct node* p4 = create_node(6);
    struct node* p5 = create_node(14);

    struct node* p6 = create_node(4);
    struct node* p7 = create_node(7);
    struct node* p8 = create_node(13);

    root->left = p1;
    root->right = p2;

    p1->left = p3;
    p1->right = p4;
    p2->right = p5;

    p4->left = p6;
    p4->right = p7;
    p5->left = p8;

    int key = 15;

    if(insertion_BST(root, key) == 1)
        printf("%d inserted successfully in BST!\n", key);
    else
        printf("%d already exists in BST, can't insert!\n", key);

    return 0;
}
