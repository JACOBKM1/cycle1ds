#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

void insert(int value) {
    if (rear == MAX_SIZE - 1) {
        printf("Queue is full. Cannot insert.\n");
    } else {
        if (front == -1) {
            front = 0;
        }
        rear++;
        queue[rear] = value;
        printf("%d inserted into the queue.\n", value);
    }
}

void delete() {
    if (front == -1) {
        printf("Queue is empty. Cannot delete.\n");
    } else {
        int deletedValue = queue[front];
        if (front == rear) {
            front = rear = -1;
        } else {
            front++;
        }
        printf("%d deleted from the queue.\n", deletedValue);
    }
}

void displayFront() {
    if (front == -1) {
        printf("Queue is empty. Front value undefined.\n");
    } else {
        printf("Front value: %d\n", queue[front]);
    }
}

void displayRear() {
    if (rear == -1) {
        printf("Queue is empty. Rear value undefined.\n");
    } else {
        printf("Rear value: %d\n", queue[rear]);
    }
}

int main() {
    int choice, value;
    
    while (1) {
        printf("\nQueue Operations:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display Front\n");
        printf("4. Display Rear\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter a value to insert: ");
                scanf("%d", &value);
                insert(value);
                break;
            case 2:
                delete();
                break;
            case 3:
                displayFront();
                break;
            case 4:
                displayRear();
                break;
            case 5:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

