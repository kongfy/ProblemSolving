#include <iostream>

using namespace std;

int map[1001][1001];
int travel_distance[1001];
bool mark[1001];
int t, n;

#define MAX 10000000

void initMap(int n)
{
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= 1000; ++j) {
            map[i][j] = MAX;
        }
    }
}

void initDistance(int n, int src)
{
    for (int i = 1; i <= n; ++i) {
        travel_distance[i] = map[src][i];
    }
}

void initMark(int n, int src)
{
    for (int i = 1; i <= n; ++i) {
        mark[i] = false;
    }
}

void dijkstra(int src)
{
    initMark(n, n);
    initDistance(n, n);

    for (int i = 0; i < n; ++i) {
        int tmp, min = MAX;
        for (int j = 1; j <= n; ++j) {
            if (!mark[j] && travel_distance[j] < min) {
                tmp = j;
                min = travel_distance[j];
            }
        }
        
        mark[tmp] = true;
        for (int j = 1; j <= n; ++j) {
            if (travel_distance[tmp] + map[tmp][j] < travel_distance[j]) {
                travel_distance[j] = travel_distance[tmp] + map[tmp][j];
            }
        }
    }
    return;
}

int main(int argc, char *argv[])
{
    cin >> t >> n;
    
    initMap(n);
    
    for (int i = 0; i < t; ++i) {
        int src, dst, cost;

        cin >> src >> dst >> cost;
        if (cost < map[src][dst]) {
            map[src][dst] = map[dst][src] = cost;
        }
    }

    dijkstra(n);

    cout << travel_distance[1] << endl;
    return 0;
}

