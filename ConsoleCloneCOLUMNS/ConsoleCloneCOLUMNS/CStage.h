#pragma once
#include "CCell.h"
#include "CDrop.h"
#include "Jewel.h"
#include "Random.h"

/*	makeC�g 2014/3/28
�X�e�[�W�N���X

���l:
	Jewel Random CDrop �́A�����Ŏ��Ԃ�����
	stage�̔z��̎��Ԃ͂����ō쐬��CStage�������̃��C���ŏ������Ǝv���Ă܂�
	�܂菈����CStage�ł��ׂčς܂���B
*/
class CStage{
private:
	CCell<int>* stage;			//�X�e�[�W�̃I�u�W�F�N�g�B���Ԃ�CCellint�^�̔z��
	CDrop* Cdrop;				//CDrop�N���X�̃I�u�W�F�N�g�B���Ԃ�CDrop�N���X�{��
	CJewel* Cjewel;				//CJewel�N���X�̃I�u�W�F�N�g�B���Ԃ�CJewel�N���X�{��
	Random* random;				//Random�N���X�̃I�u�W�F�N�g�B���Ԃ�Radom�N���X�{��
public:
	CStage();					//�R���X�g���N�^
	~CStage();					//�f�X�g���N�^

	void init();				//init�n���܂Ƃ߂Ă���
	//Drap�ɕ�΂̃Z�b�g
	void setDropOnJewel();		//�������ɕ�΂��Z�b�g����
	
	void initStage();			//�X�e�[�W�̏�����

	void setDropOnStage();		//���������X�e�[�W�ɃZ�b�g����


};

