#include"code.h"
#include"Late.h"
#include"Other.h"

Late la;
Other o;

// 页面设置 
void Other::SetWindowStyle(bool flag, bool Switch_English) {
	system("title TOP monitor [2.0.10]");
	if (flag) system("color f0");
	else system("color f");
	HANDLE hOutPut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_FONT_INFOEX consoleCurrentFontEx;
	consoleCurrentFontEx.cbSize = sizeof(CONSOLE_FONT_INFOEX);
	consoleCurrentFontEx.nFont = 0;
	consoleCurrentFontEx.dwFontSize.X = 7;//是字体的宽度 
	consoleCurrentFontEx.dwFontSize.Y = 14;//字体的高度 
	consoleCurrentFontEx.FontFamily = TMPF_VECTOR;
	consoleCurrentFontEx.FontWeight = 600;//字体的粗细(正常字体400 加粗700)
	//wcscpy_s(consoleCurrentFontEx.FaceName, __TEXT("Courier"));
	SetCurrentConsoleFontEx(hOutPut, FALSE, &consoleCurrentFontEx);
	//cout << "现在字体的大小是这样的:！Hello World" << endl;
	return;
}

// 软件主页面
void Other::Inter_Face(bool Switch_English) {
	if (Switch_English) {
		cout << "======================Welcome to So_noSlack's software======================\n\n";
		cout << "\t\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
		cout << "\t\t\t┃      1.QMS               ┃\n";
		cout << "\t\t\t┣━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
		cout << "\t\t\t┃      2.TPS               ┃\n";
		cout << "\t\t\t┣━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
		cout << "\t\t\t┃      3.Service hall      ┃\n";
		cout << "\t\t\t┣━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
		cout << "\t\t\t┃      4.Change language   ┃\n";
		cout << "\t\t\t┣━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
		cout << "\t\t\t┃      5.Colophon          ┃\n";
		cout << "\t\t\t┣━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
		cout << "\t\t\t┃      6.Copyright         ┃\n";
		cout << "\t\t\t┣━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
		cout << "\t\t\t┃      7.Service Manual    ┃\n";
		cout << "\t\t\t┣━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
		cout << "\t\t\t┃      0.Exit              ┃\n";
		cout << "\t\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";
	}
	else {
		cout << "======================欢迎来到 So_noSlack 的软件======================\n\n";
		cout << "\t\t    ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
		cout << "\t\t    ┃       1.量化管理系统       ┃\n";
		cout << "\t\t    ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
		cout << "\t\t    ┃       2.迟到扣分系统       ┃\n";
		cout << "\t\t    ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
		cout << "\t\t    ┃       3.服务大厅           ┃\n";
		cout << "\t\t    ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
		cout << "\t\t    ┃       4.切换语言           ┃\n";
		cout << "\t\t    ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
		cout << "\t\t    ┃       5.版本记录           ┃\n";
		cout << "\t\t    ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
		cout << "\t\t    ┃       6.版权说明           ┃\n";
		cout << "\t\t    ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
		cout << "\t\t    ┃       7.使用细则           ┃\n";
		cout << "\t\t    ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
		cout << "\t\t    ┃       0.退    出           ┃\n";
		cout << "\t\t    ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";
	}
	return;
}

// 量化系统主页面 
void Other::Quantitative_Inter_Face(bool Switch_English) {
	if (Switch_English) {
		cout << "======================Welcome to Quantitative Management Systems======================\n\n";
		cout << "\t\t\t  ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
		cout << "\t\t\t  ┃      1.Student port        ┃\n";
		cout << "\t\t\t  ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
		cout << "\t\t\t  ┃      2.Teacher port        ┃\n";
		cout << "\t\t\t  ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
		cout << "\t\t\t  ┃      3.Administrator port  ┃\n";
		cout << "\t\t\t  ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
		cout << "\t\t\t  ┃      4.Colophon            ┃\n";
		cout << "\t\t\t  ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
		cout << "\t\t\t  ┃      5.Switch the language ┃\n";
		cout << "\t\t\t  ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
		cout << "\t\t\t  ┃      0.Exit                ┃\n";
		cout << "\t\t\t  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";
	}
	else {
		cout << "======================欢迎来到量化管理系统======================\n\n";
		cout << "\t\t ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
		cout << "\t\t ┃         1.学    生         ┃\n";
		cout << "\t\t ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
		cout << "\t\t ┃         2.教    师         ┃\n";
		cout << "\t\t ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
		cout << "\t\t ┃         3.管 理 员         ┃\n";
		cout << "\t\t ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
		cout << "\t\t ┃         4.版本记录         ┃\n";
		cout << "\t\t ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
		cout << "\t\t ┃         5.切换语言         ┃\n";
		cout << "\t\t ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
		cout << "\t\t ┃         0.退    出         ┃\n";
		cout << "\t\t ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";
	}
	return;
}

// 迟到扣分系统主页面
void Other::Late_Inter_Face(bool Switch_English) {
	la.Inter();
	if (Switch_English) {
		cout << "======================Welcome to Tardiness Penalty Statistical System======================\n\n";
		cout << "\t\t\t ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
		cout << "\t\t\t ┃         1.Increase the count         ┃\n";
		cout << "\t\t\t ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
		cout << "\t\t\t ┃         2.Check the penalty points   ┃\n";
		cout << "\t\t\t ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
		cout << "\t\t\t ┃         3.Check the date             ┃\n";
		cout << "\t\t\t ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
		cout << "\t\t\t ┃         4.View history               ┃\n";
		cout << "\t\t\t ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
		cout << "\t\t\t ┃         5.Colophon                   ┃\n";
		cout << "\t\t\t ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
		cout << "\t\t\t ┃         6.Switch the language        ┃\n";
		cout << "\t\t\t ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
		cout << "\t\t\t ┃         0.Exit                       ┃\n";
		cout << "\t\t\t ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";
	}
	else {
		cout << "======================欢迎来到迟到扣分统计系统======================\n\n";
		cout << "\t\t   ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
		cout << "\t\t   ┃         1.记录迟到         ┃\n";
		cout << "\t\t   ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
		cout << "\t\t   ┃         2.查看扣分         ┃\n";
		cout << "\t\t   ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
		cout << "\t\t   ┃         3.查看日期         ┃\n";
		cout << "\t\t   ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
		cout << "\t\t   ┃         4.查看历史         ┃\n";
		cout << "\t\t   ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
		cout << "\t\t   ┃         5.版本记录         ┃\n";
		cout << "\t\t   ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
		cout << "\t\t   ┃         6.切换语言         ┃\n";
		cout << "\t\t   ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
		cout << "\t\t   ┃         0.退    出         ┃\n";
		cout << "\t\t   ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";
	}
	return;
}

// 娱乐区主页面
void Other::Game_Inter_Face(bool Switch_English) {
	if (Switch_English) {
		cout << "================================Welcome to the service hall================================\n\n";
		cout << "\t\t\t ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
		cout << "\t\t\t ┃         1.Words game                 ┃\n";
		cout << "\t\t\t ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
		cout << "\t\t\t ┃         2.Maths game                 ┃\n";
		cout << "\t\t\t ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
		cout << "\t\t\t ┃         3.Digital bombs              ┃\n";
		cout << "\t\t\t ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
		cout << "\t\t\t ┃         4.Name battle                ┃\n";
		cout << "\t\t\t ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
		cout << "\t\t\t ┃         5.Surprise!                  ┃\n";
		cout << "\t\t\t ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
		cout << "\t\t\t ┃         6.Colophon                   ┃\n";
		cout << "\t\t\t ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
		cout << "\t\t\t ┃         0.Exit                       ┃\n";
		cout << "\t\t\t ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";
	}
	else {
		cout << "==========================欢迎来到服务大厅==========================\n\n";
		cout << "\t\t   ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
		cout << "\t\t   ┃        1.文字游戏          ┃\n";
		cout << "\t\t   ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
		cout << "\t\t   ┃        2.2048 游戏         ┃\n";
		cout << "\t\t   ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
		cout << "\t\t   ┃        3.数字炸弹          ┃\n";
		cout << "\t\t   ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
		cout << "\t\t   ┃        4.名字大作战        ┃\n";
		cout << "\t\t   ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
		cout << "\t\t   ┃        5.Surprise！        ┃\n";
		cout << "\t\t   ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
		cout << "\t\t   ┃        6.版本记录          ┃\n";
		cout << "\t\t   ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
		cout << "\t\t   ┃        0.退    出          ┃\n";
		cout << "\t\t   ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";
	}
	return;
}

// 软件版本记录
void Other::Colophon_Software(bool Switch_English) {
	system("cls");
	if (Switch_English)
		cout << "\n\n"
		<< "┏━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n"
		<< "┃  Update date  ┃                               Modify content                                  ┃\n"
		<< "┣━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n"
		<< "┃   2023-07-05  ┃   So noSlack's software was created in the quantitative management system     ┃\n"
		<< "┣━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n"
		<< "┃   2023-08-20  ┃         The compatibility and account security are greatly improved           ┃\n"
		<< "┣━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n"
		<< "┃   2023-09-29  ┃               TOP monitor launched the service hall function                  ┃\n"
		<< "┗━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n\n\n";
	else
		cout << "\n\n"
		<< "┏━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n"
		<< "┃      日期     ┃                         修改内容                            ┃\n"
		<< "┣━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n"
		<< "┃   2023-07-05  ┃        在量化管理系统大更中产生了 So_noSlack 的软件         ┃\n"
		<< "┣━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n"
		<< "┃   2023-08-20  ┃          软件大幅优化，兼容性及账号安全性大大改进           ┃\n"
		<< "┣━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n"
		<< "┃   2023-09-29  ┃   在“双减”政策的背景下，TOP monitor 推出了服务大厅功能    ┃\n"
		<< "┗━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n\n\n";
	system("pause");
	system("cls");
	return;
}

//  量化系统版本记录 
void Other::Colophon_Score(bool Switch_English) {
	system("cls");
	if (Switch_English)
		cout << "\n\n"
		<< "┏━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n"
		<< "┃     Update date      ┃                      Modify content                        ┃\n"
		<< "┣━━━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n"
		<< "┃  2023-02-09 [1.0.1]  ┃   Build the framework and implements the basic function    ┃\n"
		<< "┣━━━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n"
		<< "┃  2023-02-26 [1.0.2]  ┃   Optimize some functional code                            ┃\n"
		<< "┣━━━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n"
		<< "┃  2023-03-31 [1.1.3]  ┃   Strengthen the security of quantization and optimize     ┃\n"
		<< "┃                      ┃   the convenience of modifying quantization                ┃\n"
		<< "┣━━━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n"
		<< "┃  2023-05-26 [1.1.4]  ┃   Add late point deduction system to optimize the ease of  ┃\n"
		<< "┃                      ┃   modification quantification                              ┃\n"
		<< "┣━━━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n"
		<< "┃  2023-06-02 [1.1.5]  ┃   Create the version record function and optimize some     ┃\n"
		<< "┃                      ┃   interfaces                                               ┃\n"
		<< "┣━━━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n"
		<< "┃                      ┃    1. Delete the backup of disk E                          ┃\n"
		<< "┃                      ┃    2. Strengthen account information                       ┃\n"
		<< "┃                      ┃    3. View the ranking function                            ┃\n"
		<< "┃  2023-06-17 [1.1.6]  ┃    4. The class represents the modification of             ┃\n"
		<< "┃                      ┃       quantitative function optimization                   ┃\n"
		<< "┃                      ┃    5. The new switch between Chinese and English function, ┃\n"
		<< "┃                      ┃       from the quantization system to internationalization ┃\n"
		<< "┣━━━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n"
		<< "┃                      ┃            Quantitative management system bigger!!         ┃\n"
		<< "┃                      ┃    1. Re-establish the program structure, and the          ┃\n"
		<< "┃                      ┃       efficiency is greatly increased                      ┃\n"
		<< "┃  2023-07-05 [2.0.7]  ┃    2. Rewrite part of the functional code, the bug rate    ┃\n"
		<< "┃                      ┃       and the collapse rate are reduced                    ┃\n"
		<< "┃                      ┃    3. Modify quantization function and optimize it again   ┃\n"
		<< "┃                      ┃    4, So_noSlack's software was produced in the larger     ┃\n"
		<< "┣━━━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n"
		<< "┃                      ┃    1. Add the small black room function                    ┃\n"
		<< "┃                      ┃    2. Lv.3 admin add the function of investigating and     ┃\n"
		<< "┃                      ┃       handling accounts for better management              ┃\n"
		<< "┃  2023-08-20 [2.0.8]  ┃    3. Teachers and administrators add login keys to make   ┃\n"
		<< "┃                      ┃       accounts more secure                                 ┃\n"
		<< "┃                      ┃    3. The hierarchy is updated and more clear              ┃\n"
		<< "┃                      ┃    4, Committee can only modify undergraduate quantization ┃\n"
		<< "┣━━━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n"
		<< "┃  2024-01-05 [2.0.10] ┃                      Fix known issues                      ┃\n"
		<< "┣━━━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫n"
		<< "┃                      ┃    1. Administrative Privilege Updates                     ┃n"
		<< "┃                      ┃    2. Login Key Function Optimization                      ┃n"
		<< "┃  2024-05-18 [2.1.11] ┃    3. Add export time function to export file              ┃n"
		<< "┃                      ┃    4. Restore Initialization Function Perfected            ┃n"
		<< "┃                      ┃    5. Fix known issues                                     ┃n"
		<< "┗━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n\n\n";
	else
		cout << "\n\n"
		<< "┏━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n"
		<< "┃      更新日期        ┃                    修改内容                       ┃\n"
		<< "┣━━━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n"
		<< "┃  2023-02-09 [1.0.1]  ┃   量化系统横空出世，搭建框架并实现基本的功能      ┃\n"
		<< "┣━━━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n"
		<< "┃  2023-02-26 [1.0.2]  ┃   优化部分功能代码                                ┃\n"
		<< "┣━━━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n"
		<< "┃  2023-03-31 [1.1.3]  ┃   加强量化的安全性，优化修改量化的便捷性          ┃\n"
		<< "┣━━━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n"
		<< "┃  2023-05-26 [1.1.4]  ┃   添加迟到扣分系统，优化修改量化的便捷性          ┃\n"
		<< "┣━━━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n"
		<< "┃  2023-06-02 [1.1.5]  ┃   创建版本记录功能，优化部分界面                  ┃\n"
		<< "┣━━━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n"
		<< "┃                      ┃    1. E 盘备份删除                                ┃\n"
		<< "┃                      ┃    2. 账号信息强化                                ┃\n"
		<< "┃  2023-06-17 [1.1.6]  ┃    3. 查看排名功能显示名次                        ┃\n"
		<< "┃                      ┃    4. 课代表修改量化功能优化                      ┃\n"
		<< "┃                      ┃    5. 新添切换中英文功能，从此量化系统走向国际化  ┃\n"
		<< "┣━━━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n"
		<< "┃                      ┃                量化管理系统大更！！！             ┃\n"
		<< "┃                      ┃    1. 重新搭建程序架构，效率大大增加              ┃\n"
		<< "┃  2023-07-05 [2.0.7]  ┃    2. 重写部分功能代码，bug 率和卡崩率减小        ┃\n"
		<< "┃                      ┃    3. 修改量化功能再次优化                        ┃\n"
		<< "┃                      ┃    4. 在大更中产生了 So_noSlack 的软件            ┃\n"
		<< "┣━━━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n"
		<< "┃                      ┃    1. 添加小黑屋功能                              ┃\n"
		<< "┃                      ┃    2. 三级管理员添加查处账号功能，更好管理        ┃\n"
		<< "┃  2023-08-20 [2.0.8]  ┃    3. 教师和管理员添加登录密钥，使账号更加安全    ┃\n"
		<< "┃                      ┃    4. 等级制度更新，更加清晰明确                  ┃\n"
		<< "┃                      ┃    5. 修改量化优化：各科课代表只能修改本科量化    ┃\n"
		<< "┣━━━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n"
		<< "┃  2024-01-05 [2.0.10] ┃                   修复已知问题                    ┃\n"
		<< "┣━━━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n"
		<< "┃                      ┃    1. 管理权限更新                                ┃\n"
		<< "┃                      ┃    2. 登录密钥功能优化                            ┃\n"
		<< "┃  2024-05-18 [2.1.11] ┃    3. 导出文件添加导出时间功能                    ┃\n"
		<< "┃                      ┃    4. 恢复初始化功能完善                          ┃\n"
		<< "┃                      ┃    5. 修复已知问题                                ┃\n"
		<< "┗━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n\n\n";
	system("pause");
	system("cls");
	return;
}

// 迟到扣分系统版本记录
void Other::Colophon__Late(bool Switch_English) {
	system("cls");
	if (Switch_English)
		cout << "\n\n"
		<< "┏━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n"
		<< "┃  Update date  ┃                               Modify content                                  ┃\n"
		<< "┣━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n"
		<< "┃   2023-05-12  ┃ Basically set up the framework, and implement a small part of the function    ┃\n"
		<< "┣━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n"
		<< "┃   2023-05-26  ┃ Add continuous input late, check the whole class late and deduction           ┃\n"
		<< "┣━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n"
		<< "┃   2023-05-27  ┃ It can be used directly with the quantitative system without manual deduction ┃\n"
		<< "┣━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n"
		<< "┃   2023-07-05  ┃ The system is larger, some functional codes are rewritten and optimized       ┃\n"
		<< "┗━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n\n\n";
	else
		cout << "\n\n"
		<< "┏━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n"
		<< "┃      日期     ┃                   修改内容                       ┃\n"
		<< "┣━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n"
		<< "┃   2023-05-12  ┃  基本搭建框架，并实现小部分功能                  ┃\n"
		<< "┣━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n"
		<< "┃   2023-05-26  ┃  添加连续录入迟到，查看全班迟到及扣分情况        ┃\n"
		<< "┣━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n"
		<< "┃   2023-05-27  ┃  与量化系统直接连用(融合)，无需人工扣分          ┃\n"
		<< "┣━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n"
		<< "┃   2023-07-05  ┃  系统大更，部分功能代码重写优化，效率大大增加    ┃\n"
		<< "┗━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n\n\n";
	system("pause");
	system("cls");
	return;
}

// 服务大厅版本记录
void Other::Colophon_Game(bool Switch_English) {
	system("cls");
	if (Switch_English)
		cout << "\n\n"
		<< "┏━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n"
		<< "┃  Update date  ┃                               Modify content                                  ┃\n"
		<< "┣━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n"
		<< "┃   2023-09-29  ┃               TOP monitor launched the service hall function                  ┃\n"
		<< "┗━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n\n\n";
	else
		cout << "\n\n"
		<< "┏━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n"
		<< "┃      日期     ┃                         修改内容                            ┃\n"
		<< "┣━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n"
		<< "┃   2023-09-29  ┃   在“双减”政策的背景下，TOP monitor 推出了服务大厅功能    ┃\n"
		<< "┗━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n\n\n";
	system("pause");
	system("cls");
	return;
}

// 软件版权
void Other::Copyright(bool Switch_English) {
	system("cls");
	if (Switch_English) {
		cout << "\t\t-----------------------------------------------------------------------------------------\n";
		cout << "\t\t| Copyright: Class 2509, Zhengzhou No. 1 High Tech Experimental High School So_noSlack  |\n";
		cout << "\t\t| Address: No.21 Zhangwuzhai Road, Zhengzhou High-tech Industrial Development Zone      |\n";
		cout << "\t\t| E-mail & WeChat: 2095259341@qq.com | w13213071120                                     |\n";
		cout << "\t\t| Statement：                                                                           |\n";
		cout << "\t\t|   1. The views expressed in this article are those of the author                      |\n";
		cout << "\t\t|   2. This project will be updated by the author in time, welcome to comment,so as to  |\n";
		cout << "\t\t|      facilitate the improvement of the project                                        |\n";
		cout << "\t\t|   3. The copyright belongs to the original author, and is strictly prohibited to      |\n";
		cout << "\t\t|      reprint without permission                                                       |\n";
		cout << "\t\t|   4. The statement of this project and the right to modify, update and final          |\n";
		cout << "\t\t|      interpretation thereof belong to the original author                             |\n";
		cout << "\t\t| So_noSlack owns the right to interpret the above statement                            |\n";
		cout << "\t\t-----------------------------------------------------------------------------------------\n\n\n";
	}
	else {
		cout << "\t\t\t-----------------------------------------------------------------\n";
		cout << "\t\t\t| 版权所有：郑州一中高新实验中学 2509 班 So_noSlack             |\n";
		cout << "\t\t\t| 地址：郑州市高新技术产业开发区张五砦路 21 号                  |\n";
		cout << "\t\t\t| 邮箱 & 微信：2095259341@qq.com | w13213071120                 |\n";
		cout << "\t\t\t| 声明：                                                        |\n";
		cout << "\t\t\t|   1.本项目仅代表作者本人的观点                                |\n";
		cout << "\t\t\t|   2.本项目会由作者及时更新，欢迎发表评论，以利项目完善        |\n";
		cout << "\t\t\t|   3.版权归原作者所有，未经允许严禁转载                        |\n";
		cout << "\t\t\t|   4.本项目之声明以及其修改权、更新权及最终解释权均属原作者所有|\n";
		cout << "\t\t\t| 以上声明的解释权归 So_noSlack 所有                            |\n";
		cout << "\t\t\t-----------------------------------------------------------------\n\n\n";
	}
	system("pause");
	system("cls");
	return;
}

// 使用细则
void Other::Service_Instruction(bool Switch_English) {
	system("cls");
	if (Switch_English) {
		cout << "\t\t\t\tTCU\n\n";
		cout << "Notice: \n";
		cout << "1. The copyright of this project belongs to So_noSlack and is not allowed to be distributed or used commercially in any form by anyone without permission\n";
		cout << "2. In the process of use, if you find loopholes, please also give positive feedback\n\n";
		cout << "\tQuantitative management system specific introduction\n\n";
		cout << "      Software owner: So_noSlack Author: H_space & So_noSlack\n\n";
		cout << "Statement: This system will be updated with the actual situation in real time, if there are loopholes, please report in time\n\n";
		cout << "First. Management characteristics\n\n";
		cout << "In response to the needs of identity management, this system has updated the new management mode, as follows: \n";
		cout << "┏━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
		cout << "┃   Type(level) ┃        users        ┃                           function                            ┃\n";
		cout << "┣━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
		cout << "┃   Lv.0(Grey)  ┃      Punished *     ┃                           Not have                            ┃\n";
		cout << "┣━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
		cout << "┃   Lv.1(Blue)  ┃   Average student   ┃   See individual quantification and ranking, ask questions    ┃\n";
		cout << "┣━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
		cout << "┃   Lv.2(Green) ┃   Class committee   ┃                     Modify quantifications                    ┃\n";
		cout << "┣━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
		cout << "┃  Lv.3(Orange) ┃     Lv.1 admin *    ┃          Use the late system, View class quantification       ┃\n";
		cout << "┣━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
		cout << "┃   Lv.4(Red)   ┃     Lv.2 admin *    ┃            Modify class quantification and export data        ┃\n";
		cout << "┣━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
		cout << "┃  Lv.5(Purple) ┃     Lv.3 admin *    ┃    Initialize, modify and optimize the source code, set keys  ┃\n";
		cout << "┗━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n\n";
		cout << "Annotation: \n";
		cout << "[Punished *] Quantified less than 0 points or major disciplinary violations, will be locked in a small black room, become the punished, later discretionary treatment\n";
		cout << "[Lv.1 admin *] Senior class committee\n";
		cout << "[Lv.2 admin *] Academic committe\n";
		cout << "[Lv.3 admin *] Owner\n\n";
		cout << "Second. System introduction\n\n";
		cout << "    The original intention of this project is to help teachers manage the program of student quantification. By default, there are three ports, namely the student side, the teacher side and the management side. The copyright description can be found on the main page of the software.\n";
		cout << "    Main functions of the student side -- modify quantization (only Lv.2 and above), view quantization scores and rankings, ask questions about quantization to the teacher, and log out.\n";
		cout << "    Main functions of the teacher side -- modify quantization, view ranking, view modification log, view account, export data, view questions, exit login.\n";
		cout << "    Main functions of the management side -- modify quantization, view modification logs, view accounts, view rankings, export data, and log out.\n\n";
		cout << "\tLate deduction system specific introduction\n\n";
		cout << "First. Management characteristics\n\n";
		cout << "    Feature 1: The use of key\n    This system is born according to demand. For some reason the login module is not added, which allows anyone to access the system and have all permissions. So I thought of using the key, so I added the link of input and use the key before entering the system, which greatly strengthened the system security and student quantization security. After logging in to the system, all operations are recorded as Admin operations.\n";
		cout << "    Feature 2: Linkage with quantitative management system\n    This system is a subsidiary system of quantitative management system, so if there is no linkage with quantitative management system, it will lose its existence value. Therefore, in the function of recording tardiness, we directly link with the quantization management system, automatically calculate the points to be deducted according to the number of tardiness, and directly deduct the points to the student's quantization, without manual deduction, which is very convenient. This function not only greatly facilitates the users but also increases the quantification fairness of students.\n\n";
		cout << "Second. System introduction\n\n";
		cout << "    This project came into being due to the need to record students' tardiness, the original intention is to facilitate the recording and real-time deduction of points.\n";
		cout << "    The main functions include recording late, viewing penalty points, date query, history query, etc. Among them, the lateness recording function is directly linked with the quantization system, responsible for updating the number of students' lateness and the lateness log, which is also the core of this project. View deduction function can directly view the late number of students with late records, this deduction and cumulative deduction, and automatically shield useless data, clear and clear.\n\n";
	}
	else {
		cout << "\t\t\t使用细则\n\n";
		cout << "公告：\n";
		cout << "1. 本项目的版权归属于 So_noSlack，任何人未经允许，不允许以任何形式传播或用于商业\n";
		cout << "2. 在使用过程中，若发现漏洞，还请积极反馈\n\n";
		cout << "\t\t  量化管理系统具体介绍\n\n";
		cout << "    软件所有者：So_noSlack    本文作者：H_space & So_noSlack\n\n";
		cout << "声明：本系统会随实际情况实时更新，如有漏洞，请及时汇报\n\n";
		cout << "一．管理特色\n\n";
		cout << "应身份管理的需求，本系统更新了新型管理方式，具体如下：\n";
		cout << "┏━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
		cout << "┃   类型(级别)  ┃     使用人群    ┃                       功能                       ┃\n";
		cout << "┣━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
		cout << "┃    Lv.0(灰)   ┃    被处罚者 *   ┃                        无                        ┃\n";
		cout << "┣━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
		cout << "┃    Lv.1(蓝)   ┃     普通学生    ┃           查看个人量化及排名、提出疑问           ┃\n";
		cout << "┣━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
		cout << "┃    Lv.2(绿)   ┃   课代表、班委  ┃      查看个人量化及排名、提出疑问、修改量化      ┃\n";
		cout << "┣━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
		cout << "┃    Lv.3(橙)   ┃   一级管理员 *  ┃           使用迟到扣分系统、查看全班量化         ┃\n";
		cout << "┣━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
		cout << "┃    Lv.4(红)   ┃   二级管理员 *  ┃              修改全班量化、导出量化              ┃\n";
		cout << "┣━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
		cout << "┃    Lv.5(紫)   ┃   三级管理员 *  ┃     初始化、修改优化源代码、查处账号、设置密钥   ┃\n";
		cout << "┗━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n\n";
		cout << "注释：\n";
		cout << "【被处罚者 *】量化低于 0 分或重大违纪，将会被关小黑屋，成为被处罚者，以后酌情处理\n";
		cout << "【一级管理员 *】一般授予 高级班委 此权限\n";
		cout << "【二级管理员 *】一般授予 学委 此权限\n";
		cout << "【三级管理员 *】一般授予 所有者 此权限\n\n";
		cout << "二．系统简介\n\n";
		cout << "    本项目的初衷为了帮助老师管理学生量化的程序，默认有三个端口，分别为学生端、教师端和管理端。在软件主页面可查看版权说明\n";
		cout << "    学生端主要功能 -- 修改量化(仅限 Lv.2 及以上)、查看量化分数及排名、向老师对量化提出疑问、退出登录。\n";
		cout << "    教师端主要功能 -- 修改量化、查看排名、查看修改日志、查看账号、导出数据、查看疑问、退出登录。\n";
		cout << "    管理端主要功能 -- 修改量化、查看修改日志、查看账号、查看排名、导出数据、退出登录。\n\n";
		cout << "\t\t  迟到扣分系统具体介绍\n\n";
		cout << "一．主要特色\n\n";
		cout << "    特色一 ：使用密钥\n    本系统应需求而生。因某种原因没有加登录模块，这使任何人都可进入该系统，并拥有一切权限。所以便想到了使用密钥，于是在进入系统前加上了输入使用密钥这一环节，大大加强了系统安全性及学生量化安全性。并且在进入系统后的所有操作，日志均会记录为 Admin 操作。\n";
		cout << "    特色二 ：与量化管理系统联动\n    本系统为量化管理系统的附属系统，因此如果与量化管理系统没有联动就失去了存在价值。所以我们在记录迟到这一功能中直接与量化管理系统联动，按迟到次数自动计算应扣分数并直接扣分至该学生量化中，不必再人工扣分，十分便捷。这一功能不仅大大方便了使用者而且增加了学生量化公平性。\n\n";
		cout << "二．系统简介\n\n";
		cout << "    本项目因需要记录学生迟到便应运而生，初衷便是为了方便记录并实时扣分。\n";
		cout << "    主要功能有记录迟到、查看扣分、日期查询、历史查询等。其中，记录迟到功能直接与量化系统联动，负责把学生迟到次数和迟到日志更新，该功能也是本项目的核心。查看扣分功能可直接查看所有有迟到记录的学生的迟到次数、本次扣分以及累计扣分，并自动屏蔽无用数据，清晰明了。\n\n";
	}
	system("pause");
	system("cls");
	return;
}

// 是否在小黑屋中
bool Other::Check(int Id) {
	ifstream ifs;
	ifs.open(SCORE_FILE, ios::in);
	long long fChinese, fMaths, fEnglish, fPolitics, fHistory, fGeography, fBiology, fPhysics, fOther, fTotal;
	int fId;
	while (ifs >> fId && ifs >> fChinese && ifs >> fMaths && ifs >> fEnglish
		&& ifs >> fPolitics && ifs >> fHistory && ifs >> fGeography && ifs >> fBiology
		&& ifs >> fPhysics && ifs >> fOther && ifs >> fTotal)
		if (fId == Id && fTotal < 0) return true;
	ifs.close();
	ifs.open(BLACK_FILE, ios::in);
	string time1, time2;
	while (ifs >> time1 && ifs >> time2 && ifs >> fId)
		if (fId == Id) return true;
	ifs.close();
	return false;
}

// 小黑屋主页
void Other::Black(string Name, bool Switch_English) {
	if (Switch_English) {
		cout << "======================Welcome to Quantitative Management Systems======================\n\n";
		cout << "Notice: Press Enter to continue after each input; To change your password, please contact your administrator.\n";
		cout << "Welcome student " << Name << " to login!\n";
		cout << "\t\t\t  ------------------------------\n";
		cout << "\t\t\t  |                            |\n";
		cout << "\t\t\t  |    You have been banned!   |\n";
		cout << "\t\t\t  |                            |\n";
		cout << "\t\t\t  ------------------------------\n";
	}
	else {
		cout << "======================欢迎来到量化管理系统======================\n\n";
		cout << "公告： 每次输入后按 Enter 继续；修改密码请联系管理员\n";
		cout << "欢迎学生 ： " << Name << " 登录！\n";
		cout << "\t\t------------------------------\n";
		cout << "\t\t|                            |\n";
		cout << "\t\t|        您已被封禁！        |\n";
		cout << "\t\t|                            |\n";
		cout << "\t\t------------------------------\n";
	}
	return;
}