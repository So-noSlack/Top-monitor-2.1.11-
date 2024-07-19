#pragma once
#ifndef STUDENT_H
#define STUDENT_H
#include"Other.h"

class Student {

public:

	// 学生端页面 
	void Inter_Face(string, int, bool, int);

	// 修改量化 
	void Modified_Quantification(string, bool, int, int);

	// 查看排名 
	void View_The_Rankings(string, int, bool, int);

	// 提出疑问 
	void Raise_Questions(string, bool);

};

#endif