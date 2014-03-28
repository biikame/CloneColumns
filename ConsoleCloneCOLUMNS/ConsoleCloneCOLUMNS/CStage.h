#pragma once
#include "CCell.h"
#include "CDrop.h"
#include "Jewel.h"
#include "Random.h"

/*	makeCト 2014/3/28
ステージクラス

備考:
	Jewel Random CDrop は、ここで実態を持つ
	stageの配列の実態はここで作成はCStageもう一つ上のメインで書こうと思ってます
	つまり処理はCStageですべて済ませる。
*/
class CStage{
private:
	CCell<int>* stage;			//ステージのオブジェクト。実態はCCellint型の配列
	CDrop* Cdrop;				//CDropクラスのオブジェクト。実態はCDropクラス本体
	CJewel* Cjewel;				//CJewelクラスのオブジェクト。実態はCJewelクラス本体
	Random* random;				//Randomクラスのオブジェクト。実態はRadomクラス本体
public:
	CStage();					//コンストラクタ
	~CStage();					//デストラクタ

	void init();				//init系をまとめておく
	//Drapに宝石のセット
	void setDropOnJewel();		//落ち物に宝石をセットする
	
	void initStage();			//ステージの初期化

	void setDropOnStage();		//落下物をステージにセットする


};

