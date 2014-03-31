#include "Jewel.h"
using namespace MakeCto;


/* makeCト 2014/3/28
コンストラクタ
引数:無し
戻り値:無し
備考:
*/
CJewel::CJewel(){
}

/* makeCト 2014/3/28
デストラクタ
引数:無し
戻り値:無し
備考:
*/
CJewel::~CJewel(){
}


/*	makeCト 2014/3/28
宝石の色を設定する

引数:
	int setColor
戻り値:無し
備考:
*/
void CJewel::setJewelColor(BLOCKDATA setColor){
	if (RED <= setColor && setColor <= PERPLE){
		color = setColor;
	}
	else{
		throw "setJewelColor:無い色の宝石をセットしようとしました";
	}
}


/*	makeCト 2014/3/28
宝石の色を取得する

引数:無し
戻り値:無し
備考:
*/
BLOCKDATA CJewel::getJewelColor(){
	if (RED <= color && color <= PERPLE){
		return color;
	}
	else{
		throw "getJewelColor:無い色の宝石をゲットしようとしました";
	}
	return ERROR_B;
}