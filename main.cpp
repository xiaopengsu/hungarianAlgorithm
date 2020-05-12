//这就是匈牙利算法的流程，至于具体实现，我们来看看代码： https://zhuanlan.zhihu.com/p/96229700


//int M, N;            //M, N分别表示左、右侧集合的元素数量
//int Map[MAXM][MAXN]; //邻接矩阵存图
//int p[MAXN];         //记录当前右侧元素所对应的左侧元素
//bool vis[MAXN];      //记录右侧元素是否已被访问过
//bool match(int i)
//{
//    for (int j = 1; j <= N; ++j)
//        if (Map[i][j] && !vis[j]) //有边且未访问
//        {
//            vis[j] = true;                 //记录状态为访问过
//            if (p[j] == 0 || match(p[j])) //如果暂无匹配，或者原来匹配的左侧元素可以找到新的匹配
//            {
//                p[j] = i;    //当前左侧元素成为当前右侧元素的新匹配
//                return true; //返回匹配成功
//            }
//        }
//    return false; //循环结束，仍未找到匹配，返回匹配失败
//}
//int Hungarian()
//{
//    int cnt = 0;
//    for (int i = 1; i <= M; ++i)
//    {
//        memset(vis, 0, sizeof(vis)); //重置vis数组
//        if (match(i))
//            cnt++;
//    }
//    return cnt;
//}





//#include <cstdio>
//#include <cstring>
//int Map[205][205], p[205], vis[205], N, T;
//bool match(int i)
//{
//    for (int j = 1; j <= N; ++j)
//    {
//        if (Map[i][j] && !vis[j])
//        {
//            vis[j] = 1;
//            if (p[j] == 0 || match(p[j]))
//            {
//                p[j] = i;
//                return true;
//            }
//        }
//    }
//    return false;
//}
//int Hungarian()
//{
//    int cnt = 0;
//    for (int i = 1; i <= N; ++i)
//    {
//        memset(vis, 0, sizeof(vis));
//        if (match(i))
//            cnt++;
//    }
//    return cnt;
//}
//int main()
//{
//    scanf("%d", &T);
//    while (T--)
//    {
//        scanf("%d", &N);
//        memset(p, 0, sizeof(p));
//        for (int i = 1; i <= N; ++i)
//            for (int j = 1; j <= N; ++j)
//                scanf("%d", &Map[i][j]);
//        puts(Hungarian() == N ? "Yes" : "No");
//    }
//    return 0;
//}

//
//
//#include <cstdio>
//#include <cstring>
//#define MAXN 500
//struct Edges
//{
//    int to, next;
//} edges[MAXN * 8];
//int Map[105][105], head[MAXN], p[MAXN], vis[MAXN], N, cnt_edge;
//inline int add(int from, int to)
//{
//    edges[++cnt_edge].next = head[from];
//    head[from] = cnt_edge;
//    edges[cnt_edge].to = to;
//}
//inline int trans(int i, int j, int n) //把坐标转化为编号
//{
//    return ((i - 1) * n + j + 1) / 2;
//}
//bool match(int i)
//{
//    for (int e = head[i]; e; e = edges[e].next)
//    {
//        int j = edges[e].to;
//        if (!vis[j])
//        {
//            vis[j] = true;
//            if (p[j] == 0 || match(p[j]))
//            {
//                p[j] = i;
//                return true;
//            }
//        }
//    }
//    return false;
//}
//int Hungarian()
//{
//    int cnt = 0;
//    for (int i = 1; i <= N; ++i)
//    {
//        memset(vis, 0, sizeof(vis));
//        if (match(i))
//            cnt++;
//    }
//    return cnt;
//}
//int main()
//{
//    int n, m, x, y;
//    scanf("%d%d", &n, &m);
//    N = (n * n + 1) / 2;
//    memset(Map, -1, sizeof(Map));
//    for (int i = 1; i <= n; ++i)
//        for (int j = 1; j <= n; ++j)
//            Map[i][j] = 0;
//    for (int i = 0; i < m; ++i)
//    {
//        scanf("%d%d", &x, &y);
//        Map[x][y] = -1;
//    }
//    for (int i = 1; i <= n; i++)
//        for (int j = i % 2 ? 1 : 2; j <= n; j += 2)
//            if (Map[i][j] == 0)
//            {
//                if (Map[i + 1][j] != -1)
//                    add(trans(i, j, n), trans(i + 1, j, n));
//                if (Map[i][j + 1] != -1)
//                    add(trans(i, j, n), trans(i, j + 1, n));
//                if (Map[i - 1][j] != -1)
//                    add(trans(i, j, n), trans(i - 1, j, n));
//                if (Map[i][j - 1] != -1)
//                    add(trans(i, j, n), trans(i, j - 1, n));
//            }
//    printf("%d\n", Hungarian());
//    return 0;
//}


//
//
//// ok_sxp
//// http://www.cppblog.com/chgsh8089/archive/2007/03/12/13205.html
//#include <iostream>
//#include <fstream>
//#include <cstdio>
//#include <cstring>
//using namespace std;
//
//const int MAXN = 10;
//int uN, vN;
//bool g[MAXN][MAXN];//g[i][j] 表示 xi与yj相连
//int xM[MAXN], yM[MAXN]; // 输出量
//bool chk[MAXN]; //辅助量 检查某轮 y[v]是否被check
//
//
//
//bool SearchPath(int u)
//{
//    int v;
//    for (v=0; v<vN; v++)
//    {
//        if (g[u][v] && !chk[v])
//        {
//            chk[v] = true;
//            if (yM[v] == -1 || SearchPath(yM[v]))
//            {
//                yM[v] = u;
//                xM[u] = v;
//                return true;
//            }
//        }
//    }
//    return false;
//}
//
//int MaxMatch()
//{
//    int u;
//    int ret = 0;
//    memset(xM, -1, sizeof(xM));
//    memset(yM, -1, sizeof(yM));
//    for (u=0; u<uN; u++)
//    {
//        if (xM[u] == -1)
//        {
//            memset(chk, false, sizeof(chk));
//            if (SearchPath(u)) ret++;
//        }
//    }
//    return ret;
//}
//
//int main()
//{
////    int i, k;
////    int tU, tV;
////    ifstream cin("test.txt");
////    cin >> uN >> vN >> k;
////    memset(g, false, sizeof(g));
////    for (i=0; i<k; i++)
////    {
////        cin >> tU >> tV;
////        g[tU][tV] = true;
////    }
//
//    uN=3;
//    vN=4;
//    g[0][0]=0; g[0][1]=1; g[0][2]=1; g[0][3]=0;
//    g[1][0]=0; g[1][1]=1; g[1][2]=0; g[1][3]=0;
//    g[2][0]=1; g[2][1]=0; g[2][2]=1; g[2][3]=1;
//
//    cout << MaxMatch() << endl;
//    for(int num=0;num<3;++num){
//        cout<<"cx["<<num+1<<"]  -> "<<xM[num]+1<<endl;
//    }
//    cout << "!!!finish!!!" << endl; // prints !!!Hello World!!!
////    system("pause");
//    return 0;
//}



//
//// bug scanf
////http://www.cppblog.com/chgsh8089/archive/2007/03/12/13205.html
//#include<stdio.h>
//#include<string.h>
//
//bool g[5][5];
//int n,m,ans;
//bool b[5];
//int link[5];
//
//bool init()
//{
//    int _x,_y;
//    memset(g,0,sizeof(g));
//    memset(link,0,sizeof(link));
//    ans=0;
//    if(scanf("%d%d",&n,&m)==EOF)return false;
//    for(int i=1;i<=n;i++)
//    {
//        scanf("%d",&_x);
//        for(int j=0;j<_x;j++)
//        {
//            scanf("%d",&_y);
//            g[i][_y]=true;
//        }
//    }
//    return true;
//}
//
//bool find(int a)
//{
//    for(int i=1;i<=m;i++)
//    {
//        if(g[a][i]==1&&!b[i])
//        {
//            b[i]=true;
//            if(link[i]==0||find(link[i]))
//            {
//                link[i]=a;
//                return true;
//            }
//        }
//    }
//    return false;
//}
//
//int main()
//{
//    while(init())
//    {
//        for(int i=1;i<=n;i++)
//        {
//            memset(b,0,sizeof(b));
//            if(find(i))ans++;
//        }
//        printf("%d\n",ans);
//    }
//}
//
//
//






//广度搜索（DFS）特点：优点，实现简洁，理解容易。适用：稠密图，由于边多，DFS找增广路很快。复杂度O（n3）
// https://blog.csdn.net/michaelhan3/article/details/51706380
//
////ok_sxp
//#include <iostream>
//#include <string.h>
//using namespace std;
//
//
//#define MAXN 10                  //MAXN表示X集合和Y集合顶点个数的最大值
//int nx,ny;                                       //x和y集合中顶点的个数
//int g[MAXN][MAXN];                //邻接矩阵，g[i][j]为1表示有连接
//int cx[MAXN],cy[MAXN];
////cx[i],表示最终求得的最大匹配中，与x集合中元素Xi匹配的集合Y中顶点的索引
////cy[i],表示最终求得的最大匹配中，与y集合中元素Yi匹配的集合X中顶点的索引
//
////DFS算法中记录顶点访问状态的数据mk[i]=0表示未访问过，为1表示访问过
//int mk[MAXN];
//
////从集合X中的定顶点u出发，用深度有限的策略寻找增广路.这种增广路只能是当前的匹配数增加1
//int path(int u){
//    for(int v=0;v<ny;++v){      //考虑所有Yi顶点v
//        if(g[u][v] && !mk[v]){     //Y中顶点v与u邻接，且没有访问过 //g[u][v] >阈值sxp.g[u][v]权重
//            mk[v]=1;                        //访问v
//
//            //如果v没有匹配，则直接将v匹配给u，如果v已经匹配了，但是从cy[v],也就是从v之前已经匹配的x出发，找到一条增广路，但是这里记住这里v已经记录访问过了
//            //如果第一个条件成立，则不会递归调用path
//            if(cy[v]==-1 || path(cy[v])){ //交换 sxp
//                cx[u]=v;            //把Y中v匹配给X中u
//                cy[v]=u;            //把X中u匹配给Y中v
//                return 1;
//            }
//        }
//    }
//    return 0;                        //如果不存在从u出发的增广路，则返回0
//}
//
//int maxMatch(){        //求二分图最大匹配的匈牙利算法
//    int res=0;
//    memset(cx,-1,sizeof(cx));        //从0匹配开始增广，将cx和xy各元素都初始化为-1
//    memset(cy,-1,sizeof(cy));
//    for(int i=0;i<nx;++i){
//        if(cx[i]==-1){       //从X集合中每个没有匹配的点出发开始寻找增广路
//            memset(mk,0,sizeof(mk));
//            res+=path(i);
//        }
//    }
//    return res;
//}
//
//
//int main() {
//    nx=3;
//    ny=4;
//    g[0][0]=0; g[0][1]=1; g[0][2]=1; g[0][3]=0;
//    g[1][0]=0; g[1][1]=1; g[1][2]=0; g[1][3]=0;
//    g[2][0]=1; g[2][1]=0; g[2][2]=1; g[2][3]=1;
//
//    int num= maxMatch();
//    cout<<"num="<<num<<endl;
//    for(int num=0;num<3;++num){
//        cout<<"cx["<<num+1<<"]  -> "<<cx[num]+1<<endl;
//    }
//    cout << "!!!finish!!!" << endl;
//    return 0;
//}


//
// ok_sxp
//深度搜索（BFS）特点：适用稀疏的二分图，边少，增广路短。复杂度O(N3)
//
//#include <iostream>
//#include <string.h>
//using namespace std;
//
//#define  MAXN 10
//int nx=3,ny=4;
//int g[MAXN][MAXN];
//int cx[MAXN];
//int cy[MAXN];
//
//int pred[MAXN];
//int queue[MAXN];
//int MaxMatch(){
//    int i,j,y;
//    int cur,tail;//尾
//    int res=0;
//    memset(cx,-1,sizeof(cx));
//    memset(cy,-1,sizeof(cx));
//    for(i=0;i<nx;++i){
//        if(cx[i]!=-1)     continue;
//        for(j=0;j<ny;j++)  pred[j]=-2;
//        cur=tail=0;
//        for(j=0;j<ny;j++){
//            if(g[i][j]){
//                pred[j]=-1;
//                queue[tail++]=j;
//            }
//        }
//        while(cur<tail){
//            y=queue[cur];
//            if(cy[y]==-1) break;
//            cur++;
//            for(j=0;j<ny;j++){
//                if(  pred[j]==-2  && g[ cy[y]] [j]){
//                    pred[j]=y;
//                    queue[tail++]=j;
//                }
//            }
//        }
//        if(cur==tail) continue;
//        while(pred[y]>-1){
//            cx[cy[pred[y]]]=y;
//            cy[y]=cy[pred[y]];
//            y=pred[y];
//        }
//        cy[y]=i;
//        cx[i]=y;
//        res++;
//    }
//    return res;
//
//}
//
//int main() {
//    g[0][0]=0; g[0][1]=1; g[0][2]=1; g[0][3]=0;
//    g[1][0]=0; g[1][1]=1; g[1][2]=0; g[1][3]=0;
//    g[2][0]=1; g[2][1]=0; g[2][2]=1; g[2][3]=1;
//
//    int num= MaxMatch();
//    cout<<"num="<<num<<endl;
//    for(int num=0;num<3;++num){
//        cout<<"cx["<<num+1<<"]  -> "<<cx[num]+1<<endl;
//    }
//    cout << "!!!finish!!!" << endl; // prints !!!Hello World!!!
//    return 0;
//}