#include<iostream>
#include<cstring>
using namespace std;
//定义链表
class link
{
public:
    int data;//存放数据
    link* next;//指向下一个节点
    link(int n=0);
};
link::link(int n)
{
    data=n;
    next=NULL;
}

void clear(link *base) {
    link *linkp, *nextp;
    for (linkp = base; linkp != NULL; linkp = nextp) {
        nextp = linkp->next;
        // printf("clear node:%d\n", linkp->data);
        delete linkp;
    }
}

int n1,n2,m,ans=0;
int result[101];//记录n2中的点匹配的点的编号
bool state[101];//记录n2中的每个点是否被搜索过
link* head[101];//记录n1中的点的邻接节点
link* last[101];//邻接表的终止位置记录

//判断能否找到从节点n开始的增广路
bool find(const int n)
{
    link* t=head[n];
    while(t!=NULL) //n仍有未查找的邻接节点时
    {
        if(!(state[t->data])) //如果邻接点t->data未被查找过
        {
            state[t->data]=true;//标记t->data为已经被找过
            if((result[t->data]==0)||//如果t->data不属于前一个匹配M
                    (find(result[t->data]))) //如果t->data匹配到的节点可以寻找到增广路
            {
                result[t->data]=n;//那么可以更新匹配M'，其中n2中的点t->data匹配n
                return true;//返回匹配成功的标志
            }
        }
        t=t->next;//继续查找下一个n的邻接节点
    }
    return false;
}

int main()
{
    while(cin >> n1 >> n2 >> m)
    {
        // init data
        ans = 0;
        memset(result, 0, sizeof(result));
        int t1=0,t2=0;
        for(int i=0; i<m; i++)
        {
            cin>>t1>>t2;
            if(last[t1]==NULL)
                last[t1]=head[t1]=new link(t2);
            else
                last[t1]=last[t1]->next=new link(t2);
        }

        // find max match
        for(int i=1; i<=n1; i++)
        {
            memset(state,0,sizeof(state));
            if(find(i))ans++;
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
        
        // free space
        for (int i = 1; i <= n1; i++)
        {
            clear(head[i]);
            head[i] = NULL;
            last[i] = NULL;
        }
    }
        
    return 0;
}