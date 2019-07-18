//��̬�滮---�Ż��༭������
/*
����ɾ�����滻���������ȫ�� 1
*/

#include "DynamicPlanning.h"

using namespace std;

int calStringDistance(string A, string B)
{
	int row = A.size();//�ַ���A�ĳ���
	int col = B.size();//�ַ���B�ĳ���
	int **dp = new int*[row + 1];//��̬����һ����ά����
	for (int i = 0; i<row + 1; i++)
	{
		dp[i] = new int[col + 1]();
	}
	dp[0][0] = 0;//���������0��Ҳ���ǿ��ַ������ַ�������Ҫ�κα༭
	for (int i = 1; i<row + 1; i++)//������A��i���ַ���B���ַ���Ҫi��ɾ������
	{
		dp[i][0] = i;
	}
	for (int j = 1; j<col + 1; j++)//������A�ӿ��ַ���B��j���ַ�����Ҫj���������
	{
		dp[0][j] = j;
	}
	for (int i = 1; i<row + 1; i++)
	{
		for (int j = 1; j<col + 1; j++)
		{
			if (A[i - 1] == B[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1];//���i��jλ���ַ���ͬ��˵��i��jλ�õ��ַ�����Ҫ�༭��dp[i][j]=dp[i-1][j-1]
			}
			else
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;//������Ҫһ���滻����
			}
			dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j]);
			dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
		}
	}
	return dp[row][col];
}