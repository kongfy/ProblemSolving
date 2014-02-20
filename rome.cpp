#include <stdio.h>

#define MAX 21

unsigned int f[MAX][MAX];
bool map[MAX][MAX];
int n, m, k;

int main(int argc, char *argv[])
{
    // input
    scanf("%d %d", &n, &m);
    scanf("%d", &k);
    for (int i = 0; i < k; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);

        map[x][y] = true;
    }

    // dp
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {

            // border
            if (i == 1 && j == 1) {
                f[i][j] = 1;
                continue;
            }

            // barrier
            if (map[i][j]) {
                f[i][j] = 0;
                continue;
            }

            f[i][j] = f[i-1][j] + f[i][j-1];
        }
    }

    printf("%d\n", f[n][m]);
    
    return 0;
}
