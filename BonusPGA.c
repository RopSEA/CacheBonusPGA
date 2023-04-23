// CDA 3103,  David/Remi Roper
// torosdagli

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


void readMemCache(FILE *trace);
double directMap(char** Cache);
double twoWayMap(char** Cache);
double fourWayMap(char** Cache);
double fullAssociative(char** Cache);
double compare(double one, double two, double three, double four);

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
    double dr = 0;
    double tw = 0;
    double frw = 0;
    double fa = 0;

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
    dr = directMap(c);
    // twoWayMap
    printf("Two way map: \n");
    tw = twoWayMap(c);
    // fourWayMap
    printf("Four way map: \n");
    frw = fourWayMap(c);
    // fully Associative
    printf("fully Associative map: \n");
    fa = fullAssociative(c);

    compare(dr, tw, frw, fa);


    fclose(trace);
}

double compare(double one, double two, double three, double four)
{
    if ( one >= two && one >= three)
    {
        if (one >= four)
        {
           printf("direct map was the one that got the best hit rate\n");
           return one;
        }
    }

    if ( two >= three && two >= one)
    {
        if (two >= four)
        {
           printf("two way map was the one that got the best hit rate\n");
           return two;
        }
    }

    if ( three >= one && three >= two)
    {
        if (three >= four)
        {
           printf("four way map was the one that got the best hit rate\n");
           return three;
        }
    }
    printf("fully Associative map was the one that got the best hit rate\n");
    return four;
}

double directMap(char** Cache)
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

    while (i < size)
    {
        if (shuffle == 0)
        {
            strcpy(map[0], Cache[i]);
            miss++;
            i++;
            continue;
        }

        if (strcmp(map[0], Cache[i]) == 0)
        {
            hit++;
            found = 1;
            j = 3;
        }

        if (found == 0)
        {
          strcpy(map[0], Cache[i]);
          miss++;
        }

        found = 0;
        i++;
    }

    printf("In a direct Map there are %d misses and %d hits\n",  miss, hit );
    printf("\n");

    return hit / miss;
}

double twoWayMap(char** Cache)
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

    printf("In a two-Way Map there are %d misses and %d hits\n",  miss, hit );
    printf("\n");
    return hit / miss;
}

double fourWayMap(char** Cache)
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

    printf("In a four-Way Map there are %d misses and %d hits\n",  miss, hit );
    printf("\n");

    return hit / miss;
}

double fullAssociative(char** Cache)
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

  printf("In a fully Associative Map there are %d misses and %d hits\n",  miss, hit );
  printf("\n");

  return hit / miss;
}
