#include <conio.h>
#include <ctime>
#include <fstream>
#include <windows.h>

using namespace std;

int random(int range) {
	//srand(time(NULL));
	return rand() % range;
}

void SystemClear() {
	system("cls");
	HWND hwn = GetConsoleWindow();
	HDC hdc = GetDC(hwn);
	HPEN pen = CreatePen(PS_DASHDOT, 2, RGB(0, 0, 0));
	HBRUSH brush = CreateSolidBrush(RGB(0, 0, 0));
	SelectObject(hdc, pen);
	SelectObject(hdc, brush);
	Rectangle(hdc, 0, 0, 10000, 10000);
}

// В траве сидел кузнечик
void Grasshoper()
{
	Beep(440, 300);
	Beep(330, 300);
	Beep(440, 300);
	Beep(330, 300);
	Beep(440, 300);
	Beep(415, 300);
	Beep(415, 300);
	Sleep(600);
	Beep(415, 300);
	Beep(330, 300);
	Beep(415, 300);
	Beep(330, 300);
	Beep(415, 300);
	Beep(440, 300);
	Beep(440, 300);
	Sleep(600);
	Beep(440, 300);
	Beep(494, 300);
	Beep(494, 100);
	Beep(494, 100);
	Beep(494, 300);
	Beep(494, 300);
	Beep(523, 300);
	Beep(523, 100);
	Beep(523, 100);
	Beep(523, 300);
	Beep(523, 300);
	Beep(523, 300);
	Beep(494, 300);
	Beep(440, 300);
	Beep(415, 300);
	Beep(440, 800);
}

// В лесу родилась елочка
void Tannenbaum()
{
	Beep(247, 500);
	Beep(417, 500);
	Beep(417, 500);
	Beep(370, 500);
	Beep(417, 500);
	Beep(329, 500);
	Beep(247, 500);
	Beep(247, 500);
	Beep(247, 500);
	Beep(417, 500);
	Beep(417, 500);
	Beep(370, 500);
	Beep(417, 500);
	Beep(497, 500);
	Sleep(500);
	Beep(497, 500);
	Beep(277, 500);
	Beep(277, 500);
	Beep(440, 500);
	Beep(440, 500);
	Beep(417, 500);
	Beep(370, 500);
	Beep(329, 500);
	Beep(247, 500);
	Beep(417, 500);
	Beep(417, 500);
	Beep(370, 500);
	Beep(417, 500);
	Beep(329, 500);
}

void MissionImpossible()
{
	Beep(784, 150);
	Sleep(300);
	Beep(784, 150);
	Sleep(300);
	Beep(932, 150);
	Sleep(150);
	Beep(1047, 150);
	Sleep(150);
	Beep(784, 150);
	Sleep(300);
	Beep(784, 150);
	Sleep(300);
	Beep(699, 150);
	Sleep(150);
	Beep(740, 150);
	Sleep(150);
	Beep(784, 150);
	Sleep(300);
	Beep(784, 150);
	Sleep(300);
	Beep(932, 150);
	Sleep(150);
	Beep(1047, 150);
	Sleep(150);
	Beep(784, 150);
	Sleep(300);
	Beep(784, 150);
	Sleep(300);
	Beep(699, 150);
	Sleep(150);
	Beep(740, 150);
	Sleep(150);
	Beep(932, 150);
	Beep(784, 150);
	Beep(587, 1200);
	Sleep(75);
	Beep(932, 150);
	Beep(784, 150);
	Beep(554, 1200);
	Sleep(75);
	Beep(932, 150);
	Beep(784, 150);
	Beep(523, 1200);
	Sleep(150);
	Beep(466, 150);
	Beep(523, 150);
}

void StarWars()
{
	system("cls");
	HWND hwn = GetConsoleWindow();
	HDC hdc = GetDC(hwn);
	HPEN PEN; HBRUSH BRUSH;
	RECT rect; GetClientRect(hwn, &rect);
	int frequency, duration, R, G, B, x = 0, y = rect.bottom;
	ifstream in;	// поток для чтения
	in.open(".\\music\\star_wars.txt");
	if (in.is_open())
	{
		while (in >> frequency >> duration)
		{
			R = random(256); G = random(256); B = random(256);
			PEN = CreatePen(PS_SOLID, 5, RGB(R, G, B));
			BRUSH = CreateSolidBrush(RGB(R, G, B));
			SelectObject(hdc, PEN); SelectObject(hdc, BRUSH);
			Rectangle(hdc, x, y - frequency, x + 20, y);
			Beep(frequency, duration);
			x += 20;
			Sleep(duration);
		}
	}
	else cout << "Не удалось открыть файл!" << endl;
}

void SuperMario()
{
	system("cls");
	HWND hwn = GetConsoleWindow();
	HDC hdc = GetDC(hwn);
	HPEN PEN; HBRUSH BRUSH;
	RECT rect;
	GetClientRect(hwn, &rect);
	int frequency[] = { 1318, 1318, 1318, 1046, 1318, 1568, 784,
						1046, 784, 659, 880, 987, 932, 880, 784,
						1318, 1568, 1750, 1396, 1568, 1318, 1046, 
						1174, 987, 1046, 784, 659, 880, 987, 932, 
						880, 784, 1318, 1568, 1750, 1396, 1568, 1318, 
						1046, 1174, 987, 1568, 1480, 1396, 1244, 1318, 
						830, 880, 1046, 880, 1046, 1174, 0, 1568, 1480, 
						1396, 1244, 1318, 2093, 2093, 2093, 1568, 1480, 
						1396, 1244, 1318, 830, 880, 1046, 880, 1046, 
						1174, 1244, 1174, 1046 };
	int duration[] = { 150, 300, 150, 150, 300, 600, 600,
					450, 150, 300, 300, 150, 150, 300, 210,
					210, 150, 300, 150, 150, 300, 150, 150, 
					450, 450, 150, 300, 300, 150, 150, 300,
					210, 210, 150, 300, 150, 150, 300, 150, 
					150, 450, 150, 150, 150, 300, 150, 150, 
					150, 150, 150, 150, 150, 0,	  150, 150, 
					150, 300, 150, 300, 150, 600, 150, 150, 
					150, 300, 150, 150, 150, 150, 150, 150, 
					150, 300, 450, 600 };
	int track_duration = 75, R, G, B, x = 0, y = rect.bottom;
	for (int i = 0; i < track_duration; i++)
	{
		R = random(256); G = random(256); B = random(256);
		PEN = CreatePen(PS_SOLID, 5, RGB(R, G, B));
		BRUSH = CreateSolidBrush(RGB(R, G, B));
		SelectObject(hdc, PEN); SelectObject(hdc, BRUSH);
		Rectangle(hdc, x, y - frequency[i] / 2, x + 20, y);
		Beep(frequency[i], duration[i]);
		x += 20;
		Sleep(duration[i] / 2);
		if (x >= rect.right)
		{
			SystemClear();
			x = 0;
			y = rect.bottom;
		}
	}
}

void Beethoven()
{
	Beep(659, 120);
	Sleep(130);
	Beep(622, 120);
	Sleep(130);

	Beep(659, 120);
	Sleep(130);
	Beep(622, 120);
	Sleep(130);
	Beep(659, 120);
	Sleep(130);
	Beep(494, 120);
	Sleep(130);
	Beep(587, 120);
	Sleep(130);
	Beep(523, 120);
	Sleep(130);

	Beep(440, 120);
	Sleep(150);
	Beep(262, 120);
	Sleep(130);
	Beep(330, 120);
	Sleep(130);
	Beep(440, 120);
	Sleep(130);

	Beep(494, 120);
	Sleep(150);
	Beep(330, 120);
	Sleep(130);
	Beep(415, 120);
	Sleep(130);
	Beep(494, 120);
	Sleep(130);

	Beep(523, 120);
	Sleep(150);
	Beep(330, 120);
	Sleep(130);
	Beep(659, 120);
	Sleep(130);
	Beep(622, 120);
	Sleep(130);

	Beep(659, 120);
	Sleep(130);
	Beep(622, 120);
	Sleep(130);
	Beep(659, 120);
	Sleep(130);
	Beep(494, 120);
	Sleep(130);
	Beep(587, 120);
	Sleep(130);
	Beep(523, 120);
	Sleep(130);

	Beep(440, 120);
	Sleep(150);
	Beep(262, 120);
	Sleep(130);
	Beep(330, 120);
	Sleep(130);
	Beep(440, 120);
	Sleep(130);

	Beep(494, 120);
	Sleep(150);
	Beep(330, 120);
	Sleep(130);
	Beep(523, 120);
	Sleep(130);
	Beep(494, 120);
	Sleep(150);
	Beep(440, 120);
}

void HappyBirthday()
{
	Sleep(2000);
	Beep(264, 125);
	Sleep(250);
	Beep(264, 125);
	Sleep(125);
	Beep(297, 500);
	Sleep(125);
	Beep(264, 500);
	Sleep(125);
	Beep(352, 500);
	Sleep(125);
	Beep(330, 1000);
	Sleep(250);
	Beep(264, 125);
	Sleep(250);
	Beep(264, 125);
	Sleep(125);
	Beep(297, 500);
	Sleep(125);
	Beep(264, 500);
	Sleep(125);
	Beep(396, 500);
	Sleep(125);
	Beep(352, 1000);
	Sleep(250);
	Beep(264, 125);
	Sleep(250);
	Beep(264, 125);
	Sleep(125);
	Beep(2642, 500);
	Sleep(125);
	Beep(440, 500);
	Sleep(125);
	Beep(352, 250);
	Sleep(125);
	Beep(352, 125);
	Sleep(125);
	Beep(330, 500);
	Sleep(125);
	Beep(297, 1000);
	Sleep(250);
	Beep(466, 125);
	Sleep(250);
	Beep(466, 125);
	Sleep(125);
	Beep(440, 500);
	Sleep(125);
	Beep(352, 500);
	Sleep(125);
	Beep(396, 500);
	Sleep(125);
	Beep(352, 1000);
}

int musicBox() {
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	char code;
	int x = 5, y = 5; 
	int randMusic;
	int countMusic = 7;
	COORD p = { x, y };
	do
	{
		system("cls");
		SetConsoleCursorPosition(handle, p);
		cout << "Нажмите Enter для открытия шкатулки!";
		code = _getch();
		if (code == 13) {
			srand((unsigned)time(0));
			//randMusic = rand() % countMusic;
			randMusic = 3;
			switch (randMusic)
			{
			case 0: Grasshoper(); break;
			case 1: Tannenbaum(); break;
			case 2: MissionImpossible(); break;
			case 3: StarWars(); break;
			case 4: SuperMario(); break;
			case 5: Beethoven(); break;
			case 6: HappyBirthday(); break;
			}
		}
	} while (code != 27);
	return 0;
}