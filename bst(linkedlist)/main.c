#include <stdio.h>
#include "functions.c"

int main() {
    struct Node* root = initBST();
    int choice, mis;
    char name[50];

    do {
        printf("\nMenu:\n");
        printf("1. Insert Node\n");
        printf("2. Count Nodes\n");
        printf("3. Remove Node\n");
        printf("4. Search\n");
        printf("5. Inorder Traversal\n");
        printf("6. Preorder Traversal\n");
        printf("7. Postorder Traversal\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter mis: ");
                scanf("%d", &mis);
                printf("Enter Name: ");
                scanf("%s", name);
                root = insertnode(root, mis, name);
                break;

            case 2:
                printf("Total Nodes: %d\n", countnodes(root));
                break;

            case 3:
                printf("Enter mis to remove: ");
                scanf("%d", &mis);
                root = removenode(root, mis);
                break;

            case 4:
                printf("Enter mis to search: ");
                scanf("%d", &mis);
                if (search(root, mis) != NULL) {
                    printf("Node found!\n");
                } else {
                    printf("Node not found!\n");
                }
                break;

            case 5:
                printf("Inorder Traversal:\n");
                inorder(root);
                break;

            case 6:
                printf("Preorder Traversal:\n");
                preorder(root);
                break;

            case 7:
                printf("Postorder Traversal:\n");
                postorder(root);
                break;

            case 8:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 8);

    return 0;
}
