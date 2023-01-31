#include<stdio.h>

int main(){
    long long int lb,ub,i,j;
    int arr[10] = {0,0,0,0,0,0,0,0,0,0};
    int count=0;

    scanf("%li %li",&lb,&ub);

    if (lb%2==0)
        lb++;
    
    for(i=lb ; i<=ub ; i+=2){

        count=0;

        for(j=2; j*j <= i ; j++ ){
            if(i%j==0){
                count=1;
                break;
            }
        }

        if(count==0){
            //printf("%li ",i);
            long int temp = i;
            while(temp){
                arr[(temp%10)]++;
                temp/=10;
            }
        }

    }

    int k,max,el=0;
    max=arr[0];
    for(k=1;k<10;k++){
        if(arr[k]>max){
            max=arr[k];
            el=k;
        }
    }
    printf("%li %li",el,max);

    return(0);

}