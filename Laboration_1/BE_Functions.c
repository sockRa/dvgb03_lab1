#include "driver.h"

/*Global data**********************************************/
int nRuns = 10;         /*how many times should the algorithm go*/
double totalTempTime = 0;
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
    totalTempTime += ((double)(endT - startT));        // casta om tiden som en double för alla beräkningar. Visa upp i tabellen som en int.
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
    }
}

double loopGivenTime(int algID,int caseID,int *list,int size, int searchedValue){

    int runs = nRuns;
    double totalTime;
    while(runs != 0){
        startTimer();
        switch(algID){
        case 1: bubbleSort(list,size);                                                                 break;
        case 2: insertion(list,size);                                                                  break;   
        case 3: quicksort(list,0,size,caseID);                                                         break;
        case 4: linearSearch(list,size,searchedValue);                                                 break;
        case 5: insertion(list,size);   binarySearch(list,0,size,searchedValue);                       break;
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
    }

    return tempName;
}

char *setCase(int Case){    //Set case based of argument

    char *tempCase;
    switch(Case){

        case 1: tempCase = "Best Case";        break;
        case 2: tempCase = "Random Case";      break;
        case 3: tempCase = "Worst Case";       break;
        
    }
    return tempCase;
}

char *setCol(int algID, int *check){

    char *tempName;
        
        if(algID == 1 || algID == 2){
            switch(*check){
                case 0:     tempName = "T/n";       *check = 1;     return tempName;    break;
                case 1:     tempName = "T/n²";      *check = 2;     return tempName;    break;      
                case 2:     tempName = "T/n³";      *check = 3;     return tempName;    break;
            }
        }
        if(algID == 3){
            switch(*check){
                case 0:     tempName = "T/n";       *check = 1;     return tempName;    break;
                case 1:     tempName = "T/nlogn";   *check = 2;     return tempName;    break;
                case 2:     tempName = "T/n²";      *check = 3;     return tempName;    break;
            }
        }
            switch(*check){
                case 0:     tempName = "T/nlogn";   *check = 1;     return tempName;    break;
                case 1:     tempName = "T/n";       *check = 2;     return tempName;    break;
                case 2:     tempName = "T/n²";      *check = 3;     return tempName;    break;
            }
}


/****************************************************************************/
/* Algorithms                                                           
/****************************************************************************/

void bubbleSort(int *array,int size){
    int i,j;
    bool swapped = false;
    for(i = 0; i < size - 1; i++){
        swapped = false;
        for(j = 0; j < size - 1 - i; j++){
            if(*(array + j) > *(array + j + 1)){
                swap((array + j), (array + j + 1));
                swapped = true;
            }
        }
        if(!swapped){
            break;
        }
    }

}

void insertion(int *array, int size){

    int i = 1,j;

    while(i < size){
        j = i;
        while(j > 0 && *(array + j - 1) > *(array + j)){
            swap((array + j), (array + j - 1));
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
   if(caseID == id_WORSTCASE) piviot = *(A + lo);
    
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
            if(*(list + i) == searchedValue) printf("Found searched value\n");
        }
        printf("Did not find searched value\n");
}

void binarySearch(int *list, int l, int r, int x){ 

   if (r >= l){ 
    
        int mid = l + (r - l)/2; 
  
        // If the element is present at the middle  
        // itself 
        if (*(list + mid) == x)   //printf("Found x\n");
            
        // If element is smaller than mid, then  
        // it can only be present in left subarray 
        if (*(list + mid) > x)  binarySearch(list, l, mid-1, x);
             
        // Else the element can only be present 
        // in right subarray 
            binarySearch(list, mid+1, r, x); 
   } 
  
   // We reach here when element is not  
   // present in array 
   //printf("Value not found!\n"); 
}