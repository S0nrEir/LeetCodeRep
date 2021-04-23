#ifndef MINIMUN_PATH_SUM_H
#define  MINIMUN_PATH_SUM_H
#include "../Entrance.h"
#include <vector>

//给定一个包含非负整数的 m x n 网格 grid ，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
//说明：每次只能向下或者向右移动一步。
//      输入：grid = 
		//[1,3,1]
		//[1,5,1],
		//[4,2,1]
//      输出：7
//      解释：因为路径 1→3→1→1→1 的总和最小。
class MinimunPathSum : public Entrance
{
public:
	MinimunPathSum();
	~MinimunPathSum();
	virtual void Impl();

private:
	int GetPathSum(std::vector<std::vector<int>>& grid);
};

#endif