#include"Student.h"
#include"Teacher.h"
#include"Manager.h"
#include"Other.h"
#include"Late.h"
#include"Game.h"
#include"code.h"
#define PWD "20220901"

Student student;
Teacher teacher;
Manager manager;
Other other;
Late late;
Code code;
Game game;

bool English = false;
int time_sec, time_min, time_hour, time_day, time_mon, time_year;
int Code_id[1005];

// 判断是否用管理员身份运行
bool IsProcessRunAsAdmin() {
	SID_IDENTIFIER_AUTHORITY NtAuthority = SECURITY_NT_AUTHORITY;
	PSID AdministratorsGroup;
	BOOL b = AllocateAndInitializeSid(
		&NtAuthority,
		2,
		SECURITY_BUILTIN_DOMAIN_RID,
		DOMAIN_ALIAS_RID_ADMINS,
		0, 0, 0, 0, 0, 0,
		&AdministratorsGroup);
	if (b) {
		CheckTokenMembership(NULL, AdministratorsGroup, &b);
		FreeSid(AdministratorsGroup);
	}
	return b == TRUE;
}

// 禁用强制退出
void Do_not_close() {
	HWND hwnd = GetConsoleWindow();
	HMENU hmenu = GetSystemMenu(hwnd, false);
	RemoveMenu(hmenu, SC_CLOSE, MF_BYCOMMAND);
	LONG style = GetWindowLong(hwnd, GWL_STYLE);
	style &= ~(WS_MINIMIZEBOX);
	SetWindowLong(hwnd, GWL_STYLE, style);
	SetWindowPos(hwnd, HWND_TOP, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
	ShowWindow(hwnd, SW_SHOWNORMAL);
	DestroyMenu(hmenu);
	ReleaseDC(hwnd, NULL);
}

// 设置字体颜色
void COLOR_PRINT_code(const char* s, int color) {
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | color);
	printf(s);
	SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | 7);
}

// 时间调用 
void time() {
	SYSTEMTIME st;
	GetLocalTime(&st);
	time_sec = st.wSecond; /*获取当前秒*/
	time_min = st.wMinute; /*获取当前分*/
	time_hour = st.wHour;  /*获取当前时*/
	time_day = st.wDay;    /*获取当前月份日数*/
	time_mon = st.wMonth;  /*获取当前月份*/
	time_year = st.wYear;  /*获取当前年份*/
	return;
}

// 登入记录
void Login_Processing(string Name, string Pwd) {
	ofstream ofs;
	ofs.open(LOG_FILE, ios::app);
	time();
	ofs << time_year << "-" << time_mon << "-" << time_day << " " << time_hour << ":" << time_min << ":" << time_sec << " " << Name << " 1\n";
	ofs.close();
	return;
}

// 登出记录
void Logout_Processing(string Name, string Pwd) {
	ofstream ofs;
	ofs.open(LOG_FILE, ios::app);
	time();
	ofs << time_year << "-" << time_mon << "-" << time_day << " " << time_hour << ":" << time_min << ":" << time_sec << " " << Name << " 0\n";
	ofs.close();
	return;
}

// string 数组 转 int 数组
bool Code_Change_string_to_int(string str[], int num) {
	for (int i = 1; i <= num; i++)
		for (int j = (int)str[i].size() - 1; j >= 0; j--) {
			if (str[i][j] > '9' || str[i][j] < '0') return false;
			Code_id[i] += int(str[i][j] - '0') * (int)pow(10, str[i].size() - j - 1);
		}
	return true;
}

// string 转 int
int Code_string_to_int(string str) {
	int a = 0;
	for (int i = (int)str.size() - 1; i >= 0; i--) {
		if ((str[i] > '9' || str[i] < '0') && str[0] != '-') return -0x3f3f3f3f;
		if (str[0] == '-' && i == 0) return -a;
		else a += int(str[i] - '0') * (int)pow(10, str.size() - i - 1);
	}
	return a;
}

// 主函数
int main() {
	if (!IsProcessRunAsAdmin()) {
		COLOR_PRINT_code("\n\n\n\t\t\t\t\t请用管理员身份运行！！！\n\n\n\t\t\t\t\t", 4);
		system("pause");
		return 0;
	}
	Do_not_close();
	other.SetWindowStyle(true, English);
	string Inter_port;
	while (true) {
		other.Inter_Face(English);
		if (English) printf("Please enter the action you want to perform: ");
		else printf("请您输入您要执行的操作： ");
		cin >> Inter_port;
		// 量化管理系统
		if (Inter_port == "1") {
			system("color f");
			while (true) {
				string port, id, name, pwd;
				string stu_port, tea_port, man_port;
				bool login_flag = false;
				system("cls");
				other.Quantitative_Inter_Face(English);
				if (English) printf("Please enter the action you want to perform: ");
				else printf("请您输入您要执行的操作： ");
				cin >> port;
				// 学生端验证
				if (port == "1") {
					if (English) cout << "Please enter your number: ";
					else cout << "请输入你的学号： ";
					cin >> id;
					if (id == "0") { system("cls"); continue; }
					if (English) cout << "Please enter the account name: ";
					else cout << "请输入账号名： ";
					cin >> name;
					if (name == "0") { system("cls"); continue; }
					if (English) cout << "Please enter your password: ";
					else cout << "请输入密码： ";
					cin >> pwd;
					for (int i = 1; i <= code.stu_num; i++) {
						if (login_flag) { break; }
						if (id == code.peo[i].Id && name == code.peo[i].Name && pwd == code.peo[i].Pwd) {
							login_flag = true;
							if (English) printf("Student verification success (any key continue)\n");
							else printf("学生验证成功(任意键继续)\n");
							Login_Processing(name, pwd);
							system("pause");
							system("cls");
							while (true) {
								if (other.Check(Code_string_to_int(id))) {
									other.Black(name, English);
									system("pause");
									system("cls");
									break;
								}
								student.Inter_Face(name, code.peo[i].Subject, English, code.peo[i].Man_Level);// 主页面
								cin >> stu_port;
								if (stu_port == "1" && code.peo[i].Subject) student.Modified_Quantification(name, English, code.peo[i].Subject, code.peo[i].Man_Level);// 修改量化
								else if ((stu_port == "2" && code.peo[i].Subject) || (stu_port == "1" && !code.peo[i].Subject)) student.View_The_Rankings(id, code.peo[i].Subject, English, code.peo[i].Man_Level);// 查看排名
								else if ((stu_port == "3" && code.peo[i].Subject) || (stu_port == "2" && !code.peo[i].Subject)) student.Raise_Questions(name, English);// 提出疑问
								else if (stu_port == "0") {
									if (English) cout << "Welcome next time (any key to continue)" << endl;
									else cout << "欢迎下次使用(任意键继续)" << endl;
									Logout_Processing(name, pwd);
									system("pause");
									system("cls");
									break;
								}
								else {
									if (English) cout << "Operation is not standard (any key to continue)" << endl;
									else cout << "操作不合规(任意键继续)" << endl;
									system("pause");
									system("cls");
								}
							}
						}
					}
					if (login_flag) { login_flag = false; }
					else if (!login_flag && English) {
						cout << "Verify login failed (any key to continue)" << endl;
						system("pause");
						system("cls");
					}
					else if (!login_flag) {
						cout << "学生验证登录失败(密码或用户名错误)" << endl;
						system("pause");
						system("cls");
					}
				}
				// 教师端验证
				else if (port == "2") {
					if (English) cout << "Please enter your employee number: ";
					else cout << "请输入你的职工号： ";
					cin >> id;
					if (id == "0") { system("cls"); continue; }
					if (English) cout << "Please enter the account name: ";
					else cout << "请输入账号名： ";
					cin >> name;
					if (name == "0") { system("cls"); continue; }
					if (English) cout << "Please enter your password: ";
					else cout << "请输入密码： ";
					cin >> pwd;
					srand(time(NULL));
					int op = rand() % 1000 + 1;
					if (English) cout << "Please enter the dynamic key(" << op << "): ";
					else cout << "请输入动态密钥（" << op << "）：";
					string s = code.Key[op - 1], p;
					cin >> p;
					if (s != p) {
						if (English) cout << "Verification fail!\n";
						else cout << "密钥验证不通过！\n";
						system("pause");
						system("cls");
						continue;
					}
					else {
						if (English) cout << "Pass the verification!\n";
						else cout << "密钥验证通过！\n";
					}
					for (int i = 1; i <= code.tea_num; i++) {
						if (login_flag) { break; }
						if (id == code.Init_Teacher[i].Id && name == code.Init_Teacher[i].Name && pwd == code.Init_Teacher[i].Pwd) {
							login_flag = true;
							if (English) printf("Teacher verification success (any key continue)\n");
							else printf("教师验证成功(任意键继续)\n");
							Login_Processing(name, pwd);
							system("pause");
							system("cls");
							while (true) {
								teacher.Inter_Face(id, name, English);// 主页面
								cin >> tea_port;
								if (tea_port == "1") teacher.Modified_Quantification(name, English);// 修改量化
								else if (tea_port == "2") teacher.View_The_Rankings(English);// 查看排名
								else if (tea_port == "3") teacher.View_Log(English);// 查看日志
								else if (tea_port == "4") teacher.View_Account(English);// 查看账号
								else if (tea_port == "5") teacher.Export_Data(English);// 导出数据
								else if (tea_port == "6") teacher.View_Questions(id, English);// 查看疑问
								else if (tea_port == "0") {
									if (English) cout << "Welcome next time (any key to continue)" << endl;
									else cout << "欢迎下次使用(任意键继续)" << endl;
									Logout_Processing(name, pwd);
									system("pause");
									system("cls");
									break;
								}
								else {
									if (English) cout << "Operation is not standard (any key to continue)" << endl;
									else cout << "操作不合规(任意键继续)" << endl;
									system("pause");
									system("cls");
								}
							}
						}
					}
					if (login_flag) { login_flag = false; }
					else if (!login_flag && English) {
						cout << "Verify login failed (any key to continue)" << endl;
						system("pause");
						system("cls");
					}
					else if (!login_flag) {
						cout << "教师验证登录失败(密码或用户名错误)" << endl;
						system("pause");
						system("cls");
					}
				}
				// 管理端验证
				else if (port == "3") {
					if (English) cout << "Please enter the account name: ";
					else cout << "请输入账号名： ";
					cin >> name;
					if (name == "0") { system("cls"); continue; }
					if (English) cout << "Please enter your password: ";
					else cout << "请输入密码： ";
					cin >> pwd;
					srand(time(NULL));
					int op = rand() % 1000 + 1;
					if (English) cout << "Please enter the dynamic key(" << op << "): ";
					else cout << "请输入动态密钥（" << op << "）：";
					string s = code.Key[op - 1], p;
					cin >> p;
					if (s != p) {
						if (English) cout << "Verification fail!\n";
						else cout << "密钥验证不通过！\n";
						system("pause");
						system("cls");
						continue;
					}
					else {
						if (English) cout << "Pass the verification!\n";
						else cout << "密钥验证通过！\n";
					}
					for (int i = 1; i <= code.man_num; i++) {
						if (login_flag) { break; }
						if (name == code.Init_Manager[i].Name && pwd == code.Init_Manager[i].Pwd) {
							login_flag = true;
							if (English) printf("Administrator verification success (any key continue)\n");
							else printf("管理员验证成功(任意键继续)\n");
							Login_Processing(name, pwd);
							system("pause");
							system("cls");
							while (true) {
								manager.Inter_Face(name, English, code.Init_Manager[i].Man_Level);// 主页面
								cin >> man_port;
								if (man_port == "1") manager.Modified_Quantification(English, code.Init_Manager[i].Man_Level);// 修改量化
								else if (man_port == "2") manager.View_Log(English);// 查看日志
								else if (man_port == "3") manager.View_Account(English);// 查看账号
								else if (man_port == "4") manager.View_The_Rankings(English);// 查看排名
								else if (man_port == "5" && code.Init_Manager[i].Man_Level != 1) manager.Export_Data(English);// 导出数据
								else if (man_port == "6" && code.Init_Manager[i].Man_Level == 3) manager.Restore_Initialization(English);// 恢复初始化程序
								else if (man_port == "7" && code.Init_Manager[i].Man_Level == 3) manager.Investigate_Account(English, code.Init_Manager[i].Man_Level);// 查处账号
								else if (man_port == "8" && code.Init_Manager[i].Man_Level == 3) manager.Set_Key(English);// 设置密钥
								else if (man_port == "0") {
									if (English) cout << "Welcome next time (any key to continue)" << endl;
									else cout << "欢迎下次使用(任意键继续)" << endl;
									Logout_Processing(name, pwd);
									system("pause");
									system("cls");
									break;
								}
								else {
									if (English) cout << "Operation is not standard (any key to continue)" << endl;
									else cout << "操作不合规(任意键继续)" << endl;
									system("pause");
									system("cls");
								}
							}
						}
					}
					if (login_flag) { login_flag = false; }
					else if (!login_flag && English) {
						cout << "Verify login failed (any key to continue)" << endl;
						system("pause");
						system("cls");
					}
					else if (!login_flag) {
						cout << "管理员验证登录失败(密码或用户名错误)" << endl;
						system("pause");
						system("cls");
					}
				}
				// 版本记录
				else if (port == "4") {
					other.Colophon_Score(English);
				}
				// 切换语言
				else if (port == "5") {
					if (English) cout << "Whether to switch Chinese mode(T/F): ";
					else cout << "是否切换英文模式(T/F)： ";
					string is_English;
					cin >> is_English;
					if ((is_English == "T" || is_English == "t") && !English) { English = true; other.SetWindowStyle(false, English); }
					else if ((is_English == "T" || is_English == "t") && English) { English = false; other.SetWindowStyle(false, English); }
					system("cls");
				}
				// 退出
				else if (port == "0") {
					if (English) printf("Exiting\n");
					else printf("正在退出……\n");
					system("pause");
					system("cls");
					system("color f0");
					break;
				}
				// 输入有误
				else {
					if (English) printf("Input error\n");
					else printf("输入有误！\n");
					system("pause");
					system("cls");
					continue;
				}
			}
		}
		// 迟到扣分系统
		else if (Inter_port == "2") {
			string s;
			if (English) cout << "Use key: ";
			else cout << "使用密钥：";
			cin >> s;
			if (s != PWD) {
				if (English) cout << "Incorrect key!\n";
				else cout << "密钥不正确！\n";
				system("pause");
				system("cls");
				continue;
			}
			else {
				if (English) cout << "Key authentication succeeded!\nWelcome Admin\n";
				else cout << "密钥验证成功！\n欢迎 Admin 进入\n";
				system("pause");
				system("cls");
				system("color f");
			}
			while (true) {
				string port_late, str[1005];
				int num = 1;
				system("cls");
				other.Late_Inter_Face(English);
				if (English) printf("Please enter the action you want to perform: ");
				else printf("请您输入您要执行的操作： ");
				cin >> port_late;
				if (port_late == "1") {
					if (English) cout << "Please enter the late student number (0 end): ";
					else cout << "请输入迟到人学号 (以 0 结束)： ";
					memset(Code_id, 0, sizeof Code_id);
					while (str[num - 1] != "0") cin >> str[num++];
					num--;
					if (str[1] == "0") {
						if (English) printf("Exiting\n");
						else printf("正在退出……\n");
						system("pause");
						system("cls");
						continue;
					}
					if (num > 100) {
						if (English) printf("Overpopulation\n");
						else printf("人数过多！\n");
						system("pause");
						system("cls");
						continue;
					}
					if (!Code_Change_string_to_int(str, num)) {
						if (English) printf("Input error\n");
						else printf("输入有误！\n");
						system("pause");
						system("cls");
						continue;
					}
					bool flag = false;
					for (int i = 1; i <= num; i++) {
						if (Code_id[i] > code.stu_num) {
							if (English) printf("The student number is not entered correctly\n");
							else printf("输入学号不正确\n");
							flag = true;
							system("pause");
							system("cls");
							break;
						}
					}
					if (flag) continue;
					late.AddTime(num, Code_id, English);
					if (English) cout << "Tardiness has been successfully recorded!\n";
					else cout << "已成功记录迟到！\n";
					if (English) cout << "This student's tardiness has been successfully deducted to the quantitative system!\n";
					else cout << "已成功将此学生本次的迟到扣分至量化系统！\n";
					system("pause");
					system("cls");
					continue;
				}
				else if (port_late == "2") {
					if (English)
						cout << "┏━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━┓\n"
						<< "┃      Name     ┃    Number     ┃   This time   ┃    In total   ┃\n";
					else
						cout << "┏━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━┓\n"
						<< "┃      姓名     ┃    迟到次数   ┃    本次扣分   ┃    累计扣分   ┃\n";
					for (int i = 1; i <= code.stu_num; i++) late.ShowScore(i, English);
					cout << "┗━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━┛\n";
					system("pause");
					system("cls");
					continue;
				}
				else if (port_late == "3") {
					if (English) cout << "Please enter the date (y - m - d) : ";
					else cout << "请输入日期(y - m - d) ： ";
					int y, m, d;
					scanf_s("%d-%d-%d", &y, &m, &d);
					if (!y) {
						system("pause");
						system("cls");
					}
					else late.ShowDay(y, m, d, English);
					continue;
				}
				else if (port_late == "4") {
					if (English) cout << "Please enter your student ID : ";
					else cout << "请输入查询人学号 ： ";
					string s;
					int Id_late;
					cin >> s;
					Id_late = Code_string_to_int(s);
					if (!late.ShowHistory(Id_late, English)) system("pause");
					continue;
				}
				else if (port_late == "5") {
					other.Colophon__Late(English);
					continue;
				}
				else if (port_late == "6") {
					if (English) cout << "Whether to switch Chinese mode(T/F): ";
					else cout << "是否切换英文模式(T/F)： ";
					string is_English;
					cin >> is_English;
					if ((is_English == "T" || is_English == "t") && !English) { English = true; other.SetWindowStyle(false, English); }
					else if ((is_English == "T" || is_English == "t") && English) { English = false; other.SetWindowStyle(false, English); }
					system("cls");
				}
				else if (port_late == "0") {
					if (English) printf("Exiting\n");
					else printf("正在退出……\n");
					system("pause");
					system("cls");
					system("color f0");
					break;
				}
				else {
					if (English) cout << "Input error!\n";
					else cout << "输入有误！\n";
					system("pause");
					system("cls");
					continue;
				}
			}
		}
		// 服务大厅
		else if (Inter_port == "3") {
			system("color f");
			while (true) {
				string Game_port;
				system("cls");
				other.Game_Inter_Face(English);
				if (English) printf("Please enter the action you want to perform: ");
				else printf("请您输入您要执行的操作： ");
				cin >> Game_port;
				// 文字游戏
				if (Game_port == "1") {
					system("cls");
					game.Words_Game();
					system("pause");
					system("cls");
				}
				// 2048 游戏
				else if (Game_port == "2") {
					system("cls");
					game.Maths_Game();
					system("pause");
					system("cls");
				}
				// 数字炸弹
				else if (Game_port == "3") {
					system("cls");
					game.Digital_Bombs();
					system("pause");
					system("cls");
				}
				// 名字大作战
				else if (Game_port == "4") {
					system("cls");
					game.Name_Battle();
					system("pause");
					system("cls");
				}
				// 不要太贪心，快去学习
				else if (Game_port == "5") {
					system("cls");
					COLOR_PRINT_code("\n\n\n\t\t\t\t\t不要太贪心，快去学习！！！\n\n\n\t\t\t\t\t", 4);
					system("pause");
					system("cls");
				}
				else if (Game_port == "6") {
					other.Colophon_Game(English);
				}
				// 退出
				else if (Game_port == "0") {
					if (English) printf("Exiting\n");
					else printf("正在退出……\n");
					system("pause");
					system("cls");
					system("color f0");
					break;
				}
				// 输入有误
				else {
					if (English) printf("Input error\n");
					else printf("输入有误！\n");
					system("pause");
					system("cls");
					continue;
				}
			}
		}
		// 切换语言
		else if (Inter_port == "4") {
			if (English) cout << "Whether to switch Chinese mode(T/F): ";
			else cout << "是否切换英文模式(T/F)： ";
			string is_English;
			cin >> is_English;
			if ((is_English == "T" || is_English == "t") && !English) { English = true; other.SetWindowStyle(true, English); }
			else if ((is_English == "T" || is_English == "t") && English) { English = false; other.SetWindowStyle(true, English); }
			system("cls");
		}
		// 版本记录
		else if (Inter_port == "5") {
			other.Colophon_Software(English);
		}
		// 版权说明
		else if (Inter_port == "6") {
			other.Copyright(English);
		}
		// 使用细则
		else if (Inter_port == "7") {
			other.Service_Instruction(English);
		}
		// 退出
		else if (Inter_port == "0") {
			if (English) printf("Exiting\n");
			else printf("正在退出……\n");
			system("pause");
			system("cls");
			return 0;
		}
		// 输入有误
		else {
			if (English) printf("Input error\n");
			else printf("输入有误！\n");
			system("pause");
			system("cls");
			continue;
		}
	}
	return 0;
}