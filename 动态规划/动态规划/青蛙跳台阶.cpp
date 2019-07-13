#include "DynamicPlanning.h"

//青蛙跳台阶问题----递归思想
//时间复杂度O(2^n),空间复杂度也很大
int Jump_01(int num)
{
	if (num <= 0)
		return 0;
	if (num == 1)
		return 1;
	return 2 * Jump_01(num - 1);
}

//青蛙跳台阶问题----动态规划
//时间复杂度O(n)空间复杂度O（1）
int jumpFloorII(int number) 
{
	if (number <= 0)
		return 0;
	int total = 1;
	for (int i = 1; i < number; i++)
		total *= 2;
	return total;
}

//青蛙跳台阶问题---排列算法
int Jump_03(int number)
{
	if (number <= 0)
		return 0;
	int result = 1 << (number - 1);
	return result;
}