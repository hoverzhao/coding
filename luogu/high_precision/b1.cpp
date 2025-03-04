#include <bits/stdc++.h>
using namespace std;

static int x = []() {
	std::ios::sync_with_stdio(false); cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("in.txt",  "r", stdin);	freopen("out.txt", "w", stdout);
#endif
	return 0;
}();

int n,m, order[10000], machine[21][21], ntime[21][21];
//          顺序      i工件j工序使用机器、时间  
int now[21],    end_[21],    has_used_t[21][10000], ans=0;
// 工件现在工序号 现结束时间  i机器j时间是否被占用
int shu_ru()
{
    int i,j;
    scanf("%d%d",&m,&n);
    for(i=1;i<=m*n;i++)
           scanf("%d",&order[i]);
    for(i=1;i<=n;i++)
          for(j=1;j<=m;j++)
               scanf("%d",&machine[i][j]);
    for(i=1;i<=n;i++)
          for(j=1;j<=m;j++)
                scanf("%d",&ntime[i][j]);
	return 0;
}
int check(int x,int bg,int ed)
{
    int i;
       for(i=bg;i<=ed;i++)
            if(has_used_t[x][i]) return 0;
         return 1;
}
int main()
{
    int i,j,l;
       shu_ru();
       for(i=1;i<=m*n;i++)           //?? 
       {
            int x=order[i];               //???? 
            int y=machine[x][++now[x]];   //?????? 
            int z=ntime[x][now[x]];        //?????? 
            for(j=end_[x];;j++)
                   if(check(y,j,j+z-1))      //????
                   {
                         for(l=0;l<z;l++)       //??????? 
                               has_used_t[y][j+l]=1;
                     if(j+z>ans) ans=j+z;    //????? 
                             end_[x]=j+z;       //??x???? 
                        break; 
                  }
    }
    printf("%d",ans);
	return 0;
}
