/*
动态规划函数为maxVal；运行之后按照提示输入即可
*/

#include<iostream>
using namespace std;

int maxVal(int** val, int* v, int* w, int bagnum, int weight)
{
    for (int i = 0; i <= bagnum; i++)
        val[i][0] = 0;
    for (int i = 0; i <= weight; i++)
        val[0][i] = 0;

    for (int i = 1; i <= bagnum; i++)
    {
        for (int j = 1; j <= weight; j++)
        {
            if (j < w[i])
                val[i][j] = val[i - 1][j];
            else
                val[i][j] = max(val[i - 1][j], val[i - 1][j - w[i]] + v[i]);
        }
    }

    return val[bagnum][weight];

}

int main()
{
    int itemnum, weight;
    cout << "please input the number of items:" << endl;
    cin >> itemnum;
    cout << "please input the weight limit of the bag:" << endl;
    cin >> weight;

    int** vals = new int* [itemnum + 1];
    vals[0] = new int[(itemnum + 1) * (weight + 1)];
    for (int i = 1; i <= itemnum; i++)
        vals[i] = vals[i - 1] + weight + 1;

    cout << "please input the weight of every item:" << endl;
    int* w = new int[itemnum + 1]();
    for (int i = 1; i <= itemnum; i++)
        cin >> w[i];

    cout << "please input the value of every item:" << endl;
    int* v = new int[itemnum + 1]();
    for (int i = 1; i <= itemnum; i++)
        cin >> v[i];

    cout << "the max value is " << maxVal(vals, v, w, itemnum, weight) << "!" << endl;
    delete[] vals, w, v;
    return 0;
}