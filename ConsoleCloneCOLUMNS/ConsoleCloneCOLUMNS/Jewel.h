#pragma once


/*	makeCト 2014/3/28
宝石クラス

備考:
	宝石の色を持つだけのクラス
	set getのみ
*/
class CJewel{
private:
	typedef enum _JEWELDATA{
		RED,
		YELLOW,
		GREEN,
		BLUE,
		ORANGE,
		PERPLE,
	}JEWELDATA;

	JEWELDATA color;													//宝石の色データ
public:
	CJewel();
	~CJewel();

	//書けないのか？　setJewelColorでの　=用に書いたけど使えないっぽい？引っ張った先のクラスでしか意味無い？mainとか
	//CJewel& operator=(int argument){
	//	color = (JEWELDATA)argument;
	//	return *this;
	//}
	
	
	void setJewelColor(int setColor);	//宝石の色データをセット
	int getJewelColor();				//宝石の色データを取得
};

