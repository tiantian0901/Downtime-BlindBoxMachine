//Downtime-BlindBoxMachine  DBBM main
#include<iostream>
#include<windows.h>
#include<cstdlib>
#include<string>
#include<ctime>
#define pgl 75   //��ͨ������
#define xgl 20  //ϡ�п�����
#define ygl 5  //���ؿ�����
using namespace std;
const int N = 100;
bool yzbflag = 0, xzbflag = 0;  //���ؿ���ϡ�п��Ƿ����100%
bool wxflag = 0; //�Ƿ�������崻���
int minn = 10, maxx = 100;
int num, money;
long long gameb = 5;
#define kd(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)
void color(int a)
{
	/*����*/              if (a == 0) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	/*��ɫ*/              if (a == 1) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
	/*��ɫ*/              if (a == 2) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
	/*��ɫ*/              if (a == 3) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE);
	/*��ɫ*/              if (a == 4) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
	/*��ɫ*/              if (a == 5) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
	/*����ɫ*/            if (a == 6) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE);
	/*����ɫor���ɫ*/    if (a == 7) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN);
	/*��ɫ�ӽ���*/        if (a == 8) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}
void yanse(int ForgC, int BackC)//SetColorAndBackground��������ɫ������ 
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
	string name;  //����
	int id;       //���
	string rarity;  //ϡ�ж�
	double price; //�۸�
	string dj;       //�ȼ�
	string jj;      //���
	int nums;     //ӵ������
	int colorflag; //�Ƿ������ɫ
}gi[N+5];
void cshgift() { //��ʼ��������Ϣ
	//���
	gi[1] = { "��ͨ��Ƭ",1,"��ͨ",0.5,"������","�ܺϳ������ͨ��Ʒ����Ƭ",0,0};
	gi[2] = { "������ż" , 2, "��ͨ", 2, "������", "��˵�����Ӻ��ˣ�", 0 ,0};
	gi[3] = { "�����ͷ" ,3,"��ͨ",0,"������","�ܿ������е���Ӱ�����ǻ��ڹ�����վ��֮�� byQ���¹�",0,0};
}
void menuwz(int midd) {
	if (midd == 1) {
		system("cls");
		cout << "��ӭ����崻���ä�л���" << endl;
		cout << endl;
		cout << "      ����ʼ-" << endl;
		cout << "      -��ֵ-" << endl;
		cout << "     -�鿴���-" << endl;
		cout << "   -�鿴�ѵý�Ʒ-" << endl;
		cout << "     -�ϳ���-" << endl;
		cout << "    -����������-" << endl;
		cout << "      -����-" << endl;
		Sleep(50);
		return;
	}
	else if (midd == 2) {
		system("cls");
		cout << "��ӭ����崻���ä�л���" << endl;
		cout << endl;
		cout << "      -��ʼ-" << endl;
		cout << "      ����ֵ-" << endl;
		cout << "     -�鿴���-" << endl;
		cout << "   -�鿴�ѵý�Ʒ-" << endl;
		cout << "     -�ϳ���-" << endl;
		cout << "    -����������-" << endl;
		cout << "      -����-" << endl;
		Sleep(50);
		return;
	}
	else if (midd == 3) {
		system("cls");
        cout << "��ӭ����崻���ä�л���" << endl;
		cout << endl;
		cout << "      -��ʼ-" << endl;
		cout << "      -��ֵ-" << endl;
		cout << "     ���鿴���-" << endl;
        cout << "   -�鿴�ѵý�Ʒ-" << endl;
        cout << "    -�ϳ���-" << endl;
        cout << "   -����������-" << endl;
		cout << "      -����-" << endl;
		Sleep(50);
        return;
	}else if (midd == 4) {
		system("cls");
		cout << "��ӭ����崻���ä�л���" << endl;
		cout << endl;
		cout << "      -��ʼ-" << endl;
		cout << "      -��ֵ-" << endl;
		cout << "     -�鿴���-" << endl;
		cout << "   ���鿴�ѵý�Ʒ-" << endl;
		cout << "     -�ϳ���-" << endl;
		cout << "    -����������-" << endl;
		cout << "      -����-" << endl;
		Sleep(50);
		return;
	}
	else if (midd == 5) {
		system("cls");
		cout << "��ӭ����崻���ä�л���" << endl;
		cout << endl;
		cout << "      -��ʼ-" << endl;
		cout << "      -��ֵ-" << endl;
		cout << "     -�鿴���-" << endl;
		cout << "   -�鿴�ѵý�Ʒ-" << endl;
		cout << "     ���ϳ���-" << endl;
		cout << "    -����������-" << endl;
		cout << "      -����-" << endl;
		Sleep(50);
		return;
	}else if (midd == 6) {
		system("cls");
		cout << "��ӭ����崻���ä�л���" << endl;
		cout << endl;
		cout << "      -��ʼ-" << endl;
		cout << "      -��ֵ-" << endl;
		cout << "     -�鿴���-" << endl;
		cout << "   -�鿴�ѵý�Ʒ-" << endl;
		cout << "     -�ϳ���-" << endl;
		cout << "    ������������-" << endl;
		cout << "      -����-" << endl;
		Sleep(50);
		return;
	}
	else if (midd == 7) {
        system("cls");
        cout << "��ӭ����崻���ä�л���" << endl;
        cout << endl;
		cout << "      -��ʼ-" << endl;
		cout << "      -��ֵ-" << endl;
        cout << "     -�鿴���-" << endl;
		cout << "   -�鿴�ѵý�Ʒ-" << endl;
		cout << "     -�ϳ���-" << endl;
		cout << "    -����������-" << endl;
        cout << "      ������-" << endl;
		Sleep(50);
		return;
	}
}
void ggwz(int idd) {
	if (idd == 1) {
		system("cls");
		cout << "��ѡ��崻��ײͣ��������Ҽ�ѡ�񣩣�" << endl;
		cout << "һ��崻��ң�30ö��     ";
		cout << "һ��崻��ң�50ö��     ";
		cout << "һ��崻��ң�100ö��    ";
		cout << "[�Ƽ�]����崻���/һ����" << endl;
		cout << "��15rmb                   ";
		cout << "25rmb                    ";
		cout << "50rmb                    ";
		cout << "40rmb" << endl;
		Sleep(50);
		return;
	}else if (idd == 2) {
		system("cls");
		cout << "��ѡ��崻��ײͣ��������Ҽ�ѡ�񣩣�" << endl;
		cout << "һ��崻��ң�30ö��     ";
		cout << "һ��崻��ң�50ö��     ";
		cout << "һ��崻��ң�100ö��    ";
		cout << "[�Ƽ�]����崻���/һ����" << endl;
		cout << "15rmb                   ";
		cout << "��25rmb                    ";
		cout << "50rmb                    ";
		cout << "40rmb" << endl;
		Sleep(50);
		return;
	}
	else if (idd == 3) {
		system("cls");
		cout << "��ѡ��崻��ײͣ��������Ҽ�ѡ�񣩣�" << endl;
		cout << "һ��崻��ң�30ö��     ";
		cout << "һ��崻��ң�50ö��     ";
		cout << "һ��崻��ң�100ö��    ";
		cout << "[�Ƽ�]����崻���/һ����" << endl;
		cout << "15rmb                   ";
		cout << "25rmb                    ";
		cout << "��50rmb                    ";
		cout << "40rmb" << endl;
		Sleep(50);
		return;
	}
	else if (idd == 4) {
		system("cls");
		cout << "��ѡ��崻��ײͣ��������Ҽ�ѡ�񣩣�" << endl;
		cout << "һ��崻��ң�30ö��     ";
		cout << "һ��崻��ң�50ö��     ";
		cout << "һ��崻��ң�100ö��    ";
		cout << "[�Ƽ�]����崻���/һ����" << endl;
		cout << "15rmb                   ";
		cout << "25rmb                    ";
		cout << "50rmb                    ";
		cout << "��40rmb" << endl;
		Sleep(50);
		return;
	}
}
int lottery(int yxb,int n) {
	if (yxb > gameb) {
		cout << "崻��Ҳ��㣡" << endl;
		Sleep(1000);
		return 0;
	}
	else {
		gameb -= yxb;
		cout << "֧���ɹ�����" << gameb << endl;
		Sleep(1000);
	}
	system("cls");
	ShowCursor();
	cout << "��ʼ�齱��������" << n << endl;
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
	cout << "��ӭ����崻���ä�л���" << endl;
	cout << endl;
	Sleep(1000);
	cout << "      ����ʼ-" << endl;
	Sleep(300);
	cout << "      -��ֵ-" << endl;
	Sleep(300);
	cout << "     -�鿴���-" << endl;
	Sleep(300);
	cout << "   -�鿴�ѵý�Ʒ-" << endl;
	Sleep(300);
    cout << "     -�ϳ���-" << endl;
    Sleep(300);
	cout << "    -����������-" << endl;
    Sleep(300);
    cout << "      -����-" << endl;
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
				cout << "������������1-30��������2025ֱ��ʮ���飩��";
				ShowCursor();
				cin >> num;
				cout << endl;
				HideCursor();
				Sleep(500);
				if (num < 1 || (num > 30 && num != 2025)) {
					cout << "�������" << endl;
					Sleep(2000);
					goto st;
				}
			pd:if (num == 2025) {
				cout << "����֧��" << 10 * 2 - 2 << "ö��Ϸ�ң��Ƿ�����֧������/�񣩣�";
			}
			else {
				cout << "����֧��" << num * 2 << "ö��Ϸ�ң��Ƿ�����֧������/�񣩣�";
			}
			ShowCursor();
			string s;
			cin >> s;
			HideCursor();
			if (s == "��") {
				int b = lottery(num * 2, num);
				if (b == 0) {
					goto menu;
				}
				else {
				pd1:cout << "�齱��ϣ��Ƿ�����齱����/�񣩣�" << endl;
					ShowCursor();
					cin >> s;
					HideCursor();
					if (s == "��") {
						goto st;
					}
					else if (s == "��") {
						cout << "��ȡ���������ص�������" << endl;
						Sleep(3000);
						goto menu;
					}
					else {
						cout << "�����������������룡";
						Sleep(2000);
						system("cls");
						goto pd1;
					}
				}
			}
			else if (s == "��") {
				cout << "��ȡ���������ص�������" << endl;
				Sleep(3000);
				goto menu;
			}
			else {
				cout << "�����������������룡";
				Sleep(2000);
				system("cls");
				goto pd;
			}
			}
			if (midd == 2) {
				system("cls");
				cout << "��ѡ��崻��ײͣ��������Ҽ�ѡ��enterȷ�ϣ���" << endl;
				Sleep(500);
				cout << "һ��崻��ң�30ö��     ";
				cout << "һ��崻��ң�50ö��     ";
				cout << "һ��崻��ң�100ö��    ";
				cout << "[�Ƽ�]����崻���/һ����" << endl;
				cout << "��15rmb                   ";
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
							cout << "����ѡ��һ��崻��ң�֧����15Ԫ" << endl;
							Sleep(2000);
							gameb += 30;
							cout << "֧���ɹ�����" << gameb << endl;
							Sleep(2000);
							goto menu;
						}
						else if (flagid == 2) {
							system("cls");
							Sleep(1000);
							cout << "����ѡ��һ��崻��ң�֧����25Ԫ" << endl;
							Sleep(2000);
							gameb += 50;
							cout << "֧���ɹ�����" << gameb << endl;
							Sleep(2000);
							goto menu;
						}
						else if (flagid == 3) {
							system("cls");
							Sleep(1000);
							cout << "����ѡ��һ��崻��ң�֧����50Ԫ" << endl;
							Sleep(2000);
							gameb += 100;
							cout << "֧���ɹ�����" << gameb << endl;
							Sleep(2000);
							goto menu;
						}
						else if (flagid == 4) {
							system("cls");
							Sleep(1000);
							cout << "����ѡ������崻���/һ���£�֧����60Ԫ" << endl;
							Sleep(2000);
							gameb = 1145141919180;
							cout << "֧���ɹ���������" << endl;
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
					cout << "��ǰ������" << endl;
					Sleep(1000);
					if (wxflag == 1) {
						cout << "ʱ��������" << endl;
					}
					else {
						cout << "ʱ����һ����" << endl;
					}
				}
				else {
					cout << "��ǰ��" << gameb  << endl;
					Sleep(1000);
					cout << "ʱ��������" << endl;
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
				cout << "������������";
				cin >> nz;
				if (nz == "wx114514") {
					gameb = 1145141919180;
					wxflag = 1;
					cout << endl;
					cout << "[����崻���]����������ɹ���" << endl;
					Sleep(1000);
					goto menu;
				}
				else if (nz == "yck100") {
					#define ygl 100
					yzbflag = 1;
					xzbflag = 0;
					cout << endl;
					cout << "[���ؿ�����]����������ɹ���" << endl;
					Sleep(1000);
					goto menu;
				}
				else if (nz == "xck100") {
					#define xgl 100
					xzbflag = 1;
					yzbflag = 0;
					cout << endl;
					cout << "[ϡ�п�����]����������ɹ���" << endl;
					Sleep(1000);
					goto menu;
				}
				else {
					cout << endl;
					cout << "��������Ч��" << endl;
					Sleep(1000);
					goto menu;
				}
			}
			if (midd == 7) {
                system("cls");
				cout << "����" << endl;
                Sleep(500);
				cout << endl;
				cout << "��������Downtime-BlindBoxMachine" << endl;
				Sleep(300);
				cout << "�汾��1.0.0" << endl;
				Sleep(300);
                
				cout << "�����ߣ�ANJourney" << endl;
                Sleep(300);
			}
		}
	}
	return 0;
}