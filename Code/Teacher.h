#pragma once
#ifndef TEACHER_H
#define TEACHER_H
#include"Other.h"

class Teacher {

public:

	// ��ʦ��ҳ�� 
	void Inter_Face(string, string, bool);

	// �޸����� 
	void Modified_Quantification(string, bool);

	// �鿴���� 
	void View_The_Rankings(bool);

	// �鿴��־
	void View_Log(bool);

	// �鿴�˺�
	void View_Account(bool);

	// ��������
	void Export_Data(bool);

	// �鿴���� 
	void View_Questions(string, bool);

};

#endif