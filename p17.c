#include <stdio.h> 
#include <time.h> 
int d[10]; 
void dijkstras(int[10][10],int,int); 
 int main() 
 { 
 clock_t start,end; 
 double clk; 
 int i,j,source,n; 
 int cost[10][10]; 
 
 printf("ENTER NO. OF VERTICES\n"); 
 scanf("%d",&n); 
 
 printf("ENTER COST ADJACENCY MATRIX\n"); 
 for(i=1;i<=n;i++) 
 for(j=1;j<=n;j++) 
 scanf("%d",&cost[i][j]); 
 
 for(i=1;i<=n;i++) 
 for(j=1;j<=n;j++) 
 if(cost[i][j]==0) 
 cost[i][j]=9999; 
 
 printf("ENTER SOURCE VERTEX\n"); 
 scanf("%d",&source); 
 
 start=clock(); 
 dijkstras(cost,n,source); 
 end=clock(); 
 
 clk=(double)((end-start)/CLOCKS_PER_SEC); 
 
 printf("\n"); 
 
 for(i=1;i<=n;i++) 
 { 
 if(i!=source) 
 printf("%d-->%d cost is %d\n",source,i,d[i]); 
 } 
 
 printf("TIME REQUIRED IS %f\n",clk); 
 
 return 0; 
 
 } 
 
 void dijkstras(int cost[10][10],int n,int source) 
 { 
 
 int i,j,u,v,min,count=1; 
 int visited[10]; 
 
 for(i=1;i<=n;i++) 
 { 
 d[i]=cost[source][i]; 
 visited[i]=0; 
 } 
 
 visited[source]=1; 
 d[source]=0; 
 
 while(count<=n) 
 { 
 min=9999; 
 for(i=1;i<=n;i++) 
 { 
 
 if(d[i]<min && visited[i]==0) 
 { 
 min=d[i]; 
 v=i; 
 } 
 } 
 
 visited[v]=1; 
 count++; 
 
 for(i=1;i<=n;i++) 
 { 
 if(d[v]+cost[v][i]<d[i]) 
 { 
 d[i]=d[v]+cost[v][i]; 
 } 
 } 
 } 
 }
