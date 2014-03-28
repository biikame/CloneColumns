#include "CDrop.h"


/*	makeCト 2014/3/28
コンストラクタ

引数:無し
戻り値:無し
備考:
	移動、差分は0で初期化しておいて後に出てくるinitで最セット
	引数無しコンストラクタはデフォ値なので、
	Common.hのデータで初期化
	dropのオブジェクト(実態)を定義 中身は、CCellint型の配列データ　
*/
CDrop::CDrop() :
x(0), y(0), dX(0), dY(0), dammyHeight(defaultDammyHeight),
width(defaultDropWidth), height(defaultDropHeight),
state(INIT), timer(0), dropNumber(defaultDropHeight){
	drop = new CCell<int>(width, height);
}


/*	makeCト 2014/3/28
デストラクタ

引数:無し
戻り値:無し
備考:
	dropのオブジェクト(実態)を削除
*/
CDrop::~CDrop(){
	delete drop;
}


/*	makeCト 2014/3/28
落下物の配列に宝石をセットする

引数:int value:入れる色データ用
戻り値:無し
備考:
	dropの配列データに宝石の色データを入れる
*/
void CDrop::setDrop(int value,int num){
	drop->set(0, num, value);
}


/*	makeCト 2014/3/28
落下物の座標を代入する

引数:
戻り値:無し
備考:
	xデータは中間座標を入れる
	yデータだけは、可変しても位置は変わらない
*/
void CDrop::setPosition(){
	//初期位置セット
	setX(width / 2);
	setY(dammyHeight);
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
	return -1;
}


/*	makeCト 2014/3/29
落ち物のデータを取得用 

引数:
戻り値:無し
備考:
	CStageからdropは呼べないので関数で呼べるようにする
*/
int CDrop::getdrop(int x, int y){
	drop->get(x,y);
	return -1;
}

