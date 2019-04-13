#include "DynamicPlanning.h"

//С��ͬѧҪ�μ�һ�����ԣ�����һ����n����Ŀ��С��������������60%����Ŀ����ͨ�����ԡ�
//���Խ�����С�������ÿ�����Եĸ��ʣ�p1,p2,...,pn�����ܰ��������ͨ�����Եĸ�����

/*
��̬�滮���⣺
i��ʾ��i���⣬j��ʾi�����д�Ե�����(0,1,2,3...i)
f[i][j]��i�����жԴ���j����ĸ��ʣ�
j = 0��		f[i][j] = f[i-1][j]*(1-p[i])��ǰ���Ѿ���0�����ԣ�
j !=0 && j !=i��f[i][j] = f[i-1][j-1]*p[i]+f[i-1][j]*(1-p[i])��
	ǰ���Ѿ���j-1�����ԣ���i������  +  ǰ���Ѿ���j�����ԣ���i������
j =i��	f[i][j] = f[i-1][j-1]*p[i]��ǰ���Ѿ���j-1�����ԣ���i�����ԣ�
*/

void RetRight()
{
	int n;
	std::cin >> n;
	double *p = new double[n];
	//������Ŀ���Եĸ���
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
	//������ά��̬���飻
	double **f = new double*[n + 1];
	for (int i = 0; i <= n; i++)
	{
		f[i] = new double[n + 1];
	}

	//��һ���⣻
	f[0][0] = 1.0;
	f[0][1] = 0;
	//ͨ�����ƹ�ʽ��⣻
	for (int i = 1; i <= n; i++)
	{
		f[i][0] = f[i - 1][0] * (1.0 - p[i - 1]);//i���ⶼ���
		for (int j = 1; j <= i; j++)
		{
			if (j == i)//i���ⶼ��ԣ�
			{
				f[i][j] = f[i - 1][j - 1] * p[i - 1];
			}
			else//i������j���⵽�ԣ�
			{
				f[i][j] = f[i - 1][j - 1] * p[i - 1] + f[i - 1][j] * (1.0 - p[i - 1]);
			}

		}
	}
	//����60%����Ŀ����ͨ�����ԣ�������Ҫ��Ե�������
	int FinNum = int(std::ceil(n*0.6));
	double pSum = 0.0;
	for (int i = FinNum; i <= n; i++)
	{
		pSum = pSum + f[n][i];//���ڵ���FinNum�Ķ���ͨ�����Ե������
	}

	std::cout << std::fixed << std::setprecision(5) << pSum << "\n";
}