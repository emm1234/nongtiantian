#include<stdio.h>
int s,j,k,h,n,m;//n是物品的个数，m物品的属性个数;
float bestp=0,cp=0,b;//bestp目前最优值,cp当前价值；
float p[5000],a[5000][5000],z[2000],bestcp[1000];//物品的价值，物品的属性条件,约束总值，将bestp的值存入bestpcp[]；
void  Backtrack(int i,float z[])
{ 
    if(i>n)//回溯结束,到达叶子结点
    {
        if(cp>bestp)//当前价值大于目前最优值
            bestp=cp;//即目前最优值为当前价值cp
		    k++;
          bestcp[k]=bestp;//将bestp存起来，然后在取出最大价值
    }
        else 
        	
        { s=1;
        	for(j=1;j<=m;j++)  
                {
				  b=z[j]-a[j][i]; //判断物品是否满足条件
				  if(b<0){
					  s=0;  //s=0,说明不取该物品
					  break;}}
				  if(s==1)    //s==1，说明取该物品
					  {cp=cp+p[i];    //存放物品后，获得当前价值
				  for(k=1;k<=m;k++)   //有m个约束条件循环m次
				  {
					  z[k]=z[k]-a[k][i]; //存放后减去容量
				  }
				  	
				  Backtrack(i+1,z);
			      cp=cp-p[i];     //到达叶子结点后，回溯
				  for(h=1;h<=m;h++){  //有m个约束条件循环m次
				  z[h]=z[h]+a[h][i];  //拿出已经存放的物品后，加上它原来的容量
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
        scanf("%f",&p[i]);
    printf("请输入物品属性条件:\n");
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
			scanf("%f",&a[i][j]);
	printf("请输入最终的约束条件\n");
	
	for(i=1;i<=m;i++)
	scanf("%f",&z[i]);
	Backtrack(1,z);
    
	printf("最大价值为:\n");
    printf("%.1f\n",bestcp[k-1]);

    }
