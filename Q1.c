#include <stdio.h>

struct Date {
    int day;
    int month;
    int year;
};

void initDate(struct Date* ptrDate) {
    ptrDate->day = 1;
    ptrDate->month = 1;
    ptrDate->year = 2000;
}

void printDateOnConsole(struct Date* ptrDate) {
    printf("Date: %02d/%02d/%04d\n", ptrDate->day, ptrDate->month, ptrDate->year);
}

void acceptDateFromConsole(struct Date* ptrDate) {
    printf("Enter date (dd mm yyyy): ");
    scanf("%d %d %d", &ptrDate->day, &ptrDate->month, &ptrDate->year);
}

int main() {
    struct Date today;
    int choice;

    do {
        printf("Menu:\n");
        printf("1. Initialize Date\n");
        printf("2. Print Date\n");
        printf("3. Accept Date\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                initDate(&today);
                printf("Date initialized.\n");
                break;
            case 2:
                printDateOnConsole(&today);
                break;
            case 3:
                acceptDateFromConsole(&today);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
