#include "driver.h"


/*Global data**********************************************/
int nRuns = 10;         /*how many times should the algorithm go*/

clock_t startT,endT,totalTempTime; 

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
    totalTempTime = (int)(endT - startT);
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

float loopGivenTime(int array[],int size,char algorithm){

    int runs = nRuns;
    while(runs != 0){
        switch(algorithm){
        case 'b': bubbleSort(array,size); break;
        // case 'i':   
        // case 'q':
        // case 'l':
        // case 'b':
        }
        runs --;
    }
    
    return totalTempTime/nRuns;
}

/****************************************************************************/
/* Set name and case for tableDisplay                                                           
/****************************************************************************/


char *setName(int alg){     //Sets name based of argument

    char *tempName;
    switch(alg){

        case 1: tempName = "Bubble Sort";       break;
        case 2: tempName = "Insertion Sort";    break;
        case 3: tempName = "Quick Sort";        break;
        case 4: tempName = "Linear Search";     break;
        case 5: tempName = "Binary Search";     break;
        default: error();
    }
    return tempName;
}

char *setCase(char Case){    //Set case based of argument

    char *tempCase;
    switch(Case){

        case 'b': tempCase = "Best Case";        break;
        case 'r': tempCase = "Random Case";      break;
        case 'w': tempCase = "Worst Case";       break;
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

/****************************************************************************/
/* Bubble Sort - All cases                                                            
/****************************************************************************/

float BE_BubbleSort_BestCase(int size){

    int array[size],i,avgTime = 0;

    for(i=0;i<size;i++){
        array[i] = i;
    }

    return loopGivenTime(array,size,'b');

}