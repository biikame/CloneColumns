#pragma once


/*	makeC�g 2014/3/28
��΃N���X

���l:
	��΂̐F���������̃N���X
	set get�̂�
*/
class CJewel{
private:
	typedef enum _JEWELDATA{
		RED,
		YELLOW,
		GREEN,
		BLUE,
		ORANGE,
		PERPLE,
	}JEWELDATA;

	JEWELDATA color;													//��΂̐F�f�[�^
public:
	CJewel();
	~CJewel();

	//�����Ȃ��̂��H�@setJewelColor�ł́@=�p�ɏ��������ǎg���Ȃ����ۂ��H������������̃N���X�ł����Ӗ������Hmain�Ƃ�
	//CJewel& operator=(int argument){
	//	color = (JEWELDATA)argument;
	//	return *this;
	//}
	
	
	void setJewelColor(int setColor);	//��΂̐F�f�[�^���Z�b�g
	int getJewelColor();				//��΂̐F�f�[�^���擾
};

