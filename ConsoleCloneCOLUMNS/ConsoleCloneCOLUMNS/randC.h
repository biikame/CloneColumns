#pragma once
#include "Common.h"


/*	makeCト 2014/3/28
C言語風のランダム群クラス

備考:
	継承元として、作成してます。
*/
class randC{
private:
	int randNum;							//ランダムで得られた値を一時保持する用
	int min, max;							//ランダムの範囲指定 最小min,最大max
public:
	randC();								//デフォルト設定用コンストラクタ
	randC(int argMin, int argMax);			//引数で設定用コンストラクタ
	~randC();								//デストラクタ

	int getRand();							//rand値取得
	int getRand(int argMin, int argMax);	//任意の引数でrand取得　設定されたmin,max以外でランダムしたい時用

	void setRand(int argMin, int argMax);	//再設定　min max
};

