#include "DynamicPlanning.h"

//小明同学要参加一场考试，考试一共有n道题目，小明必须做对至少60%的题目才能通过考试。
//考试结束后，小明估算出每题做对的概率，p1,p2,...,pn。你能帮他算出他通过考试的概率吗？

/*
动态规划问题：
i表示有i道题，j表示i道题中答对的数量(0,1,2,3...i)
f[i][j]：i道题中对答了j道题的概率；
j = 0：		f[i][j] = f[i-1][j]*(1-p[i])；前面已经有0道题答对；
j !=0 && j !=i：f[i][j] = f[i-1][j-1]*p[i]+f[i-1][j]*(1-p[i])；
	前面已经有j-1道题答对，第i道题答对  +  前面已经有j道题答对，第i道题答错；
j =i：	f[i][j] = f[i-1][j-1]*p[i]；前面已经有j-1道题答对，第i道题答对；
*/

void RetRight()
{
	int n;
	std::cin >> n;
	double *p = new double[n];
	//输入题目做对的概率
	int index = 0;
	while (std::cin >> p[index])
	{
		p[index] = p[index] / 100.0;
		index++;
		if (std::cin.peek() == ' ')
		{
			std::cin.get();
		}
		if (std::cin.peek() == '\n')
		{
			break;
		}
	}
	//创建二维动态数组；
	double **f = new double*[n + 1];
	for (int i = 0; i <= n; i++)
	{
		f[i] = new double[n + 1];
	}

	//第一道题；
	f[0][0] = 1.0;
	f[0][1] = 0;
	//通过递推公式求解；
	for (int i = 1; i <= n; i++)
	{
		f[i][0] = f[i - 1][0] * (1.0 - p[i - 1]);//i道题都答错；
		for (int j = 1; j <= i; j++)
		{
			if (j == i)//i道题都答对；
			{
				f[i][j] = f[i - 1][j - 1] * p[i - 1];
			}
			else//i道题有j道题到对；
			{
				f[i][j] = f[i - 1][j - 1] * p[i - 1] + f[i - 1][j] * (1.0 - p[i - 1]);
			}

		}
	}
	//至少60%的题目才能通过考试，至少需要答对的题数；
	int FinNum = int(std::ceil(n*0.6));
	double pSum = 0.0;
	for (int i = FinNum; i <= n; i++)
	{
		pSum = pSum + f[n][i];//大于等于FinNum的都是通过考试的情况；
	}

	std::cout << std::fixed << std::setprecision(5) << pSum << "\n";
}