#pragma once
#ifndef OTHER_H
#define OTHER_H
#include<iostream>
#include<cstdio>
#include<fstream>
#include<cmath>
#include<algorithm>
#include<string.h>
#include<cstring>
#include<string>
#include<time.h>
#include<ctime>
#include<Windows.h>
#include<wchar.h>
#include<locale.h>
#include<conio.h> 
#define STUDENT_FILE "Student.So_noSlack"
#define TEACHER_FILE "Teacher.So_noSlack"
#define MANAGER_FILE "Manager.So_noSlack"
#define JOURNAL_FILE "Journal.So_noSlack"
#define SCORE_FILE   "Score.So_noSlack"
#define QUESTION_FILE "Question.So_noSlack"
#define LATE "Record of being late.So_noSlack"
#define H_LATE "Historical latecomers.So_noSlack"
#define LOG_FILE "Log.So_noSlack"
#define BLACK_FILE "Black.So_noSlack"
#define INIT_FILE "Init.So_noSlack"
using namespace std;

class Other {

public:

	// ҳ������ 
	void SetWindowStyle(bool, bool);

	// �����ҳ��
	void Inter_Face(bool);

	// ����ϵͳ��ҳ�� 
	void Quantitative_Inter_Face(bool);

	// �ٵ��۷�ϵͳ��ҳ��
	void Late_Inter_Face(bool);

	// ���������ҳ��
	void Game_Inter_Face(bool);

	// ����汾��¼
	void Colophon_Software(bool);

	//  ����ϵͳ�汾��¼ 
	void Colophon_Score(bool);

	// �ٵ��۷�ϵͳ�汾��¼
	void Colophon__Late(bool);

	// ��������汾��¼
	void Colophon_Game(bool);

	// �����Ȩ
	void Copyright(bool);

	// ʹ��ϸ��
	void Service_Instruction(bool);

	// �Ƿ���С������
	bool Check(int);

	// С������ҳ
	void Black(string, bool);

};

#endif