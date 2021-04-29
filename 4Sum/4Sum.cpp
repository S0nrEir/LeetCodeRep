#include "4Sum.h"
#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>

using namespace std;

_4Sum::_4Sum()
{
	cout << "_4Sum constructed" << endl;
}

_4Sum::~_4Sum()
{
	cout << "_4Sum destructed" << endl;
}

void _4Sum::Impl()
{
	vector<int> nums;
	//nums.push_back(1);
	//nums.push_back(0);
	//nums.push_back(-1);
	//nums.push_back(0);
	//nums.push_back(-2);
	//nums.push_back(2);

	//-3,-1,0,4
	nums.push_back(-3);
	nums.push_back(-1);
	nums.push_back(-0);
	nums.push_back(2);
	nums.push_back(4);
	nums.push_back(5);

	auto target = 0;

	vector<vector<int>> result = FourSum(nums, target);
	auto size = result.size();

	cout << "reuslt is :" << endl;

	for (int i = 0; i < size; i++)
	{
		vector<int> child = result[i];
		auto childSize = child.size();
		for (int j =0;j<childSize ;j++)
			cout << child[j] << " ";

		cout << endl;
	}
}
vector<vector<int>> _4Sum::FourSum(vector<int>& nums, int target)
{
	//与四重循环暴力穷举法相比，四个指针同时可以取到四个值，循环遍历数比暴力法少
	vector<vector<int>> result;
	auto size = nums.size();

	if (size < 4)
		return result;

	sort(nums.begin(), nums.end());

	for (int k = 0; k < size; k++)
	{
		if (k > 0 && nums[k] == nums[k - 1])
			continue;

		for (int i = k + 1; i < size; i++) 
		{
			if (i > k + 1 && nums[i] == nums[i - 1])
				continue;

			int left = i + 1;
			int right = size - 1;
			while (right > left) 
			{
				auto sum = nums[k] + nums[i] + nums[left] + nums[right];
				if (sum > target)
				{
					right--;
					continue;
				}

				if (sum < target) 
				{
					left++;
					continue;
				}

				if(sum == target)
				{
					result.push_back(vector<int>{nums[k], nums[i], nums[left], nums[right]});

					while (right > left && nums[right] == nums[right - 1]) 
						right--;

					while (right > left && nums[left] == nums[left + 1]) 
						left++;

					right--;
					left++;
				}
			}

		}
	}
	return result;

#pragma region old_code

	//auto size = nums.size();
	//vector<vector<int>> result;
	//
	//if (size < 4)
	//	return result;

	////先排个序
	//std::sort(nums.begin(), nums.end());

	//auto end = size - 1;

	//for (auto start = 0; start < size ; start++)
	//{
	//	auto left = start + 1;
	//	auto right = end - 1;
	//	while (left < right)
	//	{
	//		auto sum = nums[start] + nums[left] + nums[right] + nums[end];
	//		if (sum > target)
	//		{
	//			right--;
	//			continue;
	//		}

	//		if (sum < target)
	//		{
	//			left++;
	//			continue;
	//		}
	//		else
	//		{
	//			vector<int> temp;
	//			temp.push_back((nums[start]));
	//			temp.push_back((nums[left]));
	//			temp.push_back((nums[right]));
	//			temp.push_back((nums[end]));

	//			result.push_back(temp);
	//			left++;
	//			right--;
	//		}
	//	}
	//}
	//return result;
#pragma endregion
}