#pragma once
#include "CCell.h"
#include "CDrop.h"
#include "Jewel.h"
#include "Random.h"
#include "Common.h"
#include "CConsole.h"
namespace MakeCto{
	/*	makeCト 2014/3/28
	ステージクラス

	備考:
	Jewel Random CDrop は、ここで実態を持つ
	stageの配列の実態はここで作成はCStageもう一つ上のメインで書こうと思ってます
	つまり処理はCStageですべて済ませる。
	*/

	class CStage{
	private:
		
		CCell<BLOCKDATA>* m_cell;	//ステージのオブジェクト。実態はCCellint型の配列
		CCell<bool>* m_cellRecursive;//ステージのオブジェクト。実態はCCellbool型の配列
		CDrop* m_drop;				//CDropクラスのオブジェクト。実態はCDropクラス本体
		CJewel* m_jewel;			//CJewelクラスのオブジェクト。実態はCJewelクラス本体
		Random* random;				//Randomクラスのオブジェクト。実態はRadomクラス本体
		CConsole m_console;			//
		int firstX, firstY;			//x,yの最初表示ポイント
		BLOCKDATA recursiveData;	//再帰用データ
		int deleteCounter;			//デリートの数用
		bool deleteflag;			
	public:
		CStage();					//コンストラクタ
		~CStage();					//デストラクタ

		void init();				//init系をまとめておく
		void draw();				//表示
		void move(WAY way);			//移動
		bool checkMove(int key);	//移動できるかチェック	
		WAY checkDropToStage(WAY& way);	//ステージと落下物のチェック
		//Drapに宝石のセット
		void setDropOnJewel();		//落ち物に宝石をセットする

		void initStage();			//ステージの初期化

		void setDropOnStage();		//落下物をステージにセットする

		void setFirstPoint();		//初期位置設定用

		bool freeDrop();			//自由落下

		void deleteCheck();			//消す処理

		bool recursiveBlock(int x, int y, int dX, int dY);		//再帰的に確認

		void initCellRecursive();

		void deleteBlock();
		void updateStage();

		void recursiveStage(int x, int y, int dX, int dY);

		void recursive();

		bool getDeleteflag(){return deleteflag; }
		void setDeleteflag(bool flag){ deleteflag = flag; }

		bool clear();
	};
}