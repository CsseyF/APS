#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE_LENGHT 30

void insertionSort(int arrSize,char arrInsert[arrSize][MAX_LINE_LENGHT], int descending){

    //Declaração de variáveis
    int i,j;
    char x[MAX_LINE_LENGHT];

    // Executa um loop de 1 a N para repetir o processo de ordenação por inserção
    for(i=1; i < arrSize; i++)
    {
        // Aloca o valor novo num local apropriado
        strcpy(x,arrInsert[i]);

        // Executa um loop while para classificação por inserção de i-1 a 0
        j=i-1;
        while(j>=0)
        {
            //Verifica se deve ser ordenado Crescentemente ou Decrescentemente
            if(descending == 1){
                // Agora verifica se o valor de x é menor que o valor indexado do array
                // então muda a string do array para a direita, senão quebra o loop.
                if(strcmp(x,arrInsert[j])<0)
                {
                    strcpy(arrInsert[j+1],arrInsert[j]);
                }
                else
                {
                    break;
                }
                j=j-1;
            }
            else{
                //Mesmo processo citado acima, mas decrescentemente
                if(strcmp(x,arrInsert[j])>0)
                {
                    strcpy(arrInsert[j+1],arrInsert[j]);
                }
                else
                {
                    break;
                }
                j=j-1;
            }

        }
        strcpy(arrInsert[j+1],x);
    }

    //Imprime o resultado
    for(i = 0; i < arrSize; i++){
        printf(" %d:%s",i+1,arrInsert[i]);
    }

}

void selectionSort(int arrSize, char arrSelect[arrSize][MAX_LINE_LENGHT], int descending){

    //Declaração de variáveis
    int i,j,snp;
    char t[MAX_LINE_LENGHT];

    // Executa um loop de 0 a N para repetir o processo de ordenação por seleção
    for(i=0; i < arrSize; i++)
    {

        // Posição da menor string
        snp=i;

        for(j=i+1; j < arrSize; j++)
        {
            //Verifica se deve ser ordenado Crescentemente ou Decrescentemente
            if(descending == 1){
                if(strcmp(arrSelect[j],arrSelect[snp])<0)
                {
                    snp=j;
                }
            }
            else{
                if(strcmp(arrSelect[j],arrSelect[snp])>0)
                {
                    snp=j;
                }
            }

        }
        //Verifica se deve ser ordenado Crescentemente ou Decrescentemente
        if(descending == 1){
            // Fora do loop., verifica se o dado indexado é
            // maior que a menor string, se sim, troca as strings de lugar
            if(strcmp(arrSelect[i],arrSelect[snp])>0)
            {
                strcpy(t,arrSelect[i]);
                strcpy(arrSelect[i],arrSelect[snp]);
                strcpy(arrSelect[snp],t);
            }
        }
        else{
            //Mesmo processo citado a cima, mas decrescementemente
            if(strcmp(arrSelect[i],arrSelect[snp])<0)
            {
                strcpy(t,arrSelect[i]);
                strcpy(arrSelect[i],arrSelect[snp]);
                strcpy(arrSelect[snp],t);
            }
        }

    }
    
    for(i = 0; i < arrSize; i++){
        printf(" %d:%s",i+1,arrSelect[i]);
    }
}

void merge(int arrSize, char newArr[arrSize][MAX_LINE_LENGHT], int l, int m, int r)
{
    // Declaração das variaveis
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Cria os arrays temporários
    char L[n1][MAX_LINE_LENGHT], R[n2][MAX_LINE_LENGHT];

    // Copia os dados do array original para os temporarios.
    for (i = 0; i < n1; i++){
        strcpy(L[i],malloc(sizeof(newArr[l+i])));
        strcpy(L[i], newArr[l + i]);
    }
    for (j = 0; j < n2; j++){
        strcpy(R[i],malloc(sizeof(newArr[m+i+1])));
        strcpy(R[j], newArr[m + 1+ j]);
    }

    // Junta os dois arrays temporários
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (strcmp(L[i],R[j])<0)
        {
            strcpy(newArr[k++],L[i++]);
        }
        else
        {
            strcpy(newArr[k++],R[j++]);
        }
    }
   
    // Copia os elementos restantes da primeira metade
    while (i < n1)
    {
        strcpy(newArr[k++],L[i++]);
    }
    
    // Copia os elementos restantes da segunda metade
    while (j < n2)
    {
        strcpy(newArr[k++],R[j++]);
    }
}


void mergeSort(int arrSize, char newArr[arrSize][MAX_LINE_LENGHT], int l, int r)
{
    if (l < r)
    {
        //Encontra o elemento do meio
        int m = (l+r)/2;

        //Recursivamente ordena as duas metades. 
        mergeSort(arrSize, newArr, l, m);
        mergeSort(arrSize, newArr, m+1, r);
        
        //Junta o array
        merge(arrSize, newArr, l, m, r);
    }
}


int main(){

    //Declarações responsáveis por ler o arquivo
    FILE *textfile;
    char line[MAX_LINE_LENGHT];
    char arr[900][MAX_LINE_LENGHT];
    int i;
    
    //Declarações responsáveis pela navegação na interface
    int filterOption, groupOption, groupValue, AsOrDesOption;

    //Parte do código responsavel por ler o arquivo de texto
    #pragma region ReadFile
    textfile = fopen("animals.txt", "r");
    if(textfile == NULL){
        printf("file can't be opened \n");
    }
    
    // Lê cada uma das linhas e cria um elemento no array para cada uma.
    while(fgets(line, sizeof(line), textfile)){
        if(i < 900){
        strcpy(arr[i], line);
        i++;
        }
        else break;
    }

    fclose(textfile);
    #pragma endregion

    //Inicio da interface
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

    printf("Ordernar de forma crescente ou decrescente?\n");
    printf("1: Crescente \n2: Decrescente\n");
    printf("Opcao desejada: ");
    scanf("%d", &AsOrDesOption);

    if(AsOrDesOption > 2 || AsOrDesOption < 0){
        printf("Opcao invalida, tente novamente.\n");
        main();
    }

    //Tratamento das respostas e opções do programa.
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
        insertionSort(arr_size, newArr, AsOrDesOption);
        break;
    
    case 2:
        selectionSort(arr_size,newArr, AsOrDesOption);
        break;

    case 3:
        mergeSort(arr_size, newArr, 0, arr_size - 1 );
        for(i = 0; i < arr_size; i++){
            printf(" %d:%s",i+1,newArr[i]);
        }
        break;
    default:
        break;
    }
    
    return 0;
}