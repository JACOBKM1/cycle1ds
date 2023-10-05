#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the circular linked list
struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL; // Initialize an empty circular linked list

// Function to insert a node at the head of the circular linked list
void insertAtHead(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        newNode->next = head->next;
        head->next = newNode;
    }
}

// Function to insert a node at the tail of the circular linked list
void insertAtTail(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        struct Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
}

// Function to insert a node at a specified position in the circular linked list
void insertAtPosition(int value, int position) {
    if (position < 1) {
        printf("Invalid position\n");
        return;
    }
    if (position == 1) {
        insertAtHead(value);
        return;
    }
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    struct Node* temp = head;
    for (int i = 1; i < position - 1; i++) {
        if (temp->next == head) {
            printf("Position out of range\n");
            free(newNode);
            return;
        }
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

// Function to delete a node from the head of the circular linked list
void deleteAtHead() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head;
    if (temp->next == head) {
        head = NULL;
    } else {
        struct Node* lastNode = head;
        while (lastNode->next != head) {
            lastNode = lastNode->next;
        }
        head = head->next;
        lastNode->next = head;
    }
    free(temp);
}

// Function to delete a node from the tail of the circular linked list
void deleteAtTail() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head;
    struct Node* prev = NULL;
    while (temp->next != head) {
        prev = temp;
        temp = temp->next;
    }
    if (prev == NULL) {
        head = NULL;
    } else {
        prev->next = head;
    }
    free(temp);
}

// Function to delete a node from a specified position in the circular linked list
void deleteAtPosition(int position) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    if (position < 1) {
        printf("Invalid position\n");
        return;
    }
    if (position == 1) {
        deleteAtHead();
        return;
    }
    struct Node* temp = head;
    struct Node* prev = NULL;
    for (int i = 1; i < position; i++) {
        if (temp->next == head) {
            printf("Position out of range\n");
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;
    free(temp);
}

// Function to search for an element in the circular linked list
int searchElement(int value) {
    if (head == NULL) {
        return 0; // Element not found
    }
    struct Node* temp = head;
    do {
        if (temp->data == value) {
            return 1; // Element found
        }
        temp = temp->next;
    } while (temp != head);
    return 0; // Element not found
}

// Function to display the circular linked list
void displayList() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("Head\n");
}

int main() {
    int choice, value, position;
    while (1) {
        printf("\nCircular Linked List Operations:\n");
        printf("1. Insert at head\n");
        printf("2. Insert at tail\n");
        printf("3. Insert at a position\n");
        printf("4. Delete at head\n");
        printf("5. Delete at tail\n");
        printf("6. Delete at a position\n");
        printf("7. Search for an element\n");
        printf("8. Display the list\n");
        printf("9. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at head: ");
                scanf("%d", &value);
                insertAtHead(value);
                break;
            case 2:
                printf("Enter value to insert at tail: ");
                scanf("%d", &value);
                insertAtTail(value);
                break;
            case 3:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                printf("Enter position to insert at: ");
                scanf("%d", &position);
                insertAtPosition(value, position);
                break;
            case 4:
                deleteAtHead();
                break;
            case 5:
                deleteAtTail();
                break;
            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteAtPosition(position);
                break;
            case 7:
                printf("Enter element to search: ");
                scanf("%d", &value);
                if (searchElement(value)) {
                    printf("Element found in the list\n");
                } else {
                    printf("Element not found in the list\n");
                }
                break;
            case 8:
                displayList();
                break;
            case 9:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}

