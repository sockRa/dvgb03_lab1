#include "driver.h"

//@   Inför uppsatsen, lägg in resultaten i en graf för att visa att det stämmer överens med big O!

/****************************************************************************/
/* Global data objects                                                      */
/****************************************************************************/


static int numTest = 5;                                         /*how many times should the loop go*/ 
static int arrayOfSizes[] = {SIZE1,SIZE2,SIZE3,SIZE4,SIZE5};    /*Init array*/  

/****************************************************************************/
/* Result table                                                            
/****************************************************************************/


void tableDisplay(int times[],int alg,char CaseChoice){

    char *name = setName(alg);
    char *Case = setCase(CaseChoice);

    printf("-------------------------------------------------------------------------\n");
    printf("--- %s-%s                                            ---\n",name,Case);
    printf("-------------------------------------------------------------------------\n");
    printf("---     N     Time          T/N            T/N^2        T/N^3         ---\n");
    printf("-------------------------------------------------------------------------\n");
    printf("---  %d       %d    %e    %e    %e    ---\n",arrayOfSizes[0],times[0],calc(times[0],arrayOfSizes[0],1), calc(times[0],arrayOfSizes[0],2), calc(times[0],arrayOfSizes[0],3));
    printf("---  %d       %d    %e    %e    %e    ---\n",arrayOfSizes[1],times[1],calc(times[1],arrayOfSizes[1],1), calc(times[1],arrayOfSizes[1],2), calc(times[1],arrayOfSizes[1],3));
    printf("---  %d       %d    %e    %e    %e    ---\n",arrayOfSizes[2],times[2],calc(times[2],arrayOfSizes[2],1), calc(times[2],arrayOfSizes[2],2), calc(times[2],arrayOfSizes[2],3));
    printf("---  %d       %d    %e    %e    %e    ---\n",arrayOfSizes[3],times[3],calc(times[3],arrayOfSizes[3],1), calc(times[3],arrayOfSizes[3],2), calc(times[3],arrayOfSizes[3],3));
    printf("---  %d       %d    %e    %e    %e    ---\n",arrayOfSizes[4],times[4],calc(times[4],arrayOfSizes[4],1), calc(times[4],arrayOfSizes[4],2), calc(times[4],arrayOfSizes[4],3));
    printf("-------------------------------------------------------------------------\n");
}

void initArray(int algID,int caseID, int size, int *list){

    int i,random;
    srand(time(NULL));
    switch(algID){

        case 1: switch(caseID){

            case 1:     for(i=0;i<size;i++) *(list + i) = i;                                    break;
            case 2:     for(i=0;i<size;i++) *(list + i) = size - i;                             break;  
            case 3:     for(i=0;i<size;i++){random = rand() % size; *(list + i) = random;}      break;
        
        } break; 

        case 2: switch(caseID){

            case 1:
            case 2:
            case 3:
        }  
    }
}

/*
@   algID 1 = BUBBLESORT
@   algID 2 = INSERSION
@   algID 3 = QUICKSORT
@   algID 4 = LINEARSEARCH
@   algID 5 = BINARYSEARCH

@   caseID 1 = BESTCASE
@   caseID 2 = RANDOMCASE
@   caseID 3 = WORSTCASE
*/

void runAlgorithm(int algID, int caseID){       /* GLÖM INTE ATT TA BORT DEN HÄR SKITEN! TOTALT ONÖDIG. LÄGG ALLT I INITARRAY ISTÄLLET, GLÖM INTE ATT FREE(ARRAY)*/

    int *list,i,times[numTest];

    switch(algID){

        case 1:    for(i=0;i<numTest;i++){ list = malloc(sizeof(int*) * arrayOfSizes[i]); initArray(algID,caseID,arrayOfSizes[i], list); times[i] = loopGivenTime(algID,list,arrayOfSizes[i]);}   break;

    }
    tableDisplay(times,1,'b');
}
    
/****************************************************************************/
/* Bubble Sort - All cases                                                            
/****************************************************************************/

// *void FE_BubbleSort_BestCase(){
//     /*
//      @ Funktionen som ska göra ett random case kan vara likadan för alla.
//     @   Fundera på o lägg loopen i en egen funktion
//     @   TableDisplay med diverse argument skulle också kunna vara en egen loop
//     @   Argumenten för table display skulle kunna vara konstanter som sätts någon annan stans
//     */

//     int i;
//     int time[numTest];
//     for(i=0;i<numTest;i++){
//      time[i] = BE_BubbleSort_BestCase(arrayOfSizes[i]);
//      printf("Time[%d] = %d\n",i,time[i]);     
//      }

//     tableDisplay(time,1,'b');
// }

/****************************************************************************/
/* Insertion Sort - All cases                                                            
/****************************************************************************/

/****************************************************************************/
/* Quicksort Sort - All cases                                                             
/****************************************************************************/

/****************************************************************************/
/* Linear Search - All cases                                                            
/****************************************************************************/

/****************************************************************************/
/* Binary Search - All cases                                                             
/****************************************************************************/
