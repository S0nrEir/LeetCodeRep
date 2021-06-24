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
	//����2��3
	//һ��ʼ����2���õ�abc������abc����ȡa��Ȼ�������һ�����֣�3����Ӧ��def����a��d��Ͻ�����һѭ����
	//��ʱindexΪ2��������һ��ݹ��index�����digits���ȣ�2��������жϸô��������ɣ���Ͻ�������result�У�
	//Ȼ���˻���һ�㣬combination����β�����ַ���������d�����Ｔ���ݣ���Ȼ�����e���ظ��ղ�����
	//�������֣�2��3���൱��������ȣ�2��Ӧ��abcÿ�����ֶ�Ҫ������3��Ӧ��def
	//�൱�ڣ�ѭ���ߵ�a��ʱ�����һ��def��b��ʱ�����һ��def��c�ٱ���һ��def
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
		dfs(result, index + 1, digits, combination);//index+1:Ѱ����һ�����ֶ�Ӧ����ĸ
		combination.pop_back();//���ݣ�ȥ���ɵģ�Ȼ��ƥ���µ�
	}
}
