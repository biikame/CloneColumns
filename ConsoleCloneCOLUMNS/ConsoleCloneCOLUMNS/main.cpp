#include "Common.h"
#include "CStage.h"
using namespace MakeCto;
using namespace std;
void chgeneState(StateData&,StateData);

int main(){
	CStage* stage = new CStage;
	
	StateData state = INIT;
	try{
		stage->initStage();						//ステージの初期化
		while(1){
			system("cls");

			
			
			switch (state){
			case INIT:
				stage->init();
				chgeneState(state,GAME);
				break;
			case GAME:
				int key = 0;
				stage->draw();

				if (kbhit()){
					key = _getch();
				}
				stage->checkMove(key);
				if (!stage->freeDrop()){
					chgeneState(state, INIT);
				}
				break;
			}
		}
	}
	catch (char* err){
		cout << "エラー" << err << endl;
	}

	delete stage;

	return 0;
}

void chgeneState(StateData& state, StateData nexetState){
	state = nexetState;
}