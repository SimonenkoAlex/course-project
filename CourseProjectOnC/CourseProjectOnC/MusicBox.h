#include <conio.h>
#include <ctime>
#include <windows.h>

using namespace std;

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
	Beep(300, 500);
	Sleep(50);
	Beep(300, 500);
	Sleep(50);
	Beep(300, 500);
	Sleep(50);
	Beep(250, 500);
	Sleep(50);
	Beep(350, 250);
	Beep(300, 500);
	Sleep(50);
	Beep(250, 500);
	Sleep(50);
	Beep(350, 250);
	Beep(300, 500);
	Sleep(50);
}

void SuperMario()
{
	Beep(659, 125);
	Beep(659, 125);
	Sleep(125);
	Beep(659, 125);
	Sleep(167);
	Beep(523, 125);
	Beep(659, 125);
	Sleep(125);
	Beep(784, 125);
	Sleep(375);
	Beep(392, 125);
	Sleep(375);
	Beep(523, 125);
	Sleep(250);
	Beep(392, 125);
	Sleep(250);
	Beep(330, 125);
	Sleep(250);
	Beep(440, 125);
	Sleep(125);
	Beep(494, 125);
	Sleep(125);
	Beep(466, 125);
	Sleep(42);
	Beep(440, 125);
	Sleep(125);
	Beep(392, 125);
	Sleep(125);
	Beep(659, 125);
	Sleep(125);
	Beep(784, 125);
	Sleep(125);
	Beep(880, 125);
	Sleep(125);
	Beep(698, 125);
	Beep(784, 125);
	Sleep(125);
	Beep(659, 125);
	Sleep(125);
	Beep(523, 125);
	Sleep(125);
	Beep(587, 125);
	Beep(494, 125);
	Sleep(125);
	Beep(523, 125);
	Sleep(250);
	Beep(392, 125);
	Sleep(250);
	Beep(330, 125);
	Sleep(250);
	Beep(440, 125);
	Sleep(125);
	Beep(494, 125);
	Sleep(125);
	Beep(466, 125);
	Sleep(42);
	Beep(440, 125);
	Sleep(125);
	Beep(392, 125);
	Sleep(125);
	Beep(659, 125);
	Sleep(125);
	Beep(784, 125);
	Sleep(125);
	Beep(880, 125);
	Sleep(125);
	Beep(698, 125);
	Beep(784, 125);
	Sleep(125);
	Beep(659, 125);
	Sleep(125);
	Beep(523, 125);
	Sleep(125);
	Beep(587, 125);
	Beep(494, 125);
	Sleep(375);
	Beep(784, 125);
	Beep(740, 125);
	Beep(698, 125);
	Sleep(42);
	Beep(622, 125);
	Sleep(125);
	Beep(659, 125);
	Sleep(167);
	Beep(415, 125);
	Beep(440, 125);
	Beep(523, 125);
	Sleep(125);
	Beep(440, 125);
	Beep(523, 125);
	Beep(587, 125);
	Sleep(250);
	Beep(784, 125);
	Beep(740, 125);
	Beep(698, 125);
	Sleep(42);
	Beep(622, 125);
	Sleep(125);
	Beep(659, 125);
	Sleep(167);
	Beep(698, 125);
	Sleep(125);
	Beep(698, 125);
	Beep(698, 125);
	Sleep(625);
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
	char code;
	int x = 5, y = 5; 
	int randMusic;
	int countMusic = 7;
	COORD p = { x, y };
	do
	{
		system("cls");
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
		cout << "Нажмите Enter для открытия шкатулки!";
		code = _getch();
		if (code == 13) {
			srand((unsigned)time(0));
			randMusic = rand() % countMusic;
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