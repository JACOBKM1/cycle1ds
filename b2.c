#include <stdio.h>
#define MAX_SIZE 5
int queue[MAX_SIZE];
int front = -1, rear = -1;

void insert() {
    if ((front == 0 && rear == MAX_SIZE - 1) || (rear == (front - 1) % (MAX_SIZE - 1))) {
        printf("Queue is full, cannot insert.\n");
    } else {
        int item;
        printf("Enter the element to insert: ");
        scanf("%d", &item);
        if (front == -1) {
            front = rear = 0;
            queue[rear] = item;
        } else if (rear == MAX_SIZE - 1 && front != 0) {
            rear = 0;
            queue[rear] = item;
        } else {
            rear++;
            queue[rear] = item;
        }
        printf("%d inserted successfully.\n", item);
    }
}

void delete() {
    if (front == -1) {
        printf("Queue is empty, cannot delete.\n");
    } else {
        int item = queue[front];
        if (front == rear) {
            front = rear = -1;
        } else if (front == MAX_SIZE - 1) {
            front = 0;
        } else {
            front++;
        }
        printf("%d deleted successfully.\n", item);
    }
}

void displayFrontRear() {
    if (front == -1) {
        printf("Queue is empty.\n");
    } else {
        printf("Front value: %d\n", queue[front]);
        printf("Rear value: %d\n", queue[rear]);
    }
}

int main() {
    int choice;
    
    while (1) {
        printf("\nCircular Queue Operations:\n");
        printf("1. Insert\n2. Delete\n3. Display Front and Rear\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                displayFrontRear();
                break;
            case 4:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}

