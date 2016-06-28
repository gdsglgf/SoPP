#include<iostream>
#include<cstring>
using namespace std;

bool data[101][101]; //邻接矩阵true代表有边相连
bool visit[101];//记录V2中的每个点是否被搜索过
int result[101];//记录V2中的点匹配V1中的点的编号
int n1, n2, m;

bool dfs(int a)
{
    for(int i=1; i<=n2; i++)
    {
        if(data[a][i]&&!visit[i])    //如果节点i与a相邻并且未被查找过
        {
            visit[i]=true;  //标记i为已查找过
            if(result[i] == 0 //如果i未在前一个匹配M中
                || dfs(result[i])) //i在匹配M中，但是从与i相邻的节点出发可以有增广路
            {
                result[i] = a; //记录查找成功记录
                return true;//返回查找成功
            }
        }
    }
    return false;
}

int main()
{
    while(cin >> n1 >> n2 >> m)
    {
        // init data
        memset(data,0,sizeof(data));
        int x,y;
        for(int i=1; i<=m; i++)
        {
            cin>>x>>y;
            data[x][y]=true;
        }
        memset(result,0,sizeof(result));

        // find max match
        int ans=0;
        for(int i=1; i<=n1; i++)
        {
            memset(visit,0,sizeof(visit)); //清空上次搜索时的标记
            if(dfs(i))ans++;
        }

        // show result
        cout<<ans<<endl;
        cout << "match result:V1-V2" << endl;
        for (int i = 1; i <= n2; ++i)
        {
            if (result[i] != 0) {
                cout << result[i] << "-" << i << " ";
            }
        }
        cout << endl;
    }
    return 0;
}