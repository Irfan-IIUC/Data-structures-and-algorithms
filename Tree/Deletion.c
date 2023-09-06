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

struct node *inOrderPredecessor(struct node* root)
{
    root = root->left;

    while(root->right != NULL)
        root = root->right;

    return root;
}

struct node *inOrderSuccessor(struct node* root)
{
    root = root->right;

    while(root->left != NULL)
        root = root->left;

    return root;
}

struct node* delete_BST(struct node* root, int value)
{
    if(root == NULL)
        return NULL;
    else if((root->left == NULL) && (root->right == NULL))
    {
        free(root);
        return NULL;
    }
    else if(value < root->data)
    {
        root->left = delete_BST(root->left, value);
    }
    else if(value > root->data)
    {
        root->right = delete_BST(root->right, value);
    }
    else
    {
        struct node* iPre = inOrderPredecessor(root);
        // struct node* iPre = inOrderSuccessor(root);

        root->data = iPre->data;
        root->left = delete_BST(root->left, iPre->data);
    }

    return root;
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

    int val;

    printf("InOrder Traversal: ");
    inorder(root);

    printf("\nEnter the value to be deleted: ");
    scanf("%d", &val);

    delete_BST(root, val);

    printf("\nInOrder Traversal: ");
    inorder(root);
    printf("\n");

    return 0;
}
