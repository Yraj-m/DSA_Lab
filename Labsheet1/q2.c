#include<stdio.h>
#include<stdlib.h>

int main(){

    long int m,n,p,q, i,j,x,y,**a,**b;

    scanf("%li %li",&m,&n);

    a = (long int**)malloc(m * sizeof(long int*));
    
    for(i=0;i<m;i++)
        a[i] = (long int*)malloc(n * sizeof(long int));

    for(i=0;i<m;i++){
        for(j=0;j<n;j++)
            scanf("%li",&a[i][j]);
    }

    scanf("%li %li",&p,&q);

    b = (long int**)malloc(p * sizeof(long int*));
    
    for(i=0;i<m;i++)
        b[i] = (long int*)malloc(q * sizeof(long int));

    for(i=0;i<p;i++){
        for(j=0;j<q;j++)
            scanf("%li",&b[i][j]);
    }

    // long int *row = (long int*)calloc(p,sizeof(long int));
    // long int *col = (long int*)calloc(q,sizeof(long int));

    long int row_count=0;
    long int col_count=0;

    long int part=0;
    long int full=0;


    for(i=0;i<=m-p && full==0;i++)
    {
        printf("i-%li ",i);
        for(j=0;j<=n-q && full==0;j++)
        {
            printf("j-%li ",j);
            row_count=0;
            for(x=0;x<p;x++)
            { 
                printf("x-%li ",x);
                if(a[i][j]==b[x][0])
                {
                    printf("i-%li&j-%li ",i,j);
                        long int tempj = j;
                        long int tempi = i;
                        col_count=0;
                        for(y=0;y<q;y++)
                        {
                            if(a[tempi][tempj]==b[x][y])
                            {
                                col_count++;
                                tempj++;
                            }
                            else
                            {
                                break;
                            }
                        }
                        printf("c-%li ",col_count);
                        if(col_count==q){
                            part=1;
                            row_count++;
                            tempi++;
                        }
                        else{
                            break;
                        } 
                }
                printf("r-%li ",row_count);
                if(row_count==p)
                    {
                        full=1;
                        break;
                    }
                // else{
                //     i++;
                // }
                       
            }
            
        }
    }

    if(part==0 && full==0)
    {
        row_count=0;
        col_count=0;
        for(i=0;i<m && part==0;i++)
        {
            for(j=0;j<n && part==0;j++)
            {
                for(y=0;y<q && part==0;y++)
                {
                    if(a[i][j]==b[0][y])
                    {
                        row_count=0;
                       for(x=0;x<p;x++)
                       {
                            if(a[i][j]==b[x][y])
                            {
                                row_count++;
                                i++;
                            }
                       }
                       if(row_count==p)
                       {
                            part=1;     
                       }
                    }
                }
            }
        }
    }
    if(full==1)
    {
        printf("YES\n");
    }
    else if(part==1)
    {
        printf("PARTIAL\n");
    }
    else{
        printf("NO\n");
    }
    

    for(i=0;i<m;i++)
        free(a[i]);

    free(a);

    for(i=0;i<p;i++)
        free(b[i]);

    free(b);

    return(0);
}