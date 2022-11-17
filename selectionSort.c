#include <stdio.h>
#include <string.h>
#include <conio.h>

void selectionSort(char arr[7][20]){

    int i,j,snp;
    char t[20];
    for(i=0; i<6; i++)
    {
        snp=i;

        for(j=i+1; j<7; j++)
        {
            if(strcmp(arr[j],arr[snp])<0)
            {
                snp=j;
            }
        }
        if(strcmp(arr[i],arr[snp])>0)
        {
            strcpy(t,arr[i]);
            strcpy(arr[i],arr[snp]);
            strcpy(arr[snp],t);
        }
    }
    
    for(i = 0; i<7; i++){
        printf("%s ",arr[i]);
    }
}


int main()
{
    char arr[7][20] = {"Casey", "Leonardo", "Gustavo", "Lucas", "Nicolas", "Rodrigo", "Douglas"};
    selectionSort(arr);
    return 0;
}
