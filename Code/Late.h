#pragma once
#ifndef LATE_H
#define LATE_H
#include"Other.h"

class Late {

public:

	// ��ʼ��
	void Inter();

	//  �ٵ��ƴ� 
	int AddTime(int, int[], bool);

	//  չʾ�۷� 
	int ShowScore(int, bool);

	//  ��ѯ���� 
	void ShowDay(int, int, int, bool);

	//  ��ѯ�ٵ���¼ 
	int ShowHistory(int, bool);

	//  �汾��¼ 
	void Colophon(bool);

};

#endif