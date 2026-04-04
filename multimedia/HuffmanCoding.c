#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Node structure for Huffman tree
struct Node {
    char data;
    int freq;
    struct Node *left, *right;
};

// Create a new node
struct Node* createNode(char data, int freq) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->freq = freq;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Print Huffman codes from the tree
void printCodes(struct Node* root, int arr[], int top) {
    // Go left: assign 0
    if (root->left) {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }
    
    // Go right: assign 1
    if (root->right) {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }
    
    // Leaf node: print the character and its code
    if (!root->left && !root->right) {
        printf("%c: ", root->data);
        for (int i = 0; i < top; i++) {
            printf("%d", arr[i]);
        }
        printf("\n");
    }
}

int main() {
    struct Node* root;
    int arr[MAX], top = 0;
    
    // Example: Build a sample Huffman tree manually
    //       (*, 100)
    //       /      \
    //    (A,40)   (*,60)
    //             /     \
    //          (B,30)  (C,30)
    
    root = createNode('*', 100);
    root->left = createNode('A', 40);
    root->right = createNode('*', 60);
    root->right->left = createNode('B', 30);
    root->right->right = createNode('C', 30);
    
    printf("Huffman Codes:\n");
    printCodes(root, arr, top);
    
    return 0;
}