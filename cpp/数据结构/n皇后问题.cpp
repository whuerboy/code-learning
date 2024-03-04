
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int n, tot = 0;
int col[15] = { 0 }, ans[15] = { 0 }; //col[i]��ֵΪ��i�еĻʺ��������ֵ����j,ans[]����������Ž��

bool check(int c, int r) //����Ƿ���Ѿ��źõĻʺ��ͻ
{
    for (int i = 0; i < r; i++)
        if (col[i] == c || (abs(col[i] - c) == abs(i - r))) //��Ϊ�����з��ã�����ֻ���������б��
            return false;
    return true;
}

void dfs(int r, int m)  //�ڵ�r�зŻʺ�,m��ʾ����
{
    if (r == m) {    //r==m,���ʺ�ŵ����һ�У�����������tot++,����;
        tot++;
        return;
    }

    for (int c = 0; c < m; c++) //�ڴ������г���
        if (check(c, r)) {   //����Ƿ��ͻ
            col[r] = c;       //����ͻ���ڴ��зŻʺ�
            dfs(r + 1, m);     //ת����һ�м�������
        }
}

int main50()
{
    cin >> n;
    for (int i = 0; i <= 13; i++) //�������N�ʺ�Ĵ𰸣��ȴ����Ȼ�ᳬʱ
    {
        memset(col, 0, sizeof(col)); //���col��׼��������һ��N�ʺ�����
        tot = 0;
        dfs(0, i);
        ans[i] = tot;
    }

    cout << ans[n] << endl;

    return 0;
}