#include "PlusTwoNumber.h"
#include <stdio.h>
#include <iostream>
#include <map>

using namespace std;

PlusTwoNumber::PlusTwoNumber()
{

}

PlusTwoNumber::~PlusTwoNumber()
{

}

void PlusTwoNumber::Impl()
{
	int arr[4]{ 2, 7, 11, 15 };
	auto target = 9;
	int* res = GetSum(arr , target);

	cout << "index of arr with target " << target << " is " << res[0] << " and " << res[1] << endl;
}

int* PlusTwoNumber::GetSum(int arr[], int target)
{
	int res[2]{ -1,-1 };
	int len = sizeof(arr);

	if (len < 2)
		return res;

	map<int, int> dic;
	for (int i = 0; i < len; i++)
	{
		int temp = target - arr[i];
		map<int, int>::iterator itor = dic.find(temp);

		if (itor == dic.end())
			dic.insert(map<int, int>::value_type(temp, i));

		/*if (!dic.at(temp))
			dic.insert(map<int, int>::value_type(temp,i));*/

		itor = dic.find(arr[i]);
		if (itor != dic.end())
		{
			res[0] = i;
			res[1] = dic.at(arr[i]);
		}
		/*if (dic.at(arr[i]))
		{
			res[0] = i;
			res[1] = dic[arr[i]];
		}*/
	}
	return res;
}