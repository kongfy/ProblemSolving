#include<stdio.h>

char a[1000005], b[10005];
int next[10005];

void getnext()
{
    int i, j;
    next[0] = 0;
    i = 1;
    j = 0;
    for(; b[i]; i++) {
        while (j > 0 && b[i] != b[j]) {
            j = next[j-1];
        }
        if (b[i] == b[j]) {
            j++;
        }
        next[i]=j;
    }
}

int kmp()
{
    int ans, i, j;
    i = j = ans = 0;
    for(; a[i]; i++) {
        while (j > 0 && a[i]!= b[j]) {
            j = next[j-1];
        }
        if (a[i] == b[j]) {
            j++;
            if (!b[j]) {
                j = next[j - 1];
                ans++;
            }
        }
    }
    return ans;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%s%s", b, a);
        getnext();
        printf("%d\n", kmp());
    }
    return 0;
}
