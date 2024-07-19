#pragma once
#ifndef LATE_H
#define LATE_H
#include"Other.h"

class Late {

public:

	// 初始化
	void Inter();

	//  迟到计次 
	int AddTime(int, int[], bool);

	//  展示扣分 
	int ShowScore(int, bool);

	//  查询日期 
	void ShowDay(int, int, int, bool);

	//  查询迟到记录 
	int ShowHistory(int, bool);

	//  版本记录 
	void Colophon(bool);

};

#endif