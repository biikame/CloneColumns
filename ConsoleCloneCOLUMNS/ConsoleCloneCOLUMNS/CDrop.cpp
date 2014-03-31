#include "CDrop.h"
using namespace MakeCto;


/*	makeCト 2014/3/28
コンストラクタ

引数:無し
戻り値:無し
備考:
	移動、差分は0で初期化しておいて後に出てくるinitで最セット
	引数無しコンストラクタはデフォ値なので、
	m_ommon.hのデータで初期化
	m_cellのオブジェクト(実態)を定義 中身は、CCellint型の配列データ　
*/
CDrop::CDrop() :
x(0), y(0), dX(0), dY(0), dammyHeight(defaultDammyHeight),
width(defaultDropWidth), height(defaultDropHeight),
stageWidth(defaultStageWidth), stageHeight(defaultStageHeight),
state(INIT), timer(0), dropNumber(defaultDropHeight){
	
	m_cell = new CCell<BLOCKDATA>(width, height);
}


CDrop::CDrop(int dropX,int dropY) :
x(0), y(0), dX(0), dY(0), dammyHeight(defaultDammyHeight),
width(dropX), height(dropY),
stageWidth(defaultStageWidth), stageHeight(defaultStageHeight),
state(INIT), timer(0), dropNumber(defaultDropHeight){

	m_cell = new CCell<BLOCKDATA>(width, height);
}


/*	makeCト 2014/3/28
デストラクタ

引数:無し
戻り値:無し
備考:
	m_cellのオブジェクト(実態)を削除
*/
CDrop::~CDrop(){
	delete m_cell;
}


/*	makeCト 2014/3/28
落下物の配列に宝石をセットする

引数:int value:入れる色データ用
戻り値:無し
備考:
	m_cellの配列データに宝石の色データを入れる
*/
void CDrop::setDrop(int x, int y, BLOCKDATA value){

	if (0 <= x && x <= width && 0 <= y && y <= height){
		m_cell->set(x, y, value);
	}
	else{
		throw "setDrop:x,yの値が範囲外を指しています。";
	}
}


/*	makeCト 2014/3/28
落下物の座標を代入する

引数:
戻り値:無し
備考:
*/
void CDrop::setPosition(int x, int y){

	//初期位置セット
	setX(x);
	setY(y);
	
}


/*	makeCト 2014/3/28
落ち物の数を取得

引数:
戻り値:無し
備考:
*/
int CDrop::getdropNumber(){
	if (0 < dropNumber && dropNumber < INT_MAX){
		return dropNumber;
	}
	else{
		throw "dropNumberにおかしなデータが入っています";
	}
	return ERR;
}


/*	makeCト 2014/3/29
落ち物のデータを取得用 

引数:
戻り値:無し
備考:
	CStageからm_cellは呼べないので関数で呼べるようにする
*/
BLOCKDATA CDrop::getdrop(int x, int y){
	int sizeX = m_cell->getSizeX();
	int sizeY = m_cell->getSizeY();
	if (0 <= x && x < sizeX && 0 <= y && y < sizeY){
		return m_cell->get(x, y);
	}
	else {
		throw "getdrop:m_cell配列の範囲外を指しています。オーバーランですよ？";
	}
	return ERROR_B;
}


/*	makeCト 2014/3/29
落ち物が動けるかチェック

引数:
戻り値:WAY　WAY型の(上下左右)は入る
備考:
CStageからm_cellは呼べないので関数で呼べるようにする
*/
int CDrop::checkKey(int key){

	dX = dY = 0;//差分初期化

	switch (key){
	case 'a':dX--; break;
	case 'd':dX++; break;
	case 'w':dY--; break;
	case 's':dY++; break;
	}
	return 0;
}


/*	makeCト 2014/3/29
落下物が自由落下する処理

引数:
戻り値:
備考:
	
*/
void CDrop::freeDrop(){
	_sleep(300);
}