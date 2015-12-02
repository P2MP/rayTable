#include <iostream>
#include <string>
#include <sstream>
#include <windows.h>
#include <conio.h>

using namespace std;

const short tsize_x = 26;
const short tsize_y = 26;
char rayTable[tsize_y][tsize_x];


int validation(string convert)
{
    int i;
    stringstream ss(convert);
    ss >> i;
    if(ss.fail())
    {
        return -1;
    }
    else
    {
        return i;
    }

}
int getx()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(h,&csbi);
    return csbi.dwCursorPosition.X;
}
int gety()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(h,&csbi);
    return csbi.dwCursorPosition.Y;
}
COORD getCoord()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(h,&csbi);
    return csbi.dwCursorPosition;
}
void gotoCoord(COORD coord)
{
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
COORD strToIndex(string strx, string stry)
{
    char px[100];
    char py[100];
    COORD coord;
    coord.X = -1;
    coord.Y = -1;

    for (int i = 0; i < tsize_y; i++)
    {
        if (i < 26)
        {
            py[i] = i + 97;
        }
        if (i >= 26)
        {
            py[i] = i + 39;
        }
        if (stry[0] == py[i])
        {
            coord.Y = i;
        }
    }
    for (int i = 0; i < tsize_x; i++)
    {
        if (i < 26)
        {
            px[i] = i + 97;
        }
        if (i >= 26)
        {
            px[i] = i + 39;
        }
        if (strx[0] == px[i])
        {
            coord.X = i;
        }
    }
    return coord;
}
void rayTablePrint()
{
    char p0[100];
    for (int i = 0; i < tsize_y; i++)
    {
        for (int j = 0; j < tsize_x; j++)
        {
            cout << rayTable[i][j];
        }
        if (i < 26)
        {
            p0[i] = i + 97;
        }
        if (i >= 26)
        {
            p0[i] = i + 39;
        }
        cout << " " << p0[i] << endl;
    }
    cout << endl;
    for (int i = 0; i < tsize_x; i++)
    {
        if (i < 26)
        {
            p0[i] = i + 97;
        }
        if (i >= 26)
        {
            p0[i] = i + 39;
        }
        cout << p0[i];
    }
    cout << endl << endl;
}
void rayTableClear()
{
    for (int i = 0; i < tsize_y; i++)
    {
        for (int j = 0; j < tsize_x; j++)
        {
            rayTable[i][j] = '.';
        }
    }
}
void rayDraw(COORD rayOrigin, short rayDirection)
{
    COORD rayCursor = rayOrigin;

    switch (rayDirection)
    {
    case 2:
        {
            while (rayCursor.Y < tsize_y)
            {
                if (rayTable[rayCursor.Y][rayCursor.X] == '.')
                {
                    rayTable[rayCursor.Y][rayCursor.X] = '1';
                }
                else
                {
                    rayTable[rayCursor.Y][rayCursor.X] += 1;
                }
                rayCursor.Y++;
            }
            break;
        }
    case 4:
        {
            while (rayCursor.X >= 0)
            {
                if (rayTable[rayCursor.Y][rayCursor.X] == '.')
                {
                    rayTable[rayCursor.Y][rayCursor.X] = '1';
                }
                else
                {
                    rayTable[rayCursor.Y][rayCursor.X] += 1;
                }
                rayCursor.X--;
            }
            break;
        }
    case 6:
        {
            while (rayCursor.X < tsize_x)
            {
                if (rayTable[rayCursor.Y][rayCursor.X] == '.')
                {
                    rayTable[rayCursor.Y][rayCursor.X] = '1';
                }
                else
                {
                    rayTable[rayCursor.Y][rayCursor.X] += 1;
                }
                rayCursor.X++;
            }
            break;
        }
    case 8:
        {
            while (rayCursor.Y >= 0)
            {
                if (rayTable[rayCursor.Y][rayCursor.X] == '.')
                {
                    rayTable[rayCursor.Y][rayCursor.X] = '1';
                }
                else
                {
                    rayTable[rayCursor.Y][rayCursor.X] += 1;
                }
                rayCursor.Y--;
            }
            break;
        }
    case 1:
        {
            while (rayCursor.Y < tsize_y && rayCursor.X >= 0)
            {
                if (rayTable[rayCursor.Y][rayCursor.X] == '.')
                {
                    rayTable[rayCursor.Y][rayCursor.X] = '1';
                }
                else
                {
                    rayTable[rayCursor.Y][rayCursor.X] += 1;
                }
                rayCursor.Y++;
                rayCursor.X--;
            }
            break;
        }
    case 3:
        {
            while (rayCursor.Y < tsize_y && rayCursor.X < tsize_x)
            {
                if (rayTable[rayCursor.Y][rayCursor.X] == '.')
                {
                    rayTable[rayCursor.Y][rayCursor.X] = '1';
                }
                else
                {
                    rayTable[rayCursor.Y][rayCursor.X] += 1;
                }
                rayCursor.Y++;
                rayCursor.X++;
            }
            break;
        }
    case 7:
        {
            while (rayCursor.Y >= 0 && rayCursor.X >= 0)
            {
                if (rayTable[rayCursor.Y][rayCursor.X] == '.')
                {
                    rayTable[rayCursor.Y][rayCursor.X] = '1';
                }
                else
                {
                    rayTable[rayCursor.Y][rayCursor.X] += 1;
                }
                rayCursor.Y--;
                rayCursor.X--;
            }
            break;
        }
    case 9:
        {
            while (rayCursor.Y >= 0 && rayCursor.X < tsize_x)
            {
                if (rayTable[rayCursor.Y][rayCursor.X] == '.')
                {
                    rayTable[rayCursor.Y][rayCursor.X] = '1';
                }
                else
                {
                    rayTable[rayCursor.Y][rayCursor.X] += 1;
                }
                rayCursor.Y--;
                rayCursor.X++;
            }
            break;
        }
    default:
        {
        }
    }
}
int main()
{
	const WORD colors[] =
		{
		0x1A, 0x2B, 0x3C, 0x4D, 0x5E, 0x6F,
		0xA1, 0xB2, 0xC3, 0xD4, 0xE5, 0xF6
		};

	HANDLE hstdin  = GetStdHandle( STD_INPUT_HANDLE  );
	HANDLE hstdout = GetStdHandle( STD_OUTPUT_HANDLE );
	WORD   index   = 0;

	// Remember how things were when we started
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo( hstdout, &csbi );

	// Tell the user how to stop
	SetConsoleTextAttribute( hstdout, 0xEC );
	std::cout << "Press any key to quit.\n";

	// Draw pretty colors until the user presses any key
	while (WaitForSingleObject( hstdin, 100 ) == WAIT_TIMEOUT)
	{
		SetConsoleTextAttribute( hstdout, colors[ index ] );
		std::cout << "\t\t\t\t Hello World \t\t\t\t" << std::endl;
		if (++index > sizeof(colors)/sizeof(colors[0]))
			index = 0;
	}
	FlushConsoleInputBuffer( hstdin );

	// Keep users happy
	SetConsoleTextAttribute( hstdout, csbi.wAttributes );
	return 0;
}
/*int main()
{
    string xIn,yIn,rayDirectionIn;
    int rayDirection;
    COORD cursorPos1,cursorPos2,rayTableIndex;

    rayTableClear();
    rayTablePrint();
    cursorPos1 = getCoord();
    for(int j = 0; j == 0;)
    {
        char temp;
        do
        {
            cout << "Podaj wspolrzedna x: ";
            xIn = getch();
            cout << xIn << endl;
            cout << "Podaj wspolrzedna y: ";
            yIn = getch();
            cout << yIn << endl;
            cursorPos2 = getCoord();
            rayTableIndex = strToIndex(xIn, yIn);
            if(rayTableIndex.X == -1 || rayTableIndex.Y == -1)
            {
                gotoCoord(cursorPos1);
                for(int i = 0; i < 400; i++)
                {
                    cout << " ";
                }
                gotoCoord(cursorPos1);
                cout << endl << "Podano zla wartosc!" << endl;
            }
        }
        while(rayTableIndex.X == -1 || rayTableIndex.Y == -1);
        temp = rayTable[rayTableIndex.Y][rayTableIndex.X];
        rayTable[rayTableIndex.Y][rayTableIndex.X] = '*';
        gotoxy(0,0);
        rayTablePrint();
        rayTable[rayTableIndex.Y][rayTableIndex.X] = temp;
        gotoCoord(cursorPos2);
        cout << "W jakim kierunku skierowac laser? ";
        rayDirectionIn = getch();
        cout << rayDirectionIn << endl;
        rayDirection = validation(rayDirectionIn);
        rayDraw(rayTableIndex, rayDirection);
        if (rayTable[rayTableIndex.Y][rayTableIndex.X] == '*')
        {
            rayTable[rayTableIndex.Y][rayTableIndex.X] = temp;
        }
        gotoxy(0,0);
        rayTablePrint();
        for(int i = 0; i < 400; i++)
        {
            cout << " ";
        }
        gotoCoord(cursorPos1);
    }
    return 0;
}*/
