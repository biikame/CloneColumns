#pragma once 


#include <iostream>
#include <time.h>
#include <conio.h>

namespace MakeCto{
	enum _ERR{
		ERR = -1,
	};


	enum defMax{
		maxX = 99,
		maxY = 99,
	};


	enum defaultData{

		defaultStageWidth = 8,
		defaultStageHeight = 17,

		defaultWidth = 6,
		defaultHeight = 13,

		defaultDropWidth = 1,
		defaultDropHeight = 3,

		defaultDammyHeight = 3,
	};


	enum StateData{
		INIT,
		GAME,
		CLEAR,
	};


	enum randCData{
		minRand = 0,
		maxRand = 6,
	};


	enum BLOCKDATA{
		SPACE,
		RED,
		YELLOW,
		GREEN,
		BLUE,
		ORANGE,
		PERPLE,
		BLOCK = 99,
		ERROR_B = -1,
	};

	enum WAY{
		UP,
		DOWN,
		LEFT,
		RIGHT,
		NONE = -1,
	};
}