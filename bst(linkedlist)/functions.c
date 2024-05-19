#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

struct Node* initBST() {
    return NULL;
}

struct Node* insertnode(struct Node* root, int MIS, const char* Name) {
    if (root == NULL) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->MIS = MIS;
        strcpy(newNode->Name, Name);
        newNode->left = newNode->right = NULL;
        return newNode;
    }

    if (MIS < root->MIS) {
        root->left = insertnode(root->left, MIS, Name);
    } else if (MIS > root->MIS) {
        root->right = insertnode(root->right, MIS, Name);
    }

    return root;
}

int countnodes(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + countnodes(root->left) + countnodes(root->right);
}

struct Node* removenode(struct Node* root, int MIS) {
    if (root == NULL) {
        return NULL;
    }

    if (MIS < root->MIS) {
        root->left = removenode(root->left, MIS);
    } else if (MIS > root->MIS) {
        root->right = removenode(root->right, MIS);
    } else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        struct Node* temp = root->right;
        while (temp->left != NULL) {
            temp = temp->left;
        }

        root->MIS = temp->MIS;
        root->right = removenode(root->right, temp->MIS);
    }

    return root;
}

struct Node* search(struct Node* root, int MIS) {
    if (root == NULL || root->MIS == MIS) {
        return root;
    }

    if (MIS < root->MIS) {
        return search(root->left, MIS);
    } else {
        return search(root->right, MIS);
    }
}

void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("MIS: %d, Name: %s\n", root->MIS, root->Name);
        inorder(root->right);
    }
}

void preorder(struct Node* root) {
    if (root != NULL) {
        printf("MIS: %d, Name: %s\n", root->MIS, root->Name);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("MIS: %d, Name: %s\n", root->MIS, root->Name);
    }
}
