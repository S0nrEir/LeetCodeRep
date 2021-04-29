#ifndef PLUS_TWO_NUMBER_H
#define  PLUS_TWO_NUMBER_H
#include "../Entrance.h"

//    ����һ���������� nums ��һ������Ŀ��ֵ target�������ڸ��������ҳ� ��ΪĿ��ֵ ���� ���� ���������������ǵ������±ꡣ����Լ���ÿ������ֻ���Ӧһ���𰸡����ǣ�������ͬһ��Ԫ���ڴ��ﲻ���ظ����֡����԰�����˳�򷵻ش𰸡�
//      ���룺nums = [2,7,11,15], target = 9
//      �����[0,1]
//      ���ͣ���Ϊ nums[0] + nums[1] == 9 ������[0, 1] ��
class PlusTwoNumber : public Entrance
{
public:
	PlusTwoNumber();
	~PlusTwoNumber();
	virtual void Impl();

private:
	int* GetSum(int arr[], int target);
};


#endif