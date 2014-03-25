#pragma once
#include "Common.h"
class Jewel
{
private:
	int jewelSetNum;
	int jewelNum;
	int* jewelArray;
public:
	Jewel();
	Jewel(int num);
	~Jewel();

	void initJewelArray();
};

