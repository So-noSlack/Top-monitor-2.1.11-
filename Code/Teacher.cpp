#include"code.h"
#include"Teacher.h"

Code co;
Teacher t;

// ѧ�������ݴ� 
struct score {
	int Id;
	long long Chinese = 0, Maths = 0, English = 0, Politics = 0, History = 0, Geography = 0, Biology = 0, Physics = 0, Other = 0, Total = 0;
} stu[1005], stu2[1005];
// ѧ�����ʴ��� 
struct n {
	string time_1, time_2, name, str;
	string subject;
} p[1005];
int id[1005], num = 1, Subject, sum;
int Time_sec, Time_min, Time_hour, Time_day, Time_mon, Time_year;

// �������� 
bool cmp(score x, score y) { return x.Total > y.Total; }

// ʱ�����
void Time() {
	SYSTEMTIME st;
	GetLocalTime(&st);
	Time_sec = st.wSecond; /*��ȡ��ǰ��*/
	Time_min = st.wMinute; /*��ȡ��ǰ��*/
	Time_hour = st.wHour;  /*��ȡ��ǰʱ*/
	Time_day = st.wDay;    /*��ȡ��ǰ�·�����*/
	Time_mon = st.wMonth;  /*��ȡ��ǰ�·�*/
	Time_year = st.wYear;  /*��ȡ��ǰ���*/
	return;
}

// string ת int
int string_to_int(string str) {
	int a = 0;
	for (int i = (int)str.size() - 1; i >= 0; i--) {
		if ((str[i] > '9' || str[i] < '0') && str[0] != '-') return -0x3f3f3f3f;
		if (str[0] == '-' && i == 0) return -a;
		else a += int(str[i] - '0') * (int)pow(10, str.size() - i - 1);
	}
	return a;
}

// string ���� ת int ����
bool Change_string_to_int(string str[]) {
	for (int i = 1; i <= num; i++)
		for (int j = (int)str[i].size() - 1; j >= 0; j--) {
			if (str[i][j] > '9' || str[i][j] < '0') return false;
			id[i] += int(str[i][j] - '0') * (int)pow(10, str[i].size() - j - 1);
		}
	return true;
}

// ����������ɫ
void COLOR_PRINT4(const char* s, int color) {
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | color);
	printf(s);
	SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | 7);
	return;
}

// ��ʦ��ҳ�� 
void Teacher::Inter_Face(string Id, string Name, bool Switch_English) {
	ifstream ifs(QUESTION_FILE);
	string time_1, time_2, name, str, subject;
	int num = 0;
	while (ifs >> time_1 && ifs >> time_2 && ifs >> name && ifs >> subject && ifs >> str) { if (Id == subject) num++; }
	ifs.close();
	if (Switch_English) {
		printf("======================Welcome to Quantitative Management Systems======================\n\n");
		printf("Notice: Press enter to continue after each input; To change your password, please contact your administrator.\n");
		if (num == 0) cout << "Welcome teacher " << Name << " to login!  You have no message.\n";
		else if (num <= 15) cout << "Welcome teacher " << Name << " to login!  You have " << num << "  message(s) in total.\n";
		else cout << "Welcome teacher " << Name << " to login!  You have 15+ messages in total.\n";
		printf("\t\t\t  ------------------------------\n");
		printf("\t\t\t  |                            |\n");
		printf("\t\t\t  |  1.Modified quantification |\n");
		printf("\t\t\t  |                            |\n");
		printf("\t\t\t  |  2.View the rankings       |\n");
		printf("\t\t\t  |                            |\n");
		printf("\t\t\t  |  3.View log                |\n");
		printf("\t\t\t  |                            |\n");
		printf("\t\t\t  |  4.View account            |\n");
		printf("\t\t\t  |                            |\n");
		printf("\t\t\t  |  5.Export data             |\n");
		printf("\t\t\t  |                            |\n");
		printf("\t\t\t  |  6.View questions          |\n");
		printf("\t\t\t  |                            |\n");
		printf("\t\t\t  |  0.Log out                 |\n");
		printf("\t\t\t  |                            |\n");
		printf("\t\t\t  ------------------------------\n");
		printf("Please enter the operation you want to perform (1-6 0 exit): ");
	}
	else {
		printf("======================��ӭ������������ϵͳ======================\n\n");
		printf("���棺 ÿ�������enter�������޸���������ϵ����Ա\n");
		if (num == 0) cout << "��ӭ��ʦ �� " << Name << "  ��¼��  ������Ϣ\n";
		else if (num <= 15) cout << "��ӭ��ʦ �� " << Name << "  ��¼��  ���й��� " << num << " ����Ϣ\n";
		else cout << "��ӭ��ʦ �� " << Name << "  ��¼��  ���й��� 15+ ����Ϣ\n";
		printf("\t\t------------------------------\n");
		printf("\t\t|                            |\n");
		printf("\t\t|         1.�޸�����         |\n");
		printf("\t\t|                            |\n");
		printf("\t\t|         2.�鿴����         |\n");
		printf("\t\t|                            |\n");
		printf("\t\t|         3.�鿴��־         |\n");
		printf("\t\t|                            |\n");
		printf("\t\t|         4.�鿴�˺�         |\n");
		printf("\t\t|                            |\n");
		printf("\t\t|         5.��������         |\n");
		printf("\t\t|                            |\n");
		printf("\t\t|         6.�鿴����         |\n");
		printf("\t\t|                            |\n");
		printf("\t\t|         0.ע����¼         |\n");
		printf("\t\t|                            |\n");
		printf("\t\t------------------------------\n");
		printf("����������Ҫִ�еĲ���(1-6 0�˳�):");
	}
	return;
}

// �޸����� 
void Teacher::Modified_Quantification(string Name, bool Switch_English) {
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
		stu[i].Id = fId;
		stu[i].Chinese = fChinese;
		stu[i].Maths = fMaths;
		stu[i].English = fEnglish;
		stu[i].Politics = fPolitics;
		stu[i].History = fHistory;
		stu[i].Geography = fGeography;
		stu[i].Biology = fBiology;
		stu[i].Physics = fPhysics;
		stu[i].Other = fOther;
		stu[i].Total = stu[i].Chinese + stu[i].Maths + stu[i].English
			+ stu[i].Politics + stu[i].History + stu[i].Geography
			+ stu[i].Biology + stu[i].Physics + stu[i].Other;
		i++;
	}
	ifs.close();
	string str[1005];
	string k, s;
	if (Switch_English) printf("Please enter the change student number(0 end; Don't > 100): ");
	else printf("�������޸���ѧ�� (�� 0 ����;������ 100 ��)�� ");
	num = 1;
	memset(id, 0, sizeof id);
	while (str[num - 1] != "0") cin >> str[num++];
	num--;
	if (str[1] == "0") {
		if (Switch_English) printf("Exiting\n");
		else printf("�����˳�����\n");
		system("pause");
		system("cls");
		return;
	}
	if (num > 100) {
		if (Switch_English) printf("Overpopulation\n");
		else printf("�������࣡\n");
		system("pause");
		system("cls");
		return;
	}
	if (!Change_string_to_int(str)) {
		if (Switch_English) printf("Input error\n");
		else printf("��������\n");
		system("pause");
		system("cls");
		return;
	}
	for (int i = 1; i <= num; i++) {
		if (id[i] > co.stu_num) {
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
		Subject = string_to_int(k);
		if (Subject == -0x3f3f3f3f) {
			if (Switch_English) printf("Invalid input\n");
			else printf("������Ч\n");
			system("pause");
			system("cls");
			return;
		}
		if (Subject < 1 || Subject > 9) {
			if (Switch_English) cout << "Incorrect account\nPlease enter modify account (1-9): ";
			else cout << "��Ŀ����ȷ\n�������޸Ŀ�Ŀ(1-9): ";
		}
		else break;
	}
	if (Switch_English) cout << "Please enter the modified score: ";
	else cout << "�������޸ķ���: ";
	cin >> s;
	sum = string_to_int(s);
	if (sum == -0x3f3f3f3f) {
		if (Switch_English) printf("Invalid input\n");
		else printf("������Ч\n");
		system("pause");
		system("cls");
		return;
	}
	for (int i = 1; i <= num; i++) {
		if (Subject == 1) stu[id[i]].Chinese += sum;
		else if (Subject == 2) stu[id[i]].Maths += sum;
		else if (Subject == 3) stu[id[i]].English += sum;
		else if (Subject == 4) stu[id[i]].Politics += sum;
		else if (Subject == 5) stu[id[i]].History += sum;
		else if (Subject == 6) stu[id[i]].Geography += sum;
		else if (Subject == 7) stu[id[i]].Biology += sum;
		else if (Subject == 8) stu[id[i]].Physics += sum;
		else if (Subject == 9) stu[id[i]].Other += sum;
	}
	ofs.open(SCORE_FILE, ios::trunc);
	for (int i = 1; i <= co.stu_num; i++) {
		ofs << stu[i].Id << "\t" << stu[i].Chinese << "\t" << stu[i].Maths << "\t" << stu[i].English << "\t";
		ofs << stu[i].Politics << "\t" << stu[i].History << "\t";
		ofs << stu[i].Geography << "\t" << stu[i].Biology << "\t";
		ofs << stu[i].Physics << "\t" << stu[i].Other << "\t";
		stu[i].Total = stu[i].Chinese + stu[i].Maths + stu[i].English
			+ stu[i].Politics + stu[i].History
			+ stu[i].Geography + stu[i].Biology
			+ stu[i].Physics + stu[i].Other;
		ofs << stu[i].Total << endl;
	}
	ofs.close();
	if (Switch_English) cout << "modify successfully! " << endl;
	else cout << "�޸ĳɹ���" << endl;
	Time();
	ofs.open(JOURNAL_FILE, ios::app);
	printf("   %d-%d-%d %d:%d:%d\n", Time_year, Time_mon, Time_day, Time_hour, Time_min, Time_sec);
	if (Switch_English) cout << "\tName: " << Name << endl;
	else cout << "\t����: " << Name << endl;
	if (Switch_English) printf("\tNumber of modifications: %d\n\tSubject: %d\n\tScore: %d\n\tModify student number: ", num - 1, Subject, sum);
	else printf("\t�޸�����: %d\n\t��Ŀ: %d\n\t��������: %d\n\t�޸���ѧ��: ", num - 1, Subject, sum);
	for (int i = 1; i < num; i++) cout << id[i] << " ";
	cout << endl;
	if (Switch_English) cout << "Your changes have been logged (any key to continue)" << endl;
	else cout << "�ѽ������޸���Ϣ��¼����־(���������)" << endl;
	ofs << Time_year << "-" << Time_mon << "-" << Time_day << " " << Time_hour << ":" << Time_min << ":" << Time_sec;
	ofs << " " << Name << " " << num - 1 << " " << Subject << " " << sum << " ";
	for (int i = 1; i < num; i++) ofs << id[i] << ";";
	ofs << endl;
	ofs.close();
	system("pause");
	system("cls");
	return;
}

// �鿴���� 
void Teacher::View_The_Rankings(bool Switch_English) {
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
		stu2[k].Id = fid;
		stu2[k].Chinese = fchinese;
		stu2[k].Maths = fmaths;
		stu2[k].English = fenglish;
		stu2[k].Politics = fpolitics;
		stu2[k].History = fhistory;
		stu2[k].Geography = fgeography;
		stu2[k].Biology = fbiology;
		stu2[k].Physics = fphysics;
		stu2[k].Other = fother;
		stu2[k].Total = ftotal;
		k++;
	}
	sort(stu2 + 1, stu2 + co.stu_num + 1, cmp);
	if (Switch_English) cout << "Rank=====ID======Ch======Ma======En======Po======Hi======Ge======Bi======Ph======Other===Total==\n";
	else cout << "����====ѧ��====����====��ѧ====Ӣ��====����====��ʷ====����====����====����====����====�ܷ�====\n";
	for (int i = 1; i <= co.stu_num; i++) {
		cout << i << "\t|" << stu2[i].Id << "\t|" << stu2[i].Chinese << "\t|" << stu2[i].Maths << "\t|" << stu2[i].English
			<< "\t|" << stu2[i].Politics << "\t|" << stu2[i].History
			<< "\t|" << stu2[i].Geography << "\t|" << stu2[i].Biology
			<< "\t|" << stu2[i].Physics << "\t|" << stu2[i].Other << "\t|" << stu2[i].Total << "\t|\n";
	}
	cout << "================================================================================================\n";
	system("pause");
	system("cls");
	return;
}

// �鿴��־
void Teacher::View_Log(bool Switch_English) {
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
void Teacher::View_Account(bool Switch_English) {
	if (Switch_English) cout << "Please select to view content (1/2/0) : " << endl;
	else cout << "��ѡ��鿴����(1/2/0) �� " << endl;
	if (Switch_English) cout << "\t1. View all students" << endl;
	else cout << "\t1. �鿴����ѧ��" << endl;
	if (Switch_English) cout << "\t2. View all teachers" << endl;
	else cout << "\t2. �鿴���н�ʦ" << endl;
	if (Switch_English) cout << "\t0. Return" << endl;
	else cout << "\t0. ����" << endl;
	string slect = "0";
	string fId, fName, fPwd;
	long long id = 1;
	cin >> slect;
	if (slect == "1") {
		if (Switch_English) cout << "All srudents information is as follows (any key to continue) : " << endl;
		else cout << "���е�ѧ����Ϣ����(���������) �� " << endl;
		for (int i = 1; i <= co.stu_num; i++) {
			if (Switch_English) cout << "No." << i << " student: " << endl;
			else cout << "�� " << i << " ���� " << endl;
			if (Switch_English) cout << "\tStudent ID: " << co.peo[i].Id << endl;
			else cout << "\tѧ�ţ� " << co.peo[i].Id << endl;
			if (Switch_English) cout << "\tStudent Name: " << co.peo[i].Name << endl;
			else cout << "\t������ " << co.peo[i].Name;
			if (co.peo[i].Man_Level == 1) { COLOR_PRINT4(" Lv.3", 6); }
			else if (co.peo[i].Man_Level == 2) { COLOR_PRINT4(" Lv.4", 4); }
			else if (co.peo[i].Man_Level == 3) { COLOR_PRINT4(" Lv.5", 5); }
			else if (co.peo[i].Subject) { COLOR_PRINT4(" Lv.2", 2); }
			else { COLOR_PRINT4(" Lv.1", 1); }
			cout << endl;
			if (Switch_English) cout << "\tStudent Password: " << co.peo[i].Pwd << endl;
			else cout << "\t���룺 " << co.peo[i].Pwd << endl;
			if (co.peo[i].Subject == 1 && Switch_English) cout << "\tPosition: " << "Chinese" << endl;
			else if (co.peo[i].Subject == 1 && !Switch_English) cout << "\t��ְ�� " << "����" << endl;
			else if (co.peo[i].Subject == 2 && Switch_English) cout << "\tPosition: " << "Maths" << endl;
			else if (co.peo[i].Subject == 2 && !Switch_English) cout << "\t��ְ�� " << "��ѧ" << endl;
			else if (co.peo[i].Subject == 3 && Switch_English) cout << "\tPosition: " << "English" << endl;
			else if (co.peo[i].Subject == 3 && !Switch_English) cout << "\t��ְ�� " << "Ӣ��" << endl;
			else if (co.peo[i].Subject == 4 && Switch_English) cout << "\tPosition: " << "Politics" << endl;
			else if (co.peo[i].Subject == 4 && !Switch_English) cout << "\t��ְ�� " << "����" << endl;
			else if (co.peo[i].Subject == 5 && Switch_English) cout << "\tPosition: " << "History" << endl;
			else if (co.peo[i].Subject == 5 && !Switch_English) cout << "\t��ְ�� " << "��ʷ" << endl;
			else if (co.peo[i].Subject == 6 && Switch_English) cout << "\tPosition: " << "Geography" << endl;
			else if (co.peo[i].Subject == 6 && !Switch_English) cout << "\t��ְ�� " << "����" << endl;
			else if (co.peo[i].Subject == 7 && Switch_English) cout << "\tPosition: " << "Biology" << endl;
			else if (co.peo[i].Subject == 7 && !Switch_English) cout << "\t��ְ�� " << "����" << endl;
			else if (co.peo[i].Subject == 8 && Switch_English) cout << "\tPosition: " << "Physics" << endl;
			else if (co.peo[i].Subject == 8 && !Switch_English) cout << "\t��ְ�� " << "����" << endl;
			else if (co.peo[i].Subject == 9 && Switch_English) cout << "\tPosition: " << "Other" << endl;
			else if (co.peo[i].Subject == 9 && !Switch_English) cout << "\t��ְ�� " << "����" << endl;
			else if (!co.peo[i].Subject && Switch_English) cout << "\ttPosition: " << "NO" << endl;
			else cout << "\t��ְ�� " << "��" << endl;
		}
	}
	else if (slect == "2") {
		// �鿴��ʦ
		if (Switch_English) cout << "All teachers information is as follows (any key to continue) : " << endl;
		else cout << "���еĽ�ʦ��Ϣ����(���������) �� " << endl;
		for (int i = 1; i <= co.tea_num; i++) {
			if (Switch_English) cout << "No." << i << " teacher: " << endl;
			else cout << "�� " << i << " ���� " << endl;
			if (Switch_English) cout << "\tTeacher ID: " << co.Init_Teacher[i].Id << endl;
			else cout << "\tְ���ţ� " << co.Init_Teacher[i].Id << endl;
			if (Switch_English) cout << "\tTeacher Name: " << co.Init_Teacher[i].Name << endl;
			else cout << "\t������ " << co.Init_Teacher[i].Name << endl;
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

// ��������
void Teacher::Export_Data(bool Switch_English) {
	ifstream ifs;
	ofstream ofs;
	if (Switch_English) cout << "Please select Export data (1/2/0): " << endl;
	else cout << "��ѡ�񵼳�����(1/2/0)�� " << endl;
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
		ofs.open("����.csv", ios::out | ios::trunc);
		long long k = 1, fother, fchinese, fmaths, fenglish, fpolitics, fhistory, fgeography, fbiology, fphysics, ftotal;
		int fid;
		if (Switch_English) ofs << "Student number, rank, name, Chinese, Mathematics, English, Politics, History, Geography, Biology, Physics, others, total score" << endl;
		else ofs << "ѧ��,����,����,����,��ѧ,Ӣ��,����,��ʷ,����,����,����,����,�ܷ�" << endl;
		while (ifs >> fid && ifs >> fchinese && ifs >> fmaths && ifs >> fenglish
			&& ifs >> fpolitics && ifs >> fhistory && ifs >> fgeography
			&& ifs >> fbiology && ifs >> fphysics && ifs >> fother && ifs >> ftotal) {
			stu2[k].Id = fid, stu2[k].Chinese = fchinese, stu2[k].Maths = fmaths, stu2[k].English = fenglish;
			stu2[k].Politics = fpolitics, stu2[k].History = fhistory, stu2[k].Geography = fgeography;
			stu2[k].Biology = fbiology, stu2[k].Politics = fphysics, stu2[k].Other = fother, stu2[k].Total = ftotal;
			k++;
		}
		sort(stu2 + 1, stu2 + co.stu_num + 1, cmp);
		for (int i = 1; i <= co.stu_num; i++) {
			for (int j = 1; j <= co.stu_num; j++) {
				int Id = string_to_int(co.peo[j].Id);
				if (stu2[i].Id == Id) {
					ofs << Id << "," << i << "," << co.peo[j].Name << ",";
					break;
				}
			}
			ofs << stu2[i].Chinese << "," << stu2[i].Maths << "," << stu2[i].English << ","
				<< stu2[i].Politics << "," << stu2[i].History << ","
				<< stu2[i].Geography << "," << stu2[i].Biology << ","
				<< stu2[i].Physics << "," << stu2[i].Other << "," << stu2[i].Total << endl;
		}
		ifs.close();
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

// �鿴���� 
void Teacher::View_Questions(string Id, bool Switch_English) {
	ifstream ifs;
	ifs.open(QUESTION_FILE);
	if (!ifs.is_open()) {
		if (Switch_English) cout << "Failed to open the file(press any key to continue)\n";
		else cout << "�ļ���ʧ��(���������)\n";
		system("pause");
		system("cls");
		return;
	}
	string time_1, time_2, name, str;
	string subject;
	int num = 0;
	string n;
	if (!(ifs >> time_1 >> time_2 >> name >> subject >> str)) {
		if (Switch_English) cout << "No news\n";
		else cout << "������Ϣ\n";
		system("pause");
		system("cls");
		return;
	}
	else if (Id == subject) {
		if (Switch_English) cout << name << " told you at " << time_1 << " " << time_2 << " that " << str << " ��\n";
		else cout << name << " �� " << time_1 << " " << time_2 << " ���ĸ���˵���� " << str << " ��\n";
	}
	while (ifs >> time_1 && ifs >> time_2 && ifs >> name && ifs >> subject && ifs >> str) {
		if (Id == subject) {
			if (Switch_English) cout << name << " told you at " << time_1 << " " << time_2 << " that " << str << " ��\n";
			else cout << name << " �� " << time_1 << " " << time_2 << " ���ĸ���˵���� " << str << " ��\n";
		}
	}
	if (Switch_English) cout << "Whether to permanently empty message bar (T/F): ";
	else cout << "�Ƿ����������Ϣ��(T/F)�� ";
	cin >> n;
	int k = 1;
	if (n == "T" || n == "t") {
		while (ifs >> time_1 && ifs >> time_2 && ifs >> name && ifs >> subject && ifs >> str)
			if (Id != subject) p[k].time_1 = time_1, p[k].time_2 = time_2, p[k].name = name, p[k].subject = subject, p[k++].str = str;
		ofstream ofs;
		ofs.open(QUESTION_FILE, ios::out | ios::trunc);
		for (int i = 1; i < k; i++)
			ofs << time_1 << " " << time_2 << " " << name << " " << subject << " " << str << endl;
		ofs.close();
		if (Switch_English) cout << "Empty success!\n";
		else cout << "��ճɹ���\n";
	}
	system("pause");
	system("cls");
	ifs.close();
	return;
}