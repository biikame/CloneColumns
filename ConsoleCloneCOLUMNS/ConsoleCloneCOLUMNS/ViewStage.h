#pragma once
#include "BaseStage.h"
class ViewStage:public BaseStage
{
private:
	const int viewWidth;
	const int viewHeight;
public:
	ViewStage();
	ViewStage(int width, int height);
	~ViewStage();

	void initStage();
	void setStage(int x, int y, int value);
	int getStage(int x, int y);
	void draw();
};

