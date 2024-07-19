#pragma once
#ifndef MANAGER_H
#define MANAGER_H
#include"Other.h"

class Manager {

public:

	// 管理端页面 
	void Inter_Face(string, bool, int);

	// 修改量化 
	void Modified_Quantification(bool, int);

	// 查看日志
	void View_Log(bool);

	// 查看账号
	void View_Account(bool);

	// 查看排名 
	void View_The_Rankings(bool);

	// 导出数据
	void Export_Data(bool);

	// 恢复初始化程序
	void Restore_Initialization(bool);

	// 查处账号
	void Investigate_Account(bool, int);

	// 设置密钥
	void Set_Key(bool);

};

#endif