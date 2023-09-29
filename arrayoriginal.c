#include <stdio.h>

#define MAX_SIZE 100

int arr[MAX_SIZE];
int size = 0;
void displayArray() {
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void insertElement() {
    if (size >= MAX_SIZE) {
        printf("Array is full. Cannot insert.\n");
        return;
    }
    int element, position;
    printf("Enter element to insert: ");
    scanf("%d", &element);

    if (size == 0) {
        arr[size++] = element;
        return;
    }
    printf("Enter position for insertion (0-%d): ", size);
    scanf("%d", &position);

    if (position < 0 || position > size) {
        printf("Invalid position for insertion.\n");
        return;
    }
    for (int i = size; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position] = element;
    size++;
}
void deleteElement() {
    if (size == 0) {
        printf("Array is empty. Cannot delete.\n");
        return;
    }
    int position;
    printf("Enter position for deletion (0-%d): ", size - 1);
    scanf("%d", &position);

    if (position < 0 || position >= size) {
        printf("Invalid position for deletion.\n");
        return;
    }
    for (int i = position; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
}
void sortArray() {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
void mergeArrays() {
    int size2;
    printf("Enter the size of the second array: ");
    scanf("%d", &size2);

    if (size + size2 > MAX_SIZE) {
        printf("Arrays are too large to merge.\n");
        return;
    }
    printf("Enter elements for the second array:\n");
    for (int i = size; i < size + size2; i++) {
        scanf("%d", &arr[i]);
    }
    size += size2;
}
int main() {
    int choice;
    while (1) {
        printf("\nArray Operations:\n");
        printf("1. Insert Element\n");
        printf("2. Delete Element\n");
        printf("3. Sort Array\n");
        printf("4. Merge Arrays\n");
        printf("5. Display Array\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                insertElement();
                break;
            case 2:
                deleteElement();
                break;
            case 3:
                sortArray();
                break;
            case 4:
                mergeArrays();
                break;
            case 5:
                displayArray();
                break;
            case 6:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}

