/*
运行之后按照提示输入即可
*/

#include<iostream>
using namespace std;

int main()
{
	int n;
	cout << "size：" << endl;
	cin >> n;
	cout << "nums：" << endl;
	int* a = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int sum = 0;
	int max = 0;
	for (int i = 0; i < n; i++)
	{
		sum += a[i];
		if (sum > max)
		{
			max = sum;
		}
		else if (sum < 0)
		{
			sum = 0;
		}
	}
	cout << "max sum is " << max << endl;
	delete[] a;
	return 0;
}