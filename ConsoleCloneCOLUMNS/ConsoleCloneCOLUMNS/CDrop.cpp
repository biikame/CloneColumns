#include "CDrop.h"
using namespace MakeCto;


/*	makeC�g 2014/3/28
�R���X�g���N�^

����:����
�߂�l:����
���l:
	�ړ��A������0�ŏ��������Ă����Č�ɏo�Ă���init�ōŃZ�b�g
	���������R���X�g���N�^�̓f�t�H�l�Ȃ̂ŁA
	m_ommon.h�̃f�[�^�ŏ�����
	m_cell�̃I�u�W�F�N�g(����)���` ���g�́ACCellint�^�̔z��f�[�^�@
*/
CDrop::CDrop() :
x(0), y(0), dX(0), dY(0), dammyHeight(defaultDammyHeight),
width(defaultDropWidth), height(defaultDropHeight),
stageWidth(defaultStageWidth), stageHeight(defaultStageHeight),
state(INIT), timer(0), dropNumber(defaultDropHeight){
	
	m_cell = new CCell<BLOCKDATA>(width, height);
}


CDrop::CDrop(int dropX,int dropY) :
x(0), y(0), dX(0), dY(0), dammyHeight(defaultDammyHeight),
width(dropX), height(dropY),
stageWidth(defaultStageWidth), stageHeight(defaultStageHeight),
state(INIT), timer(0), dropNumber(defaultDropHeight){

	m_cell = new CCell<BLOCKDATA>(width, height);
}


/*	makeC�g 2014/3/28
�f�X�g���N�^

����:����
�߂�l:����
���l:
	m_cell�̃I�u�W�F�N�g(����)���폜
*/
CDrop::~CDrop(){
	delete m_cell;
}


/*	makeC�g 2014/3/28
�������̔z��ɕ�΂��Z�b�g����

����:int value:�����F�f�[�^�p
�߂�l:����
���l:
	m_cell�̔z��f�[�^�ɕ�΂̐F�f�[�^������
*/
void CDrop::setDrop(int x, int y, BLOCKDATA value){

	if (0 <= x && x <= width && 0 <= y && y <= height){
		m_cell->set(x, y, value);
	}
	else{
		throw "setDrop:x,y�̒l���͈͊O���w���Ă��܂��B";
	}
}


/*	makeC�g 2014/3/28
�������̍��W��������

����:
�߂�l:����
���l:
*/
void CDrop::setPosition(int x, int y){

	//�����ʒu�Z�b�g
	setX(x);
	setY(y);
	
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
	return ERR;
}


/*	makeC�g 2014/3/29
�������̃f�[�^���擾�p 

����:
�߂�l:����
���l:
	CStage����m_cell�͌ĂׂȂ��̂Ŋ֐��ŌĂׂ�悤�ɂ���
*/
BLOCKDATA CDrop::getdrop(int x, int y){
	int sizeX = m_cell->getSizeX();
	int sizeY = m_cell->getSizeY();
	if (0 <= x && x < sizeX && 0 <= y && y < sizeY){
		return m_cell->get(x, y);
	}
	else {
		throw "getdrop:m_cell�z��͈̔͊O���w���Ă��܂��B�I�[�o�[�����ł���H";
	}
	return ERROR_B;
}


/*	makeC�g 2014/3/29
�������������邩�`�F�b�N

����:
�߂�l:WAY�@WAY�^��(�㉺���E)�͓���
���l:
CStage����m_cell�͌ĂׂȂ��̂Ŋ֐��ŌĂׂ�悤�ɂ���
*/
int CDrop::checkKey(int key){

	dX = dY = 0;//����������

	switch (key){
	case 'a':dX--; break;
	case 'd':dX++; break;
	case 'w':dY--; break;
	case 's':dY++; break;
	}
	return 0;
}


/*	makeC�g 2014/3/29
�����������R�������鏈��

����:
�߂�l:
���l:
	
*/
void CDrop::freeDrop(){
	_sleep(300);
}