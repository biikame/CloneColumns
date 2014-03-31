#pragma once
#include "CCell.h"

namespace MakeCto{
	/*	makeCト 2014/3/28
	落下物クラス

	引数: 無し
	戻り値:無し
	備考:
	cellデータをnewする。
	デフォの場合はm_ommon.hのデータで初期化
	*/
	class CDrop{
	private:

		CCell<BLOCKDATA>* m_cell;							//落ち物のオブジェクト。実態はCCellint型の配列

		int x, y;										//落ち物の座標
		int dX, dY;										//差分
		int state, timer;								//状態、タイマー

		const int width, height;						//width,heightの値、データ
		const int stageWidth, stageHeight;				//stage width,heightの値、データ
		const int dropNumber;							//落ち物の配列の数
		const int dammyHeight;							//y座標の配列ダミー部分
	public:
		CDrop();										//コンストラクタ
		CDrop(int x, int y);							//コンストラクタ
		~CDrop();										//デストラクタ

		void setX(int argX){ x = argX; }				//x座標のセット
		void setY(int argY){ y = argY; }				//y座標のセット

		int getX(){ return x; }							//x座標を取得
		int getY(){ return y; }							//y座標を取得
		int getWidth(){ return width; }					//widthを取得
		int getHeight(){ return height; }				//heightを取得
		int getDx(){ return dX; }						//移動差分dX取得用
		int getDy(){ return dY; }						//移動差分dY取得用
		void timerPuls(){ timer++; }					//タイマーを回す
		int getTimer(){ return timer; }					//タイマーの取得
		void setTimer(int time){ timer = time; }		//タイマーのセット
		int getDammyHeight(){ return dammyHeight; }		//dammyHeightを取得

		void setDrop(int x, int y, BLOCKDATA value);	//宝石のデータを落ち物に入れる

		void setPosition(int x, int y);					//座標をセット

		int getdropNumber();							//落ち物の数を取得

		BLOCKDATA getdrop(int x, int y);				//CCellデータを取得

		int checkKey(int key);							//何キーが押されたか返す

		void freeDrop();								//自由落下
	};
}