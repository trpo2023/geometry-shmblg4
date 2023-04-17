#include <cmath>
#include <libgeometry/parser.h>
#include <string>

void Get_Info(std::string temp, float* x, float* y, float* r)
{
    int tmp = 7;

    while (temp[tmp] == ' ')
        tmp++;

    int flag = 0;

    if (temp[tmp] == '-') {
        flag = 1;
        tmp++;
    }

    while (temp[tmp] >= '0' && temp[tmp] <= '9') {
        *x = *x * 10 + (temp[tmp] - '0');
        tmp++;
    }

    if (temp[tmp] == '.') {
        tmp++;
        int z = -1;
        while (temp[tmp] >= '0' && temp[tmp] <= '9') {
            *x = *x + (temp[tmp] - '0') * pow(10, z);
            tmp++;
        }
    }

    if (flag == 1)
        *x *= -1;

    while (temp[tmp] == ' ')
        tmp++;

    flag = 0;

    if (temp[tmp] == '-') {
        flag = 1;
        tmp++;
    }

    while (temp[tmp] >= '0' && temp[tmp] <= '9') {
        *y = *y * 10 + (temp[tmp] - '0');
        tmp++;
    }

    if (temp[tmp] == '.') {
        tmp++;
        int z = -1;
        while (temp[tmp] >= '0' && temp[tmp] <= '9') {
            *y = *y + (temp[tmp] - '0') * pow(10, z);
            tmp++;
        }
    }

    if (flag == 1)
        *y *= -1;

    while (temp[tmp] == ',')
        tmp++;

    while (temp[tmp] == ' ')
        tmp++;

    while (temp[tmp] >= '0' && temp[tmp] <= '9') {
        *r = *r * 10 + (temp[tmp] - '0');
        tmp++;
    }

    if (temp[tmp] == '.') {
        tmp++;
        int z = -1;
        while (temp[tmp] >= '0' && temp[tmp] <= '9') {
            *r = *r + (temp[tmp] - '0') * pow(10, z);
            tmp++;
        }
    }
}