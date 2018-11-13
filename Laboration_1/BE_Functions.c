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
    //printf("TotalTempTime: %ld\n",totalTempTime);
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

int loopGivenTime(int algID,int array[],int size){

    int runs = nRuns,totalTime;
    printf("array: %d\n",array[0]);
    while(runs != 0){
        switch(algID){
        case 1: bubbleSort(array,size); break;
        case 2: insertion(array,size);  break;   
        // case 3:
        // case 4:
        // case 5:
        }
        runs --;
    }
    totalTime = totalTempTime;      //Need to reset totalTempTime after nRuns
    totalTempTime = 0;

    return totalTime/nRuns;
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

/****************************************************************************/
/* Algorithms                                                           
/****************************************************************************/

void bubbleSort(int array[],int size){
    int i,j,temp;
    
    startTimer();

    for(i = 0; i < size; i++){
        for(j = 0; j < (size - i - 1); j++){
            if(array[j] > array[j + 1]){
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }

    stopTimer();
}

void insertion(int array[], int size){

    int i = 1,j,temp;
    startTimer();

    while(i < size){
        j = i;
        while(j > 0 && array[j - 1] > array[j]){
            
            temp = array[j];
            array[j] = array[j - 1];
            array[j - 1] = temp;
            j = j - 1;
        }
        i = i + 1;
    }

    stopTimer();
}
