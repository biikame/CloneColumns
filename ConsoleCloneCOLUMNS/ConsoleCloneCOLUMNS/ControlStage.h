#pragma once
#include "BaseStage.h"
class ControlStage:public BaseStage
{
private:
	const int stageWidth;
	const int stageHeight;
public:
	ControlStage();
	ControlStage(int width , int height);
	~ControlStage();
	
	void initStage();
	void setStage(int x, int y,int value);
	int getStage(int x, int y);
	void draw();
};

