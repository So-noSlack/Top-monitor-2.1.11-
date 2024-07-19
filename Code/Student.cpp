#include"code.h"
#include"Student.h"

Code cod;
Student s;

// ѧ�������ݴ� 
struct stu_score {
	int Id;
	long long Chinese = 0, Maths = 0, English = 0, Politics = 0, History = 0, Geography = 0, Biology = 0, Physics = 0, Other = 0, Total = 0;
} stu[1005], stu2[1005];
// ѧ�����ʴ��� 
struct stu_node {
	string time_1, time_2, name, str;
	string subject;
} p[1005];
int stu_id[1005], stu_num = 1, stu_Subject, stu_sum;
int stu_Time_sec, stu_Time_min, stu_Time_hour, stu_Time_day, stu_Time_mon, stu_Time_year;

// �������� 
bool cmp(stu_score x, stu_score y) { return x.Total > y.Total; }

// ʱ�����
void stu_Time() {
	SYSTEMTIME st;
	GetLocalTime(&st);
	stu_Time_sec = st.wSecond; /*��ȡ��ǰ��*/
	stu_Time_min = st.wMinute; /*��ȡ��ǰ��*/
	stu_Time_hour = st.wHour;  /*��ȡ��ǰʱ*/
	stu_Time_day = st.wDay;    /*��ȡ��ǰ�·�����*/
	stu_Time_mon = st.wMonth;  /*��ȡ��ǰ�·�*/
	stu_Time_year = st.wYear;  /*��ȡ��ǰ���*/
	return;
}

// string ת int
int stu_string_to_int(string str) {
	int a = 0;
	for (int i = (int)str.size() - 1; i >= 0; i--) {
		if ((str[i] > '9' || str[i] < '0') && str[0] != '-') return -0x3f3f3f3f;
		if (str[0] == '-' && i == 0) return -a;
		else a += int(str[i] - '0') * (int)pow(10, str.size() - i - 1);
	}
	return a;
}

// string ���� ת int ����
bool stu_Change_string_to_int(string str[]) {
	for (int i = 1; i <= stu_num; i++)
		for (int j = (int)str[i].size() - 1; j >= 0; j--) {
			if (str[i][j] > '9' || str[i][j] < '0') return false;
			stu_id[i] += int(str[i][j] - '0') * (int)pow(10, str[i].size() - j - 1);
		}
	return true;
}

// ����������ɫ
void COLOR_PRINT(const char* s, int color) {
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | color);
	printf(s);
	SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | 7);
}

// ѧ����ҳ�� 
void Student::Inter_Face(string Name, int Subject, bool Switch_English, int Level) {
	if (Subject && Switch_English) {
		cout << "======================Welcome to Quantitative Management Systems======================\n\n";
		cout << "Notice: Press enter to continue after each input; To change your password, please contact your administrator.\n";
		cout << "Welcome class cadre " << Name;
		if (Level == 1) { COLOR_PRINT(" Lv.3", 6); }
		else if (Level == 2) { COLOR_PRINT(" Lv.4", 4); }
		else if (Level == 3) { COLOR_PRINT(" Lv.5", 5); }
		else if (Subject) { COLOR_PRINT(" Lv.2", 2); }
		cout << " to login!\n";
		cout << "\t\t\t  ------------------------------\n";
		cout << "\t\t\t  |                            |\n";
		cout << "\t\t\t  |  1.Modified quantification |\n";
		cout << "\t\t\t  |                            |\n";
		cout << "\t\t\t  |  2.View the rankings       |\n";
		cout << "\t\t\t  |                            |\n";
		cout << "\t\t\t  |  3.Raise questions         |\n";
		cout << "\t\t\t  |                            |\n";
		cout << "\t\t\t  |  0.Log out                 |\n";
		cout << "\t\t\t  |                            |\n";
		cout << "\t\t\t  ------------------------------\n";
		cout << "Please enter the operation you want to perform (1-3 0 exit): ";
	}
	else if (Subject && !Switch_English) {
		cout << "======================��ӭ������������ϵͳ======================\n\n";
		cout << "���棺 ÿ�������enter�������޸���������ϵ����Ա\n";
		cout << "��ӭ��ɲ� �� " << Name;
		if (Level == 1) { COLOR_PRINT(" Lv.3", 6); }
		else if (Level == 2) { COLOR_PRINT(" Lv.4", 4); }
		else if (Level == 3) { COLOR_PRINT(" Lv.5", 5); }
		else if (Subject) { COLOR_PRINT(" Lv.2", 2); }
		cout << " ��¼��\n";
		cout << "\t\t------------------------------\n";
		cout << "\t\t|                            |\n";
		cout << "\t\t|         1.�޸�����         |\n";
		cout << "\t\t|                            |\n";
		cout << "\t\t|         2.�鿴����         |\n";
		cout << "\t\t|                            |\n";
		cout << "\t\t|         3.�������         |\n";
		cout << "\t\t|                            |\n";
		cout << "\t\t|         0.ע����¼         |\n";
		cout << "\t\t|                            |\n";
		cout << "\t\t------------------------------\n";
		cout << "����������Ҫִ�еĲ���(1-3 0�˳�):";
	}
	else if (!Subject && Switch_English) {
		cout << "======================Welcome to Quantitative Management Systems======================\n\n";
		cout << "Notice: Press enter to continue after each input; To change your password, please contact your administrator.\n";
		cout << "Welcome student " << Name;
		if (Level == 1) { COLOR_PRINT(" Lv.3", 6); }
		else if (Level == 2) { COLOR_PRINT(" Lv.4", 4); }
		else if (Level == 3) { COLOR_PRINT(" Lv.5", 5); }
		else if (!Subject) { COLOR_PRINT(" Lv.1", 1); }
		cout << " to login!\n";
		cout << "\t\t\t  ------------------------------\n";
		cout << "\t\t\t  |                            |\n";
		cout << "\t\t\t  |  1.View the rankings       |\n";
		cout << "\t\t\t  |                            |\n";
		cout << "\t\t\t  |  2.Raise questions         |\n";
		cout << "\t\t\t  |                            |\n";
		cout << "\t\t\t  |  0.Log out                 |\n";
		cout << "\t\t\t  |                            |\n";
		cout << "\t\t\t  ------------------------------\n";
		cout << "Please enter the operation you want to perform (1-2 0 exit): ";
	}
	else {
		cout << "======================��ӭ������������ϵͳ======================\n\n";
		cout << "���棺 ÿ�������enter�������޸���������ϵ����Ա\n";
		cout << "��ӭѧ�� �� " << Name;
		if (Level == 1) { COLOR_PRINT(" Lv.3", 6); }
		else if (Level == 2) { COLOR_PRINT(" Lv.4", 4); }
		else if (Level == 3) { COLOR_PRINT(" Lv.5", 5); }
		else if (!Subject) { COLOR_PRINT(" Lv.1", 1); }
		cout << " ��¼��\n";
		cout << "\t\t------------------------------\n";
		cout << "\t\t|                            |\n";
		cout << "\t\t|         1.�鿴����         |\n";
		cout << "\t\t|                            |\n";
		cout << "\t\t|         2.�������         |\n";
		cout << "\t\t|                            |\n";
		cout << "\t\t|         0.ע����¼         |\n";
		cout << "\t\t|                            |\n";
		cout << "\t\t------------------------------\n";
		cout << "����������Ҫִ�еĲ���(1-2 0�˳�):";
	}
	return;
}

// �޸����� 
void Student::Modified_Quantification(string Name, bool Switch_English, int Subject, int Level) {
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
	stu_num = 1;
	memset(stu_id, 0, sizeof stu_id);
	while (str[stu_num - 1] != "0") cin >> str[stu_num++];
	stu_num--;
	if (str[1] == "0") {
		if (Switch_English) printf("Exiting\n");
		else printf("�����˳�����\n");
		system("pause");
		system("cls");
		return;
	}
	if (stu_num > 100) {
		if (Switch_English) printf("Overpopulation\n");
		else printf("�������࣡\n");
		system("pause");
		system("cls");
		return;
	}
	if (!stu_Change_string_to_int(str)) {
		if (Switch_English) printf("Input error\n");
		else printf("��������\n");
		system("pause");
		system("cls");
		return;
	}
	for (int i = 1; i <= stu_num; i++) {
		if (stu_id[i] > cod.stu_num) {
			if (Switch_English) printf("The student number is not entered correctly\n");
			else printf("����ѧ�Ų���ȷ\n");
			system("pause");
			system("cls");
			return;
		}
	}
	stu_Subject = Subject;
	if (Switch_English) cout << "Please enter the modified score: ";
	else cout << "�������޸ķ���: ";
	cin >> s;
	stu_sum = stu_string_to_int(s);
	if (stu_sum == -0x3f3f3f3f) {
		if (Switch_English) printf("Invalid input\n");
		else printf("������Ч\n");
		system("pause");
		system("cls");
		return;
	}
	for (int i = 1; i <= stu_num; i++) {
		if (stu_Subject == 1) stu[stu_id[i]].Chinese += stu_sum;
		else if (stu_Subject == 2) stu[stu_id[i]].Maths += stu_sum;
		else if (stu_Subject == 3) stu[stu_id[i]].English += stu_sum;
		else if (stu_Subject == 4) stu[stu_id[i]].Politics += stu_sum;
		else if (stu_Subject == 5) stu[stu_id[i]].History += stu_sum;
		else if (stu_Subject == 6) stu[stu_id[i]].Geography += stu_sum;
		else if (stu_Subject == 7) stu[stu_id[i]].Biology += stu_sum;
		else if (stu_Subject == 8) stu[stu_id[i]].Physics += stu_sum;
		else if (stu_Subject == 9) stu[stu_id[i]].Other += stu_sum;
	}
	ofs.open(SCORE_FILE, ios::trunc);
	for (int i = 1; i <= cod.stu_num; i++) {
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
	stu_Time();
	ofs.open(JOURNAL_FILE, ios::app);
	printf("   %d-%d-%d %d:%d:%d\n", stu_Time_year, stu_Time_mon, stu_Time_day, stu_Time_hour, stu_Time_min, stu_Time_sec);
	if (Switch_English) cout << "\tName: " << Name;
	else cout << "\t����: " << Name;
	if (Level == 1) { COLOR_PRINT(" Lv.3", 6); }
	else if (Level == 2) { COLOR_PRINT(" Lv.4", 4); }
	else if (Level == 3) { COLOR_PRINT(" Lv.5", 5); }
	else if (Subject) { COLOR_PRINT(" Lv.2", 2); }
	cout << endl;
	if (Switch_English) printf("\tNumber of modifications: %d\n\tSubject: %d\n\tScore: %d\n\tModify student number: ", stu_num - 1, stu_Subject, stu_sum);
	else printf("\t�޸�����: %d\n\t��Ŀ: %d\n\t��������: %d\n\t�޸���ѧ��: ", stu_num - 1, stu_Subject, stu_sum);
	for (int i = 1; i < stu_num; i++) cout << stu_id[i] << " ";
	cout << endl;
	if (Switch_English) cout << "Your changes have been logged (any key to continue)" << endl;
	else cout << "�ѽ������޸���Ϣ��¼����־(���������)" << endl;
	ofs << stu_Time_year << "-" << stu_Time_mon << "-" << stu_Time_day << " " << stu_Time_hour << ":" << stu_Time_min << ":" << stu_Time_sec;
	ofs << " " << Name << " " << stu_num - 1 << " " << stu_Subject << " " << stu_sum << " ";
	for (int i = 1; i < stu_num; i++) ofs << stu_id[i] << ";";
	ofs << endl;
	ofs.close();
	system("pause");
	system("cls");
	return;
}

// �鿴���� 
void Student::View_The_Rankings(string Id, int Subject, bool Switch_English, int Level) {
	ifstream ifs;
	ifs.open(SCORE_FILE);
	if (!ifs.is_open()) {
		if (Switch_English) cout << "Failed to open the file(press any key to continue)\n";
		else cout << "�ļ���ʧ��(���������)\n";
		system("pause");
		system("cls");
		return;
	}
	int Number, k = 1, fother, fchinese, fmaths, fenglish, fpolitics, fhistory, fgeography, fbiology, fphysics, ftotal;
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
	sort(stu2 + 1, stu2 + cod.stu_num + 1, cmp);
	for (int i = 1; i <= cod.stu_num; i++) {
		int stu_Id = stu_string_to_int(Id);
		if (stu_Id == stu2[i].Id) {
			Number = i;
			break;
		}
	}
	ifs.close();
	ifs.open(SCORE_FILE);
	if (!ifs.is_open()) {
		if (Switch_English) cout << "Failed to open the file(press any key to continue)\n";
		else cout << "�ļ���ʧ��(���������)\n";
		system("pause");
		system("cls");
		return;
	}
	while (ifs >> fid && ifs >> fchinese && ifs >> fmaths && ifs >> fenglish
		&& ifs >> fpolitics && ifs >> fhistory && ifs >> fgeography
		&& ifs >> fbiology && ifs >> fphysics && ifs >> fother && ifs >> ftotal) {
		int stu_Id = stu_string_to_int(Id);
		if (fid == stu_Id) {
			if (Switch_English) {
				cout << cod.peo[fid].Name << "'s";
				if (Level == 1) { COLOR_PRINT(" Lv.3", 6); }
				else if (Level == 2) { COLOR_PRINT(" Lv.4", 4); }
				else if (Level == 3) { COLOR_PRINT(" Lv.5", 5); }
				else if (Subject) { COLOR_PRINT(" Lv.2", 2); }
				else { COLOR_PRINT(" Lv.1", 1); }
				cout << " quantification is as follows: " << endl;
			}
			else {
				cout << cod.peo[fid].Name;
				if (Level == 1) { COLOR_PRINT(" Lv.3", 6); }
				else if (Level == 2) { COLOR_PRINT(" Lv.4", 4); }
				else if (Level == 3) { COLOR_PRINT(" Lv.5", 5); }
				else if (Subject) { COLOR_PRINT(" Lv.2", 2); }
				else { COLOR_PRINT(" Lv.1", 1); }
				cout << " ���������£� " << endl;
			}
			if (Switch_English)
				cout << "����������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n"
				<< "��  Ch   ��  Ma   ��  En   ��  Po   ��  Hi   ��  Ge   ��  Bi   ��  Ph   ��  Ot   ��  To   ��  Ra   ��\n"
				<< "�ǩ�������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n"
				<< "�� " << fchinese << "\t�� " << fmaths << "\t�� " << fenglish
				<< "\t�� " << fpolitics << "\t�� " << fhistory
				<< "\t�� " << fgeography << "\t�� " << fbiology << "\t�� "
				<< fphysics << "\t�� " << fother << "\t�� "
				<< ftotal << "\t�� " << Number << "\t��" << endl
				<< "����������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n";
			else
				cout << "����������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n"
				<< "�� ����  �� ��ѧ  �� Ӣ��  �� ����  �� ��ʷ  �� ����  �� ����  �� ����  �� ����  �� �ܷ�  �� ����  ��\n"
				<< "�ǩ�������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n"
				<< "�� " << fchinese << "\t�� " << fmaths << "\t�� " << fenglish
				<< "\t�� " << fpolitics << "\t�� " << fhistory
				<< "\t�� " << fgeography << "\t�� " << fbiology << "\t�� "
				<< fphysics << "\t�� " << fother << "\t�� "
				<< ftotal << "\t�� " << Number << "\t��" << endl
				<< "����������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n";
			ifs.close();
			break;
		}
	}
	system("pause");
	system("cls");
	ifs.close();
	return;
}

// ������� 
void Student::Raise_Questions(string Name, bool Switch_English) {
	ofstream ofs;
	ofs.open(QUESTION_FILE, ios::app);
	string str;
	int subject;
	if (Switch_English) cout << "Please enter the subject you want to question (1-7 0 exit): ";
	else cout << "��������Ҫ������ʵĿ�Ŀ(1-7 0�˳�)��";
	cin >> subject;
	if (subject == 0) {
		if (Switch_English) printf("Exiting\n");
		else printf("�����˳�����\n");
		system("pause");
		system("cls");
		return;
	}
	if (Switch_English) cout << "Please enter your question: ";
	else cout << "�������������(����)��";
	cin >> str;
	if (Switch_English) cout << "send successfully!" << endl;
	else cout << "���ͳɹ���" << endl;
	system("pause");
	system("cls");
	stu_Time();
	ofs << stu_Time_year << "-" << stu_Time_mon << "-" << stu_Time_day << " " << stu_Time_hour << ":" << stu_Time_min << ":" << stu_Time_sec;
	ofs << " " << Name << " " << subject << " " << str << endl;
	ofs.close();
	return;
}