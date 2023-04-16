#include <cstring>
#include <stdio.h>
#include <string>

#include <libgeometry/lexer.h>

using namespace std;

void printGaps(int n)
{
    for (int i = 0; i < n - 1; i++)
        printf(" ");
}

void ErCheck(char arr[N], int line, int* p)
{
    string name;

    // Check name of figure
    for (int i = 0; i < 6; i++)
        name += tolower(arr[i]);
    if (name != "circle") {
        *p = 0;
        printf("%s", arr);
        printf("^\n" RED("ERROR") " in line %d: expected 'circle'\n\n", line);
        return;
    }

    // Check coordinates
    int index = 7;
    while (arr[index] != ',') {
        if (arr[index] != ' ') {
            if (!(((arr[index] >= '0') && (arr[index] <= '9'))
                  || arr[index] == '.')) {
                *p = 0;
                printf("%s", arr);
                printGaps(index);
                printf("^\n" RED("ERROR") " in line %d: expected number\n\n",
                       line);
                index = 0;
                return;
            }
        }
        index++;
    }
    index++;
    int tmp = index;
    // Check radius
    while (arr[index] != ')') {
        if (arr[index] != ' ') {
            if (arr[index] == '(') {
                *p = 0;
                printf("%s", arr);
                printGaps(index);
                printf("^\n" RED("ERROR") " in line %d: expected ')'\n\n",
                       line);
                index = tmp;
                return;
            }
            if (!(((arr[index] >= '0') && (arr[index] <= '9'))
                  || arr[index] == '.')) {
                *p = 0;
                printf("%s", arr);
                printGaps(index);
                printf("^\n" RED("ERROR") " in line %d: expected number\n\n",
                       line);
                index = tmp;
                return;
            }
        }
        index++;
    }
    index++;
    while (arr[index] != '\n') {
        if (arr[index] != ' ') {
            *p = 0;
            printf("%s", arr);
            printGaps(index);
            printf("^\n" RED("ERROR") " in line %d: unexpected token\n\n",
                   line);
            return;
        }
        index++;
    }
}
