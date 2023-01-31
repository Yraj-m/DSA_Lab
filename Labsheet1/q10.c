#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){


    char s[1000],a[1000];

    scanf("%s",s);
    scanf("%s",a);

    int n = strlen(s);
    int count =0;

    int *seq;

    seq = (int*)calloc(n,sizeof(int));

    for(int i=0;i<n;i++){
        for(int j=0; j<n; j++){
            if(s[i]==a[j]){
                if(seq[j]!=0)
                    continue;
                seq[j]=i+1;
                count++;
            }
        }
    }
    if(count!=n){
        printf("NOT POSSIBLE");
    }
    else{
        for(int i=0;i<n;i++){
            printf("%d ",seq[i]);
        }
    }

    free(seq);

    return(0);

}