#include "CStage.h"


/*	makeCト 2014/3/28
コンストラクタ

引数:無し
戻り値:無し
備考:
	stageのオブジェクトを定義 中身は、CCell<int>の配列のオブジェクト
	Cdropのオブジェクトを定義 中身は、CDropのクラスのオブジェクト
	Cjewelのオブジェクトを定義 中身は、CJewelのクラスのオブジェクト
	randomのオブジェクトを定義 中身は、Randomのクラスのオブジェクト
*/
CStage::CStage(){
	stage = new CCell<int>(defaultStageWidth, defaultStageHeight);
	Cdrop = new CDrop;
	Cjewel = new CJewel;
	random = new Random;
}


/*	makeCト 2014/3/28
デストラクタ

引数:無し
戻り値:無し
備考:
	オブジェクトを削除
*/
CStage::~CStage(){
	delete stage;
	delete Cdrop;
	delete Cjewel;
	delete random;
}


/*	makeCト 2014/3/28
落下物オブジェクトを宝石の色を取ってセット

引数:無し
戻り値:無し
備考:
	ランダムで返ってきた値を宝石の色としてjewelクラスのcolorデータメンバにセットして、
	それを取得してセットするを3回繰り返す

	CDropにランダムの配列を投げてやろうかと思ったけども、どっちが設計的にいいか判断しにくい。
	一応データを一つで投げて、実態を作成しているここでループさせるべきかなぁーと
	そしたら使いまわし行けそうだし、とか、いいつつもCDropでdropNumber持たせてるし…
*/
void CStage::setDropOnJewel(){

	int dropNum = Cdrop->getdropNumber();

	for (int i = 0; i < dropNum; i++){
		int numOfRand = random->getRand();
		Cjewel->setJewelColor(numOfRand);

		int jewelColor = Cjewel->getJewelColor();
		Cdrop->setDrop(jewelColor, i);
	}
}

/*	makeCト 2014/3/28
ステージにセットする

引数:無し
戻り値:無し
備考:

*/
void CStage::initStage(){
	
	for (int y = 0; y < stage->getSizeY(); y++){
		for (int x = 0; x < stage->getSizeX(); x++){
			if (x == 0 || x == (stage->getSizeX() - 1) ||
				y == (stage->getSizeY() - 1)){
					stage->set(x, y, BLOCK);
			}
			else{
				stage->set(x, y, SPACE);
			}
		}
	}
}
/*	makeCト 2014/3/28
落下物をステージにセットする

引数:無し
戻り値:無し
備考:

*/
void CStage::setDropOnStage(){
	
}

/*	makeCト 2014/3/28
initまとめ 

引数:無し
戻り値:無し
備考:
	まとめて呼び出す用
*/
void CStage::init(){

	initStage();			//ステージの初期化

	setDropOnJewel();		//落下物のセット

	Cdrop->setPosition();	//落下物の座標を初期化

}