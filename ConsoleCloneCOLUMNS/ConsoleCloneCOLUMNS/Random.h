#pragma once
/*
INCLUDE
*/

#include "Common.h"

class Random
{
private:
public:
	Random();
	~Random();

	int getRand(int maxNum){ return rand() % maxNum; }	//npc�̃N���X�̒��ɓ���悤�����������ǁA���チ���Z���k����邩��p���B�t�@�C���킯�Ă���
};

