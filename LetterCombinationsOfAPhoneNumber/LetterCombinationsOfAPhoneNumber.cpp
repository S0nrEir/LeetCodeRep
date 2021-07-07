#include "LetterCombinationsOfAPhoneNumber.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

LetterCombinationsOfAPhoneNumber::LetterCombinationsOfAPhoneNumber()
{
	cout << "LetterCombinationsOfAPhoneNumber constructed" << endl;
	//_map = new std::map<char, string>();
	_map.insert(pair<char, string>('1',""));
	_map.insert(pair<char, string>('2', "abc"));
	_map.insert(pair<char, string>('3', "def"));
	_map.insert(pair<char, string>('4', "ghi"));
	_map.insert(pair<char, string>('5', "jkl"));
	_map.insert(pair<char, string>('6', "mno"));
	_map.insert(pair<char, string>('7', "pqrs"));
	_map.insert(pair<char, string>('8', "tuv"));
	_map.insert(pair<char, string>('9', "wxyz"));
}

LetterCombinationsOfAPhoneNumber::~LetterCombinationsOfAPhoneNumber()
{
	_map.clear();
	cout << "LetterCombinationsOfAPhoneNumber destructed" << endl;
}

void LetterCombinationsOfAPhoneNumber::Impl()
{
	vector<string> result = letter_combinations("23");
	for (const auto str : result)
		cout << str << endl;
}

vector<string> LetterCombinationsOfAPhoneNumber::letter_combinations(string digits)
{
	vector<string> result;
	auto size = digits.size();
	if (size == 0)
		return result;

	if (size == 1 && digits[0] == '1')
		return result;

	string combination;
	dfs(result, 0, digits,combination);
	return result;
}

void LetterCombinationsOfAPhoneNumber::dfs(vector<string>& result, int index,string digits,string combination)
{
	//输入2，3
	//一开始输入2，拿到abc，遍历abc，先取a，然后进入下一个数字（3）对应的def，将a和d组合进入下一循环，
	//此时index为2，进入下一层递归后index会等于digits长度（2），因此判断该次组合已完成，组合结果添加至result中，
	//然后退回上一层，combination弹出尾部的字符串（弹出d，这里即回溯），然后添加e，重复刚才流程
	//即：数字（2和3）相当于树的深度，2对应的abc每个数字都要索引到3对应的def
	//相当于：循环走到a的时候遍历一次def，b的时候遍历一次def，c再遍历一次def
	if(index == digits.size())
	{
		result.emplace_back(combination);
		return;
	}

	auto charNumber = digits[index];
	auto str = _map.at(charNumber);
	for (const auto c : str)
	{
		combination.push_back(c);
		dfs(result, index + 1, digits, combination);//index+1:寻找下一个数字对应的字母
		combination.pop_back();//回溯，去掉旧的，然后匹配新的
	}
}
