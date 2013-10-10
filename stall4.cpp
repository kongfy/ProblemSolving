/*
  ID: 31440461
  PROG: stall4
  LANG: C++
*/

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std ;


int map[201][201];
int match[201];
bool flag[201];
int n, m;

bool existCrossPath(int cow)
{
    for (int i = 1; i <= map[cow][0]; ++i) {
        int stall = map[cow][i];

        if (flag[stall]) {
            continue;
        }

        flag[stall] = true;
        if (!match[stall] || existCrossPath(match[stall])) {
            match[stall] = cow;
            return true;
        }
    }
    return false;
}

int main(int argc, char *argv[])
{
    // ifstream fin("stall4.in");
    // ofstream fout("stall4.out");

    //fin >> n >> m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        int num, stall;
        //fin >> num;
        cin >> num;
        map[i][0] = num;
        for (int j = 1; j <= num; ++j) {
            //fin >> stall;
            cin >> stall;
            map[i][j] = stall;
        }
    }

    int result = 0;
    for (int i = 1; i <= n; ++i) {
        if (existCrossPath(i)) {
            result++;
        }
        memset(flag, false, sizeof(flag));
    }

    //fout << result << endl;
    cout << result << endl;

    // fin.close();
    // fout.close();
    
    return 0;
}

