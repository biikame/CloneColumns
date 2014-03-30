#pragma once
#include "Common.h"

namespace  MakeCto{
	/*	makeCト 2014/3/28
	宝石クラス

	備考:
	宝石の色を持つだけのクラス
	set getのみ
	*/
	class CJewel{
	private:
		BLOCKDATA color;													//宝石の色データ
	public:
		CJewel();
		~CJewel();

		void setJewelColor(BLOCKDATA setColor);	//宝石の色データをセット
		BLOCKDATA getJewelColor();				//宝石の色データを取得
	};

}