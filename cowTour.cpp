/*
  ID: 31440461
  PROG: cowtour
  LANG: C++
*/

#include <cmath>
#include <cstdlib>
#include <cstdio>

struct point
{
    int x, y;
};

point pastures[150];
int n;
double map[150][150];
double diameter[150];
double block_diameter[150];

#define INF 1e20

double distance(int a, int b)
{
    int dx = abs(pastures[a].x - pastures[b].x);
    int dy = abs(pastures[a].y - pastures[b].y);
    return sqrt(dx * dx + dy * dy);
}

inline double max(double a, double b)
{
    if (a > b) {
        return a;
    }
    return b;
}

inline double min(double a, double b)
{
    if (a < b) {
        return a;
    }
    return b;
}

void floyd()
{
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
            }
        }
    }
}

int main(int argc, char *argv[])
{
    // FILE *fin, *fout;

    // fin = fopen("cowtour.in", "r");
    // fout = fopen("cowtour.out", "w");

    scanf("%d\n", &n);
    //fscanf(fin, "%d\n", &n);
    for (int i = 0; i < n; ++i) {
        int x, y;
        scanf("%d %d\n", &x, &y);
        //fscanf(fin, "%d %d\n", &x, &y);
        pastures[i].x = x;
        pastures[i].y = y;
    }

    char c;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            c = getchar();
            //c = getc(fin);
            if (c == '0') {
                map[i][j] = INF;
            } else {
                map[i][j] = distance(i, j);
            }
            if (i == j) {
                map[i][j] = 0;
            }
        }
        c = getchar();
        //c = getc(fin);
    }

    floyd();

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (map[i][j] != INF && map[i][j] > diameter[i]) {
                diameter[i] = map[i][j];
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (map[i][j] != INF) {
                block_diameter[i] = max(block_diameter[i], diameter[i]);
                block_diameter[i] = max(block_diameter[i], diameter[j]);
            }
        }
    }

    double temp = INF;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (map[i][j] == INF) {
                temp = min(temp, distance(i, j) + diameter[i] + diameter[j]);
                temp = max(temp, block_diameter[i]);
                temp = max(temp, block_diameter[j]);
            }
        }
    }

    printf("%0.6f\n", temp);
    //fprintf(fout, "%0.6f\n", temp);
    
    return 0;
}
