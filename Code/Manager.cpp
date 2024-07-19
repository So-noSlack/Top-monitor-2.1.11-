#include"Manager.h"
#include"code.h"
#include"Other.h"

Code c;
Manager m;

//  学生量化储存 
struct node {
	int id;
	long long chinese = 0, maths = 0, english = 0, politics = 0, history = 0, geography = 0, biology = 0, physics = 0, other = 0, total = 0;
} stu[1005], stu2[1005];
int man_num = 1, man_sum, man_Subject, man_id[1005];
int man_Time_sec, man_Time_min, man_Time_hour, man_Time_day, man_Time_mon, man_Time_year;
struct Black_p { string time, name; } p[1005], q[1005];

// 降序排序 
bool cmp(node x, node y) { return x.total > y.total; }

// 时间调用
void man_Time() {
	SYSTEMTIME st;
	GetLocalTime(&st);
	man_Time_sec = st.wSecond; /*获取当前秒*/
	man_Time_min = st.wMinute; /*获取当前分*/
	man_Time_hour = st.wHour;  /*获取当前时*/
	man_Time_day = st.wDay;    /*获取当前月份日数*/
	man_Time_mon = st.wMonth;  /*获取当前月份*/
	man_Time_year = st.wYear;  /*获取当前年份*/
	return;
}

// string 转 int
int man_string_to_int(string str) {
	int a = 0;
	for (int i = (int)str.size() - 1; i >= 0; i--) {
		if (str[i] > '9' || str[i] < '0' && str[0] != '-') return -0x3f3f3f3f;
		if (str[0] == '-' && i == 0) return -a;
		a += int(str[i] - '0') * (int)pow(10, str.size() - i - 1);
	}
	return a;
}

// string 数组 转 int 数组
bool man_Change_string_to_int(string str[]) {
	for (int i = 1; i <= man_num; i++)
		for (int j = (int)str[i].size() - 1; j >= 0; j--) {
			if (str[i][j] > '9' || str[i][j] < '0') return false;
			man_id[i] += int(str[i][j] - '0') * (int)pow(10, str[i].size() - j - 1);
		}
	return true;
}

// 设置字体颜色
void COLOR_PRINT2(const char* s, int color) {
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | color);
	printf(s);
	SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | 7);
	return;
}

void Manage(int num1, int num2, int n) {
	if (q[n].name != "\t")
		if (q[n].name.size() == 4) cout << q[n].time << " " << q[n].name << "\t\t";
		else cout << q[n].time << " " << q[n].name << "\t";
	else cout << "\t\t\t";
	if (q[18 + n].name != "\t") cout << q[18 + n].time << " " << q[18 + n].name << "\t";
	else cout << "\t\t\t";
	for (int i = 1; i <= num1 / 18 + (num1 % 18 >= n); i++) cout << p[(i - 1) * 18 + (n % 18 == 0 ? 18 : n % 18)].name << "\t";
	cout << endl;
	return;
}

// 管理端页面 
void Manager::Inter_Face(string Name, bool Switch_English, int Level) {
	ifstream ifs;
	ifs.open(SCORE_FILE, ios::in);
	long long fChinese, fMaths, fEnglish, fPolitics, fHistory, fGeography, fBiology, fPhysics, fOther, fTotal;
	int fId, num1 = 0, num2 = 0;
	while (ifs >> fId && ifs >> fChinese && ifs >> fMaths && ifs >> fEnglish
		&& ifs >> fPolitics && ifs >> fHistory && ifs >> fGeography && ifs >> fBiology
		&& ifs >> fPhysics && ifs >> fOther && ifs >> fTotal)
		if (fTotal < 0) p[++num1].name = c.peo[fId].Name;
	ifs.close();
	ifs.open(BLACK_FILE, ios::in);
	string time1, time2;
	while (ifs >> time1 && ifs >> time2 && ifs >> fId) q[++num2].time = time1, q[num2].name = c.peo[fId].Name;
	for (int i = num2 + 1; i <= 36; i++) q[i].name = "\t", q[i].time = "\t\t";
	ifs.close();
	if (Switch_English && Level == 3) {
		cout << "======================Welcome to Quantitative Management Systems======================\n\n";
		cout << "Notice: Press enter to continue after each input; If you want to change the password, please change directly in the source code\n";
		cout << "Welcome administrator " << Name;
		COLOR_PRINT2(" Lv.5", 5);
		cout << " to login!\n";
		cout << "\t\t\t  ------------------------------\n";
		cout << "\t\t\t  |                            |\tBlock user:\t\t\t\t\tBlack room: \n";
		cout << "\t\t\t  |  1.Modified quantification |\t"; Manage(num1, num2, 1);
		cout << "\t\t\t  |                            |\t"; Manage(num1, num2, 2);
		cout << "\t\t\t  |  2.View log                |\t"; Manage(num1, num2, 3);
		cout << "\t\t\t  |                            |\t"; Manage(num1, num2, 4);
		cout << "\t\t\t  |  3.View account            |\t"; Manage(num1, num2, 5);
		cout << "\t\t\t  |                            |\t"; Manage(num1, num2, 6);
		cout << "\t\t\t  |  4.View the rankings       |\t"; Manage(num1, num2, 7);
		cout << "\t\t\t  |                            |\t"; Manage(num1, num2, 8);
		cout << "\t\t\t  |  5.Export data             |\t"; Manage(num1, num2, 9);
		cout << "\t\t\t  |                            |\t"; Manage(num1, num2, 10);
		cout << "\t\t\t  |  6.Restore initialization  |\t"; Manage(num1, num2, 11);
		cout << "\t\t\t  |                            |\t"; Manage(num1, num2, 12);
		cout << "\t\t\t  |  7.Investigate account     |\t"; Manage(num1, num2, 13);
		cout << "\t\t\t  |                            |\t"; Manage(num1, num2, 14);
		cout << "\t\t\t  |  8.Set key                 |\t"; Manage(num1, num2, 15);
		cout << "\t\t\t  |                            |\t"; Manage(num1, num2, 16);
		cout << "\t\t\t  |  0.Log out                 |\t"; Manage(num1, num2, 17);
		cout << "\t\t\t  |                            |\t"; Manage(num1, num2, 18);
		cout << "\t\t\t  ------------------------------\n";
		cout << "Please enter the operation you want to perform (1-8 0 exit): ";
	}
	else if (!Switch_English && Level == 3) {
		cout << "======================欢迎来到量化管理系统======================\n\n";
		cout << "公告： 每次输入后按enter继续；如要修改密码请直接在源代码改\n";
		cout << "欢迎管理员 ： " << Name;
		COLOR_PRINT2(" Lv.5", 5);
		cout << " 登录！\n";
		cout << "\t\t------------------------------\n";
		cout << "\t\t|                            |\t封禁用户：\t\t\t\t\t小黑屋：\n";
		cout << "\t\t|         1.修改量化         |\t"; Manage(num1, num2, 1);
		cout << "\t\t|                            |\t"; Manage(num1, num2, 2);
		cout << "\t\t|         2.查看日志         |\t"; Manage(num1, num2, 3);
		cout << "\t\t|                            |\t"; Manage(num1, num2, 4);
		cout << "\t\t|         3.查看账号         |\t"; Manage(num1, num2, 5);
		cout << "\t\t|                            |\t"; Manage(num1, num2, 6);
		cout << "\t\t|         4.查看排名         |\t"; Manage(num1, num2, 7);
		cout << "\t\t|                            |\t"; Manage(num1, num2, 8);
		cout << "\t\t|         5.导出数据         |\t"; Manage(num1, num2, 9);
		cout << "\t\t|                            |\t"; Manage(num1, num2, 10);
		cout << "\t\t|         6.恢复初始化       |\t"; Manage(num1, num2, 11);
		cout << "\t\t|                            |\t"; Manage(num1, num2, 12);
		cout << "\t\t|         7.查处账号         |\t"; Manage(num1, num2, 13);
		cout << "\t\t|                            |\t"; Manage(num1, num2, 14);
		cout << "\t\t|         8.设置密钥         |\t"; Manage(num1, num2, 15);
		cout << "\t\t|                            |\t"; Manage(num1, num2, 16);
		cout << "\t\t|         0.注销登录         |\t"; Manage(num1, num2, 17);
		cout << "\t\t|                            |\t"; Manage(num1, num2, 18);
		cout << "\t\t------------------------------\n";
		cout << "请您输入您要执行的操作(1-8 0退出)： ";
	}
	else if (Switch_English && Level == 2) {
		cout << "======================Welcome to Quantitative Management Systems======================\n\n";
		cout << "Notice: Press enter to continue after each input; If you want to change the password, please change directly in the source code\n";
		cout << "Welcome administrator " << Name;
		COLOR_PRINT2(" Lv.4", 4);
		cout << " to login!\n";
		cout << "\t\t\t  ------------------------------\n";
		cout << "\t\t\t  |                            |\n";
		cout << "\t\t\t  |  1.Modified quantification |\n";
		cout << "\t\t\t  |                            |\n";
		cout << "\t\t\t  |  2.View log                |\n";
		cout << "\t\t\t  |                            |\n";
		cout << "\t\t\t  |  3.View account            |\n";
		cout << "\t\t\t  |                            |\n";
		cout << "\t\t\t  |  4.View the rankings       |\n";
		cout << "\t\t\t  |                            |\n";
		cout << "\t\t\t  |  5.Export data             |\n";
		cout << "\t\t\t  |                            |\n";
		cout << "\t\t\t  |  0.Log out                 |\n";
		cout << "\t\t\t  |                            |\n";
		cout << "\t\t\t  ------------------------------\n";
		cout << "Please enter the operation you want to perform (1-5 0 exit): ";
	}
	else if (Switch_English && Level == 2) {
		cout << "======================欢迎来到量化管理系统======================\n\n";
		cout << "公告： 每次输入后按enter继续；如要修改密码请直接在源代码改\n";
		cout << "欢迎管理员 ： " << Name;
		COLOR_PRINT2(" Lv.4", 4);
		cout << " 登录！\n";
		cout << "\t\t------------------------------\n";
		cout << "\t\t|                            |\n";
		cout << "\t\t|         1.修改量化         |\n";
		cout << "\t\t|                            |\n";
		cout << "\t\t|         2.查看日志         |\n";
		cout << "\t\t|                            |\n";
		cout << "\t\t|         3.查看账号         |\n";
		cout << "\t\t|                            |\n";
		cout << "\t\t|         4.查看排名         |\n";
		cout << "\t\t|                            |\n";
		cout << "\t\t|         5.导出数据         |\n";
		cout << "\t\t|                            |\n";
		cout << "\t\t|         0.注销登录         |\n";
		cout << "\t\t|                            |\n";
		cout << "\t\t------------------------------\n";
		cout << "请您输入您要执行的操作(1-5 0退出)： ";
	}
	else if (Switch_English) {
		cout << "======================Welcome to Quantitative Management Systems======================\n\n";
		cout << "Notice: Press enter to continue after each input; If you want to change the password, please change directly in the source code\n";
		cout << "Welcome administrator " << Name;
		COLOR_PRINT2(" Lv.3", 6);
		cout << " to login!\n";
		cout << "\t\t\t  ------------------------------\n";
		cout << "\t\t\t  |                            |\n";
		cout << "\t\t\t  |  1.Modified quantification |\n";
		cout << "\t\t\t  |                            |\n";
		cout << "\t\t\t  |  2.View log                |\n";
		cout << "\t\t\t  |                            |\n";
		cout << "\t\t\t  |  3.View account            |\n";
		cout << "\t\t\t  |                            |\n";
		cout << "\t\t\t  |  4.View the rankings       |\n";
		cout << "\t\t\t  |                            |\n";
		cout << "\t\t\t  |  0.Log out                 |\n";
		cout << "\t\t\t  |                            |\n";
		cout << "\t\t\t  ------------------------------\n";
		cout << "Please enter the operation you want to perform (1-4 0 exit): ";
	}
	else {
		cout << "======================欢迎来到量化管理系统======================\n\n";
		cout << "公告： 每次输入后按enter继续；如要修改密码请直接在源代码改\n";
		cout << "欢迎管理员 ： " << Name;
		COLOR_PRINT2(" Lv.3", 6);
		cout << " 登录！\n";
		cout << "\t\t------------------------------\n";
		cout << "\t\t|                            |\n";
		cout << "\t\t|         1.修改量化         |\n";
		cout << "\t\t|                            |\n";
		cout << "\t\t|         2.查看日志         |\n";
		cout << "\t\t|                            |\n";
		cout << "\t\t|         3.查看账号         |\n";
		cout << "\t\t|                            |\n";
		cout << "\t\t|         4.查看排名         |\n";
		cout << "\t\t|                            |\n";
		cout << "\t\t|         0.注销登录         |\n";
		cout << "\t\t|                            |\n";
		cout << "\t\t------------------------------\n";
		cout << "请您输入您要执行的操作(1-4 0退出)： ";
	}
	return;
}

// 修改量化 
void Manager::Modified_Quantification(bool Switch_English, int Level) {
	ifstream ifs;
	ofstream ofs;
	ifs.open(SCORE_FILE);
	if (!ifs.is_open()) {
		if (Switch_English) printf("Failed to open the file(press any key to continue)\n");
		else printf("文件打开失败(任意键继续)\n");
		system("pause");
		system("cls");
		return;
	}
	long long fChinese, fMaths, fEnglish, fPolitics, fHistory, fGeography, fBiology, fPhysics, fOther, fTotal, i = 1;
	int fId;
	while (ifs >> fId && ifs >> fChinese && ifs >> fMaths && ifs >> fEnglish
		&& ifs >> fPolitics && ifs >> fHistory && ifs >> fGeography && ifs >> fBiology
		&& ifs >> fPhysics && ifs >> fOther && ifs >> fTotal) {
		stu[i].id = fId;
		stu[i].chinese = fChinese;
		stu[i].maths = fMaths;
		stu[i].english = fEnglish;
		stu[i].politics = fPolitics;
		stu[i].history = fHistory;
		stu[i].geography = fGeography;
		stu[i].biology = fBiology;
		stu[i].physics = fPhysics;
		stu[i].other = fOther;
		stu[i].total = stu[i].chinese + stu[i].maths + stu[i].english
			+ stu[i].politics + stu[i].history + stu[i].geography
			+ stu[i].biology + stu[i].physics + stu[i].other;
		i++;
	}
	ifs.close();
	string str[1005];
	string k, s;
	if (Switch_English) printf("Please enter the change student number(0 end; Don't > 100): ");
	else printf("请输入修改人学号 (以 0 结束;不超过 100 人)： ");
	man_num = 1;
	memset(man_id, 0, sizeof man_id);
	while (str[man_num - 1] != "0") cin >> str[man_num++];
	man_num--;
	if (str[1] == "0") {
		if (Switch_English) printf("Exiting\n");
		else printf("正在退出……\n");
		system("pause");
		system("cls");
		return;
	}
	if (man_num > 100) {
		if (Switch_English) printf("Overpopulation\n");
		else printf("人数过多！\n");
		system("pause");
		system("cls");
		return;
	}
	if (!man_Change_string_to_int(str)) {
		if (Switch_English) printf("Input error\n");
		else printf("输入有误！\n");
		system("pause");
		system("cls");
		return;
	}
	for (int i = 1; i <= man_num; i++) {
		if (man_id[i] > c.stu_num) {
			if (Switch_English) printf("The student number is not entered correctly\n");
			else printf("输入学号不正确\n");
			system("pause");
			system("cls");
			return;
		}
	}
	if (Switch_English) cout << "Please enter the modified account (1-9): ";
	else cout << "请输入修改科目(1-9): ";
	while (cin >> k) {
		man_Subject = man_string_to_int(k);
		if (man_Subject == -0x3f3f3f3f) {
			if (Switch_English) printf("Invalid input\n");
			else printf("输入无效\n");
			system("pause");
			system("cls");
			return;
		}
		if (man_Subject < 1 || man_Subject > 9) {
			if (Switch_English) cout << "Incorrect account\nPlease enter modify account (1-9): ";
			else cout << "科目不正确\n请输入修改科目(1-9): ";
		}
		else break;
	}
	if (Switch_English) cout << "Please enter the modified score: ";
	else cout << "请输入修改分数: ";
	cin >> s;
	man_sum = man_string_to_int(s);
	if (man_sum == -0x3f3f3f3f) {
		if (Switch_English) printf("Invalid input\n");
		else printf("输入无效\n");
		system("pause");
		system("cls");
		return;
	}
	for (int i = 1; i <= man_num; i++) {
		if (man_Subject == 1) stu[man_id[i]].chinese += man_sum;
		else if (man_Subject == 2) stu[man_id[i]].maths += man_sum;
		else if (man_Subject == 3) stu[man_id[i]].english += man_sum;
		else if (man_Subject == 4) stu[man_id[i]].politics += man_sum;
		else if (man_Subject == 5) stu[man_id[i]].history += man_sum;
		else if (man_Subject == 6) stu[man_id[i]].geography += man_sum;
		else if (man_Subject == 7) stu[man_id[i]].biology += man_sum;
		else if (man_Subject == 8) stu[man_id[i]].physics += man_sum;
		else if (man_Subject == 9) stu[man_id[i]].other += man_sum;
	}
	ofs.open(SCORE_FILE, ios::trunc);
	for (int i = 1; i <= c.stu_num; i++) {
		ofs << stu[i].id << "\t" << stu[i].chinese << "\t" << stu[i].maths << "\t" << stu[i].english << "\t";
		ofs << stu[i].politics << "\t" << stu[i].history << "\t";
		ofs << stu[i].geography << "\t" << stu[i].biology << "\t";
		ofs << stu[i].physics << "\t" << stu[i].other << "\t";
		stu[i].total = stu[i].chinese + stu[i].maths + stu[i].english
			+ stu[i].politics + stu[i].history
			+ stu[i].geography + stu[i].biology
			+ stu[i].physics + stu[i].other;
		ofs << stu[i].total << endl;
	}
	ofs.close();
	if (Switch_English) cout << "modify successfully! " << endl;
	else cout << "修改成功！" << endl;
	man_Time();
	ofs.open(JOURNAL_FILE, ios::app);
	printf("   %d-%d-%d %d:%d:%d\n", man_Time_year, man_Time_mon, man_Time_day, man_Time_hour, man_Time_min, man_Time_sec);
	if (Switch_English) cout << "\tName: Admin";
	else cout << "\t姓名: Adimin";
	if (Level == 1) { COLOR_PRINT2(" Lv.3", 6); }
	else if (Level == 2) { COLOR_PRINT2(" Lv.4", 4); }
	else if (Level == 3) { COLOR_PRINT2(" Lv.5", 5); }
	cout << endl;
	if (Switch_English) printf("\tNumber of modifications: %d\n\tSubject: %d\n\tScore: %d\n\tModify student number: ", man_num - 1, man_Subject, man_sum);
	else printf("\t修改人数: %d\n\t科目: %d\n\t波动分数: %d\n\t修改人学号: ", man_num - 1, man_Subject, man_sum);
	for (int i = 1; i < man_num; i++) cout << man_id[i] << " ";
	cout << endl;
	if (Switch_English) cout << "Your changes have been logged (any key to continue)" << endl;
	else cout << "已将您的修改信息记录到日志(任意键继续)" << endl;
	ofs << man_Time_year << "-" << man_Time_mon << "-" << man_Time_day << " " << man_Time_hour << ":" << man_Time_min << ":" << man_Time_sec;
	ofs << " Admin " << man_num - 1 << " " << man_Subject << " " << man_sum << " ";
	for (int i = 1; i < man_num; i++) ofs << man_id[i] << ";";
	ofs << endl;
	ofs.close();
	system("pause");
	system("cls");
	return;
}

// 查看日志
void Manager::View_Log(bool Switch_English) {
	ifstream ifs(JOURNAL_FILE, ios::in);
	if (!ifs.is_open()) {
		if (Switch_English) cout << "Failed to open the file(press any key to continue)\n";
		else cout << "文件打开失败(任意键继续)\n";
		system("pause");
		system("cls");
		return;
	}
	string time_year, time_hour, name, str;
	long long peo_num, subject, score;
	if (!(ifs >> time_year >> time_hour >> name >> peo_num >> subject >> score >> str)) {
		if (Switch_English) cout << "No modification log is displayed\n";
		else cout << "暂无修改日志\n";
	}
	else {
		if (Switch_English) {
			cout << name << " add " << score << " points to ";
			if (subject == 1) cout << "Chinese";
			else if (subject == 2) cout << "Maths";
			else if (subject == 3) cout << "English";
			else if (subject == 4) cout << "Politics";
			else if (subject == 5) cout << "History";
			else if (subject == 6) cout << "Geography";
			else if (subject == 7) cout << "Biology";
			else if (subject == 8) cout << "Physics";
			else if (subject == 9) cout << "Other";
			cout << " on " << str << " at " << time_year << " " << time_hour << "\n";
		}
		else {
			cout << name << " 在 " << time_year << " " << time_hour << " 给 " << str;
			if (subject == 1 && score > 0) cout << " 号的 语文 加了 ";
			else if (subject == 1 && score < 0) cout << " 号的 语文 扣了 ";
			else if (subject == 2 && score > 0) cout << " 号的 数学 加了 ";
			else if (subject == 2 && score < 0) cout << " 号的 数学 扣了 ";
			else if (subject == 3 && score > 0) cout << " 号的 英语 加了 ";
			else if (subject == 3 && score < 0) cout << " 号的 英语 扣了 ";
			else if (subject == 4 && score > 0) cout << " 号的 政治 加了 ";
			else if (subject == 4 && score < 0) cout << " 号的 政治 扣了 ";
			else if (subject == 5 && score > 0) cout << " 号的 历史 加了 ";
			else if (subject == 5 && score < 0) cout << " 号的 历史 扣了 ";
			else if (subject == 6 && score > 0) cout << " 号的 地理 加了 ";
			else if (subject == 6 && score < 0) cout << " 号的 地理 扣了 ";
			else if (subject == 7 && score > 0) cout << " 号的 生物 加了 ";
			else if (subject == 7 && score < 0) cout << " 号的 生物 扣了 ";
			else if (subject == 8 && score > 0) cout << " 号的 物理 加了 ";
			else if (subject == 8 && score < 0) cout << " 号的 物理 扣了 ";
			else if (subject == 9 && score > 0) cout << " 号的 其他 加了 ";
			else if (subject == 9 && score < 0) cout << " 号的 其他 扣了 ";
			cout << abs(score) << " 分\n";
		}
	}
	while (ifs >> time_year && ifs >> time_hour && ifs >> name &&
		ifs >> peo_num && ifs >> subject && ifs >> score && ifs >> str) {
		if (Switch_English) {
			cout << name << " add " << score << " points to ";
			if (subject == 1) cout << "Chinese";
			else if (subject == 2) cout << "Maths";
			else if (subject == 3) cout << "English";
			else if (subject == 4) cout << "Politics";
			else if (subject == 5) cout << "History";
			else if (subject == 6) cout << "Geography";
			else if (subject == 7) cout << "Biology";
			else if (subject == 8) cout << "Physics";
			else if (subject == 9) cout << "Other";
			cout << " on " << str << " at " << time_year << " " << time_hour << "\n";
		}
		else {
			cout << name << " 在 " << time_year << " " << time_hour << " 给 " << str;
			if (subject == 1 && score > 0) cout << " 号的 语文 加了 ";
			else if (subject == 1 && score < 0) cout << " 号的 语文 扣了 ";
			else if (subject == 2 && score > 0) cout << " 号的 数学 加了 ";
			else if (subject == 2 && score < 0) cout << " 号的 数学 扣了 ";
			else if (subject == 3 && score > 0) cout << " 号的 英语 加了 ";
			else if (subject == 3 && score < 0) cout << " 号的 英语 扣了 ";
			else if (subject == 4 && score > 0) cout << " 号的 政治 加了 ";
			else if (subject == 4 && score < 0) cout << " 号的 政治 扣了 ";
			else if (subject == 5 && score > 0) cout << " 号的 历史 加了 ";
			else if (subject == 5 && score < 0) cout << " 号的 历史 扣了 ";
			else if (subject == 6 && score > 0) cout << " 号的 地理 加了 ";
			else if (subject == 6 && score < 0) cout << " 号的 地理 扣了 ";
			else if (subject == 7 && score > 0) cout << " 号的 生物 加了 ";
			else if (subject == 7 && score < 0) cout << " 号的 生物 扣了 ";
			else if (subject == 8 && score > 0) cout << " 号的 物理 加了 ";
			else if (subject == 8 && score < 0) cout << " 号的 物理 扣了 ";
			else if (subject == 9 && score > 0) cout << " 号的 其他 加了 ";
			else if (subject == 9 && score < 0) cout << " 号的 其他 扣了 ";
			cout << abs(score) << " 分\n";
		}
	}
	system("pause");
	system("cls");
	return;
}

// 查看账号
void Manager::View_Account(bool Switch_English) {
	if (Switch_English) cout << "Please select to view content (1/2/3/0) : " << endl;
	else cout << "请选择查看内容(1/2/3/0) ： " << endl;
	if (Switch_English) cout << "\t1. View all students" << endl;
	else cout << "\t1. 查看所有学生" << endl;
	if (Switch_English) cout << "\t2. View all teachers" << endl;
	else cout << "\t2. 查看所有教师" << endl;
	if (Switch_English) cout << "\t3. View all administrators" << endl;
	else cout << "\t3. 查看所有管理员" << endl;
	if (Switch_English) cout << "\t0. Return" << endl;
	else cout << "\t0. 返回" << endl;
	string slect = "0";// 接受用户选择 
	string fId, fName, fPwd;
	long long id = 1;
	cin >> slect;
	if (slect == "1") {
		if (Switch_English) cout << "All srudents information is as follows (any key to continue) : " << endl;
		else cout << "所有的学生信息如下(任意键继续) ： " << endl;
		for (int i = 1; i <= c.stu_num; i++) {
			if (Switch_English) cout << "No." << i << " student: " << endl;
			else cout << "第 " << i << " 名： " << endl;
			if (Switch_English) cout << "\tStudent ID: " << c.peo[i].Id << endl;
			else cout << "\t学号： " << c.peo[i].Id << endl;
			if (Switch_English) cout << "\tStudent Name: " << c.peo[i].Name << endl;
			else cout << "\t姓名： " << c.peo[i].Name;
			if (c.peo[i].Man_Level == 1) { COLOR_PRINT2(" Lv.3", 6); }
			else if (c.peo[i].Man_Level == 2) { COLOR_PRINT2(" Lv.4", 4); }
			else if (c.peo[i].Man_Level == 3) { COLOR_PRINT2(" Lv.5", 5); }
			else if (c.peo[i].Subject) { COLOR_PRINT2(" Lv.2", 2); }
			else { COLOR_PRINT2(" Lv.1", 1); }
			cout << endl;
			if (Switch_English) cout << "\tStudent Password: " << c.peo[i].Pwd << endl;
			else cout << "\t密码： " << c.peo[i].Pwd << endl;
			if (c.peo[i].Subject == 1 && Switch_English) cout << "\tPosition: " << "Chinese" << endl;
			else if (c.peo[i].Subject == 1 && !Switch_English) cout << "\t任职： " << "语文" << endl;
			else if (c.peo[i].Subject == 2 && Switch_English) cout << "\tPosition: " << "Maths" << endl;
			else if (c.peo[i].Subject == 2 && !Switch_English) cout << "\t任职： " << "数学" << endl;
			else if (c.peo[i].Subject == 3 && Switch_English) cout << "\tPosition: " << "English" << endl;
			else if (c.peo[i].Subject == 3 && !Switch_English) cout << "\t任职： " << "英语" << endl;
			else if (c.peo[i].Subject == 4 && Switch_English) cout << "\tPosition: " << "Politics" << endl;
			else if (c.peo[i].Subject == 4 && !Switch_English) cout << "\t任职： " << "政治" << endl;
			else if (c.peo[i].Subject == 5 && Switch_English) cout << "\tPosition: " << "History" << endl;
			else if (c.peo[i].Subject == 5 && !Switch_English) cout << "\t任职： " << "历史" << endl;
			else if (c.peo[i].Subject == 6 && Switch_English) cout << "\tPosition: " << "Geography" << endl;
			else if (c.peo[i].Subject == 6 && !Switch_English) cout << "\t任职： " << "地理" << endl;
			else if (c.peo[i].Subject == 7 && Switch_English) cout << "\tPosition: " << "Biology" << endl;
			else if (c.peo[i].Subject == 7 && !Switch_English) cout << "\t任职： " << "生物" << endl;
			else if (c.peo[i].Subject == 8 && Switch_English) cout << "\tPosition: " << "Physics" << endl;
			else if (c.peo[i].Subject == 8 && !Switch_English) cout << "\t任职： " << "物理" << endl;
			else if (c.peo[i].Subject == 9 && Switch_English) cout << "\tPosition: " << "Other" << endl;
			else if (c.peo[i].Subject == 9 && !Switch_English) cout << "\t任职： " << "其他" << endl;
			else if (!c.peo[i].Subject && Switch_English) cout << "\ttPosition: " << "NO" << endl;
			else cout << "\t任职： " << "否" << endl;
		}
	}
	else if (slect == "2") {
		// 查看教师
		if (Switch_English) cout << "All teachers information is as follows (any key to continue) : " << endl;
		else cout << "所有的教师信息如下(任意键继续) ： " << endl;
		for (int i = 1; i <= c.tea_num; i++) {
			if (Switch_English) cout << "No." << i << " teacher: " << endl;
			else cout << "第 " << i << " 名： " << endl;
			if (Switch_English) cout << "\tTeacher ID: " << c.Init_Teacher[i].Id << endl;
			else cout << "\t职工号： " << c.Init_Teacher[i].Id << endl;
			if (Switch_English) cout << "\tTeacher Name: " << c.Init_Teacher[i].Name << endl;
			else cout << "\t姓名： " << c.Init_Teacher[i].Name << endl;
			if (Switch_English) cout << "\tTeacher Password: " << c.Init_Teacher[i].Pwd << endl;
			else cout << "\t密码： " << c.Init_Teacher[i].Pwd << endl;
		}
	}
	else if (slect == "3") {
		// 查看管理员
		if (Switch_English) cout << "All administrators information is as follows (any key to continue) : " << endl;
		else cout << "所有的管理员信息如下(任意键继续) ： " << endl;
		for (int i = 1; i <= c.man_num; i++) {
			if (Switch_English) cout << "No." << i << " administrator: " << endl;
			else cout << "第 " << i << " 名： " << endl;
			if (Switch_English) cout << "\tName: " << c.Init_Manager[i].Name << endl;
			else cout << "\t姓名：" << c.Init_Manager[i].Name;
			if (c.Init_Manager[i].Man_Level == 1) { COLOR_PRINT2(" Lv.3", 6); }
			else if (c.Init_Manager[i].Man_Level == 2) { COLOR_PRINT2(" Lv.4", 4); }
			else if (c.Init_Manager[i].Man_Level == 3) { COLOR_PRINT2(" Lv.5", 5); }
			cout << endl;
		}
	}
	else if (slect == "0") {
		if (Switch_English) cout << "Any key to return" << endl;
		else cout << "按任意键返回" << endl;
	}
	else {
		if (Switch_English) cout << "Operation is not standard (any key to continue)" << endl;
		else cout << "操作不合规(任意键继续)" << endl;
	}
	system("pause");
	system("cls");
	return;
}

// 查看排名 
void Manager::View_The_Rankings(bool Switch_English) {
	ifstream ifs;
	ifs.open(SCORE_FILE);
	if (!ifs.is_open()) {
		if (Switch_English) cout << "Failed to open the file(press any key to continue)\n";
		else cout << "文件打开失败(任意键继续)\n";
		system("pause");
		system("cls");
		return;
	}
	long long k = 1, fother = 0, fchinese = 0, fmaths = 0, fenglish = 0, fpolitics = 0, fhistory = 0, fgeography = 0, fbiology = 0, fphysics = 0, ftotal = 0;
	int fid;
	while (ifs >> fid && ifs >> fchinese && ifs >> fmaths && ifs >> fenglish
		&& ifs >> fpolitics && ifs >> fhistory && ifs >> fgeography
		&& ifs >> fbiology && ifs >> fphysics && ifs >> fother && ifs >> ftotal) {
		stu2[k].id = fid;
		stu2[k].chinese = fchinese;
		stu2[k].maths = fmaths;
		stu2[k].english = fenglish;
		stu2[k].politics = fpolitics;
		stu2[k].history = fhistory;
		stu2[k].geography = fgeography;
		stu2[k].biology = fbiology;
		stu2[k].physics = fphysics;
		stu2[k].other = fother;
		stu2[k].total = ftotal;
		k++;
	}
	sort(stu2 + 1, stu2 + c.stu_num + 1, cmp);
	if (Switch_English) cout << "Rank=====ID======Ch======Ma======En======Po======Hi======Ge======Bi======Ph======Other===Total==\n";
	else cout << "名次====学号====语文====数学====英语====政治====历史====地理====生物====物理====其他====总分====\n";
	for (int i = 1; i <= c.stu_num; i++) {
		cout << i << "\t|" << stu2[i].id << "\t|" << stu2[i].chinese << "\t|" << stu2[i].maths << "\t|" << stu2[i].english
			<< "\t|" << stu2[i].politics << "\t|" << stu2[i].history
			<< "\t|" << stu2[i].geography << "\t|" << stu2[i].biology
			<< "\t|" << stu2[i].physics << "\t|" << stu2[i].other << "\t|" << stu2[i].total << "\t|\n";
	}
	cout << "================================================================================================\n";
	system("pause");
	system("cls");
	return;
}

// 导出数据
void Manager::Export_Data(bool Switch_English) {
	ifstream ifs;
	ofstream ofs;
	if (Switch_English) cout << "Please select Export data (1/2/3/0): " << endl;
	else cout << "请选择导出数据(1/2/3/0)： " << endl;
	if (Switch_English) cout << "\t1. Export the change logs\n";
	else cout << "\t1. 导出修改日志\n";
	if (Switch_English) cout << "\t2. Exporting quantitative rankings\n";
	else cout << "\t2. 导出量化排名\n";
	if (Switch_English) cout << "\t3. Export login logs\n";
	else cout << "\t3. 导出登录日志\n";
	if (Switch_English) cout << "\t0. Return\n";
	else cout << "\t0. 返回\n";
	string slect = "0";
	cin >> slect;
	if (slect == "1") {
		ifs.open(JOURNAL_FILE);
		if (!ifs.is_open()) {
			if (Switch_English) cout << "Failed to open the file(press any key to continue)\n";
			else cout << "文件打开失败(任意键继续)\n";
			system("pause");
			system("cls");
			return;
		}
		ofs.open("修改日志.csv", ios::out | ios::trunc);
		string str_year, str_hour, str_name, str_people, str_subject, str_score;
		string str_id;
		if (Switch_English) ofs << "Date, time, modifier, modifier number, subject, score, student number" << endl;
		else ofs << "日期,时间,修改人,修改人数,科目,分数,学号" << endl;
		while (ifs >> str_year && ifs >> str_hour && ifs >> str_name
			&& ifs >> str_people && ifs >> str_subject && ifs >> str_score && ifs >> str_id) {
			ofs << str_year << "," << str_hour << "," << str_name << "," << str_people << "," << str_subject << "," << str_score << "," << str_id << endl;
		}
		man_Time();
		if (Switch_English) cout << "Time, ";
		else cout << "导出时间, ";
		ofs << man_Time_year << "-" << man_Time_mon << "-" << man_Time_day << " " << man_Time_hour << ":" << man_Time_min << ":" << man_Time_sec;
		ifs.close();
		ofs.close();
		if (Switch_English) cout << "Export successful to export to the same folder under the 修改日志.csv!" << endl;
		else cout << "导出成功 以导出到同文件夹下的 修改日志.csv！" << endl;
		system("pause");
		system("cls");
	}
	else if (slect == "2") {
		ifs.open(SCORE_FILE);
		if (!ifs.is_open()) {
			if (Switch_English) cout << "Failed to open the file(press any key to continue)\n";
			else cout << "文件打开失败(任意键继续)\n";
			system("pause");
			system("cls");
			return;
		}
		long long k = 1, fother, fchinese, fmaths, fenglish, fpolitics, fhistory, fgeography, fbiology, fphysics, ftotal;
		int fid;
		while (ifs >> fid && ifs >> fchinese && ifs >> fmaths && ifs >> fenglish
			&& ifs >> fpolitics && ifs >> fhistory && ifs >> fgeography
			&& ifs >> fbiology && ifs >> fphysics && ifs >> fother && ifs >> ftotal) {
			stu2[k].id = fid;
			stu2[k].chinese = fchinese;
			stu2[k].maths = fmaths;
			stu2[k].english = fenglish;
			stu2[k].politics = fpolitics;
			stu2[k].history = fhistory;
			stu2[k].geography = fgeography;
			stu2[k].biology = fbiology;
			stu2[k].physics = fphysics;
			stu2[k].other = fother;
			stu2[k].total = ftotal;
			k++;
		}
		ifs.close();
		sort(stu2 + 1, stu2 + c.stu_num + 1, cmp);
		ofs.open("量化.csv", ios::out | ios::trunc);
		if (Switch_English) ofs << "Student number, rank, name, Chinese, Mathematics, English, Politics, History, Geography, Biology, Physics, others, total score" << endl;
		else ofs << "学号,排名,姓名,语文,数学,英语,政治,历史,地理,生物,物理,其他,总分" << endl;
		for (int i = 1; i <= c.stu_num; i++) {
			for (int j = 1; j <= c.stu_num; j++) {
				int Id = man_string_to_int(c.peo[j].Id);
				if (stu2[i].id == Id) {
					ofs << Id << "," << i << "," << c.peo[j].Name << ",";
					break;
				}
			}
			ofs << stu2[i].chinese << "," << stu2[i].maths << "," << stu2[i].english << ","
				<< stu2[i].politics << "," << stu2[i].history << ","
				<< stu2[i].geography << "," << stu2[i].biology << ","
				<< stu2[i].physics << "," << stu2[i].other << "," << stu2[i].total << endl;
		}
		man_Time();
		if (Switch_English) ofs << "Time, ";
		else ofs << "导出时间, ";
		ofs << man_Time_year << "-" << man_Time_mon << "-" << man_Time_day << " " << man_Time_hour << ":" << man_Time_min << ":" << man_Time_sec;
		ofs.close();
		if (Switch_English) cout << "Export successful to export to the same folder under the 量化.csv!" << endl;
		else cout << "导出成功 以导出到同文件夹下的 量化.csv！" << endl;
		system("pause");
		system("cls");
	}
	else if (slect == "3") {
		ifs.open(LOG_FILE);
		if (!ifs.is_open()) {
			if (Switch_English) cout << "Failed to open the file(press any key to continue)\n";
			else cout << "文件打开失败(任意键继续)\n";
			system("pause");
			system("cls");
			return;
		}
		ofs.open("登录日志.csv", ios::out | ios::trunc);
		string str_year, str_hour, str_name, str_status;
		if (Switch_English) ofs << "Date,Time,Name,Login status" << endl;
		else ofs << "日期,时间,姓名,登录状态" << endl;
		while (ifs >> str_year && ifs >> str_hour && ifs >> str_name && ifs >> str_status) {
			ofs << str_year << "," << str_hour << "," << str_name << ",";
			if (str_status == "1") ofs << "已登录\n";
			else ofs << "退出登录\n";
		}
		man_Time();
		if (Switch_English) cout << "Time, ";
		else cout << "导出时间, ";
		ofs << man_Time_year << "-" << man_Time_mon << "-" << man_Time_day << " " << man_Time_hour << ":" << man_Time_min << ":" << man_Time_sec;
		ifs.close();
		ofs.close();
		if (Switch_English) cout << "Export successful to export to the same folder under the 登录日志.csv!" << endl;
		else cout << "导出成功 以导出到同文件夹下的 登录日志.csv！" << endl;
		system("pause");
		system("cls");
	}
	else if (slect == "0") {
		system("pause");
		system("cls");
	}
	else {
		if (Switch_English) cout << "Operation is not standard (any key to continue)" << endl;
		else cout << "操作不合规(任意键继续)" << endl;
		system("pause");
		system("cls");
	}
	return;
}

// 恢复初始化程序
void Manager::Restore_Initialization(bool Switch_English) {
	ifstream ifs;
	ofstream ofs;
	ifs.open(INIT_FILE, ios::in);
	ofs.open(SCORE_FILE, ios::trunc);
	if (!ifs.is_open()) {
		for (int i = 1; i <= c.stu_num; i++) {
			ofs << i << "\t0\t0\t0\t0\t0\t0\t0\t0\t0\t0\n";
		}
		ofs.close();
		ofs.open(JOURNAL_FILE, ios::trunc);
		ofs.close();
		ofs.open(LOG_FILE, ios::trunc);
		ofs.close();
		if (Switch_English) cout << "Tips: No initialization file found, all quantization scores have been emptied.\n";
		else cout << "tips： 未找到初始化文件，已全部清空量化分数。\n";
	}
	else {
		long long tp0, tp1, tp2, tp3, tp4, tp5, tp6, tp7, tp8, tp9, tp10;
		for (int i = 1; i <= c.stu_num; i++) {
			ifs >> tp0 >> tp1 >> tp2 >> tp3 >> tp4 >> tp5 >> tp6 >> tp7 >> tp8 >> tp9 >> tp10;
			ofs << tp0 << "\t" << tp1 << "\t" << tp2 << "\t" << tp3 << "\t" << tp4 << "\t" << tp5 << "\t" << tp6 << "\t" << tp7 << "\t" << tp8 << "\t" << tp9 << "\t" << tp10 << "\n";
		}
		ofs.close();
		ofs.open(JOURNAL_FILE, ios::trunc);
		ofs.close();
		ofs.open(LOG_FILE, ios::trunc);
		ofs.close();
		if (Switch_English) cout << "Tips: The initialization file has been completed.\n";
		else cout << "tips： 已按照初始化文件完成操作。\n";
	}
	ifs.close();
	if (Switch_English) cout << "Finish!\n";
	else cout << "初始化完毕！\n";
	if (Switch_English) cout << "Block user, late message, and query message to be initialized.\n";
	else cout << "封禁用户、迟到信息和疑问信息待初始化。\n";
	system("pause");
	system("cls");
	return;
}

// 查处账号
void Manager::Investigate_Account(bool Switch_English, int Level) {
	ifstream ifs;
	ofstream ofs;
	if (Switch_English) cout << "Please select the type of investigation (1/2/0): " << endl;
	else cout << "请选择查处类型(1/2/0)： " << endl;
	if (Switch_English) cout << "\t1. Blocked account\n";
	else cout << "\t1. 封禁账户\n";
	if (Switch_English) cout << "\t2. Unseal account\n";
	else cout << "\t2. 解封账户\n";
	if (Switch_English) cout << "\t0. Return\n";
	else cout << "\t0. 返回\n";
	struct Black { string time1, time2; int fid; } p[1005];
	string op = "0", s;
	int Id;
	cin >> op;
	if (op == "1") {
		if (Switch_English) cout << "Please enter the banned student number: ";
		else cout << "请输入封禁学号：";
		cin >> s;
		Id = man_string_to_int(s);
		if (Id == 0x3f3f3f3f || Id < 1 || Id > c.stu_num) {
			if (Switch_English) printf("Invalid input\n");
			else printf("输入学号无效\n");
			system("pause");
			system("cls");
			return;
		}
		ofs.open(BLACK_FILE, ios::app);
		man_Time();
		printf("   %d-%d-%d %d:%d:%d\n", man_Time_year, man_Time_mon, man_Time_day, man_Time_hour, man_Time_min, man_Time_sec);
		if (Switch_English) cout << "\tName: Admin";
		else cout << "\t姓名: Adimin";
		if (Level == 1) { COLOR_PRINT2(" Lv.3", 6); }
		else if (Level == 2) { COLOR_PRINT2(" Lv.4", 4); }
		else if (Level == 3) { COLOR_PRINT2(" Lv.5", 5); }
		cout << endl;
		if (Switch_English) printf("\Ban student number: %d\n", Id);
		else printf("\t封禁学号: %d\n", Id);
		ofs << man_Time_year << "-" << man_Time_mon << "-" << man_Time_day << " " << man_Time_hour << ":" << man_Time_min << ":" << man_Time_sec << " " << Id << endl;
		ofs.close();
		if (Switch_English) cout << "Finish!\n";
		else cout << "封禁成功！\n";
		system("pause");
		system("cls");
	}
	else if (op == "2") {
		if (Switch_English) cout << "Please enter the unblocking student number: ";
		else cout << "请输入解封学号：";
		cin >> s;
		Id = man_string_to_int(s);
		if (Id == 0x3f3f3f3f || Id < 1 || Id > c.stu_num) {
			if (Switch_English) printf("Invalid input\n");
			else printf("输入学号无效\n");
			system("pause");
			system("cls");
			return;
		}
		int i = 1;
		ifs.open(BLACK_FILE, ios::in);
		while (ifs >> p[i].time1 && ifs >> p[i].time2 && ifs >> p[i].fid)
			if (p[i].fid != Id) i++;
		ifs.close();
		ofs.open(BLACK_FILE, ios::trunc);
		for (int k = 1; k < i; k++) ofs << p[k].time1 << " " << p[k].time2 << " " << p[k].fid << endl;
		ofs.close();
		if (Switch_English) cout << "Finish!\n";
		else cout << "解封成功！\n";
		system("pause");
		system("cls");
	}
	else if (op == "0") {
		system("pause");
		system("cls");
	}
	else {
		if (Switch_English) cout << "Operation is not standard (any key to continue)" << endl;
		else cout << "操作不合规(任意键继续)" << endl;
		system("pause");
		system("cls");
	}
	return;
}

// 设置密钥
void Manager::Set_Key(bool Switch_English) {
	ifstream ifs;
	ofstream ofs;
	ofs.open("Keys.csv", ios::trunc);
	char Set_key[105] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '!', '@', '$', '%', '&', '*', ')', '(' };
	srand(time(NULL));
	for (int i = 1; i <= 1000; i++) {
		for (int j = 1; j <= 15; j++) ofs << Set_key[rand() % 70];
		ofs << endl;
	}
	ofs.close();
	ifs.open("Keys.csv", ios::in);
	ofs.open("Keys.txt", ios::trunc);
	string s;
	while (ifs >> s) ofs << "\"" << s << "\", ";
	ifs.close();
	ofs.close();
	if (Switch_English) cout << "Finish!\n";
	else cout << "生成完成，请查看同目录下文件 Keys.csv！\n";
	system("pause");
	system("cls");
	return;
}