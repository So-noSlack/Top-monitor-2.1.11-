#include"Late.h"
#include"code.h"

Late l;
Code cc;

// 迟到信息储存 
struct people {
	string Name_late;
	int id, time;
	int Score, total;
} L_peo[1005], peo_late[1005];
// 学生量化暂存 
struct score {
	int id;
	int chinese, maths, english, politics, history, geography, biology, physics, other, total;
} stu_late[1005];
int Id_late, K;
int late_Time_sec, late_Time_min, late_Time_hour, late_Time_day, late_Time_mon, late_Time_year;

// 时间调用
void late_Time() {
	SYSTEMTIME st;
	GetLocalTime(&st);
	late_Time_sec = st.wSecond; /*获取当前秒*/
	late_Time_min = st.wMinute; /*获取当前分*/
	late_Time_hour = st.wHour;  /*获取当前时*/
	late_Time_day = st.wDay;    /*获取当前月份日数*/
	late_Time_mon = st.wMonth;  /*获取当前月份*/
	late_Time_year = st.wYear;  /*获取当前年份*/
	return;
}

// 设置字体颜色
void COLOR_PRINT3(const char* s, int color) {
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | color);
	printf(s);
	SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | 7);
	return;
}

// 初始化
void Late::Inter() {
	ifstream ifs;
	ifs.open(LATE);
	string fName;
	int fId, fTime, i = 1;
	while (ifs >> fId && ifs >> fName && ifs >> fTime) {
		peo_late[i].id = i, peo_late[i].Name_late = fName, peo_late[i].time = fTime;
		peo_late[i].Score = (int)pow(2, peo_late[i].time - 1);
		for (int j = 1; j <= peo_late[i].time; j++) peo_late[i].total += (int)pow(2, j - 1);
		i++;
	}
	return;
}

//  迟到计次 
int Late::AddTime(int num_late, int S[], bool Switch_English) {
	ifstream ifs;
	ofstream ofs;
	if (Id_late < 0 || Id_late > cc.stu_num) {
		if (Switch_English) printf("Student not found!\n");
		else printf("未查找到该学生！\n");
		return 0;
	}
	for (int j = 1; j <= num_late; j++) {
		peo_late[S[j]].time++;
		peo_late[S[j]].Score = (int)pow(2, peo_late[S[j]].time - 1);
		for (int l = 1; l <= peo_late[S[j]].time; l++) peo_late[S[j]].total += (int)pow(2, l - 1);
	}
	ofs.open(LATE, ios::trunc);
	if (!ofs.is_open()) {
		if (Switch_English) cout << "Failed to open the file(press any key to continue)\n";
		else cout << "文件打开失败(任意键继续)\n";
		system("pause");
		system("cls");
		return 1;
	}
	for (int i = 1; i <= cc.stu_num; i++)
		ofs << peo_late[i].id << "\t" << peo_late[i].Name_late << "\t\t" << peo_late[i].time << "\n";
	ofs.close();
	ofs.open(H_LATE, ios::app);
	late_Time();
	for (int j = 1; j <= num_late - 1; j++)
		ofs << late_Time_year << "-" << late_Time_mon << "-" << late_Time_day << " " << peo_late[S[j]].Name_late << "\n";
	ofs.close();
	ifs.open(SCORE_FILE);
	if (!ifs.is_open()) {
		if (Switch_English) cout << "Failed to open the file(press any key to continue)\n";
		else cout << "文件打开失败(任意键继续)\n";
		system("pause");
		system("cls");
		return 1;
	}
	int fId;
	int fChinese, fMaths, fEnglish, fPolitics, fHistory, fGeography, fBiology, fPhysics, fOther, fTotal, i = 1;
	while (ifs >> fId && ifs >> fChinese && ifs >> fMaths && ifs >> fEnglish
		&& ifs >> fPolitics && ifs >> fHistory && ifs >> fGeography
		&& ifs >> fBiology && ifs >> fPhysics && ifs >> fOther && ifs >> fTotal) {
		stu_late[i].id = fId; stu_late[i].chinese = fChinese; stu_late[i].maths = fMaths;
		stu_late[i].english = fEnglish; stu_late[i].politics = fPolitics; stu_late[i].history = fHistory;
		stu_late[i].geography = fGeography; stu_late[i].biology = fBiology; stu_late[i].physics = fPhysics; stu_late[i].other = fOther;
		for (int j = 1; j <= num_late - 1; j++) {
			if (S[j] == fId) stu_late[i].other -= peo_late[i].Score;
		}
		i++;
	}
	ifs.close();
	ofs.open(SCORE_FILE, ios::trunc);
	for (int i = 1; i <= cc.stu_num; i++) {
		ofs << stu_late[i].id << "\t" << stu_late[i].chinese << "\t" << stu_late[i].maths << "\t" << stu_late[i].english << "\t";
		ofs << stu_late[i].politics << "\t" << stu_late[i].history << "\t";
		ofs << stu_late[i].geography << "\t" << stu_late[i].biology << "\t";
		ofs << stu_late[i].physics << "\t" << stu_late[i].other << "\t";
		stu_late[i].total = stu_late[i].chinese + stu_late[i].maths + stu_late[i].english
			+ stu_late[i].politics + stu_late[i].history
			+ stu_late[i].geography + stu_late[i].biology + stu_late[i].physics + stu_late[i].other;
		ofs << stu_late[i].total << endl;
	}
	ofs.close();
	ofs.open(JOURNAL_FILE, ios::app);
	late_Time();
	for (int j = 1; j <= num_late - 1; j++) {
		cout << "   " << late_Time_year << "-" << late_Time_mon << "-" << late_Time_day << " " << late_Time_hour << ":" << late_Time_min << ":" << late_Time_sec << "\n";
		if (Switch_English) {
			cout << "\tName: Admin";
			COLOR_PRINT3(" Lv.5", 5);
			cout << "\n\tNumber of modifications : 1\n\tSubject: 9\n\tScore: " << -peo_late[S[j]].Score << "\n\tModify student number : " << S[j] << "\n";
		}
		else {
			cout << "\t姓名: Admin";
			COLOR_PRINT3(" Lv.5", 5);
			cout << "\n\t修改人数: 1\n\t科目: 9\n\t波动分数: " << -peo_late[S[j]].Score << "\n\t修改人学号: " << S[j] << "\n";
		}
		ofs << late_Time_year << "-" << late_Time_mon << "-" << late_Time_day << " " << late_Time_hour << ":" << late_Time_min << ":" << late_Time_sec;
		ofs << " Admin 1 9 " << -peo_late[S[j]].Score << " " << S[j] << ",\n";
	}
	ofs.close();
	return 1;
}

//  展示扣分 
int Late::ShowScore(int Id_late, bool Switch_English) {
	ifstream ifs;
	ifs.open(LATE);
	if (!ifs.is_open()) {
		if (Switch_English) cout << "Failed to open the file(press any key to continue)\n";
		else cout << "文件打开失败(任意键继续)\n";
		system("pause");
		system("cls");
		return 1;
	}
	string fName;
	int fId, fTime, Score, total = 0;
	bool flag = false;
	while (ifs >> fId && ifs >> fName && ifs >> fTime)
		if (fId == Id_late) {
			flag = true;
			break;
		}
	if (!flag) {
		if (Switch_English) printf("Student not found!\n");
		else printf("未查找到该学生！\n");
		return 0;
	}
	Score = (int)pow(2, fTime - 1);
	for (int i = 1; i <= fTime; i++) total += (int)pow(2, i - 1);
	if (fName.size() == 8 && total != 0) {
		cout << "┣━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━┫\n"
			<< "┃     " << fName << "\t┃\t" << fTime << "\t┃\t" << -Score << "\t┃\t" << -total << "\t┃\n";
	}
	else if (total != 0) {
		cout << "┣━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━┫\n"
			<< "┃     " << fName << "\t┃\t" << fTime << "\t┃\t" << -Score << "\t┃\t" << -total << "\t┃\n";
	}
	ifs.close();
	return 1;
}

//  查询日期 
void Late::ShowDay(int y, int m, int d, bool Switch_English) {
	ifstream ifs;
	ifs.open(H_LATE);
	if (!ifs.is_open()) {
		if (Switch_English) cout << "Failed to open the file(press any key to continue)\n";
		else cout << "文件打开失败(任意键继续)\n";
		system("pause");
		system("cls");
		return;
	}
	int fy, fm, fd;
	char c;
	string fName;
	bool flag = false;
	if (Switch_English) printf("\n%d-%d-%d The lateness is as follows : \n", y, m, d);
	else printf("\n%d-%d-%d 迟到人员如下 ： \n", y, m, d);
	while (ifs >> fy >> c >> fm >> c >> fd >> fName)
		if (fy == y && fm == m && fd == d) {
			cout << fName << " ";
			flag = true;
		}
	if (!flag)
		if (Switch_English) cout << "Nobody\n\n";
		else cout << "无\n\n";
	else cout << "\n\n";
	ifs.close();
	system("pause");
	system("cls");
	return;
}

//  查询迟到记录 
int Late::ShowHistory(int Id_late, bool Switch_English) {
	ifstream ifs;
	ifs.open(H_LATE);
	if (!ifs.is_open()) {
		if (Switch_English) cout << "Failed to open the file(press any key to continue)\n";
		else cout << "文件打开失败(任意键继续)\n";
		system("pause");
		system("cls");
		return 1;
	}
	if (Id_late < 1 || Id_late > cc.stu_num) {
		if (Switch_English) printf("Student not found!\n");
		else printf("未查找到该学生！\n");
		return 0;
	}
	int fy, fm, fd;
	char c;
	string fName;
	bool flag = false;
	if (Switch_English) cout << "\n No." << Id_late << " " << peo_late[Id_late].Name_late << " ： \n";
	else cout << "\n " << Id_late << " 号 " << peo_late[Id_late].Name_late << " ： \n";
	while (ifs >> fy >> c >> fm >> c >> fd >> fName)
		if (fName == peo_late[Id_late].Name_late) {
			printf("\t\t%d-%d-%d\n", fy, fm, fd);
			flag = true;
		}
	if (!flag)
		if (Switch_English) cout << "\t\tNo late record\n\n";
		else cout << "\t\t无迟到记录\n\n";
	else cout << "\n";
	ifs.close();
	system("pause");
	system("cls");
	return 1;
}

//  版本记录 
void Late::Colophon(bool Switch_English) {
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
		<< "┗━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n\n\n";
	else
		cout << "\n\n"
		<< "┏━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n"
		<< "┃      日期     ┃                  修改内容                     ┃\n"
		<< "┣━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n"
		<< "┃   2023-05-12  ┃  基本搭建框架，并实现小部分功能               ┃\n"
		<< "┣━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n"
		<< "┃   2023-05-26  ┃  添加连续录入迟到，查看全班迟到及扣分情况     ┃\n"
		<< "┣━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n"
		<< "┃   2023-05-27  ┃  与量化系统直接连用(融合)，无需人工扣分       ┃\n"
		<< "┗━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n\n\n";
	system("pause");
	system("cls");
	return;
}