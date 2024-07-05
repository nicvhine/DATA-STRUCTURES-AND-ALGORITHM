#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "binaryTree.h"

int main() {
    struct node *root = NULL;
    Product p1 = {"Product1", 10.5, 5, {1, 1, 2025}};
    Product p2 = {"Product2", 20.0, 3, {15, 5, 2023}};
    Product p3 = {"Product3", 13.0, 10, {30, 8, 2024}};
    Product p4 = {"Product4", 11.0, 10, {30, 8, 2024}};
    Product p5 = {"Product5", 25.0, 10, {30, 8, 2024}};

    root = insert(root, p1);
    root = insert(root, p2);
    root = insert(root, p3);
    root = insert(root, p4);
    root = insert(root, p5);

    printf("INORDER TRAVERSAL\n");
    printf("| %-20s | %-6s | %-8s | %-10s |\n", "Product Name", "Price", "Quantity", "Expiry Date");
    printf("|----------------------|--------|----------|------------|\n");
    inorderTraversal(root);

    printf("\nPREORDER TRAVERSAL\n");
    printf("| %-20s | %-6s | %-8s | %-10s |\n", "Product Name", "Price", "Quantity", "Expiry Date");
    printf("|----------------------|--------|----------|------------|\n");
    preorderTraversal(root);

    printf("\nPOSTORDER TRAVERSAL\n");
    printf("| %-20s | %-6s | %-8s | %-10s |\n", "Product Name", "Price", "Quantity", "Expiry Date");
    printf("|----------------------|--------|----------|------------|\n");
    postorderTraversal(root);

    printf("\nBFS TRAVERSAL\n");
    printf("| %-20s | %-6s | %-8s | %-10s |\n", "Product Name", "Price", "Quantity", "Expiry Date");
    printf("|----------------------|--------|----------|------------|\n");
    bfsTraversal(root);

    root = deleteNode(root, p2);

    printf("\nINORDER TRAVERSAL AFTER DELETION\n");
    printf("| %-20s | %-6s | %-8s | %-10s |\n", "Product Name", "Price", "Quantity", "Expiry Date");
    printf("|----------------------|--------|----------|------------|\n");
    inorderTraversal(root);

    return 0;
}
