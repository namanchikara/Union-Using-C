#include "stdio.h"
int **arr[1000]={0},crr[1000]={0};
int *brr[1000]={0},k=0;


  
void find(int num1, int num2)
{
  if(*(*arr[num1])==*(*arr[num2]))
      printf("Related\n");
      
  else printf("Not Related\n");
}
void UN(int x,int y)
{
    if(!arr[x] && !arr[y])  //when both of the elements, x and y are defined first time, so both of them will point to same address location, that's why k is incremented by one, and index x and y of array arr is going to point at brr[k].
    {
      ++k;
      //brr[k] = &crr[k];
      arr[x] = &brr[k];
      arr[y] = &brr[k];
      //printf("%d %d %d  %d    ----- 1  --%d %d\n",*arr[x],*arr[y],brr[k],crr[k],x,y);
    }
    
    else if(!arr[x]) //i.e if y has already been defined in past, so whomever y is pointing to, x will point to that too.
        {
          arr[x]=arr[y];
          //printf("%d %d %d %d      ----- 2  --%d %d\n",*arr[x],*arr[y],brr[k],crr[k],x,y);
        }
    else if(!arr[y]) //i.e if x has already been defined in past, so whomever x is pointing to, y will point to that too.
        {
          arr[y]=arr[x];
          //printf("%d %d %d %d      ----- 3   --%d %d\n",*arr[x],*arr[y],brr[k],crr[k],x,y);
        }
    else  //i.e if both x and y are pointing to some (different/same) location then, x will not change it's pointing location, but it will change the value which it was pointing to earlier to what y is pointing to right now, so all the indices of arr, which were pointing to same location as x, will have the same value as x and this is getting complicated to explain, so i'll leave it up to you to understand -_-
        {
          *arr[x]=*arr[y];  
          //printf("%d %d %d  %d    ----- 4   --%d %d\n",*arr[x],*arr[y],brr[k],crr[k],x,y);
        }
}


int main(void)
{
  for(int i=1;i<1000;i++)
  {
    brr[i]=&crr[i];
    crr[i]=i;
  }
  
  int n,x,y; //n will be used to get the information how many pairs will be entered by the user, like 10 pairs or something. 
  printf("How many union operations do you want to perform??");
  scanf("%d",&n);
  while(n--)
  {
      //for each value of n, there will be two numbers x and y, i.e: x union y, so basically next steps are to scan those two numbers and then do UNION on them.
    
    scanf("%d %d",&x,&y);
    UN(x,y);
  }
  
  printf("\n");
  //for(int i=1;i<8;i++)
  //  printf("%d %d %p \n",i,**arr[i],arr[i]);
  //n will be used to get the queries, like for each query there will be two numbers x and y, and we need to answer whether x and y are related or not.
  printf("i   arr[i]   brr[i]  *arr[i]  **arr[i]  *brr[i]\n");
  for(int i=1;i<8;i++)  
     printf("%d   %d  %d  %d  %d           %d\n",i,arr[i],brr[i],*arr[i],**arr[i],&brr[i]);

  printf("\n\nEnter no. of queries\n");  
  scanf("%d",&n);
  while(n--)
  {
    scanf("%d %d",&x,&y);
    find(x, y);
  }
  
}
