
#define MAX_STRINGS 20
#define MAX_STRING_LEN 200

void insertionSort(char arr[7][20]){

    int i,j;
    char x[20];
    for(i=1; i<7; i++)
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

    for(i = 0; i<7; i++){
        printf("%s ", arr[i]);
    }

}

int main()
{
    char arr[7][20] = {"Casey", "Leonardo", "Gustavo", "Lucas", "Nicolas", "Rodrigo", "Douglas"};
    insertionSort(arr);
    return 0;
}
