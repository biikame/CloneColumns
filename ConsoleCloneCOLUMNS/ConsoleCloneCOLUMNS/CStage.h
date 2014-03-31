#pragma once
#include "CCell.h"
#include "CDrop.h"
#include "Jewel.h"
#include "Random.h"
#include "Common.h"
#include "CConsole.h"
namespace MakeCto{
	/*	makeC�g 2014/3/28
	�X�e�[�W�N���X

	���l:
	Jewel Random CDrop �́A�����Ŏ��Ԃ�����
	stage�̔z��̎��Ԃ͂����ō쐬��CStage�������̃��C���ŏ������Ǝv���Ă܂�
	�܂菈����CStage�ł��ׂčς܂���B
	*/

	class CStage{
	private:
		
		CCell<BLOCKDATA>* m_cell;	//�X�e�[�W�̃I�u�W�F�N�g�B���Ԃ�CCellint�^�̔z��
		CCell<bool>* m_cellRecursive;//�X�e�[�W�̃I�u�W�F�N�g�B���Ԃ�CCellbool�^�̔z��
		CDrop* m_drop;				//CDrop�N���X�̃I�u�W�F�N�g�B���Ԃ�CDrop�N���X�{��
		CJewel* m_jewel;			//CJewel�N���X�̃I�u�W�F�N�g�B���Ԃ�CJewel�N���X�{��
		Random* random;				//Random�N���X�̃I�u�W�F�N�g�B���Ԃ�Radom�N���X�{��
		CConsole m_console;			//
		int firstX, firstY;			//x,y�̍ŏ��\���|�C���g
		BLOCKDATA recursiveData;	//�ċA�p�f�[�^
		int deleteCounter;			//�f���[�g�̐��p
		bool deleteflag;			
	public:
		CStage();					//�R���X�g���N�^
		~CStage();					//�f�X�g���N�^

		void init();				//init�n���܂Ƃ߂Ă���
		void draw();				//�\��
		void move(WAY way);			//�ړ�
		bool checkMove(int key);	//�ړ��ł��邩�`�F�b�N	
		WAY checkDropToStage(WAY& way);	//�X�e�[�W�Ɨ������̃`�F�b�N
		//Drap�ɕ�΂̃Z�b�g
		void setDropOnJewel();		//�������ɕ�΂��Z�b�g����

		void initStage();			//�X�e�[�W�̏�����

		void setDropOnStage();		//���������X�e�[�W�ɃZ�b�g����

		void setFirstPoint();		//�����ʒu�ݒ�p

		bool freeDrop();			//���R����

		void deleteCheck();			//��������

		bool recursiveBlock(int x, int y, int dX, int dY);		//�ċA�I�Ɋm�F

		void initCellRecursive();

		void deleteBlock();
		void updateStage();

		void recursiveStage(int x, int y, int dX, int dY);

		void recursive();

		bool getDeleteflag(){return deleteflag; }
		void setDeleteflag(bool flag){ deleteflag = flag; }

		bool clear();
	};
}