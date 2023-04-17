#include <cmath>
#include <cstring>
#include <fstream>
#include <libgeometry/colors.h>
#include <libgeometry/lexer.cpp>
#include <libgeometry/parser.cpp>
#include <stdio.h>
#include <string>

using namespace std;

int main()
{
    ifstream geom;
    std::string arr;
    int line = 1;
    int status = 1;
    geom.open("geom.txt");
    if (!geom.is_open()) {
        printf(RED("ERROR!") " Expected geom.txt\n");
        return 1;
    }
    while (!geom.eof()) {
        getline(geom, arr);
        ErCheck(arr, line, &status);
        line++;
    }

    geom.close();

    if (status == 0)
        return 1;

    circle cmas[line];

    geom.open("geom.txt");
    int k = 0;
    while (!geom.eof()) {
        getline(geom, arr);
        Get_Info(arr, &cmas[k].x, &cmas[k].y, &cmas[k].r);
        k++;
    }

    geom.close();

    geom.open("geom.txt");
    int i = 0;
    while (!geom.eof()) {
        getline(geom, arr);
        printf("Фигура: " YELLOW("%s") "\n", arr.c_str());
        double p = 2 * M_PI * cmas[i].r;
        double s = M_PI * pow(cmas[i].r, 2);
        printf("Периметр: %.2f\nПлощадь %.2f\n", p, s);
        for (int j = 0; j < line; j++) {
            if (i != j) {
                double dl
                        = sqrt(pow(cmas[j].x - cmas[i].x, 2)
                               + pow(cmas[j].y - cmas[i].y, 2));
                if (dl <= cmas[i].r + cmas[j].r)
                    printf("Пересекается с фигурой %d\n", j);
            }
        }
        printf("\n");
        i++;
    }
    return 0;
}