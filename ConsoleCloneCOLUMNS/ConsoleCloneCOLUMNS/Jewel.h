#pragma once
#include "Common.h"

namespace  MakeCto{
	/*	makeC�g 2014/3/28
	��΃N���X

	���l:
	��΂̐F���������̃N���X
	set get�̂�
	*/
	class CJewel{
	private:
		BLOCKDATA color;													//��΂̐F�f�[�^
	public:
		CJewel();
		~CJewel();

		void setJewelColor(BLOCKDATA setColor);	//��΂̐F�f�[�^���Z�b�g
		BLOCKDATA getJewelColor();				//��΂̐F�f�[�^���擾
	};

}