#include "LongestPalindromicSubString.h"
#include <iostream>
#include <string.h>
#include <string>
#include <math.h>

using namespace std;

LongestPalindromicSubString::LongestPalindromicSubString()
{
	cout << "LongestPalindromicSubString constructed" << endl;
}

LongestPalindromicSubString::~LongestPalindromicSubString()
{
	cout << "LongestPalindromicSubString destructed" << endl;
}

void LongestPalindromicSubString::Impl()
{
	//cout << "palindromic string is " << get_palindromic("babad") << endl;
	//cout << "palindromic string is " << get_palindromic("cbbd") << endl;
	//cout << "palindromic string is " << get_palindromic("bb") << endl;
	cout << "palindromic string is " << get_palindromic("ccc") << endl;
}

string LongestPalindromicSubString::get_palindromic(string s)
{
	int len = s.length();
	if (len == 0)
		return "";

	if (len == 1)
		return s;

	int max_len = 0;
	int targetIndex = 0;
	int start = 0;
	int end = 0;

	for (int i = 0; i < len; i++)
	{
		int tempLeft_1 = 0;
		int tempRight_1 = 0;
		int tempLeft_2 = 0;
		int tempRight_2 = 0;
		auto pal_len_1 = is_palindromic(s, i, i, tempLeft_1,tempRight_1);//中心扩展aba
		auto pal_len_2 = is_palindromic(s, i, i + 1, tempLeft_2,tempRight_2);//对偶cbb
		if (tempRight_1 - tempLeft_1 > end - start)
		{
			start = tempLeft_1;
			end = tempRight_1;
		}
		if (tempRight_2 - tempLeft_2 > end - start)
		{
			start = tempLeft_2;
			end = tempRight_2;
		}
	}
	return s.substr(start, end - start + 1);
}

int LongestPalindromicSubString::is_palindromic(string s,int left, int right,int &indexLeft,int &indexRight)
{
	int offset = 0;
	int len = s.length();
	int pal_len = 0;
	int index_left = left;
	int index_right = right;
	
	//if (left - 1 < 0 || right + 1 >= len)//超出边界
	//	return -1;

	while (!(left - offset < 0) && !(right + offset >= len))
	{
		char left_char = s[left - offset];
		char right_char = s[right + offset];
		if (left_char == right_char)
		{
			offset++;
			index_left--;
			index_right++;
		}
		else
			break;
	}
	indexLeft = index_left + 1;
	indexRight = index_right - 1;
	return offset;
}
