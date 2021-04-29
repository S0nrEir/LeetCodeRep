#ifndef LONGEST_PALINDROMIC_SUB_STRING
#define LONGEST_PALINDROMIC_SUB_STRING

#include "../Entrance.h"
#include <string.h>
#include <string>

using namespace std;

/// <summary>
/// ����һ���ַ��� s���ҵ� s ����Ļ����Ӵ���
/// ʾ�� 1��
/// ���룺s = "babad"
/// �����"bab"
/// ���ͣ�"aba" ͬ���Ƿ�������Ĵ𰸡�
/// </summary>
class LongestPalindromicSubString : public Entrance
{
public:
	LongestPalindromicSubString();
	~LongestPalindromicSubString();

	virtual void Impl();

private:
	/// <summary>
	/// ��ȡ����Ĵ�
	/// </summary>
	string get_palindromic(string s);

	/// <summary>
	/// ��鵱ǰ�ַ��ڴ����Ƿ�Ϊ���ģ����س��ȣ����Ƿ���-1
	/// </summary>
	int is_palindromic(string s, int left, int right, int& indexLeft, int& indexRight);
};
#endif
