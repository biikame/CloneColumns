#include "Jewel.h"

/* makeC�g 2014/3/28
�R���X�g���N�^
����:����
�߂�l:����
���l:
*/
CJewel::CJewel(){
}

/* makeC�g 2014/3/28
�f�X�g���N�^
����:����
�߂�l:����
���l:
*/
CJewel::~CJewel(){
}


/*	makeC�g 2014/3/28
��΂̐F��ݒ肷��

����:
	int setColor
�߂�l:����
���l:
*/
void CJewel::setJewelColor(int setColor){
	if (RED <= setColor && setColor <= PERPLE){
		color = (JEWELDATA)setColor;
	}
	else{
		throw "setJewelColor:�����F�̕�΂��Z�b�g���悤�Ƃ��܂���";
	}
}


/*	makeC�g 2014/3/28
��΂̐F���擾����

����:����
�߂�l:����
���l:
*/
int CJewel::getJewelColor(){
	if (RED <= color && color <= PERPLE){
		return (int)color;
	}
	else{
		throw "getJewelColor:�����F�̕�΂��Q�b�g���悤�Ƃ��܂���";
	}
	return -1;
}