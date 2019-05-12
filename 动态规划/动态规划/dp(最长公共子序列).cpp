#include "DynamicPlanning.h"

//最长公共子序列
///
//  a  b  c  f  b  c
//a 1  1  1  1  1  1
//b 1  2  2  2  2  2
//f 1  2  2  3  3  3
//c 1  2  3  3  3  4 
//a 1  2  3  3  3  4
//b 1  2  3  4  4  4
size_t retMax_Length(string str1, string str2)
{
	int len1 = str1.size();
	int len2 = str2.size();
	vector<vector<int>> arr(len1 + 1, vector<int>(len2 + 1, 0));
	for (int i = 1; i <= len1; i++)
	{
		for (int j = 1; j <= len2; j++)
		{
			if (str1[i - 1] == str2[j - 1])
			{
				arr[i][j] = max(max(arr[i - 1][j], arr[i][j - 1]), arr[i - 1][j - 1] + 1);
			}
			else
				arr[i][j] = max(arr[i - 1][j], arr[i][j - 1]);
		}
	}
	return arr[len1][len2];
}