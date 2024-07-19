#include"Manager.h"
#include"code.h"
#include"Other.h"

Code c;
Manager m;

//  ѧ���������� 
struct node {
	int id;
	long long chinese = 0, maths = 0, english = 0, politics = 0, history = 0, geography = 0, biology = 0, physics = 0, other = 0, total = 0;
} stu[1005], stu2[1005];
int man_num = 1, man_sum, man_Subject, man_id[1005];
int man_Time_sec, man_Time_min, man_Time_hour, man_Time_day, man_Time_mon, man_Time_year;
struct Black_p { string time, name; } p[1005], q[1005];

// �������� 
bool cmp(node x, node y) { return x.total > y.total; }

// ʱ�����
void man_Time() {
	SYSTEMTIME st;
	GetLocalTime(&st);
	man_Time_sec = st.wSecond; /*��ȡ��ǰ��*/
	man_Time_min = st.wMinute; /*��ȡ��ǰ��*/
	man_Time_hour = st.wHour;  /*��ȡ��ǰʱ*/
	man_Time_day = st.wDay;    /*��ȡ��ǰ�·�����*/
	man_Time_mon = st.wMonth;  /*��ȡ��ǰ�·�*/
	man_Time_year = st.wYear;  /*��ȡ��ǰ���*/
	return;
}

// string ת int
int man_string_to_int(string str) {
	int a = 0;
	for (int i = (int)str.size() - 1; i >= 0; i--) {
		if (str[i] > '9' || str[i] < '0' && str[0] != '-') return -0x3f3f3f3f;
		if (str[0] == '-' && i == 0) return -a;
		a += int(str[i] - '0') * (int)pow(10, str.size() - i - 1);
	}
	return a;
}

// string ���� ת int ����
bool man_Change_string_to_int(string str[]) {
	for (int i = 1; i <= man_num; i++)
		for (int j = (int)str[i].size() - 1; j >= 0; j--) {
			if (str[i][j] > '9' || str[i][j] < '0') return false;
			man_id[i] += int(str[i][j] - '0') * (int)pow(10, str[i].size() - j - 1);
		}
	return true;
}

// ����������ɫ
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

// �����ҳ�� 
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
		cout << "======================��ӭ������������ϵͳ======================\n\n";
		cout << "���棺 ÿ�������enter��������Ҫ�޸�������ֱ����Դ�����\n";
		cout << "��ӭ����Ա �� " << Name;
		COLOR_PRINT2(" Lv.5", 5);
		cout << " ��¼��\n";
		cout << "\t\t------------------------------\n";
		cout << "\t\t|                            |\t����û���\t\t\t\t\tС���ݣ�\n";
		cout << "\t\t|         1.�޸�����         |\t"; Manage(num1, num2, 1);
		cout << "\t\t|                            |\t"; Manage(num1, num2, 2);
		cout << "\t\t|         2.�鿴��־         |\t"; Manage(num1, num2, 3);
		cout << "\t\t|                            |\t"; Manage(num1, num2, 4);
		cout << "\t\t|         3.�鿴�˺�         |\t"; Manage(num1, num2, 5);
		cout << "\t\t|                            |\t"; Manage(num1, num2, 6);
		cout << "\t\t|         4.�鿴����         |\t"; Manage(num1, num2, 7);
		cout << "\t\t|                            |\t"; Manage(num1, num2, 8);
		cout << "\t\t|         5.��������         |\t"; Manage(num1, num2, 9);
		cout << "\t\t|                            |\t"; Manage(num1, num2, 10);
		cout << "\t\t|         6.�ָ���ʼ��       |\t"; Manage(num1, num2, 11);
		cout << "\t\t|                            |\t"; Manage(num1, num2, 12);
		cout << "\t\t|         7.�鴦�˺�         |\t"; Manage(num1, num2, 13);
		cout << "\t\t|                            |\t"; Manage(num1, num2, 14);
		cout << "\t\t|         8.������Կ         |\t"; Manage(num1, num2, 15);
		cout << "\t\t|                            |\t"; Manage(num1, num2, 16);
		cout << "\t\t|         0.ע����¼         |\t"; Manage(num1, num2, 17);
		cout << "\t\t|                            |\t"; Manage(num1, num2, 18);
		cout << "\t\t------------------------------\n";
		cout << "����������Ҫִ�еĲ���(1-8 0�˳�)�� ";
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
		cout << "======================��ӭ������������ϵͳ======================\n\n";
		cout << "���棺 ÿ�������enter��������Ҫ�޸�������ֱ����Դ�����\n";
		cout << "��ӭ����Ա �� " << Name;
		COLOR_PRINT2(" Lv.4", 4);
		cout << " ��¼��\n";
		cout << "\t\t------------------------------\n";
		cout << "\t\t|                            |\n";
		cout << "\t\t|         1.�޸�����         |\n";
		cout << "\t\t|                            |\n";
		cout << "\t\t|         2.�鿴��־         |\n";
		cout << "\t\t|                            |\n";
		cout << "\t\t|         3.�鿴�˺�         |\n";
		cout << "\t\t|                            |\n";
		cout << "\t\t|         4.�鿴����         |\n";
		cout << "\t\t|                            |\n";
		cout << "\t\t|         5.��������         |\n";
		cout << "\t\t|                            |\n";
		cout << "\t\t|         0.ע����¼         |\n";
		cout << "\t\t|                            |\n";
		cout << "\t\t------------------------------\n";
		cout << "����������Ҫִ�еĲ���(1-5 0�˳�)�� ";
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
		cout << "======================��ӭ������������ϵͳ======================\n\n";
		cout << "���棺 ÿ�������enter��������Ҫ�޸�������ֱ����Դ�����\n";
		cout << "��ӭ����Ա �� " << Name;
		COLOR_PRINT2(" Lv.3", 6);
		cout << " ��¼��\n";
		cout << "\t\t------------------------------\n";
		cout << "\t\t|                            |\n";
		cout << "\t\t|         1.�޸�����         |\n";
		cout << "\t\t|                            |\n";
		cout << "\t\t|         2.�鿴��־         |\n";
		cout << "\t\t|                            |\n";
		cout << "\t\t|         3.�鿴�˺�         |\n";
		cout << "\t\t|                            |\n";
		cout << "\t\t|         4.�鿴����         |\n";
		cout << "\t\t|                            |\n";
		cout << "\t\t|         0.ע����¼         |\n";
		cout << "\t\t|                            |\n";
		cout << "\t\t------------------------------\n";
		cout << "����������Ҫִ�еĲ���(1-4 0�˳�)�� ";
	}
	return;
}

// �޸����� 
void Manager::Modified_Quantification(bool Switch_English, int Level) {
	ifstream ifs;
	ofstream ofs;
	ifs.open(SCORE_FILE);
	if (!ifs.is_open()) {
		if (Switch_English) printf("Failed to open the file(press any key to continue)\n");
		else printf("�ļ���ʧ��(���������)\n");
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
	else printf("�������޸���ѧ�� (�� 0 ����;������ 100 ��)�� ");
	man_num = 1;
	memset(man_id, 0, sizeof man_id);
	while (str[man_num - 1] != "0") cin >> str[man_num++];
	man_num--;
	if (str[1] == "0") {
		if (Switch_English) printf("Exiting\n");
		else printf("�����˳�����\n");
		system("pause");
		system("cls");
		return;
	}
	if (man_num > 100) {
		if (Switch_English) printf("Overpopulation\n");
		else printf("�������࣡\n");
		system("pause");
		system("cls");
		return;
	}
	if (!man_Change_string_to_int(str)) {
		if (Switch_English) printf("Input error\n");
		else printf("��������\n");
		system("pause");
		system("cls");
		return;
	}
	for (int i = 1; i <= man_num; i++) {
		if (man_id[i] > c.stu_num) {
			if (Switch_English) printf("The student number is not entered correctly\n");
			else printf("����ѧ�Ų���ȷ\n");
			system("pause");
			system("cls");
			return;
		}
	}
	if (Switch_English) cout << "Please enter the modified account (1-9): ";
	else cout << "�������޸Ŀ�Ŀ(1-9): ";
	while (cin >> k) {
		man_Subject = man_string_to_int(k);
		if (man_Subject == -0x3f3f3f3f) {
			if (Switch_English) printf("Invalid input\n");
			else printf("������Ч\n");
			system("pause");
			system("cls");
			return;
		}
		if (man_Subject < 1 || man_Subject > 9) {
			if (Switch_English) cout << "Incorrect account\nPlease enter modify account (1-9): ";
			else cout << "��Ŀ����ȷ\n�������޸Ŀ�Ŀ(1-9): ";
		}
		else break;
	}
	if (Switch_English) cout << "Please enter the modified score: ";
	else cout << "�������޸ķ���: ";
	cin >> s;
	man_sum = man_string_to_int(s);
	if (man_sum == -0x3f3f3f3f) {
		if (Switch_English) printf("Invalid input\n");
		else printf("������Ч\n");
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
	else cout << "�޸ĳɹ���" << endl;
	man_Time();
	ofs.open(JOURNAL_FILE, ios::app);
	printf("   %d-%d-%d %d:%d:%d\n", man_Time_year, man_Time_mon, man_Time_day, man_Time_hour, man_Time_min, man_Time_sec);
	if (Switch_English) cout << "\tName: Admin";
	else cout << "\t����: Adimin";
	if (Level == 1) { COLOR_PRINT2(" Lv.3", 6); }
	else if (Level == 2) { COLOR_PRINT2(" Lv.4", 4); }
	else if (Level == 3) { COLOR_PRINT2(" Lv.5", 5); }
	cout << endl;
	if (Switch_English) printf("\tNumber of modifications: %d\n\tSubject: %d\n\tScore: %d\n\tModify student number: ", man_num - 1, man_Subject, man_sum);
	else printf("\t�޸�����: %d\n\t��Ŀ: %d\n\t��������: %d\n\t�޸���ѧ��: ", man_num - 1, man_Subject, man_sum);
	for (int i = 1; i < man_num; i++) cout << man_id[i] << " ";
	cout << endl;
	if (Switch_English) cout << "Your changes have been logged (any key to continue)" << endl;
	else cout << "�ѽ������޸���Ϣ��¼����־(���������)" << endl;
	ofs << man_Time_year << "-" << man_Time_mon << "-" << man_Time_day << " " << man_Time_hour << ":" << man_Time_min << ":" << man_Time_sec;
	ofs << " Admin " << man_num - 1 << " " << man_Subject << " " << man_sum << " ";
	for (int i = 1; i < man_num; i++) ofs << man_id[i] << ";";
	ofs << endl;
	ofs.close();
	system("pause");
	system("cls");
	return;
}

// �鿴��־
void Manager::View_Log(bool Switch_English) {
	ifstream ifs(JOURNAL_FILE, ios::in);
	if (!ifs.is_open()) {
		if (Switch_English) cout << "Failed to open the file(press any key to continue)\n";
		else cout << "�ļ���ʧ��(���������)\n";
		system("pause");
		system("cls");
		return;
	}
	string time_year, time_hour, name, str;
	long long peo_num, subject, score;
	if (!(ifs >> time_year >> time_hour >> name >> peo_num >> subject >> score >> str)) {
		if (Switch_English) cout << "No modification log is displayed\n";
		else cout << "�����޸���־\n";
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
			cout << name << " �� " << time_year << " " << time_hour << " �� " << str;
			if (subject == 1 && score > 0) cout << " �ŵ� ���� ���� ";
			else if (subject == 1 && score < 0) cout << " �ŵ� ���� ���� ";
			else if (subject == 2 && score > 0) cout << " �ŵ� ��ѧ ���� ";
			else if (subject == 2 && score < 0) cout << " �ŵ� ��ѧ ���� ";
			else if (subject == 3 && score > 0) cout << " �ŵ� Ӣ�� ���� ";
			else if (subject == 3 && score < 0) cout << " �ŵ� Ӣ�� ���� ";
			else if (subject == 4 && score > 0) cout << " �ŵ� ���� ���� ";
			else if (subject == 4 && score < 0) cout << " �ŵ� ���� ���� ";
			else if (subject == 5 && score > 0) cout << " �ŵ� ��ʷ ���� ";
			else if (subject == 5 && score < 0) cout << " �ŵ� ��ʷ ���� ";
			else if (subject == 6 && score > 0) cout << " �ŵ� ���� ���� ";
			else if (subject == 6 && score < 0) cout << " �ŵ� ���� ���� ";
			else if (subject == 7 && score > 0) cout << " �ŵ� ���� ���� ";
			else if (subject == 7 && score < 0) cout << " �ŵ� ���� ���� ";
			else if (subject == 8 && score > 0) cout << " �ŵ� ���� ���� ";
			else if (subject == 8 && score < 0) cout << " �ŵ� ���� ���� ";
			else if (subject == 9 && score > 0) cout << " �ŵ� ���� ���� ";
			else if (subject == 9 && score < 0) cout << " �ŵ� ���� ���� ";
			cout << abs(score) << " ��\n";
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
			cout << name << " �� " << time_year << " " << time_hour << " �� " << str;
			if (subject == 1 && score > 0) cout << " �ŵ� ���� ���� ";
			else if (subject == 1 && score < 0) cout << " �ŵ� ���� ���� ";
			else if (subject == 2 && score > 0) cout << " �ŵ� ��ѧ ���� ";
			else if (subject == 2 && score < 0) cout << " �ŵ� ��ѧ ���� ";
			else if (subject == 3 && score > 0) cout << " �ŵ� Ӣ�� ���� ";
			else if (subject == 3 && score < 0) cout << " �ŵ� Ӣ�� ���� ";
			else if (subject == 4 && score > 0) cout << " �ŵ� ���� ���� ";
			else if (subject == 4 && score < 0) cout << " �ŵ� ���� ���� ";
			else if (subject == 5 && score > 0) cout << " �ŵ� ��ʷ ���� ";
			else if (subject == 5 && score < 0) cout << " �ŵ� ��ʷ ���� ";
			else if (subject == 6 && score > 0) cout << " �ŵ� ���� ���� ";
			else if (subject == 6 && score < 0) cout << " �ŵ� ���� ���� ";
			else if (subject == 7 && score > 0) cout << " �ŵ� ���� ���� ";
			else if (subject == 7 && score < 0) cout << " �ŵ� ���� ���� ";
			else if (subject == 8 && score > 0) cout << " �ŵ� ���� ���� ";
			else if (subject == 8 && score < 0) cout << " �ŵ� ���� ���� ";
			else if (subject == 9 && score > 0) cout << " �ŵ� ���� ���� ";
			else if (subject == 9 && score < 0) cout << " �ŵ� ���� ���� ";
			cout << abs(score) << " ��\n";
		}
	}
	system("pause");
	system("cls");
	return;
}

// �鿴�˺�
void Manager::View_Account(bool Switch_English) {
	if (Switch_English) cout << "Please select to view content (1/2/3/0) : " << endl;
	else cout << "��ѡ��鿴����(1/2/3/0) �� " << endl;
	if (Switch_English) cout << "\t1. View all students" << endl;
	else cout << "\t1. �鿴����ѧ��" << endl;
	if (Switch_English) cout << "\t2. View all teachers" << endl;
	else cout << "\t2. �鿴���н�ʦ" << endl;
	if (Switch_English) cout << "\t3. View all administrators" << endl;
	else cout << "\t3. �鿴���й���Ա" << endl;
	if (Switch_English) cout << "\t0. Return" << endl;
	else cout << "\t0. ����" << endl;
	string slect = "0";// �����û�ѡ�� 
	string fId, fName, fPwd;
	long long id = 1;
	cin >> slect;
	if (slect == "1") {
		if (Switch_English) cout << "All srudents information is as follows (any key to continue) : " << endl;
		else cout << "���е�ѧ����Ϣ����(���������) �� " << endl;
		for (int i = 1; i <= c.stu_num; i++) {
			if (Switch_English) cout << "No." << i << " student: " << endl;
			else cout << "�� " << i << " ���� " << endl;
			if (Switch_English) cout << "\tStudent ID: " << c.peo[i].Id << endl;
			else cout << "\tѧ�ţ� " << c.peo[i].Id << endl;
			if (Switch_English) cout << "\tStudent Name: " << c.peo[i].Name << endl;
			else cout << "\t������ " << c.peo[i].Name;
			if (c.peo[i].Man_Level == 1) { COLOR_PRINT2(" Lv.3", 6); }
			else if (c.peo[i].Man_Level == 2) { COLOR_PRINT2(" Lv.4", 4); }
			else if (c.peo[i].Man_Level == 3) { COLOR_PRINT2(" Lv.5", 5); }
			else if (c.peo[i].Subject) { COLOR_PRINT2(" Lv.2", 2); }
			else { COLOR_PRINT2(" Lv.1", 1); }
			cout << endl;
			if (Switch_English) cout << "\tStudent Password: " << c.peo[i].Pwd << endl;
			else cout << "\t���룺 " << c.peo[i].Pwd << endl;
			if (c.peo[i].Subject == 1 && Switch_English) cout << "\tPosition: " << "Chinese" << endl;
			else if (c.peo[i].Subject == 1 && !Switch_English) cout << "\t��ְ�� " << "����" << endl;
			else if (c.peo[i].Subject == 2 && Switch_English) cout << "\tPosition: " << "Maths" << endl;
			else if (c.peo[i].Subject == 2 && !Switch_English) cout << "\t��ְ�� " << "��ѧ" << endl;
			else if (c.peo[i].Subject == 3 && Switch_English) cout << "\tPosition: " << "English" << endl;
			else if (c.peo[i].Subject == 3 && !Switch_English) cout << "\t��ְ�� " << "Ӣ��" << endl;
			else if (c.peo[i].Subject == 4 && Switch_English) cout << "\tPosition: " << "Politics" << endl;
			else if (c.peo[i].Subject == 4 && !Switch_English) cout << "\t��ְ�� " << "����" << endl;
			else if (c.peo[i].Subject == 5 && Switch_English) cout << "\tPosition: " << "History" << endl;
			else if (c.peo[i].Subject == 5 && !Switch_English) cout << "\t��ְ�� " << "��ʷ" << endl;
			else if (c.peo[i].Subject == 6 && Switch_English) cout << "\tPosition: " << "Geography" << endl;
			else if (c.peo[i].Subject == 6 && !Switch_English) cout << "\t��ְ�� " << "����" << endl;
			else if (c.peo[i].Subject == 7 && Switch_English) cout << "\tPosition: " << "Biology" << endl;
			else if (c.peo[i].Subject == 7 && !Switch_English) cout << "\t��ְ�� " << "����" << endl;
			else if (c.peo[i].Subject == 8 && Switch_English) cout << "\tPosition: " << "Physics" << endl;
			else if (c.peo[i].Subject == 8 && !Switch_English) cout << "\t��ְ�� " << "����" << endl;
			else if (c.peo[i].Subject == 9 && Switch_English) cout << "\tPosition: " << "Other" << endl;
			else if (c.peo[i].Subject == 9 && !Switch_English) cout << "\t��ְ�� " << "����" << endl;
			else if (!c.peo[i].Subject && Switch_English) cout << "\ttPosition: " << "NO" << endl;
			else cout << "\t��ְ�� " << "��" << endl;
		}
	}
	else if (slect == "2") {
		// �鿴��ʦ
		if (Switch_English) cout << "All teachers information is as follows (any key to continue) : " << endl;
		else cout << "���еĽ�ʦ��Ϣ����(���������) �� " << endl;
		for (int i = 1; i <= c.tea_num; i++) {
			if (Switch_English) cout << "No." << i << " teacher: " << endl;
			else cout << "�� " << i << " ���� " << endl;
			if (Switch_English) cout << "\tTeacher ID: " << c.Init_Teacher[i].Id << endl;
			else cout << "\tְ���ţ� " << c.Init_Teacher[i].Id << endl;
			if (Switch_English) cout << "\tTeacher Name: " << c.Init_Teacher[i].Name << endl;
			else cout << "\t������ " << c.Init_Teacher[i].Name << endl;
			if (Switch_English) cout << "\tTeacher Password: " << c.Init_Teacher[i].Pwd << endl;
			else cout << "\t���룺 " << c.Init_Teacher[i].Pwd << endl;
		}
	}
	else if (slect == "3") {
		// �鿴����Ա
		if (Switch_English) cout << "All administrators information is as follows (any key to continue) : " << endl;
		else cout << "���еĹ���Ա��Ϣ����(���������) �� " << endl;
		for (int i = 1; i <= c.man_num; i++) {
			if (Switch_English) cout << "No." << i << " administrator: " << endl;
			else cout << "�� " << i << " ���� " << endl;
			if (Switch_English) cout << "\tName: " << c.Init_Manager[i].Name << endl;
			else cout << "\t������" << c.Init_Manager[i].Name;
			if (c.Init_Manager[i].Man_Level == 1) { COLOR_PRINT2(" Lv.3", 6); }
			else if (c.Init_Manager[i].Man_Level == 2) { COLOR_PRINT2(" Lv.4", 4); }
			else if (c.Init_Manager[i].Man_Level == 3) { COLOR_PRINT2(" Lv.5", 5); }
			cout << endl;
		}
	}
	else if (slect == "0") {
		if (Switch_English) cout << "Any key to return" << endl;
		else cout << "�����������" << endl;
	}
	else {
		if (Switch_English) cout << "Operation is not standard (any key to continue)" << endl;
		else cout << "�������Ϲ�(���������)" << endl;
	}
	system("pause");
	system("cls");
	return;
}

// �鿴���� 
void Manager::View_The_Rankings(bool Switch_English) {
	ifstream ifs;
	ifs.open(SCORE_FILE);
	if (!ifs.is_open()) {
		if (Switch_English) cout << "Failed to open the file(press any key to continue)\n";
		else cout << "�ļ���ʧ��(���������)\n";
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
	else cout << "����====ѧ��====����====��ѧ====Ӣ��====����====��ʷ====����====����====����====����====�ܷ�====\n";
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

// ��������
void Manager::Export_Data(bool Switch_English) {
	ifstream ifs;
	ofstream ofs;
	if (Switch_English) cout << "Please select Export data (1/2/3/0): " << endl;
	else cout << "��ѡ�񵼳�����(1/2/3/0)�� " << endl;
	if (Switch_English) cout << "\t1. Export the change logs\n";
	else cout << "\t1. �����޸���־\n";
	if (Switch_English) cout << "\t2. Exporting quantitative rankings\n";
	else cout << "\t2. ������������\n";
	if (Switch_English) cout << "\t3. Export login logs\n";
	else cout << "\t3. ������¼��־\n";
	if (Switch_English) cout << "\t0. Return\n";
	else cout << "\t0. ����\n";
	string slect = "0";
	cin >> slect;
	if (slect == "1") {
		ifs.open(JOURNAL_FILE);
		if (!ifs.is_open()) {
			if (Switch_English) cout << "Failed to open the file(press any key to continue)\n";
			else cout << "�ļ���ʧ��(���������)\n";
			system("pause");
			system("cls");
			return;
		}
		ofs.open("�޸���־.csv", ios::out | ios::trunc);
		string str_year, str_hour, str_name, str_people, str_subject, str_score;
		string str_id;
		if (Switch_English) ofs << "Date, time, modifier, modifier number, subject, score, student number" << endl;
		else ofs << "����,ʱ��,�޸���,�޸�����,��Ŀ,����,ѧ��" << endl;
		while (ifs >> str_year && ifs >> str_hour && ifs >> str_name
			&& ifs >> str_people && ifs >> str_subject && ifs >> str_score && ifs >> str_id) {
			ofs << str_year << "," << str_hour << "," << str_name << "," << str_people << "," << str_subject << "," << str_score << "," << str_id << endl;
		}
		man_Time();
		if (Switch_English) cout << "Time, ";
		else cout << "����ʱ��, ";
		ofs << man_Time_year << "-" << man_Time_mon << "-" << man_Time_day << " " << man_Time_hour << ":" << man_Time_min << ":" << man_Time_sec;
		ifs.close();
		ofs.close();
		if (Switch_English) cout << "Export successful to export to the same folder under the �޸���־.csv!" << endl;
		else cout << "�����ɹ� �Ե�����ͬ�ļ����µ� �޸���־.csv��" << endl;
		system("pause");
		system("cls");
	}
	else if (slect == "2") {
		ifs.open(SCORE_FILE);
		if (!ifs.is_open()) {
			if (Switch_English) cout << "Failed to open the file(press any key to continue)\n";
			else cout << "�ļ���ʧ��(���������)\n";
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
		ofs.open("����.csv", ios::out | ios::trunc);
		if (Switch_English) ofs << "Student number, rank, name, Chinese, Mathematics, English, Politics, History, Geography, Biology, Physics, others, total score" << endl;
		else ofs << "ѧ��,����,����,����,��ѧ,Ӣ��,����,��ʷ,����,����,����,����,�ܷ�" << endl;
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
		else ofs << "����ʱ��, ";
		ofs << man_Time_year << "-" << man_Time_mon << "-" << man_Time_day << " " << man_Time_hour << ":" << man_Time_min << ":" << man_Time_sec;
		ofs.close();
		if (Switch_English) cout << "Export successful to export to the same folder under the ����.csv!" << endl;
		else cout << "�����ɹ� �Ե�����ͬ�ļ����µ� ����.csv��" << endl;
		system("pause");
		system("cls");
	}
	else if (slect == "3") {
		ifs.open(LOG_FILE);
		if (!ifs.is_open()) {
			if (Switch_English) cout << "Failed to open the file(press any key to continue)\n";
			else cout << "�ļ���ʧ��(���������)\n";
			system("pause");
			system("cls");
			return;
		}
		ofs.open("��¼��־.csv", ios::out | ios::trunc);
		string str_year, str_hour, str_name, str_status;
		if (Switch_English) ofs << "Date,Time,Name,Login status" << endl;
		else ofs << "����,ʱ��,����,��¼״̬" << endl;
		while (ifs >> str_year && ifs >> str_hour && ifs >> str_name && ifs >> str_status) {
			ofs << str_year << "," << str_hour << "," << str_name << ",";
			if (str_status == "1") ofs << "�ѵ�¼\n";
			else ofs << "�˳���¼\n";
		}
		man_Time();
		if (Switch_English) cout << "Time, ";
		else cout << "����ʱ��, ";
		ofs << man_Time_year << "-" << man_Time_mon << "-" << man_Time_day << " " << man_Time_hour << ":" << man_Time_min << ":" << man_Time_sec;
		ifs.close();
		ofs.close();
		if (Switch_English) cout << "Export successful to export to the same folder under the ��¼��־.csv!" << endl;
		else cout << "�����ɹ� �Ե�����ͬ�ļ����µ� ��¼��־.csv��" << endl;
		system("pause");
		system("cls");
	}
	else if (slect == "0") {
		system("pause");
		system("cls");
	}
	else {
		if (Switch_English) cout << "Operation is not standard (any key to continue)" << endl;
		else cout << "�������Ϲ�(���������)" << endl;
		system("pause");
		system("cls");
	}
	return;
}

// �ָ���ʼ������
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
		else cout << "tips�� δ�ҵ���ʼ���ļ�����ȫ���������������\n";
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
		else cout << "tips�� �Ѱ��ճ�ʼ���ļ���ɲ�����\n";
	}
	ifs.close();
	if (Switch_English) cout << "Finish!\n";
	else cout << "��ʼ����ϣ�\n";
	if (Switch_English) cout << "Block user, late message, and query message to be initialized.\n";
	else cout << "����û����ٵ���Ϣ��������Ϣ����ʼ����\n";
	system("pause");
	system("cls");
	return;
}

// �鴦�˺�
void Manager::Investigate_Account(bool Switch_English, int Level) {
	ifstream ifs;
	ofstream ofs;
	if (Switch_English) cout << "Please select the type of investigation (1/2/0): " << endl;
	else cout << "��ѡ��鴦����(1/2/0)�� " << endl;
	if (Switch_English) cout << "\t1. Blocked account\n";
	else cout << "\t1. ����˻�\n";
	if (Switch_English) cout << "\t2. Unseal account\n";
	else cout << "\t2. ����˻�\n";
	if (Switch_English) cout << "\t0. Return\n";
	else cout << "\t0. ����\n";
	struct Black { string time1, time2; int fid; } p[1005];
	string op = "0", s;
	int Id;
	cin >> op;
	if (op == "1") {
		if (Switch_English) cout << "Please enter the banned student number: ";
		else cout << "��������ѧ�ţ�";
		cin >> s;
		Id = man_string_to_int(s);
		if (Id == 0x3f3f3f3f || Id < 1 || Id > c.stu_num) {
			if (Switch_English) printf("Invalid input\n");
			else printf("����ѧ����Ч\n");
			system("pause");
			system("cls");
			return;
		}
		ofs.open(BLACK_FILE, ios::app);
		man_Time();
		printf("   %d-%d-%d %d:%d:%d\n", man_Time_year, man_Time_mon, man_Time_day, man_Time_hour, man_Time_min, man_Time_sec);
		if (Switch_English) cout << "\tName: Admin";
		else cout << "\t����: Adimin";
		if (Level == 1) { COLOR_PRINT2(" Lv.3", 6); }
		else if (Level == 2) { COLOR_PRINT2(" Lv.4", 4); }
		else if (Level == 3) { COLOR_PRINT2(" Lv.5", 5); }
		cout << endl;
		if (Switch_English) printf("\Ban student number: %d\n", Id);
		else printf("\t���ѧ��: %d\n", Id);
		ofs << man_Time_year << "-" << man_Time_mon << "-" << man_Time_day << " " << man_Time_hour << ":" << man_Time_min << ":" << man_Time_sec << " " << Id << endl;
		ofs.close();
		if (Switch_English) cout << "Finish!\n";
		else cout << "����ɹ���\n";
		system("pause");
		system("cls");
	}
	else if (op == "2") {
		if (Switch_English) cout << "Please enter the unblocking student number: ";
		else cout << "��������ѧ�ţ�";
		cin >> s;
		Id = man_string_to_int(s);
		if (Id == 0x3f3f3f3f || Id < 1 || Id > c.stu_num) {
			if (Switch_English) printf("Invalid input\n");
			else printf("����ѧ����Ч\n");
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
		else cout << "���ɹ���\n";
		system("pause");
		system("cls");
	}
	else if (op == "0") {
		system("pause");
		system("cls");
	}
	else {
		if (Switch_English) cout << "Operation is not standard (any key to continue)" << endl;
		else cout << "�������Ϲ�(���������)" << endl;
		system("pause");
		system("cls");
	}
	return;
}

// ������Կ
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
	else cout << "������ɣ���鿴ͬĿ¼���ļ� Keys.csv��\n";
	system("pause");
	system("cls");
	return;
}