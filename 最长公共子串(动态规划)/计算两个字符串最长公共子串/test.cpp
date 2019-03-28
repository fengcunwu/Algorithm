#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;

int main()
{
	string firstStr;
	string secondStr;
	while (cin >> firstStr >> secondStr)
	{
		int len1 = firstStr.size();
		int len2 = secondStr.size();
		int maxlength = 0;
		vector<vector<int>>  arr(len1 + 1, vector<int>(len2 + 1, 0));//初始化二维数组，
		for (int i = 1; i <= len1; i++)
		{
			for (int j = 1; j <= len2; j++)
			{
				if (firstStr[i - 1] == secondStr[j - 1])
				{
					arr[i][j] = arr[i - 1][j - 1] + 1;
					maxlength = (maxlength > arr[i][j] ? maxlength : arr[i][j]);
				}
			}
		}
		cout << maxlength << endl;
	}
	system("pause");
	return 0;
}