void printArray(int a[], int length)
{
	for(int i = 0; i < length; i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;

}
int main(int argc, char* argv[])
{

	int n;

	if(argc == 1)
	{
		cout<<"Usage: ./a.out {n / test} {case}"<<endl;
		return 0;
	}
	if(strcmp(argv[1], "test") == 0)
	{
		cout<<"\nActivating Test Mode\n"<<endl;

		clock_t t;

		t = clock();
		fibonacci(5);
		t = clock() - t;
		cout<<"Test Case 1__Size : 5__Time (in ticks) : "<<t<<endl<<endl;

		t = clock();
		fibonacci(15);
		t = clock() - t;
		cout<<"Test Case 1__Size : 5__Time (in ticks) : "<<t<<endl<<endl;

		t = clock();
		fibonacci(25);
		t = clock() - t;
		cout<<"Test Case 1__Size : 5__Time (in ticks) : "<<t<<endl<<endl;

		t = clock();
		fibonacci(35);
		t = clock() - t;
		cout<<"Test Case 1__Size : 5__Time (in ticks) : "<<t<<endl<<endl;

		t = clock();
		fibonacci(50);
		t = clock() - t;
		cout<<"Test Case 1__Size : 5__Time (in ticks) : "<<t<<endl<<endl;

	}
	else
	{
		n = atoi(argv[1]);
		if(argc == 2)
		{
			fibonacci(n);
		}
	}
}