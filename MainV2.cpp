#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <shellapi.h>
#include <cstdlib>
#include <stralign.h>
#include <string>
#include <conio.h>

#define UP 72 
#define DWN 80 
#define back 8
#define esc 27
#define ENTR 13

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


int main() {
	setlocale(LC_ALL, "ru");
	system("mode con cols=162 lines=19");
	ConsoleCursorVisible(false, 100);
	string Stral[] = { " [>>]" };
	string Stral2[] = { " [>] " };
	string Menu[] = { Stral2[0] + " ДИСК",  Stral2[0] + " Активация Windows 10",  Stral2[0] + " Активация Windows 11",  Stral2[0] + " Информация",  Stral2[0] + " Выход"};
	string Logo[] = { " $$\\      $$\\ $$\\                 $$\\                                          $$$$$$\\              $$\\     $$\\                      $$\\                           $$ | $\\  $$ |\\__|                $$ |                                        $$  __$$\\             $$ |    \\__|                     $$ |                          $$ |$$$\\ $$ |$$\\ $$$$$$$\\   $$$$$$$ | $$$$$$\\  $$\\  $$\\  $$\\  $$$$$$$\\       $$ /  $$ | $$$$$$$\\ $$$$$$\\   $$\\ $$\\    $$\\ $$$$$$\\ $$$$$$\\    $$$$$$\\   $$$$$$\\    $$ $$ $$\\$$ |$$ |$$  __$$\\ $$  __$$ |$$  __$$\\ $$ | $$ | $$ |$$  _____|      $$$$$$$$ |$$  _____|\\_$$  _|  $$ |\\$$\\  $$  |\\____$$\\\\_$$  _|  $$  __$$\\ $$  __$$\\   $$$$  _$$$$ |$$ |$$ |  $$ |$$ /  $$ |$$ /  $$ |$$ | $$ | $$ |\\$$$$$$\\        $$  __$$ |$$ /        $$ |    $$ | \\$$\\$$  / $$$$$$$ | $$ |    $$ /  $$ |$$ |  \\__|  $$$  / \\$$$ |$$ |$$ |  $$ |$$ |  $$ |$$ |  $$ |$$ | $$ | $$ | \\____$$\\       $$ |  $$ |$$ |        $$ |$$\\ $$ |  \\$$$  / $$  __$$ | $$ |$$\\ $$ |  $$ |$$ |        $$  /   \\$$ |$$ |$$ |  $$ |\\$$$$$$$ |\\$$$$$$  |\\$$$$$\\$$$$  |$$$$$$$  |      $$ |  $$ |\\$$$$$$$\\   \\$$$$  |$$ |   \\$  /  \\$$$$$$$ | \\$$$$  |\\$$$$$$  |$$ |        \\__/     \\__|\\__|\\__|  \\__| \\_______| \\______/  \\_____\\____/ \\_______/       \\__|  \\__| \\_______|   \\____/ \\__|    \\_/    \\_______|  \\____/  \\______/ \\__|      " };
	char ch, wd10, wd11, wds;
	wstring disc;
	wstring dis = L"c";
	int active_menu = 0;
	SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);

	

	while (true)
	{
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
			cout << Logo[a] << endl;
		}

		int x = 5, y = 12;
		GoToXY(x, y);

		for (int i = 0; i < sizeof(Menu) / sizeof(Menu[0]); i++) {
			if (i == active_menu) {
				SetConsoleTextAttribute(hStdOut, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
				GoToXY(x, y++);
				Menu[i] = Stral[0] + Menu[i].substr(5);
				cout << Menu[i];
			}
			else {
				SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);
				Menu[i] = Stral2[0] + Menu[i].substr(5);
				GoToXY(x, y++);
				cout << Menu[i];
			}

			/*cout << Menu[i] << endl;*/
		}
		
		ch = _getch();
	if (ch == -32) ch = _getch(); 
		switch (ch)
		{
		case esc:
			system("cls");
			system("mode con cols=72 lines=15");
			GoToXB(b, s);
			cout << "$$$$$$$\\                            $$\\                           \n";
			cout << " $$  __$$\\                           $$ |                          \n";
			cout << " $$ |  $$ |$$\\   $$\\  $$$$$$\\        $$$$$$$\\  $$\\   $$\\  $$$$$$\\  \n";
			cout << " $$$$$$$\\ |$$ |  $$ |$$  __$$\\       $$  __$$\\ $$ |  $$ |$$  __$$\\ \n";
			cout << " $$  __$$\\ $$ |  $$ |$$$$$$$$ |      $$ |  $$ |$$ |  $$ |$$$$$$$$ |\n";
			cout << " $$ |  $$ |$$ |  $$ |$$   ____|      $$ |  $$ |$$ |  $$ |$$   ____|\n";
			cout << " $$$$$$$  |\\$$$$$$$ |\\$$$$$$$\\       $$$$$$$  |\\$$$$$$$ |\$$$$$$$\\ \n";
			cout << " \\_______/  \\____$$ | \\_______|      \\_______/  \\____$$ | \\______|\n";
			cout << "           $$\\   $$ |                          $$\\   $$ |          \n";
			cout << "           \\$$$$$$  |                          \\$$$$$$  |          \n";
			cout << "            \\______/                            \\______/           \n";
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
				cout << "\n	 !!! ПИШИ НАЗВАНИЕ ДИСКА НА ENG !!!\n";
				SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);
				cout << " [>>] Выбери диск на котором установлена Windows (Пример: c): ";
				wcin >> disc;
				system("cls");
				system("mode con cols=162 lines=19");
				break;
			case 1:
				SetConsoleTitle(L"Windows 10");
				system("cls");
				system("mode con cols=110 lines=24");
				SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);
				cout << "\n [1] Windows 10 Pro                         [20] Windows 10 Core Country Specific\n";
				cout << " [2] Windows 10 Pro N                       [21] Windows 10 Education\n";
				cout << " [3] Windows 10 Pro Enterprise              [22] Windows 10 Education N\n";
				cout << " [4] Windows 10 Pro for Workstation         [23] Windows 10 Pro Education \n";
				cout << " [5] Windows 10 Pro N for Workstation       [24] Windows 10 Pro Education N \n";
				cout << " [6] Windows 10 Home                        [25] Windows 10 S\n";
				cout << " [7] Windows 10 Home N                      [26] Windows 10 Сorporative 2021 with long-term service\n";
				cout << " [8] Windows 10 Home Country Specific       [27] Windows 10 Сorporative LTSC 2019\n";
				cout << " [9] Windows 10 Home Single Language        [28] Windows 10 Сorporative 2015 with long-term service\n";
				cout << "\n [10] Windows 10 Enterprise                 [29] Windows 10 Сorporative N LTSC 2021\n";
				cout << " [11] Windows 10 Enterprise N               [30] Windows 10 Сorporative N LTSC 2019\n";
				cout << " [12] Windows 10 Enterprise S               [31] Windows 10 Сorporative 2015 with long-term service N\n";
				cout << " [13] Windows 10 Enterprise G               [32] Windows 10 Сorporative\n";
				cout << " [14] Windows 10 Enterprise G N             [33] Windows 10 Сorporative N\n";
				cout << " [15] Windows 10 Enterprise 2015 LTSB       [34] Windows 10 Сorporative G\n";
				cout << " [16] Windows 10 Enterprise 2015 LTSB N     [35] Windows 10 Сorporative G N\n";
				cout << " [17] Windows 10 Enterprise 2016 LTSB       [0] Back\n";
				cout << " [18] Windows 10 Enterprise 2016 LTSB N     \n";
				cout << " [19] Windows 10 Core Single Language       \n\n";
				cout << " [>>] Введи номер пункта: ";
				cin >> wd10;
				if (wd10 == '1') {
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
							cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk W269N-WFGWX-YVC9B-4J6C9-T83GX\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
							_getch();
							wd10 = '\0';
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
							cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk W269N-WFGWX-YVC9B-4J6C9-T83GX\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
							_getch();
							wd10 = '\0';
							system("cls");
							system("mode con cols=162 lines=19");
							break;
						}
				}
				else if (wd10 == '2') {
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
						cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk MH37W-N47XK-V7XM9-C7227-GCQG9\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd10 = '\0';
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
						cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk MH37W-N47XK-V7XM9-C7227-GCQG9\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd10 = '\0';
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
				}
				else if (wd10 == '3') {
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
						cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk NPPR9-FWDCX-D2C8J-H872K-2YT43\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd10 = '\0';
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
						cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk NPPR9-FWDCX-D2C8J-H872K-2YT43\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd10 = '\0';
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
				}
				else if (wd10 == '4') {
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
						cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk NRG8B-VKK3Q-CXVCJ-9G2XF-6Q84J\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd10 = '\0';
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
						cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk NRG8B-VKK3Q-CXVCJ-9G2XF-6Q84J\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd10 = '\0';
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
				}
				else if (wd10 == '5') {
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
						cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk 9FNHH-K3HBT-3W4TD-6383H-6XYWF\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd10 = '\0';
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
						cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk 9FNHH-K3HBT-3W4TD-6383H-6XYWF\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd10 = '\0';
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}

				}
				else if (wd10 == '6') {
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
						cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk TX9XD-98N7V-6WMQ6-BX7FG-H8Q99\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd10 = '\0';
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
						cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk TX9XD-98N7V-6WMQ6-BX7FG-H8Q99\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd10 = '\0';
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
				}
				else if (wd10 == '7') {
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
						cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk 3KHY7-WNT83-DGQKR-F7HPR-844BM\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd10 = '\0';
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
						cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk 3KHY7-WNT83-DGQKR-F7HPR-844BM\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd10 = '\0';
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
				}
				else if (wd10 == '8') {
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
						cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk PVMJN-6DFY6-9CCP6-7BKTT-D3WVR\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd10 = '\0';
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
						cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk PVMJN-6DFY6-9CCP6-7BKTT-D3WVR\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd10 = '\0';
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
				}
				else if (wd10 == '9') {
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
						cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk 7HNRX-D7KGG-3K4RQ-4WPJ4-YTDFH\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd10 = '\0';
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
						cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk 7HNRX-D7KGG-3K4RQ-4WPJ4-YTDFH\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd10 = '\0';
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
				}
				else if (wd10 == '10') {
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
						cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk NPPR9-FWDCX-D2C8J-H872K-2YT43\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd10 = '\0';
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
						cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk NPPR9-FWDCX-D2C8J-H872K-2YT43\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd10 = '\0';
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
				}
				else if (wd10 == '11') {
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
						cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk DPH2V-TTNVB-4X9Q3-TJR4H-KHJW4\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd10 = '\0';
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
						cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk DPH2V-TTNVB-4X9Q3-TJR4H-KHJW4\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd10 = '\0';
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
				}
				else if (wd10 == '12') {
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
						cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk FWN7H-PF93Q-4GGP8-M8RF3-MDWWW\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd10 = '\0';
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
						cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk FWN7H-PF93Q-4GGP8-M8RF3-MDWWW\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd10 = '\0';
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
				}
				else if (wd10 == '13') {
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
						cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk YYVX9-NTFWV-6MDM3-9PT4T-4M68B\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd10 = '\0';
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
						cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk YYVX9-NTFWV-6MDM3-9PT4T-4M68B\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd10 = '\0';
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
				}
				else if (wd10 == '14') {
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
						cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk 44RPN-FTY23-9VTTB-MP9BX-T84FV\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd10 = '\0';
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
						cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk 44RPN-FTY23-9VTTB-MP9BX-T84FV\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd10 = '\0';
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
				}
				else if (wd10 == '15') {
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
						cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk WNMTR-4C88C-JK8YV-HQ7T2-76DF9\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd10 = '\0';
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
						cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk WNMTR-4C88C-JK8YV-HQ7T2-76DF9\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd10 = '\0';
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
				}
				else if (wd10 == '16') {
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
						cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk 2F77B-TNFGY-69QQF-B8YKP-D69TJ\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd10 = '\0';
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
						cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk 2F77B-TNFGY-69QQF-B8YKP-D69TJ\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd10 = '\0';
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
				}
				else if (wd10 == '17') {
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
						cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk DCPHK-NFMTC-H88MJ-PFHPY-QJ4BJ\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd10 = '\0';
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
						cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk DCPHK-NFMTC-H88MJ-PFHPY-QJ4BJ\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd10 = '\0';
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
				}
				else if (wd10 == '18') {
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
						cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk QFFDN-GRT3P-VKWWX-X7T3R-8B639\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd10 = '\0';
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
						cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk QFFDN-GRT3P-VKWWX-X7T3R-8B639\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd10 = '\0';
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
				}
				else if (wd10 == '19') {
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
						cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk BT79Q-G7N6G-PGBYW-4YWX6-6F4BT\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd10 = '\0';
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
						cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk BT79Q-G7N6G-PGBYW-4YWX6-6F4BT\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd10 = '\0';
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
				}
				else if (wd10 == '20') {
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
						cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk N2434-X9D7W-8PF6X-8DV9T-8TYMD\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd10 = '\0';
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
						cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk N2434-X9D7W-8PF6X-8DV9T-8TYMD\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd10 = '\0';
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
				}
				else if (wd10 == '21') {
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
						cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk YNMGQ-8RYV3-4PGQ3-C8XTP-7CFBY\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd10 = '\0';
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
						cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk YNMGQ-8RYV3-4PGQ3-C8XTP-7CFBY\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd10 = '\0';
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
				}
				else if (wd10 == '22') {
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
						cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk 84NGF-MHBT6-FXBX8-QWJK7-DRR8H\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd10 = '\0';
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
						cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk 84NGF-MHBT6-FXBX8-QWJK7-DRR8H\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd10 = '\0';
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
				}
				else if (wd10 == '23') {
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
						cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk 8PTT6-RNW4C-6V7J2-C2D3X-MHBPB\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd10 = '\0';
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
						cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk 8PTT6-RNW4C-6V7J2-C2D3X-MHBPB\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd10 = '\0';
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
				}
				else if (wd10 == '24') {
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
						cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk GJTYN-HDMQY-FRR76-HVGC7-QPF8P\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						system("cls");
						wd10 = '\0';
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
						cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk GJTYN-HDMQY-FRR76-HVGC7-QPF8P\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						system("cls");
						wd10 = '\0';
						system("mode con cols=162 lines=19");
						break;
					}
				}
				else if (wd10 == '25') {
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
						cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk 3NF4D-GF9GY-63VKH-QRC3V-7QW8P\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						system("cls");
						wd10 = '\0';
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
						cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk 3NF4D-GF9GY-63VKH-QRC3V-7QW8P\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						system("cls");
						wd10 = '\0';
						system("mode con cols=162 lines=19");
						break;
					}
				}
				else if (wd10 == '26') {
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
						cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk M7XTQ-FN8P6-TTKYV-9D4CC-J462D\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						system("cls");
						wd10 = '\0';
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
						cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk M7XTQ-FN8P6-TTKYV-9D4CC-J462D\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						system("cls");
						wd10 = '\0';
						system("mode con cols=162 lines=19");
						break;
					}
				}
				else if (wd10 == '27') {
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
						cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk M7XTQ-FN8P6-TTKYV-9D4CC-J462D\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						system("cls");
						wd10 = '\0';
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
						cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk M7XTQ-FN8P6-TTKYV-9D4CC-J462D\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						system("cls");
						wd10 = '\0';
						system("mode con cols=162 lines=19");
						break;
					}
				}
				else if (wd10 == '28') {
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
						cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk WNMTR-4C88C-JK8YV-HQ7T2-76DF9\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						system("cls");
						wd10 = '\0';
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
						cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk WNMTR-4C88C-JK8YV-HQ7T2-76DF9\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						system("cls");
						wd10 = '\0';
						system("mode con cols=162 lines=19");
						break;
					}
				}
				else if (wd10 == '29') {
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
						cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk 92NFX-8DJQP-P6BBQ-THF9C-7CG2H\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd10 = '\0';
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
						cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk 92NFX-8DJQP-P6BBQ-THF9C-7CG2H\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd10 = '\0';
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
				}
				else if (wd10 == '30') {
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
						cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk 92NFX-8DJQP-P6BBQ-THF9C-7CG2H\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd10 = '\0';
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
						cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk 92NFX-8DJQP-P6BBQ-THF9C-7CG2H\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd10 = '\0';
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
				}
				else if (wd10 == '31') {
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
						cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk 2F77B-TNFGY-69QQF-B8YKP-D69TJ\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd10 = '\0';
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
						cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk 2F77B-TNFGY-69QQF-B8YKP-D69TJ\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd10 = '\0';
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
				}
				else if (wd10 == '32') {
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
						cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk NPPR9-FWDCX-D2C8J-H872K-2YT43\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd10 = '\0';
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
						cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk NPPR9-FWDCX-D2C8J-H872K-2YT43\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd10 = '\0';
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
				}
				else if (wd10 == '33') {
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
						cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk DPH2V-TTNVB-4X9Q3-TJR4H-KHJW4\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd10 = '\0';
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
						cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk DPH2V-TTNVB-4X9Q3-TJR4H-KHJW4\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd10 = '\0';
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
				}
				else if (wd10 == '34') {
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
						cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk YYVX9-NTFWV-6MDM3-9PT4T-4M68B\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd10 = '\0';
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
						cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk YYVX9-NTFWV-6MDM3-9PT4T-4M68B\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd10 = '\0';
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
				}
				else if (wd10 == '35') {
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
						cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk 44RPN-FTY23-9VTTB-MP9BX-T84FV\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd10 = '\0';
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
						cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk 44RPN-FTY23-9VTTB-MP9BX-T84FV\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd10 = '\0';
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
				}
				else {
					wd10 = '\0';
					system("cls");
					system("mode con cols=162 lines=19");
					break;
				}
				
			case 2:
				SetConsoleTitle(L"Windows 11");
				system("cls");
				system("mode con cols=110 lines=24");
				SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);
				cout << "\n [1] Windows 11 Pro                          [19] Windows 11 Enterprise G\n";
				cout << " [2] Windows 11 Pro N                        [20] Windows 11 Enterprise G N\n";
				cout << " [3] Windows 11 Pro Workstation              [21] Windows 11 Enterprise LTSC 2019\n";
				cout << " [4] Windows 11 Pro Workstation N            [22] Windows 11 Enterprise N LTSC 2019\n";
				cout << " [5] Windows 11 Pro Education                [0] Back\n";
				cout << " [6] Windows 11 Pro Education N              \n";
				cout << " [7] Windows 11 Education                    \n";
				cout << " [8] Windows 11 Education N                  \n";
				cout << " [9] Windows 11 Сorporative                  \n";
				cout << "\n [10] Windows 11 Сorporative N               \n";
				cout << " [11] Windows 11 Сorporative G               \n";
				cout << " [12] Windows 11 Сorporative G N             \n";
				cout << " [13] Windows 11 Home                        \n";
				cout << " [14] Windows 11 Home N                      \n";
				cout << " [15] Windows 11 Home Home Single Language   \n";
				cout << " [16] Windows 11 Home Country Specific       \n";
				cout << " [17] Windows 11 Enterprise\n";
				cout << " [18] Windows 11 Enterprise N\n\n";
				cout << " [>>] Введи номер пункта: ";
				cin >> wd11;
				if (wd11 == '1') {
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
						cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk W269N-WFGWX-YVC9B-4J6C9-T83GX\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd11 = '\0';
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
						cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk W269N-WFGWX-YVC9B-4J6C9-T83GX\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd11 = '\0';
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
				}
				else if (wd11 == '2') {
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
						cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk MH37W-N47XK-V7XM9-C7227-GCQG9\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd11 = '\0';
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
							cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk MH37W-N47XK-V7XM9-C7227-GCQG9\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
							_getch();
							wd11 = '\0';
							system("cls");
							system("mode con cols=162 lines=19");
							break;
						}
				}
				else if (wd11 == '3') {
					system("cls");
					SHELLEXECUTEINFO sei = { sizeof(sei) };
					if (disc.empty()) {
						sei.lpVerb = L"runas";
						sei.lpFile = L"cmd.exe";
						std::wstring parameters = L"/" + dis + L" slmgr /upk & slmgr /ipk NRG8B-VKK3Q-CXVCJ-9G2XF-6Q84J & slmgr /skms kms.digiboy.ir & slmgr /ato";
						sei.lpParameters = const_cast<wchar_t*>(parameters.c_str());

						system("mode con cols=100 lines=15");
						cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk NRG8B-VKK3Q-CXVCJ-9G2XF-6Q84J\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd11 = '\0';
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
						cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk NRG8B-VKK3Q-CXVCJ-9G2XF-6Q84J\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd11 = '\0';
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
				}
				else if (wd11 == '4') {
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
						cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk 9FNHH-K3HBT-3W4TD-6383H-6XYWF\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd11 = '\0';
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
						cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk 9FNHH-K3HBT-3W4TD-6383H-6XYWF\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd11 = '\0';
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
				}
				else if (wd11 == '5') {
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
						cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk 6TP4R-GNPTD-KYYHQ-7B7DP-J447Y\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd11 = '\0';
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
						cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk 6TP4R-GNPTD-KYYHQ-7B7DP-J447Y\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd11 = '\0';
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
				}
				else if (wd11 == '6') {
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
						cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk YVWGF-BXNMC-HTQYQ-CPQ99-66QFC\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd11 = '\0';
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
						cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk YVWGF-BXNMC-HTQYQ-CPQ99-66QFC\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd11 = '\0';
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
					}
				else if (wd11 == '7') {
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
						cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk NW6C2-QMPVW-D7KKK-3GKT6-VCFB2\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd11 = '\0';
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
						cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk NW6C2-QMPVW-D7KKK-3GKT6-VCFB2\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd11 = '\0';
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
					}
				else if (wd11 == '8') {
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
						cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk 2WH4N-8QGBV-H22JP-CT43Q-MDWWJ\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd11 = '\0';
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
						cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk 2WH4N-8QGBV-H22JP-CT43Q-MDWWJ\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd11 = '\0';
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
					}
				else if (wd11 == '9') {
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
						cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk NPPR9-FWDCX-D2C8J-H872K-2YT43\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd11 = '\0';
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
						cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk NPPR9-FWDCX-D2C8J-H872K-2YT43\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd11 = '\0';
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
					}
				else if (wd11 == '10') {
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
						cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk DPH2V-TTNVB-4X9Q3-TJR4H-KHJW4\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd11 = '\0';
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
						cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk DPH2V-TTNVB-4X9Q3-TJR4H-KHJW4\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd11 = '\0';
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
					}
				else if (wd11 == '11') {
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
						cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk YYVX9-NTFWV-6MDM3-9PT4T-4M68B \n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd11 = '\0';
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
						cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk YYVX9-NTFWV-6MDM3-9PT4T-4M68B \n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd11 = '\0';
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
					}
				else if (wd11 == '12') {
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
						cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk 44RPN-FTY23-9VTTB-MP9BX-T84FV\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd11 = '\0';
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
						cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk 44RPN-FTY23-9VTTB-MP9BX-T84FV\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd11 = '\0';
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
					}
				else if (wd11 == '13') {
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
						cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk TX9XD-98N7V-6WMQ6-BX7FG-H8Q99\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd11 = '\0';
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
						cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk TX9XD-98N7V-6WMQ6-BX7FG-H8Q99\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd11 = '\0';
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
					}
				else if (wd11 == '14') {
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
						cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk 3KHY7-WNT83-DGQKR-F7HPR-844BM\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd11 = '\0';
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
						cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk 3KHY7-WNT83-DGQKR-F7HPR-844BM\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd11 = '\0';
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
					}
				else if (wd11 == '15') {
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
						cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk 7HNRX-D7KGG-3K4RQ-4WPJ4-YTDFH\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd11 = '\0';
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
						cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk 7HNRX-D7KGG-3K4RQ-4WPJ4-YTDFH\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd11 = '\0';
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
					}
				else if (wd11 == '16') {
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
						cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk PVMJN-6DFY6-9CCP6-7BKTT-D3WVR\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd11 = '\0';
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
						cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk PVMJN-6DFY6-9CCP6-7BKTT-D3WVR\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd11 = '\0';
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
					}
				else if (wd11 == '17') {
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
						cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk NPPR9-FWDCX-D2C8J-H872K-2YT43\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd11 = '\0';
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
						cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk NPPR9-FWDCX-D2C8J-H872K-2YT43\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd11 = '\0';
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
					}
				else if (wd11 == '18') {
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
						cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk DPH2V-TTNVB-4X9Q3-TJR4H-KHJW4\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd11 = '\0';
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
						cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk DPH2V-TTNVB-4X9Q3-TJR4H-KHJW4\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd11 = '\0';
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
					}
				else if (wd11 == '19') {
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
						cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk YYVX9-NTFWV-6MDM3-9PT4T-4M68B\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd11 = '\0';
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
						cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk YYVX9-NTFWV-6MDM3-9PT4T-4M68B\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd11 = '\0';
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
				}
				else if (wd11 == '20') {
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
						cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk 44RPN-FTY23-9VTTB-MP9BX-T84FV\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd11 = '\0';
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
						cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk 44RPN-FTY23-9VTTB-MP9BX-T84FV\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd11 = '\0';
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
				}
				else if (wd11 == '21') {
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
						cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk M7XTQ-FN8P6-TTKYV-9D4CC-J462D\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd11 = '\0';
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
						cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk M7XTQ-FN8P6-TTKYV-9D4CC-J462D\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd11 = '\0';
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
					}
				else if (wd11 == '22') {
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
						cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk 92NFX-8DJQP-P6BBQ-THF9C-7CG2H\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd11 = '\0';
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
						cout << "\n ЧТО ПРОИЗОШЛО:\n slmgr /upk\n slmgr /ipk 92NFX-8DJQP-P6BBQ-THF9C-7CG2H\n slmgr /skms kms.digiboy.ir\n slmgr /ato\n\n";
						_getch();
						wd11 = '\0';
						system("cls");
						system("mode con cols=162 lines=19");
						break;
					}
					}
				else {
					wd11 = '\0';
					system("cls");
					system("mode con cols=162 lines=19");
					break;
				}
			case 3:
				SetConsoleTitle(L"Информэйшен");
				system("cls");
				system("mode con cols=110 lines=24");
				
				SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				cout << "Пользователь выбрал " << Menu[active_menu] << "\n";
				_getch();
				system("cls");
				system("mode con cols=162 lines=19");
				break;
			case 4:
				system("cls");
				system("mode con cols=72 lines=15");
				GoToXB(b, s);
				cout << "$$$$$$$\\                            $$\\                           \n";
				cout << " $$  __$$\\                           $$ |                          \n";
				cout << " $$ |  $$ |$$\\   $$\\  $$$$$$\\        $$$$$$$\\  $$\\   $$\\  $$$$$$\\  \n";
				cout << " $$$$$$$\\ |$$ |  $$ |$$  __$$\\       $$  __$$\\ $$ |  $$ |$$  __$$\\ \n";
				cout << " $$  __$$\\ $$ |  $$ |$$$$$$$$ |      $$ |  $$ |$$ |  $$ |$$$$$$$$ |\n";
				cout << " $$ |  $$ |$$ |  $$ |$$   ____|      $$ |  $$ |$$ |  $$ |$$   ____|\n";
				cout << " $$$$$$$  |\\$$$$$$$ |\\$$$$$$$\\       $$$$$$$  |\\$$$$$$$ |\$$$$$$$\\ \n";
				cout << " \\_______/  \\____$$ | \\_______|      \\_______/  \\____$$ | \\______|\n";
				cout << "           $$\\   $$ |                          $$\\   $$ |          \n";
				cout << "           \\$$$$$$  |                          \\$$$$$$  |          \n";
				cout << "            \\______/                            \\______/           \n";
				Sleep(1337);
				exit(0);
			}
			break;
		default:
			cout << "\0";
		}
	}
	}
	
