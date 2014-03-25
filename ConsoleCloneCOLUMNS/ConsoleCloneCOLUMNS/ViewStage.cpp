#include "ViewStage.h"


ViewStage::ViewStage():
viewWidth(defaultViewStageWidth), viewHeight(defaultViewStageHeight)
{
	stageData = new int[viewWidth * viewHeight];
}


ViewStage::ViewStage(int width, int height):
viewWidth(width), viewHeight(height)
{
	stageData = new int[viewWidth * viewHeight];
}


ViewStage::~ViewStage()
{
	delete[] stageData;
}


void ViewStage::initStage()
{
	for (int y = 0; y < viewHeight; y++)
	{
		for (int x = 0; x < viewWidth; x++)
		{
			if (
				x == 0 || x == (viewWidth - 1) ||
				y == (viewHeight - 1)
				)
			{
				stageData[y * viewWidth + x] = BLOCK;
			}
			else
			{
				stageData[y * viewWidth + x] = SPACE;
			}
		}
	}
}

void ViewStage::setStage(int x,int y,int value)
{
	stageData[y * viewWidth + x] = value;
}


int ViewStage::getStage(int x, int y)
{
	return stageData[y * viewWidth + x];
}


void ViewStage::draw()
{
	using namespace std;
	for (int y = 0; y < viewHeight; y++)
	{
		for (int x = 0; x < viewWidth; x++)
		{
			switch (getStage(x, y))
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