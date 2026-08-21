#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

FILE *fp;
char delim[14] = {' ', '\t', '\n', ',', ';', '(', ')', '{', '}', '[', ']', '#', '<', '>'};
char oper[7] = {'+', '-', '*', '/', '%', '=', '!'};
char key[20][12] = {
    "int", "float", "char", "double", "bool", "void", "extern", "unsigned", "goto",
    "static", "class", "struct", "for", "if", "else", "return", "register", "long", "while", "do"
};
char predirect[2][12] = {"include", "define"};
char header[6][15] = {"stdio.h", "conio.h", "stdlib.h", "process.h", "string.h", "ctype.h"};

void skipcomment(void);
void analyze(void);
void check(char t[]);
int isdelim(char c);
int isop(char c);

int fop = 0, numflag = 0, f = 0;
char c, ch, sop;

int main(void) {
    char fname[50];
    printf("Enter filename: ");
    if (scanf("%s", fname) != 1) return 1;

    fp = fopen(fname, "r");
    if (fp == NULL) {
        printf("Error: File '%s' doesn't exist.\n", fname);
        return 1;
    }

    analyze();
    printf("\nEnd of file\n");
    fclose(fp);
    return 0;
}

void analyze(void) {
    char token[100];
    int j = 0;

    while ((c = fgetc(fp)) != EOF) {
        if (c == '/') {
            char next = fgetc(fp);
            if (next == '/' || next == '*') {
                ungetc(next, fp);
                skipcomment();
                continue;
            } else {
                ungetc(next, fp);
            }
        }

        if (isalpha(c) || c == '_') {
            token[j++] = c;
            while ((c = fgetc(fp)) != EOF && (isalnum(c) || c == '_' || c == '.')) {
                token[j++] = c;
            }
            token[j] = '\0';
            check(token);
            j = 0;
            if (c == EOF) break;
            ungetc(c, fp);
        } else if (isdigit(c)) {
            token[j++] = c;
            while ((c = fgetc(fp)) != EOF && (isdigit(c) || c == '.')) {
                token[j++] = c;
            }
            token[j] = '\0';
            printf("\nNumber\t\t\t%s", token);
            j = 0;
            if (c == EOF) break;
            ungetc(c, fp);
        } else if (isdelim(c)) {
            if (c != ' ' && c != '\t' && c != '\n') {
                printf("\nDelimiter\t\t%c", c);
            }
        } else if (isop(c)) {
            char next = fgetc(fp);
            if (isop(next)) {
                printf("\nOperator\t\t%c%c", c, next);
            } else {
                if (next != EOF) ungetc(next, fp);
                printf("\nOperator\t\t%c", c);
            }
        }
    }
}

int isdelim(char ch_in) {
    for (int i = 0; i < 14; i++) {
        if (ch_in == delim[i]) return 1;
    }
    return 0;
}

int isop(char ch_in) {
    for (int i = 0; i < 7; i++) {
        if (ch_in == oper[i]) return 1;
    }
    return 0;
}

void check(char t[]) {
    for (int i = 0; i < 2; i++) {
        if (strcmp(t, predirect[i]) == 0) {
            printf("\nPreprocessor directive\t%s", t);
            return;
        }
    }
    for (int i = 0; i < 6; i++) {
        if (strcmp(t, header[i]) == 0) {
            printf("\nHeader file\t\t%s", t);
            return;
        }
    }
    for (int i = 0; i < 20; i++) {
        if (strcmp(key[i], t) == 0) {
            printf("\nKeyword\t\t\t%s", key[i]);
            return;
        }
    }
    printf("\nIdentifier\t\t%s", t);
}

void skipcomment(void) {
    char next = fgetc(fp);
    if (next == '/') {
        while ((ch = fgetc(fp)) != EOF && ch != '\n');
    } else if (next == '*') {
        while ((ch = fgetc(fp)) != EOF) {
            if (ch == '*') {
                char c2 = fgetc(fp);
                if (c2 == '/') break;
                else if (c2 != EOF) ungetc(c2, fp);
            }
        }
    }
}
