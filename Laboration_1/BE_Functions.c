#include "driver.h"

/*Global data**********************************************/
int nRuns = 10,totalTempTime = 0;         /*how many times should the algorithm go*/

clock_t startT,endT; 

/**********************************************************/

void error(){
    printf("Something went wrong\n");
}

/****************************************************************************/
/* BE Utilitys                                                           
/****************************************************************************/

void startTimer(){

    startT = clock();
}

void stopTimer(){

    endT = clock();
    totalTempTime += ((int)(endT - startT));
    resetTimer();
}

void resetTimer(){
    startT = 0;
    endT = 0;
}


double calc(double t, double n, int toPower){   //Calc function for doing calculations that's gonna be displayed as result.

    switch(toPower){
        
        case 1: return t/n;         break;
        case 2: return t/(n*n);     break;
        case 3: return t/(n*n*n);   break;
        default: error();
    }
}

int loopGivenTime(int algID,int caseID,int array[],int size, int searchedValue){

    int runs = nRuns,totalTime;
    while(runs != 0){
        startTimer();
        switch(algID){
        case 1: bubbleSort(array,size);                                                 break;
        case 2: insertion(array,size);                                                  break;   
        case 3: quicksort(array,0,size-1,caseID);                                       break;
        case 4: linearSearch(array,size,searchedValue);                                 break;
        // case 5:
        }
        runs --;
        stopTimer();
    }

    totalTime = totalTempTime;      //Need to reset totalTempTime after nRuns
    totalTempTime = 0;

    return totalTime/nRuns;
}

int calcMid(int A[],int lo, int hi){
    int mid = (lo + hi) / 2;

    if(A[mid] < A[lo])  swap(&A[lo], &A[mid]);

    if(A[hi] < A[lo])   swap(&A[lo], &A[hi]);
     
    if(A[mid] < A[hi])  swap(&A[mid], &A[hi]);

    return A[hi];
}

void swap(int *a, int *b){

    int temp = *a;
    *a = *b;
    *b = temp;

}

/****************************************************************************/
/* Set name and case for tableDisplay                                                           
/****************************************************************************/


char *setName(int algID){     //Sets name based of argument
    
    char *tempName;
    switch(algID){

        case 1: tempName = "Bubble Sort";       break;
        case 2: tempName = "Insertion Sort";    break;
        case 3: tempName = "Quick Sort";        break;
        case 4: tempName = "Linear Search";     break;
        case 5: tempName = "Binary Search";     break;
        default: error();
    }

    return tempName;
}

char *setCase(int Case){    //Set case based of argument

    char *tempCase;
    switch(Case){

        case 1: tempCase = "Best Case";        break;
        case 2: tempCase = "Random Case";      break;
        case 3: tempCase = "Worst Case";       break;
        default: error();
        
    }
    return tempCase;
}

void setCol(int algID, int *check){

    char *tempName;
        
        if(algID == 1 || algID == 2){
            switch(*check){
                case 0:     printf("\t\t\tT/N");        *check = 1;     break;
                case 1:     printf("\t\t\tT/n²");       *check = 2;     break;      
                case 2:     printf("\t\tT/n³");         *check = 3;     break;
            }
        }
        if(algID == 3){
            switch(*check){
                case 0:     printf("T/n");              *check = 1;     break;
                case 1:     printf("T/nlogn");          *check = 2;     break;
                case 2:     printf("T/n²");             *check = 3;     break;
            }
        }
            switch(*check){
                case 0:     printf("T/nlogn");      *check = 1;         break;
                case 1:     printf("T/n");          *check = 2;         break;
                case 2:     printf("T/n²");         *check = 3;         break;
            }
}


/****************************************************************************/
/* Algorithms                                                           
/****************************************************************************/

void bubbleSort(int array[],int size){
    int i,j,temp;

    for(i = 0; i < size; i++){
        for(j = 0; j < (size - i - 1); j++){
            if(array[j] > array[j + 1]){
                swap(&array[j], &array[j + 1]);
            }
        }
    }
}

void insertion(int array[], int size){

    int i = 1,j,temp;

    while(i < size){
        j = i;
        while(j > 0 && array[j - 1] > array[j]){
            
            swap(&array[j], &array[j - 1]);

            j = j - 1;
        }
        i = i + 1;
    }
}

void quicksort(int A[],int lo,int hi, int caseID){
    int p;
    if(lo < hi){
        p = partition(A, lo, hi, caseID);
        quicksort(A, lo, p, caseID);
        quicksort(A, p + 1, hi, caseID);
    }
}

int partition(int A[],int lo,int hi, int caseID){
    int piviot;
   if(caseID == id_WORSTCASE) piviot = A[lo];
    
    piviot = calcMid(A,lo,hi);   
    
    int i = lo - 1;
    int j = hi + 1;
    int temp;

    while(1){
        do{
            i = i + 1;
        }while(A[i] < piviot);

        do{
            j = j - 1;
        }while(A[j] > piviot);

        if (i >= j){
            return j;
        }
        swap(&A[i], &A[j]);
    }
}

void linearSearch(int list[], int size, int searchedValue){
        int i;
        for(i = 0; i < size; i++){
            if(list[i] == searchedValue) printf("Found searched value\n");
        }
        printf("Did not find searched value\n");
}
