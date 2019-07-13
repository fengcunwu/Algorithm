#include "DynamicPlanning.h"

//������̨������----�ݹ�˼��
//ʱ�临�Ӷ�O(2^n),�ռ临�Ӷ�Ҳ�ܴ�
int Jump_01(int num)
{
	if (num <= 0)
		return 0;
	if (num == 1)
		return 1;
	return 2 * Jump_01(num - 1);
}

//������̨������----��̬�滮
//ʱ�临�Ӷ�O(n)�ռ临�Ӷ�O��1��
int jumpFloorII(int number) 
{
	if (number <= 0)
		return 0;
	int total = 1;
	for (int i = 1; i < number; i++)
		total *= 2;
	return total;
}

//������̨������---�����㷨
int Jump_03(int number)
{
	if (number <= 0)
		return 0;
	int result = 1 << (number - 1);
	return result;
}