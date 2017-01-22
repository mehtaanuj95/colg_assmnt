/*
@author : Anuj Bhai Mehta
Description : Finds x^n using newton raphson method
Date: Saturday, 21 January 2017
Usage: g++ ass1_q4_3.cpp -lm

note: decimalconversion.h
Ref: http://rosettacode.org/wiki/Convert_decimal_number_to_rational
*/


#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>
#include "decimalconversion.h"

using namespace std;
double p;

float f2 (float x, int d, int n)
{
    return pow(x,d) - pow(p,n);
}
float df (float x, int d)
{
    return d*pow(x, d-1);
}
int main()
{

    int z;
    int64_t d, n;
    double f1;
    //double p;
    cout<<"Enter x and n"<<endl;
    cin>>p>>f1;
    for (z = 1; z <= 20; z *= 16) 
    {
        rat_approx(f1, z, &n, &d);
    }

    int itr, maxmitr;
    float h, x0, x1, allerr;
    
    x0 = 1;
    allerr = 0.005;
    maxmitr = 2000;
    for (itr=1; itr<=maxmitr; itr++)
    {
        h=f2(x0, d, n)/df(x0, d);
        x1=x0-h;
        //printf(" At Iteration no. %3d, x = %9.6f\n", itr, x1);
        if (fabs(h) < allerr)
        {
            printf("After %3d iterations, root = %8.6f\n", itr, x1);
            return 0;
        }
        x0=x1;
    }
    printf("Not able to calculate...Sorry\n");
    return 0;
}