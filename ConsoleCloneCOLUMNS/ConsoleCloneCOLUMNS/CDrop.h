#pragma once
#include "CCell.h"


/*	makeC�g 2014/3/28
�������N���X

����: ����
�߂�l:����
���l:
cell�f�[�^��new����B
�f�t�H�̏ꍇ��Common.h�̃f�[�^�ŏ�����
*/
class CDrop{
private:
	CCell<int>* drop;					//�������̃I�u�W�F�N�g�B���Ԃ�CCellint�^�̔z��

	int x, y;							//�������̍��W
	int dX, dY;							//����
	int state, timer;					//��ԁA�^�C�}�[

	const int width, height;			//width,height�̒l�A�f�[�^
	const int dropNumber;				//�������̔z��̐�
	const int dammyHeight;				//y���W�̔z��_�~�[����
public:
	CDrop();							//�R���X�g���N�^
	~CDrop();							//�f�X�g���N�^

	void setX(int argX){ x = argX; }	//x���W�̃Z�b�g
	void setY(int argY){ y = argY; }	//y���W�̃Z�b�g

	int getX(){ return x; }				//x���W���擾
	int getY(){ return y; }				//y���W���擾

	void setDrop(int value,int num);	//��΂̃f�[�^�𗎂����ɓ����

	void setPosition();					//���W�̏�����

	int getdropNumber();				//�������̐����擾

	int getdrop(int x, int y);			//CCell�f�[�^���擾


};