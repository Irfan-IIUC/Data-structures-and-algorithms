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

void inorder(struct node* root)
{
    if(root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
};

int main()
{
    /*
                7
              /   \
             2     1
            / \
           3   5
    */

    struct node* root = create_node(7);

    struct node* p1 = create_node(2);
    struct node* p2 = create_node(1);

    struct node* p3 = create_node(3);
    struct node* p4 = create_node(5);

    root->left = p1;
    root->right = p2;

    p1->left = p3;
    p1->right = p4;

    printf("InOrder traversal: ");
    inorder(root);

    printf("\n");

    return 0;
}
