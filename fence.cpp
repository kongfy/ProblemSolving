/*
  ID: 31440461
  PROG: fence
  LANG: C++
*/

#include <cstdio>
#include <cstring>

int f;
int map[501][501];
int max;
bool color[501];
//FILE *fin, *fout;

int find_start_point()
{
    for (int i = 1; i <= max; ++i) {
        if (map[i][0] % 2 == 1) {
            return i;
        }
    }
    return 1;
}

void del_edge(int u, int v)
{
    map[u][0]--;
    map[v][0]--;
    map[u][v]--;
    map[v][u]--;
}

void add_edge(int u, int v)
{
    map[u][0]++;
    map[v][0]++;
    map[u][v]++;
    map[v][u]++;
}

void fill(int v)
{
    if (color[v]) return;
    color[v] = true;

    for (int i = 1; i <= max; ++i) {
        if (map[v][i] > 0) {
            fill(i);
        }
    }
}

bool is_bridge(int u, int v)
{
    bool result = false;
    
    del_edge(u, v);

    memset(color, false, sizeof(color));
    fill(u);
    if (!color[v]) {
        result = true;
    }
    
    add_edge(u, v);
    return result;
}

void travel(int v)
{
    //fprintf(fout, "%d\n", v);
    printf("%d\n", v);
            
    if (!map[v][0]) return;

    for (int i = 1; i <= max; ++i) {
        if (map[v][i] > 0) {
            if (1 == map[v][0]) {
                del_edge(v, i);
                travel(i);
            } else {
                if (!is_bridge(v, i)) {
                    del_edge(v, i);
                    travel(i);
                }
            }
        }
    }
}

int main(int argc, char *argv[])
{
    // fin = fopen("fence.in", "r");
    // fout = fopen("fence.out", "w");
    
    // fscanf(fin, "%d", &f);
    scanf("%d", &f);

    for (int i = 0; i < f; ++i) {
        int s, t;
        
        //fscanf(fin, "%d %d", &s, &t);
        scanf ("%d %d", &s, &t);
        
        add_edge(s, t);
        if (s > max) max = s;
        if (t > max) max = t;
    }

    travel(find_start_point());

    // fclose(fin);
    // fclose(fout);
    
    return 0;
}
