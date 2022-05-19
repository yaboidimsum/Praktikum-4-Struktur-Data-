#include <iostream>
#include <array>
#include <list>
#include <queue>

using namespace std;

int _size, found = 0;

array<array<int,50>,50> layout;
array<array<int,50>,50> visited;

int start_x, start_y;

void start_position();
void traverse(int,int);


int main()
{
    cin >> _size;
    for (int i = 0; i <= _size ; i++)
    {
        layout[i].fill(-1);
        visited[i].fill(0);
    }
    for (int i = 0; i < _size;i++)
    {
        for(int j=0; j < _size; j++)
        {
            cin >> layout [i][j];
        }
    }

    start_position();
    traverse(start_x,start_y);

    if (found)
    {
        cout << "yey" << endl;
    }
    else
    {
        cout << "yah" << endl;
    }

}

void start_position()
{
    for (int i = 0; i < _size; i++)
    {
        for (int j = 0; j < _size; j++)
        {
            if (layout [i][j]==2)
            {
                start_x = i;
                start_y = j;
                return;
            }
        }
    }
    return;
}

void traverse (int x, int y)
{
    if( (x<0)||(y<0))
    {
        return;
    }
    if(visited[x][y])
    {
        return;
    }
    if(layout[x][y]==-1)
    {
        return;
    }
    if( layout[x][y]==1)
    {
        return;
    }
    if( layout[x][y]==3)
    {
        found = 1;
        return;
    }


    visited[x][y] = 1;
    traverse(x-1,y); //traverse atas
    traverse(x+1,y); //traverse bawah
    traverse(x,y-1); //traverse kiri
    traverse(x,y+1); //traverse kanan

}
