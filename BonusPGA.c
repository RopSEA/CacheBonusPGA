// CDA 3103,  David/Remi Roper
// torosdagli

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


void readMemCache(FILE *trace);
void directMap();
void twoWay();
void fourWay();


int main()
{
    FILE *trace;

    printf("Hello World\n");
    readMemCache(trace);
    return 0;
}

void readMemCache(FILE *trace)
{
    trace = fopen("traces.txt", "r");
    printf("hiii\n");

    fclose(trace);
}
