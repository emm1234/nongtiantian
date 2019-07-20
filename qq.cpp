#include<stdio.h>
int s,j,b,k,h,n,m,bestp=0,cp=0;
int p[10000],a[10000][10000],z[20000];
void  Backtrack(int i,int z[])
{ 
    if(i>n)
    {
        if(cp>bestp)
            bestp=cp;
    }
        else 
        	
        { s=1;
        	for(j=1;j<=m;j++)  
                {
				   b=z[j]-a[j][i];
				  if(b<0){
					  s=0;  
					  break;}}
				  if(s==1)    
					  {cp=cp+p[i];    
				  for(k=1;k<=m;k++)   
				  {
					  z[k]=z[k]-a[k][i]; 
				  }
				  	
				  Backtrack(i+1,z);
			      cp=cp-p[i];     
				  for(h=1;h<=m;h++){  
				  z[h]=z[h]+a[h][i];  
			  }
			}
				 Backtrack(i+1,z);
			  }
		
}

 void  main()
{
    int i,j; 
    printf("请输入物品个数:\n");
    scanf("%d",&n);
	printf("请输入物品属性个数:\n");
    scanf("%d",&m);
    printf("请依次输入物品的价值:\n");
    for(i=1;i<=n;i++) 
        scanf("%d",&p[i]);
    printf("请输入物品属性条件:\n");
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
	printf("请输入最终的约束条件\n");
	
	for(i=1;i<=m;i++)
	scanf("%d",&z[i]);
	Backtrack(1,z);
    
	printf("最大价值为:\n");
    printf("%d\n",bestp);

    }
