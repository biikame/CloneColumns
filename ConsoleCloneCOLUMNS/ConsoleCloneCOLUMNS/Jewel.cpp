#include "Jewel.h"
using namespace MakeCto;


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
void CJewel::setJewelColor(BLOCKDATA setColor){
	if (RED <= setColor && setColor <= PERPLE){
		color = setColor;
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
BLOCKDATA CJewel::getJewelColor(){
	if (RED <= color && color <= PERPLE){
		return color;
	}
	else{
		throw "getJewelColor:�����F�̕�΂��Q�b�g���悤�Ƃ��܂���";
	}
	return ERROR_B;
}