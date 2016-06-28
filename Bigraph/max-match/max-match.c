#include <stdio.h>
#include <string.h>

typedef enum {false, true} bool;

int n1, n2, m, ans;
int result[101];//记录V2中的点匹配V1中的点的编号
bool state[101];//记录V2中的每个点是否被搜索过
bool data[101][101];//邻接矩阵true代表有边相连

bool init()
{
    memset(data, 0, sizeof(data));
    memset(result, 0, sizeof(result));
    ans = 0;
    bool isEnd = scanf("%d %d %d", &n1, &n2, &m) == EOF;
    if (isEnd) {
        return false;
    }
    printf("----%d %d %d\n", n1, n2, m);
    int t1, t2, i;
    for(i = 1; i <= m; i++)
    {
        scanf("%d %d", &t1, &t2);
        printf("%d %d\n", t1, t2);
        data[t1][t2] = true;
    }

    return true;
}

bool find(int a)
{
    int i;
    for(i = 1; i <= n2; i++)
    {
        if(data[a][i] && !state[i]) //如果节点i与a相邻并且未被查找过
        {
            state[i] = true; //标记i为已查找过

            if(result[i] == 0 //如果i未在前一个匹配M中
                || find(result[i])) //i在匹配M中，但是从与i相邻的节点出发可以有增广路
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
    int i;
    while(init()) {        
        for(i = 1; i <= n1; i++)
        {
            memset(state, 0, sizeof(state)); //清空上次搜索时的标记
            if(find(i))
            {
                ans++;    //从节点i尝试扩展
            }
        }

        printf("%d\n", ans);
        printf("match result:V1-V2\n");
        for(i = 1; i <= n2; i++)
        {
            if (result[i] != 0) {
                printf("%d-%d ", result[i], i);
            }
        }
        printf("\n");
    }
        
    return 0;
}