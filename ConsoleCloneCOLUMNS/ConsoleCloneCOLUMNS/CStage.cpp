#include "CStage.h"
using namespace MakeCto;

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
CStage::CStage():
firstX(0), firstY(0){
	stage = new CCell<BLOCKDATA>(defaultStageWidth, defaultStageHeight);
	Cdrop = new CDrop;
	Cjewel = new CJewel;
	random = new Random(RED, PERPLE);
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

	for (int y = 0; y < dropNum; y++){
		BLOCKDATA numOfRand = (BLOCKDATA)random->getRand();
		Cjewel->setJewelColor(numOfRand);

		BLOCKDATA jewelColor = (BLOCKDATA)Cjewel->getJewelColor();
		Cdrop->setDrop(0,y,jewelColor);
	}
}


/*	makeCト 2014/3/28
ステージにセットする

引数:無し
戻り値:無し
備考:

*/
void CStage::initStage(){
	int width = stage->getSizeX();
	int height = stage->getSizeY();

	for (int y = 0; y < height; y++){
		for (int x = 0; x < width; x++){
			if (x == 0 || x == (width - 1) ||
				y == (height - 1)){
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
	int width = Cdrop->getWidth();
	int height = Cdrop->getHeight();

	for (int y = 0; y < height; y++){
		for (int x = 0; x < width; x++){
			BLOCKDATA drop = Cdrop->getdrop(x, y);
			stage->set((x+firstX), (y+firstY), drop);
		}
	}
}


/*	makeCト 2014/3/28
initまとめ 

引数:無し
戻り値:無し
備考:
	まとめて呼び出す用
*/
void CStage::init(){

	setDropOnJewel();					//落下物に宝石をセット

	setFirstPoint();					//初期位置の座標をセット

	Cdrop->setPosition(firstX, firstY);	//落下物の座標を初期化

	setDropOnStage();					//ステージに落下物をセット

}


/*	makeCト 2014/3/28
draw

引数:無し
戻り値:無し
備考:
	画面表示
*/
void CStage::draw(){
	using namespace std;
	
	int width = stage->getSizeX();
	int height = stage->getSizeY();

	for (int y = 0; y < height; y++){
		for (int x = 0; x < width; x++){

			switch (stage->get(x, y)){
			case SPACE:	cout << "　"; break;
			case BLOCK:	cout << "＃"; break;
			case RED:	cout << "赤"; break;
			case YELLOW:cout << "黄"; break;
			case GREEN:	cout << "緑"; break;
			case BLUE:	cout << "青"; break;
			case ORANGE:cout << "橙"; break;
			case PERPLE:cout << "紫"; break;
			case ERROR:	cout << "エ"; break;
			default:	cout << "？"; break;
			}
		}
		cout << endl;
	}
}


/*	makeCト 2014/3/28
ステージ上でのdropを移動させる

引数:無し
戻り値:無し
備考:
	ステージ上に置かれた落下物を全部移動させる
*/
bool CStage::checkMove(int key){
	
	Cdrop->checkKey(key);
	WAY way = NONE;
	way = checkDropToStage(way);
	if (way == NONE){ return false; }
	move(way);
	return true;
}

/*	makeCト 2014/3/28
ステージ上のnext先を確認

引数:無し
戻り値:無し
備考:
ステージ上に置かれた落下物を全部移動させる
*/
WAY CStage::checkDropToStage(WAY& way){
	int dropX = Cdrop->getX(), dropY = Cdrop->getY();
	int dX = Cdrop->getDx(), dY = Cdrop->getDy();
	int x = Cdrop->getX(), y = Cdrop->getY();
	int dropNumber = Cdrop->getdropNumber();
	int nextX = dropX + dX, nextY = dropY + dY;
	int stageWidth = stage->getSizeX(), stageHeight = stage->getSizeY();

	if (dX != 0){
		if (dX >0){//LEFT
			for (int i = 0; i < dropNumber; i++){
				int nextX = x + dX, nextY = y + dY + i;
				if (1 > nextX || nextX >= (stageWidth - 1) ||
					1 > nextY || nextY >= (stageHeight - 1)||
					stage->get(nextX,nextY) != SPACE){

					return NONE;
				}
			}
			return LEFT;
		}
		else if (dX < 0){//RIGHT
			for (int i = 0; i < dropNumber; i++){
				int nextX = x + dX, nextY = y + dY + i;
				if (1 > nextX || nextX >= (stageWidth - 1) ||
					1 > nextY || nextY >= (stageHeight - 1) ||
					stage->get(nextX, nextY) != SPACE){

					return NONE;
				}
			}
			return RIGHT;
		}
	}
	else if (dY != 0){
		if (dY > 0){//DOWN
			int nextX = x + dX, nextY = y + dY + (dropNumber - 1);

			if (1 > nextX || nextX >= (stageWidth - 1) ||
				1 > nextY || nextY >= (stageHeight - 1) ||
				stage->get(nextX, nextY) != SPACE){

				return NONE;
			}
			else{
				return DOWN;
			}
		}
		else if (dY < 0){//UP
			int nextX = x + dX, nextY = y + dY;

			if (1 > nextX || nextX >= (stageWidth - 1) ||
				1 > nextY || nextY >= (stageHeight - 1) ||
				stage->get(nextX, nextY) != SPACE){

				return NONE;
			}
			else{
				return UP;
			}
		}
	}
	//throw "データがきちんと入っていません";
	return NONE;
}
/*	makeCト 2014/3/28
ステージ上でのdropを移動させる

引数:無し
戻り値:無し
備考:
	ステージ上に置かれた落下物を全部移動させる
*/
void CStage::move(WAY way){

	int dropX = Cdrop->getX(), dropY = Cdrop->getY();
	int dX = Cdrop->getDx(), dY = Cdrop->getDy();
	int nextX = dropX + dX, nextY = dropY + dY;
	int dropNum = Cdrop->getdropNumber();

	switch (way){
	case UP:
		for (int i = 0; i < dropNum; i++){
			stage->swap(nextX, nextY + i, dropX, dropY + i);
		}
		Cdrop->setX(nextX), Cdrop->setY(nextY);
		break;
	case DOWN:
		for (int i = (dropNum - 1); i >= 0; i--){
			stage->swap(nextX, nextY + i, dropX, dropY + i);
		}
		Cdrop->setX(nextX), Cdrop->setY(nextY);
		break;
	case LEFT:
		for (int i = 0; i < dropNum; i++){
			stage->swap(nextX, nextY + i, dropX, dropY + i);
		}
		Cdrop->setX(nextX), Cdrop->setY(nextY);
		break;
	case RIGHT:
		for (int i = 0; i < dropNum; i++){
			stage->swap(nextX, nextY + i, dropX, dropY + i);
		}
		Cdrop->setX(nextX), Cdrop->setY(nextY);
		break;
	case NONE:
		Cdrop->setX(dropX), Cdrop->setY(dropY);
		break;
	}
}


/*	makeCト 2014/3/28
ステージ上でのdropの初期位置セット

引数:無し
戻り値:無し
備考:
*/
void CStage::setFirstPoint(){

	int tmpX = stage->getSizeX();
	int tmpY = Cdrop->getDammyHeight();

	if (0 < tmpX && tmpX < INT_MAX &&
		0 < tmpY && tmpY < INT_MAX
		){
		if (tmpX == 1){
			firstX = tmpX;
			firstY = tmpY;
		}
		else{
			firstX = tmpX / 2;
			firstY = tmpY;
		}
	}
}

bool CStage::freeDrop(){
	WAY way = NONE;

	Cdrop->freeDrop();
	Cdrop->checkKey('s');
	way = checkDropToStage(way);
	if (way == NONE){ return false; }
	move(way);
	return true;
}
/*
WAY way = NONE;
way = Cdrop->checkMove(key);
way = checkDropToStage(way);
move(way);
*/