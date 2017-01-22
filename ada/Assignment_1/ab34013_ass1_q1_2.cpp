/*
@author : Anuj Bhai Mehta
Description : Generates n unique random numbers.
Date: Saturday, 21 January 2017
Usage: g++ ass1_q1_2.cpp -std=c++11
*/

#include <iostream>
#include <random>
#include <set>

using namespace std;

int main()
{
	//Constant for mersenne_twister_engine.
	//Seeding above engine with random seed (1729...!! Its Ramanujan Number)	
	mt19937 mt(1729);
	int range,n;
	cin>>range>>n;
	set<int> myset;
  	set<int>::iterator it;
  	//Code to generate uniform Integer Distribution.
	uniform_int_distribution<int> dist(0,range);
	
	for(int i=0; i<n;++i)
	{
		//int r = dist(mt);
		//cout<<r<<"  ";
		myset.insert(dist(mt));
	}
	cout<<endl<<"Unique Random numbers are"<<endl;
	for(it=myset.begin(); it!= myset.end(); it++)
	{
		cout<<*it<<"  ";
	}
	cout<<endl;

}
