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
		return "";//�߽���������ĸΪ0

	if (numerator == 0)
		return "0";//�߽�����������Ϊ0

	string result;

	//ת��Ϊlonglong��ֹ���
	long long num = static_cast<long long>(numerator);
	long long denom = static_cast<long long>(denominator);

	//���������ţ�һ��һ��ȡ����
	if ((num > 0) ^ (denom > 0))result.push_back('-');

	//���ӷ�ĸȫ��ת��Ϊ����
	num = llabs(num); denom = llabs(denom);

	//������������
	result.append(to_string(num / denom));

	//����С������
	num %= denom;
	if (num == 0)
		return result;//����Ϊ0����ʾ�����ˣ�ֱ�ӷ��ؽ��

	result.push_back('.');//������Ϊ0�����С����
	int index = result.size() - 1;//���С������±�
	unordered_map<int, int> record;//map������¼�����ظ������±꣬Ȼ��'('���뵽�ظ���ǰ��

	while (num && record.count(num) == 0)
	{   //С�����֣�������Ϊ0��������û�г����ظ�����
		record[num] = ++index;
		num *= 10;//��������10����Ȼ�����̣��Ͳݸ屾�����㷽����һ����
		result += to_string(num / denom);
		num %= denom;
	}

	//����ѭ��������ֱ�����ظ�����ǰ�����'(',�ַ���ĩβ���')'
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