#include<bits/stdc++.h>
using namespace std;

int parent[1000005];

struct edge
{
    int a,b,w;
};
struct edge ar[5000005];
bool comp (edge a,edge b)
{
    if(a.w<b.w)return true;
    else return false;
}

int findd(int a)
{
    if(parent[a]==a)return a;
    else
    {
        return parent[a]=findd(parent[a]);
    }
}
void unionn(int a,int b)
{
    parent[a]=b;
}

int main()
{
    int n,t=0;
    while(scanf("%d", &n) != EOF)
    {
        for(int i=0;i<=n;i++)parent[i]=i;

        int sum=0;
        for(int i=0; i<n-1; i++)
        {

            int f,t,c;
            cin>>f>>t>>c;
           sum+=c;


        }
        int k;
        cin>>k;
        int sum1=0;
        for(int i=0;i<k;i++)
        {

            cin>>ar[i].a>>ar[i].b>>ar[i].w;

        }

        int m;
        cin>>m;
        for(int i=k;i<m+k;i++)
        {
           cin>>ar[i].a>>ar[i].b>>ar[i].w;
        }
        sort(ar,ar+k+m,comp);
        for(int i=0; i<m+k; i++)
        {
            int u=findd(ar[i].a);
            int v=findd(ar[i].b);
            if(u!=v)
            {
                sum1+=ar[i].w;
                unionn(u,v);
            }
        }
         if(t != 0) printf("\n");
        printf("%d\n", sum);
         printf("%d\n",sum1);

        t++;
    }

}
