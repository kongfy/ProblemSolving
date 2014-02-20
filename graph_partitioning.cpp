#include <cstdio>
#include <cstring>

int n, m;
int map[201][201];
int flow[201][201];
bool flag[201];
bool mark[201][201];
bool reverse_mark[201][201];

int min(int a, int b)
{
    if (a < b) return a;
    return b;
}

int exist_path_with_extra_flow(int src, int dst)
{
    if (src == dst) {
        return 0;
    }
    
    flag[src] = true;
    for (int i = 1; i <= m; ++i) {
        if (flag[i]) continue;
        if (map[src][i] > 0) {
            int flow_left = map[src][i] - flow[src][i];
            if (flow_left > 0) {
                int temp = exist_path_with_extra_flow(i, dst);
                if (temp >= 0) {
                    mark[src][i] = true;
                    if (temp == 0) temp = flow_left;
                    return min(flow_left, temp);
                }
            }
        }
        if (flow[i][src] > 0) {
            int temp = exist_path_with_extra_flow(i, dst);
            if (temp > 0) {
                reverse_mark[i][src] = true;
                return min(flow[i][src], temp);
            }
        }
    }
    return -1;
}

int edmonds_karp(int src, int dst)
{
    int result = 0;

    // do some clean jobs
    memset(flow, 0, sizeof(flow));
    memset(flag, false, sizeof(flag));
    
    while (true) {
        int temp = exist_path_with_extra_flow(src, dst);
        if (temp > 0) {
            for (int i = 1; i <= m; ++i) {
                for (int j = 1; j <= m; ++j) {
                    if (mark[i][j]) {
                        flow[i][j] += temp;
                        mark[i][j] = false;
                    }
                    if (reverse_mark[i][j]) {
                        flow[i][j] -= temp;
                        reverse_mark[i][j] = false;
                    }
                }
            }
            result += temp;
            memset(flag, false, sizeof(flag));
        } else {
            break;
        }
    }
    return result;
}

int main(int argc, char *argv[])
{
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);

        map[a][b] += 1;
        map[b][a] += 1;
    }

    int mincut = 0x7fffffff;
    for (int i = 2; i <= m; ++i) {
        int temp = edmonds_karp(1, i);
        mincut = min(mincut, temp);
        if (mincut == 0) {
            break;
        }
    }

    printf("%d\n", mincut);
    return 0;
}
