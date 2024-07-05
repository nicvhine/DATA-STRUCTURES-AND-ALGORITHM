#ifndef BINARY_TREE_HEADER
#define BINARY_TREE_HEADER

typedef struct {
    int day, month, year;
} Date;

typedef struct {
    char prodName[20];
    float prodPrice;
    int prodQty;
    Date expDate;
} Product;

typedef struct node {
    Product item;
    struct node *left, *right;
} NodeType, *NodePtr;

struct node *newNode(Product item);
int compareProducts(Product a, Product b);
struct node *insert(struct node *root, Product item);
struct node *minValueNode(struct node *node);
struct node *deleteNode(struct node *root, Product item);
void inorderTraversal(struct node *root);
void preorderTraversal(struct node *root);
void postorderTraversal(struct node *root);
void bfsTraversal(struct node *root);

#endif