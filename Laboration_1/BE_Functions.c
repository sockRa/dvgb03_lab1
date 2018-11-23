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
   //Skip saving time-mesurment the first two times for better results. 
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
        case id_BUBBLESORT: bubbleSort(array,size);                         break;
        case id_INSERSION: insertion(array,size);                           break;   
        case id_QUICKSORT: quicksort(array,0,size-1);                       break;
        case id_LINEARSEARCH: linearSearch(array,size,searchedValue);       break;
        case id_BINARYSEARCH: binarySearch(array,0,size-1,searchedValue);   break;
        }
        runs --;
        stopTimer();
    }

    totalTime = totalTempTime;      
    totalTempTime = 0;          // Need to reset totalTempTime after nRuns
    count = 0;                  // Counter to know what time to throw away

    return totalTime/(nRuns - 2);   // I subtract 2 from nRuns because I throw away the first 2 time-mesurments for a more realistic result.
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

        case id_BUBBLESORT: printf("\tBubble Sort ");           break;
        case id_INSERSION: printf("\tInsertion Sort ");         break;
        case id_QUICKSORT: printf("\tQuick Sort ");             break;
        case id_LINEARSEARCH: printf("\tLinear Search ");       break;
        case id_BINARYSEARCH: printf("\tBinary Search ");       break;
    }
}

void printCase(int caseID){    //Set case based of argument

    switch(caseID){

        case id_BESTCASE: printf("- Best Case\n");                  break;
        case id_RANDOMCASE: printf("- Average Case\n");             break;
        case id_WORSTCASE: printf("- Worst Case\n");                break;
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

void quicksort(int *list,int low,int high){

    int p;
    if(low < high){
        p = partition(list,low,high);
        quicksort(list, low, p-1);
        quicksort(list, p+1, high);
    }
}

int partition(int *list,int low,int high){
    
   int mid = (low + high) / 2;
   int pivot = *(list + mid);

   swap((list + mid), (list + high));
   int i = low - 1;
   int j;
   
   for(j = low; j < high; j++){
       if(*(list + j) <= pivot){
           i++;
           swap((list + j), (list + i));
       }
   }
   swap((list + i + 1), (list + high));
   return (i + 1);
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
