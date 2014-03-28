#include "Common.h"
#include "CStage.h"

int main(){

	CStage* stage = new CStage;

	stage->init();

	delete stage;
	return 0;
}