#pragma once
#include "CCell.h"

namespace MakeCto{
	/*	makeC�g 2014/3/28
	�������N���X

	����: ����
	�߂�l:����
	���l:
	cell�f�[�^��new����B
	�f�t�H�̏ꍇ��m_ommon.h�̃f�[�^�ŏ�����
	*/
	class CDrop{
	private:

		CCell<BLOCKDATA>* m_cell;							//�������̃I�u�W�F�N�g�B���Ԃ�CCellint�^�̔z��

		int x, y;										//�������̍��W
		int dX, dY;										//����
		int state, timer;								//��ԁA�^�C�}�[

		const int width, height;						//width,height�̒l�A�f�[�^
		const int stageWidth, stageHeight;				//stage width,height�̒l�A�f�[�^
		const int dropNumber;							//�������̔z��̐�
		const int dammyHeight;							//y���W�̔z��_�~�[����
	public:
		CDrop();										//�R���X�g���N�^
		CDrop(int x, int y);							//�R���X�g���N�^
		~CDrop();										//�f�X�g���N�^

		void setX(int argX){ x = argX; }				//x���W�̃Z�b�g
		void setY(int argY){ y = argY; }				//y���W�̃Z�b�g

		int getX(){ return x; }							//x���W���擾
		int getY(){ return y; }							//y���W���擾
		int getWidth(){ return width; }					//width���擾
		int getHeight(){ return height; }				//height���擾
		int getDx(){ return dX; }						//�ړ�����dX�擾�p
		int getDy(){ return dY; }						//�ړ�����dY�擾�p
		void timerPuls(){ timer++; }					//�^�C�}�[����
		int getTimer(){ return timer; }					//�^�C�}�[�̎擾
		void setTimer(int time){ timer = time; }		//�^�C�}�[�̃Z�b�g
		int getDammyHeight(){ return dammyHeight; }		//dammyHeight���擾

		void setDrop(int x, int y, BLOCKDATA value);	//��΂̃f�[�^�𗎂����ɓ����

		void setPosition(int x, int y);					//���W���Z�b�g

		int getdropNumber();							//�������̐����擾

		BLOCKDATA getdrop(int x, int y);				//CCell�f�[�^���擾

		int checkKey(int key);							//���L�[�������ꂽ���Ԃ�

		void freeDrop();								//���R����
	};
}