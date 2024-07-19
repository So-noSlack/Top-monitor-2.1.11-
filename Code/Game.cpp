#include"Game.h"
#include"code.h"

/*======================================文字游戏======================================*/
/*====================================================================================*/

struct node {
	int x, y;
} peo;
struct Ghost {
	int x, y;
	bool t;
} g[1005];
char Words_port;
bool flag_win = false;
int m, n, p, num_m = 1, gh = 0;
string map[105][105];
string Massages[100005];

void ShowCursor(bool visible) { //显示或隐藏光标
	CONSOLE_CURSOR_INFO cursor_info = { 20, visible };
	//CONSOLE_CURSOR_INFO结构体包含控制台光标信息，成员分别表示光标百分比厚度和是否可见
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
	//SetConsoleCursorInfo设定控制台窗口的光标大小和是否可见
}

void Windows_System() {
	ShowCursor(false);
	return;
}

void Face() {
	printf("\t\t================================\n");
	printf("\t\t|          1.继续游戏          |\n");
	printf("\t\t|------------------------------|\n");
	printf("\t\t|          2.从头开始          |\n");
	printf("\t\t|------------------------------|\n");
	printf("\t\t|          0.退出游戏          |\n");
	printf("\t\t================================\n");
	printf("请按下你的选择\n");
	return;
}

void up() { map[peo.x - 1][peo.y] = "我"; map[peo.x][peo.y] = "  "; peo.x--; system("cls"); return; }
void down() { map[peo.x + 1][peo.y] = "我"; map[peo.x][peo.y] = "  "; peo.x++; system("cls"); return; }
void left() { map[peo.x][peo.y - 1] = "我"; map[peo.x][peo.y] = "  "; peo.y--; system("cls"); return; }
void right() { map[peo.x][peo.y + 1] = "我"; map[peo.x][peo.y] = "  "; peo.y++; system("cls"); return; }
void mem() { for (int i = 1; i < 100; i++) for (int j = 1; j < 100; j++) map[i][j] = "  "; return; }

//                      Level 1
/*=======================================================*/

void level_1() {
	mem();
	for (int i = 1; i <= 1005; i++) Massages[i] = " "; num_m = 1;
	map[1][1] = "墙"; map[1][3] = "墙"; map[1][4] = "墙"; map[1][5] = "墙"; map[1][6] = "墙"; map[2][1] = "墙"; map[2][6] = "墙";
	map[3][1] = "墙"; map[3][6] = "墙"; map[4][1] = "墙"; map[4][6] = "墙"; map[5][1] = "墙"; map[5][2] = "墙"; map[5][3] = "墙";
	map[5][4] = "墙"; map[5][5] = "墙"; map[5][6] = "墙";
	map[4][5] = "我"; map[1][2] = "门"; peo.x = 4, peo.y = 5; n = 5, m = 6;
	Massages[0] = "输入 0 退出此关卡";
	return;
}

void print_level_1() {
	cout << "=====Level 1=====\n";
	for (int i = 1; i <= n; i++) {
		cout << "  ";
		for (int j = 1; j <= m; j++) cout << map[i][j];
		cout << endl;
	}
	for (int i = 0; i <= num_m - 1; i++) cout << Massages[i] << endl;
	return;
}

/*=======================================================*/

//                      Level 2
/*=======================================================*/

void level_2() {
	mem();
	for (int i = 1; i <= 1005; i++) Massages[i] = " "; num_m = 1;
	for (int i = 1; i <= 10; i++)
		for (int j = 1; j <= 20; j++)
			map[i][j] = "墙";
	for (int i = 2; i <= 9; i++)
		for (int j = 2; j <= 12; j++)
			map[i][j] = "  ";
	for (int i = 8; i <= 9; i++)
		for (int j = 13; j <= 19; j++)
			map[i][j] = "  ";
	for (int i = 2; i <= 6; i++)
		for (int j = 14; j <= 19; j++)
			map[i][j] = "  ";
	map[2][2] = "我";
	map[3][20] = "门";
	map[6][8] = "破";
	peo.x = 2, peo.y = 2; n = 10, m = 20;
	Massages[0] = "输入 0 退出此关卡";
	return;
}

void print_level_2() {
	cout << "====================Level 2====================\n";
	for (int i = 1; i <= n; i++) {
		cout << "    ";
		for (int j = 1; j <= m; j++) cout << map[i][j];
		cout << endl;
	}
	for (int i = 0; i <= num_m - 1; i++) cout << Massages[i] << endl;
	return;
}

bool Put_to(int x) {
	if (x == 1) {
		map[peo.x][peo.y] = "  ", map[peo.x - 1][peo.y] = "我", map[peo.x - 2][peo.y] = "破";
		peo.x--;
		system("cls");
		return true;
	}
	else if (x == 2) {
		map[peo.x][peo.y] = "  ", map[peo.x + 1][peo.y] = "我", map[peo.x + 2][peo.y] = "破";
		peo.x++;
		system("cls");
		return true;
	}
	else if (x == 3) {
		map[peo.x][peo.y] = "  ", map[peo.x][peo.y - 1] = "我", map[peo.x][peo.y - 2] = "破";
		peo.y--;
		system("cls");
		return true;
	}
	else if (x == 4) {
		map[peo.x][peo.y] = "  ", map[peo.x][peo.y + 1] = "我", map[peo.x][peo.y + 2] = "破";
		peo.y++;
		system("cls");
		return true;
	}
	return false;
}

/*=======================================================*/

//                      Level 3
/*=======================================================*/

void level_3() {
	mem();
	for (int i = 1; i <= 1005; i++) Massages[i] = " "; num_m = 1;
	for (int i = 1; i <= 25; i++)
		for (int j = 1; j <= 20; j++)
			map[i][j] = "墙";
	for (int i = 2; i <= 9; i++)
		for (int j = 2; j <= 19; j++)
			map[i][j] = "  ";
	for (int j = 2; j <= 19; j++) map[11][j] = "  ";
	for (int j = 2; j <= 19; j++) map[12][j] = "  ";
	for (int i = 14; i <= 17; i++)
		for (int j = 2; j <= 19; j++)
			map[i][j] = "  ";
	for (int i = 19; i <= 24; i++)
		for (int j = 2; j <= 19; j++)
			map[i][j] = "  ";
	map[10][4] = map[13][16] = map[18][10] = "  ";
	map[2][2] = "我";
	map[25][10] = "门";
	map[11][2] = map[12][19] = map[14][2] = map[15][19] = map[16][2] = map[17][19] = map[19][19] = map[20][2] = map[21][19] = map[22][2] = map[23][19] = "鬼";
	peo.x = 2, peo.y = 2; n = 25, m = 20, gh = 11;
	g[1].x = 11, g[1].y = 2; g[2].x = 12, g[2].y = 19; g[3].x = 14, g[3].y = 2; g[4].x = 15, g[4].y = 19; g[5].x = 16, g[5].y = 2;
	g[6].x = 17, g[6].y = 19; g[7].x = 19, g[7].y = 19; g[8].x = 20, g[8].y = 2; g[9].x = 21, g[9].y = 19; g[10].x = 22, g[10].y = 2;
	g[11].x = 23, g[11].y = 19;
	g[1].t = 1, g[2].t = 0; g[3].t = 1, g[4].t = 0; g[5].t = 1, g[6].t = 0; g[7].t = 0, g[8].t = 1; g[9].t = 0, g[10].t = 1; g[11].t = 0;
	Massages[0] = "输入 0 退出此关卡";
	return;
}

void print_level_3() {
	cout << "====================Level 3====================\n";
	for (int i = 1; i <= n; i++) {
		cout << "    ";
		for (int j = 1; j <= m; j++) cout << map[i][j];
		cout << endl;
	}
	for (int i = 0; i <= num_m - 1; i++) cout << Massages[i] << endl;
	return;
}

void Ghosts() {
	Sleep(50);
	for (int i = 1; i <= gh; i++) {
		if (g[i].t)
			if (map[g[i].x][g[i].y + 1] == "墙") g[i].t = 0, map[g[i].x][g[i].y] = "  ", map[g[i].x][--g[i].y] = "鬼";
			else if (map[g[i].x][g[i].y + 1] == "我") flag_win = false;
			else map[g[i].x][g[i].y] = "  ", map[g[i].x][++g[i].y] = "鬼";
		else
			if (map[g[i].x][g[i].y - 1] == "墙") g[i].t = 1, map[g[i].x][g[i].y] = "  ", map[g[i].x][++g[i].y] = "鬼";
			else if (map[g[i].x][g[i].y - 1] == "我") flag_win = false;
			else map[g[i].x][g[i].y] = "  ", map[g[i].x][--g[i].y] = "鬼";
	}
	return;
}

/*=======================================================*/

void run(int level) {
	if (level == 1) {
		level_1();
		print_level_1();
		while (true) {
			Words_port = _getch();
			if (num_m >= 20) {
				for (int i = 1; i <= 20; i++) Massages[i] = " ";
				num_m = 1;
				system("cls");
				print_level_1();
			}
			if (Words_port == '0') {
				system("cls");
				return;
			}
			else if ((Words_port == 'w' || Words_port == 'W') && map[peo.x - 1][peo.y] == "门") {
				printf("恭喜通关！\n");
				for (int i = 1; i <= 1005; i++) Massages[i] = " ";
				num_m = 1;
				ofstream ofs;
				ofs.open("Level.dat", ios::out);
				ofs << 2;
				ofs.close();
				system("pause");
				system("cls");
				return;
			}
			else if (Words_port == 'w' || Words_port == 'W') {
				if (map[peo.x - 1][peo.y] != "  ") { Massages[num_m++] = "别撞墙!"; system("cls"); }
				else { up(); Massages[num_m++] = "已向上走!"; }
				print_level_1();
			}
			else if (Words_port == 's' || Words_port == 'S') {
				if (map[peo.x + 1][peo.y] != "  ") { Massages[num_m++] = "别撞墙!"; system("cls"); }
				else { down(); Massages[num_m++] = "已向下走!"; }
				print_level_1();
			}
			else if (Words_port == 'a' || Words_port == 'A') {
				if (map[peo.x][peo.y - 1] != "  ") { Massages[num_m++] = "别撞墙!"; system("cls"); }
				else { left(); Massages[num_m++] = "已向左走!"; }
				print_level_1();
			}
			else if (Words_port == 'd' || Words_port == 'D') {
				if (map[peo.x][peo.y + 1] != "  ") { Massages[num_m++] = "别撞墙!"; system("cls"); }
				else { right(); Massages[num_m++] = "已向右走!"; }
				print_level_1();
			}
		}
	}
	else if (level == 2) {
		level_2();
		print_level_2();
		while (true) {
			Words_port = _getch();
			if (num_m >= 13) {
				for (int i = 1; i <= 13; i++) Massages[i] = " ";
				num_m = 1;
				system("cls");
				print_level_2();
			}
			if (Words_port == '0') {
				system("cls");
				return;
			}
			else if ((Words_port == 'd' || Words_port == 'D') && map[peo.x][peo.y + 1] == "门") {
				printf("恭喜通关！\n");
				for (int i = 1; i <= 1005; i++) Massages[i] = " ";
				num_m = 1;
				ofstream ofs;
				ofs.open("Level.dat", ios::out);
				ofs << 3;
				ofs.close();
				system("pause");
				system("cls");
				return;
			}
			else if (Words_port == 'w' || Words_port == 'W') {
				if (map[peo.x - 1][peo.y] != "  " && map[peo.x - 1][peo.y] != "破") { Massages[num_m++] = "别撞墙!"; system("cls"); }
				else if (map[peo.x - 1][peo.y] == "破") { Put_to(1); Massages[num_m++] = "已把'破'向上推!"; }
				else { up(); Massages[num_m++] = "已向上走!"; }
				print_level_2();
			}
			else if (Words_port == 's' || Words_port == 'S') {
				if (map[peo.x + 1][peo.y] != "  " && map[peo.x + 1][peo.y] != "破") { Massages[num_m++] = "别撞墙!"; system("cls"); }
				else if (map[peo.x + 1][peo.y] == "破") { Put_to(2); Massages[num_m++] = "已把'破'向下推!"; }
				else { down(); Massages[num_m++] = "已向下走!"; }
				print_level_2();
			}
			else if (Words_port == 'a' || Words_port == 'A') {
				if (map[peo.x][peo.y - 1] != "  " && map[peo.x][peo.y - 1] != "破") { Massages[num_m++] = "别撞墙!"; system("cls"); }
				else if (map[peo.x][peo.y - 1] == "破") { Put_to(3); Massages[num_m++] = "已把'破'向左推!"; }
				else { left(); Massages[num_m++] = "已向左走!"; }
				print_level_2();
			}
			else if (Words_port == 'd' || Words_port == 'D') {
				if (map[peo.x][peo.y + 1] != "  " && map[peo.x][peo.y + 1] != "破") { Massages[num_m++] = "别撞墙!"; system("cls"); }
				else if (map[peo.x][peo.y + 1] == "破") { Put_to(4); Massages[num_m++] = "已把'破'向右推!"; }
				else { right(); Massages[num_m++] = "已向右走!"; }
				print_level_2();
			}
		}
	}
	else if (level == 3) {
		level_3();
		print_level_3();
		while (true) {
			flag_win = true;
			while (true) {
				if (_kbhit()) {
					Words_port = _getch();
					break;
				}
				Ghosts();
				system("cls");
				print_level_3();
			}
			//port = getch();
			if (num_m >= 5) {
				for (int i = 1; i <= 5; i++) Massages[i] = " ";
				num_m = 1;
				system("cls");
				print_level_3();
			}
			if (Words_port == '0') {
				system("cls");
				return;
			}
			else if ((Words_port == 's' || Words_port == 'S') && map[peo.x + 1][peo.y] == "门") {
				printf("恭喜通关！\n");
				for (int i = 1; i <= 1005; i++) Massages[i] = " ";
				num_m = 1;
				ofstream ofs;
				ofs.open("Level.dat", ios::out);
				ofs << 4;
				ofs.close();
				system("pause");
				system("cls");
				return;
			}
			else if (Words_port == 'w' || Words_port == 'W') {
				if (map[peo.x - 1][peo.y] == "墙") { Massages[num_m++] = "别撞墙!"; system("cls"); }
				else if (map[peo.x - 1][peo.y] == "鬼" || !flag_win) {
					Massages[num_m++] = "你被鬼杀死了！";
					map[peo.x][peo.y] = "  ";
					system("cls");
					print_level_3();
					Sleep(1000);
					system("pause");
					system("cls");
					return;
				}
				else { up(); Massages[num_m++] = "已向上走!"; }
				print_level_3();
			}
			else if (Words_port == 's' || Words_port == 'S') {
				if (map[peo.x + 1][peo.y] == "墙") { Massages[num_m++] = "别撞墙!"; system("cls"); }
				else if (map[peo.x + 1][peo.y] == "鬼" || !flag_win) {
					Massages[num_m++] = "你被鬼杀死了！";
					map[peo.x][peo.y] = "  ";
					system("cls");
					print_level_3();
					Sleep(1000);
					system("pause");
					system("cls");
					return;
				}
				else { down(); Massages[num_m++] = "已向下走!"; }
				print_level_3();
			}
			else if (Words_port == 'a' || Words_port == 'A') {
				if (map[peo.x][peo.y - 1] == "墙") { Massages[num_m++] = "别撞墙!"; system("cls"); }
				else if (map[peo.x][peo.y - 1] == "鬼" || !flag_win) {
					Massages[num_m++] = "你被鬼杀死了！";
					map[peo.x][peo.y] = "  ";
					system("cls");
					print_level_3();
					Sleep(1000);
					system("pause");
					system("cls");
					return;
				}
				else { left(); Massages[num_m++] = "已向左走!"; }
				print_level_3();
			}
			else if (Words_port == 'd' || Words_port == 'D') {
				if (map[peo.x][peo.y + 1] == "墙") { Massages[num_m++] = "别撞墙!"; system("cls"); }
				else if (map[peo.x][peo.y + 1] == "鬼" || !flag_win) {
					Massages[num_m++] = "你被鬼杀死了！";
					map[peo.x][peo.y] = "  ";
					system("cls");
					print_level_3();
					Sleep(1000);
					system("pause");
					system("cls");
					return;
				}
				else { right(); Massages[num_m++] = "已向右走!"; }
				print_level_3();
			}
		}
	}
	else return;
	return;
}

/*======================================文字游戏======================================*/
/*====================================================================================*/


/*=====================================================================================*/
/*======================================2048 游戏======================================*/

int mp[10][10], winpd = 2048, povpd = 4, scorec = 0, twin = 0, sjpd = 1, sjpd_2 = 0;
unsigned long long scoreh = 1, sscore = 0, score = 0;
int last1 = 4, last2 = 1, last2_2 = 0, last3 = 2048, last4 = 1, last4_2 = 0;

// 染色 字体颜色/背景颜色 
void color(int x, int y) {
	if (y == 1)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);
}

// 加载动画 
void load() {
	cout << "L"; Sleep(150);
	cout << "o"; Sleep(150);
	cout << "a"; Sleep(150);
	cout << "d"; Sleep(150);
	cout << "i"; Sleep(150);
	cout << "n"; Sleep(150);
	cout << "g"; Sleep(150);
	cout << "."; Sleep(150);
	cout << "."; Sleep(150);
	cout << "."; Sleep(150);
	return;
}

// 胜利动画
void win() {
	system("color 04"); cout << "Y"; Sleep(100);
	system("color 06"); cout << "O"; Sleep(100);
	system("color 0e"); cout << "U"; Sleep(100);
	system("color 02"); cout << " "; Sleep(100);
	system("color 09"); cout << "W"; Sleep(100);
	system("color 01"); cout << "I"; Sleep(100);
	system("color 05"); cout << "N"; Sleep(100);
	system("color 04"); cout << "!"; Sleep(100);
	system("color 06"); cout << "!"; Sleep(100);
	system("color 0e"); cout << "!"; Sleep(100);
	system("color 04"); cout << "T"; Sleep(100);
	system("color 06"); cout << "H"; Sleep(100);
	system("color 0e"); cout << "A"; Sleep(100);
	system("color 02"); cout << "N"; Sleep(100);
	system("color 09"); cout << "K"; Sleep(100);
	system("color 01"); cout << " "; Sleep(100);
	system("color 05"); cout << "Y"; Sleep(100);
	system("color 04"); cout << "O"; Sleep(100);
	system("color 06"); cout << "U"; Sleep(100);
	system("color 0e"); cout << " "; Sleep(100);
	system("color 09"); cout << "F"; Sleep(100);
	system("color 01"); cout << "O"; Sleep(100);
	system("color 05"); cout << "R"; Sleep(100);
	system("color 04"); cout << " "; Sleep(100);
	system("color 06"); cout << "P"; Sleep(100);
	system("color 0e"); cout << "L"; Sleep(100);
	system("color 04"); cout << "A"; Sleep(100);
	system("color 06"); cout << "Y"; Sleep(100);
	system("color 0e"); cout << "I"; Sleep(100);
	system("color 02"); cout << "N"; Sleep(100);
	system("color 09"); cout << "G"; Sleep(100);
	system("color f "); cout << "!"; Sleep(100);
	return;
}

// 游戏主界面 
void start() {
	system("cls");
	cout << "                  ______________________ " << endl;
	cout << "                 |  ver2.0 made by HYF  |" << endl;
	cout << "                 |  总分:" << sscore << "              |" << endl;
	cout << "                 |                      |" << endl;
	cout << "                 |      2048小游戏      |" << endl;
	cout << "                 |                      |" << endl;
	cout << "                 |      1.开始游戏      |" << endl;
	cout << "                 |                      |" << endl;
	cout << "                 |      2.游戏规则      |" << endl;
	cout << "                 |                      |" << endl;
	cout << "                 |      3.游戏设置      |" << endl;
	cout << "                 |                      |" << endl;
	cout << "                 |      0.退出游戏      |" << endl;
	cout << "                 |______________________|" << endl;
	cout << "                 请输入数字进行操作...   " << endl;
	cout << "                 ";
	//17 空格 
	return;
}

// 游戏规则与玩法
void rule() {
	system("cls");
	cout << "              ________________________________" << endl;
	cout << "             |                                |" << endl;
	cout << "             |         游戏规则与玩法         |" << endl;
	cout << "             |                                |" << endl;
	cout << "             |  游戏由一个a*a的窗口组成,16个  |" << endl;
	cout << "             |  数字由2^n(整数)组成(11>n>0).  |" << endl;
	cout << "             |  通过按动wasd(WASD)键控制,数   |" << endl;
	cout << "             |  字会按照固定方向移动,如行或   |" << endl;
	cout << "             |  列有相邻且相等数字,则合并。   |" << endl;
	cout << "             |________________________________|" << endl;
	cout << "             输入1返回..." << endl;
	cout << "             ";
	//13 空格 
	return;
}

// 设置界面 
void set() {
	system("cls");
	cout << "                  ______________________ " << endl;
	cout << "                 |                      |" << endl;
	cout << "                 |       游戏设置       |" << endl;
	cout << "                 |                      |" << endl;
	cout << "                 |      1.游戏界面      |" << endl;
	cout << "                 |                      |" << endl;
	cout << "                 |      2.分数加减      |" << endl;
	cout << "                 |                      |" << endl;
	cout << "                 |      3.胜利判定      |" << endl;
	cout << "                 |                      |" << endl;
	cout << "                 |      4.随机判定      |" << endl;
	cout << "                 |                      |" << endl;
	cout << "                 |      5.一键默认      |" << endl;
	cout << "                 |                      |" << endl;
	cout << "                 |      6.返回上级      |" << endl;
	cout << "                 |______________________|" << endl;
	cout << "              1中默认大小为4,2中加分默认相加." << endl;
	cout << "              3中默认为2048.部分操作需要enter" << endl;
	cout << "              请输入数字操作,请用英文输入法" << endl;
	cout << "              ";
	return;
}

void dy(int n) {
	if (n == 0)cout << "#";
	if (n == 2) { color(8, 1); cout << n; color(-1, 1); }
	if (n == 4) { color(2, 1); cout << n; color(-1, 1); }
	if (n == 8) { color(3, 1); cout << n; color(-1, 1); }
	if (n == 16) { color(4, 1); cout << n; color(-1, 1); }
	if (n == 32) { color(5, 1); cout << n; color(-1, 1); }
	if (n == 64) { color(6, 1); cout << n; color(-1, 1); }
	if (n == 128) { color(13, 1); cout << n; color(-1, 1); }
	if (n == 256) { color(1, 1); cout << n; color(-1, 1); }
	if (n == 512) { color(9, 1); cout << n; color(-1, 1); }
	if (n == 1024) { color(10, 1); cout << n; color(-1, 1); }
	if (n == 2048) { color(11, 1); cout << n; color(-1, 1); }
	if (n == 4096) { color(12, 1); cout << n; color(-1, 1); }
	if (n > 4096) { color(14, 1); cout << n; color(-1, 1); }
	return;
}

// 游戏主界面 
void gmot() {
	system("cls");
	cout << "       ";
	for (int i = 1; i <= (9 - povpd) * 2; i++) cout << " ";
	cout << " scores:" << score << endl;
	cout << "       ";
	for (int i = 1; i <= (9 - povpd) * 2; i++) cout << " ";
	cout << " ____";
	for (int i = 1; i <= povpd; i++) cout << "_";
	for (int i = 1; i <= povpd - 1; i++) cout << "___";
	cout << endl;
	for (int i = 1; i <= povpd; i++) {
		cout << "       ";
		for (int k = 1; k <= (9 - povpd) * 2; k++) cout << " ";
		cout << "|";
		cout << "    ";
		for (int k = 1; k <= povpd; k++) cout << " ";
		for (int k = 1; k <= povpd - 1; k++) cout << "   ";
		cout << "|" << endl;
		cout << "       ";
		for (int k = 1; k <= (9 - povpd) * 2; k++) cout << " ";
		cout << "|  ";
		for (int j = 1; j <= povpd - 1; j++) { dy(mp[i][j]); cout << "   "; }
		dy(mp[i][povpd]);
		cout << "  |" << endl;
	}
	cout << "       ";
	for (int k = 1; k <= (9 - povpd) * 2; k++) cout << " ";
	cout << "|";
	cout << "____";
	for (int i = 1; i <= povpd; i++) cout << "_";
	for (int i = 1; i <= povpd - 1; i++) cout << "___";
	cout << "|" << endl;
	cout << "请输入w(上),a(左),s(下),d(右),/(返回)操作..." << endl;
	return;
}

// 方向判断
bool check_move(int x) {
	int ckpd1 = 0, ckpd2 = 0;
	if (x == 1) // 上
		for (int j = 1; j <= povpd; j++)
			for (int i = 1; i <= povpd; i++) {
				if (mp[i][j] == 0) {
					for (int k = i - 1; k >= 1; k--) if (mp[k][j] != 0) ckpd1 = mp[k][j];
					for (int m = i + 1; m <= povpd; m++) if (mp[m][j] != 0) ckpd2 = mp[m][j];
					if (ckpd1 != 0 && ckpd2 != 0 || ckpd1 == 0) { return true; break; }
				}
				if (mp[i][j] == mp[i + 1][j] && mp[i][j] != 0) { return true; break; }
			}
	else if (x == 2) // 左
		for (int i = 1; i <= povpd; i++)
			for (int j = 1; j <= povpd; j++) {
				if (mp[i][j] == 0) {
					for (int k = j - 1; k >= 1; k--) if (mp[i][k] != 0) ckpd1 = mp[i][k];
					for (int m = j + 1; m <= povpd; m++) if (mp[i][m] != 0) ckpd2 = mp[i][m];
					if (ckpd1 != 0 && ckpd2 != 0 || ckpd1 == 0) { return true; break; }
				}
				if (mp[i][j] == mp[i][j + 1] && mp[i][j] != 0) { return true; break; }
			}
	else if (x == 3) // 下
		for (int j = 1; j <= povpd; j++)
			for (int i = povpd; i >= 1; i--) {
				if (mp[i][j] == 0) {
					for (int k = i - 1; k >= 1; k--) if (mp[k][j] != 0)ckpd1 = mp[k][j];
					for (int m = i + 1; m <= povpd; m++) if (mp[m][j] != 0)ckpd2 = mp[m][j];
					if (ckpd1 != 0 && ckpd2 != 0 || ckpd2 == 0) { return true; break; }
				}
				if (mp[i][j] == mp[i - 1][j] && mp[i][j] != 0) { return true; break; }
			}
	else if (x == 4) // 右
		for (int j = povpd; j >= 1; j--)
			for (int i = 1; i <= povpd; i++) {
				if (mp[i][j] == 0) {
					for (int k = j - 1; k >= 1; k--) if (mp[i][k] != 0)ckpd1 = mp[i][k];
					for (int m = j + 1; m <= povpd; m++) if (mp[i][m] != 0)ckpd2 = mp[i][m];
					if (ckpd1 != 0 && ckpd2 != 0 || ckpd2 == 0) { return true; break; }
				}
				if (mp[i][j] == mp[i][j - 1] && mp[i][j] != 0) { return true; break; }
			}
	return false;
}

/*======================================2048 游戏======================================*/
/*=====================================================================================*/


/*======================================================================================*/
/*======================================名字大作战======================================*/

string name[4];
int hp[4] = { 0 }, fy[4] = { 0 }, sh[4] = { 0 }, meig[4] = { 1, 10, 10, 10 }, huog[4] = { 1, 10, 10, 10 };
int weny[4] = { 5, 10, 10, 10 };
bool si[4] = { false }, bei[4] = { false };

void color(const int textColor) {
	if (textColor >= 0 && textColor <= 15) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), textColor);
	else SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

void meiq(int rrs, int rrm) {
	cout << name[rrs] << " 对 " << name[rrm] << " 使用了"; color(13);
	cout << " 魅惑 "; color(7);
	Sleep(800);
	if (rand() % 5 == 1) {
		cout << "，但 " << name[rrm];
		color(11);
		cout << " 回避 ";
		color(7);
		cout << "了这个攻击";
		Sleep(800);
		goto anssn;
	}
	cout << "， " << name[rrm] << " 被";
	color(13);
	cout << " 魅惑 ";
	color(7);
	cout << "了";
	bei[rrm] = true;
anssn:
	Sleep(200);
	cout << endl;
}

void huoq(int x, int y) {
	int s1 = rand() % 30, xyz = 0, cp = rand() % 114;
	cout << name[x] << " 对 " << name[y] << " 使用了"; color(12);
	cout << " 火球攻 "; color(7);
	Sleep(800);
	if (rand() % 5 == 1) {
		cout << "，但 " << name[y];
		color(11);
		cout << " 回避 ";
		color(7);
		cout << "了这个攻击";
		Sleep(800);
		goto AAS2;
	}
	else if (rand() % 4 == 2) {
		xyz = 1;
		cout << "， " << name[y] << " 使用了 ";
		color(11);
		cout << "防御 ";
		color(7);
		Sleep(600);
	}
	if (fy[y] >= sh[x] + s1 + cp / (xyz == 0 ? 1 : 2))hp[y]--;
	else hp[y] -= (sh[x] - fy[y] + s1 + cp) / (xyz == 0 ? 2 : 1);
	cout << "， " << name[y] << " 受到了 " << max(1, (sh[x] - fy[y] + s1 + cp) / (xyz == 0 ? 2 : 1)) << " 点伤害， ";
	Sleep(500);
	cout << name[y] << " 还有 " << hp[y] << " 滴血";
AAS2:
	Sleep(200);
	cout << endl;
}

void sha(int x, int y, string fz) {
	color(7);
	if (fz == "反击") {
		cout << "\t" << name[x] << " 反击 (〝▼皿▼) ";
		Sleep(500);
		goto ABNSBDV;
	}
	cout << name[x] << " 对 " << name[y] << " 使用了 攻击 ";
	Sleep(800);
ABNSBDV:
	bool s123 = false;
	int s1 = rand() % 30, xyz = 0;
	if (rand() % 5 == 1) {
		cout << "，但 " << name[y];
		color(11);
		cout << " 回避 ";
		color(7);
		cout << "了这个攻击";
		Sleep(800);
		goto AAS;
	}
	else if (rand() % 5 == 2) {
		xyz = 1;
		cout << "， " << name[y] << " 使用了 ";
		color(11);
		cout << "防御 ";
		color(7);
		Sleep(600);
	}
	if ((fy[y] >= sh[x] + s1) / (xyz == 0 ? 1 : 2)) {
		hp[y]--;
		s123 = true;
	}
	else {
		hp[y] -= (sh[x] - fy[y] + s1) / (xyz == 0 ? 1 : 2);
	}
	cout << "， " << name[y] << " 受到了 " << max(1, (sh[x] - fy[y] + s1) / (xyz == 0 ? 1 : 2)) << " 点伤害， ";
	Sleep(500);
	cout << name[y] << " 还有 " << hp[y] << " 滴血 ";
	if (s123)cout << "(︶︿︶)＝凸";
AAS:
	Sleep(800);

	cout << endl;
}

void wenyi(int rrs, int rrm) {
	int s1 = rand() % 95, sn = hp[rrm];
	cout << name[rrs] << " 对 " << name[rrm] << " 使用了 ";
	color(3);
	cout << "瘟疫 ";
	color(7);
	Sleep(500);
	if (rand() % 5 == 1) {
		cout << "，但 " << name[rrm];
		color(11);
		cout << " 回避 ";
		color(7);
		cout << "了这个攻击";
		Sleep(800);
		goto AAAAAA;
	}
	cout << "， " << name[rrm] << " 生命减少 " << s1 << " %， ";
	Sleep(300);
	hp[rrm] = ceil(hp[rrm] * 0.01 * (100 - s1));
	cout << name[rrm] << " 受到了 " << sn - ceil(sn * 0.01 * (100 - s1)) << " 点伤害， ";
	Sleep(300);
	cout << name[rrm] << " 还有 " << hp[rrm] << " 滴血 ";
AAAAAA:
	Sleep(200);
	cout << endl;
}

bool ttt = false;
void xuanji() {
	srand(time(NULL));
	cout << "名字1：";
	cin >> name[1];
	if (name[1] == "SB")hp[1] += 60, fy[1] += 20, sh[1] += 20;
	cout << "名字2：";
	cin >> name[2];
	if (name[2] == "SB")hp[2] += 60, fy[2] += 20, sh[2] += 20;
	cout << "名字3：";
	cin >> name[3];
	if (name[3] == "SB")hp[3] += 60, fy[3] += 20, sh[3] += 20;
	if (rand() % 8 == 0) meig[1] = rand() % 50;
	if (rand() % 8 == 2) huog[1] = rand() % 50;
	if (rand() % 8 == 7) weny[1] = rand() % 50;
	if (rand() % 8 == 0) meig[2] = rand() % 50;
	if (rand() % 8 == 2) huog[2] = rand() % 50;
	if (rand() % 8 == 7) weny[2] = rand() % 50;
	if (rand() % 8 == 0) meig[3] = rand() % 50;
	if (rand() % 8 == 2) huog[3] = rand() % 50;
	if (rand() % 8 == 7) weny[3] = rand() % 50;
	for (int i = 0; i < 550; i++) {
		if (rand() % 100 < 55)hp[1]++;
		else if (rand() % 100 >= 55 && rand() % 100 <= 57)fy[1]++;
		else if (rand() % 100 > 57 && rand() % 100 <= 100)sh[1]++;
		if (rand() % 100 < 55)hp[2]++;
		else if (rand() % 100 >= 55 && rand() % 100 <= 57)fy[2]++;
		else if (rand() % 100 > 57 && rand() % 100 <= 100)sh[2]++;
		if (rand() % 100 < 55)hp[3]++;
		else if (rand() % 100 >= 55 && rand() % 100 <= 57)fy[3]++;
		else if (rand() % 100 > 57 && rand() % 100 <= 100)sh[3]++;
	}
}

/*======================================名字大作战======================================*/
/*======================================================================================*/

//  文字游戏
void Game::Words_Game() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	ifstream ifs;
	ofstream ofs;
	Windows_System();
	while (true) {
		Face();
		Words_port = _getch();
		if (Words_port == '1') {
			system("cls"); mem();
			ifs.open("Level.dat");
			ifs >> p;
			ifs.close();
			if (p == 1) { run(1); continue; }
			else if (p == 2) { run(2); continue; }
			else if (p == 3) { run(3); continue; }
			else { system("cls"); printf("恭喜您已通关，暂无更多关卡！\n"); system("pause"); system("cls"); continue; }
		}
		else if (Words_port == '2') {
			system("cls"); mem();
			ofs.open("Level.dat");
			ofs << 1;
			ofs.close();
			run(1);
			continue;
		}
		else if (Words_port == '0') { ShowCursor(true); return; }
		else system("cls");
	}
	ShowCursor(true);
	return;
}

//  2048 游戏
void Game::Maths_Game() {
	srand(time(0));
loop:
	while (true) {
		start();
		string st;
		st = _getch();
		if (st == "1") { start(); load(); break; }
		if (st == "2") {
			while (true) {
				rule();
				string rule;
				rule = _getch();
				if (rule == "1")break;
				else {
					cout << "输入有误!" << endl << "             ";
					Sleep(300);
					system("cls");
					continue;
				}
			}
		}
		if (st == "3") {
		looop:
			while (true) {
				set();
				string set;
				set = _getch();
				if (set == "1") {
					while (true) {
						cout << "请输入界面大小 n * n (2 < n < 10),目前是" << povpd << "." << endl << "              ";
						povpd = _getch();
						povpd -= 48;
						if (povpd > 2 && povpd < 13) { cout << "设置成功!"; last1 = povpd; Sleep(400); goto looop; }
						else { povpd = last1; cout << "设置失败!"; Sleep(400); goto looop; }
					}
				}
				if (set == "2") {
					while (true) {
						cout << "每加分是默认的 n (n > 0)倍.目前是" << scoreh << "倍." << endl << "              ";
						cin >> scoreh;
						if (scoreh > 0) {
							cout << "              设置成功!";
							last2 = scoreh;
							Sleep(400);
							cout << endl << "              启用减分? 1(是) 0(否).目前";
							if (scorec == 1)cout << "已启用." << endl << "              ";
							else cout << "未启用." << endl << "              ";
							scorec = _getch();
							scorec -= 48;
							if (scorec == 1 || scorec == 0) { cout << "设置成功!"; last2_2 = scorec; Sleep(400); goto looop; }
							else { scorec = last2_2; cout << "设置失败!"; Sleep(400); goto looop; }
						}
						else { scoreh = last2; cout << "设置失败!"; Sleep(400); goto looop; }
					}
				}
				if (set == "3") {
					while (true) {
						cout << "当出现 n (n > 32)时游戏胜利.目前是" << winpd << "." << endl << "              ";
						cin >> winpd;
						if (winpd == 64 || winpd == 128 || winpd == 256 || winpd == 512 || winpd == 1024 || winpd == 2048 || winpd == 4096) {
							cout << "              设置成功!";
							last3 = winpd;
							Sleep(400);
							goto looop;
						}
						else { winpd = last3; cout << "              设置失败!"; Sleep(400); goto looop; }
					}
				}
				if (set == "5") {
					while (true) {
						cout << "确定? 1(是) 其他(否)" << endl << "              ";
						string resetmr;
						resetmr = _getch();
						if (resetmr == "1") {
							cout << "设置成功!";
							winpd = 2048; povpd = 4; scoreh = 1; scorec = 0, sjpd = 1, sjpd_2 = 0;
							last1 = 4; last2 = 1; last2_2 = 0; last3 = 2048; last4 = 1; last4_2 = 0;
							Sleep(400);
							goto looop;
						}
						else { cout << "已取消!"; Sleep(400); goto looop; }
					}
				}
				if (set == "4") {
					while (true) {
						cout << "游戏随机生成 n (0 < n < 4)个数.目前生成:" << sjpd << "." << endl << "              ";
						sjpd = _getch();
						sjpd -= 48;
						if (sjpd == 1 || sjpd == 2 || sjpd == 3 || sjpd == 4) {
							cout << "设置成功!" << endl;
							last4 = sjpd;
							Sleep(400);
							cout << "              是否生成数随机(2 ~ 8)？1(是) 其他(否),目前:";
							if (sjpd_2 == 1)cout << "是." << endl;
							else cout << "否." << endl;
							sjpd_2 = _getch();
							sjpd_2 -= 48;
							if (sjpd_2 == 1) { cout << "              设置成功!" << endl; last4_2 = sjpd_2; Sleep(400); goto looop; }
							else { cout << "              已取消!"; sjpd_2 = last4_2; Sleep(400); goto looop; }
						}
						else { cout << "设置失败!"; sjpd = last4; Sleep(400); goto looop; }
					}
				}
				if (set == "6") { goto loop; }
				if (set != "5" && set != "1" && set != "2" && set != "3" && set != "4" && set != "6") { cout << "输入错误!"; Sleep(400); goto looop; }
			}
		}
		if (st == "0") { return; }
		if (st != "0" && st != "1" && st != "2" && st != "3") { cout << "输入有误!" << endl << "                 "; Sleep(300); system("cls"); continue; }
	}
lop:
	mp[1][1] = 2; score = 0;
	while (true) {
		int pdg = 0;
		for (int i = 1; i <= povpd; i++) {
			for (int j = 1; j <= povpd; j++) {
				if (mp[i][j] == int(pow(2, povpd * povpd - 5)) || mp[i][j] == winpd) { // WIN 
					gmot(); win(); sscore += score; system("color 0f");
					cout << "YOU GOT " << score << " scores." << endl;
					cout << "AGAIN? 1(是) 2(返回) 0(退出)" << endl;
					while (true) {
						string again;
						cin >> again;
						if (again == "1") {
							for (int i = 1; i <= povpd; i++) for (int j = 1; j <= povpd; j++) mp[i][j] = 0;
							goto lop;
						}
						else if (again == "2") {
							for (int i = 1; i <= povpd; i++) for (int j = 1; j <= povpd; j++) mp[i][j] = 0;
							goto loop;
						}
						else if (again == "0") { return; }
						else {
							cout << "输入有误!" << endl;
							Sleep(300);
							system("cls");
							gmot();
							cout << "YOU WIN!THANK YOU FOR PLAYING!" << "YOU GOT " << score << " scores." << endl;
							cout << "AGAIN? 1(是) 2(返回) 0(退出)" << endl;
							continue;
						}
					}
				}
				if (mp[i][j] != mp[i][j + 1] && mp[i][j] != mp[i][j - 1] &&
					mp[i][j] != mp[i + 1][j] && mp[i][j] != mp[i - 1][j] && mp[i][j] != 0) pdg++;
			}
		}
		if (pdg == povpd * povpd) {
			cout << "GAME OVER!THANK FOR PLAYING!" << endl;
			cout << "YOU GOT " << score << " scores.AGAIN? 1(是) 2(返回) 0(退出)" << endl;
			while (true) {
				string again;
				cin >> again;
				if (again == "1") {
					for (int i = 1; i <= povpd; i++) for (int j = 1; j <= povpd; j++) mp[i][j] = 0;
					goto lop;
				}
				else if (again == "2") {
					for (int i = 1; i <= povpd; i++) for (int j = 1; j <= povpd; j++) mp[i][j] = 0;
					goto loop;
				}
				else if (again == "0") { return; }
				else {
					cout << "输入有误!" << endl;
					Sleep(300);
					system("cls");
					gmot();
					cout << "GAME OVER!THANK FOR PLAYING!" << endl;
					cout << "YOU GOT " << score << " scores.AGAIN? 1(是) 2(返回) 0(退出)" << endl;
					continue;
				}
			}
		}
		// 随机生成数字
		while (true) {
			if (sjpd == 0) { sjpd = last4; break; }
			int cnt = 0;
			for (int i = 1; i <= povpd; i++) for (int j = 1; j <= povpd; j++) if (mp[i][j] != 0) cnt++;
			if (cnt == povpd * povpd)break;
			int x = 0, y = 0;
			x = rand() % povpd + 1;// a~b = (b - a + 1) + a
			y = rand() % povpd + 1;
			int z = rand() % 3 + 1;
			if (mp[x][y] != 0)continue;
			else { mp[x][y] = 2; if (sjpd_2 == 1) mp[x][y] = pow(2, z); sjpd--; }
		}
		while (true) {
			gmot();
			string move;
			move = _getch();
			if (move == "w" || move == "W") {
				if (!check_move(1)) {
					cout << "换个方向试试." << endl;
					if (scorec)score = score / 8 * 7;
					Sleep(400);
					system("cls");
					continue;
				}
				for (int j = 1; j <= povpd; j++)
					for (int i = 1; i <= povpd - 1; i++)
						if (mp[i][j] == 0)
							for (int k = i + 1; k <= povpd; k++)
								if (mp[k][j] != 0) { mp[i][j] = mp[k][j]; mp[k][j] = 0; break; }
				for (int j = 1; j <= povpd; j++)
					for (int i = 1; i <= povpd - 1; i++)
						if (mp[i][j] == mp[i + 1][j] && mp[i][j] != 0) { mp[i][j] *= 2; score += mp[i + 1][j] * scoreh; mp[i + 1][j] = 0; }
				for (int j = 1; j <= povpd; j++)
					for (int i = 1; i <= povpd - 1; i++)
						if (mp[i][j] == 0)
							for (int k = i + 1; k <= povpd; k++)
								if (mp[k][j] != 0) { mp[i][j] = mp[k][j]; mp[k][j] = 0; break; }
				break;
			}
			else if (move == "a" || move == "A") {
				if (!check_move(2)) {
					cout << "换个方向试试." << endl;
					if (scorec)score = score / 8 * 7;
					Sleep(400);
					system("cls");
					continue;
				}
				for (int i = 1; i <= povpd; i++)
					for (int j = 1; j <= povpd - 1; j++)
						if (mp[i][j] == 0)
							for (int k = j + 1; k <= povpd; k++)
								if (mp[i][k] != 0) { mp[i][j] = mp[i][k]; mp[i][k] = 0; break; }
				for (int i = 1; i <= povpd; i++)
					for (int j = 1; j <= povpd - 1; j++)
						if (mp[i][j] == mp[i][j + 1] && mp[i][j] != 0) { mp[i][j] *= 2; score += mp[i][j + 1] * scoreh; mp[i][j + 1] = 0; }
				for (int i = 1; i <= povpd; i++)
					for (int j = 1; j <= povpd - 1; j++)
						if (mp[i][j] == 0)
							for (int k = j + 1; k <= povpd; k++)
								if (mp[i][k] != 0) { mp[i][j] = mp[i][k]; mp[i][k] = 0; break; }
				break;
			}
			else if (move == "s" || move == "S") {
				if (!check_move(3)) {
					cout << "换个方向试试." << endl;
					if (scorec)score = score / 8 * 7;
					Sleep(400);
					system("cls");
					continue;
				}
				for (int j = 1; j <= povpd; j++)
					for (int i = povpd; i >= 2; i--)
						if (mp[i][j] == 0)
							for (int k = i - 1; k >= 1; k--)
								if (mp[k][j] != 0) { mp[i][j] = mp[k][j]; mp[k][j] = 0; break; }
				for (int j = 1; j <= povpd; j++)
					for (int i = povpd; i >= 2; i--)
						if (mp[i][j] == mp[i - 1][j] && mp[i][j] != 0) { mp[i][j] *= 2; score += mp[i - 1][j] * scoreh; mp[i - 1][j] = 0; }
				for (int j = 1; j <= povpd; j++)
					for (int i = povpd; i >= 2; i--)
						if (mp[i][j] == 0)
							for (int k = i - 1; k >= 1; k--)
								if (mp[k][j] != 0) { mp[i][j] = mp[k][j]; mp[k][j] = 0; break; }
				break;
			}
			else if (move == "d" || move == "D") {
				if (!check_move(4)) {
					cout << "换个方向试试." << endl;
					if (scorec)score = score / 8 * 7;
					Sleep(400);
					system("cls");
					continue;
				}
				for (int i = 1; i <= povpd; i++)
					for (int j = povpd; j >= 2; j--)
						if (mp[i][j] == 0)
							for (int k = j - 1; k >= 1; k--)
								if (mp[i][k] != 0) { mp[i][j] = mp[i][k]; mp[i][k] = 0; break; }
				for (int i = 1; i <= povpd; i++)
					for (int j = povpd; j >= 2; j--)
						if (mp[i][j] == mp[i][j - 1] && mp[i][j] != 0) { mp[i][j] *= 2; score += mp[i][j] * scoreh; mp[i][j - 1] = 0; }
				for (int i = 1; i <= povpd; i++)
					for (int j = povpd; j >= 2; j--)
						if (mp[i][j] == 0)
							for (int k = j - 1; k >= 1; k--)
								if (mp[i][k] != 0) { mp[i][j] = mp[i][k]; mp[i][k] = 0; break; }
				break;
			}
			else if (move == "/") {
				for (int i = 1; i <= povpd; i++) for (int j = 1; j <= povpd; j++) mp[i][j] = 0;
				goto loop;
			}
			else {
				cout << "输入有误!" << endl;
				Sleep(300);
				system("cls");
				gmot();
			}
		}
	}
	return;
}

//  数字炸弹
void Game::Digital_Bombs() {
	while (true) {
		cout << "================欢迎来到数字炸弹小游戏================\n";
		cout << "|                    1.人机对战                      |\n";
		cout << "|                    2.联机对战                      |\n";
		cout << "|                    0.  退出                        |\n";
		cout << "======================================================\n";
		cout << "请选择操作:";
		string select = "0";
		cin >> select;
		if (select == "1") {
			srand((unsigned)time(NULL));
			int bomb = rand() % 101, sum1, sum2, sum3, sum4, l = 0, r = 100, top = 4, time;
			bool flag2 = true, flag3 = true, flag4 = true;
			// 开挂(慎用)
			// cout << "炸弹是（悄悄）:" << bomb << endl;
			cout << "您是第 " << 1 << " 位" << endl;
			while (true) {
				if (top == 1) { cout << "恭喜您 第 1 名!!" << endl; break; }
				cout << "1号: "; cin >> sum1;
				if (sum1 <= l || sum1 >= r) { cout << "输入不合法！" << endl; system("pause"); continue; }
				if (sum1 < bomb)l = sum1;
				else if (sum1 > bomb)r = sum1;
				else { cout << "很遗憾您出局了 您是第 " << top << " 名" << endl; break; }
				cout << "炸弹在 " << l << "-" << r << " 之间" << endl;
				if (flag2) {
					time = rand() % 3000 + 500;
					Sleep(time);
					sum2 = rand() % (r - l) + l + 1;
					if (r - l == 2) {
						cout << "2号出局 第 " << top-- << " 名" << endl << endl;
						if (flag3) cout << "3号出局 第 " << top-- << " 名" << endl << endl;
						if (flag4) cout << "4号出局 第 " << top-- << " 名" << endl << endl;
						flag2 = flag3 = flag4 = false;
						continue;
					}
					while (sum1 == sum2 || sum2 == l || sum2 == r)sum2 = rand() % (r - l) + l;
					if (sum2 == bomb) flag2 = false, cout << "2号出局 第 " << top-- << " 名" << endl;
					else {
						cout << "2号: " << sum2 << endl;
						if (sum2 < bomb)l = sum2;
						else if (sum2 > bomb)r = sum2;
						cout << "炸弹在 " << l << "-" << r << " 之间" << endl;
					}
				}
				if (flag3) {
					time = rand() % 3000 + 500;
					Sleep(time);
					sum3 = rand() % (r - l) + l + 1;
					if (r - l == 2) {
						cout << "3号出局 第 " << top-- << " 名" << endl << endl;
						if (flag4) cout << "4号出局 第 " << top-- << " 名" << endl << endl;
						flag3 = flag4 = false;
						continue;
					}
					while (sum2 == sum3 || sum3 == l || sum3 == r)sum3 = rand() % (r - l) + l;
					if (sum3 == bomb) flag3 = false, cout << "3号出局 第 " << top-- << " 名" << endl;
					else {
						cout << "3号: " << sum3 << endl;
						if (sum3 < bomb)l = sum3;
						else if (sum3 > bomb)r = sum3;
						cout << "炸弹在 " << l << "-" << r << " 之间" << endl;
					}
				}
				if (flag4) {
					time = rand() % 3000 + 500;
					Sleep(time);
					sum4 = rand() % (r - l) + l + 1;
					if (r - l == 2) {
						flag4 = false;
						cout << "4号出局 第 " << top-- << " 名" << endl << endl;
						continue;
					}
					while (sum3 == sum4 || sum4 == l || sum4 == r)sum4 = rand() % (r - l) + l;
					if (sum4 == bomb) flag4 = false, cout << "4号出局 第 " << top-- << " 名" << endl;
					else {
						cout << "4号: " << sum4 << endl;
						if (sum4 < bomb)l = sum4;
						else if (sum4 > bomb)r = sum4;
						cout << "炸弹在 " << l << "-" << r << " 之间" << endl;
					}
				}
				cout << endl;
			}
			system("pause");
			system("cls");
		}
		else if (select == "2") {
			cout << "正在开发***" << endl;
			system("pause");
			system("cls");
		}
		else if (select == "0") {
			cout << "正在退出***" << endl;
			Sleep(500);
			cout << "退出成功！" << endl;
			return;
		}
		else {
			cout << "输入有误！" << endl;
			system("pause");
			system("cls");
		}
	}
	return;
}

//  名字大作战
void Game::Name_Battle() {
	xuanji();
	cout << name[1] << ": 血量 " << hp[1] << "  防御 " << fy[1] << "  伤害 " << sh[1] << endl;
	cout << name[2] << ": 血量 " << hp[2] << "  防御 " << fy[2] << "  伤害 " << sh[2] << endl;
	cout << name[3] << ": 血量 " << hp[3] << "  防御 " << fy[3] << "  伤害 " << sh[3] << endl;
	int rrs = ((rand() % 10) % 3) + 1, rrm = ((rand() % 10) % 3) + 1;
	for (int i = 1; i < 1000000; i++) {
	ERTYU:
		rrs = ((rand() % 10) % 3) + 1, rrm = ((rand() % 10) % 3) + 1;
		if (rrm == rrs) goto ERTYU;
		if (hp[rrs] <= 0 || hp[rrm] <= 0) goto ERTYU;
		if (bei[rrs] == true)rrm = rrs, bei[rrs] = false;
		if (rand() % 100 <= meig[rrs]) { meiq(rrs, rrm); ttt = true; }
		else if (huog[rrs] > rand() % 100) huoq(rrs, rrm);
		else if (weny[rrs] > rand() % 100) wenyi(rrs, rrm);
		else sha(rrs, rrm, "114514");
		bool istrue = false;
	jinitaimei:
		if (hp[1] <= 0 && si[1] == false) {
			cout << "\t" << name[1]; color(4);
			cout << " 死亡"; color(7);
			cout << "了" << endl;
			si[1] = true;
		}
		if (hp[2] <= 0 && si[2] == false) {
			cout << "\t" << name[2]; color(4);
			cout << " 死亡"; color(7);
			cout << "了" << endl;
			si[2] = true;
		}
		if (hp[3] <= 0 && si[3] == false) {
			cout << "\t" << name[3]; color(4);
			cout << " 死亡"; color(7);
			cout << "了" << endl;
			si[3] = true;
		}
		if (hp[rrm] > 0 && rand() % 2 == 1 && !istrue) {
			sha(rrm, rrs, "反击");
			istrue = true;
			goto jinitaimei;
		}
		if (hp[rrm] > 0 && rrs == rrm && ttt != true) {
			cout << "\t" << name[rrs] << " 解除了 ";
			color(13);
			cout << "魅惑" << endl;
			Sleep(400);
			color(7);
		}
		ttt = false;
		color(14);
		if (hp[1] <= 0 && hp[3] <= 0) { cout << name[2] << " win" << endl; system("color f"); return; }
		else if (hp[2] <= 0 && hp[3] <= 0) { cout << name[1] << " win" << endl; system("color f"); return; }
		else if (hp[2] <= 0 && hp[1] <= 0) { cout << name[3] << " win" << endl; system("color f"); return; }
		color(7);
		Sleep(200);
	}
	system("color f");
	return;
}