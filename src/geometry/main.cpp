#include <cmath>
#include <cstring>
#include <libgeometry/lexer.cpp>
#include <libgeometry/parser.cpp>
#include <libgeometry/colors.h>
#include <stdio.h>
#include <string>

#define N 50
#define PI 3.14

using namespace std;

int main()
{
    FILE* geom;
    char arr[N];
    int line = 1;
    int status = 1;
    geom = fopen("geom.txt", "r");
    if (geom == NULL) {
        printf(RED("ERROR!") " Expected geom.txt\n");
        return 1;
    }
    while (fgets(arr, N, geom) != NULL) {
        ErCheck(arr, line, &status);
        line++;
    }

    fclose(geom);
    if (status == 0)
        return 1;

    circle cmas[line];

    geom = fopen("geom.txt", "r");
    int i = 0;
    while (fgets(arr, N, geom) != NULL) {
        Get_Info(arr, cmas[i].x, cmas[i].y, cmas[i].r);
        i++;
    }

    fclose(geom);

    // geom = fopen("geom.txt", "r");
    // int count = 1;
    // while (fgets(arr, N, geom) != NULL) {
    //     for (int i = 0; i < line; i++)
    //     {
    //         for (int j = 0; j < n; j++)
    //         {
    //             double l = sqrt(pow(cmas[j].x) - cmas[i].x, 2) + pow(cmas[j].y - cmas[i].y, 2);
    //         }
    //     }
    // }

    return 0;
}