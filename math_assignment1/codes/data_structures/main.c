#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "lib.h"

int main()
{
    Node* a = loadtxt("a.dat"); // Load the point A from the text file into a linked list
    Node* e1 = loadtxt("e1.dat"); // Load e1(1,0) from the .dat file into a linked list

    Node* q1 = loadtxt("q1.dat"); 
    Node* p1 = loadtxt("p1.dat");

    int i = 8;
    int j = 9;
    double theta = radians(60); 

    int m = 2, n = 1;

    
    Node* b = mat_val(e1, j); 

  
    //  results
    
    print(b);
    save("b1.dat", b1, m, n);
     return 0;
}

