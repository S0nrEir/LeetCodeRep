#include "ContainerWithMostWater.h"
#include <iostream>
#include <string>
#include <vector>
#include <math.h>


using namespace std;

ContainerWithMostWater::ContainerWithMostWater()
{
	cout << "ContainerWithMostWater constructed" << endl;
}

ContainerWithMostWater::~ContainerWithMostWater()
{
	cout << "ContainerWithMostWater destructed" << endl;
}

void ContainerWithMostWater::Impl()
{
	vector<int> heightList;

	//test case:
	heightList.push_back(1);
	heightList.push_back(8);
	heightList.push_back(6);
	heightList.push_back(2);
	heightList.push_back(5);
	heightList.push_back(4);
	heightList.push_back(8);
	heightList.push_back(3);
	heightList.push_back(7);
	heightList.push_back(1);

	//test case:
	//heightList.push_back(4);
	//heightList.push_back(3);
	//heightList.push_back(2);
	//heightList.push_back(1);
	//heightList.push_back(4);

	cout << "result:" << max_area(heightList) << endl;
}

int ContainerWithMostWater::max_area(vector<int>& height)
{
	auto l = 0;
	auto r = height.size() - 1;
	int ans = 0;
	while (l < r) 
	{
		int area = min(height[l], height[r]) * (r - l);
		ans = max(ans, area);

		if (height[l] <= height[r])
			++l;
		else
			--r;
	}
	return ans;
}