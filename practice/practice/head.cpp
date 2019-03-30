#include "head.h"

using namespace std;

//��̬�滮�����ս�������������Ϸ��ߵ���������·����ó�·��֮�͵����ֵ

int getMost(vector<vector<int>> & board)
{
	// write code here
	int row = board.size();
	int col = board[0].size();
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (i == 0 && j == 0)
				continue;
			else if (i == 0)
				board[i][j] += board[i][j - 1];
			else if (j == 0)
				board[i][j] += board[i - 1][j];
			else
			{
				board[i][j] += max(board[i - 1][j], board[i][j - 1]);
			}
		}
	}
	return board[row - 1][col - 1];
}