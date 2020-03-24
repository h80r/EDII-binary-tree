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
int searchValue(int value, Node** node);
int depth(Node **node);
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
    
    printf("%d\n", searchValue(6, &tree));
    printf("%d\n", searchValue(8, &tree));
    printf("%d\n", searchValue(19, &tree));

    putchar('\n');

    printf("%d\n", depth(&tree));

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

Node* newNode(int value)
{
    Node* output = (Node*) malloc(sizeof(Node));
    output->value = value;
    output->left = NULL;
    output->right = NULL;
    return output;
}