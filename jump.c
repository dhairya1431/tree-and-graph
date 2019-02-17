#include<stdio.h>
int main()
{
    long long int n;
    int t;
    scanf("%d",&t);
  while(t--)
    {
        
         scanf("%lld", &n);
  if((n==0)||(n%3==0)||((n-1)%6==0))
    printf("Yes\n");
    else
        printf("No\n");

    }

    return(0);
}

