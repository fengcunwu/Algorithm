//动态规划---优化编辑器问题
/*
本题删除，替换，插入代价全是 1
*/

#include "DynamicPlanning.h"

using namespace std;

int calStringDistance(string A, string B)
{
	int row = A.size();//字符串A的长度
	int col = B.size();//字符串B的长度
	int **dp = new int*[row + 1];//动态创建一个二维数组
	for (int i = 0; i<row + 1; i++)
	{
		dp[i] = new int[col + 1]();
	}
	dp[0][0] = 0;//这里代价是0，也就是空字符到空字符，不需要任何编辑
	for (int i = 1; i<row + 1; i++)//这里是A的i个字符到B空字符需要i个删除代价
	{
		dp[i][0] = i;
	}
	for (int j = 1; j<col + 1; j++)//这里是A从空字符到B的j个字符共需要j个插入代价
	{
		dp[0][j] = j;
	}
	for (int i = 1; i<row + 1; i++)
	{
		for (int j = 1; j<col + 1; j++)
		{
			if (A[i - 1] == B[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1];//如果i和j位置字符相同，说明i和j位置的字符不需要编辑。dp[i][j]=dp[i-1][j-1]
			}
			else
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;//这里需要一个替换代价
			}
			dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j]);
			dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
		}
	}
	return dp[row][col];
}