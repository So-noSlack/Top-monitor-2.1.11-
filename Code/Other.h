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

	// 页面设置 
	void SetWindowStyle(bool, bool);

	// 软件主页面
	void Inter_Face(bool);

	// 量化系统主页面 
	void Quantitative_Inter_Face(bool);

	// 迟到扣分系统主页面
	void Late_Inter_Face(bool);

	// 服务大厅主页面
	void Game_Inter_Face(bool);

	// 软件版本记录
	void Colophon_Software(bool);

	//  量化系统版本记录 
	void Colophon_Score(bool);

	// 迟到扣分系统版本记录
	void Colophon__Late(bool);

	// 服务大厅版本记录
	void Colophon_Game(bool);

	// 软件版权
	void Copyright(bool);

	// 使用细则
	void Service_Instruction(bool);

	// 是否在小黑屋中
	bool Check(int);

	// 小黑屋主页
	void Black(string, bool);

};

#endif