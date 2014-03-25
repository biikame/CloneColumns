#include "Columns.h"

Columns::Columns()
{
	controlStage = new ControlStage;
	viewStage = new ViewStage;
	jewel = new Jewel;
}


Columns::~Columns()
{
	delete controlStage;
	delete viewStage;
	delete jewel;
}


void Columns::init()
{
	BaseStage* baseStage[2];

	baseStage[0] = controlStage;
	baseStage[1] = viewStage;

	for (int i = 0; i < 2; i++)
	{
		baseStage[i]->initStage();
	}
}


void Columns::draw()
{
//DEBUG
#ifdef DEBUG	//ステージの中身確認用
	BaseStage* baseStage[2];

	baseStage[0] = controlStage;
	baseStage[1] = viewStage;

	for (int i = 0; i < 2; i++)
	{
		baseStage[i]->draw();
	}
#else	
	viewStage->draw();
#endif
}