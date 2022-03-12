#include <Windows.h>
#include <conio.h>
#include <locale.h>
#include <iostream>

#pragma warning(disable:4996)

using namespace std;

// список студентов группы
struct student
{
	char firstName[20];
	char secondName[20];
	char town[20];
	unsigned int school;
};

extern FILE *DB;

void changeItemMenu(int position);
void browsingRecords();
void searchRecords();

HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
WORD colorPrimaryText = FOREGROUND_RED | FOREGROUND_INTENSITY;
WORD colorAccentText = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;

void menuHandbook() {
	char lines[][30] = { "Просмотр (Browsing)", "Поиск (Search)", "Добавить (Add)", 
		"Редактирование (Edit)", "Удалить (Delete)", "Выход (Exit)" };
	WORD active = FOREGROUND_GREEN | FOREGROUND_INTENSITY;
	WORD noActive = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY;
	const int startPosX = 15, startPosY = 5;
	int position = 0, lastItemMenu = 6;
	char code, space = ' ';
	COORD coordinate;
	while (true) {
		system("cls");
		for (int i = 0; i < lastItemMenu; i++) {
			if (position == i)
				SetConsoleTextAttribute(handle, active);
			else
				SetConsoleTextAttribute(handle, noActive);
			coordinate.X = startPosX; coordinate.Y = startPosY + i * 2;
			SetConsoleCursorPosition(handle, coordinate);
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
		if (code == 13) changeItemMenu(position);
	}
}

void changeItemMenu(int position) {
	switch (position) {
	case 0: browsingRecords(); system("cls"); break;
	case 1: searchRecords(); system("cls"); break;
		//case 2: addRecords(); SystemClear(); break;
		//case 3: editRecords(); system("cls"); break;
		//case 4: deleteRecords(); system("cls"); break;
	case 5: exit(1);
	}
}

void browsingRecords() {
	system("cls");
	struct student z[20];
	const int startPosX = 10, startPosY = 2;
	int i = 0; char space = ' ';
	COORD coordinate;

	if ((DB = fopen("student_group.txt", "r")) == NULL) {
		coordinate.X = startPosX; coordinate.Y = startPosY;
		SetConsoleCursorPosition(handle, coordinate);
		SetConsoleTextAttribute(handle, colorPrimaryText);
		cout << "Файл НЕ ВОЗМОЖНО открыть, т.к. он не создан";
		exit(1);
	}
	coordinate.X = startPosX; coordinate.Y = startPosY;
	SetConsoleCursorPosition(handle, coordinate);
	SetConsoleTextAttribute(handle, colorPrimaryText);
	cout << "Файл успешно открыт!!!";

	coordinate.X = startPosX - 5; coordinate.Y = startPosY + 2;
	SetConsoleCursorPosition(handle, coordinate);
	SetConsoleTextAttribute(handle, colorAccentText);
	printf("\t------------------------------------------------------------------\n");
	printf("\t|   Имя   |   Фамилия   |    Город обучения    |   Номер школы   |\n");
	printf("\t|         |             |                      |                 |\n");
	while (!feof(DB)) {
		fscanf(DB, "%s", z[i].firstName);
		printf("\t|%9s", z[i].firstName);
		fscanf(DB, "%s", z[i].secondName);
		printf("|%13s", z[i].secondName);
		fscanf(DB, "%s", z[i].town);
		printf("|%22s", z[i].town);
		if (strcmp(z[i].town, "Омск") == 0) {
			fscanf_s(DB, "%u", &z[i].school);
			printf("|%17u|\n", z[i].school);
		}
		else {
			fscanf_s(DB, "%u", &z[i].school);
			printf("|%17c|\n", space);
		}
		i++;
	}
	printf("\t------------------------------------------------------------------\n");
	fclose(DB);
	_getch();
}

void searchRecords() {
	system("cls");
	//setlocale(LC_CTYPE, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	struct student z[20];
	const int startPosX = 10, startPosY = 2;
	int i = 0; char space = ' ';
	COORD coordinate;

	if ((DB = fopen("student_group.txt", "r")) == NULL) {
		coordinate.X = startPosX; coordinate.Y = startPosY;
		SetConsoleCursorPosition(handle, coordinate);
		SetConsoleTextAttribute(handle, colorPrimaryText);
		cout << "Файл НЕ ВОЗМОЖНО открыть, т.к. он не создан" << endl;
		exit(1);
	}
	coordinate.X = startPosX; coordinate.Y = startPosY;
	SetConsoleCursorPosition(handle, coordinate);
	SetConsoleTextAttribute(handle, colorPrimaryText);
	cout << "Файл успешно открыт!!!" << endl;

	char secondNameSearch[20];
	printf("\tВведите фамилию студента для поиска: ");
	SetConsoleTextAttribute(handle, colorAccentText);
	cin.getline(secondNameSearch, 20);

	coordinate.X = startPosX - 5; coordinate.Y = startPosY + 4;
	SetConsoleCursorPosition(handle, coordinate);
	printf("\t------------------------------------------------------------------\n");
	printf("\t|   Имя   |   Фамилия   |    Город обучения    |   Номер школы   |\n");
	printf("\t|         |             |                      |                 |\n");
	while (!feof(DB)) {
		fscanf(DB, "%s", z[i].firstName);
		fscanf(DB, "%s", z[i].secondName);
		fscanf(DB, "%s", z[i].town);
		fscanf_s(DB, "%u", &z[i].school);
		if (strcmp(z[i].secondName, secondNameSearch) == 0) {
			printf("\t|%9s", z[i].firstName);
			printf("|%13s", z[i].secondName);
			printf("|%22s", z[i].town);
			if (strcmp(z[i].town, "Омск") == 0)
				printf("|%17u|\n", z[i].school);
			else printf("|%17c|\n", space);
		}
		i++;
	}
	printf("\t------------------------------------------------------------------\n");
	fclose(DB);
	_getch();
}