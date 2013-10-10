/*
  ID: 31440461
  PROG: ditch
  LANG: C++
*/

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

int exist_path_with_extra_flow(int src)
{
    if (src == m) {
        return 0;
    }
    
    flag[src] = true;
    for (int i = 1; i <= m; ++i) {
        if (flag[i]) continue;
        if (map[src][i] > 0) {
            int flow_left = map[src][i] - flow[src][i];
            if (flow_left > 0) {
                int temp = exist_path_with_extra_flow(i);
                if (temp >= 0) {
                    mark[src][i] = true;
                    if (temp == 0) temp = flow_left;
                    return min(flow_left, temp);
                }
            }
        }
        if (flow[i][src] > 0) {
            int temp = exist_path_with_extra_flow(i);
            if (temp > 0) {
                reverse_mark[i][src] = true;
                return min(flow[i][src], temp);
            }
        }
    }
    return -1;
}

int main(int argc, char *argv[])
{
    // FILE *fin, *fout;

    // fin = fopen("ditch.in", "r");
    // fout = fopen("ditch.out", "w");
    
    // fscanf(fin, "%d %d", &n, &m);
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; ++i) {
        int s, e, c;
        //fscanf(fin, "%d %d %d", &s, &e, &c);
        scanf("%d %d %d", &s, &e, &c);

        map[s][e] += c;
    }

    int result = 0;
    while (true) {
        int temp = exist_path_with_extra_flow(1);
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

    //fprintf(fout, "%d\n", result);
    printf("%d\n", result);

    return 0;
}
