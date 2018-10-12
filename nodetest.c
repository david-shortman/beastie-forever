#include <stdio.h>
#include "node.h"

static void displayCstring(FILE *fp,void *s) { fprintf(fp,"%s",(char *) s); }
static void displayCinteger(FILE *fp,void *s) { fprintf(fp,"%d",*((int *) s)); }
    
int
main(void)
    {
    NODE *n,*spot;

    /* make the list */
    n = newNODE("dog",0); /* zero is the null pointer */
    n = newNODE("cat",n);
    n = newNODE("rhino",n);

    /* display the list */
    spot = n;
    while (spot != 0)
        {
        displayNODE(spot,stdout,displayCstring);
        spot = getNODEnext(spot);
        }
    printf("\n");

    /* free the list */
    spot = n;
    while (spot != 0)
        {
        NODE *next = getNODEnext(spot);
        freeNODE(spot,0); /* no need to free the value, so pass 0 */
        spot = next;
        }

    int a = 5,b = 10,c = 6;

    /* make the list */
    n = newNODE(&a,0);
    n = newNODE(&b,n);
    n = newNODE(&c,n);

    /* display the list */
    spot = n;
    while (spot != 0)
        {
        displayNODE(spot,stdout,displayCinteger);
        spot = getNODEnext(spot);
        }
    printf("\n");

    /* free the list */
    spot = n;
    while (spot != 0)
        {
        NODE *next = getNODEnext(spot);
        freeNODE(spot,0); /* no need to free the value, so pass 0 */
        spot = next;
        }

    return 0;
    }
