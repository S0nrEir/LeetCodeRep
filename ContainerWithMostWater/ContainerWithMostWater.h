#ifndef CONTAINER_WITH_MOST_WATER_H
#define CONTAINER_WITH_MOST_WATER_H

#include "../Entrance.h"
#include <vector>

using namespace std;



class ContainerWithMostWater : public Entrance
{
public:
	ContainerWithMostWater();
	~ContainerWithMostWater();


	virtual void Impl();

private:
	int max_area(vector<int>& height);
};
#endif


