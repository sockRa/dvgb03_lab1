
#include "driver.h"

/****************************************************************************/
/* global data objects                                                      */
/****************************************************************************/
#define     MAXLNC              80                   /* max number of input line chars   */
#define     MAXLN               MAXLNC+1             /* max size of input line buffer    */

char       lnbuff[MAXLN];               /* input line buffer                */
int        echomode=0;                  /* echo mode on/off 
/****************************************************************************/
/* All algorithms and cases. Each defined by their own id.
/****************************************************************************/
#define     id_BUBBLESORT       1
#define     id_INSERSION        2
#define     id_QUICKSORT        3
#define     id_LINEARSEARCH     4
#define     id_BINARYSEARCH     5

#define     id_BESTCASE         1
#define     id_RANDOMCASE       2
#define     id_WORSTCASE        3


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
   printf("***   k:   Quciksort Sort - Worst Case                      ***\n");
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
            case 'd': case 'D': printf("To be done\n");                     break;
            case 'e': case 'E': printf("To be done\n");                     break;
            case 'f': case 'F': printf("To be done\n");                     break;
            case 'g': case 'G': printf("To be done\n");                     break;
            case 'h': case 'H': printf("To be done\n");                     break;
            case 'i': case 'I': printf("To be done\n");                     break;
            case 'j': case 'J': printf("To be done\n");                     break;
            case 'k': case 'K': printf("To be done\n");                     break;
            case 'l': case 'L': printf("To be done\n");                     break;
            case 'm': case 'M': printf("To be done\n");                     break;
            case 'n': case 'N': printf("To be done\n");                     break;
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