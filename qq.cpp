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
    printf("��������Ʒ����:\n");
    scanf("%d",&n);
	printf("��������Ʒ���Ը���:\n");
    scanf("%d",&m);
    printf("������������Ʒ�ļ�ֵ:\n");
    for(i=1;i<=n;i++) 
        scanf("%d",&p[i]);
    printf("��������Ʒ��������:\n");
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
	printf("���������յ�Լ������\n");
	
	for(i=1;i<=m;i++)
	scanf("%d",&z[i]);
	Backtrack(1,z);
    
	printf("����ֵΪ:\n");
    printf("%d\n",bestp);

    }
