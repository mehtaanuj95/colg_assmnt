/*
@author : Anuj Bhai Mehta
Description : Generates n unique random numbers.
Date: Tuesday, 10 January 2017
Usage: g++ ass1_q1_1.cpp
*/
#include <time.h>
#include <string.h>
#include <iostream>

using namespace std;

const unsigned int prime = 4294967291u;
unsigned int halfprime;
unsigned int m_index;
unsigned int m_intermediateOffset;

int calculate_quadratic_residue(int x)
{
	
	// For numbers greater than prime, their one to one mapping will be with themselves.
	if (x >= prime)
		return x;

	int residue = ((long long) x * x) % prime;
	if(x <= halfprime)	
		return residue;
	else
		return prime - residue;
}

void seed(int seedBase, int seedOffset)
{
    m_index = calculate_quadratic_residue(calculate_quadratic_residue(seedBase) + 0x1f233144);
    m_intermediateOffset = calculate_quadratic_residue(calculate_quadratic_residue(seedOffset) + 0x1234f52a);
}

//Returns a unique random number
int generate()
{
    return calculate_quadratic_residue((calculate_quadratic_residue(m_index++) + m_intermediateOffset) ^ 0x4ba52c19);
}

int getUniqueRandomNumber()
{
    int r_seed = (int) time(NULL);
	seed(r_seed, r_seed + 1);
    int i = 0;
    int z;
    cin>>z;
    cout<<"Generating "<<z<<" Random numbers"<<endl;
	for(int i = 0; i < z; i++)
	{
		cout<<generate()<<endl;
	}
	return 0;
}

int main()
{
	halfprime = prime / 2;
	return getUniqueRandomNumber();
	return 1;
}