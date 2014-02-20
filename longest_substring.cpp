#include <cstdio>
#include <cstdlib>

#define MAXLEN 5000

int n;
int a[MAXLEN], f[MAXLEN], g[MAXLEN];

inline int max(int a, int b)
{
    if (a > b) {
        return a;
    }
    return b;
}

int main(int argc, char *argv[])
{
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }

    int ans1, ans2;
    ans1 = ans2 = 0;

    for (int i = 0; i < n; ++i) {
        f[i] = 1;
        for (int j = 0; j < i; ++j) {
            if (a[i] > a[j]) {
                f[i] = max(f[i], f[j] + 1);
            }
        }
        ans1 = max(ans1, f[i]);
    }

    for (int i = n - 1; i >= 0; --i) {
        g[i] = 1;
        for (int j = i + 1; j < n; ++j) {
            if (a[i] > a[j]) {
                g[i] = max(g[i], g[j] + 1);
            }
        }
        ans2 = max(ans2, f[i] + g[i] - 1);
    }

    printf("%d %d\n", ans1, ans2);
    
    return 0;
}
