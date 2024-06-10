#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <shellapi.h>
#include <cstdlib>
#include <stralign.h>
#include <string>
#include <conio.h>
#include <mmsystem.h>
#include <xaudio2.h>

#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "xaudio2.lib")

#define UP 72 
#define DWN 80 
#define back 8
#define esc 27
#define ENTR 13
#define ETR 13
#define upa 72
#define dwns 80


using namespace std;

HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE); 



void ConsoleCursorVisible(bool show, short size)
{
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(hStdOut, &structCursorInfo);
	structCursorInfo.bVisible = show; 
	structCursorInfo.dwSize = size; 
	SetConsoleCursorInfo(hStdOut, &structCursorInfo);
}


void GoToXY(short x, short y)
{
	SetConsoleCursorPosition(hStdOut, { x, y });
}

void GoToXB(short b, short s)
{
	SetConsoleCursorPosition(hStdOut, { b, s });
}

void GoToMN(short m, short n)
{
	SetConsoleCursorPosition(hStdOut, { m, n });
}


int main() {
	waveOutSetVolume(0, 0x20002000);
	PlaySound(TEXT(".\\sounds\\main.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	setlocale(LC_ALL, "ru");
	system("mode con cols=163 lines=19");
	ConsoleCursorVisible(false, 100);
	string Stral[] = { " [>>]" };
	string Stral2[] = { " [>] " };
	string Menu[] = { Stral2[0] + " ДИСК",  Stral2[0] + " Активация Windows 10",  Stral2[0] + " Активация Windows 11",  Stral2[0] + " Информация",  Stral2[0] + " Выход" };
	string Logo[] = { " $$\\      $$\\ $$\\                 $$\\                                          $$$$$$\\              $$\\     $$\\                      $$\\                           $$ | $\\  $$ |\\__|                $$ |                                        $$  __$$\\             $$ |    \\__|                     $$ |                          $$ |$$$\\ $$ |$$\\ $$$$$$$\\   $$$$$$$ | $$$$$$\\  $$\\  $$\\  $$\\  $$$$$$$\\       $$ /  $$ | $$$$$$$\\ $$$$$$\\   $$\\ $$\\    $$\\ $$$$$$\\ $$$$$$\\    $$$$$$\\   $$$$$$\\    $$ $$ $$\\$$ |$$ |$$  __$$\\ $$  __$$ |$$  __$$\\ $$ | $$ | $$ |$$  _____|      $$$$$$$$ |$$  _____|\\_$$  _|  $$ |\\$$\\  $$  |\\____$$\\\\_$$  _|  $$  __$$\\ $$  __$$\\   $$$$  _$$$$ |$$ |$$ |  $$ |$$ /  $$ |$$ /  $$ |$$ | $$ | $$ |\\$$$$$$\\        $$  __$$ |$$ /        $$ |    $$ | \\$$\\$$  / $$$$$$$ | $$ |    $$ /  $$ |$$ |  \\__|  $$$  / \\$$$ |$$ |$$ |  $$ |$$ |  $$ |$$ |  $$ |$$ | $$ | $$ | \\____$$\\       $$ |  $$ |$$ |        $$ |$$\\ $$ |  \\$$$  / $$  __$$ | $$ |$$\\ $$ |  $$ |$$ |        $$  /   \\$$ |$$ |$$ |  $$ |\\$$$$$$$ |\\$$$$$$  |\\$$$$$\\$$$$  |$$$$$$$  |      $$ |  $$ |\\$$$$$$$\\   \\$$$$  |$$ |   \\$  /  \\$$$$$$$ | \\$$$$  |\\$$$$$$  |$$ |        \\__/     \\__|\\__|\\__|  \\__| \\_______| \\______/  \\_____\\____/ \\_______/       \\__|  \\__| \\_______|   \\____/ \\__|    \\_/    \\_______|  \\____/  \\______/ \\__|      " };
	string info[] = { Stral2[0] + " [Discord]",  Stral2[0] + " [GitHub]" };
	char ch;
	wstring disc;
	string wd10, wd11, wds;
	wstring dis = L"c";
	int active_menu = 0, act_info =0;
	SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);

	

	while (true)
	{
		string Stral[] = { " [>>]" };
		ExALL:
		SetConsoleTitle(L"Windows Activator.v2 by CHEATER KID");
		int b = 1, s = 1;
		GoToXB(b, s);
		for (int a = 0; a < size(Logo); a++) {
			if (a == active_menu) {
				int color = rand() % 15 + 1;
				SetConsoleTextAttribute(hStdOut, FOREGROUND_INTENSITY | color);
			}
			else if (a != active_menu) {
				int color = rand() % 15 + 1;
				SetConsoleTextAttribute(hStdOut, FOREGROUND_INTENSITY | color);
			}
			else 	SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);
			GoToXB(b, s++);
			std::cout << Logo[a] << endl;
		}
		
		int x = 5, y = 12;
		GoToXY(x, y);
		for (int i = 0; i < sizeof(Menu) / sizeof(Menu[0]); i++) {
			if (i == active_menu) {
				SetConsoleTextAttribute(hStdOut, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
				GoToXY(x, y++);
				Menu[i] = Stral[0] + Menu[i].substr(5);
				std::cout << Menu[i];
			}
			else {
				SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);
				Menu[i] = Stral2[0] + Menu[i].substr(5);
				GoToXY(x, y++);
				std::cout << Menu[i];
			}
		}
		
		ch = _getch();
	if (ch == -32) ch = _getch(); 
		switch (ch)
		{
		case esc:
			system("cls");
			system("mode con cols=72 lines=15");
			GoToXB(b, s);
			std::cout << "$$$$$$$\\                            $$\\                           \n";
			std::cout << " $$  __$$\\                           $$ |                          \n";
			std::cout << " $$ |  $$ |$$\\   $$\\  $$$$$$\\        $$$$$$$\\  $$\\   $$\\  $$$$$$\\  \n";
			std::cout << " $$$$$$$\\ |$$ |  $$ |$$  __$$\\       $$  __$$\\ $$ |  $$ |$$  __$$\\ \n";
			std::cout << " $$  __$$\\ $$ |  $$ |$$$$$$$$ |      $$ |  $$ |$$ |  $$ |$$$$$$$$ |\n";
			std::cout << " $$ |  $$ |$$ |  $$ |$$   ____|      $$ |  $$ |$$ |  $$ |$$   ____|\n";
			std::cout << " $$$$$$$  |\\$$$$$$$ |\\$$$$$$$\\       $$$$$$$  |\\$$$$$$$ |\$$$$$$$\\ \n";
			std::cout << " \\_______/  \\____$$ | \\_______|      \\_______/  \\____$$ | \\______|\n";
			std::cout << "           $$\\   $$ |                          $$\\   $$ |          \n";
			std::cout << "           \\$$$$$$  |                          \\$$$$$$  |          \n";
			std::cout << "            \\______/                            \\______/           \n";
			Sleep(1337);
			exit(0);
		case UP:
			if (active_menu > 0) {
				--active_menu;
			}
			break;

		case DWN:
			if (active_menu < size(Menu)-1) {
				++active_menu;
			}
			break;
		case ENTR:
			switch (active_menu)
			{
			case 0:
				SetConsoleTitle(L"ВЫБОР ДИСКА: ! ТОЛЬКО НА ENG !");
				system("mode con cols=65 lines=7");
				system("cls");
				SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
				std::cout << "\n	 !!! ПИШИ НАЗВАНИЕ ДИСКА НА ENG !!!\n";
				SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);
				std::cout << " [>>] Выбери диск на котором установлена Windows (Пример: c): ";
				wcin >> disc;
				system("cls");
				system("mode con cols=162 lines=19");
				break;
			case 1:
				SetConsoleTitle(L"Windows 10");
				system("cls");
				system("mode con cols=110 lines=24");
				SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);
				std::cout << "\n [1] Windows 10 Pro                         [20] Windows 10 Core Country Specific\n";
				std::cout << " [2] Windows 10 Pro N                       [21] Windows 10 Education\n";
				std::cout << " [3] Windows 10 Pro Enterprise              [22] Windows 10 Education N\n";
				std::cout << " [4] Windows 10 Pro for Workstation         [23] Windows 10 Pro Education \n";
				std::cout << " [5] Windows 10 Pro N for Workstation       [24] Windows 10 Pro Education N \n";
				std::cout << " [6] Windows 10 Home                        [25] Windows 10 S\n";
				std::cout << " [7] Windows 10 Home N                      [26] Windows 10 Сorporative 2021 with long-term service\n";
				std::cout << " [8] Windows 10 Home Country Specific       [27] Windows 10 Сorporative LTSC 2019\n";
				std::cout << " [9] Windows 10 Home Single Language        [28] Windows 10 Сorporative 2015 with long-term service\n";
				std::cout << "\n [10] Windows 10 Enterprise                 [29] Windows 10 Сorporative N LTSC 2021\n";
				std::cout << " [11] Windows 10 Enterprise N               [30] Windows 10 Сorporative N LTSC 2019\n";
				std::cout << " [12] Windows 10 Enterprise S               [31] Windows 10 Сorporative 2015 with long-term service N\n";
				std::cout << " [13] Windows 10 Enterprise G               [32] Windows 10 Сorporative\n";
				std::cout << " [14] Windows 10 Enterprise G N             [33] Windows 10 Сorporative N\n";
				std::cout << " [15] Windows 10 Enterprise 2015 LTSB       [34] Windows 10 Сorporative G\n";
				std::cout << " [16] Windows 10 Enterprise 2015 LTSB N     [35] Windows 10 Сorporative G N\n";
				std::cout << " [17] Windows 10 Enterprise 2016 LTSB       [0] Back\n";
				std::cout << " [18] Windows 10 Enterprise 2016 LTSB N     \n";
				std::cout << " [19] Windows 10 Core Single Language       \n\n";
				std::cout << " [>>] Введи номер пункта: ";
				std::cin >> wd10;
				if (wd10 == "1") {
						system("cls");
						SHELLEXECUTEINFO sei = { sizeof(sei) };
						if (disc.empty()) {
							sei.lpVerb = L"runas";
							sei.lpFile = L"cmd.exe";
							std::wstring parameters = L"/" + dis + L" slmgr /upk & slmgr /ipk W269N-WFGWX-YVC9B-4J6C9-T83GX & slmgr /skms kms.digiboy.ir & slmgr /ato";
							sei.lpParameters = const_cast<wchar_t*>(parameters.c_str());
							if (!ShellExecuteEx(&sei))
							{

								DWORD error = GetLastError();
							}
							system("mode con cols=100 lines=15");
							std::cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk W269N-WFGWX-YVC9B-4J6C9-T83GX\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
							_getch();
							wd10 = "\0";
							system("cls");
							system("mode con cols=162 lines=19");
							break;
						}
						else {
							sei.lpVerb = L"runas";
							sei.lpFile = L"cmd.exe";
							std::wstring parameters = L"/" + disc + L" slmgr /upk & slmgr /ipk W269N-WFGWX-YVC9B-4J6C9-T83GX & slmgr /skms kms.digiboy.ir & slmgr /ato";
							sei.lpParameters = const_cast<wchar_t*>(parameters.c_str());
							if (!ShellExecuteEx(&sei))
							{

								DWORD error = GetLastError();
							}
							system("mode con cols=100 lines=15");
							std::cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk W269N-WFGWX-YVC9B-4J6C9-T83GX\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
							_getch();
							wd10 = "\0";
							system("cls");
							system("mode con cols=162 lines=19");
							break;
						}
				}
				else if (wd10 == "2") {
					system("cls");
					SHELLEXECUTEINFO sei = { sizeof(sei) };
					if (disc.empty()) {
						sei.lpVerb = L"runas";
						sei.lpFile = L"cmd.exe";
						std::wstring parameters = L"/" + dis + L" slmgr /upk & slmgr /ipk MH37W-N47XK-V7XM9-C7227-GCQG9 & slmgr /skms kms.digiboy.ir & slmgr /ato";
						sei.lpParameters = const_cast<wchar_t*>(parameters.c_str());

						if (!ShellExecuteEx(&sei))
						{

							DWORD error = GetLastError();
						}
						std::cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk MH37W-N47XK-V7XM9-C7227-GCQG9\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd10 = "\0";
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
					else {
						sei.lpVerb = L"runas";
						sei.lpFile = L"cmd.exe";
						std::wstring parameters = L"/" + disc + L" slmgr /upk & slmgr /ipk MH37W-N47XK-V7XM9-C7227-GCQG9 & slmgr /skms kms.digiboy.ir & slmgr /ato";
						sei.lpParameters = const_cast<wchar_t*>(parameters.c_str());

						if (!ShellExecuteEx(&sei))
						{

							DWORD error = GetLastError();
						}
						std::cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk MH37W-N47XK-V7XM9-C7227-GCQG9\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd10 = "\0";
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
				}
				else if (wd10 == "3") {
					system("cls");
					SHELLEXECUTEINFO sei = { sizeof(sei) };
					if (disc.empty()) {
						sei.lpVerb = L"runas";
						sei.lpFile = L"cmd.exe";
						std::wstring parameters = L"/" + dis + L" slmgr /upk & slmgr /ipk NPPR9-FWDCX-D2C8J-H872K-2YT43 & slmgr /skms kms.digiboy.ir & slmgr /ato";
						sei.lpParameters = const_cast<wchar_t*>(parameters.c_str());

						if (!ShellExecuteEx(&sei))
						{

							DWORD error = GetLastError();
						}
						std::cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk NPPR9-FWDCX-D2C8J-H872K-2YT43\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd10 = "\0";
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
					else {
						sei.lpVerb = L"runas";
						sei.lpFile = L"cmd.exe";
						std::wstring parameters = L"/" + disc + L" slmgr /upk & slmgr /ipk NPPR9-FWDCX-D2C8J-H872K-2YT43 & slmgr /skms kms.digiboy.ir & slmgr /ato";
						sei.lpParameters = const_cast<wchar_t*>(parameters.c_str());

						if (!ShellExecuteEx(&sei))
						{

							DWORD error = GetLastError();
						}
						std::cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk NPPR9-FWDCX-D2C8J-H872K-2YT43\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd10 = "\0";
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
				}
				else if (wd10 == "4") {
					system("cls");
					SHELLEXECUTEINFO sei = { sizeof(sei) };
					if (disc.empty()) {
						sei.lpVerb = L"runas";
						sei.lpFile = L"cmd.exe";
						std::wstring parameters = L"/" + dis + L" slmgr /upk & slmgr /ipk NRG8B-VKK3Q-CXVCJ-9G2XF-6Q84J & slmgr /skms kms.digiboy.ir & slmgr /ato";
						sei.lpParameters = const_cast<wchar_t*>(parameters.c_str());

						if (!ShellExecuteEx(&sei))
						{

							DWORD error = GetLastError();
						}
						std::cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk NRG8B-VKK3Q-CXVCJ-9G2XF-6Q84J\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd10 = "\0";
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
					else {
						sei.lpVerb = L"runas";
						sei.lpFile = L"cmd.exe";
						std::wstring parameters = L"/" + disc + L" slmgr /upk & slmgr /ipk NRG8B-VKK3Q-CXVCJ-9G2XF-6Q84J & slmgr /skms kms.digiboy.ir & slmgr /ato";
						sei.lpParameters = const_cast<wchar_t*>(parameters.c_str());

						if (!ShellExecuteEx(&sei))
						{

							DWORD error = GetLastError();
						}
						std::cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk NRG8B-VKK3Q-CXVCJ-9G2XF-6Q84J\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd10 = "\0";
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
				}
				else if (wd10 == "5") {
					system("cls");
					SHELLEXECUTEINFO sei = { sizeof(sei) };
					if (disc.empty()) {
						sei.lpVerb = L"runas";
						sei.lpFile = L"cmd.exe";
						std::wstring parameters = L"/" + dis + L" slmgr /upk & slmgr /ipk 9FNHH-K3HBT-3W4TD-6383H-6XYWF & slmgr /skms kms.digiboy.ir & slmgr /ato";
						sei.lpParameters = const_cast<wchar_t*>(parameters.c_str());

						if (!ShellExecuteEx(&sei))
						{

							DWORD error = GetLastError();
						}
						std::cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk 9FNHH-K3HBT-3W4TD-6383H-6XYWF\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd10 = "\0";
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
					else {
						sei.lpVerb = L"runas";
						sei.lpFile = L"cmd.exe";
						std::wstring parameters = L"/" + disc + L" slmgr /upk & slmgr /ipk 9FNHH-K3HBT-3W4TD-6383H-6XYWF & slmgr /skms kms.digiboy.ir & slmgr /ato";
						sei.lpParameters = const_cast<wchar_t*>(parameters.c_str());

						if (!ShellExecuteEx(&sei))
						{

							DWORD error = GetLastError();
						}
						std::cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk 9FNHH-K3HBT-3W4TD-6383H-6XYWF\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd10 = "\0";
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}

				}
				else if (wd10 == "6") {
					system("cls");
					SHELLEXECUTEINFO sei = { sizeof(sei) };
					if (disc.empty()) {
						sei.lpVerb = L"runas";
						sei.lpFile = L"cmd.exe";
						std::wstring parameters = L"/" + dis + L" slmgr /upk & slmgr /ipk TX9XD-98N7V-6WMQ6-BX7FG-H8Q99 & slmgr /skms kms.digiboy.ir & slmgr /ato";
						sei.lpParameters = const_cast<wchar_t*>(parameters.c_str());

						if (!ShellExecuteEx(&sei))
						{

							DWORD error = GetLastError();
						}
						std::cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk TX9XD-98N7V-6WMQ6-BX7FG-H8Q99\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd10 = "\0";
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
					else {
						sei.lpVerb = L"runas";
						sei.lpFile = L"cmd.exe";
						std::wstring parameters = L"/" + disc + L" slmgr /upk & slmgr /ipk TX9XD-98N7V-6WMQ6-BX7FG-H8Q99 & slmgr /skms kms.digiboy.ir & slmgr /ato";
						sei.lpParameters = const_cast<wchar_t*>(parameters.c_str());

						if (!ShellExecuteEx(&sei))
						{

							DWORD error = GetLastError();
						}
						std::cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk TX9XD-98N7V-6WMQ6-BX7FG-H8Q99\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd10 = "\0";
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
				}
				else if (wd10 == "7") {
					system("cls");
					SHELLEXECUTEINFO sei = { sizeof(sei) };
					if (disc.empty()) {
						sei.lpVerb = L"runas";
						sei.lpFile = L"cmd.exe";
						std::wstring parameters = L"/" + dis + L" slmgr /upk & slmgr /ipk 3KHY7-WNT83-DGQKR-F7HPR-844BM & slmgr /skms kms.digiboy.ir & slmgr /ato";
						sei.lpParameters = const_cast<wchar_t*>(parameters.c_str());

						if (!ShellExecuteEx(&sei))
						{

							DWORD error = GetLastError();
						}
						std::cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk 3KHY7-WNT83-DGQKR-F7HPR-844BM\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd10 = "\0";
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
					else {
						sei.lpVerb = L"runas";
						sei.lpFile = L"cmd.exe";
						std::wstring parameters = L"/" + disc + L" slmgr /upk & slmgr /ipk 3KHY7-WNT83-DGQKR-F7HPR-844BM & slmgr /skms kms.digiboy.ir & slmgr /ato";
						sei.lpParameters = const_cast<wchar_t*>(parameters.c_str());

						if (!ShellExecuteEx(&sei))
						{

							DWORD error = GetLastError();
						}
						std::cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk 3KHY7-WNT83-DGQKR-F7HPR-844BM\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd10 = "\0";
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
				}
				else if (wd10 == "8") {
					system("cls");
					SHELLEXECUTEINFO sei = { sizeof(sei) };
					if (disc.empty()) {
						sei.lpVerb = L"runas";
						sei.lpFile = L"cmd.exe";
						std::wstring parameters = L"/" + dis + L" slmgr /upk & slmgr /ipk PVMJN-6DFY6-9CCP6-7BKTT-D3WVR  & slmgr /skms kms.digiboy.ir & slmgr /ato";
						sei.lpParameters = const_cast<wchar_t*>(parameters.c_str());

						if (!ShellExecuteEx(&sei))
						{

							DWORD error = GetLastError();
						}
						std::cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk PVMJN-6DFY6-9CCP6-7BKTT-D3WVR\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd10 = "\0";
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
					else {
						sei.lpVerb = L"runas";
						sei.lpFile = L"cmd.exe";
						std::wstring parameters = L"/" + disc + L" slmgr /upk & slmgr /ipk PVMJN-6DFY6-9CCP6-7BKTT-D3WVR  & slmgr /skms kms.digiboy.ir & slmgr /ato";
						sei.lpParameters = const_cast<wchar_t*>(parameters.c_str());

						if (!ShellExecuteEx(&sei))
						{

							DWORD error = GetLastError();
						}
						std::cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk PVMJN-6DFY6-9CCP6-7BKTT-D3WVR\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd10 = "\0";
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
				}
				else if (wd10 == "9") {
					system("cls");
					SHELLEXECUTEINFO sei = { sizeof(sei) };
					if (disc.empty()) {
						sei.lpVerb = L"runas";
						sei.lpFile = L"cmd.exe";
						std::wstring parameters = L"/" + dis + L" slmgr /upk & slmgr /ipk 7HNRX-D7KGG-3K4RQ-4WPJ4-YTDFH & slmgr /skms kms.digiboy.ir & slmgr /ato";
						sei.lpParameters = const_cast<wchar_t*>(parameters.c_str());

						if (!ShellExecuteEx(&sei))
						{

							DWORD error = GetLastError();
						}
						std::cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk 7HNRX-D7KGG-3K4RQ-4WPJ4-YTDFH\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd10 = "\0";
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
					else {
						sei.lpVerb = L"runas";
						sei.lpFile = L"cmd.exe";
						std::wstring parameters = L"/" + disc + L" slmgr /upk & slmgr /ipk 7HNRX-D7KGG-3K4RQ-4WPJ4-YTDFH & slmgr /skms kms.digiboy.ir & slmgr /ato";
						sei.lpParameters = const_cast<wchar_t*>(parameters.c_str());

						if (!ShellExecuteEx(&sei))
						{

							DWORD error = GetLastError();
						}
						std::cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk 7HNRX-D7KGG-3K4RQ-4WPJ4-YTDFH\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd10 = "\0";
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
				}
				else if (wd10 == "10") {
					system("cls");
					SHELLEXECUTEINFO sei = { sizeof(sei) };
					if (disc.empty()) {
						sei.lpVerb = L"runas";
						sei.lpFile = L"cmd.exe";
						std::wstring parameters = L"/" + dis + L" slmgr /upk & slmgr /ipk NPPR9-FWDCX-D2C8J-H872K-2YT43 & slmgr /skms kms.digiboy.ir & slmgr /ato";
						sei.lpParameters = const_cast<wchar_t*>(parameters.c_str());

						if (!ShellExecuteEx(&sei))
						{

							DWORD error = GetLastError();
						}
						std::cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk NPPR9-FWDCX-D2C8J-H872K-2YT43\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd10 = "\0";
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
					else {
						sei.lpVerb = L"runas";
						sei.lpFile = L"cmd.exe";
						std::wstring parameters = L"/" + disc + L" slmgr /upk & slmgr /ipk NPPR9-FWDCX-D2C8J-H872K-2YT43 & slmgr /skms kms.digiboy.ir & slmgr /ato";
						sei.lpParameters = const_cast<wchar_t*>(parameters.c_str());

						if (!ShellExecuteEx(&sei))
						{

							DWORD error = GetLastError();
						}
						std::cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk NPPR9-FWDCX-D2C8J-H872K-2YT43\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd10 = "\0";
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
				}
				else if (wd10 == "11") {
					system("cls");
					SHELLEXECUTEINFO sei = { sizeof(sei) };
					if (disc.empty()) {
						sei.lpVerb = L"runas";
						sei.lpFile = L"cmd.exe";
						std::wstring parameters = L"/" + dis + L" slmgr /upk & slmgr /ipk DPH2V-TTNVB-4X9Q3-TJR4H-KHJW4 & slmgr /skms kms.digiboy.ir & slmgr /ato";
						sei.lpParameters = const_cast<wchar_t*>(parameters.c_str());

						if (!ShellExecuteEx(&sei))
						{

							DWORD error = GetLastError();
						}
						std::cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk DPH2V-TTNVB-4X9Q3-TJR4H-KHJW4\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd10 = "\0";
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
					else {
						sei.lpVerb = L"runas";
						sei.lpFile = L"cmd.exe";
						std::wstring parameters = L"/" + disc + L" slmgr /upk & slmgr /ipk DPH2V-TTNVB-4X9Q3-TJR4H-KHJW4 & slmgr /skms kms.digiboy.ir & slmgr /ato";
						sei.lpParameters = const_cast<wchar_t*>(parameters.c_str());

						if (!ShellExecuteEx(&sei))
						{

							DWORD error = GetLastError();
						}
						std::cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk DPH2V-TTNVB-4X9Q3-TJR4H-KHJW4\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd10 = "\0";
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
				}
				else if (wd10 == "12") {
					system("cls");
					SHELLEXECUTEINFO sei = { sizeof(sei) };
					if (disc.empty()) {
						sei.lpVerb = L"runas";
						sei.lpFile = L"cmd.exe";
						std::wstring parameters = L"/" + dis + L" slmgr /upk & slmgr /ipk FWN7H-PF93Q-4GGP8-M8RF3-MDWWW & slmgr /skms kms.digiboy.ir & slmgr /ato";
						sei.lpParameters = const_cast<wchar_t*>(parameters.c_str());

						if (!ShellExecuteEx(&sei))
						{

							DWORD error = GetLastError();
						}
						std::cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk FWN7H-PF93Q-4GGP8-M8RF3-MDWWW\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd10 = "\0";
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
					else {
						sei.lpVerb = L"runas";
						sei.lpFile = L"cmd.exe";
						std::wstring parameters = L"/" + disc + L" slmgr /upk & slmgr /ipk FWN7H-PF93Q-4GGP8-M8RF3-MDWWW & slmgr /skms kms.digiboy.ir & slmgr /ato";
						sei.lpParameters = const_cast<wchar_t*>(parameters.c_str());

						if (!ShellExecuteEx(&sei))
						{

							DWORD error = GetLastError();
						}
						std::cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk FWN7H-PF93Q-4GGP8-M8RF3-MDWWW\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd10 = "\0";
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
				}
				else if (wd10 == "13") {
					system("cls");
					SHELLEXECUTEINFO sei = { sizeof(sei) };
					if (disc.empty()) {
						sei.lpVerb = L"runas";
						sei.lpFile = L"cmd.exe";
						std::wstring parameters = L"/" + dis + L" slmgr /upk & slmgr /ipk YYVX9-NTFWV-6MDM3-9PT4T-4M68B & slmgr /skms kms.digiboy.ir & slmgr /ato";
						sei.lpParameters = const_cast<wchar_t*>(parameters.c_str());

						if (!ShellExecuteEx(&sei))
						{

							DWORD error = GetLastError();
						}
						std::cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk YYVX9-NTFWV-6MDM3-9PT4T-4M68B\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd10 = "\0";
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
					else {
						sei.lpVerb = L"runas";
						sei.lpFile = L"cmd.exe";
						std::wstring parameters = L"/" + disc + L" slmgr /upk & slmgr /ipk YYVX9-NTFWV-6MDM3-9PT4T-4M68B & slmgr /skms kms.digiboy.ir & slmgr /ato";
						sei.lpParameters = const_cast<wchar_t*>(parameters.c_str());

						if (!ShellExecuteEx(&sei))
						{

							DWORD error = GetLastError();
						}
						std::cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk YYVX9-NTFWV-6MDM3-9PT4T-4M68B\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd10 = "\0";
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
				}
				else if (wd10 == "14") {
					system("cls");
					SHELLEXECUTEINFO sei = { sizeof(sei) };
					if (disc.empty()) {
						sei.lpVerb = L"runas";
						sei.lpFile = L"cmd.exe";
						std::wstring parameters = L"/" + dis + L" slmgr /upk & slmgr /ipk 44RPN-FTY23-9VTTB-MP9BX-T84FV & slmgr /skms kms.digiboy.ir & slmgr /ato";
						sei.lpParameters = const_cast<wchar_t*>(parameters.c_str());

						if (!ShellExecuteEx(&sei))
						{

							DWORD error = GetLastError();
						}
						std::cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk 44RPN-FTY23-9VTTB-MP9BX-T84FV\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd10 = "\0";
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
					else {
						sei.lpVerb = L"runas";
						sei.lpFile = L"cmd.exe";
						std::wstring parameters = L"/" + disc + L" slmgr /upk & slmgr /ipk 44RPN-FTY23-9VTTB-MP9BX-T84FV & slmgr /skms kms.digiboy.ir & slmgr /ato";
						sei.lpParameters = const_cast<wchar_t*>(parameters.c_str());

						std::cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk 44RPN-FTY23-9VTTB-MP9BX-T84FV\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd10 = "\0";
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
				}
				else if (wd10 == "15") {
					system("cls");
					SHELLEXECUTEINFO sei = { sizeof(sei) };
					if (disc.empty()) {
						sei.lpVerb = L"runas";
						sei.lpFile = L"cmd.exe";
						std::wstring parameters = L"/" + dis + L" slmgr /upk & slmgr /ipk WNMTR-4C88C-JK8YV-HQ7T2-76DF9 & slmgr /skms kms.digiboy.ir & slmgr /ato";
						sei.lpParameters = const_cast<wchar_t*>(parameters.c_str());

						if (!ShellExecuteEx(&sei))
						{

							DWORD error = GetLastError();
						}
						std::cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk WNMTR-4C88C-JK8YV-HQ7T2-76DF9\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd10 = "\0";
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
					else {
						sei.lpVerb = L"runas";
						sei.lpFile = L"cmd.exe";
						std::wstring parameters = L"/" + disc + L" slmgr /upk & slmgr /ipk WNMTR-4C88C-JK8YV-HQ7T2-76DF9 & slmgr /skms kms.digiboy.ir & slmgr /ato";
						sei.lpParameters = const_cast<wchar_t*>(parameters.c_str());

						if (!ShellExecuteEx(&sei))
						{

							DWORD error = GetLastError();
						}
						std::cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk WNMTR-4C88C-JK8YV-HQ7T2-76DF9\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd10 = "\0";
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
				}
				else if (wd10 == "16") {
					system("cls");
					SHELLEXECUTEINFO sei = { sizeof(sei) };
					if (disc.empty()) {
						sei.lpVerb = L"runas";
						sei.lpFile = L"cmd.exe";
						std::wstring parameters = L"/" + dis + L" slmgr /upk & slmgr /ipk 2F77B-TNFGY-69QQF-B8YKP-D69TJ & slmgr /skms kms.digiboy.ir & slmgr /ato";
						sei.lpParameters = const_cast<wchar_t*>(parameters.c_str());

						if (!ShellExecuteEx(&sei))
						{

							DWORD error = GetLastError();
						}
						std::cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk 2F77B-TNFGY-69QQF-B8YKP-D69TJ\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd10 = "\0";
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
					else {
						sei.lpVerb = L"runas";
						sei.lpFile = L"cmd.exe";
						std::wstring parameters = L"/" + disc + L" slmgr /upk & slmgr /ipk 2F77B-TNFGY-69QQF-B8YKP-D69TJ & slmgr /skms kms.digiboy.ir & slmgr /ato";
						sei.lpParameters = const_cast<wchar_t*>(parameters.c_str());

						if (!ShellExecuteEx(&sei))
						{

							DWORD error = GetLastError();
						}
						std::cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk 2F77B-TNFGY-69QQF-B8YKP-D69TJ\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd10 = "\0";
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
				}
				else if (wd10 == "17") {
					system("cls");
					SHELLEXECUTEINFO sei = { sizeof(sei) };
					if (disc.empty()) {
						sei.lpVerb = L"runas";
						sei.lpFile = L"cmd.exe";
						std::wstring parameters = L"/" + dis + L" slmgr /upk & slmgr /ipk DCPHK-NFMTC-H88MJ-PFHPY-QJ4BJ & slmgr /skms kms.digiboy.ir & slmgr /ato";
						sei.lpParameters = const_cast<wchar_t*>(parameters.c_str());

						if (!ShellExecuteEx(&sei))
						{

							DWORD error = GetLastError();
						}
						std::cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk DCPHK-NFMTC-H88MJ-PFHPY-QJ4BJ\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd10 = "\0";
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
					else {
						sei.lpVerb = L"runas";
						sei.lpFile = L"cmd.exe";
						std::wstring parameters = L"/" + disc + L" slmgr /upk & slmgr /ipk DCPHK-NFMTC-H88MJ-PFHPY-QJ4BJ & slmgr /skms kms.digiboy.ir & slmgr /ato";
						sei.lpParameters = const_cast<wchar_t*>(parameters.c_str());

						if (!ShellExecuteEx(&sei))
						{

							DWORD error = GetLastError();
						}
						std::cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk DCPHK-NFMTC-H88MJ-PFHPY-QJ4BJ\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd10 = "\0";
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
				}
				else if (wd10 == "18") {
					system("cls");
					SHELLEXECUTEINFO sei = { sizeof(sei) };
					if (disc.empty()) {
						sei.lpVerb = L"runas";
						sei.lpFile = L"cmd.exe";
						std::wstring parameters = L"/" + dis + L" slmgr /upk & slmgr /ipk QFFDN-GRT3P-VKWWX-X7T3R-8B639 & slmgr /skms kms.digiboy.ir & slmgr /ato";
						sei.lpParameters = const_cast<wchar_t*>(parameters.c_str());

						if (!ShellExecuteEx(&sei))
						{

							DWORD error = GetLastError();
						}
						std::cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk QFFDN-GRT3P-VKWWX-X7T3R-8B639\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd10 = "\0";
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
					else {
						sei.lpVerb = L"runas";
						sei.lpFile = L"cmd.exe";
						std::wstring parameters = L"/" + disc + L" slmgr /upk & slmgr /ipk QFFDN-GRT3P-VKWWX-X7T3R-8B639 & slmgr /skms kms.digiboy.ir & slmgr /ato";
						sei.lpParameters = const_cast<wchar_t*>(parameters.c_str());

						if (!ShellExecuteEx(&sei))
						{

							DWORD error = GetLastError();
						}
						std::cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk QFFDN-GRT3P-VKWWX-X7T3R-8B639\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd10 = "\0";
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
				}
				else if (wd10 == "19") {
					system("cls");
					SHELLEXECUTEINFO sei = { sizeof(sei) };
					if (disc.empty()) {
						sei.lpVerb = L"runas";
						sei.lpFile = L"cmd.exe";
						std::wstring parameters = L"/" + dis + L" slmgr /upk & slmgr /ipk BT79Q-G7N6G-PGBYW-4YWX6-6F4BT & slmgr /skms kms.digiboy.ir & slmgr /ato";
						sei.lpParameters = const_cast<wchar_t*>(parameters.c_str());

						if (!ShellExecuteEx(&sei))
						{

							DWORD error = GetLastError();
						}
						std::cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk BT79Q-G7N6G-PGBYW-4YWX6-6F4BT\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd10 = "\0";
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
					else {
						sei.lpVerb = L"runas";
						sei.lpFile = L"cmd.exe";
						std::wstring parameters = L"/" + disc + L" slmgr /upk & slmgr /ipk BT79Q-G7N6G-PGBYW-4YWX6-6F4BT & slmgr /skms kms.digiboy.ir & slmgr /ato";
						sei.lpParameters = const_cast<wchar_t*>(parameters.c_str());

						if (!ShellExecuteEx(&sei))
						{

							DWORD error = GetLastError();
						}
						std::cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk BT79Q-G7N6G-PGBYW-4YWX6-6F4BT\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd10 = "\0";
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
				}
				else if (wd10 == "20") {
					system("cls");
					SHELLEXECUTEINFO sei = { sizeof(sei) };
					if (disc.empty()) {
						sei.lpVerb = L"runas";
						sei.lpFile = L"cmd.exe";
						std::wstring parameters = L"/" + dis + L" slmgr /upk & slmgr /ipk N2434-X9D7W-8PF6X-8DV9T-8TYMD & slmgr /skms kms.digiboy.ir & slmgr /ato";
						sei.lpParameters = const_cast<wchar_t*>(parameters.c_str());

						if (!ShellExecuteEx(&sei))
						{

							DWORD error = GetLastError();
						}
						std::cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk N2434-X9D7W-8PF6X-8DV9T-8TYMD\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd10 = "\0";
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
					else {
						sei.lpVerb = L"runas";
						sei.lpFile = L"cmd.exe";
						std::wstring parameters = L"/" + disc + L" slmgr /upk & slmgr /ipk N2434-X9D7W-8PF6X-8DV9T-8TYMD & slmgr /skms kms.digiboy.ir & slmgr /ato";
						sei.lpParameters = const_cast<wchar_t*>(parameters.c_str());

						if (!ShellExecuteEx(&sei))
						{

							DWORD error = GetLastError();
						}
						std::cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk N2434-X9D7W-8PF6X-8DV9T-8TYMD\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd10 = "\0";
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
				}
				else if (wd10 == "21") {
					system("cls");
					SHELLEXECUTEINFO sei = { sizeof(sei) };
					if (disc.empty()) {
						sei.lpVerb = L"runas";
						sei.lpFile = L"cmd.exe";
						std::wstring parameters = L"/" + dis + L" slmgr /upk & slmgr /ipk YNMGQ-8RYV3-4PGQ3-C8XTP-7CFBY & slmgr /skms kms.digiboy.ir & slmgr /ato";
						sei.lpParameters = const_cast<wchar_t*>(parameters.c_str());

						if (!ShellExecuteEx(&sei))
						{

							DWORD error = GetLastError();
						}
						std::cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk YNMGQ-8RYV3-4PGQ3-C8XTP-7CFBY\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd10 = "\0";
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
					else {
						sei.lpVerb = L"runas";
						sei.lpFile = L"cmd.exe";
						std::wstring parameters = L"/" + disc + L" slmgr /upk & slmgr /ipk YNMGQ-8RYV3-4PGQ3-C8XTP-7CFBY & slmgr /skms kms.digiboy.ir & slmgr /ato";
						sei.lpParameters = const_cast<wchar_t*>(parameters.c_str());

						if (!ShellExecuteEx(&sei))
						{

							DWORD error = GetLastError();
						}
						std::cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk YNMGQ-8RYV3-4PGQ3-C8XTP-7CFBY\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd10 = "\0";
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
				}
				else if (wd10 == "22") {
					system("cls");
					SHELLEXECUTEINFO sei = { sizeof(sei) };
					if (disc.empty()) {
						sei.lpVerb = L"runas";
						sei.lpFile = L"cmd.exe";
						std::wstring parameters = L"/" + dis + L" slmgr /upk & slmgr /ipk 84NGF-MHBT6-FXBX8-QWJK7-DRR8H & slmgr /skms kms.digiboy.ir & slmgr /ato";
						sei.lpParameters = const_cast<wchar_t*>(parameters.c_str());

						if (!ShellExecuteEx(&sei))
						{

							DWORD error = GetLastError();
						}
						std::cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk 84NGF-MHBT6-FXBX8-QWJK7-DRR8H\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd10 = "\0";
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
					else {
						sei.lpVerb = L"runas";
						sei.lpFile = L"cmd.exe";
						std::wstring parameters = L"/" + disc + L" slmgr /upk & slmgr /ipk 84NGF-MHBT6-FXBX8-QWJK7-DRR8H & slmgr /skms kms.digiboy.ir & slmgr /ato";
						sei.lpParameters = const_cast<wchar_t*>(parameters.c_str());

						if (!ShellExecuteEx(&sei))
						{

							DWORD error = GetLastError();
						}
						std::cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk 84NGF-MHBT6-FXBX8-QWJK7-DRR8H\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd10 = "\0";
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
				}
				else if (wd10 == "23") {
					system("cls");
					SHELLEXECUTEINFO sei = { sizeof(sei) };
					if (disc.empty()) {
						sei.lpVerb = L"runas";
						sei.lpFile = L"cmd.exe";
						std::wstring parameters = L"/" + dis + L" slmgr /upk & slmgr /ipk 8PTT6-RNW4C-6V7J2-C2D3X-MHBPB & slmgr /skms kms.digiboy.ir & slmgr /ato";
						sei.lpParameters = const_cast<wchar_t*>(parameters.c_str());

						if (!ShellExecuteEx(&sei))
						{

							DWORD error = GetLastError();
						}
						std::cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk 8PTT6-RNW4C-6V7J2-C2D3X-MHBPB\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd10 = "\0";
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
					else {
						sei.lpVerb = L"runas";
						sei.lpFile = L"cmd.exe";
						std::wstring parameters = L"/" + disc + L" slmgr /upk & slmgr /ipk 8PTT6-RNW4C-6V7J2-C2D3X-MHBPB & slmgr /skms kms.digiboy.ir & slmgr /ato";
						sei.lpParameters = const_cast<wchar_t*>(parameters.c_str());

						if (!ShellExecuteEx(&sei))
						{

							DWORD error = GetLastError();
						}
						std::cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk 8PTT6-RNW4C-6V7J2-C2D3X-MHBPB\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd10 = "\0";
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
				}
				else if (wd10 == "24") {
					system("cls");
					SHELLEXECUTEINFO sei = { sizeof(sei) };
					if (disc.empty()) {
						sei.lpVerb = L"runas";
						sei.lpFile = L"cmd.exe";
						std::wstring parameters = L"/" + dis + L" slmgr /upk & slmgr /ipk GJTYN-HDMQY-FRR76-HVGC7-QPF8P & slmgr /skms kms.digiboy.ir & slmgr /ato";
						sei.lpParameters = const_cast<wchar_t*>(parameters.c_str());

						if (!ShellExecuteEx(&sei))
						{

							DWORD error = GetLastError();
						}
						std::cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk GJTYN-HDMQY-FRR76-HVGC7-QPF8P\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						system("cls");
						wd10 = "\0";
						system("mode con cols=162 lines=19");
						break;
					}
					else {
						sei.lpVerb = L"runas";
						sei.lpFile = L"cmd.exe";
						std::wstring parameters = L"/" + disc + L" slmgr /upk & slmgr /ipk GJTYN-HDMQY-FRR76-HVGC7-QPF8P & slmgr /skms kms.digiboy.ir & slmgr /ato";
						sei.lpParameters = const_cast<wchar_t*>(parameters.c_str());

						if (!ShellExecuteEx(&sei))
						{

							DWORD error = GetLastError();
						}
						std::cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk GJTYN-HDMQY-FRR76-HVGC7-QPF8P\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						system("cls");
						wd10 = "\0";
						system("mode con cols=162 lines=19");
						break;
					}
				}
				else if (wd10 == "25") {
					system("cls");
					SHELLEXECUTEINFO sei = { sizeof(sei) };
					if (disc.empty()) {
						sei.lpVerb = L"runas";
						sei.lpFile = L"cmd.exe";
						std::wstring parameters = L"/" + dis + L" slmgr /upk & slmgr /ipk 3NF4D-GF9GY-63VKH-QRC3V-7QW8P & slmgr /skms kms.digiboy.ir & slmgr /ato";
						sei.lpParameters = const_cast<wchar_t*>(parameters.c_str());

						if (!ShellExecuteEx(&sei))
						{

							DWORD error = GetLastError();
						}
						std::cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk 3NF4D-GF9GY-63VKH-QRC3V-7QW8P\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						system("cls");
						wd10 = "\0";
						system("mode con cols=162 lines=19");
						break;
					}
					else {
						sei.lpVerb = L"runas";
						sei.lpFile = L"cmd.exe";
						std::wstring parameters = L"/" + disc + L" slmgr /upk & slmgr /ipk 3NF4D-GF9GY-63VKH-QRC3V-7QW8P & slmgr /skms kms.digiboy.ir & slmgr /ato";
						sei.lpParameters = const_cast<wchar_t*>(parameters.c_str());

						if (!ShellExecuteEx(&sei))
						{

							DWORD error = GetLastError();
						}
						std::cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk 3NF4D-GF9GY-63VKH-QRC3V-7QW8P\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						system("cls");
						wd10 = "\0";
						system("mode con cols=162 lines=19");
						break;
					}
				}
				else if (wd10 == "26") {
					system("cls");
					SHELLEXECUTEINFO sei = { sizeof(sei) };
					if (disc.empty()) {
						sei.lpVerb = L"runas";
						sei.lpFile = L"cmd.exe";
						std::wstring parameters = L"/" + dis + L" slmgr /upk & slmgr /ipk M7XTQ-FN8P6-TTKYV-9D4CC-J462D & slmgr /skms kms.digiboy.ir & slmgr /ato";
						sei.lpParameters = const_cast<wchar_t*>(parameters.c_str());

						if (!ShellExecuteEx(&sei))
						{

							DWORD error = GetLastError();
						}
						std::cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk M7XTQ-FN8P6-TTKYV-9D4CC-J462D\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						system("cls");
						wd10 = "\0";
						system("mode con cols=162 lines=19");
						break;
					}
					else {
						sei.lpVerb = L"runas";
						sei.lpFile = L"cmd.exe";
						std::wstring parameters = L"/" + disc + L" slmgr /upk & slmgr /ipk M7XTQ-FN8P6-TTKYV-9D4CC-J462D & slmgr /skms kms.digiboy.ir & slmgr /ato";
						sei.lpParameters = const_cast<wchar_t*>(parameters.c_str());

						if (!ShellExecuteEx(&sei))
						{

							DWORD error = GetLastError();
						}
						std::cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk M7XTQ-FN8P6-TTKYV-9D4CC-J462D\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						system("cls");
						wd10 = "\0";
						system("mode con cols=162 lines=19");
						break;
					}
				}
				else if (wd10 == "27") {
					system("cls");
					SHELLEXECUTEINFO sei = { sizeof(sei) };
					if (disc.empty()) {
						sei.lpVerb = L"runas";
						sei.lpFile = L"cmd.exe";
						std::wstring parameters = L"/" + dis + L" slmgr /upk & slmgr /ipk M7XTQ-FN8P6-TTKYV-9D4CC-J462D & slmgr /skms kms.digiboy.ir & slmgr /ato";
						sei.lpParameters = const_cast<wchar_t*>(parameters.c_str());

						if (!ShellExecuteEx(&sei))
						{

							DWORD error = GetLastError();
						}
						std::cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk M7XTQ-FN8P6-TTKYV-9D4CC-J462D\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						system("cls");
						wd10 = "\0";
						system("mode con cols=162 lines=19");
						break;
					}
					else {
						sei.lpVerb = L"runas";
						sei.lpFile = L"cmd.exe";
						std::wstring parameters = L"/" + disc + L" slmgr /upk & slmgr /ipk M7XTQ-FN8P6-TTKYV-9D4CC-J462D & slmgr /skms kms.digiboy.ir & slmgr /ato";
						sei.lpParameters = const_cast<wchar_t*>(parameters.c_str());

						if (!ShellExecuteEx(&sei))
						{

							DWORD error = GetLastError();
						}
						std::cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk M7XTQ-FN8P6-TTKYV-9D4CC-J462D\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						system("cls");
						wd10 = "\0";
						system("mode con cols=162 lines=19");
						break;
					}
				}
				else if (wd10 == "28") {
					system("cls");
					SHELLEXECUTEINFO sei = { sizeof(sei) };
					if (disc.empty()) {
						sei.lpVerb = L"runas";
						sei.lpFile = L"cmd.exe";
						std::wstring parameters = L"/" + dis + L" slmgr /upk & slmgr /ipk WNMTR-4C88C-JK8YV-HQ7T2-76DF9 & slmgr /skms kms.digiboy.ir & slmgr /ato";
						sei.lpParameters = const_cast<wchar_t*>(parameters.c_str());

						if (!ShellExecuteEx(&sei))
						{

							DWORD error = GetLastError();
						}
						std::cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk WNMTR-4C88C-JK8YV-HQ7T2-76DF9\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						system("cls");
						wd10 = "\0";
						system("mode con cols=162 lines=19");
						break;
					}
					else {
						sei.lpVerb = L"runas";
						sei.lpFile = L"cmd.exe";
						std::wstring parameters = L"/" + disc + L" slmgr /upk & slmgr /ipk WNMTR-4C88C-JK8YV-HQ7T2-76DF9 & slmgr /skms kms.digiboy.ir & slmgr /ato";
						sei.lpParameters = const_cast<wchar_t*>(parameters.c_str());

						if (!ShellExecuteEx(&sei))
						{

							DWORD error = GetLastError();
						}
						std::cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk WNMTR-4C88C-JK8YV-HQ7T2-76DF9\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						system("cls");
						wd10 = "\0";
						system("mode con cols=162 lines=19");
						break;
					}
				}
				else if (wd10 == "29") {
					system("cls");
					SHELLEXECUTEINFO sei = { sizeof(sei) };
					if (disc.empty()) {
						sei.lpVerb = L"runas";
						sei.lpFile = L"cmd.exe";
						std::wstring parameters = L"/" + dis + L" slmgr /upk & slmgr /ipk 92NFX-8DJQP-P6BBQ-THF9C-7CG2H & slmgr /skms kms.digiboy.ir & slmgr /ato";
						sei.lpParameters = const_cast<wchar_t*>(parameters.c_str());

						if (!ShellExecuteEx(&sei))
						{

							DWORD error = GetLastError();
						}
						std::cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk 92NFX-8DJQP-P6BBQ-THF9C-7CG2H\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd10 = "\0";
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
					else {
						sei.lpVerb = L"runas";
						sei.lpFile = L"cmd.exe";
						std::wstring parameters = L"/" + disc + L" slmgr /upk & slmgr /ipk 92NFX-8DJQP-P6BBQ-THF9C-7CG2H & slmgr /skms kms.digiboy.ir & slmgr /ato";
						sei.lpParameters = const_cast<wchar_t*>(parameters.c_str());

						if (!ShellExecuteEx(&sei))
						{

							DWORD error = GetLastError();
						}
						std::cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk 92NFX-8DJQP-P6BBQ-THF9C-7CG2H\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd10 = "\0";
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
				}
				else if (wd10 == "30") {
					system("cls");
					SHELLEXECUTEINFO sei = { sizeof(sei) };
					if (disc.empty()) {
						sei.lpVerb = L"runas";
						sei.lpFile = L"cmd.exe";
						std::wstring parameters = L"/" + dis + L" slmgr /upk & slmgr /ipk 92NFX-8DJQP-P6BBQ-THF9C-7CG2H & slmgr /skms kms.digiboy.ir & slmgr /ato";
						sei.lpParameters = const_cast<wchar_t*>(parameters.c_str());

						if (!ShellExecuteEx(&sei))
						{

							DWORD error = GetLastError();
						}
						std::cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk 92NFX-8DJQP-P6BBQ-THF9C-7CG2H\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd10 = "\0";
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
					else {
						sei.lpVerb = L"runas";
						sei.lpFile = L"cmd.exe";
						std::wstring parameters = L"/" + disc + L" slmgr /upk & slmgr /ipk 92NFX-8DJQP-P6BBQ-THF9C-7CG2H & slmgr /skms kms.digiboy.ir & slmgr /ato";
						sei.lpParameters = const_cast<wchar_t*>(parameters.c_str());

						if (!ShellExecuteEx(&sei))
						{

							DWORD error = GetLastError();
						}
						std::cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk 92NFX-8DJQP-P6BBQ-THF9C-7CG2H\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd10 = "\0";
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
				}
				else if (wd10 == "31") {
					system("cls");
					SHELLEXECUTEINFO sei = { sizeof(sei) };
					if (disc.empty()) {
						sei.lpVerb = L"runas";
						sei.lpFile = L"cmd.exe";
						std::wstring parameters = L"/" + dis + L" slmgr /upk & slmgr /ipk 2F77B-TNFGY-69QQF-B8YKP-D69TJ & slmgr /skms kms.digiboy.ir & slmgr /ato";
						sei.lpParameters = const_cast<wchar_t*>(parameters.c_str());

						if (!ShellExecuteEx(&sei))
						{

							DWORD error = GetLastError();
						}
						std::cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk 2F77B-TNFGY-69QQF-B8YKP-D69TJ\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd10 = "\0";
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
					else {
						sei.lpVerb = L"runas";
						sei.lpFile = L"cmd.exe";
						std::wstring parameters = L"/" + disc + L" slmgr /upk & slmgr /ipk 2F77B-TNFGY-69QQF-B8YKP-D69TJ & slmgr /skms kms.digiboy.ir & slmgr /ato";
						sei.lpParameters = const_cast<wchar_t*>(parameters.c_str());

						if (!ShellExecuteEx(&sei))
						{

							DWORD error = GetLastError();
						}
						std::cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk 2F77B-TNFGY-69QQF-B8YKP-D69TJ\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd10 = "\0";
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
				}
				else if (wd10 == "32") {
					system("cls");
					SHELLEXECUTEINFO sei = { sizeof(sei) };
					if (disc.empty()) {
						sei.lpVerb = L"runas";
						sei.lpFile = L"cmd.exe";
						std::wstring parameters = L"/" + dis + L" slmgr /upk & slmgr /ipk NPPR9-FWDCX-D2C8J-H872K-2YT43 & slmgr /skms kms.digiboy.ir & slmgr /ato";
						sei.lpParameters = const_cast<wchar_t*>(parameters.c_str());

						if (!ShellExecuteEx(&sei))
						{

							DWORD error = GetLastError();
						}
						std::cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk NPPR9-FWDCX-D2C8J-H872K-2YT43\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd10 = "\0";
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
					else {
						sei.lpVerb = L"runas";
						sei.lpFile = L"cmd.exe";
						std::wstring parameters = L"/" + disc + L" slmgr /upk & slmgr /ipk NPPR9-FWDCX-D2C8J-H872K-2YT43 & slmgr /skms kms.digiboy.ir & slmgr /ato";
						sei.lpParameters = const_cast<wchar_t*>(parameters.c_str());

						if (!ShellExecuteEx(&sei))
						{

							DWORD error = GetLastError();
						}
						std::cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk NPPR9-FWDCX-D2C8J-H872K-2YT43\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd10 = "\0";
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
				}
				else if (wd10 == "33") {
					system("cls");
					SHELLEXECUTEINFO sei = { sizeof(sei) };
					if (disc.empty()) {
						sei.lpVerb = L"runas";
						sei.lpFile = L"cmd.exe";
						std::wstring parameters = L"/" + dis + L" slmgr /upk & slmgr /ipk DPH2V-TTNVB-4X9Q3-TJR4H-KHJW4 & slmgr /skms kms.digiboy.ir & slmgr /ato";
						sei.lpParameters = const_cast<wchar_t*>(parameters.c_str());

						if (!ShellExecuteEx(&sei))
						{

							DWORD error = GetLastError();
						}
						std::cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk DPH2V-TTNVB-4X9Q3-TJR4H-KHJW4\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd10 = "\0";
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
					else {
						sei.lpVerb = L"runas";
						sei.lpFile = L"cmd.exe";
						std::wstring parameters = L"/" + disc + L" slmgr /upk & slmgr /ipk DPH2V-TTNVB-4X9Q3-TJR4H-KHJW4 & slmgr /skms kms.digiboy.ir & slmgr /ato";
						sei.lpParameters = const_cast<wchar_t*>(parameters.c_str());

						if (!ShellExecuteEx(&sei))
						{

							DWORD error = GetLastError();
						}
						std::cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk DPH2V-TTNVB-4X9Q3-TJR4H-KHJW4\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd10 = "\0";
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
				}
				else if (wd10 == "34") {
					system("cls");
					SHELLEXECUTEINFO sei = { sizeof(sei) };
					if (disc.empty()) {
						sei.lpVerb = L"runas";
						sei.lpFile = L"cmd.exe";
						std::wstring parameters = L"/" + dis + L" slmgr /upk & slmgr /ipk YYVX9-NTFWV-6MDM3-9PT4T-4M68B & slmgr /skms kms.digiboy.ir & slmgr /ato";
						sei.lpParameters = const_cast<wchar_t*>(parameters.c_str());

						if (!ShellExecuteEx(&sei))
						{

							DWORD error = GetLastError();
						}
						std::cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk YYVX9-NTFWV-6MDM3-9PT4T-4M68B\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd10 = "\0";
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
					else {
						sei.lpVerb = L"runas";
						sei.lpFile = L"cmd.exe";
						std::wstring parameters = L"/" + disc + L" slmgr /upk & slmgr /ipk YYVX9-NTFWV-6MDM3-9PT4T-4M68B & slmgr /skms kms.digiboy.ir & slmgr /ato";
						sei.lpParameters = const_cast<wchar_t*>(parameters.c_str());

						if (!ShellExecuteEx(&sei))
						{

							DWORD error = GetLastError();
						}
						std::cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk YYVX9-NTFWV-6MDM3-9PT4T-4M68B\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd10 = "\0";
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
				}
				else if (wd10 == "35") {
					system("cls");
					SHELLEXECUTEINFO sei = { sizeof(sei) };
					if (disc.empty()) {
						sei.lpVerb = L"runas";
						sei.lpFile = L"cmd.exe";
						std::wstring parameters = L"/" + dis + L" slmgr /upk & slmgr /ipk 44RPN-FTY23-9VTTB-MP9BX-T84FV & slmgr /skms kms.digiboy.ir & slmgr /ato";
						sei.lpParameters = const_cast<wchar_t*>(parameters.c_str());

						if (!ShellExecuteEx(&sei))
						{

							DWORD error = GetLastError();
						}
						std::cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk 44RPN-FTY23-9VTTB-MP9BX-T84FV\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd10 = "\0";
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
					else {
						sei.lpVerb = L"runas";
						sei.lpFile = L"cmd.exe";
						std::wstring parameters = L"/" + disc + L" slmgr /upk & slmgr /ipk 44RPN-FTY23-9VTTB-MP9BX-T84FV & slmgr /skms kms.digiboy.ir & slmgr /ato";
						sei.lpParameters = const_cast<wchar_t*>(parameters.c_str());

						if (!ShellExecuteEx(&sei))
						{

							DWORD error = GetLastError();
						}
						std::cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk 44RPN-FTY23-9VTTB-MP9BX-T84FV\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd10 = "\0";
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
				}
				else {
					wd10 = "\0";
					system("cls");
					system("mode con cols=162 lines=19");
					break;
				}
				
			case 2:
				SetConsoleTitle(L"Windows 11");
				system("cls");
				system("mode con cols=110 lines=24");
				SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);
				std::cout << "\n [1] Windows 11 Pro                          [19] Windows 11 Enterprise G\n";
				std::cout << " [2] Windows 11 Pro N                        [20] Windows 11 Enterprise G N\n";
				std::cout << " [3] Windows 11 Pro Workstation              [21] Windows 11 Enterprise LTSC 2019\n";
				std::cout << " [4] Windows 11 Pro Workstation N            [22] Windows 11 Enterprise N LTSC 2019\n";
				std::cout << " [5] Windows 11 Pro Education                [0] Back\n";
				std::cout << " [6] Windows 11 Pro Education N              \n";
				std::cout << " [7] Windows 11 Education                    \n";
				std::cout << " [8] Windows 11 Education N                  \n";
				std::cout << " [9] Windows 11 Сorporative                  \n";
				std::cout << "\n [10] Windows 11 Сorporative N               \n";
				std::cout << " [11] Windows 11 Сorporative G               \n";
				std::cout << " [12] Windows 11 Сorporative G N             \n";
				std::cout << " [13] Windows 11 Home                        \n";
				std::cout << " [14] Windows 11 Home N                      \n";
				std::cout << " [15] Windows 11 Home Home Single Language   \n";
				std::cout << " [16] Windows 11 Home Country Specific       \n";
				std::cout << " [17] Windows 11 Enterprise\n";
				std::cout << " [18] Windows 11 Enterprise N\n\n";
				std::cout << " [>>] Введи номер пункта: ";
				std::cin >> wd11;
				if (wd11 == "1") {
					system("cls");
					SHELLEXECUTEINFO sei = { sizeof(sei) };
					if (disc.empty()) {
						sei.lpVerb = L"runas";
						sei.lpFile = L"cmd.exe";
						std::wstring parameters = L"/" + dis + L" slmgr /upk & slmgr /ipk W269N-WFGWX-YVC9B-4J6C9-T83GX & slmgr /skms kms.digiboy.ir & slmgr /ato";
						sei.lpParameters = const_cast<wchar_t*>(parameters.c_str());

						if (!ShellExecuteEx(&sei))
						{

							DWORD error = GetLastError();
						}
						system("mode con cols=100 lines=15");
						std::cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk W269N-WFGWX-YVC9B-4J6C9-T83GX\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd11 = "\0";
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
					else {
						sei.lpVerb = L"runas";
						sei.lpFile = L"cmd.exe";
						std::wstring parameters = L"/" + disc + L" slmgr /upk & slmgr /ipk W269N-WFGWX-YVC9B-4J6C9-T83GX & slmgr /skms kms.digiboy.ir & slmgr /ato";
						sei.lpParameters = const_cast<wchar_t*>(parameters.c_str());

						if (!ShellExecuteEx(&sei))
						{

							DWORD error = GetLastError();
						}
						system("mode con cols=100 lines=15");
						std::cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk W269N-WFGWX-YVC9B-4J6C9-T83GX\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd11 = "\0";
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
				}
				else if (wd11 == "2") {
						system("cls");
						SHELLEXECUTEINFO sei = { sizeof(sei) };
						if (disc.empty()) {
						sei.lpVerb = L"runas";
						sei.lpFile = L"cmd.exe";
						std::wstring parameters = L"/" + dis + L" slmgr /upk & slmgr /ipk MH37W-N47XK-V7XM9-C7227-GCQG9 & slmgr /skms kms.digiboy.ir & slmgr /ato";
						sei.lpParameters = const_cast<wchar_t*>(parameters.c_str());

						if (!ShellExecuteEx(&sei))
						{

							DWORD error = GetLastError();
						}
						system("mode con cols=100 lines=15");
						std::cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk MH37W-N47XK-V7XM9-C7227-GCQG9\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd11 = "\0";
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
						else {
							sei.lpVerb = L"runas";
							sei.lpFile = L"cmd.exe";
							std::wstring parameters = L"/" + disc + L" slmgr /upk & slmgr /ipk MH37W-N47XK-V7XM9-C7227-GCQG9 & slmgr /skms kms.digiboy.ir & slmgr /ato";
							sei.lpParameters = const_cast<wchar_t*>(parameters.c_str());

							if (!ShellExecuteEx(&sei))
							{

								DWORD error = GetLastError();
							}
							system("mode con cols=100 lines=15");
							std::cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk MH37W-N47XK-V7XM9-C7227-GCQG9\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
							_getch();
							wd11 = "\0";
							system("cls");
							system("mode con cols=162 lines=19");
							break;
						}
				}
				else if (wd11 == "3") {
					system("cls");
					SHELLEXECUTEINFO sei = { sizeof(sei) };
					if (disc.empty()) {
						sei.lpVerb = L"runas";
						sei.lpFile = L"cmd.exe";
						std::wstring parameters = L"/" + dis + L" slmgr /upk & slmgr /ipk NRG8B-VKK3Q-CXVCJ-9G2XF-6Q84J & slmgr /skms kms.digiboy.ir & slmgr /ato";
						sei.lpParameters = const_cast<wchar_t*>(parameters.c_str());

						system("mode con cols=100 lines=15");
						std::cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk NRG8B-VKK3Q-CXVCJ-9G2XF-6Q84J\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd11 = "\0";
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
					else {
						sei.lpVerb = L"runas";
						sei.lpFile = L"cmd.exe";
						std::wstring parameters = L"/" + disc + L" slmgr /upk & slmgr /ipk NRG8B-VKK3Q-CXVCJ-9G2XF-6Q84J & slmgr /skms kms.digiboy.ir & slmgr /ato";
						sei.lpParameters = const_cast<wchar_t*>(parameters.c_str());

						system("mode con cols=100 lines=15");
						std::cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk NRG8B-VKK3Q-CXVCJ-9G2XF-6Q84J\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd11 = "\0";
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
				}
				else if (wd11 == "4") {
					system("cls");
					SHELLEXECUTEINFO sei = { sizeof(sei) };
					if (disc.empty()) {
						sei.lpVerb = L"runas";
						sei.lpFile = L"cmd.exe";
						std::wstring parameters = L"/" + dis + L" slmgr /upk & slmgr /ipk 9FNHH-K3HBT-3W4TD-6383H-6XYWF & slmgr /skms kms.digiboy.ir & slmgr /ato";
						sei.lpParameters = const_cast<wchar_t*>(parameters.c_str());

						if (!ShellExecuteEx(&sei))
						{

							DWORD error = GetLastError();
						}
						system("mode con cols=100 lines=15");
						std::cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk 9FNHH-K3HBT-3W4TD-6383H-6XYWF\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd11 = "\0";
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
					else {
						sei.lpVerb = L"runas";
						sei.lpFile = L"cmd.exe";
						std::wstring parameters = L"/" + disc + L" slmgr /upk & slmgr /ipk 9FNHH-K3HBT-3W4TD-6383H-6XYWF & slmgr /skms kms.digiboy.ir & slmgr /ato";
						sei.lpParameters = const_cast<wchar_t*>(parameters.c_str());

						if (!ShellExecuteEx(&sei))
						{

							DWORD error = GetLastError();
						}
						system("mode con cols=100 lines=15");
						std::cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk 9FNHH-K3HBT-3W4TD-6383H-6XYWF\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd11 = "\0";
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
				}
				else if (wd11 == "5") {
					system("cls");
					SHELLEXECUTEINFO sei = { sizeof(sei) };
					if (disc.empty()) {
						sei.lpVerb = L"runas";
						sei.lpFile = L"cmd.exe";
						std::wstring parameters = L"/" + dis + L" slmgr /upk & slmgr /ipk 6TP4R-GNPTD-KYYHQ-7B7DP-J447Y & slmgr /skms kms.digiboy.ir & slmgr /ato";
						sei.lpParameters = const_cast<wchar_t*>(parameters.c_str());

						if (!ShellExecuteEx(&sei))
						{

							DWORD error = GetLastError();
						}
						system("mode con cols=100 lines=15");
						std::cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk 6TP4R-GNPTD-KYYHQ-7B7DP-J447Y\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd11 = "\0";
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
					else {
						sei.lpVerb = L"runas";
						sei.lpFile = L"cmd.exe";
						std::wstring parameters = L"/" + disc + L" slmgr /upk & slmgr /ipk 6TP4R-GNPTD-KYYHQ-7B7DP-J447Y & slmgr /skms kms.digiboy.ir & slmgr /ato";
						sei.lpParameters = const_cast<wchar_t*>(parameters.c_str());

						if (!ShellExecuteEx(&sei))
						{

							DWORD error = GetLastError();
						}
						system("mode con cols=100 lines=15");
						std::cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk 6TP4R-GNPTD-KYYHQ-7B7DP-J447Y\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd11 = "\0";
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
				}
				else if (wd11 == "6") {
					system("cls");
					SHELLEXECUTEINFO sei = { sizeof(sei) };
					if (disc.empty()) {
						sei.lpVerb = L"runas";
						sei.lpFile = L"cmd.exe";
						std::wstring parameters = L"/" + dis + L" slmgr /upk & slmgr /ipk YVWGF-BXNMC-HTQYQ-CPQ99-66QFC & slmgr /skms kms.digiboy.ir & slmgr /ato";
						sei.lpParameters = const_cast<wchar_t*>(parameters.c_str());

						if (!ShellExecuteEx(&sei))
						{

							DWORD error = GetLastError();
						}
						system("mode con cols=100 lines=15");
						std::cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk YVWGF-BXNMC-HTQYQ-CPQ99-66QFC\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd11 = "\0";
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
					else {
						sei.lpVerb = L"runas";
						sei.lpFile = L"cmd.exe";
						std::wstring parameters = L"/" + disc + L" slmgr /upk & slmgr /ipk YVWGF-BXNMC-HTQYQ-CPQ99-66QFC & slmgr /skms kms.digiboy.ir & slmgr /ato";
						sei.lpParameters = const_cast<wchar_t*>(parameters.c_str());

						if (!ShellExecuteEx(&sei))
						{

							DWORD error = GetLastError();
						}
						system("mode con cols=100 lines=15");
						std::cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk YVWGF-BXNMC-HTQYQ-CPQ99-66QFC\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd11 = "\0";
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
					}
				else if (wd11 == "7") {
					system("cls");
					SHELLEXECUTEINFO sei = { sizeof(sei) };
					if (disc.empty()) {
						sei.lpVerb = L"runas";
						sei.lpFile = L"cmd.exe";
						std::wstring parameters = L"/" + dis + L" slmgr /upk & slmgr /ipk NW6C2-QMPVW-D7KKK-3GKT6-VCFB2 & slmgr /skms kms.digiboy.ir & slmgr /ato";
						sei.lpParameters = const_cast<wchar_t*>(parameters.c_str());

						if (!ShellExecuteEx(&sei))
						{

							DWORD error = GetLastError();
						}
						system("mode con cols=100 lines=15");
						std::cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk NW6C2-QMPVW-D7KKK-3GKT6-VCFB2\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd11 = "\0";
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
					else {
						sei.lpVerb = L"runas";
						sei.lpFile = L"cmd.exe";
						std::wstring parameters = L"/" + disc + L" slmgr /upk & slmgr /ipk NW6C2-QMPVW-D7KKK-3GKT6-VCFB2 & slmgr /skms kms.digiboy.ir & slmgr /ato";
						sei.lpParameters = const_cast<wchar_t*>(parameters.c_str());

						if (!ShellExecuteEx(&sei))
						{

							DWORD error = GetLastError();
						}
						system("mode con cols=100 lines=15");
						std::cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk NW6C2-QMPVW-D7KKK-3GKT6-VCFB2\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd11 = "\0";
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
					}
				else if (wd11 == "8") {
					system("cls");
					SHELLEXECUTEINFO sei = { sizeof(sei) };
					if (disc.empty()) {
						sei.lpVerb = L"runas";
						sei.lpFile = L"cmd.exe";
						std::wstring parameters = L"/" + dis + L" slmgr /upk & slmgr /ipk 2WH4N-8QGBV-H22JP-CT43Q-MDWWJ & slmgr /skms kms.digiboy.ir & slmgr /ato";
						sei.lpParameters = const_cast<wchar_t*>(parameters.c_str());

						if (!ShellExecuteEx(&sei))
						{

							DWORD error = GetLastError();
						}
						system("mode con cols=100 lines=15");
						std::cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk 2WH4N-8QGBV-H22JP-CT43Q-MDWWJ\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd11 = "\0";
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
					else {
						sei.lpVerb = L"runas";
						sei.lpFile = L"cmd.exe";
						std::wstring parameters = L"/" + disc + L" slmgr /upk & slmgr /ipk 2WH4N-8QGBV-H22JP-CT43Q-MDWWJ & slmgr /skms kms.digiboy.ir & slmgr /ato";
						sei.lpParameters = const_cast<wchar_t*>(parameters.c_str());

						if (!ShellExecuteEx(&sei))
						{

							DWORD error = GetLastError();
						}
						system("mode con cols=100 lines=15");
						std::cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk 2WH4N-8QGBV-H22JP-CT43Q-MDWWJ\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd11 = "\0";
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
					}
				else if (wd11 == "9") {
					system("cls");
					SHELLEXECUTEINFO sei = { sizeof(sei) };
					if (disc.empty()) {
						sei.lpVerb = L"runas";
						sei.lpFile = L"cmd.exe";
						std::wstring parameters = L"/" + dis + L" slmgr /upk & slmgr /ipk NPPR9-FWDCX-D2C8J-H872K-2YT43 & slmgr /skms kms.digiboy.ir & slmgr /ato";
						sei.lpParameters = const_cast<wchar_t*>(parameters.c_str());

						if (!ShellExecuteEx(&sei))
						{

							DWORD error = GetLastError();
						}
						system("mode con cols=100 lines=15");
						std::cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk NPPR9-FWDCX-D2C8J-H872K-2YT43\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd11 = "\0";
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
					else {
						sei.lpVerb = L"runas";
						sei.lpFile = L"cmd.exe";
						std::wstring parameters = L"/" + disc + L" slmgr /upk & slmgr /ipk NPPR9-FWDCX-D2C8J-H872K-2YT43 & slmgr /skms kms.digiboy.ir & slmgr /ato";
						sei.lpParameters = const_cast<wchar_t*>(parameters.c_str());

						if (!ShellExecuteEx(&sei))
						{

							DWORD error = GetLastError();
						}
						system("mode con cols=100 lines=15");
						std::cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk NPPR9-FWDCX-D2C8J-H872K-2YT43\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd11 = "\0";
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
					}
				else if (wd11 == "10") {
					system("cls");
					SHELLEXECUTEINFO sei = { sizeof(sei) };
					if (disc.empty()) {
						sei.lpVerb = L"runas";
						sei.lpFile = L"cmd.exe";
						std::wstring parameters = L"/" + dis + L" slmgr /upk & slmgr /ipk DPH2V-TTNVB-4X9Q3-TJR4H-KHJW4 & slmgr /skms kms.digiboy.ir & slmgr /ato";
						sei.lpParameters = const_cast<wchar_t*>(parameters.c_str());

						if (!ShellExecuteEx(&sei))
						{

							DWORD error = GetLastError();
						}
						system("mode con cols=100 lines=15");
						std::cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk DPH2V-TTNVB-4X9Q3-TJR4H-KHJW4\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd11 = "\0";
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
					else {
						sei.lpVerb = L"runas";
						sei.lpFile = L"cmd.exe";
						std::wstring parameters = L"/" + disc + L" slmgr /upk & slmgr /ipk DPH2V-TTNVB-4X9Q3-TJR4H-KHJW4 & slmgr /skms kms.digiboy.ir & slmgr /ato";
						sei.lpParameters = const_cast<wchar_t*>(parameters.c_str());

						if (!ShellExecuteEx(&sei))
						{

							DWORD error = GetLastError();
						}
						system("mode con cols=100 lines=15");
						std::cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk DPH2V-TTNVB-4X9Q3-TJR4H-KHJW4\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd11 = "\0";
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
					}
				else if (wd11 == "11") {
					system("cls");
					SHELLEXECUTEINFO sei = { sizeof(sei) };
					if (disc.empty()) {
						sei.lpVerb = L"runas";
						sei.lpFile = L"cmd.exe";
						std::wstring parameters = L"/" + dis + L" slmgr /upk & slmgr /ipk YYVX9-NTFWV-6MDM3-9PT4T-4M68B & slmgr /skms kms.digiboy.ir & slmgr /ato";
						sei.lpParameters = const_cast<wchar_t*>(parameters.c_str());

						if (!ShellExecuteEx(&sei))
						{

							DWORD error = GetLastError();
						}
						system("mode con cols=100 lines=15");
						std::cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk YYVX9-NTFWV-6MDM3-9PT4T-4M68B \n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd11 = "\0";
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
					else {
						sei.lpVerb = L"runas";
						sei.lpFile = L"cmd.exe";
						std::wstring parameters = L"/" + disc + L" slmgr /upk & slmgr /ipk YYVX9-NTFWV-6MDM3-9PT4T-4M68B & slmgr /skms kms.digiboy.ir & slmgr /ato";
						sei.lpParameters = const_cast<wchar_t*>(parameters.c_str());

						if (!ShellExecuteEx(&sei))
						{

							DWORD error = GetLastError();
						}
						system("mode con cols=100 lines=15");
						std::cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk YYVX9-NTFWV-6MDM3-9PT4T-4M68B \n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd11 = "\0";
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
					}
				else if (wd11 == "12") {
					system("cls");
					SHELLEXECUTEINFO sei = { sizeof(sei) };
					if (disc.empty()) {
						sei.lpVerb = L"runas";
						sei.lpFile = L"cmd.exe";
						std::wstring parameters = L"/" + dis + L" slmgr /upk & slmgr /ipk 44RPN-FTY23-9VTTB-MP9BX-T84FV & slmgr /skms kms.digiboy.ir & slmgr /ato";
						sei.lpParameters = const_cast<wchar_t*>(parameters.c_str());

						if (!ShellExecuteEx(&sei))
						{

							DWORD error = GetLastError();
						}
						system("mode con cols=100 lines=15");
						std::cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk 44RPN-FTY23-9VTTB-MP9BX-T84FV\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd11 = "\0";
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
					else {
						sei.lpVerb = L"runas";
						sei.lpFile = L"cmd.exe";
						std::wstring parameters = L"/" + disc + L" slmgr /upk & slmgr /ipk 44RPN-FTY23-9VTTB-MP9BX-T84FV & slmgr /skms kms.digiboy.ir & slmgr /ato";
						sei.lpParameters = const_cast<wchar_t*>(parameters.c_str());

						if (!ShellExecuteEx(&sei))
						{

							DWORD error = GetLastError();
						}
						system("mode con cols=100 lines=15");
						std::cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk 44RPN-FTY23-9VTTB-MP9BX-T84FV\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd11 = "\0";
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
					}
				else if (wd11 == "13") {
					system("cls");
					SHELLEXECUTEINFO sei = { sizeof(sei) };
					if (disc.empty()) {
						sei.lpVerb = L"runas";
						sei.lpFile = L"cmd.exe";
						std::wstring parameters = L"/" + dis + L" slmgr /upk & slmgr /ipk TX9XD-98N7V-6WMQ6-BX7FG-H8Q99 & slmgr /skms kms.digiboy.ir & slmgr /ato";
						sei.lpParameters = const_cast<wchar_t*>(parameters.c_str());

						if (!ShellExecuteEx(&sei))
						{

							DWORD error = GetLastError();
						}
						system("mode con cols=100 lines=15");
						std::cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk TX9XD-98N7V-6WMQ6-BX7FG-H8Q99\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd11 = "\0";
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
					else {
						sei.lpVerb = L"runas";
						sei.lpFile = L"cmd.exe";
						std::wstring parameters = L"/" + disc + L" slmgr /upk & slmgr /ipk TX9XD-98N7V-6WMQ6-BX7FG-H8Q99 & slmgr /skms kms.digiboy.ir & slmgr /ato";
						sei.lpParameters = const_cast<wchar_t*>(parameters.c_str());

						if (!ShellExecuteEx(&sei))
						{

							DWORD error = GetLastError();
						}
						system("mode con cols=100 lines=15");
						std::cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk TX9XD-98N7V-6WMQ6-BX7FG-H8Q99\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd11 = "\0";
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
					}
				else if (wd11 == "14") {
					system("cls");
					SHELLEXECUTEINFO sei = { sizeof(sei) };
					if (disc.empty()) {
						sei.lpVerb = L"runas";
						sei.lpFile = L"cmd.exe";
						std::wstring parameters = L"/" + dis + L" slmgr /upk & slmgr /ipk 3KHY7-WNT83-DGQKR-F7HPR-844BM & slmgr /skms kms.digiboy.ir & slmgr /ato";
						sei.lpParameters = const_cast<wchar_t*>(parameters.c_str());

						if (!ShellExecuteEx(&sei))
						{

							DWORD error = GetLastError();
						}
						system("mode con cols=100 lines=15");
						std::cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk 3KHY7-WNT83-DGQKR-F7HPR-844BM\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd11 = "\0";
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
					else {
						sei.lpVerb = L"runas";
						sei.lpFile = L"cmd.exe";
						std::wstring parameters = L"/" + disc + L" slmgr /upk & slmgr /ipk 3KHY7-WNT83-DGQKR-F7HPR-844BM & slmgr /skms kms.digiboy.ir & slmgr /ato";
						sei.lpParameters = const_cast<wchar_t*>(parameters.c_str());

						if (!ShellExecuteEx(&sei))
						{

							DWORD error = GetLastError();
						}
						system("mode con cols=100 lines=15");
						std::cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk 3KHY7-WNT83-DGQKR-F7HPR-844BM\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd11 = "\0";
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
					}
				else if (wd11 == "15") {
					system("cls");
					SHELLEXECUTEINFO sei = { sizeof(sei) };
					if (disc.empty()) {
						sei.lpVerb = L"runas";
						sei.lpFile = L"cmd.exe";
						std::wstring parameters = L"/" + dis + L" slmgr /upk & slmgr /ipk 7HNRX-D7KGG-3K4RQ-4WPJ4-YTDFH & slmgr /skms kms.digiboy.ir & slmgr /ato";
						sei.lpParameters = const_cast<wchar_t*>(parameters.c_str());

						if (!ShellExecuteEx(&sei))
						{

							DWORD error = GetLastError();
						}
						system("mode con cols=100 lines=15");
						std::cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk 7HNRX-D7KGG-3K4RQ-4WPJ4-YTDFH\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd11 = "\0";
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
					else {
						sei.lpVerb = L"runas";
						sei.lpFile = L"cmd.exe";
						std::wstring parameters = L"/" + disc + L" slmgr /upk & slmgr /ipk 7HNRX-D7KGG-3K4RQ-4WPJ4-YTDFH & slmgr /skms kms.digiboy.ir & slmgr /ato";
						sei.lpParameters = const_cast<wchar_t*>(parameters.c_str());

						if (!ShellExecuteEx(&sei))
						{

							DWORD error = GetLastError();
						}
						system("mode con cols=100 lines=15");
						std::cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk 7HNRX-D7KGG-3K4RQ-4WPJ4-YTDFH\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd11 = "\0";
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
					}
				else if (wd11 == "16") {
					system("cls");
					SHELLEXECUTEINFO sei = { sizeof(sei) };
					if (disc.empty()) {
						sei.lpVerb = L"runas";
						sei.lpFile = L"cmd.exe";
						std::wstring parameters = L"/" + dis + L" slmgr /upk & slmgr /ipk PVMJN-6DFY6-9CCP6-7BKTT-D3WVR & slmgr /skms kms.digiboy.ir & slmgr /ato";
						sei.lpParameters = const_cast<wchar_t*>(parameters.c_str());

						if (!ShellExecuteEx(&sei))
						{

							DWORD error = GetLastError();
						}
						system("mode con cols=100 lines=15");
						std::cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk PVMJN-6DFY6-9CCP6-7BKTT-D3WVR\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd11 = "\0";
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
					else {
						sei.lpVerb = L"runas";
						sei.lpFile = L"cmd.exe";
						std::wstring parameters = L"/" + disc + L" slmgr /upk & slmgr /ipk PVMJN-6DFY6-9CCP6-7BKTT-D3WVR & slmgr /skms kms.digiboy.ir & slmgr /ato";
						sei.lpParameters = const_cast<wchar_t*>(parameters.c_str());

						if (!ShellExecuteEx(&sei))
						{

							DWORD error = GetLastError();
						}
						system("mode con cols=100 lines=15");
						std::cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk PVMJN-6DFY6-9CCP6-7BKTT-D3WVR\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd11 = "\0";
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
					}
				else if (wd11 == "17") {
					system("cls");
					SHELLEXECUTEINFO sei = { sizeof(sei) };
					if (disc.empty()) {
						sei.lpVerb = L"runas";
						sei.lpFile = L"cmd.exe";
						std::wstring parameters = L"/" + dis + L" slmgr /upk & slmgr /ipk NPPR9-FWDCX-D2C8J-H872K-2YT43 & slmgr /skms kms.digiboy.ir & slmgr /ato";
						sei.lpParameters = const_cast<wchar_t*>(parameters.c_str());

						if (!ShellExecuteEx(&sei))
						{

							DWORD error = GetLastError();
						}
						system("mode con cols=100 lines=15");
						std::cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk NPPR9-FWDCX-D2C8J-H872K-2YT43\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd11 = "\0";
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
					else {
						sei.lpVerb = L"runas";
						sei.lpFile = L"cmd.exe";
						std::wstring parameters = L"/" + disc + L" slmgr /upk & slmgr /ipk NPPR9-FWDCX-D2C8J-H872K-2YT43 & slmgr /skms kms.digiboy.ir & slmgr /ato";
						sei.lpParameters = const_cast<wchar_t*>(parameters.c_str());

						if (!ShellExecuteEx(&sei))
						{

							DWORD error = GetLastError();
						}
						system("mode con cols=100 lines=15");
						std::cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk NPPR9-FWDCX-D2C8J-H872K-2YT43\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd11 = "\0";
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
					}
				else if (wd11 == "18") {
					system("cls");
					SHELLEXECUTEINFO sei = { sizeof(sei) };
					if (disc.empty()) {
						sei.lpVerb = L"runas";
						sei.lpFile = L"cmd.exe";
						std::wstring parameters = L"/" + dis + L" slmgr /upk & slmgr /ipk DPH2V-TTNVB-4X9Q3-TJR4H-KHJW4 & slmgr /skms kms.digiboy.ir & slmgr /ato";
						sei.lpParameters = const_cast<wchar_t*>(parameters.c_str());

						if (!ShellExecuteEx(&sei))
						{

							DWORD error = GetLastError();
						}
						system("mode con cols=100 lines=15");
						std::cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk DPH2V-TTNVB-4X9Q3-TJR4H-KHJW4\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd11 = "\0";
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
					else {
						sei.lpVerb = L"runas";
						sei.lpFile = L"cmd.exe";
						std::wstring parameters = L"/" + disc + L" slmgr /upk & slmgr /ipk DPH2V-TTNVB-4X9Q3-TJR4H-KHJW4 & slmgr /skms kms.digiboy.ir & slmgr /ato";
						sei.lpParameters = const_cast<wchar_t*>(parameters.c_str());

						if (!ShellExecuteEx(&sei))
						{

							DWORD error = GetLastError();
						}
						system("mode con cols=100 lines=15");
						std::cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk DPH2V-TTNVB-4X9Q3-TJR4H-KHJW4\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd11 = "\0";
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
					}
				else if (wd11 == "19") {
					system("cls");
					SHELLEXECUTEINFO sei = { sizeof(sei) };
					if (disc.empty()) {
						sei.lpVerb = L"runas";
						sei.lpFile = L"cmd.exe";
						std::wstring parameters = L"/" + dis + L" slmgr /upk & slmgr /ipk YYVX9-NTFWV-6MDM3-9PT4T-4M68B & slmgr /skms kms.digiboy.ir & slmgr /ato";
						sei.lpParameters = const_cast<wchar_t*>(parameters.c_str());

						if (!ShellExecuteEx(&sei))
						{

							DWORD error = GetLastError();
						}
						system("mode con cols=100 lines=15");
						std::cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk YYVX9-NTFWV-6MDM3-9PT4T-4M68B\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd11 = "\0";
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
					else {
						sei.lpVerb = L"runas";
						sei.lpFile = L"cmd.exe";
						std::wstring parameters = L"/" + disc + L" slmgr /upk & slmgr /ipk YYVX9-NTFWV-6MDM3-9PT4T-4M68B & slmgr /skms kms.digiboy.ir & slmgr /ato";
						sei.lpParameters = const_cast<wchar_t*>(parameters.c_str());

						if (!ShellExecuteEx(&sei))
						{

							DWORD error = GetLastError();
						}
						system("mode con cols=100 lines=15");
						std::cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk YYVX9-NTFWV-6MDM3-9PT4T-4M68B\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd11 = "\0";
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
				}
				else if (wd11 == "20") {
					system("cls");
					SHELLEXECUTEINFO sei = { sizeof(sei) };
					if (disc.empty()) {
						sei.lpVerb = L"runas";
						sei.lpFile = L"cmd.exe";
						std::wstring parameters = L"/" + dis + L" slmgr /upk & slmgr /ipk 44RPN-FTY23-9VTTB-MP9BX-T84FV & slmgr /skms kms.digiboy.ir & slmgr /ato";
						sei.lpParameters = const_cast<wchar_t*>(parameters.c_str());

						if (!ShellExecuteEx(&sei))
						{

							DWORD error = GetLastError();
						}
						system("mode con cols=100 lines=15");
						std::cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk 44RPN-FTY23-9VTTB-MP9BX-T84FV\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd11 = "\0";
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
					else {
						sei.lpVerb = L"runas";
						sei.lpFile = L"cmd.exe";
						std::wstring parameters = L"/" + disc + L" slmgr /upk & slmgr /ipk 44RPN-FTY23-9VTTB-MP9BX-T84FV & slmgr /skms kms.digiboy.ir & slmgr /ato";
						sei.lpParameters = const_cast<wchar_t*>(parameters.c_str());

						if (!ShellExecuteEx(&sei))
						{

							DWORD error = GetLastError();
						}
						system("mode con cols=100 lines=15");
						std::cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk 44RPN-FTY23-9VTTB-MP9BX-T84FV\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd11 = "\0";
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
				}
				else if (wd11 == "21") {
					system("cls");
					SHELLEXECUTEINFO sei = { sizeof(sei) };
					if (disc.empty()) {
						sei.lpVerb = L"runas";
						sei.lpFile = L"cmd.exe";
						std::wstring parameters = L"/" + dis + L" slmgr /upk & slmgr /ipk M7XTQ-FN8P6-TTKYV-9D4CC-J462D & slmgr /skms kms.digiboy.ir & slmgr /ato";
						sei.lpParameters = const_cast<wchar_t*>(parameters.c_str());

						if (!ShellExecuteEx(&sei))
						{

							DWORD error = GetLastError();
						}
						system("mode con cols=100 lines=15");
						std::cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk M7XTQ-FN8P6-TTKYV-9D4CC-J462D\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd11 = "\0";
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
					else {
						sei.lpVerb = L"runas";
						sei.lpFile = L"cmd.exe";
						std::wstring parameters = L"/" + disc + L" slmgr /upk & slmgr /ipk M7XTQ-FN8P6-TTKYV-9D4CC-J462D & slmgr /skms kms.digiboy.ir & slmgr /ato";
						sei.lpParameters = const_cast<wchar_t*>(parameters.c_str());

						if (!ShellExecuteEx(&sei))
						{

							DWORD error = GetLastError();
						}
						system("mode con cols=100 lines=15");
						std::cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk M7XTQ-FN8P6-TTKYV-9D4CC-J462D\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd11 = "\0";
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
					}
				else if (wd11 == "22") {
					system("cls");
					SHELLEXECUTEINFO sei = { sizeof(sei) };
					if (disc.empty()) {
						sei.lpVerb = L"runas";
						sei.lpFile = L"cmd.exe";
						std::wstring parameters = L"/" + dis + L" slmgr /upk & slmgr /ipk 92NFX-8DJQP-P6BBQ-THF9C-7CG2H & slmgr /skms kms.digiboy.ir & slmgr /ato";
						sei.lpParameters = const_cast<wchar_t*>(parameters.c_str());

						if (!ShellExecuteEx(&sei))
						{

							DWORD error = GetLastError();
						}
						system("mode con cols=100 lines=15");
						std::cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk 92NFX-8DJQP-P6BBQ-THF9C-7CG2H\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd11 = "\0";
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
					else {
						sei.lpVerb = L"runas";
						sei.lpFile = L"cmd.exe";
						std::wstring parameters = L"/" + disc + L" slmgr /upk & slmgr /ipk 92NFX-8DJQP-P6BBQ-THF9C-7CG2H & slmgr /skms kms.digiboy.ir & slmgr /ato";
						sei.lpParameters = const_cast<wchar_t*>(parameters.c_str());

						if (!ShellExecuteEx(&sei))
						{

							DWORD error = GetLastError();
						}
						system("mode con cols=100 lines=15");
						std::cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk 92NFX-8DJQP-P6BBQ-THF9C-7CG2H\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd11 = "\0";
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
					}
				else {
					wd11 = "\0";
					system("cls");
					system("mode con cols=162 lines=19");
					break;
				}
			case 3:
				system("cls");
				waveOutSetVolume(0, 0x20002000);
				PlaySound(TEXT(".\\sounds\\sound.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
				SetConsoleTitle(L"Информэйшен");
				system("mode con cols=100 lines=41");
				
				SetConsoleTextAttribute(hStdOut, FOREGROUND_RED);
				std::cout << "\n\n";
				std::cout << "                                                ^YYJYYYJYYYYJYJ.                                    \n";
				std::cout << "                        .:!7~.         .~!!!!!!!?PPPPPPPPPPPPPP7!!!!!!!^                            \n";
				std::cout << "                         ^5P?     .:::::5PPPPP55555555555555555PPPPPPPP?:::::.                      \n";
				std::cout << "                                  ?PPPPPPPPPP5:              .:GGGGGGPPPPPPPP^                      \n";
				std::cout << "                               ~YJPGG7^^^^^^^:     ~YYJJJJYJJJYPGGGGPPPPPPPPPYJJ.                   \n";
				std::cout << "                         .!!!!~JPPGGG?~~!!!~~!!!!!!JPPPPPPPPPPPPPPPPPPPPPPPPPPPP7!~                 \n";
				std::cout << "                  .:::.::~PPPPPPPPPPPPPPPPPPPPP555P55555555555555555555555PPPPPPPPP.                \n";
				std::cout << "                 JPPPPPPPPPPPPPPPPPPPPPPPPPPP5:                          'JPPPPPPP5...              \n";
				std::cout << "                 ^~~~~^~~7GG5~~^^~~~^YPP!^~~~^                            :^~~~~5PPJJ?..            \n";
				std::cout << "                         :GGJ        YPP:      .:!!^                           .7?JGGP!!^           \n";
				std::cout << "                       ::~PPJ        JP5:       ~PP7                              :PPPPP?           \n";
				std::cout << "                      .5PPPPJ                                                       .^PP?           \n";
				std::cout << "              !JJJJJJJYPPPPP5JJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJYJJJJJJJJJJJJJJJJJYYYPP?           \n";
				std::cout << "           ^~~YPPPPPPPPGGGGGGGGGGGPPPPPPPPPPPPPPPPPPPPPPPPPPPPPJJJJJYGGPPPPPPPPPPPPGGGPP?           \n";
				std::cout << "           !PPP55555555GGGGGGGPPPGP5555555555555PPPP5555555555Y.    ~GPPPPP55555PPP555PP?           \n";
				std::cout << "                      :PPPPPJ.                  !PP?                  '7PP7.    5P5: ^PP?           \n";
				std::cout << "                      :PPPPP5JY!                .~!^             ^JJ7. :~~:.   .5PP. ^PP?           \n";
				std::cout << "                       ?JYGGGBB?                                 :JY7           7JJ!~7PP?           \n";
				std::cout << "                         ^GGGGGJ.                                                 :GGG5P7           \n";
				std::cout << "           !PPPPPPPP55555PPPPPPP555555555555555555P7                   !P5555555555PP5::            \n";
				std::cout << "           :!!~~~!!!PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP5?JJ??JJJ??JJ???JJJ?5GGGGGGGGPPP!!~              \n";
				std::cout << "                    ?JJJJYPPPPPPPPPPPYJJJJJPPPPPPPPPPPPPPPPPPPPPPPPPPJJYYYYYYPGGPP5. .~~^           \n";
				std::cout << "                         :PPPPPPPPPPP~..  .5PPPPPPPPPPPPPPPPPPPPPPPP?     ...YPPPP5. ^PP?           \n";
				std::cout << "                          ::!PPGGGGGGGPP:                                 7P5PPP^                   \n";
				std::cout << "                            ~PPPGGGGGGGGYJ?.                     .??????J?5PP?~!                    \n";
				std::cout << "                            ~PPPGG5JJJJJGGG~^~!~^          .~~^^~7PPPPPPPP5JJ:                      \n";
				std::cout << "                            ~PPGGG!    .YPPPPPGGY..      .::5PPPPPPPPPPPPP!                         \n";
				std::cout << "                            ~PP?::            ^:~P555P555555PPP::::.!GGGPP!                         \n";
				std::cout << "                            ~PP?                :7!!!!YPPPPP7!!     :!!JPP!                         \n";
				std::cout << "                            ^JY!                      !YYPPP:          !PP!                         \n";
				std::cout << "                                                         JPP:          7PP!                         \n";
				std::cout << "                                                        .:::           7PP!                         \n";
				std::cout << "                                                                       7PP!                         \n";
				std::cout << "                                                                       ~YY~                         \n";
				std::cout << "\n\n";
				while (true)
				{
					int m = 5, n = 38;
					for (int z = 0; z < sizeof(info) / sizeof(info[0]); z++) {
						if (z == act_info) {
							SetConsoleTextAttribute(hStdOut, FOREGROUND_RED);
							info[z] = Stral[0] + info[z].substr(5);
							GoToMN(m, n++);
							std::cout << info[z];
						}
						else {
							SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
							info[z] = Stral2[0] + info[z].substr(5);
							GoToMN(m, n++);
							std::cout << info[z];
						}
					}
					ch = _getch();
					if (ch == -32) ch = _getch();
					switch (ch)
					{
					case esc:
						system("cls");
						system("mode con cols=162 lines=19");
						waveOutSetVolume(0, 0x20002000);
						PlaySound(TEXT(".\\sounds\\main.wav"), NULL, SND_FILENAME | SND_ASYNC);
						goto ExALL;
					case upa:
						if (act_info > 0) {
							--act_info;
						}
						break;

					case dwns:
						if (act_info < size(info) - 1) {
							++act_info;
						}
						break;
					case ETR:
						switch (act_info)
						{
						case 0:
							system("start https://discord.gg/SydPS5V6Pa");
							break;
						case 1:
							system("start https://github.com/z-ipox");
							break;
						}
						break;
					}
				}
				system("mode con cols=162 lines=19");
				break;
			case 4:
				system("cls");
				system("mode con cols=72 lines=15");
				GoToXB(b, s);
				std::cout << "$$$$$$$\\                            $$\\                           \n";
				std::cout << " $$  __$$\\                           $$ |                          \n";
				std::cout << " $$ |  $$ |$$\\   $$\\  $$$$$$\\        $$$$$$$\\  $$\\   $$\\  $$$$$$\\  \n";
				std::cout << " $$$$$$$\\ |$$ |  $$ |$$  __$$\\       $$  __$$\\ $$ |  $$ |$$  __$$\\ \n";
				std::cout << " $$  __$$\\ $$ |  $$ |$$$$$$$$ |      $$ |  $$ |$$ |  $$ |$$$$$$$$ |\n";
				std::cout << " $$ |  $$ |$$ |  $$ |$$   ____|      $$ |  $$ |$$ |  $$ |$$   ____|\n";
				std::cout << " $$$$$$$  |\\$$$$$$$ |\\$$$$$$$\\       $$$$$$$  |\\$$$$$$$ |\$$$$$$$\\ \n";
				std::cout << " \\_______/  \\____$$ | \\_______|      \\_______/  \\____$$ | \\______|\n";
				std::cout << "           $$\\   $$ |                          $$\\   $$ |          \n";
				std::cout << "           \\$$$$$$  |                          \\$$$$$$  |          \n";
				std::cout << "            \\______/                            \\______/           \n";
				Sleep(1337);
				exit(0);
			}
			break;
		default:
			std::cout << "\0";
		}
	}
	}
	
