#pragma once 
#include "Common.h"


namespace MakeCto{
	/*	makeCト 2014/3/28
	可変する配列クラス

	備考:
	get set init swap最低限の機能あり。
	cellデータ自体を外に出さないようにして扱う。
	*/
	template<class T>
	class CCell{
	private:
		T* cell;				//T型のなんでも対応出来る用
		int sizeX, sizeY;		//T型のサイズ用
	public:
		/*	makeCト 2014/3/28
		コンストラクタ

		引数:無し
		戻り値:無し
		備考:
		引数付きコンストラクタは可変用なので
		引数で初期化
		*/
		CCell(int XSizeSet, int YSizeSet) :
			sizeX(XSizeSet), sizeY(YSizeSet){
			cell = new T[sizeX * sizeY];
		};
		/*	makeCト 2014/3/28
		コンストラクタ

		引数:無し
		戻り値:無し
		備考:
		cellデータをnewする。
		デフォの場合はm_ommon.hのデータで初期化
		*/
		CCell() :
			sizeX(maxX), sizeY(maxY){
			cell = new T[sizeX * sizeY];
		};
		/*	makeCト 2014/3/28
		デストラクタ

		引数:無し
		戻り値:無し
		備考:
		newされたcellデータの削除
		*/
		~CCell(){
			delete[] cell;
		}
		/*	makeCト 2014/3/28
		cellのデータの代入

		引数: 　
		T* ArgumentCell T型のポインタ
		戻り値:無し
		備考:
		cellのx,yのdataを取得
		*/
		void init(T* ArgumentCell){

			int arraySize = maxX * maxY;

			for (int i = 0; i < arraySize; i++){
				cell[i] = ArgumentCell[i];
			}
		}
		/*	makeCト 2014/3/28
		cellのデータゲット

		引数:
		int x,int y,
		戻り値:T型テンプレート
		備考:
		cellのx,yのdataを取得
		*/
		T get(int x, int y){
			if (0 <= x && x < sizeX && 0 <= y && y < sizeY){
				return cell[y * sizeX + x];
			}
			else{
				throw "get:範囲外にアクセスしています";
			}
			return ERROR_B;
		}
		/*	makeCト 2014/3/28
		cellのデータセット

		引数:
		int x,int y,T value　
		戻り値:無し
		備考:
		データをセットする
		cellのx,yの位置にvalueを入れる
		*/
		void set(int x, int y, T value){
			if (0 <= x && x < sizeX && 0 <= y && y < sizeY){
				cell[y * sizeX + x] = value;
			}
			else{
				throw "set:データセットミス";
			}
		}
		/*	makeCト 2014/3/28
		cellのデータを交換

		引数:
		int xa,int ya, 交換先のx,y
		int xb,int yb, 交換先のx,y
		戻り値:無し
		備考:
		xa,yaのcellデータとxb,ybのcellデータを交換する
		*/
		void swap(int xa, int ya, int xb, int yb){
			T c = cell[ya * sizeX + xa];
			T d = cell[yb * sizeX + xb];

			set(xa, ya, d);
			set(xb, yb, c);
		}

		int getSizeX(){ return sizeX; }			//ステージサイズXを取得
		int getSizeY(){ return sizeY; }			//ステージサイズYを取得
	};
}