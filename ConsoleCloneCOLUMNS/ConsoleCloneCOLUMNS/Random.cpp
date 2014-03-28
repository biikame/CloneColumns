#include "Random.h"


/* makeCト 2014/3/28
コンストラクタ

引数:無し
戻り値:無し
備考:
	Common.hにあるデフォルトデータで設定
*/
Random::Random(){//:randC(minRand, maxRand) 書いてももいいし書かなくても。

}


/* makeCト 2014/3/28
引数つきコンストラクタ

引数:
	int min: ランダムで得られる最小値
	int max: ランダムで得られる最大値
戻り値:無し
備考:
	randCの引数つきコンストラクタを呼んでデータを設定
*/
Random::Random(int min, int max) :randC(min,max){
}


/* makeCト 2014/3/28
デストラクタ

引数:無し
戻り値:無し
備考:
*/
Random::~Random()
{
}
