#pragma once
/*
INCLUDE
*/
#include "Common.h"
#include "randC.h"


/* makeC�g 2014/3/28
�����_���N���X-randC���p��

���l:
*/
class Random:public randC{
public:
	Random();				//�f�t�H���g�Őݒ�p�R���X�g���N�^
	Random(int min,int max);//�����Őݒ�p�R���X�g���N�^
	~Random();				//�f�X�g���N�^
};

