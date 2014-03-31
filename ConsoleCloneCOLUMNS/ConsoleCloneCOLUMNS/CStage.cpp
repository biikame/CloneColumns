#include "CStage.h"
using namespace MakeCto;

/*	makeCト 2014/3/28
コンストラクタ

引数:無し
戻り値:無し
備考:
	m_cellのオブジェクトを定義 中身は、CCell<int>の配列のオブジェクト
	m_dropのオブジェクトを定義 中身は、CDropのクラスのオブジェクト
	m_jewelのオブジェクトを定義 中身は、CJewelのクラスのオブジェクト
	randomのオブジェクトを定義 中身は、Randomのクラスのオブジェクト
*/
CStage::CStage():
firstX(0), firstY(0), recursiveData(SPACE), deleteCounter(0), deleteflag(false){
	m_cell = new CCell<BLOCKDATA>(defaultStageWidth, defaultStageHeight);
	m_cellRecursive = new CCell<bool>(defaultStageWidth, defaultStageHeight);
	m_drop = new CDrop;
	m_jewel = new CJewel;
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
	delete m_cell;
	delete m_cellRecursive;
	delete m_drop;
	delete m_jewel;
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

	int dropNum = m_drop->getdropNumber();

	for (int y = 0; y < dropNum; y++){
		BLOCKDATA numOfRand = (BLOCKDATA)random->getRand();
		m_jewel->setJewelColor(numOfRand);

		BLOCKDATA jewelColor = (BLOCKDATA)m_jewel->getJewelColor();
		m_drop->setDrop(0,y,jewelColor);
	}
}


/*	makeCト 2014/3/28
ステージにセットする

引数:無し
戻り値:無し
備考:

*/
void CStage::initStage(){
	int width = m_cell->getSizeX();
	int height = m_cell->getSizeY();

	for (int y = 0; y < height; y++){
		for (int x = 0; x < width; x++){
			if (x == 0 || x == (width - 1) ||
				y == (height - 1)){
					m_cell->set(x, y, BLOCK);
			}
			else{
				m_cell->set(x, y, SPACE);
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
	int width = m_drop->getWidth();
	int height = m_drop->getHeight();

	for (int y = 0; y < height; y++){
		for (int x = 0; x < width; x++){
			BLOCKDATA drop = m_drop->getdrop(x, y);
			m_cell->set((x+firstX), (y+firstY), drop);
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

	initCellRecursive();				//再帰用配列の初期化

	setDropOnJewel();					//落下物に宝石をセット

	setFirstPoint();					//初期位置の座標をセット

	m_drop->setPosition(firstX, firstY);	//落下物の座標を初期化

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
	
	int width = m_cell->getSizeX();
	int height = m_cell->getSizeY();
	int dammyHeight = m_drop->getDammyHeight();
	for (int y = 0; y < height; y++){
		for (int x = 0; x < width; x++){

			switch (m_cell->get(x, y)){
			case SPACE:	
				m_console.setCursorPosition(x*2, y);
				m_console.setColor(0, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
				cout << "　"; break;
			case BLOCK:	
				m_console.setCursorPosition(x * 2, y);
				m_console.setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE , BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
				cout << "□"; break;
			case RED:
				m_console.setCursorPosition(x * 2, y);
				m_console.setColor(FOREGROUND_RED | FOREGROUND_INTENSITY, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
				cout << "●"; break;
			case YELLOW: 
				m_console.setCursorPosition(x * 2, y);
				m_console.setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
				cout << "●";
				break;
			case GREEN:
				m_console.setCursorPosition(x * 2, y);
				m_console.setColor(FOREGROUND_GREEN | FOREGROUND_GREEN | FOREGROUND_INTENSITY, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
				cout << "●";
				break;
			case BLUE:
				m_console.setCursorPosition(x * 2, y);
				m_console.setColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
				cout << "●";
				break;
			case ORANGE:
				m_console.setCursorPosition(x * 2, y);
				m_console.setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
				cout << "●";
				break;
			case PERPLE:
				m_console.setCursorPosition(x * 2, y);
				m_console.setColor(FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
				cout << "●";
				break;
			case ERROR_B:
				m_console.setCursorPosition(x * 2, y);
				m_console.setColor(0,0);
				cout << "エ";
				break;
			default:
				m_console.setCursorPosition(x * 2, y);
				m_console.setColor(0, 0); 
				cout << "？";
				break;
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
	
	m_drop->checkKey(key);
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
	int dropX = m_drop->getX(), dropY = m_drop->getY();
	int dX = m_drop->getDx(), dY = m_drop->getDy();
	int x = m_drop->getX(), y = m_drop->getY();
	int dropNumber = m_drop->getdropNumber();
	int nextX = dropX + dX, nextY = dropY + dY;
	int stageWidth = m_cell->getSizeX(), stageHeight = m_cell->getSizeY();

	if (dX != 0){
		if (dX >0){//LEFT
			for (int i = 0; i < dropNumber; i++){
				int nextX = x + dX, nextY = y + dY + i;
				if (1 > nextX || nextX >= (stageWidth - 1) ||
					1 > nextY || nextY >= (stageHeight - 1)||
					m_cell->get(nextX,nextY) != SPACE){

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
					m_cell->get(nextX, nextY) != SPACE){

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
				m_cell->get(nextX, nextY) != SPACE){

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
				m_cell->get(nextX, nextY) != SPACE){

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

	int dropX = m_drop->getX(), dropY = m_drop->getY();
	int dX = m_drop->getDx(), dY = m_drop->getDy();
	int nextX = dropX + dX, nextY = dropY + dY;
	int dropNum = m_drop->getdropNumber();

	switch (way){
	case UP:
		for (int i = 0; i < dropNum; i++){
			m_cell->swap(nextX, nextY + i, dropX, dropY + i);
		}
		m_drop->setX(nextX), m_drop->setY(nextY);
		break;
	case DOWN:
		for (int i = (dropNum - 1); i >= 0; i--){
			m_cell->swap(nextX, nextY + i, dropX, dropY + i);
		}
		m_drop->setX(nextX), m_drop->setY(nextY);
		break;
	case LEFT:
		for (int i = 0; i < dropNum; i++){
			m_cell->swap(nextX, nextY + i, dropX, dropY + i);
		}
		m_drop->setX(nextX), m_drop->setY(nextY);
		break;
	case RIGHT:
		for (int i = 0; i < dropNum; i++){
			m_cell->swap(nextX, nextY + i, dropX, dropY + i);
		}
		m_drop->setX(nextX), m_drop->setY(nextY);
		break;
	case NONE:
		m_drop->setX(dropX), m_drop->setY(dropY);
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

	int tmpX = m_cell->getSizeX();
	int tmpY = m_drop->getDammyHeight();

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

	m_drop->freeDrop();
	m_drop->checkKey('s');
	way = checkDropToStage(way);
	if (way == NONE){ return false; }
	move(way);
	return true;
}
/*
WAY way = NONE;
way = m_drop->checkMove(key);
way = checkDropToStage(way);
move(way);
*/


void CStage::deleteCheck(){
	int width = m_cell->getSizeX();
	int height = m_cell->getSizeY();

	for (int y = height-1; y >= 0; y--){
		for (int x = 0; x < width; x++){
			deleteCounter = 0;
			recursiveData = m_cell->get(x, y);

			if (recursiveData != SPACE && recursiveData != BLOCK){
				if (recursiveBlock(x, y, -1, 0)){ m_cellRecursive->set(x, y, true); deleteCounter = 0; };		//左
				if (recursiveBlock(x, y, -1, -1)){ m_cellRecursive->set(x, y, true); deleteCounter = 0; };		//左上
				if (recursiveBlock(x, y, 0, -1)){ m_cellRecursive->set(x, y, true); deleteCounter = 0; };		//上
				if (recursiveBlock(x, y, 1, -1)){ m_cellRecursive->set(x, y, true); deleteCounter = 0; };		//右上
				if (recursiveBlock(x, y, 1, 0)){ m_cellRecursive->set(x, y, true); deleteCounter = 0; };		//右
				if (recursiveBlock(x, y, 1, 1)){ m_cellRecursive->set(x, y, true); deleteCounter = 0; };		//右下
				if (recursiveBlock(x, y, 0, 1)){ m_cellRecursive->set(x, y, true); deleteCounter = 0; };		//下
				if (recursiveBlock(x, y, -1, 1)){ m_cellRecursive->set(x, y, true); deleteCounter = 0; };		//左下
			}
		}
	}
}

bool CStage::recursiveBlock(int x, int y, int dX, int dY){

	int sizeX = m_cell->getSizeX();
	int sizeY = m_cell->getSizeY();

	int nextX = x + dX;
	int nextY = y + dY;

	if (0 >= nextX || nextX >= sizeX || 0 >= nextY || nextY >= sizeY)return false;

	BLOCKDATA nextRecursive = m_cell->get(nextX, nextY);
	
	if (nextRecursive != recursiveData){
		return false;
	}
	else if (nextRecursive == recursiveData){
		deleteCounter++;

		recursiveBlock(nextX, nextY, dX, dY);
	}
	if (deleteCounter >= 2){ 
		m_cellRecursive->set(x, y, true);
		deleteflag = true;
		return true;
	}
	
	//deleteflag = false;
	deleteCounter = 0;
	return false;
}


/*	makeCト 2014/3/28
再帰用のステージ初期化する

引数:無し
戻り値:無し
備考:
*/
void CStage::initCellRecursive(){
	int width = m_cellRecursive->getSizeX();
	int height = m_cellRecursive->getSizeY();

	for (int y = 0; y < height; y++){
		for (int x = 0; x < width; x++){
			m_cellRecursive->set(x, y, false);
		}
	}
}


void CStage::deleteBlock(){
	
	int width = m_cellRecursive->getSizeX();
	int height = m_cellRecursive->getSizeY();

	for (int y = 0; y < height; y++){
		for (int x = 0; x < width; x++){
			if (m_cellRecursive->get(x,y) == true){

				m_cell->set(x, y, SPACE);
			}
		}
	}
}
void CStage::updateStage(){
	
	int width = m_cellRecursive->getSizeX();
	int height = m_cellRecursive->getSizeY();

	for (int y = height-1; y >= 0; y--){
		for (int x = 1; x < (width-1); x++){
			if (m_cell->get(x, y) == SPACE){
				recursiveStage(x, y, 0, -1);
			}
		}
	}
}

void CStage::recursiveStage(int x, int y, int dX, int dY){

	int sizeX = m_cell->getSizeX();
	int sizeY = m_cell->getSizeY();
	int nextX = x + dX;
	int nextY = y + dY;

	if (0 >= nextX || nextX >= sizeX || 0 >= nextY || nextY >= sizeY)return;

	BLOCKDATA nextRecursive = m_cell->get(nextX, nextY);

	recursiveStage(nextX, nextY, dX, dY);

	m_cell->set(x, y, nextRecursive);
}

void CStage::recursive(){

	deleteCheck();
	deleteBlock();
	initCellRecursive();
}


bool CStage::clear(){
	int sizeX = m_cell->getSizeX();
	int sizeY = m_cell->getSizeY();
	int DammyHeight = m_drop->getDammyHeight();

	for (int y = 0; y < DammyHeight; y++){
		for (int x = 1; x < (sizeX-1); x++){
			if (RED <= m_cell->get(x, y) && m_cell->get(x, y) <= PERPLE){
				return false;
			}
		}
	}
	for (int y = 0; y < (sizeY-1); y++){
		for (int x = 1; x < (sizeX - 1); x++){
			
		}
	}
	return true;
}