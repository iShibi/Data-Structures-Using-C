// Node struct
// usage: struct Node* root = NULL;
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// function declarations
struct Node* createNode(int data);
struct Node* insert(int data, struct Node** node);
void printInOrder(struct Node* node);       // [left] [root] [right]
void printPreOrder(struct Node* node);      // [root] [left] [right]
void printPostOrder(struct Node* node);     // [left] [right] [root]

// create node function
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// insert node function
// usage: insert(1, &root);
struct Node* insert(int data, struct Node** node) {
    if (*node == NULL) {
        *node = createNode(data);
    } else if (data < (*node)->data) {
        (*node)->left = insert(data, &(*node)->left);
    } else if (data > (*node)->data) {
        (*node)->right = insert(data, &(*node)->right);
    }
    return *node;
}

// inorder traversal function [Depth First Traversal]
// usage: printInOrder(root);
void printInOrder(struct Node* node) {
    if (node == NULL) {
        return;
    }
    printInOrder(node->left);
    printf("%d ", node->data);
    printInOrder(node->right);
}

// preOrder traversal function [Depth First Traversal]
// usage: printPreOrder(root);
void printPreOrder(struct Node* node) {
    if (node == NULL) {
        return;
    }
    printf("%d ", node->data);
    printPreOrder(node->left);
    printPreOrder(node->right);
}

// postOrder traversal function [Depth First Traversal]
// usage: printPostOrder(root);
void printPostOrder(struct Node* node) {
    if (node == NULL) {
        return;
    }
    printPostOrder(node->left);
    printPostOrder(node->right);
    printf("%d ", node->data);
}

// search node function
// check returned node is not NULL before using it
// usage: search(1, root);
struct Node* search(int data, struct Node* node) {
    if (node == NULL) {
        return NULL;
    } else if (data == node->data) {
        return node;
    } else if (data < node->data) {
        return search(data, node->left);
    } else if (data > node->data) {
        return search(data, node->right);
    }
}