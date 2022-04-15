#include<stdio.h>
#include<stdbool.h>
#include<malloc.h>
int find_val(int max,int *S)
{
   int pos=-1;
   int val=-100;
   int i;
   for(i=0;i<max;i++)
   {
      if(S[i]<max && S[i]>val)
      {
         pos=i;
         val=S[i];
      }
   }
   return pos;
}
int solve (int N, int* S, int Q, int** work) 
{
   int *temp = (int *)malloc(N*sizeof(int));
   int i,j;
   for(int k=0;k<N;k++)
   {
      temp[k]=0;
   }
   for(i=0;i<Q;i++)
   {
      j=work[i][0]-1;
      while(j<work[i][1])
      {
         temp[j]=temp[j]+work[i][2];
         j++;
      }
   }
   for(i=0;i<N;i++)
   {
      int val=temp[i];
      if(val!=0)
      {
         j=find_val(val,S);
         S[j]=S[j]-val;
      }
   }
   int count=0;
   for(i=0;i<N;i++)
   {
      if(S[i]<=0)
      {
         count++;
      }
   }
   return count;
}

int main() {
    int N;
    scanf("%d", &N);
    int i_S;
    int *S = (int *)malloc(sizeof(int)*(N));
    for(i_S = 0; i_S < N; i_S++)
    	scanf("%d", &S[i_S]);
    int Q;
    scanf("%d", &Q);
    int i_work, j_work;
    int **work = (int **)malloc((Q)*sizeof(int *));
    for(i_work = 0; i_work < Q; i_work++)
    {
    	work[i_work] = (int *)malloc((3)*sizeof(int));
    }
    for(i_work = 0; i_work < Q; i_work++)
    {
    	for(j_work = 0; j_work < 3; j_work++)
    	{
    		scanf("%d", &work[i_work][j_work]);
    	}
    }

    int out_ = solve(N, S, Q, work);
    printf("%d", out_);
}