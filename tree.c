// Libs needed
#include <stdio.h>
#include <stdlib.h>

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
Node* newNode(int value);

// Main function
int main()
{
    Node* tree;
    startTree(&tree);
    addValue(8, &tree);
    addValue(6, &tree);
    addValue(10, &tree);
    printf("%d\n", tree->value);
    printf("%d\n", tree->left->value);
    printf("%d\n", tree->right->value);
    return 0;
}

// Functions
void startTree(Node **node)
{
    *node = NULL;
}

void addValue(int value, Node** node)
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

Node* newNode(int value)
{
    Node* output =(Node*) malloc(sizeof(Node));
    output->value = value;
    output->left = NULL;
    output->right = NULL;
    return output;
}