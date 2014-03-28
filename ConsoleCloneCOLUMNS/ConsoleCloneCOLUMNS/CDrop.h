#pragma once
#include "CCell.h"


/*	makeCト 2014/3/28
落下物クラス

引数: 無し
戻り値:無し
備考:
cellデータをnewする。
デフォの場合はCommon.hのデータで初期化
*/
class CDrop{
private:
	CCell<int>* drop;					//落ち物のオブジェクト。実態はCCellint型の配列

	int x, y;							//落ち物の座標
	int dX, dY;							//差分
	int state, timer;					//状態、タイマー

	const int width, height;			//width,heightの値、データ
	const int dropNumber;				//落ち物の配列の数
	const int dammyHeight;				//y座標の配列ダミー部分
public:
	CDrop();							//コンストラクタ
	~CDrop();							//デストラクタ

	void setX(int argX){ x = argX; }	//x座標のセット
	void setY(int argY){ y = argY; }	//y座標のセット

	int getX(){ return x; }				//x座標を取得
	int getY(){ return y; }				//y座標を取得

	void setDrop(int value,int num);	//宝石のデータを落ち物に入れる

	void setPosition();					//座標の初期化

	int getdropNumber();				//落ち物の数を取得

	int getdrop(int x, int y);			//CCellデータを取得


};