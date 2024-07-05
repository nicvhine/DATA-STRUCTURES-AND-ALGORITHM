#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "binaryTree.h"

struct node *newNode(Product item) {
    struct node *node = (struct node *)malloc(sizeof(NodeType));
    if (node != NULL) {
        node->item = item;
        node->left = NULL;
        node->right = NULL;
    }
    return node;
}

int compareProducts(Product a, Product b) {
    return strcmp(a.prodName, b.prodName);
}

struct node *insert(struct node *root, Product item) {
    if (root == NULL) {
        return newNode(item);
    } else {
        if (compareProducts(item, root->item) <= 0) {
            root->left = insert(root->left, item);
        } else {
            root->right = insert(root->right, item);
        }
        return root;
    }
}

struct node *minValueNode(struct node *node) {
    struct node *current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

struct node *deleteNode(struct node *root, Product item) {
    if (root == NULL) return root;

    int comparison = compareProducts(item, root->item);
    if (comparison < 0) {
        root->left = deleteNode(root->left, item);
    } else if (comparison > 0) {
        root->right = deleteNode(root->right, item);
    } else {
        if (root->left == NULL) {
            struct node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        struct node *temp = minValueNode(root->right);

        root->item = temp->item;

        root->right = deleteNode(root->right, temp->item);
    }
    return root;
}

// Inorder Traversal
void inorderTraversal(struct node *root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("| %-20s | %-6.2f | %-8d | %02d/%02d/%04d |\n",
               root->item.prodName, root->item.prodPrice, root->item.prodQty,
               root->item.expDate.day, root->item.expDate.month, root->item.expDate.year);
        inorderTraversal(root->right);
    }
}

// Preorder Traversal
void preorderTraversal(struct node *root) {
    if (root != NULL) {
        printf("| %-20s | %-6.2f | %-8d | %02d/%02d/%04d |\n",
               root->item.prodName, root->item.prodPrice, root->item.prodQty,
               root->item.expDate.day, root->item.expDate.month, root->item.expDate.year);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// Postorder Traversal
void postorderTraversal(struct node *root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("| %-20s | %-6.2f | %-8d | %02d/%02d/%04d |\n",
               root->item.prodName, root->item.prodPrice, root->item.prodQty,
               root->item.expDate.day, root->item.expDate.month, root->item.expDate.year);
    }
}

// BFS Traversal
void bfsTraversal(struct node *root) {
    if (root == NULL) return;

    struct node **queue = malloc(100 * sizeof(struct node *));
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        struct node *current = queue[front++];
        printf("| %-20s | %-6.2f | %-8d | %02d/%02d/%04d |\n",
               current->item.prodName, current->item.prodPrice, current->item.prodQty,
               current->item.expDate.day, current->item.expDate.month, current->item.expDate.year);

        if (current->left != NULL) {
            queue[rear++] = current->left;
        }
        if (current->right != NULL) {
            queue[rear++] = current->right;
        }
    }

    free(queue);
}

