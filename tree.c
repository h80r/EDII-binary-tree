// Libs needed
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Struct needed
typedef struct Node
{
    int value;
    struct Node *left;
    struct Node *right;
} Node;

// Functions needed
void startTree(Node **node);
void addValue(int value, Node** node);
int isBinarySearchTree(Node **node, int min, int max);
int searchValue(int value, Node** node);
int depth(Node **node);
void inOrder(Node **node);
void preOrder(Node **node);
void posOrder(Node **node);
Node* newNode(int value);

// Main function
int main()
{
    Node* tree;
    startTree(&tree);
    addValue(8, &tree);
    addValue(6, &tree);
    addValue(10, &tree);
    addValue(5, &tree);
    printf("%d\n", tree->value);
    printf("%d\n", tree->left->value);
    printf("%d\n", tree->left->left->value);
    printf("%d\n", tree->right->value);

    putchar('\n');

    if (isBinarySearchTree(&tree, INT_MIN, INT_MAX))
        puts("true\n");
    else
        puts("false\n\n");

    printf("%d\n", searchValue(6, &tree));
    printf("%d\n", searchValue(8, &tree));
    printf("%d\n", searchValue(19, &tree));

    putchar('\n');

    printf("%d\n", depth(&tree));

    putchar('\n');

    inOrder(&tree);    puts("\n");
    preOrder(&tree);   puts("\n");
    posOrder(&tree);   puts("\n");

    return 0;
}

// Functions
void startTree(Node **node)
{
    *node = NULL;
}

void addValue(int value, Node **node)
{
    if (*node == NULL)
        *node = newNode(value);
    else
    {
        if (value > (*node)->value)
            addValue(value, &(*node)->right);
        else
            addValue(value, &(*node)->left);
    }   
}

int isBinarySearchTree(Node **node, int min, int max)
{
    if (*node == NULL)
        return 1;
    if ((*node)->value <= min || (*node)->value > max)
        return 0;
    return isBinarySearchTree(&(*node)->left, min, (*node)->value) && isBinarySearchTree(&(*node)->right, (*node)->value, max);
}

int searchValue(int search, Node **node)
{
    if (*node == NULL)
        return 0;
    else 
    {
        if ((*node)->value == search)
            return 1;
        if ((*node)->value > search)
            return searchValue(search, &(*node)->left);
        return searchValue(search, &(*node)->right);
    }
}

int depth(Node **node)
{
    if (*node == NULL)
        return -1;
    else
    {
        int leftDepth = depth(&(*node)->left);
        int rightDepth = depth(&(*node)->right);

        if (leftDepth > rightDepth)
            return leftDepth + 1;
        else
            return rightDepth + 1;
    }
}

// left - root - right
void inOrder(Node **node)
{
    if (*node != NULL)
    {
        inOrder(&(*node)->left);
        printf("%d ", (*node)->value);
        inOrder(&(*node)->right); 
    }
}

// root - left - right
void preOrder(Node **node)
{
    if (*node != NULL)
    {
        printf("%d ", (*node)->value);
        preOrder(&(*node)->left);
        preOrder(&(*node)->right); 
    }
}

// left - right - root
void posOrder(Node **node)
{
    if (*node != NULL)
    {
        posOrder(&(*node)->left);
        posOrder(&(*node)->right); 
        printf("%d ", (*node)->value);
    }
}

Node* newNode(int value)
{
    Node* output = (Node*) malloc(sizeof(Node));
    output->value = value;
    output->left = NULL;
    output->right = NULL;
    return output;
}