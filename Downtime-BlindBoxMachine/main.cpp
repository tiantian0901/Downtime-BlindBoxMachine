//Downtime-BlindBoxMachine  DBBM main
#include<iostream>
#include<windows.h>
#include<cstdlib>
#include<string>
#include<ctime>
#define pgl 75   //普通卡概率
#define xgl 20  //稀有卡概率
#define ygl 5  //隐藏卡概率
using namespace std;
const int N = 100;
bool yzbflag = 0, xzbflag = 0;  //隐藏卡和稀有卡是否概率100%
bool wxflag = 0; //是否开启无限宕机币
int minn = 10, maxx = 100;
int num, money;
long long gameb = 5;
#define kd(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)
void color(int a)
{
	/*亮白*/              if (a == 0) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	/*蓝色*/              if (a == 1) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
	/*绿色*/              if (a == 2) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
	/*紫色*/              if (a == 3) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE);
	/*红色*/              if (a == 4) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
	/*黄色*/              if (a == 5) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
	/*深蓝色*/            if (a == 6) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE);
	/*土黄色or金黄色*/    if (a == 7) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN);
	/*灰色接近白*/        if (a == 8) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}
void yanse(int ForgC, int BackC)//SetColorAndBackground函数（颜色函数） 
{
	WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
	return;
}
void noedit(){
	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
	DWORD mode;
	GetConsoleMode(hStdin, &mode);
	mode &= ~ENABLE_QUICK_EDIT_MODE;
	mode &= ~ENABLE_INSERT_MODE;
	mode &= ~ENABLE_MOUSE_INPUT;
	SetConsoleMode(hStdin, mode);
}
void HideCursor(){
	CONSOLE_CURSOR_INFO cur = { 1,0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cur);
}
void ShowCursor(){
	CONSOLE_CURSOR_INFO cur = { 1,1 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cur);
}
struct gift {
	string name;  //名称
	int id;       //编号
	string rarity;  //稀有度
	double price; //价格
	string dj;       //等级
	string jj;      //简介
	int nums;     //拥有数量
	int colorflag; //是否高亮颜色
}gi[N+5];
void cshgift() { //初始化礼物信息
	//☆★
	gi[1] = { "普通碎片",1,"普通",0.5,"★☆☆☆☆","能合成随机普通物品的碎片",0,0};
	gi[2] = { "星星玩偶" , 2, "普通", 2, "★★☆☆☆", "据说能增加好运？", 0 ,0};
	gi[3] = { "落地烟头" ,3,"普通",0,"☆☆☆☆☆","能看到城市的身影，常徘徊于公交车站牌之中 byQ的月光",0,0};
}
void menuwz(int midd) {
	if (midd == 1) {
		system("cls");
		cout << "欢迎来到宕机牌盲盒机！" << endl;
		cout << endl;
		cout << "      →开始-" << endl;
		cout << "      -充值-" << endl;
		cout << "     -查看余额-" << endl;
		cout << "   -查看已得奖品-" << endl;
		cout << "     -合成器-" << endl;
		cout << "    -输入作弊码-" << endl;
		cout << "      -关于-" << endl;
		Sleep(50);
		return;
	}
	else if (midd == 2) {
		system("cls");
		cout << "欢迎来到宕机牌盲盒机！" << endl;
		cout << endl;
		cout << "      -开始-" << endl;
		cout << "      →充值-" << endl;
		cout << "     -查看余额-" << endl;
		cout << "   -查看已得奖品-" << endl;
		cout << "     -合成器-" << endl;
		cout << "    -输入作弊码-" << endl;
		cout << "      -关于-" << endl;
		Sleep(50);
		return;
	}
	else if (midd == 3) {
		system("cls");
        cout << "欢迎来到宕机牌盲盒机！" << endl;
		cout << endl;
		cout << "      -开始-" << endl;
		cout << "      -充值-" << endl;
		cout << "     →查看余额-" << endl;
        cout << "   -查看已得奖品-" << endl;
        cout << "    -合成器-" << endl;
        cout << "   -输入作弊码-" << endl;
		cout << "      -关于-" << endl;
		Sleep(50);
        return;
	}else if (midd == 4) {
		system("cls");
		cout << "欢迎来到宕机牌盲盒机！" << endl;
		cout << endl;
		cout << "      -开始-" << endl;
		cout << "      -充值-" << endl;
		cout << "     -查看余额-" << endl;
		cout << "   →查看已得奖品-" << endl;
		cout << "     -合成器-" << endl;
		cout << "    -输入作弊码-" << endl;
		cout << "      -关于-" << endl;
		Sleep(50);
		return;
	}
	else if (midd == 5) {
		system("cls");
		cout << "欢迎来到宕机牌盲盒机！" << endl;
		cout << endl;
		cout << "      -开始-" << endl;
		cout << "      -充值-" << endl;
		cout << "     -查看余额-" << endl;
		cout << "   -查看已得奖品-" << endl;
		cout << "     →合成器-" << endl;
		cout << "    -输入作弊码-" << endl;
		cout << "      -关于-" << endl;
		Sleep(50);
		return;
	}else if (midd == 6) {
		system("cls");
		cout << "欢迎来到宕机牌盲盒机！" << endl;
		cout << endl;
		cout << "      -开始-" << endl;
		cout << "      -充值-" << endl;
		cout << "     -查看余额-" << endl;
		cout << "   -查看已得奖品-" << endl;
		cout << "     -合成器-" << endl;
		cout << "    →输入作弊码-" << endl;
		cout << "      -关于-" << endl;
		Sleep(50);
		return;
	}
	else if (midd == 7) {
        system("cls");
        cout << "欢迎来到宕机牌盲盒机！" << endl;
        cout << endl;
		cout << "      -开始-" << endl;
		cout << "      -充值-" << endl;
        cout << "     -查看余额-" << endl;
		cout << "   -查看已得奖品-" << endl;
		cout << "     -合成器-" << endl;
		cout << "    -输入作弊码-" << endl;
        cout << "      →关于-" << endl;
		Sleep(50);
		return;
	}
}
void ggwz(int idd) {
	if (idd == 1) {
		system("cls");
		cout << "请选择宕机套餐（方向左右键选择）：" << endl;
		cout << "一筐宕机币（30枚）     ";
		cout << "一盒宕机币（50枚）     ";
		cout << "一箱宕机币（100枚）    ";
		cout << "[推荐]无限宕机币/一个月" << endl;
		cout << "→15rmb                   ";
		cout << "25rmb                    ";
		cout << "50rmb                    ";
		cout << "40rmb" << endl;
		Sleep(50);
		return;
	}else if (idd == 2) {
		system("cls");
		cout << "请选择宕机套餐（方向左右键选择）：" << endl;
		cout << "一筐宕机币（30枚）     ";
		cout << "一盒宕机币（50枚）     ";
		cout << "一箱宕机币（100枚）    ";
		cout << "[推荐]无限宕机币/一个月" << endl;
		cout << "15rmb                   ";
		cout << "→25rmb                    ";
		cout << "50rmb                    ";
		cout << "40rmb" << endl;
		Sleep(50);
		return;
	}
	else if (idd == 3) {
		system("cls");
		cout << "请选择宕机套餐（方向左右键选择）：" << endl;
		cout << "一筐宕机币（30枚）     ";
		cout << "一盒宕机币（50枚）     ";
		cout << "一箱宕机币（100枚）    ";
		cout << "[推荐]无限宕机币/一个月" << endl;
		cout << "15rmb                   ";
		cout << "25rmb                    ";
		cout << "→50rmb                    ";
		cout << "40rmb" << endl;
		Sleep(50);
		return;
	}
	else if (idd == 4) {
		system("cls");
		cout << "请选择宕机套餐（方向左右键选择）：" << endl;
		cout << "一筐宕机币（30枚）     ";
		cout << "一盒宕机币（50枚）     ";
		cout << "一箱宕机币（100枚）    ";
		cout << "[推荐]无限宕机币/一个月" << endl;
		cout << "15rmb                   ";
		cout << "25rmb                    ";
		cout << "50rmb                    ";
		cout << "→40rmb" << endl;
		Sleep(50);
		return;
	}
}
int lottery(int yxb,int n) {
	if (yxb > gameb) {
		cout << "宕机币不足！" << endl;
		Sleep(1000);
		return 0;
	}
	else {
		gameb -= yxb;
		cout << "支付成功！余额：" << gameb << endl;
		Sleep(1000);
	}
	system("cls");
	ShowCursor();
	cout << "开始抽奖！次数：" << n << endl;
	HideCursor();
	for (int i = 1; i <= n; i++) {
		srand(time(0));

	}
}
int main() {
	cshgift();
	menu:noedit();
	HideCursor();
	system("title Downtime-BlindBoxMachine");
	//system("mode con cols=50 lines=20");
	system("cls");
	cout << "欢迎来到宕机牌盲盒机！" << endl;
	cout << endl;
	Sleep(1000);
	cout << "      →开始-" << endl;
	Sleep(300);
	cout << "      -充值-" << endl;
	Sleep(300);
	cout << "     -查看余额-" << endl;
	Sleep(300);
	cout << "   -查看已得奖品-" << endl;
	Sleep(300);
    cout << "     -合成器-" << endl;
    Sleep(300);
	cout << "    -输入作弊码-" << endl;
    Sleep(300);
    cout << "      -关于-" << endl;
	int midd = 1;
	while (1) {
		if (kd(VK_DOWN)) {
			midd++;
			if (midd > 7) {
				midd = 7;
			}
			menuwz(midd);
		}
		if (kd(VK_UP)) {
			midd--;
			if (midd < 1) {
				midd = 1;
			}
            menuwz(midd);
		}
		if (kd(VK_RETURN)) {
			if (midd == 1) {
			st:system("cls");
				Sleep(300);
				cout << "请输入数量，1-30（或输入2025直接十连抽）：";
				ShowCursor();
				cin >> num;
				cout << endl;
				HideCursor();
				Sleep(500);
				if (num < 1 || (num > 30 && num != 2025)) {
					cout << "输入错误！" << endl;
					Sleep(2000);
					goto st;
				}
			pd:if (num == 2025) {
				cout << "共需支付" << 10 * 2 - 2 << "枚游戏币，是否立即支付（是/否）？";
			}
			else {
				cout << "共需支付" << num * 2 << "枚游戏币，是否立即支付（是/否）？";
			}
			ShowCursor();
			string s;
			cin >> s;
			HideCursor();
			if (s == "是") {
				int b = lottery(num * 2, num);
				if (b == 0) {
					goto menu;
				}
				else {
				pd1:cout << "抽奖完毕，是否继续抽奖（是/否）？" << endl;
					ShowCursor();
					cin >> s;
					HideCursor();
					if (s == "是") {
						goto st;
					}
					else if (s == "否") {
						cout << "已取消，三秒后回到主界面" << endl;
						Sleep(3000);
						goto menu;
					}
					else {
						cout << "输入有误！请重新输入！";
						Sleep(2000);
						system("cls");
						goto pd1;
					}
				}
			}
			else if (s == "否") {
				cout << "已取消，三秒后回到主界面" << endl;
				Sleep(3000);
				goto menu;
			}
			else {
				cout << "输入有误！请重新输入！";
				Sleep(2000);
				system("cls");
				goto pd;
			}
			}
			if (midd == 2) {
				system("cls");
				cout << "请选择宕机套餐（方向左右键选择，enter确认）：" << endl;
				Sleep(500);
				cout << "一筐宕机币（30枚）     ";
				cout << "一盒宕机币（50枚）     ";
				cout << "一箱宕机币（100枚）    ";
				cout << "[推荐]无限宕机币/一个月" << endl;
				cout << "→15rmb                   ";
				cout << "25rmb                    ";
				cout << "50rmb                    ";
				cout << "60rmb" << endl;
				int flagid = 1;
				while (1) {
					if (kd(VK_LEFT)) {
						flagid--;
						if (flagid < 1) {
							flagid = 1;
						}
						ggwz(flagid);
					}
					if (kd(VK_RIGHT)) {
						flagid++;
						if (flagid > 4) {
							flagid = 4;
						}
						ggwz(flagid);
					}
					if (kd(VK_RETURN)) {
						if (flagid == 1) {
							system("cls");
							Sleep(1000);
							cout << "你已选择一筐宕机币，支付：15元" << endl;
							Sleep(2000);
							gameb += 30;
							cout << "支付成功！余额：" << gameb << endl;
							Sleep(2000);
							goto menu;
						}
						else if (flagid == 2) {
							system("cls");
							Sleep(1000);
							cout << "你已选择一盒宕机币，支付：25元" << endl;
							Sleep(2000);
							gameb += 50;
							cout << "支付成功！余额：" << gameb << endl;
							Sleep(2000);
							goto menu;
						}
						else if (flagid == 3) {
							system("cls");
							Sleep(1000);
							cout << "你已选择一箱宕机币，支付：50元" << endl;
							Sleep(2000);
							gameb += 100;
							cout << "支付成功！余额：" << gameb << endl;
							Sleep(2000);
							goto menu;
						}
						else if (flagid == 4) {
							system("cls");
							Sleep(1000);
							cout << "你已选择无限宕机币/一个月，支付：60元" << endl;
							Sleep(2000);
							gameb = 1145141919180;
							cout << "支付成功！余额：无限" << endl;
							Sleep(2000);
							goto menu;
						}
					}
				}
			}
			if (midd == 3) {
				system("cls");
				Sleep(1000);
				if (gameb == 1145141919180) {
					cout << "当前余额：无限" << endl;
					Sleep(1000);
					if (wxflag == 1) {
						cout << "时长：不限" << endl;
					}
					else {
						cout << "时长：一个月" << endl;
					}
				}
				else {
					cout << "当前余额：" << gameb  << endl;
					Sleep(1000);
					cout << "时长：不限" << endl;
				}
				Sleep(2000);
				system("pause");
				goto menu;
			}
			if (midd == 4) {

			}
			if (midd == 5) {

			}
			if (midd == 6) {
				string nz;
				system("cls");
				Sleep(500);
				cout << "请输入作弊吗：";
				cin >> nz;
				if (nz == "wx114514") {
					gameb = 1145141919180;
					wxflag = 1;
					cout << endl;
					cout << "[更改宕机币]作弊码输入成功！" << endl;
					Sleep(1000);
					goto menu;
				}
				else if (nz == "yck100") {
					#define ygl 100
					yzbflag = 1;
					xzbflag = 0;
					cout << endl;
					cout << "[隐藏卡概率]作弊码输入成功！" << endl;
					Sleep(1000);
					goto menu;
				}
				else if (nz == "xck100") {
					#define xgl 100
					xzbflag = 1;
					yzbflag = 0;
					cout << endl;
					cout << "[稀有卡概率]作弊码输入成功！" << endl;
					Sleep(1000);
					goto menu;
				}
				else {
					cout << endl;
					cout << "作弊码无效！" << endl;
					Sleep(1000);
					goto menu;
				}
			}
			if (midd == 7) {
                system("cls");
				cout << "关于" << endl;
                Sleep(500);
				cout << endl;
				cout << "程序名：Downtime-BlindBoxMachine" << endl;
				Sleep(300);
				cout << "版本：1.0.0" << endl;
				Sleep(300);
                
				cout << "开发者：ANJourney" << endl;
                Sleep(300);
			}
		}
	}
	return 0;
}