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

// �ж��Ƿ��ù���Ա�������
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

// ����ǿ���˳�
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

// ����������ɫ
void COLOR_PRINT_code(const char* s, int color) {
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | color);
	printf(s);
	SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | 7);
}

// ʱ����� 
void time() {
	SYSTEMTIME st;
	GetLocalTime(&st);
	time_sec = st.wSecond; /*��ȡ��ǰ��*/
	time_min = st.wMinute; /*��ȡ��ǰ��*/
	time_hour = st.wHour;  /*��ȡ��ǰʱ*/
	time_day = st.wDay;    /*��ȡ��ǰ�·�����*/
	time_mon = st.wMonth;  /*��ȡ��ǰ�·�*/
	time_year = st.wYear;  /*��ȡ��ǰ���*/
	return;
}

// �����¼
void Login_Processing(string Name, string Pwd) {
	ofstream ofs;
	ofs.open(LOG_FILE, ios::app);
	time();
	ofs << time_year << "-" << time_mon << "-" << time_day << " " << time_hour << ":" << time_min << ":" << time_sec << " " << Name << " 1\n";
	ofs.close();
	return;
}

// �ǳ���¼
void Logout_Processing(string Name, string Pwd) {
	ofstream ofs;
	ofs.open(LOG_FILE, ios::app);
	time();
	ofs << time_year << "-" << time_mon << "-" << time_day << " " << time_hour << ":" << time_min << ":" << time_sec << " " << Name << " 0\n";
	ofs.close();
	return;
}

// string ���� ת int ����
bool Code_Change_string_to_int(string str[], int num) {
	for (int i = 1; i <= num; i++)
		for (int j = (int)str[i].size() - 1; j >= 0; j--) {
			if (str[i][j] > '9' || str[i][j] < '0') return false;
			Code_id[i] += int(str[i][j] - '0') * (int)pow(10, str[i].size() - j - 1);
		}
	return true;
}

// string ת int
int Code_string_to_int(string str) {
	int a = 0;
	for (int i = (int)str.size() - 1; i >= 0; i--) {
		if ((str[i] > '9' || str[i] < '0') && str[0] != '-') return -0x3f3f3f3f;
		if (str[0] == '-' && i == 0) return -a;
		else a += int(str[i] - '0') * (int)pow(10, str.size() - i - 1);
	}
	return a;
}

// ������
int main() {
	if (!IsProcessRunAsAdmin()) {
		COLOR_PRINT_code("\n\n\n\t\t\t\t\t���ù���Ա������У�����\n\n\n\t\t\t\t\t", 4);
		system("pause");
		return 0;
	}
	Do_not_close();
	other.SetWindowStyle(true, English);
	string Inter_port;
	while (true) {
		other.Inter_Face(English);
		if (English) printf("Please enter the action you want to perform: ");
		else printf("����������Ҫִ�еĲ����� ");
		cin >> Inter_port;
		// ��������ϵͳ
		if (Inter_port == "1") {
			system("color f");
			while (true) {
				string port, id, name, pwd;
				string stu_port, tea_port, man_port;
				bool login_flag = false;
				system("cls");
				other.Quantitative_Inter_Face(English);
				if (English) printf("Please enter the action you want to perform: ");
				else printf("����������Ҫִ�еĲ����� ");
				cin >> port;
				// ѧ������֤
				if (port == "1") {
					if (English) cout << "Please enter your number: ";
					else cout << "���������ѧ�ţ� ";
					cin >> id;
					if (id == "0") { system("cls"); continue; }
					if (English) cout << "Please enter the account name: ";
					else cout << "�������˺����� ";
					cin >> name;
					if (name == "0") { system("cls"); continue; }
					if (English) cout << "Please enter your password: ";
					else cout << "���������룺 ";
					cin >> pwd;
					for (int i = 1; i <= code.stu_num; i++) {
						if (login_flag) { break; }
						if (id == code.peo[i].Id && name == code.peo[i].Name && pwd == code.peo[i].Pwd) {
							login_flag = true;
							if (English) printf("Student verification success (any key continue)\n");
							else printf("ѧ����֤�ɹ�(���������)\n");
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
								student.Inter_Face(name, code.peo[i].Subject, English, code.peo[i].Man_Level);// ��ҳ��
								cin >> stu_port;
								if (stu_port == "1" && code.peo[i].Subject) student.Modified_Quantification(name, English, code.peo[i].Subject, code.peo[i].Man_Level);// �޸�����
								else if ((stu_port == "2" && code.peo[i].Subject) || (stu_port == "1" && !code.peo[i].Subject)) student.View_The_Rankings(id, code.peo[i].Subject, English, code.peo[i].Man_Level);// �鿴����
								else if ((stu_port == "3" && code.peo[i].Subject) || (stu_port == "2" && !code.peo[i].Subject)) student.Raise_Questions(name, English);// �������
								else if (stu_port == "0") {
									if (English) cout << "Welcome next time (any key to continue)" << endl;
									else cout << "��ӭ�´�ʹ��(���������)" << endl;
									Logout_Processing(name, pwd);
									system("pause");
									system("cls");
									break;
								}
								else {
									if (English) cout << "Operation is not standard (any key to continue)" << endl;
									else cout << "�������Ϲ�(���������)" << endl;
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
						cout << "ѧ����֤��¼ʧ��(������û�������)" << endl;
						system("pause");
						system("cls");
					}
				}
				// ��ʦ����֤
				else if (port == "2") {
					if (English) cout << "Please enter your employee number: ";
					else cout << "���������ְ���ţ� ";
					cin >> id;
					if (id == "0") { system("cls"); continue; }
					if (English) cout << "Please enter the account name: ";
					else cout << "�������˺����� ";
					cin >> name;
					if (name == "0") { system("cls"); continue; }
					if (English) cout << "Please enter your password: ";
					else cout << "���������룺 ";
					cin >> pwd;
					srand(time(NULL));
					int op = rand() % 1000 + 1;
					if (English) cout << "Please enter the dynamic key(" << op << "): ";
					else cout << "�����붯̬��Կ��" << op << "����";
					string s = code.Key[op - 1], p;
					cin >> p;
					if (s != p) {
						if (English) cout << "Verification fail!\n";
						else cout << "��Կ��֤��ͨ����\n";
						system("pause");
						system("cls");
						continue;
					}
					else {
						if (English) cout << "Pass the verification!\n";
						else cout << "��Կ��֤ͨ����\n";
					}
					for (int i = 1; i <= code.tea_num; i++) {
						if (login_flag) { break; }
						if (id == code.Init_Teacher[i].Id && name == code.Init_Teacher[i].Name && pwd == code.Init_Teacher[i].Pwd) {
							login_flag = true;
							if (English) printf("Teacher verification success (any key continue)\n");
							else printf("��ʦ��֤�ɹ�(���������)\n");
							Login_Processing(name, pwd);
							system("pause");
							system("cls");
							while (true) {
								teacher.Inter_Face(id, name, English);// ��ҳ��
								cin >> tea_port;
								if (tea_port == "1") teacher.Modified_Quantification(name, English);// �޸�����
								else if (tea_port == "2") teacher.View_The_Rankings(English);// �鿴����
								else if (tea_port == "3") teacher.View_Log(English);// �鿴��־
								else if (tea_port == "4") teacher.View_Account(English);// �鿴�˺�
								else if (tea_port == "5") teacher.Export_Data(English);// ��������
								else if (tea_port == "6") teacher.View_Questions(id, English);// �鿴����
								else if (tea_port == "0") {
									if (English) cout << "Welcome next time (any key to continue)" << endl;
									else cout << "��ӭ�´�ʹ��(���������)" << endl;
									Logout_Processing(name, pwd);
									system("pause");
									system("cls");
									break;
								}
								else {
									if (English) cout << "Operation is not standard (any key to continue)" << endl;
									else cout << "�������Ϲ�(���������)" << endl;
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
						cout << "��ʦ��֤��¼ʧ��(������û�������)" << endl;
						system("pause");
						system("cls");
					}
				}
				// �������֤
				else if (port == "3") {
					if (English) cout << "Please enter the account name: ";
					else cout << "�������˺����� ";
					cin >> name;
					if (name == "0") { system("cls"); continue; }
					if (English) cout << "Please enter your password: ";
					else cout << "���������룺 ";
					cin >> pwd;
					srand(time(NULL));
					int op = rand() % 1000 + 1;
					if (English) cout << "Please enter the dynamic key(" << op << "): ";
					else cout << "�����붯̬��Կ��" << op << "����";
					string s = code.Key[op - 1], p;
					cin >> p;
					if (s != p) {
						if (English) cout << "Verification fail!\n";
						else cout << "��Կ��֤��ͨ����\n";
						system("pause");
						system("cls");
						continue;
					}
					else {
						if (English) cout << "Pass the verification!\n";
						else cout << "��Կ��֤ͨ����\n";
					}
					for (int i = 1; i <= code.man_num; i++) {
						if (login_flag) { break; }
						if (name == code.Init_Manager[i].Name && pwd == code.Init_Manager[i].Pwd) {
							login_flag = true;
							if (English) printf("Administrator verification success (any key continue)\n");
							else printf("����Ա��֤�ɹ�(���������)\n");
							Login_Processing(name, pwd);
							system("pause");
							system("cls");
							while (true) {
								manager.Inter_Face(name, English, code.Init_Manager[i].Man_Level);// ��ҳ��
								cin >> man_port;
								if (man_port == "1") manager.Modified_Quantification(English, code.Init_Manager[i].Man_Level);// �޸�����
								else if (man_port == "2") manager.View_Log(English);// �鿴��־
								else if (man_port == "3") manager.View_Account(English);// �鿴�˺�
								else if (man_port == "4") manager.View_The_Rankings(English);// �鿴����
								else if (man_port == "5" && code.Init_Manager[i].Man_Level != 1) manager.Export_Data(English);// ��������
								else if (man_port == "6" && code.Init_Manager[i].Man_Level == 3) manager.Restore_Initialization(English);// �ָ���ʼ������
								else if (man_port == "7" && code.Init_Manager[i].Man_Level == 3) manager.Investigate_Account(English, code.Init_Manager[i].Man_Level);// �鴦�˺�
								else if (man_port == "8" && code.Init_Manager[i].Man_Level == 3) manager.Set_Key(English);// ������Կ
								else if (man_port == "0") {
									if (English) cout << "Welcome next time (any key to continue)" << endl;
									else cout << "��ӭ�´�ʹ��(���������)" << endl;
									Logout_Processing(name, pwd);
									system("pause");
									system("cls");
									break;
								}
								else {
									if (English) cout << "Operation is not standard (any key to continue)" << endl;
									else cout << "�������Ϲ�(���������)" << endl;
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
						cout << "����Ա��֤��¼ʧ��(������û�������)" << endl;
						system("pause");
						system("cls");
					}
				}
				// �汾��¼
				else if (port == "4") {
					other.Colophon_Score(English);
				}
				// �л�����
				else if (port == "5") {
					if (English) cout << "Whether to switch Chinese mode(T/F): ";
					else cout << "�Ƿ��л�Ӣ��ģʽ(T/F)�� ";
					string is_English;
					cin >> is_English;
					if ((is_English == "T" || is_English == "t") && !English) { English = true; other.SetWindowStyle(false, English); }
					else if ((is_English == "T" || is_English == "t") && English) { English = false; other.SetWindowStyle(false, English); }
					system("cls");
				}
				// �˳�
				else if (port == "0") {
					if (English) printf("Exiting\n");
					else printf("�����˳�����\n");
					system("pause");
					system("cls");
					system("color f0");
					break;
				}
				// ��������
				else {
					if (English) printf("Input error\n");
					else printf("��������\n");
					system("pause");
					system("cls");
					continue;
				}
			}
		}
		// �ٵ��۷�ϵͳ
		else if (Inter_port == "2") {
			string s;
			if (English) cout << "Use key: ";
			else cout << "ʹ����Կ��";
			cin >> s;
			if (s != PWD) {
				if (English) cout << "Incorrect key!\n";
				else cout << "��Կ����ȷ��\n";
				system("pause");
				system("cls");
				continue;
			}
			else {
				if (English) cout << "Key authentication succeeded!\nWelcome Admin\n";
				else cout << "��Կ��֤�ɹ���\n��ӭ Admin ����\n";
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
				else printf("����������Ҫִ�еĲ����� ");
				cin >> port_late;
				if (port_late == "1") {
					if (English) cout << "Please enter the late student number (0 end): ";
					else cout << "������ٵ���ѧ�� (�� 0 ����)�� ";
					memset(Code_id, 0, sizeof Code_id);
					while (str[num - 1] != "0") cin >> str[num++];
					num--;
					if (str[1] == "0") {
						if (English) printf("Exiting\n");
						else printf("�����˳�����\n");
						system("pause");
						system("cls");
						continue;
					}
					if (num > 100) {
						if (English) printf("Overpopulation\n");
						else printf("�������࣡\n");
						system("pause");
						system("cls");
						continue;
					}
					if (!Code_Change_string_to_int(str, num)) {
						if (English) printf("Input error\n");
						else printf("��������\n");
						system("pause");
						system("cls");
						continue;
					}
					bool flag = false;
					for (int i = 1; i <= num; i++) {
						if (Code_id[i] > code.stu_num) {
							if (English) printf("The student number is not entered correctly\n");
							else printf("����ѧ�Ų���ȷ\n");
							flag = true;
							system("pause");
							system("cls");
							break;
						}
					}
					if (flag) continue;
					late.AddTime(num, Code_id, English);
					if (English) cout << "Tardiness has been successfully recorded!\n";
					else cout << "�ѳɹ���¼�ٵ���\n";
					if (English) cout << "This student's tardiness has been successfully deducted to the quantitative system!\n";
					else cout << "�ѳɹ�����ѧ�����εĳٵ��۷�������ϵͳ��\n";
					system("pause");
					system("cls");
					continue;
				}
				else if (port_late == "2") {
					if (English)
						cout << "���������������������������������ש������������������������������ש������������������������������ש�������������������������������\n"
						<< "��      Name     ��    Number     ��   This time   ��    In total   ��\n";
					else
						cout << "���������������������������������ש������������������������������ש������������������������������ש�������������������������������\n"
						<< "��      ����     ��    �ٵ�����   ��    ���ο۷�   ��    �ۼƿ۷�   ��\n";
					for (int i = 1; i <= code.stu_num; i++) late.ShowScore(i, English);
					cout << "���������������������������������ߩ������������������������������ߩ������������������������������ߩ�������������������������������\n";
					system("pause");
					system("cls");
					continue;
				}
				else if (port_late == "3") {
					if (English) cout << "Please enter the date (y - m - d) : ";
					else cout << "����������(y - m - d) �� ";
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
					else cout << "�������ѯ��ѧ�� �� ";
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
					else cout << "�Ƿ��л�Ӣ��ģʽ(T/F)�� ";
					string is_English;
					cin >> is_English;
					if ((is_English == "T" || is_English == "t") && !English) { English = true; other.SetWindowStyle(false, English); }
					else if ((is_English == "T" || is_English == "t") && English) { English = false; other.SetWindowStyle(false, English); }
					system("cls");
				}
				else if (port_late == "0") {
					if (English) printf("Exiting\n");
					else printf("�����˳�����\n");
					system("pause");
					system("cls");
					system("color f0");
					break;
				}
				else {
					if (English) cout << "Input error!\n";
					else cout << "��������\n";
					system("pause");
					system("cls");
					continue;
				}
			}
		}
		// �������
		else if (Inter_port == "3") {
			system("color f");
			while (true) {
				string Game_port;
				system("cls");
				other.Game_Inter_Face(English);
				if (English) printf("Please enter the action you want to perform: ");
				else printf("����������Ҫִ�еĲ����� ");
				cin >> Game_port;
				// ������Ϸ
				if (Game_port == "1") {
					system("cls");
					game.Words_Game();
					system("pause");
					system("cls");
				}
				// 2048 ��Ϸ
				else if (Game_port == "2") {
					system("cls");
					game.Maths_Game();
					system("pause");
					system("cls");
				}
				// ����ը��
				else if (Game_port == "3") {
					system("cls");
					game.Digital_Bombs();
					system("pause");
					system("cls");
				}
				// ���ִ���ս
				else if (Game_port == "4") {
					system("cls");
					game.Name_Battle();
					system("pause");
					system("cls");
				}
				// ��Ҫ̫̰�ģ���ȥѧϰ
				else if (Game_port == "5") {
					system("cls");
					COLOR_PRINT_code("\n\n\n\t\t\t\t\t��Ҫ̫̰�ģ���ȥѧϰ������\n\n\n\t\t\t\t\t", 4);
					system("pause");
					system("cls");
				}
				else if (Game_port == "6") {
					other.Colophon_Game(English);
				}
				// �˳�
				else if (Game_port == "0") {
					if (English) printf("Exiting\n");
					else printf("�����˳�����\n");
					system("pause");
					system("cls");
					system("color f0");
					break;
				}
				// ��������
				else {
					if (English) printf("Input error\n");
					else printf("��������\n");
					system("pause");
					system("cls");
					continue;
				}
			}
		}
		// �л�����
		else if (Inter_port == "4") {
			if (English) cout << "Whether to switch Chinese mode(T/F): ";
			else cout << "�Ƿ��л�Ӣ��ģʽ(T/F)�� ";
			string is_English;
			cin >> is_English;
			if ((is_English == "T" || is_English == "t") && !English) { English = true; other.SetWindowStyle(true, English); }
			else if ((is_English == "T" || is_English == "t") && English) { English = false; other.SetWindowStyle(true, English); }
			system("cls");
		}
		// �汾��¼
		else if (Inter_port == "5") {
			other.Colophon_Software(English);
		}
		// ��Ȩ˵��
		else if (Inter_port == "6") {
			other.Copyright(English);
		}
		// ʹ��ϸ��
		else if (Inter_port == "7") {
			other.Service_Instruction(English);
		}
		// �˳�
		else if (Inter_port == "0") {
			if (English) printf("Exiting\n");
			else printf("�����˳�����\n");
			system("pause");
			system("cls");
			return 0;
		}
		// ��������
		else {
			if (English) printf("Input error\n");
			else printf("��������\n");
			system("pause");
			system("cls");
			continue;
		}
	}
	return 0;
}