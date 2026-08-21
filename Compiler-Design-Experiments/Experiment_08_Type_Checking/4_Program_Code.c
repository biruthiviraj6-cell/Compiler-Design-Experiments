#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int count = 0;
char key[4][12] = {"int", "float", "char", "double"};
char dstr[100][100], estr[100][100];

struct table {
    char var[10];
    char dt[10];
} tbl[20];

void entry(char *declaration);
int check(char t[]);
int search(char variable[]);
void typecheck(char *expression);

int main(void) {
    int i = 0, num_d = 0, num_e = 0;
    char line[100];

    printf("======================================\n");
    printf("   IMPLEMENTATION OF TYPE CHECKING\n");
    printf("======================================\n");

    printf("\nDECLARATIONS (Enter 'END' to finish):\n");
    while (1) {
        printf("  ");
        if (!fgets(line, sizeof(line), stdin)) break;
        line[strcspn(line, "\r\n")] = '\0';
        if (strcmp(line, "END") == 0) break;
        if (strlen(line) > 0) {
            strcpy(dstr[num_d++], line);
            entry(line);
        }
    }

    printf("\nEXPRESSIONS (Enter 'END' to finish):\n");
    while (1) {
        printf("  ");
        if (!fgets(line, sizeof(line), stdin)) break;
        line[strcspn(line, "\r\n")] = '\0';
        if (strcmp(line, "END") == 0) break;
        if (strlen(line) > 0) {
            strcpy(estr[num_e++], line);
        }
    }

    printf("\n======================================\n");
    printf(" SEMANTIC ANALYZER (TYPE CHECKING):\n");
    printf("======================================\n");
    for (i = 0; i < num_e; i++) {
        typecheck(estr[i]);
    }

    return 0;
}

void entry(char *declaration) {
    char datatype[10], varname[10];
    if (sscanf(declaration, "%s %[^;];", datatype, varname) < 2) {
        return;
    }

    if (!check(datatype)) {
        printf("Invalid datatype: %s\n", datatype);
        return;
    }

    if (search(varname) != -1) {
        printf("The variable '%s' is already declared.\n", varname);
        return;
    }

    strcpy(tbl[count].dt, datatype);
    strcpy(tbl[count].var, varname);
    count++;
}

int check(char t[]) {
    for (int i = 0; i < 4; i++) {
        if (strcmp(key[i], t) == 0) {
            return 1;
        }
    }
    return 0;
}

int search(char variable[]) {
    for (int i = 0; i < count; i++) {
        if (strcmp(tbl[i].var, variable) == 0) {
            return i;
        }
    }
    return -1;
}

void typecheck(char *expression) {
    char result[10], op1[10], op2[10], op;
    char resultvardt[10], arg1dt[10], arg2dt[10];

    int matched = sscanf(expression, "%s = %s %c %[^;];", result, op1, &op, op2);
    if (matched < 4) {
        printf("Invalid expression format: %s\n", expression);
        return;
    }

    int rIndex = search(result);
    int o1Index = search(op1);
    int o2Index = search(op2);

    if (rIndex == -1) {
        printf("Undefined variable: %s\n", result);
        return;
    }
    if (o1Index == -1) {
        printf("Undefined variable: %s\n", op1);
        return;
    }
    if (o2Index == -1) {
        printf("Undefined variable: %s\n", op2);
        return;
    }

    strcpy(resultvardt, tbl[rIndex].dt);
    strcpy(arg1dt, tbl[o1Index].dt);
    strcpy(arg2dt, tbl[o2Index].dt);

    if (strcmp(arg1dt, arg2dt) == 0) {
        if (strcmp(resultvardt, arg1dt) == 0) {
            printf("No type mismatch in expression: %s\n", expression);
        } else {
            printf("Type mismatch: Lvalue (%s) and Rvalue (%s) must be same in '%s'\n", resultvardt, arg1dt, expression);
        }
    } else {
        printf("Type mismatch between operands (%s and %s) in '%s'\n", arg1dt, arg2dt, expression);
    }
}
