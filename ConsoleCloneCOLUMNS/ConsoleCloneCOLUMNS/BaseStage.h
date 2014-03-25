#pragma once
#include "Common.h"
class BaseStage
{
protected:
	int* stageData;
public:
	BaseStage();
	~BaseStage();

	virtual void initStage() = 0;
	virtual void setStage(int x, int y,int value) = 0;
	virtual int getStage(int x, int y) = 0;
	virtual void draw() = 0;
	
};

