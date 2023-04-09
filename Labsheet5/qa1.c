#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void makeBrack(char temp[], char arr[], int left, int right, int n)
{
    if (left == (n / 2) && right == (n / 2))
    {
        strcat(arr, temp);
        return;
    }
    char my[14] = "";
    strcpy(my, temp);

    if (left < n / 2)
        makeBrack(strcat(my, "("), arr, left + 1, right, n);

    strcpy(my, temp);

    if (right < left)
        makeBrack(strcat(my, ")"), arr, left, right + 1, n);
}

int main()
{
    int k;
    scanf("%d", &k);
    char temp[14] = "";
    char arr[20000] = "";
    makeBrack(temp, arr, 0, 0, k);
    int st_len = strlen(arr);
    int num = st_len / k;
    printf("%d\n", num);

    int i = 0;
    while (i < st_len)
    {
        for (int j = 0; j < k; j++)
        {
            printf("%c", arr[i]);
            i++;
        }
        printf("\n");
    }
    return (0);
}