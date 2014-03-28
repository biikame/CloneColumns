#include "CStage.h"


/*	makeC�g 2014/3/28
�R���X�g���N�^

����:����
�߂�l:����
���l:
	stage�̃I�u�W�F�N�g���` ���g�́ACCell<int>�̔z��̃I�u�W�F�N�g
	Cdrop�̃I�u�W�F�N�g���` ���g�́ACDrop�̃N���X�̃I�u�W�F�N�g
	Cjewel�̃I�u�W�F�N�g���` ���g�́ACJewel�̃N���X�̃I�u�W�F�N�g
	random�̃I�u�W�F�N�g���` ���g�́ARandom�̃N���X�̃I�u�W�F�N�g
*/
CStage::CStage(){
	stage = new CCell<int>(defaultStageWidth, defaultStageHeight);
	Cdrop = new CDrop;
	Cjewel = new CJewel;
	random = new Random;
}


/*	makeC�g 2014/3/28
�f�X�g���N�^

����:����
�߂�l:����
���l:
	�I�u�W�F�N�g���폜
*/
CStage::~CStage(){
	delete stage;
	delete Cdrop;
	delete Cjewel;
	delete random;
}


/*	makeC�g 2014/3/28
�������I�u�W�F�N�g���΂̐F������ăZ�b�g

����:����
�߂�l:����
���l:
	�����_���ŕԂ��Ă����l���΂̐F�Ƃ���jewel�N���X��color�f�[�^�����o�ɃZ�b�g���āA
	������擾���ăZ�b�g�����3��J��Ԃ�

	CDrop�Ƀ����_���̔z��𓊂��Ă�낤���Ǝv�������ǂ��A�ǂ������݌v�I�ɂ��������f���ɂ����B
	�ꉞ�f�[�^����œ����āA���Ԃ��쐬���Ă��邱���Ń��[�v������ׂ����Ȃ��[��
	��������g���܂킵�s�����������A�Ƃ��A������CDrop��dropNumber�������Ă邵�c
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

/*	makeC�g 2014/3/28
�X�e�[�W�ɃZ�b�g����

����:����
�߂�l:����
���l:

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
/*	makeC�g 2014/3/28
���������X�e�[�W�ɃZ�b�g����

����:����
�߂�l:����
���l:

*/
void CStage::setDropOnStage(){
	
}

/*	makeC�g 2014/3/28
init�܂Ƃ� 

����:����
�߂�l:����
���l:
	�܂Ƃ߂ČĂяo���p
*/
void CStage::init(){

	initStage();			//�X�e�[�W�̏�����

	setDropOnJewel();		//�������̃Z�b�g

	Cdrop->setPosition();	//�������̍��W��������

}