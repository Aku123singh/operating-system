
#include<stdio.h>
#include <stdbool.h>
 
int main()
{
        int cur[5][5];
        int max[5][5];
        int avil[5];
        int need[5][5];
        int r,p,exec;
        int max_res[5];
    int running[5];
    
    int count = 0,i,j;
    bool safe = false;
        printf("\nenter no. of resources : ");
        scanf("%d",&r);
        printf("\nenter the no. of processes");
        scanf("%d",&p);
        for(i = 0; i < p; i++)
        {
        running[i] = 1;
        count++;
    }
         printf("\n enter the values of allocation_matrix\n ");
          for(i=0 ; i<p ; i++)
          {
               for(j=0 ; j<r ; j++)
               {
                       scanf("\t %d",&cur[i][j]);
               }
                 printf("\n");
          }
         
          
          printf("\n enter the values of Max_matrix\n");
          for(i=0;i<p;i++)
          {
              
               for(j=0;j<r;j++)
               {
                       scanf("\t%d",&max[i][j]);
               }
                      printf("\n");
          }
         
          printf("\n enter the available resource\n");
          for(i=0;i<r;i++)
          {
               scanf("\t%d",&avil[i]);
          }
         
          printf("\nALLOCATION MATRIX TABLE IS\n");
          for(i=0;i<p;i++)
          {
               for(j=0;j<r;j++)
               {
                       printf("\t%d",cur[i][j]);
                 }
                 printf("\n");
          }
          printf("\nMAX MATRIX TABLE IS\n");
          for(i=0;i<p;i++)
          {
               for(j=0;j<r;j++)
               {
                       printf("\t %d",max[i][j]);
                      
                 }
                 printf("\n");
          }
          printf("\n available matrix is \n");
          for(i=0;i<r;i++)
          {
               printf("\t%d",avil[i]);
          }
          printf("\n NEED MATRIX IS\n");
          for(i=0; i<p ;i++)
           {
                for(j=0; j<r;j++)
                 {
                      need[i][j]=max[i][j]-cur[i][j];
                      printf("\t %d",need[i][j]);
                       }
                       printf("\n");
           }
            while (count != 0) {
        safe = false;
        for (i = 0; i < p; i++) {
            if (running[i]) {
                exec = 1;
                for (j = 0; j < r; j++) {
                    if (max[i][j] - cur[i][j] > avil[j]) {
                        exec = 0;
                        break;
                    }
                }
                if (exec) {
                    printf("\nProcess%d is executing.\n", i );
                    running[i] = 0;
                    count--;
                    safe = true;
                    for (j = 0; j < r; j++)
                        avil[j] += cur[i][j];
                    break;
                }
            }
        }
        if (!safe) {
            printf("\nThe processes are in unsafe state.");
            break;
        }
        if (safe)
            printf("\nThe process is in safe state.");
        printf("\nAvailable vector: ");
        for (i = 0; i < r; i++)
            printf("%d ", avil[i]);
    }
    return 0;
          
           
}
