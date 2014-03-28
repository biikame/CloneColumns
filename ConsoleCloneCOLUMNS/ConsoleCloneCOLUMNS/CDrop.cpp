#include "CDrop.h"


/*	makeC�g 2014/3/28
�R���X�g���N�^

����:����
�߂�l:����
���l:
	�ړ��A������0�ŏ��������Ă����Č�ɏo�Ă���init�ōŃZ�b�g
	���������R���X�g���N�^�̓f�t�H�l�Ȃ̂ŁA
	Common.h�̃f�[�^�ŏ�����
	drop�̃I�u�W�F�N�g(����)���` ���g�́ACCellint�^�̔z��f�[�^�@
*/
CDrop::CDrop() :
x(0), y(0), dX(0), dY(0), dammyHeight(defaultDammyHeight),
width(defaultDropWidth), height(defaultDropHeight),
state(INIT), timer(0), dropNumber(defaultDropHeight){
	drop = new CCell<int>(width, height);
}


/*	makeC�g 2014/3/28
�f�X�g���N�^

����:����
�߂�l:����
���l:
	drop�̃I�u�W�F�N�g(����)���폜
*/
CDrop::~CDrop(){
	delete drop;
}


/*	makeC�g 2014/3/28
�������̔z��ɕ�΂��Z�b�g����

����:int value:�����F�f�[�^�p
�߂�l:����
���l:
	drop�̔z��f�[�^�ɕ�΂̐F�f�[�^������
*/
void CDrop::setDrop(int value,int num){
	drop->set(0, num, value);
}


/*	makeC�g 2014/3/28
�������̍��W��������

����:
�߂�l:����
���l:
	x�f�[�^�͒��ԍ��W������
	y�f�[�^�����́A�ς��Ă��ʒu�͕ς��Ȃ�
*/
void CDrop::setPosition(){
	//�����ʒu�Z�b�g
	setX(width / 2);
	setY(dammyHeight);
}


/*	makeC�g 2014/3/28
�������̐����擾

����:
�߂�l:����
���l:
*/
int CDrop::getdropNumber(){
	if (0 < dropNumber && dropNumber < INT_MAX){
		return dropNumber;
	}
	else{
		throw "dropNumber�ɂ������ȃf�[�^�������Ă��܂�";
	}
	return -1;
}


/*	makeC�g 2014/3/29
�������̃f�[�^���擾�p 

����:
�߂�l:����
���l:
	CStage����drop�͌ĂׂȂ��̂Ŋ֐��ŌĂׂ�悤�ɂ���
*/
int CDrop::getdrop(int x, int y){
	drop->get(x,y);
	return -1;
}

