#ifndef COMBINATION_SUM_H
#define COMBINATION_SUM_H

#include "../Entrance.h"
#include <vector>

using namespace std;
//#note
/// <summary>
/// 给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
/// candidates 中的数字可以无限制重复被选取。
///说明：
///所有数字（包括target）都是正整数。
///解集不能包含重复的组合。 
/// 示例：
/// 输入candidates = [2,3,.6,7] target = 7 , 所求解集为：[[7],[2,2,3]]。
/// </summary>
class CombinationSum : public Entrance
{
public:
	 CombinationSum();
	~ CombinationSum();

	virtual void Impl();

private:
	vector<vector<int>> combination_sum(vector<int>& candidates, int target);
	void dfs(int index, int target, vector<int>& candidates, vector<int>& temp, vector<vector<int>>& res);
};

#endif
