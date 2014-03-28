#pragma once
/*
INCLUDE
*/
#include "Common.h"
#include "randC.h"


/* makeCト 2014/3/28
ランダムクラス-randCを継承

備考:
*/
class Random:public randC{
public:
	Random();				//デフォルトで設定用コンストラクタ
	Random(int min,int max);//引数で設定用コンストラクタ
	~Random();				//デストラクタ
};

