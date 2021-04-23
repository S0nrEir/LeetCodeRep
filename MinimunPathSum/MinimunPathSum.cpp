#include "MinimunPathSum.h"
#include <iostream>
#include <vector>
#include <stdio.h>
#include <limits.h>
#include <algorithm>
#include <math.h>
using namespace std;

MinimunPathSum::MinimunPathSum()
{
	std::cout << "MinimunPathSum constructed\n";
}

MinimunPathSum::~MinimunPathSum()
{
	std::cout << "MinimunPathSum Destructed\n";
}

/// <summary>
/// 实现
/// </summary>
void MinimunPathSum ::Impl()
{
	vector<vector<int>> grid;
	grid.push_back(vector<int>{ 1, 3, 1 });
	grid.push_back(vector<int>{ 1, 5, 1 });
	grid.push_back(vector<int>{ 4, 2, 1 });

	//每一点保存了从起点到当前点所需的最小移动代价
	//{ 1, 4, 5 },
	//{ 2, 7, 6 },
	//{ 6, 8, 7 },
	cout << "path sum : " << GetPathSum(grid) << "\n";
}

/// <summary>
/// 获取路径和
/// </summary>
int MinimunPathSum::GetPathSum(vector<vector<int>>& grid)
{
	auto m = grid.size();
	auto n = grid[0].size();
	auto dp = vector<vector<int>>(m, vector<int>(n));
	for (int i = 0; i < m; i++)
	{
		for (int j = 0 ; j< n;j++)
		{
			if (i == 0 && j == 0)
				dp[i][j] = grid[i][j];
			else
			{
				auto top = i - 1 >= 0 ? dp[i - 1][j] + grid[i][j] : INTMAX_MAX;
				auto left = j - 1 >= 0 ? dp[i][j - 1] + grid[i][j] : INTMAX_MAX;
				dp[i][j] = min(top, left);
			}
		}
	}
	auto temp = dp[m - 1][n - 1];
	return dp[m - 1][n - 1];
}

