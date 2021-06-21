#include "CombinationSum.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

CombinationSum::CombinationSum()
{
	cout << "CombinationSum constructed" << endl;
}

CombinationSum::~CombinationSum()
{
	cout << "CombinationSum destructed" << endl;
}

void CombinationSum::Impl()
{
	vector<int> candidates;
	candidates.push_back(2);
	candidates.push_back(3);
	candidates.push_back(6);
	candidates.push_back(7);

	vector<vector<int>> res = combination_sum(candidates, 7);
	for (vector<int> lst : res)
	{
		for (int num : lst)
			cout << num << ",";

		cout << endl;
	}
}

vector<vector<int>> CombinationSum::combination_sum(vector<int>& candidates, int target)
{
	vector<vector<int>> res;
	auto size = candidates.size();
	if (size == 0)
		return res;

	//target等于唯一元素
	if (size == 1)
	{
		if (candidates[0] == target)
		{
			vector<int> vec;
			vec.push_back(candidates[0]);
			res.push_back(vec);
			return res;
		}
		else
			return res;
	}
	vector<int> temp;
	sort(candidates.begin(), candidates.end());
	dfs(0, target, candidates, temp ,res);
	return res;
}

void CombinationSum::dfs(int index, int target, vector<int> &candidates, vector<int> &temp, vector<vector<int>> &res)
{
	if (target == 0)
	{
		res.emplace_back(temp);
		return;
	}

	auto size = candidates.size();
	for (int i = index; i < size; i++)
	{
		auto curr = candidates[i];

		//if (curr == 7)
		//	cout << "break" << endl;

		if (curr <= target)
		{
			temp.emplace_back(curr);
			dfs(i, target - curr, candidates, temp, res);
			//如果在上一步return掉了（成功了），那么这里temp就是空的，那么他必定会插入一个错误的值
			temp.pop_back();
		}
	}
}