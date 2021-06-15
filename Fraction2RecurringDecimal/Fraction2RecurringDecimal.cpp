#include "Fraction2RecurringDecimal.h"
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

Fraction2RecurringDecimal::Fraction2RecurringDecimal()
{
	cout << "Fraction2RecurringDecimal constructed" << endl;
}

Fraction2RecurringDecimal::~Fraction2RecurringDecimal()
{
	cout << "Fraction2RecurringDecimal destructed" << endl;
}

void Fraction2RecurringDecimal::Impl()
{
	int numerator = 4;
	int denominator = 333;

	//int numerator = 2;
	//int denominator = 5;

	string res = fraction_2_decimal(numerator,denominator);
	cout << "numerator:"<< numerator<< ",denominator:"<< denominator << endl << "result:" << res <<endl;
}

string Fraction2RecurringDecimal::fraction_2_decimal(int numerator, int denominator)
{
	if (denominator == 0)
		return "";//边界条件，分母为0

	if (numerator == 0)
		return "0";//边界条件，分子为0

	string result;

	//转换为longlong防止溢出
	long long num = static_cast<long long>(numerator);
	long long denom = static_cast<long long>(denominator);

	//处理正负号，一正一负取负号
	if ((num > 0) ^ (denom > 0))result.push_back('-');

	//分子分母全部转换为正数
	num = llabs(num); denom = llabs(denom);

	//处理整数部分
	result.append(to_string(num / denom));

	//处理小数部分
	num %= denom;
	if (num == 0)
		return result;//余数为0，表示整除了，直接返回结果

	result.push_back('.');//余数不为0，添加小数点
	int index = result.size() - 1;//获得小数点的下标
	unordered_map<int, int> record;//map用来记录出现重复数的下标，然后将'('插入到重复数前面

	while (num && record.count(num) == 0)
	{   //小数部分：余数不为0且余数还没有出现重复数字
		record[num] = ++index;
		num *= 10;//余数扩大10倍，然后求商，和草稿本上运算方法是一样的
		result += to_string(num / denom);
		num %= denom;
	}

	//出现循环余数，直接在重复数字前面添加'(',字符串末尾添加')'
	if (record.count(num) == 1)
	{
		result.insert(record[num], "(");
		result.push_back(')');
	}
	return result;

#pragma region

	//auto float_numerator = (float)numerator;
	//auto float_denominator = (float)denominator;
	//double factor = float_numerator / float_denominator;

	//if (numerator == 0)
	//	return "0";

	//if (numerator % denominator == 0)
	//	return std::to_string(factor);

	//if (factor * float_denominator == numerator)
	//	return std::to_string(factor);
	//else
	//{
	//	string res = "";
	//	int int_res = numerator;
	//	//int mul = int_res % denominator;
	//	int mul = 0;
	//	while (mul != numerator)
	//	{
	//		mul = int_res % denominator;
	//		int_res = numerator / denominator;
	//		if (int_res == numerator)
	//			return res;

	//		while (mul < denominator)
	//			mul *= 10;

	//		res += std::to_string(int_res);
	//	}

	//	return std::to_string(numerator / denominator) + "(" + res + ")";
	//}
#pragma endregion
}