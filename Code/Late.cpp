#include"Late.h"
#include"code.h"

Late l;
Code cc;

// �ٵ���Ϣ���� 
struct people {
	string Name_late;
	int id, time;
	int Score, total;
} L_peo[1005], peo_late[1005];
// ѧ�������ݴ� 
struct score {
	int id;
	int chinese, maths, english, politics, history, geography, biology, physics, other, total;
} stu_late[1005];
int Id_late, K;
int late_Time_sec, late_Time_min, late_Time_hour, late_Time_day, late_Time_mon, late_Time_year;

// ʱ�����
void late_Time() {
	SYSTEMTIME st;
	GetLocalTime(&st);
	late_Time_sec = st.wSecond; /*��ȡ��ǰ��*/
	late_Time_min = st.wMinute; /*��ȡ��ǰ��*/
	late_Time_hour = st.wHour;  /*��ȡ��ǰʱ*/
	late_Time_day = st.wDay;    /*��ȡ��ǰ�·�����*/
	late_Time_mon = st.wMonth;  /*��ȡ��ǰ�·�*/
	late_Time_year = st.wYear;  /*��ȡ��ǰ���*/
	return;
}

// ����������ɫ
void COLOR_PRINT3(const char* s, int color) {
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | color);
	printf(s);
	SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | 7);
	return;
}

// ��ʼ��
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

//  �ٵ��ƴ� 
int Late::AddTime(int num_late, int S[], bool Switch_English) {
	ifstream ifs;
	ofstream ofs;
	if (Id_late < 0 || Id_late > cc.stu_num) {
		if (Switch_English) printf("Student not found!\n");
		else printf("δ���ҵ���ѧ����\n");
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
		else cout << "�ļ���ʧ��(���������)\n";
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
		else cout << "�ļ���ʧ��(���������)\n";
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
			cout << "\t����: Admin";
			COLOR_PRINT3(" Lv.5", 5);
			cout << "\n\t�޸�����: 1\n\t��Ŀ: 9\n\t��������: " << -peo_late[S[j]].Score << "\n\t�޸���ѧ��: " << S[j] << "\n";
		}
		ofs << late_Time_year << "-" << late_Time_mon << "-" << late_Time_day << " " << late_Time_hour << ":" << late_Time_min << ":" << late_Time_sec;
		ofs << " Admin 1 9 " << -peo_late[S[j]].Score << " " << S[j] << ",\n";
	}
	ofs.close();
	return 1;
}

//  չʾ�۷� 
int Late::ShowScore(int Id_late, bool Switch_English) {
	ifstream ifs;
	ifs.open(LATE);
	if (!ifs.is_open()) {
		if (Switch_English) cout << "Failed to open the file(press any key to continue)\n";
		else cout << "�ļ���ʧ��(���������)\n";
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
		else printf("δ���ҵ���ѧ����\n");
		return 0;
	}
	Score = (int)pow(2, fTime - 1);
	for (int i = 1; i <= fTime; i++) total += (int)pow(2, i - 1);
	if (fName.size() == 8 && total != 0) {
		cout << "�ǩ������������������������������贈�����������������������������贈�����������������������������贈������������������������������\n"
			<< "��     " << fName << "\t��\t" << fTime << "\t��\t" << -Score << "\t��\t" << -total << "\t��\n";
	}
	else if (total != 0) {
		cout << "�ǩ������������������������������贈�����������������������������贈�����������������������������贈������������������������������\n"
			<< "��     " << fName << "\t��\t" << fTime << "\t��\t" << -Score << "\t��\t" << -total << "\t��\n";
	}
	ifs.close();
	return 1;
}

//  ��ѯ���� 
void Late::ShowDay(int y, int m, int d, bool Switch_English) {
	ifstream ifs;
	ifs.open(H_LATE);
	if (!ifs.is_open()) {
		if (Switch_English) cout << "Failed to open the file(press any key to continue)\n";
		else cout << "�ļ���ʧ��(���������)\n";
		system("pause");
		system("cls");
		return;
	}
	int fy, fm, fd;
	char c;
	string fName;
	bool flag = false;
	if (Switch_English) printf("\n%d-%d-%d The lateness is as follows : \n", y, m, d);
	else printf("\n%d-%d-%d �ٵ���Ա���� �� \n", y, m, d);
	while (ifs >> fy >> c >> fm >> c >> fd >> fName)
		if (fy == y && fm == m && fd == d) {
			cout << fName << " ";
			flag = true;
		}
	if (!flag)
		if (Switch_English) cout << "Nobody\n\n";
		else cout << "��\n\n";
	else cout << "\n\n";
	ifs.close();
	system("pause");
	system("cls");
	return;
}

//  ��ѯ�ٵ���¼ 
int Late::ShowHistory(int Id_late, bool Switch_English) {
	ifstream ifs;
	ifs.open(H_LATE);
	if (!ifs.is_open()) {
		if (Switch_English) cout << "Failed to open the file(press any key to continue)\n";
		else cout << "�ļ���ʧ��(���������)\n";
		system("pause");
		system("cls");
		return 1;
	}
	if (Id_late < 1 || Id_late > cc.stu_num) {
		if (Switch_English) printf("Student not found!\n");
		else printf("δ���ҵ���ѧ����\n");
		return 0;
	}
	int fy, fm, fd;
	char c;
	string fName;
	bool flag = false;
	if (Switch_English) cout << "\n No." << Id_late << " " << peo_late[Id_late].Name_late << " �� \n";
	else cout << "\n " << Id_late << " �� " << peo_late[Id_late].Name_late << " �� \n";
	while (ifs >> fy >> c >> fm >> c >> fd >> fName)
		if (fName == peo_late[Id_late].Name_late) {
			printf("\t\t%d-%d-%d\n", fy, fm, fd);
			flag = true;
		}
	if (!flag)
		if (Switch_English) cout << "\t\tNo late record\n\n";
		else cout << "\t\t�޳ٵ���¼\n\n";
	else cout << "\n";
	ifs.close();
	system("pause");
	system("cls");
	return 1;
}

//  �汾��¼ 
void Late::Colophon(bool Switch_English) {
	system("cls");
	if (Switch_English)
		cout << "\n\n"
		<< "���������������������������������ש���������������������������������������������������������������������������������������������������������������������������������������������������������������\n"
		<< "��  Update date  ��                               Modify content                                  ��\n"
		<< "�ǩ������������������������������贈��������������������������������������������������������������������������������������������������������������������������������������������������������������\n"
		<< "��   2023-05-12  �� Basically set up the framework, and implement a small part of the function    ��\n"
		<< "�ǩ������������������������������贈��������������������������������������������������������������������������������������������������������������������������������������������������������������\n"
		<< "��   2023-05-26  �� Add continuous input late, check the whole class late and deduction           ��\n"
		<< "�ǩ������������������������������贈��������������������������������������������������������������������������������������������������������������������������������������������������������������\n"
		<< "��   2023-05-27  �� It can be used directly with the quantitative system without manual deduction ��\n"
		<< "���������������������������������ߩ���������������������������������������������������������������������������������������������������������������������������������������������������������������\n\n\n";
	else
		cout << "\n\n"
		<< "���������������������������������ש�����������������������������������������������������������������������������������������������\n"
		<< "��      ����     ��                  �޸�����                     ��\n"
		<< "�ǩ������������������������������贈����������������������������������������������������������������������������������������������\n"
		<< "��   2023-05-12  ��  �������ܣ���ʵ��С���ֹ���               ��\n"
		<< "�ǩ������������������������������贈����������������������������������������������������������������������������������������������\n"
		<< "��   2023-05-26  ��  �������¼��ٵ����鿴ȫ��ٵ����۷����     ��\n"
		<< "�ǩ������������������������������贈����������������������������������������������������������������������������������������������\n"
		<< "��   2023-05-27  ��  ������ϵͳֱ������(�ں�)�������˹��۷�       ��\n"
		<< "���������������������������������ߩ�����������������������������������������������������������������������������������������������\n\n\n";
	system("pause");
	system("cls");
	return;
}