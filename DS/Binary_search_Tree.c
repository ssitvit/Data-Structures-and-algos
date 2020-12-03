#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *left;
    struct node *right;
};
struct node *newNode(int item)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d  ", root->data);
        inorder(root->right);
    }
}
void preorder(struct node *root)
{
    if(root!=NULL)
    {
        printf("%d  ", root->data);
        inorder(root->left);
        inorder(root->right);
    }
}
void postorder(struct node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        inorder(root->right);
        printf("%d  ", root->data);
    }
}
struct node* insert(struct node* node, int data){
    if(node==NULL)
        return newNode(data);
    if(data<node->data)
        node->left = insert(node->left, data);
    else if (data>node->data)
        node->right=insert(node->right, data);
    return node;
}
void main()
{
    struct node *root=NULL;
    int input, choice;
    printf("Enter root node: ");
    scanf("%d", &input);
    root = insert(root, input);
    printf("1. Insert element\n2. Inorder Traversal\n3. Preorder Traversal\n4. Postorder Traversal\n0. Exit\nEnter your choice: ");
    scanf("%d", &choice);
    while(choice!=0)
    {
        switch(choice)
        {
        case 1:
            printf("Enter data: ");
            scanf("%d", &input);
            insert(root, input);
            break;
        case 2:
            printf("Inorder Traversal:\n");
            inorder(root);
            break;
        case 3:
            printf("Preorder Traversal:\n");
            preorder(root);
            break;
        case 4:
            printf("Postorder Traversal:\n");
            postorder(root);
            break;
        }
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
    }
}
