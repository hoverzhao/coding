#include <bits/stdc++.h>
using namespace std;
int c[100000];
int main()
{
  int t,n,a;
  cin>>t;
  for(int i=0; i<t; i++)
  {
    cin>>n>>a;
    memset(c,0,sizeof(c));
    c[0]=1;
    int l=1;
    for(int j=2; j<=n; j++)//??????
    {
      int w=0;
      for(int k=0; k<l; k++)//???????
      {
        c[k]=c[k]*j+w;
        w=c[k]/10;
        c[k]%=10;
      }
      while(w>0)//?????
      {
        c[l]=w%10;
        l++;
        w/=10;
      }
    }
    int sum=0;
    for(int j=0; j<l; j++)
      if(c[j]==a) sum++;//????
    cout<<sum<<endl;
  }
  return 0;
}
