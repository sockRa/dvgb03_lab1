
#include "driver.h"

/****************************************************************************/
/* global data objects                                                      */
/****************************************************************************/
#define     MAXLNC              80                   /* max number of input line chars   */
#define     MAXLN               MAXLNC+1             /* max size of input line buffer    */

char       lnbuff[MAXLN];               /* input line buffer                */
int        echomode=0;                  /* echo mode on/off 

/****************************************************************************/
/* User dialog functions                                                    */
/****************************************************************************/

void UI_invalidChoice()                 {printf("INVALID MENU CHOICE\n");   }
void UI_exit()                          {printf("Good bye\n");}

/****************************************************************************/
/* UI functions                                                             */
/****************************************************************************/


/*****************************************************************************/
/*  get_choice: get user input from keyboard (1 character)                   */
/*****************************************************************************/
static char UI_get_choice() { 

  printf("\n Enter choice ==> ");
  scanf("%s", lnbuff);
  if (echomode) printf(" %c \n", lnbuff[0]);
  return(lnbuff[0]);
  }

/*****************************************************************************/
/*  dispmenu: display the user menu                                          */
/*****************************************************************************/

static void UI_dispmenu(){

     printf("\n");
   printf("***************************************************************\n");
   printf("***                                                         ***\n");
   printf("***   a:   MENU                                             ***\n");
   printf("***   b:   ALL Results                                      ***\n");
   printf("***   c:   Bubble Sort - Best Case                          ***\n");
   printf("***   d:   Bubble Sort - Random Case                        ***\n");
   printf("***   e:   Bubble Sort - Worst Case                         ***\n");
   printf("***   f:   Insersion Sort - Best Case                       ***\n");
   printf("***   g:   Insersion Sort - Random Case                     ***\n");
   printf("***   h:   Insersion Sort - Worst Case                      ***\n");
   printf("***   i:   Quicksort Sort - Best Case                       ***\n");
   printf("***   j:   Quicksort Sort - Random Case                     ***\n");
   printf("***   k:   Quicksort Sort - Worst Case                      ***\n");
   printf("***   l:   Linear Search - Best Case                        ***\n");
   printf("***   m:   Linear Search - Random Case                      ***\n");
   printf("***   n:   Linear Search - Worst Case                       ***\n");
   printf("***   o:   Binary Search - Best Case                        ***\n");
   printf("***   p:   Binary Search - Random Case                      ***\n");
   printf("***   q:   Binary Search - Worst Case                       ***\n");
   printf("***   r:   Exit                                             ***\n");
   printf("***************************************************************\n");
   printf("\n");
   
}

/****************************************************************************/
/*  runmenu: execute the user menu                                          */
/****************************************************************************/

void UI_runmenu(){

    char choice;

    UI_dispmenu();
    do{
        choice = UI_get_choice();
        switch(choice){

            case 'a': case 'A': UI_dispmenu();                              break;
            case 'b': case 'B': printf("To be done\n");                     break;
            case 'c': case 'C': initArray(id_BUBBLESORT,id_BESTCASE);       break;
            case 'd': case 'D': initArray(id_BUBBLESORT,id_RANDOMCASE);     break;
            case 'e': case 'E': initArray(id_BUBBLESORT,id_WORSTCASE);      break;
            case 'f': case 'F': initArray(id_INSERSION,id_BESTCASE);        break;
            case 'g': case 'G': initArray(id_INSERSION,id_RANDOMCASE);      break;
            case 'h': case 'H': initArray(id_INSERSION,id_WORSTCASE);       break;
            case 'i': case 'I': initArray(id_QUICKSORT,id_BESTCASE);        break;
            case 'j': case 'J': initArray(id_QUICKSORT,id_RANDOMCASE);      break;
            case 'k': case 'K': initArray(id_QUICKSORT,id_WORSTCASE);       break;
            case 'l': case 'L': initArray(id_LINEARSEARCH,id_BESTCASE);     break;
            case 'm': case 'M': initArray(id_LINEARSEARCH,id_RANDOMCASE);   break;
            case 'n': case 'N': initArray(id_LINEARSEARCH,id_WORSTCASE);    break;
            case 'o': case 'O': printf("To be done\n");                     break;
            case 'p': case 'P': printf("To be done\n");                     break;
            case 'q': case 'Q': printf("To be done\n");                     break;
            case 'r': case 'R': UI_exit();                                  break;

            default: UI_invalidChoice(); UI_dispmenu();                                      
        }

    } while (choice != 'r' && choice != 'R');

    printf("\n");
}

/****************************************************************************/
/* end of menu functions                                                    */
/****************************************************************************/