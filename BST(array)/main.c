#include "functions.c"
#include <windows.h>
int main() {
    bt root;
    init(&root);
    
    int choice, value;

    do {
        printf("\nMenu:\n");
        printf("1. Insert Node\n");
        printf("2. Check if BST is Complete\n");
        printf("3. Levelwise Traversal\n");
        printf("4. Inorder Traversal\n");
        printf("5. Preorder Traversal\n");
        printf("6. Postorder Traversal\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value for the node to be inserted: ");
                scanf("%d", &value);
                insert(&root, value);
                printf("Node inserted successfully.\n");
                break;

            case 2:
                if (iscomplete(&root)) {
                    printf("The BST is a complete tree.\n");
                } else {
                    printf("The BST is not a complete tree.\n");
                }
                break;

            case 3:
                printf("Levelwise Traversal: ");
                levelwise(&root);
                printf("\n");
                break;

            case 4:
                printf("Inorder Traversal: ");
                inorder(&root);
                printf("\n");
                break;

            case 5:
                printf("Preorder Traversal: ");
                preorder(&root);
                printf("\n");
                break;

            case 6:
                printf("Postorder Traversal: ");
                postorder(&root);
                printf("\n");
                break;

            case 7:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
        Sleep(2000);
    } while (choice != 7);

    return 0;
}
