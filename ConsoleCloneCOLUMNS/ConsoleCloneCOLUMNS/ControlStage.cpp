#include "ControlStage.h"


ControlStage::ControlStage():
stageWidth(defaultStageWidth), stageHeight(defaultStageHeight)
{
	stageData = new int[stageWidth * stageHeight];
}


ControlStage::ControlStage(int width, int height):
stageWidth(width), stageHeight(height)
{
	stageData = new int[stageWidth * stageHeight];
}


ControlStage::~ControlStage()
{
	delete[] stageData;
}


void ControlStage::initStage()
{
	for (int y = 0; y < stageHeight; y++)
	{
		for (int x = 0; x < stageWidth; x++)
		{
			setStage(x, y, SPACE);
		}
	}
}


void ControlStage::setStage(int x, int y,int value)
{
	stageData[y * stageWidth + x] = value;
}


int ControlStage::getStage(int x, int y)
{
	return stageData[y * stageWidth + x];
}


void ControlStage::draw()
{
	using namespace std;
	for (int y = 0; y < stageHeight; y++)
	{
		for (int x = 0; x < stageWidth; x++)
		{
			switch (getStage(x,y))
			{
			case SPACE:
				cout << ' ';
				break;
			case BLOCK:
				cout << '#';
				break;
			}
		}
		cout << endl;
	}
}