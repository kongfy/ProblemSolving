//Memory Time   
//420K   16MS   
      
#include <iostream>
#include <cstring>

using namespace std;  
      
int ipmap[41][11];   //标记存在城市'*'的位置，并依次记录城市的编号  
int ip;     //城市编号（最终是城市数量）  
int V1,V2;  //二分图的两个顶点集  
int M;      //最大二分匹配  
      
bool city[401][401];   //标记两个城市之间是否能连通  
//通过“拆点”操作，把每一个城市拆分为2个，分别属于所构造的二分图的两个点集  
bool vist[401];  
int mlink[401];  
      
int dire_r[4]={-1,1,0,0};  
int dire_c[4]={0,0,-1,1};   //分别对应四个方位 上 下 左 右  
      
      
/*Hungary Algorithm*/  
      
bool dfs(int x)  
{  
    for(int y=1;y<=V2;y++)  
        if(city[x][y] && !vist[y])  
        {  
            vist[y]=true;  
            if(mlink[y]==0 || dfs(mlink[y]))  
            {  
                mlink[y]=x;  
                return true;  
            }  
        }  
    return false;  
}  
      
void search(void)  
{  
    for(int x=1;x<=V1;x++)  
    {  
        memset(vist,false,sizeof(vist));  
        if(dfs(x))  
            M++;  
    }  
    return;  
}  
      
int main(void)  
{  
    int test,h,w;  
    cin>>test;  
    while(test--)  
    {  
        /*Initial*/  
      
        memset(ipmap,0,sizeof(ipmap));  
        memset(city,false,sizeof(city));  
        memset(mlink,0,sizeof(mlink));  
        ip=0;  
        M=0;  
      
        /*Read in the maps*/  
      
        cin>>h>>w;  
      
        int i,j;  
        char temp;  
        for(i=1;i<=h;i++)  
            for(j=1;j<=w;j++)  
            {  
                cin>>temp;  
                if(temp=='*')  
                    ipmap[i][j]=++ip;  
            }  
      
        /*Structure the Bipartite Graphs*/  
      
        for(i=1;i<=h;i++)  
            for(j=1;j<=w;j++)  
                if(ipmap[i][j])  
                    for(int k=0;k<4;k++)  
                    {  
                        int x=i+dire_r[k];  
                        int y=j+dire_c[k];  
                        if(ipmap[x][y])  
                            city[ ipmap[i][j] ][ ipmap[x][y] ]=true;      //"拆点"操作是"顺便"被完成的  
                    }                                                    //二分图构造完毕后，之后的问题就和POJ3041一样处理了  
      
        V1=V2=ip;  
      
        /*增广轨搜索*/  
      
        search();  
      
        /*Output*/  
      
        cout<<ip-M/2<<endl;   //无向二分图：最小路径覆盖数 = "拆点"前原图的顶点数 - 最大匹配数/2  
    }  
    return 0;  
}  
