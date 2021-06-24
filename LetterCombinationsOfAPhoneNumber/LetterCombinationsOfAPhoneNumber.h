#ifndef LETTER_COMBINATIONS_OF_A_PHONE_NUMBER_H
#define LETTER_COMBINATIONS_OF_A_PHONE_NUMBER_H

#include "../Entrance.h"
#include <vector>
#include <string>
#include <map>

using namespace std;

/// <summary>
/// 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。
/// 给出数字到字母的映射如下（与电话按键相同）。注意1不对应任何字母。
/// 1:!@#,2:abc,3:def
/// 4:ghi,5:jkl,6:mno
/// 7:pqrs,8:tuv,9:wxyz
/// *:+,0....,# ↑
/// </summary>
class LetterCombinationsOfAPhoneNumber : public Entrance
{
//#note
public:
	LetterCombinationsOfAPhoneNumber ();
	~LetterCombinationsOfAPhoneNumber ();

	virtual void Impl();

private:
	vector<string> letter_combinations(string digits);
	void dfs(vector<string>& result, int index, string digits, string combination);
	map<char, string> _map;
};


#endif
