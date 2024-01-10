#include<stdio.h>
#include<math.h>

 void main()
 {
    int a[12] = { 3,5,4,1};
    int n,i,j,k,flag=0,prime=0;
    int q;
    q=a[0];
    for(i=1;i<4;i++)
    {
        if(q>a[i])
        {
            q=a[i];
        }
    }
    printf("MIN natural number q=%d",q);
    for(k=1;k<=100;k++)
    {
        for(j=2;j<k/2;j++)
        {
            if(k%j == 0)
            {
                flag++;
                break;
            }
        }
        if(flag ==0 && k!= 1)
        {
            for(i=0;i<4;i++)
            {
              if(k%a[i] == 1)
              {
                 prime++;
              }
              
            }
            if(prime==3)
              {
                break;
              }
              else
              {
                 prime=0;
              }
        }
        flag=0;
        
    }
    printf("\np =%d ",prime);
      if(prime == 3)
      {
        printf("\n%d",k);
      }
 }