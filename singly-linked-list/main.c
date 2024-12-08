#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node and add it to the end of the list
void addNode(struct Node** head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;  // If the list is empty, make newNode the head
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;  // Traverse to the end of the list
        }
        temp->next = newNode;
    }
    printf("Node with value %d added.\n", value);
}

// Function to delete a node by value
void deleteNode(struct Node** head, int value) {
    struct Node *temp = *head, *prev = NULL;

    // If the head node itself holds the value to be deleted
    if (temp != NULL && temp->data == value) {
        *head = temp->next;  // Change head
        free(temp);  // Free old head
        printf("Node with value %d deleted.\n", value);
        return;
    }

    // Search for the node to be deleted
    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    // If value was not found in the list
    if (temp == NULL) {
        printf("Node with value %d not found.\n", value);
        return;
    }

    // Unlink the node from the list
    prev->next = temp->next;
    free(temp);
    printf("Node with value %d deleted.\n", value);
}

// Function to display the list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    printf("Current List: ");
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    struct Node* head = NULL;
    int choice, value;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Add Node\n");
        printf("2. Delete Node\n");
        printf("3. Display List\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to add: ");
                scanf("%d", &value);
                addNode(&head, value);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteNode(&head, value);
                break;
            case 3:
                displayList(head);
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
