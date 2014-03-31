#pragma once 
#include "Common.h"


namespace MakeCto{
	/*	makeC�g 2014/3/28
	�ς���z��N���X

	���l:
	get set init swap�Œ���̋@�\����B
	cell�f�[�^���̂��O�ɏo���Ȃ��悤�ɂ��Ĉ����B
	*/
	template<class T>
	class CCell{
	private:
		T* cell;				//T�^�̂Ȃ�ł��Ή��o����p
		int sizeX, sizeY;		//T�^�̃T�C�Y�p
	public:
		/*	makeC�g 2014/3/28
		�R���X�g���N�^

		����:����
		�߂�l:����
		���l:
		�����t���R���X�g���N�^�͉ϗp�Ȃ̂�
		�����ŏ�����
		*/
		CCell(int XSizeSet, int YSizeSet) :
			sizeX(XSizeSet), sizeY(YSizeSet){
			cell = new T[sizeX * sizeY];
		};
		/*	makeC�g 2014/3/28
		�R���X�g���N�^

		����:����
		�߂�l:����
		���l:
		cell�f�[�^��new����B
		�f�t�H�̏ꍇ��m_ommon.h�̃f�[�^�ŏ�����
		*/
		CCell() :
			sizeX(maxX), sizeY(maxY){
			cell = new T[sizeX * sizeY];
		};
		/*	makeC�g 2014/3/28
		�f�X�g���N�^

		����:����
		�߂�l:����
		���l:
		new���ꂽcell�f�[�^�̍폜
		*/
		~CCell(){
			delete[] cell;
		}
		/*	makeC�g 2014/3/28
		cell�̃f�[�^�̑��

		����: �@
		T* ArgumentCell T�^�̃|�C���^
		�߂�l:����
		���l:
		cell��x,y��data���擾
		*/
		void init(T* ArgumentCell){

			int arraySize = maxX * maxY;

			for (int i = 0; i < arraySize; i++){
				cell[i] = ArgumentCell[i];
			}
		}
		/*	makeC�g 2014/3/28
		cell�̃f�[�^�Q�b�g

		����:
		int x,int y,
		�߂�l:T�^�e���v���[�g
		���l:
		cell��x,y��data���擾
		*/
		T get(int x, int y){
			if (0 <= x && x < sizeX && 0 <= y && y < sizeY){
				return cell[y * sizeX + x];
			}
			else{
				throw "get:�͈͊O�ɃA�N�Z�X���Ă��܂�";
			}
			return ERROR_B;
		}
		/*	makeC�g 2014/3/28
		cell�̃f�[�^�Z�b�g

		����:
		int x,int y,T value�@
		�߂�l:����
		���l:
		�f�[�^���Z�b�g����
		cell��x,y�̈ʒu��value������
		*/
		void set(int x, int y, T value){
			if (0 <= x && x < sizeX && 0 <= y && y < sizeY){
				cell[y * sizeX + x] = value;
			}
			else{
				throw "set:�f�[�^�Z�b�g�~�X";
			}
		}
		/*	makeC�g 2014/3/28
		cell�̃f�[�^������

		����:
		int xa,int ya, �������x,y
		int xb,int yb, �������x,y
		�߂�l:����
		���l:
		xa,ya��cell�f�[�^��xb,yb��cell�f�[�^����������
		*/
		void swap(int xa, int ya, int xb, int yb){
			T c = cell[ya * sizeX + xa];
			T d = cell[yb * sizeX + xb];

			set(xa, ya, d);
			set(xb, yb, c);
		}

		int getSizeX(){ return sizeX; }			//�X�e�[�W�T�C�YX���擾
		int getSizeY(){ return sizeY; }			//�X�e�[�W�T�C�YY���擾
	};
}