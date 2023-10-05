//Implement singly linked list (Insert at the head, insert at tail, insert at a position, delete at the head, delete at tail, delete form a position, search an element)
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the linked list
void insertAtHead(int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
}

// Function to insert a node at the end of the linked list
void insertAtTail(int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Function to insert a node at a given position in the linked list
void insertAtPosition(int data, int position) {
    if (position < 0) {
        printf("Invalid position\n");
        return;
    }

    if (position == 0) {
        insertAtHead(data);
        return;
    }

    struct Node* newNode = createNode(data);
    struct Node* current = head;
    int count = 0;

    while (count < position - 1 && current != NULL) {
        current = current->next;
        count++;
    }

    if (current == NULL) {
        printf("Position out of bounds\n");
        free(newNode);
        return;
    }

    newNode->next = current->next;
    current->next = newNode;
}

// Function to delete a node from the head of the linked list
void deleteAtHead() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = head;
    head = head->next;
    free(temp);
}

// Function to delete a node from the tail of the linked list
void deleteAtTail() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }

    struct Node* current = head;
    while (current->next->next != NULL) {
        current = current->next;
    }

    free(current->next);
    current->next = NULL;
}

// Function to delete a node from a given position in the linked list
void deleteAtPosition(int position) {
    if (position < 0 || head == NULL) {
        printf("Invalid position\n");
        return;
    }

    if (position == 0) {
        deleteAtHead();
        return;
    }

    struct Node* current = head;
    int count = 0;

    while (count < position - 1 && current != NULL) {
        current = current->next;
        count++;
    }

    if (current == NULL || current->next == NULL) {
        printf("Position out of bounds\n");
        return;
    }

    struct Node* temp = current->next;
    current->next = current->next->next;
    free(temp);
}

// Function to search for an element in the linked list
int searchElement(int data) {
    struct Node* current = head;
    int position = 0;

    while (current != NULL) {
        if (current->data == data) {
            return position;
        }
        current = current->next;
        position++;
    }

    return -1; // Element not found
}

// Function to display the linked list
void display() {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, data, position;

    while (1) {
        printf("\nLinked List Operations:\n");
        printf("1. Insert at the Head\n");
        printf("2. Insert at the Tail\n");
        printf("3. Insert at a Position\n");
        printf("4. Delete at the Head\n");
        printf("5. Delete at the Tail\n");
        printf("6. Delete at a Position\n");
        printf("7. Search an Element\n");
        printf("8. Display\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at the head: ");
                scanf("%d", &data);
                insertAtHead(data);
                break;
            case 2:
                printf("Enter data to insert at the tail: ");
                scanf("%d", &data);
                insertAtTail(data);
                break;
            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &position);
                insertAtPosition(data, position);
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
                scanf("%d", &data);
                position = searchElement(data);
                if (position != -1) {
                    printf("Element found at position %d\n", position);
                } else {
                    printf("Element not found\n");
                }
                break;
            case 8:
                display();
                break;
            case 9:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}

