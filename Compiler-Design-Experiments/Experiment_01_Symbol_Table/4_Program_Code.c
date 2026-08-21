#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 20

struct table {
    char var[10];
    int value;
};

struct table tbl[MAX];
int n = 0;

void create(void);
void insert(void);
void modify(void);
int search(char variable[], int count);
void display(void);

int main(void) {
    int ch, result = 0;
    char v[10];

    do {
        printf("\nEnter your choice:\n1.Create\n2.Insert\n3.Modify\n4.Search\n5.Display\n6.Exit\nChoice: ");
        if (scanf("%d", &ch) != 1) {
            break;
        }

        switch (ch) {
            case 1:
                create();
                break;
            case 2:
                insert();
                break;
            case 3:
                modify();
                break;
            case 4:
                printf("Enter the variable to be searched for: ");
                scanf("%s", v);
                result = search(v, n);
                if (result == 0) {
                    printf("The variable '%s' does not belong to the table.\n", v);
                } else {
                    printf("The location of the variable is %d\n", result);
                    printf("The value of %s is %d\n", tbl[result].var, tbl[result].value);
                }
                break;
            case 5:
                display();
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (ch != 6);

    return 0;
}

void create(void) {
    int i, j;
    printf("Enter the no. of entries: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        printf("Enter variable %d and value: ", i);
        scanf("%s %d", tbl[i].var, &tbl[i].value);

        while (!isalpha(tbl[i].var[0])) {
            printf("The variable should start with an alphabet.\nEnter correct variable name: ");
            scanf("%s %d", tbl[i].var, &tbl[i].value);
        }

        for (j = 1; j < i; j++) {
            if (strcmp(tbl[i].var, tbl[j].var) == 0) {
                printf("The variable already exists. Enter another variable name: ");
                scanf("%s %d", tbl[i].var, &tbl[i].value);
                j = 0; // recheck from beginning
            }
        }
    }
    printf("\nThe table after creation is:\n");
    display();
}

void insert(void) {
    int j;
    if (n >= MAX - 1) {
        printf("Cannot insert. Table is full!\n");
        return;
    }

    n++;
    printf("Enter the variable and value: ");
    scanf("%s %d", tbl[n].var, &tbl[n].value);

    while (!isalpha(tbl[n].var[0])) {
        printf("The variable should start with an alphabet.\nEnter correct variable name: ");
        scanf("%s %d", tbl[n].var, &tbl[n].value);
    }

    for (j = 1; j < n; j++) {
        if (strcmp(tbl[j].var, tbl[n].var) == 0) {
            printf("The variable already exists. Enter another variable: ");
            scanf("%s %d", tbl[n].var, &tbl[n].value);
            j = 0;
        }
    }

    printf("\nThe table after insertion is:\n");
    display();
}

void modify(void) {
    char variable[10];
    int result = 0;

    printf("Enter the variable to be modified: ");
    scanf("%s", variable);
    result = search(variable, n);

    if (result == 0) {
        printf("'%s' does not belong to the table.\n", variable);
    } else {
        printf("Current value of variable '%s' is %d\n", tbl[result].var, tbl[result].value);
        printf("Enter the new variable name and its value: ");
        scanf("%s %d", tbl[result].var, &tbl[result].value);

        while (!isalpha(tbl[result].var[0])) {
            printf("The variable should start with an alphabet.\nEnter correct variable name: ");
            scanf("%s %d", tbl[result].var, &tbl[result].value);
        }
        printf("\nThe table after modification is:\n");
        display();
    }
}

int search(char variable[], int count) {
    int i;
    for (i = 1; i <= count; i++) {
        if (strcmp(tbl[i].var, variable) == 0) {
            return i;
        }
    }
    return 0;
}

void display(void) {
    int i;
    printf("--------------------------\n");
    printf("VARIABLE\tVALUE\n");
    printf("--------------------------\n");
    for (i = 1; i <= n; i++) {
        printf("%s\t\t%d\n", tbl[i].var, tbl[i].value);
    }
    printf("--------------------------\n");
}
