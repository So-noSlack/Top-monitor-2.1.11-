#pragma once
#ifndef MANAGER_H
#define MANAGER_H
#include"Other.h"

class Manager {

public:

	// �����ҳ�� 
	void Inter_Face(string, bool, int);

	// �޸����� 
	void Modified_Quantification(bool, int);

	// �鿴��־
	void View_Log(bool);

	// �鿴�˺�
	void View_Account(bool);

	// �鿴���� 
	void View_The_Rankings(bool);

	// ��������
	void Export_Data(bool);

	// �ָ���ʼ������
	void Restore_Initialization(bool);

	// �鴦�˺�
	void Investigate_Account(bool, int);

	// ������Կ
	void Set_Key(bool);

};

#endif