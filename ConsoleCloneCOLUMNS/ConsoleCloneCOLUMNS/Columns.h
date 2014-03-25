#pragma once
#include "Common.h"
#include "ControlStage.h"
#include "ViewStage.h"
#include "Jewel.h"
class Columns
{
private:
	ControlStage* controlStage;
	ViewStage* viewStage;
	Jewel* jewel;
public:
	Columns();
	~Columns();

	void init();
	void draw();
};

