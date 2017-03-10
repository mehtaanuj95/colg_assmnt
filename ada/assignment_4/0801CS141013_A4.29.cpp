#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cout<<"Enter number of persons"<<endl;
	cin>>n;
	int person[n];
	set<int> a,b;
	set<int>::iterator it;
	set<int>::reverse_iterator rit;
	cout<<"Enter person's crossing time"<<endl;
	for(int i = 0; i <n;i++)
	{
		cin>>person[i];
		a.insert(person[i]);
	}
	/*for(int i = 0;i<n;i++)
		cout<<person[i]<<"  ";
	cout<<endl;
	for(it=a.begin(); it!=a.end();it++)
		cout<<*it<<"  ";*/
	if(n == 1)
	{
		cout<<"the minimum time required for a single person to cross the bridge is "<<person[0]<<endl;
		exit(0);
	}
	int first,second;
	int revfirst,revsecond;
	int back;
	while(!a.empty())
	{
		//1st step
		it=a.begin();
		first=*it; second=*(++it);
		cout<<"step ---> "<<first<<" "<<second<<endl;
		b.insert(first); b.insert(second);
		a.erase(first); a.erase(second);
		if(a.empty())
			exit(0);
		it=b.begin();
		back = *it;
		b.erase(back);
		a.insert(back);
		cout<<"step  <--- "<<back<<endl;
		//2nd step
		if(a.empty())
			exit(0);
		rit=a.rbegin();
		revfirst=*rit; revsecond=*(++rit);
		cout<<"step ---> "<<revfirst<<" "<<revsecond<<endl;
		b.insert(revfirst); b.insert(revsecond);
		a.erase(revfirst); a.erase(revsecond);
		if(a.empty())
			exit(0);
		it=b.begin();
		back = *it;
		b.erase(back);
		a.insert(back);
		cout<<"step  <--- "<<back<<endl;
	}
	return 0;
}
