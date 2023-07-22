#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"lib.h"

int main()
{
    double **a, **b, **q, **p, **e1 ; // initializing the variables as matrices
     double theta = radians(30);
    int m = 2, n = 1;
    int i = 8, j = 9; // initializing assumptions 

    a = loadtxt("a.dat", 2, 1); // loading the point A from the text file
    e1 = loadtxt("e1.dat", 2, 1); // loading the e1(1,0) from the .dat file
    b = mult_int(j, e1, m, n);
    q = np_array(i * cos(theta), i * sin(theta));
    p = np_array(i * cos(theta), i * sin(-theta));


   return 0;
}

