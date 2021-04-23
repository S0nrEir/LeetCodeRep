#ifndef MINIMUN_PATH_SUM_H
#define  MINIMUN_PATH_SUM_H
#include "Entrance.h"
#include <vector>

//����һ�������Ǹ������� m x n ���� grid �����ҳ�һ�������Ͻǵ����½ǵ�·����ʹ��·���ϵ������ܺ�Ϊ��С��
//˵����ÿ��ֻ�����»��������ƶ�һ����
//      ���룺grid = 
		//[1,3,1]
		//[1,5,1],
		//[4,2,1]
//      �����7
//      ���ͣ���Ϊ·�� 1��3��1��1��1 ���ܺ���С��
class MinimunPathSum : public Entrance
{
public:
	MinimunPathSum();
	~MinimunPathSum();
	virtual void Impl();

private:
	int GetPathSum(std::vector<std::vector<int>>& grid);
};

#endif