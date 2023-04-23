// CDA 3103,  David/Remi Roper
// torosdagli

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


void readMemCache(FILE *trace);
void directMap(char** Cache);
void twoWayMap(char** Cache);
void fourWayMap(char** Cache);
void fullAssociative(char** Cache);

int main()
{
    FILE *trace;

    printf("---------<[Start of Program]>------\n");
    readMemCache(trace);
    printf("---------<[End of Program]>------\n");
    return 0;
}

void readMemCache(FILE *trace)
{
    char** c;
    int i = 0;
    int size = 10000;

    c = malloc(sizeof(char*) * (size+1));


    trace = fopen("traces.txt", "r");

    while( i < size)
    {
        c[i] = malloc(sizeof(char) * (15  + 1));
        fscanf(trace, "%s",  c[i]);
        i++;
    }

    // directMap
    printf("Direct Map: \n");
    directMap(c);
    // twoWayMap
    printf("Two way map: \n");
    twoWayMap(c);
    // fourWayMap
    printf("Four way map: \n");
    fourWayMap(c);
    // fully Associative
    printf("fully Associative map: \n");
    fullAssociative(c);


    fclose(trace);
}

void directMap(char** Cache)
{
    int hit = 0;
    int miss = 0;
    int size = 10000;
    int shuffle = 0;
    int  i = 0;
    int j = 0;
    int found = 0;
    char** map;

    while (i < size)
    {
        i++;
    }

    printf("In a direct Map %d misses and %d hits\n",  miss, hit );
    printf("\n");
}

void twoWayMap(char** Cache)
{
  int hit = 0;
  int miss = 0;
  int size = 10000;
  int shuffle = 0;
  int  i = 0;
  int j = 0;
  int found = 0;
  char** map;

  map = malloc(sizeof(char*) * (2 + 1));

  map[0] = malloc(sizeof(char) * (15+1));
  map[1] = malloc(sizeof(char) * (15+1));

  while (i < size)
  {
      if (shuffle == 0)
      {
          strcpy(map[shuffle], Cache[i]);
          shuffle++;
          miss++;
          i++;
          continue;
      }

      for (j = 0; j < 2; j++)
      {
          if (strcmp(map[j], Cache[i]) == 0)
          {
              hit++;
              found = 1;
              shuffle++;
              if (shuffle == 2)
              {
                  shuffle = 0;
              }
              j = 3;
          }
      }

      if (found == 0)
      {
        shuffle++;
        if (shuffle == 2)
        {
            shuffle = 0;
        }
        strcpy(map[shuffle], Cache[i]);
        miss++;
      }

      found = 0;

      i++;
  }

    printf("In a two-Way Map %d misses and %d hits\n",  miss, hit );
    printf("\n");
}

void fourWayMap(char** Cache)
{
  int hit = 0;
  int miss = 0;
  int size = 10000;
  int shuffle = 0;
  int  i = 0;
  int j = 0;
  int found = 0;
  char** map;

  map = malloc(sizeof(char*) * (4 + 1));

  map[0] = malloc(sizeof(char) * (15+1));
  map[1] = malloc(sizeof(char) * (15+1));
  map[2] = malloc(sizeof(char) * (15+1));
  map[3] = malloc(sizeof(char) * (15+1));

  while (i < size)
  {
      if (shuffle == 0)
      {
          strcpy(map[shuffle], Cache[i]);
          shuffle++;
          miss++;
          i++;
          continue;
      }

      for (j = 0; j < 4; j++)
      {
          if (strcmp(map[j], Cache[i]) == 0)
          {
              hit++;
              found = 1;
              shuffle++;
              if (shuffle == 4)
              {
                  shuffle = 0;
              }
              j = 5;
          }
      }

      if (found == 0)
      {
        shuffle++;
        if (shuffle == 4)
        {
            shuffle = 0;
        }
        strcpy(map[shuffle], Cache[i]);
        miss++;
      }

      found = 0;

      i++;
  }

    printf("In a four-Way Map %d misses and %d hits\n",  miss, hit );
    printf("\n");
}

void fullAssociative(char** Cache)
{
  int hit = 0;
  int miss = 0;
  int size = 10000;
  int shuffle = 0;
  int  i = 0;
  int j = 0;
  int found = 0;
  char** map;

  map = malloc(sizeof(char*) * (size + 1));

  while (i < size)
  {
      if (shuffle == 0)
      {
          map[shuffle] = malloc(sizeof(char) * (15+1));
          strcpy(map[shuffle], Cache[i]);
          shuffle++;
          miss++;
          i++;
          continue;
      }

      for (j = 0; j < shuffle; j++)
      {
          if (strcmp(map[j], Cache[i]) == 0)
          {
              hit++;
              j = shuffle + 1;
              found = 1;
          }

      }

      if (found == 0)
      {
        shuffle++;
        map[shuffle-1] = malloc(sizeof(char) * (15+1));
        strcpy(map[shuffle-1], Cache[i]);
        miss++;
      }

      found = 0;
      i++;
  }

  printf("In a fully Associative Map %d misses and %d hits\n",  miss, hit );
  printf("\n");
}
