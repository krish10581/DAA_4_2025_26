#include <iostream>
#include <climits>
using namespace std;

int graph[10][10], visited[10], n, cost = 0;

void tsp(int city)
{
    int nextCity = -1;
    int minDist = INT_MAX;

    visited[city] = 1;
    cout << city + 1 << " -> ";

    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && graph[city][i] < minDist && graph[city][i] != 0)
        {
            minDist = graph[city][i];
            nextCity = i;
        }
    }

    if (nextCity == -1)
    {
        for (int i = 0; i < n; i++)
        {
            if (graph[city][i] != 0)
            {
                cost += graph[city][0];
                cout << "1";
                return;
            }
        }
    }

    cost += minDist;
    tsp(nextCity);
}

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			cin >> graph[i][j];
		}    
	}
    
    for (int i = 0; i < n; i++){
		visited[i] = 0;
	}
    tsp(0);
    cout << "\nMinimum Cost: " << cost;

    return 0;
}