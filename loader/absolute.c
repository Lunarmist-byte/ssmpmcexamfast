#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define BUF 1000


int main() {
    FILE* obj = fopen("objcode.txt", "r");
    if (!obj) {
        printf("Couldnot open file...\n");
        return 1;
    }
    int locctr = 0;
    char ch;
    while ((ch = fgetc(obj)) != EOF) {
        if (ch == 'H') {
            while ((ch = fgetc(obj)) == ' ');
            char pname[6];
            int start, length;
            fscanf(obj, "%s %X %X\n", pname, &start, &length);
            locctr = start;
            printf("Program Name: %c%s\n", ch, pname);
            printf("Starting Address: %X\n", start);
            printf("Program Length: %X\n", length);
        }
        else if (ch == 'T') {
            while ((ch = fgetc(obj)) == ' ');
            int start, length;
            fscanf(obj, "%X %X ", &start, &length);
            for (int i = 0; i < length; i++) {
                ch = fgetc(obj);
                if (ch == ' ') {
                    i--;
                    continue;
                }
                char ch1 = fgetc(obj);
                printf("%X: %c%c\n", locctr++, ch, ch1);
            }
        }
    }
    return 0;
}
