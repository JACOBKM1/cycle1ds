#include <stdio.h>
#include <string.h>

int main() {
    char str1[100], str2[100], result[200];
    int choice;
     int start, length;

    printf("Enter the first string: ");
    scanf("%s", str1);

    printf("Enter the second string: ");
    scanf("%s", str2);

    printf("Choose an operation:\n");
    printf("1. Search for a substring\n");
    printf("2. Concatenate two strings\n");
    printf("3. Extract a substring\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            if (strstr(str1, str2) != NULL) {
                printf("'%s' is found in '%s'.\n", str2, str1);
            } else {
                printf("'%s' is not found in '%s'.\n", str2, str1);
            }
            break;

        case 2:
            strcpy(result, str1);
            strcat(result, str2);
            printf("Concatenated string: %s\n", result);
            break;

        case 3:
         
            printf("Enter the starting index for substring: ");
            scanf("%d", &start);
            printf("Enter the length of substring: ");
            scanf("%d", &length);

            if (start >= 0 && start < strlen(str1) && length >= 0) {
                strncpy(result, str1 + start, length);
                result[length] = '\0';
                printf("Extracted substring: %s\n", result);
            } else {
                printf("Invalid starting index or length.\n");
            }
            break;

        default:
            printf("Invalid choice.\n");
    }

    return 0;
}
