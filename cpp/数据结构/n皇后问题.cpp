
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int n, tot = 0;
int col[15] = { 0 }, ans[15] = { 0 }; //col[i]的值为第i行的皇后的列数的值，即j,ans[]数组用来存放结果

bool check(int c, int r) //检查是否和已经放好的皇后冲突
{
    for (int i = 0; i < r; i++)
        if (col[i] == c || (abs(col[i] - c) == abs(i - r))) //因为是逐行放置，所以只考虑纵向和斜向
            return false;
    return true;
}

void dfs(int r, int m)  //在第r行放皇后,m表示行数
{
    if (r == m) {    //r==m,即皇后放到最后一行，满足条件，tot++,返回;
        tot++;
        return;
    }

    for (int c = 0; c < m; c++) //在此行逐列尝试
        if (check(c, r)) {   //检查是否冲突
            col[r] = c;       //不冲突就在此列放皇后
            dfs(r + 1, m);     //转到下一行继续尝试
        }
}

int main50()
{
    cin >> n;
    for (int i = 0; i <= 13; i++) //算出所有N皇后的答案，先打表，不然会超时
    {
        memset(col, 0, sizeof(col)); //清空col，准备计算下一个N皇后问题
        tot = 0;
        dfs(0, i);
        ans[i] = tot;
    }

    cout << ans[n] << endl;

    return 0;
}