/*
动态规划函数为coinChange；运行之后按照提示输入即可
*/

#include<iostream>
using namespace std;

int coinChange(const int* coins, int amount, int numCoin)
{
	int* dp = new int[amount + 1];
	for (int i = 0; i < amount + 1; i++) dp[i] = -1;
	dp[0] = 0;
	for (int i = 1; i <= amount; i++)
	{
		for (int j = 0; j < numCoin; j++)
		{
			if (coins[j] <= i && dp[i - coins[j]] != -1)
			{
				if (dp[i] == -1 || dp[i] > dp[i - coins[j]] + 1)
					dp[i] = dp[i - coins[j]] + 1;
			}
		}
	}
	int temp = dp[amount];
	delete[] dp;
	return temp;
}

int main()
{
	int amount;
	cout << "please input the total amount:" << endl;
	cin >> amount;
	int coinNum;
	cout << "please input the number of types of coins:" << endl;
	cin >> coinNum;
	int* coins = new int[coinNum];
	cout << "please input the value of each coin:" << endl;
	for (int i = 0; i < coinNum; i++) cin >> coins[i];
	int temp = coinChange(coins, amount, coinNum);
	if (temp == -1)
	{
		cout << "cannot change!" << endl;
		delete[] coins;
		return 0;
	}
	cout << "the min num of coins is " << temp << endl;
	delete[] coins;
	return 0;
}