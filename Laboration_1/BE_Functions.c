#include "driver.h"

/*Global data**********************************************/
double nRuns = 10;      /*how many times should the algorithm go*/
double totalTempTime = 0;
int count = 0;         

clock_t startT,endT; 

/**********************************************************/

/****************************************************************************/
/* BE Utilitys                                                           
/****************************************************************************/

void startTimer(){

    startT = clock();
}

void stopTimer(){

    endT = clock();
   //Skip saving timer the first two times for better results. 
    if(count != 2){
        totalTempTime += ((double)(endT - startT));
    }
    count ++;
    resetTimer();
}

void resetTimer(){
    startT = 0;
    endT = 0;
}

//Calc function for doing calculations that's gonna be displayed as result.
void calc(double N[],double T[],int algID){    
        int i,calc;
            for(i = 0; i < (nRuns/2); i++){
                printf("%d\t",(int) N[i]);
                printf("%d",(int) T[i]);

                if(algID == id_BUBBLESORT || algID == id_INSERSION){
                    printf("\t%E", (T[i] / N[i]));
                    printf("\t%E", (T[i] / (pow(N[i],POW2))));
                    printf("\t%E\n", (T[i] / (pow(N[i],POW3))));
                }
                if(algID == id_LINEARSEARCH || algID == id_BINARYSEARCH){
                    printf("\t%E", (T[i] / (N[i] * log(N[i]))));
                    printf("\t%E", (T[i] / N[i]));
                    printf("\t%E\n", (T[i] / (pow(N[i],POW2))));
                }
                if(algID == id_QUICKSORT){
                    printf("\t%E", (T[i] / N[i]));
                    printf("\t%E", (T[i] / (N[i] * log(N[i]))));
                    printf("\t%E\n", (T[i] / (pow(N[i], POW2))));
                }
            }
}   

double loopGivenTime(int algID,int caseID,int *array,int size, int searchedValue){

    double runs = nRuns,totalTime;
    while(runs != 0){
        startTimer();
        switch(algID){
        case 1: bubbleSort(array,size);                                                             break;
        case 2: insertion(array,size);                                                              break;   
        case 3: quicksort(array,0,size-1,caseID);                                                   break;
        case 4: linearSearch(array,size,searchedValue);                                             break;
        case 5: binarySearch(array,0,size-1,searchedValue);                                         break;
        }
        runs --;
        stopTimer();
    }

    totalTime = totalTempTime;      
    totalTempTime = 0;  //Need to reset totalTempTime after nRuns
    count = 0;          // Counter to know what time to throw away

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


void printName(int algID){     //Sets name based of argument
    
    switch(algID){

        case 1: printf("\tBubble Sort ");          break;
        case 2: printf("\tInsertion Sort ");       break;
        case 3: printf("\tQuick Sort ");           break;
        case 4: printf("\tLinear Search ");        break;
        case 5: printf("\tBinary Search ");        break;
    }
}

void printCase(int Case){    //Set case based of argument

    switch(Case){

        case 1: printf("- Best Case\n");              break;
        case 2: printf("- Random Case\n");            break;
        case 3: printf("- Worst Case\n");             break;
    }
}

void printCol(int algID, int *check){
        
        if(algID == id_BUBBLESORT || algID == id_INSERSION){
            switch(*check){
                case 0:     printf("T/N");            *check = 1;     break;
                case 1:     printf("\t\tT/n²");       *check = 2;     break;      
                case 2:     printf("\t\tT/n³\n");     *check = 3;     break;
            }
        }
        if(algID == id_QUICKSORT){
            switch(*check){
                case 0:     printf("T/n");               *check = 1;     break;
                case 1:     printf("\t\tT/nlogn");       *check = 2;     break;
                case 2:     printf("\t\tT/n²\n");        *check = 3;     break;
            }
        }
        if(algID == id_LINEARSEARCH || algID == id_BINARYSEARCH){
            switch(*check){
                case 0:     printf("T/nlogn");          *check = 1;     break;
                case 1:     printf("\t\tT/n");          *check = 2;     break;
                case 2:     printf("\t\tT/n²\n");       *check = 3;     break;
            }
        }
}


/****************************************************************************/
/* Algorithms                                                           
/****************************************************************************/

void bubbleSort(int *list,int size){
    int i,j;
    bool swapped = false;
    for(i = 0; i < (size - 1); i++){
        swapped = false;
        for(j = 0; j < (size - 1 - i); j++){
            if(*(list + j) > *(list + (j + 1))){
                swap((list + j), (list + j + 1));
                swapped = true;
            }
        }
        if(!swapped) break;
    }
}

void insertion(int *array, int size){

    int i = 1,j,temp;

    while(i < size){
        j = i;
        while(j > 0 && *(array + (j - 1)) > *(array + j)){
            
            swap((array + j), (array + (j - 1)));

            j = j - 1;
        }
        i = i + 1;
    }
}

void quicksort(int *A,int lo,int hi, int caseID){
    int p;
    if(lo < hi){
        p = partition(A, lo, hi, caseID);
        quicksort(A, lo, p, caseID);
        quicksort(A, p + 1, hi, caseID);
    }
}

int partition(int *A,int lo,int hi, int caseID){
    int piviot;

    piviot = calcMid(A,lo,hi);   
    
    int i = lo - 1;
    int j = hi + 1;
    int temp;

    while(1){
        do{
            i = i + 1;
        }while(*(A + i) < piviot);

        do{
            j = j - 1;
        }while(*(A + j) > piviot);

        if (i >= j){
            return j;
        }
        swap((A + i), (A + j));
    }
}

void linearSearch(int *list, int size, int searchedValue){
        int i;
        for(i = 0; i < size; i++){
            if(*(list + i) == searchedValue) break;
        }     
}

void binarySearch(int *list,int low, int size, int searchedValue){

    int mid;
    while(low <= size){
        mid = low + (size - low) / 2;

        if(*(list + mid) == searchedValue)  break;  //Value found
        else{
            if(*(list + mid) < searchedValue) low = mid + 1;
            else{
                size = mid - 1;
            }
        }
    }

}
