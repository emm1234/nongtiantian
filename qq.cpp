#include<stdio.h>
int s,j,k,h,n,m;//n����Ʒ�ĸ�����m��Ʒ�����Ը���;
float bestp=0,cp=0,b;//bestpĿǰ����ֵ,cp��ǰ��ֵ��
float p[5000],a[5000][5000],z[2000],bestcp[1000];//��Ʒ�ļ�ֵ����Ʒ����������,Լ����ֵ����bestp��ֵ����bestpcp[]��
void  Backtrack(int i,float z[])
{ 
    if(i>n)//���ݽ���,����Ҷ�ӽ��
    {
        if(cp>bestp)//��ǰ��ֵ����Ŀǰ����ֵ
            bestp=cp;//��Ŀǰ����ֵΪ��ǰ��ֵcp
		    k++;
          bestcp[k]=bestp;//��bestp��������Ȼ����ȡ������ֵ
    }
        else 
        	
        { s=1;
        	for(j=1;j<=m;j++)  
                {
				  b=z[j]-a[j][i]; //�ж���Ʒ�Ƿ���������
				  if(b<0){
					  s=0;  //s=0,˵����ȡ����Ʒ
					  break;}}
				  if(s==1)    //s==1��˵��ȡ����Ʒ
					  {cp=cp+p[i];    //�����Ʒ�󣬻�õ�ǰ��ֵ
				  for(k=1;k<=m;k++)   //��m��Լ������ѭ��m��
				  {
					  z[k]=z[k]-a[k][i]; //��ź��ȥ����
				  }
				  	
				  Backtrack(i+1,z);
			      cp=cp-p[i];     //����Ҷ�ӽ��󣬻���
				  for(h=1;h<=m;h++){  //��m��Լ������ѭ��m��
				  z[h]=z[h]+a[h][i];  //�ó��Ѿ���ŵ���Ʒ�󣬼�����ԭ��������
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
        scanf("%f",&p[i]);
    printf("��������Ʒ��������:\n");
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
			scanf("%f",&a[i][j]);
	printf("���������յ�Լ������\n");
	
	for(i=1;i<=m;i++)
	scanf("%f",&z[i]);
	Backtrack(1,z);
    
	printf("����ֵΪ:\n");
    printf("%.1f\n",bestcp[k-1]);

    }
