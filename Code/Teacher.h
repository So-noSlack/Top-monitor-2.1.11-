#pragma once
#ifndef TEACHER_H
#define TEACHER_H
#include"Other.h"

class Teacher {

public:

	// 教师端页面 
	void Inter_Face(string, string, bool);

	// 修改量化 
	void Modified_Quantification(string, bool);

	// 查看排名 
	void View_The_Rankings(bool);

	// 查看日志
	void View_Log(bool);

	// 查看账号
	void View_Account(bool);

	// 导出数据
	void Export_Data(bool);

	// 查看疑问 
	void View_Questions(string, bool);

};

#endif