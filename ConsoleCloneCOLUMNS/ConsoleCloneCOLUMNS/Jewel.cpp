#include "Jewel.h"
#include "Random.h"

Jewel::Jewel():
jewelSetNum(defDewelNum), jewelNum(defJewelNum)
{
	jewelArray = new int[jewelSetNum];
}


Jewel::Jewel(int num):
jewelSetNum(num), jewelNum(defJewelNum)
{
	jewelArray = new int[jewelSetNum];
}


Jewel::~Jewel()
{
	delete[] jewelArray;
}


void Jewel::initJewelArray()
{
	Random random;

	for (int i = 0; i < jewelSetNum; i++)
	{
		jewelArray[jewelSetNum] = random.getRand(jewelNum);
	}
}