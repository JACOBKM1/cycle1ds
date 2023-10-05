// mplement doubly linked list (Insert at the head, insert at tail, insert at a position, delete at the head, delete at tail, delete form a position, search an element).
#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the doubly linked list
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the head of the list
void insertAtHead(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    newNode->next = *head;
    (*head)->prev = newNode;
    *head = newNode;
}

// Function to insert a node at the tail of the list
void insertAtTail(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    newNode->prev = current;
}

// Function to insert a node at a specific position in the list
void insertAtPosition(struct Node** head, int data, int position) {
    if (position <= 0) {
        printf("Invalid position\n");
        return;
    }
    if (position == 1) {
        insertAtHead(head, data);
        return;
    }
    struct Node* newNode = createNode(data);
    struct Node* current = *head;
    int count = 1;
    while (count < position - 1 && current != NULL) {
        current = current->next;
        count++;
    }
    if (current == NULL) {
        printf("Position out of range\n");
        return;
    }
    newNode->next = current->next;
    newNode->prev = current;
    if (current->next != NULL) {
        current->next->prev = newNode;
    }
    current->next = newNode;
}

// Function to delete the node at the head of the list
void deleteAtHead(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next;
    if (*head != NULL) {
        (*head)->prev = NULL;
    }
    free(temp);
}

// Function to delete the node at the tail of the list
void deleteAtTail(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    if (current->prev != NULL) {
        current->prev->next = NULL;
    } else {
        *head = NULL;
    }
    free(current);
}

// Function to delete a node from a specific position in the list
void deleteAtPosition(struct Node** head, int position) {
    if (*head == NULL || position <= 0) {
        printf("Invalid operation\n");
        return;
    }
    if (position == 1) {
        deleteAtHead(head);
        return;
    }
    struct Node* current = *head;
    int count = 1;
    while (count < position && current != NULL) {
        current = current->next;
        count++;
    }
    if (current == NULL) {
        printf("Position out of range\n");
        return;
    }
    if (current->next != NULL) {
        current->next->prev = current->prev;
    }
    if (current->prev != NULL) {
        current->prev->next = current->next;
    } else {
        *head = current->next;
    }
    free(current);
}

// Function to search for an element in the list
int searchElement(struct Node* head, int key) {
    struct Node* current = head;
    int position = 1;
    while (current != NULL) {
        if (current->data == key) {
            return position;
        }
        current = current->next;
        position++;
    }
    return -1; // Element not found
}

// Function to display the linked list
void display(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data, position, key, result;

    while (1) {
        printf("1. Insert at head\n");
        printf("2. Insert at tail\n");
        printf("3. Insert at a position\n");
        printf("4. Delete at head\n");
        printf("5. Delete at tail\n");
        printf("6. Delete at a position\n");
        printf("7. Search an element\n");
        printf("8. Display\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertAtHead(&head, data);
                break;
            case 2:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertAtTail(&head, data);
                break;
            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &position);
                insertAtPosition(&head, data, position);
                break;
            case 4:
                deleteAtHead(&head);
                break;
            case 5:
                deleteAtTail(&head);
                break;
            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteAtPosition(&head, position);
                break;
            case 7:
                printf("Enter key to search: ");
                scanf("%d", &key);
                result = searchElement(head, key);
                if (result != -1) {
                    printf("Element found at position %d\n", result);
                } else {
                    printf("Element not found\n");
                }
                break;
            case 8:
                display(head);
                break;
            case 9:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}

