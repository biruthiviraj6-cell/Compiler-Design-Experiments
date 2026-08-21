#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

char code[100][100];

int main(void) {
    FILE *fp;
    int i = 0, lines = 0;
    char buffer[100];

    printf("===================================================\n");
    printf("       CODE OPTIMIZATION TECHNIQUES IN C\n");
    printf("===================================================\n");
    printf("Enter Three Address Code lines (Type 'END' to finish):\n");

    fp = fopen("infile.txt", "w");
    if (fp == NULL) {
        printf("Error opening file for writing.\n");
        return 1;
    }

    while (fgets(buffer, sizeof(buffer), stdin)) {
        buffer[strcspn(buffer, "\r\n")] = '\0';
        if (strcmp(buffer, "END") == 0) break;
        if (strlen(buffer) > 0) {
            fprintf(fp, "%s\n", buffer);
        }
    }
    fclose(fp);

    // Read from file
    fp = fopen("infile.txt", "r");
    if (fp == NULL) {
        printf("Error opening file for reading.\n");
        return 1;
    }

    printf("\n--- Unoptimized Code ---\n");
    while (fgets(code[lines], sizeof(code[lines]), fp)) {
        code[lines][strcspn(code[lines], "\r\n")] = '\0';
        printf("%s\n", code[lines]);
        lines++;
    }
    fclose(fp);

    printf("\n--- Optimized Code ---\n");
    for (i = 0; i < lines; i++) {
        char lhs, op1, op2, opr;
        int val1, val2, res;

        if (sscanf(code[i], "%c=%c%c%c;", &lhs, &op1, &opr, &op2) == 4 ||
            sscanf(code[i], "%c = %c %c %c;", &lhs, &op1, &opr, &op2) == 4 ||
            sscanf(code[i], "%c=%c%c%c", &lhs, &op1, &opr, &op2) == 4) {

            if (isdigit(op1) && isdigit(op2)) {
                val1 = op1 - '0';
                val2 = op2 - '0';
                switch (opr) {
                    case '+': res = val1 + val2; break;
                    case '-': res = val1 - val2; break;
                    case '*': res = val1 * val2; break;
                    case '/': res = (val2 != 0) ? (val1 / val2) : 0; break;
                    default:  res = 0; break;
                }
                printf("%c=%d;\t\t// Constant Folding\n", lhs, res);
            } else if ((opr == '*' && op2 == '1') || (opr == '/' && op2 == '1')) {
                printf("%c=%c;\t\t// Algebraic Simplification (X*1 or X/1 -> X)\n", lhs, op1);
            } else if ((opr == '+' && op2 == '0') || (opr == '-' && op2 == '0')) {
                printf("%c=%c;\t\t// Algebraic Simplification (X+0 or X-0 -> X)\n", lhs, op1);
            } else if (opr == '*' && op2 == '2') {
                printf("%c=%c+%c;\t\t// Strength Reduction (X*2 -> X+X)\n", lhs, op1, op1);
            } else {
                printf("%s;\t\t// No Optimization\n", code[i]);
            }
        } else {
            printf("%s\n", code[i]);
        }
    }
    printf("===================================================\n");

    return 0;
}
