#include "randC.h"


/* makeCト 2014/3/28
コンストラクタ

引数:無し
戻り値:無し
備考:
	引数無しコンストラクタはデフォ値用なので、
	デフォの場合はCommon.hのデータで初期化
*/
randC::randC():
min(minRand), max(maxRand), randNum(0){

	srand((unsigned int)time(NULL));//rand()関数の罠回避
}


/* makeCト 2014/3/28
引数付きコンストラクタ

引数: 
	int argumentMin:minの値設定用
	int argumentMax:maxの値設定用
戻り値:無し	
備考:
	引数付きコンストラクタは可変用なので、
	引数で初期化
*/
randC::randC(int argumentMin,int argumentMax):
min(argumentMin), max(argumentMax), randNum(0){

	srand((unsigned int)time(NULL));//rand()関数の罠回避
}


/*	makeCト 2014/3/28
デストラクタ

引数:無し
戻り値:無し
備考:
*/
randC::~randC(){
}


/*	makeCト 2014/3/28
ランダムの値を取得する

引数:無し
戻り値:min~maxまでの値を返す
備考:
	min,maxの値を元にradmNumに値を入れてから戻す
*/
int randC::getRand(){

	randNum = (rand() % max) + min;

	if (min <= randNum && randNum <= max){
		return randNum;
	}
	else{
		throw "getRand:ランダムの値に範囲外の値が入っています";
	}
	return -1;
}


/*	makeCト 2014/3/28
ランダムの値を取得する　オーバーロード

引数: 
	int argumentMin: minの値とする
	int argumentMax: maxの値とする
戻り値:min~maxまでの値を返す
備考:
	引数のmin,maxの値を元にradmNumに値を入れてから戻す
*/
int randC::getRand(int argumentMin, int argumentMax){

	randNum = (rand() % argumentMax) + argumentMin;

	if (argumentMin <= randNum && randNum <= argumentMax){
		return randNum;
	}
	else{
		throw "getRand:ランダムの値に範囲外の値が入っています";
	}
	return -1;
}


/*	makeCト 2014/3/28
min,max値をセットする

引数:
int argumentMin: 再設定用のminの値
int argumentMax: 再設定用のmaxの値
戻り値:無し
備考:
	最設定
*/
void randC::setRand(int argumentMin, int argumentMax){
	
	if (0 <= argumentMin &&
		argumentMin <= argumentMax &&
		argumentMax <= INT_MAX){
		min = argumentMin;
		max = argumentMax;
	}
	else{
		throw "setRand:min,maxにおかしな値を代入しようとしています";
	}
}