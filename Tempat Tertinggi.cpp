#include <iostream>

using namespace std;

char layout [30][30];
int row,column;

void fallFunction(int,int);

int main()
{
    int testCase;

    cin >> testCase;

    for (int i = 0; i<testCase;i++)
    {
        cin >> row;
        cin>>  column;
        for (int j = 0; j < row;j++)
        {
            for (int k = 0;k<column;k++)
            {
                layout[j][k]= 'x';
            }
        }
        for (int j = 0; j< row;j++)
        {
            for (int k = 0; k < column; k++)
            {
                cin >> layout[j][k];
            }
        }
        for (int j = row-1;j>=0;j--)
        {
            for (int k = column -1;k>=0;k--)
            {
                if (layout[j][k]=='*')
                {
                    fallFunction(j,k);
                }
            }
        }

        for (int j = 0; j<row;j++)
        {
            for (int k = 0; k < column;k++)
            {
                cout << layout[j][k];
            }
            cout << endl;
        }

    }
}

void fallFunction(int x, int y) {
    if (x + 1 == row) {
        return;
    }

    if ((layout[x+1][y] == 'o') || (layout[x+1][y] == '*')) {
        return;
    }

    layout[x][y] = '.';
    layout[x+1][y] = '*';
    fallFunction(x+1, y);
}
