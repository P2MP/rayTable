#include <iostream>
#include <string>
#include <sstream>


using namespace std;

const short tsize_x = 20;
const short tsize_y = 20;
string rayTable[tsize_y][tsize_x];


int validation(string convert)
{
    int i;
    stringstream ss(convert);
    ss >> i;
    if(ss.fail())
    {
        return 0;
    }
    else
    {
        return i;
    }

}


void rayTablePrint()
{
    for (int i = 0; i < tsize_y; i++)
    {
        for (int j = 0; j < tsize_x; j++)
        {
            cout << rayTable[i][j];
        }
        cout << " " << i << endl;
    }
    cout << endl;
    if (tsize_x <= 10)
    {
        for (int i = 0; i < tsize_y; i++)
        {
            cout << i;
        }
        cout << endl;
    }
    else
    {
        cout << "0123456789";
        //for (int i = 0;)
    }
}

void rayTableClear()
{
    for (int i = 0; i < tsize_y; i++)
    {
        for (int j = 0; j < tsize_x; j++)
        {
            rayTable[i][j] = '0';
        }
    }

}

int main()
{
    rayTableClear();
    rayTablePrint();
    return 0;
}
