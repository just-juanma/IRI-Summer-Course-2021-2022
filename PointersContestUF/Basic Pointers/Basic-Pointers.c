#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PI 3.14159265359

int perimeter(int lengthCount, int* lengths) {
    if (lengthCount == 1) return 2 * PI * lengths[0];
    else if (lengthCount == 3) return lengths[0] + lengths[1] + lengths[2];
    else return (lengths[0] * 2) + (lengths[1] * 2);
}

int area(int lengthCount, int* lengths) {
    if (lengthCount == 1) return PI * pow(lengths[0], 2);
    else if (lengthCount == 3) return (lengths[0] * lengths[1]) / 2;
    else return lengths[0] * lengths[1];
}

char* typeFigure(int lengthCount, int* lengths) {
    if (lengthCount == 1) return "Square";
    else if (lengthCount == 3) return "Triangle Rectangle";
    else {
        if (lengths[0] == lengths[1]) return "Square";
        else return "Rectangle";
    }

}

void traversingArray(int lengthCount, int* lengths) {
    int area = 0, perimeter = 0;
    char* figure = typeFigure(lengthCount, lengths);
    area = area(lengthCount, lengths);
    perimetro = perimeter(lengthCount, lengths);
    printf("%s\nArea [%d]\nPerimeter [%d]", figure, area, perimeter);
    return;
}

int main()
{
 
    // traversingArray(lados, LongitudLados); no main

    return 0;
}