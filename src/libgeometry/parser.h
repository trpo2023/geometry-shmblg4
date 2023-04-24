#pragma once

#include <cmath>
#include <string>

typedef struct Circle {
    float x = 0;
    float y = 0;
    float r = 0;
} circle;

void Get_Info(std::string temp, float* x, float* y, float* r);
