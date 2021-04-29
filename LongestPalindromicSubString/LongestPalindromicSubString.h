#ifndef LONGEST_PALINDROMIC_SUB_STRING
#define LONGEST_PALINDROMIC_SUB_STRING

#include "../Entrance.h"
#include <string.h>
#include <string>

using namespace std;

/// <summary>
/// 给你一个字符串 s，找到 s 中最长的回文子串。
/// 示例 1：
/// 输入：s = "babad"
/// 输出："bab"
/// 解释："aba" 同样是符合题意的答案。
/// </summary>
class LongestPalindromicSubString : public Entrance
{
public:
	LongestPalindromicSubString();
	~LongestPalindromicSubString();

	virtual void Impl();

private:
	/// <summary>
	/// 获取最长回文串
	/// </summary>
	string get_palindromic(string s);

	/// <summary>
	/// 检查当前字符在串中是否为回文，返回长度，不是返回-1
	/// </summary>
	int is_palindromic(string s, int left, int right, int& indexLeft, int& indexRight);
};
#endif
