#include <Windows.h>
#include <conio.h>
#include <stdlib.h>
#include <iostream>
#include <locale.h>
#include <ctime>
#include <fstream>
#include <vector>

using namespace std;

const int sizeMap = 10;
const int NUM_SHIPS = 9;
int ShipsID = 1;
int Ships[10] = { 0 };

void gotoxy(int x, int y)
{
	COORD p = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
}

enum ConsoleColor
{
	Black = 0, Blue = 1, Green = 2, Cyan = 3, Red = 4, Magenta = 5,
	Brown = 6, LightGray = 7, DarkGray = 8, LightBlue = 9, LightGreen = 10,
	LightCyan = 11, LightRed = 12, LightMagenta = 13, Yellow = 14, White = 15
};

void SetColor(ConsoleColor text, ConsoleColor background)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

void shipShow(int x, int y, int route, int sizeShip)
{
	for (int i = 0; i < sizeShip; i++) {
		gotoxy(x + 1, y + 1);
		cout << "| # ";
		switch (route)
		{
		case 0: x++; break;
		case 1: y++; break;
		case 2: x--; break;
		case 3: y--; break;
		}
	}
}

bool shipInMap(int x, int y, int route, int sizeShip)
{
	bool inMap = true;
	// проверка возможности постановки корабля
	for (int i = 0; i < sizeShip; i++) {
		if (x < 0 || y < 0 || x >= sizeMap || y >= sizeMap)
		{
			inMap = false;
			break;
		}

		switch (route)
		{
		case 0: x++; break;
		case 1: y++; break;
		case 2: x--; break;
		case 3: y--; break;
		}
	}
	return inMap;
}

bool setShip(int map[sizeMap][sizeMap], int x, int y, int route, int sizeShip)
{
	int saveX = x;
	int saveY = y;
	bool settingIsPossible = true;
	// проверка возможности постановки корабля
	for (int i = 0; i < sizeShip; i++) {
		if (x < 0 || y < 0 || x >= sizeMap || y >= sizeMap)
		{
			settingIsPossible = false;
			break;
		}
		if (map[x][y] >= 1)
		{
			settingIsPossible = false;
			break;
		}
		if (y < sizeMap - 1)
		{
			if (map[x][y + 1] >= 1)
			{
				settingIsPossible = false;
				break;
			}
		}
		if (y > 0)
		{
			if (map[x][y - 1] >= 1)
			{
				settingIsPossible = false;
				break;
			}
		}
		if (x < sizeMap - 1)
		{
			if (map[x + 1][y] >= 1)
			{
				settingIsPossible = false;
				break;
			}
		}
		if (x > 0)
		{
			if (map[x - 1][y] >= 1)
			{
				settingIsPossible = false;
				break;
			}
		}
		if (x < sizeMap - 1 && y < sizeMap - 1)
		{
			if (map[x + 1][y + 1] >= 1)
			{
				settingIsPossible = false;
				break;
			}
		}
		if (x < sizeMap - 1 && y > 0)
		{
			if (map[x + 1][y - 1] >= 1)
			{
				settingIsPossible = false;
				break;
			}
		}
		if (x > 0 && y < sizeMap - 1)
		{
			if (map[x - 1][y + 1] >= 1)
			{
				settingIsPossible = false;
				break;
			}
		}
		if (x > 0 && y > 0)
		{
			if (map[x - 1][y - 1] >= 1)
			{
				settingIsPossible = false;
				break;
			}
		}
		switch (route)
		{
		case 0: x++; break;
		case 1: y++; break;
		case 2: x--; break;
		case 3: y--; break;
		}
	}
	// если есть возможность поставить корабль, то ставим
	if (settingIsPossible) {
		x = saveX;
		y = saveY;
		for (int i = 0; i < sizeShip; i++) {
			map[x][y] = ShipsID;
			switch (route)
			{
			case 0: x++; break;
			case 1: y++; break;
			case 2: x--; break;
			case 3: y--; break;
			}
		}
		Ships[ShipsID] = sizeShip;
		ShipsID++;
	}
	return settingIsPossible;
}

//// функция случайной расстановки кораблей ////
void setRandShip(int map[sizeMap][sizeMap], int sizeShip, int shipID)
{
	int x, y;
	int direction = 0;
	int counterShip = 0;
	int counterTact = 0;
	srand(time(NULL));
	while (counterShip < 1)
	{
		counterTact++;
		if (counterTact > 1000) break;
		// первичная позиция
		x = rand() % sizeMap;
		y = rand() % sizeMap;
		int saveX = x;
		int saveY = y;
		// генерация направления
		direction = rand() % 4;
		bool settingIsPossible = true;
		// проверка возможности постановки корабля
		for (int i = 0; i < sizeShip; i++) {
			if (x < 0 || y < 0 || x >= sizeMap || y >= sizeMap)
			{
				settingIsPossible = false;
				break;
			}
			if (map[x][y] >= 1 ||
				map[x][y + 1] >= 1 ||
				map[x][y - 1] >= 1 ||
				map[x + 1][y] >= 1 ||
				map[x + 1][y + 1] >= 1 ||
				map[x + 1][y - 1] >= 1 ||
				map[x - 1][y] >= 1 ||
				map[x - 1][y + 1] >= 1 ||
				map[x - 1][y - 1] >= 1)
			{
				settingIsPossible = false;
				break;
			}
			switch (direction)
			{
			case 0: x++; break;
			case 1: y++; break;
			case 2: x--; break;
			case 3: y--; break;
			}
		}
		// если есть возможность поставить корабль, то ставим
		if (settingIsPossible) {
			x = saveX;
			y = saveY;
			for (int i = 0; i < sizeShip; i++) {
				map[x][y] = shipID;
				switch (direction)
				{
				case 0: x++; break;
				case 1: y++; break;
				case 2: x--; break;
				case 3: y--; break;
				}
			}
			counterShip++;
		}
	}
}

//// функция ручной расстановки кораблей ////
//void setHandShip(int map[sizeMap][sizeMap], int mask[sizeMap][sizeMap], int sizeShip, int route)
//{
//	//int buttonCode;
//	//while (true) 
//	//{
//	//	mapShow(map, mask, 0);
//	//	shipShow(x, y, route, sizeShip);
//	//	int saveX = x;
//	//	int saveY = y;
//	//	int savedir = route;
//	//	buttonCode = _getch();
//	//	switch (buttonCode)
//	//	{ // изменить координаты или направление
//	//	case 100: x++; break; // d - вправо
//	//	case 115: y++; break; // s - вниз
//	//	case 97: x--; break; // a - влево
//	//	case 119: y--; break; // w - вверх
//	//	case 114: route = !route; break; // r - поворот
//	//	case 13: // Enter - установка корабля
//	//	if (setShip(map, x, y, route, sizeShip)) 
//	//	{
//	//		x = 0; y = 0;
//	//		route = 0; 
//	//		sizeShip--;
//	//	}; break;
//	//	}
//	//	if (!shipInMap(x, y, route, sizeShip))
//	//	{
//	//		x = saveX;
//	//		y = saveY;
//	//		route = savedir;
//	//	}
//	//	if (sizeShip == 0) break;
//	//	system("cls");
//	//}
//}

//// функция рисования поля ////
void mapShow(int map[sizeMap][sizeMap], int mask[sizeMap][sizeMap], bool useMask)
{
	SetColor(LightCyan, Black);
	cout << "|   ";
	for (int i = 0; i < sizeMap; i++) {
		SetColor(LightCyan, Black);
		cout << "| " << i << " ";
		SetColor(LightBlue, LightGray);
	}
	cout << endl;
	for (int i = 0; i < sizeMap; i++) {
		SetColor(LightCyan, Black);
		cout << "| " << i << " ";
		SetColor(LightBlue, LightGray);
		for (int j = 0; j < sizeMap; j++) {
			if (mask[j][i] == 1 || useMask == 0)
			{
				if (map[j][i] == 0) cout << "| - ";
				else if (map[j][i] == -1) cout << "| X ";
				else if (map[j][i] == -2) cout << "| . ";
				else cout << "| " << map[j][i] << " ";
			}
			else cout << "|   ";
		}
		cout << "|" << endl;
	}
	SetColor(LightCyan, Black);
}

int shot(int map[sizeMap][sizeMap], int mask[sizeMap][sizeMap], int x, int y, int ships[NUM_SHIPS + 1])
{
	int result = 0;
	if (map[x][y] == -1 || map[x][y] == -2)
	{
		result = 3;
	}
	else if (map[x][y] >= 1)
	{
		ships[map[x][y]]--;
		if (ships[map[x][y]] <= 0) {
			result = 2;
		}
		else {
			result = 1;
		}
		map[x][y] = -1;
	}
	else {
		map[x][y] = -2;
	}
	mask[x][y] = 1;
	return result;
}

int Game() {
	setlocale(LC_CTYPE, "rus");
	while (true)
	{
		// игровые поля
		int map[sizeMap][sizeMap] = { 0 };
		int mapAI[sizeMap][sizeMap] = { 0 };
		int mask[sizeMap][sizeMap] = { 0 };
		int maskAI[sizeMap][sizeMap] = { 0 };
		// корабли
		int shipsPlayer[NUM_SHIPS + 1] = { 0, 4, 3, 3, 2, 2, 2, 1, 1, 1 };
		int shipsAI[NUM_SHIPS + 1] = { 0, 4, 3, 3, 2, 2, 2, 1, 1, 1 };
		//int route = 0; // по умолчанию горизонтальное направление корабля
		for (int i = 1; i <= NUM_SHIPS; i++)
		{ // случайная расстановка кораблей игрока
			setRandShip(map, shipsPlayer[i], i);
		}
		for (int i = 1; i <= NUM_SHIPS; i++)
		{ // случайная расстановка кораблей компьютера
			setRandShip(mapAI, shipsAI[i], i);
		}
		int x = 0, y = 0;
		int sizeShip = 4;
		int xAI = 0, yAI = 0;
		int firstHitX = 0, firstHitY = 0, mode = 0, dir = 0;
		vector <int> dirs;
		dirs.push_back(3);
		dirs.push_back(2);
		dirs.push_back(1);
		dirs.push_back(0);
		bool winHuman = 0;
		bool winAI = 0;
		bool turn = 1;
		while (winHuman == false && winAI == false)
		{
			int resultShot = 0;
			do
			{
				mapShow(map, mask, 0);
				cout << endl;
				mapShow(mapAI, maskAI, 1);
				if (turn == 1) {
					SetColor(White, Black);
					cout << endl << "Введите координаты цели: ";
					cin >> x; cin >> y;
					SetColor(LightBlue, Black);
					resultShot = shot(mapAI, maskAI, x, y, shipsAI);
					if (resultShot == 1) {
						cout << "Ранен" << endl;
					}
					else if (resultShot == 2) {
						bool killed = 1;
						for (int i = 1; i <= NUM_SHIPS; i++)
						{
							if (shipsAI[i] != 0)
							{
								killed = 0;
								break;
							}
						}
						if (killed == 1)
						{
							winHuman = 1;
							break;
						}
						cout << "Убит" << endl;
					}
					else {
						cout << "Промах" << endl;
					}
				}
				else {
					cout << endl << "Ход компьютера: ";
					Sleep(1000);
					if (mode == 0)
					{
						do {
							xAI = rand() % sizeMap;
							yAI = rand() % sizeMap;
							resultShot = shot(map, mask, xAI, yAI, shipsPlayer);
						} while (resultShot == 3);
						if (resultShot == 1) {
							mode = 1;
							firstHitX = xAI;
							firstHitY = yAI;
							if (!dirs.empty())
							{
								dir = dirs[dirs.size() - 1];
								dirs.pop_back();
							}
							cout << "Ранен" << endl;
						}
						else if (resultShot == 2) {
							bool killed = 1;
							for (int i = 1; i <= NUM_SHIPS; i++)
							{
								if (shipsPlayer[i] != 0)
								{
									killed = 0;
									break;
								}
							}
							if (killed == 1)
							{
								winAI = 1;
								break;
							}
							cout << "Убит" << endl;
						}
						else {
							cout << "Промах" << endl;
						}
					}
					else
					{
						bool changeDir = 0;
						if (dir == 0) // влево
						{
							if (xAI > 0) xAI--;
							else
							{
								changeDir = 1;
							}
						}
						else if (dir == 1) // вправо
						{
							if (xAI < sizeMap - 1) xAI++;
							else
							{
								changeDir = 1;
							}
						}
						else if (dir == 2) // вверх
						{
							if (yAI > 0) yAI--;
							else
							{
								changeDir = 1;
							}
						}
						else if (dir == 3) // вниз
						{
							if (yAI < sizeMap - 1) yAI++;
							else
							{
								changeDir = 1;
							}
						}
						if (changeDir == 1)
						{
							if (!dirs.empty())
							{
								dir = dirs[dirs.size() - 1];
								dirs.pop_back();
							}
							xAI = firstHitX;
							yAI = firstHitY;
							continue;
						}
						resultShot = shot(map, mask, xAI, yAI, shipsPlayer);
						if (resultShot == 1) {
							cout << "Ранен" << endl;
						}
						else if (resultShot == 2) {
							mode = 0;
							dirs.clear();
							dirs.push_back(3);
							dirs.push_back(2);
							dirs.push_back(1);
							dirs.push_back(0);
							bool killed = 1;
							for (int i = 1; i <= NUM_SHIPS; i++)
							{
								if (shipsPlayer[i] != 0)
								{
									killed = 0;
									break;
								}
							}
							if (killed == 1)
							{
								winAI = 1;
								break;
							}
							cout << "Убит" << endl;
						}
						else {
							if (!dirs.empty())
							{
								dir = dirs[dirs.size() - 1];
								dirs.pop_back();
							}
							xAI = firstHitX;
							yAI = firstHitY;
							cout << "Промах" << endl;
						}
					}
				}
				Sleep(1000);
				system("cls");
			} while (resultShot != 0);
			turn = !turn;
		}
		if (winHuman == true) {
			cout << "Вы ПОБЕДИЛИ !!!" << endl;
		}
		if (winAI == true) {
			cout << "ПОРАЖЕНИЕ" << endl;
		}
		_getch();
		system("cls");
	}
	//_getch();
	system("pause");
	return 0;
}

void SystemFonGame()
{
	HWND hwn = GetConsoleWindow();
	HDC hdc = GetDC(hwn);
	HPEN pen = CreatePen(PS_DASHDOT, 2, RGB(10, 10, 100));
	HBRUSH brush = CreateSolidBrush(RGB(10, 10, 100));
	SelectObject(hdc, pen);
	SelectObject(hdc, brush);
	Rectangle(hdc, 0, 0, 10000, 10000);
}

void Help() {
	SystemFonGame();
	int x = 5, y = 5;
	char symbol = '-';
	gotoxy(x, y - 2);
	printf("%20c", symbol);
	gotoxy(x, y);
	printf(" Для начала игры вам необходимо нажать на кнопку 'Начать игру'.");
	gotoxy(x, y + 2);
	printf(" После того как начнётся игра, вы увидите два поля.");
	gotoxy(x, y + 4);
	printf(" Верхнее поле - ваше, нижнее - соперника.");
	gotoxy(x, y + 6);
	printf(" Если сейчас ваш черёд хода, введите координаты клетки поля");
	gotoxy(x, y + 8);
	printf(" соперника, по которым предполагается выстрел.");
	gotoxy(x, y + 10);
	printf(" Если вы попали по кораблю или подбили его, то вы сново сможете");
	gotoxy(x, y + 12);
	printf(" ходить. Если вы промахнулись, то ход совершает ваш соперник.");
	gotoxy(x, y + 14);
	printf(" Игра ведётся до тех пор, пока один из игроков не уничтожит");
	gotoxy(x, y + 16);
	printf(" весь флот соперника.");
	gotoxy(x, y + 18);
	printf(" Удачной игры!");
	gotoxy(x, y + 20);
	printf("%20c", symbol);
	_getch();
}

void selectItemMenu(int position) {
	switch (position) {
	case 0: Game(); SystemFonGame(); break;
	case 1: Help(); SystemFonGame(); break;
	case 2: exit(0);
	}
}

int toGameMenu() {
	setlocale(LC_CTYPE, "rus");
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	WORD active = FOREGROUND_GREEN | FOREGROUND_INTENSITY;
	WORD noActive = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY;
	char lines[][20] = { "Начать игру", "Помощь", "Выход" };
	COORD coordinate;
	int position = 0, lastItemMenu = 3;
	char code;
	while (true) {
		system("cls");
		for (int i = 0; i < lastItemMenu; i++) {
			if (position == i)
				SetConsoleTextAttribute(handle, active);
			else
				SetConsoleTextAttribute(handle, noActive);
			gotoxy(25, 5 + i * 2);
			cout << i + 1 << ") " << lines[i] << endl;
		}
		code = _getch();
		if (code == 72) {
			if (position == 0) position = lastItemMenu - 1;
			else position--;
		}
		if (code == 80) {
			if (position == lastItemMenu - 1) position = 0;
			else position++;
		}
		if (code == 13) selectItemMenu(position);
	}
	return 0;
}