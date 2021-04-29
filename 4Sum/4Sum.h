#ifndef _4_SUM_H
#define _4_SUM_H

#include "../Entrance.h"
#include <vector>
using namespace std;
/// <summary>
/// 给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，
/// 使得 a + b + c + d 的值与 target 相等？找出所有满足条件且不重复的四元组。
/// 注意：答案中不可以包含重复的四元组。
/// 输入：nums = [1,0,-1,0,-2,2], target = 0
/// 输出： [[-2, -1, 1, 2], [-2, 0, 0, 2], [-1, 0, 0, 1]]
/// </summary>
class _4Sum : public Entrance
{
public:
	_4Sum();
	~_4Sum();

	virtual void Impl();

private:
	vector<vector<int>> FourSum(vector<int> &nums, int target);
};


#endif
