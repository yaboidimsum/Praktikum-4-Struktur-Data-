#include <iostream>
#include <list>
#include <array>

using namespace std;

array <int,1000> visited;
list <int> adjList[1000];

void DFS(int);


int main()
{
    int vertex,pair_vertex,total_graph = 0;
    visited.fill(0);

    cin >> vertex;
    cin >> pair_vertex;

    for (int i = 0; i < pair_vertex ; i++)
    {
        int A,B;

        cin >> A;
        cin >> B;

        adjList[A].push_back(B);
        adjList[B].push_back(A);

    }

    for (int i = 1; i<= vertex;i++)
    {
        if (!visited[i])
        {
            DFS(i);
            total_graph++;
        }
    }
    cout << --total_graph << endl;
}


void DFS(int startVertex)
{
    visited[startVertex] = 1;
    for (auto i = adjList[startVertex].begin() ; i != adjList[startVertex].end() ; ++i)
    {
        int curVertex=*i;
        if (!visited[curVertex])
        {
           DFS(curVertex);
        }
    }
}
