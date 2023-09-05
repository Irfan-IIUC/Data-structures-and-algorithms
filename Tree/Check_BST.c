#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
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

int isBST(struct node* root, int min, int max)
{
    if(root == NULL)
        return 1;

    if((root->data < min) || (root->data > max))
        return 0;

    return isBST(root->left, min, root->data - 1) && isBST(root->right, root->data + 1, max);
}

int main()
{
    /*
                 9
              /     \
             4      11
           /   \       \
          2     7      15
               / \     /
              5   8   14
    */

    struct node* root = create_node(9);

    struct node* p1 = create_node(4);
    struct node* p2 = create_node(11);

    struct node* p3 = create_node(2);
    struct node* p4 = create_node(7);
    struct node* p5 = create_node(15);

    struct node* p6 = create_node(5);
    struct node* p7 = create_node(8);
    struct node* p8 = create_node(14);

    root->left = p1;
    root->right = p2;

    p1->left = p3;
    p1->right = p4;
    p2->right = p5;

    p4->left = p6;
    p4->right = p7;
    p5->left = p8;

    if(isBST(root, INT_MIN, INT_MAX))
        printf("It is a Binary Search Tree!\n");
    else
        printf("It is not a Binary Search Tree!\n");

    return 0;
}
