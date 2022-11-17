#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE_LENGHT 30

void insertionSort(int arrSize,char arr[arrSize][MAX_LINE_LENGHT]){

    int i,j;
    char x[MAX_LINE_LENGHT];
    for(i=1; i < arrSize; i++)
    {
        strcpy(x,arr[i]);
        j=i-1;
        while(j>=0)
        {
            if(strcmp(x,arr[j])<0)
            {
                strcpy(arr[j+1],arr[j]);
            }
            else
            {
                break;
            }
            j=j-1;
        }
        strcpy(arr[j+1],x);
    }

    for(i = 0; i < arrSize; i++){
        printf("%s ", arr[i]);
    }

}

void selectionSort(int arrSize, char arr[arrSize][MAX_LINE_LENGHT]){

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

void merge(char arr[7][MAX_LINE_LENGHT], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    char L[n1][20], R[n2][20];

    for (i = 0; i < n1; i++){
        strcpy(L[i],malloc(sizeof(arr[l+i])));
        strcpy(L[i], arr[l + i]);
    }
    for (j = 0; j < n2; j++){
        strcpy(R[i],malloc(sizeof(arr[m+i+1])));
        strcpy(R[j], arr[m + 1+ j]);
    }

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (strcmp(L[i],R[j])<0)
        {
            strcpy(arr[k++],L[i++]);
        }
        else
        {
            strcpy(arr[k++],R[j++]);
        }
    }

    while (i < n1)
    {
    strcpy(arr[k++],L[i++]);
    }
    while (j < n2)
    {
    strcpy(arr[k++],R[j++]);
    }
}


void mergeSort(int arrSize,char arr[arrSize][MAX_LINE_LENGHT], int l, int r)
{
    if (l < r)
    {
        int m = (l+r)/2;

        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        
        merge(arr, l, m, r);
    }
}


int main(){

    //Declarações responsáveis por ler o arquivo
    FILE *textfile;
    char line[MAX_LINE_LENGHT];
    char arr[900][MAX_LINE_LENGHT];
    int i;
    
    int filterOption, groupOption, groupValue;

    #pragma region ReadFile
    textfile = fopen("animals.txt", "r");
    if(textfile == NULL){
        printf("file can't be opened \n");
    }
    
    while(fgets(line, sizeof(line), textfile)){
        if(i < 900){
        strcpy(arr[i], line);
        i++;
        }
        else break;
    }

    fclose(textfile);
    #pragma endregion

    printf("Bem vindo! \nSelecione o metodo de ordenacao desejado:\n");
    printf("1: Insertion sort \n2: Selection sort \n3: Merge sort\n");
    printf("Opcao desejada: ");
    scanf("%d", &filterOption);

    if(filterOption > 3 || filterOption < 0){
        printf("Opcao invalida, tente novamente.\n");
        main();
    }

    printf("Otimo! Agora selecione o conjunto de quantos animais serao ordenados:\n");
    printf("1: 100 Animais \n2: 400 Animais \n3: 600 Animais \n4: 900 Animais\n");
    printf("Opcao desejada: ");
    scanf("%d", &groupOption);

    if(filterOption > 4 || filterOption < 0){
        printf("Opcao invalida, tente novamente.\n");
        main();
    }

    switch (groupOption)
    {
    case 1:
        groupValue = 100;
        break;
    
    case 2:
        groupValue = 400;
        break;

    case 3:
        groupValue = 600;
        break;
    
    case 4: 
        groupValue = 900;
        break;
    default:
        break;
    }

    char newArr[groupValue][MAX_LINE_LENGHT];

    for(i = 0; i < groupValue; i++){
        strcpy(newArr[i], arr[i]);
    }

    int arr_size = sizeof(newArr)/sizeof(newArr[0]);

    switch (filterOption)
    {
    case 1:
        insertionSort(arr_size, newArr);
        break;
    
    case 2:
        selectionSort(arr_size,newArr);

    case 3:
        mergeSort(arr_size, newArr, 0, arr_size - 1 );
    default:
        break;
    }

    return 0;
}