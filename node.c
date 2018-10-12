#include <stdio.h>
#include <stdlib.h>
#include "node.h"

struct node
    {
    void *value;
    NODE *next;
    };

/*************** public interface *************/

/* constructors */

NODE *
newNODE(void *v,NODE *n)
    {
    NODE *p = malloc(sizeof(NODE));
    if (p == 0) { fprintf(stderr,"out of memory\n"); exit(1); }
    p->value = v;
    p->next = n;
    return p;
    }

/* accessors */

void  *getNODEvalue(NODE *n) { return n->value; }
NODE  *getNODEnext(NODE *n)  { return n->next; }

/* mutators */

void  setNODEvalue(NODE *n,void *v) { n->value = v; }
void  setNODEnext(NODE *n,NODE *p)  { n->next = p; }

/* visualizers */

void displayNODE(NODE *n,FILE *fp,void (*d)(FILE *,void *))
    {
    fprintf(fp,"[[");
    d(fp,n->value);
    fprintf(fp,"]]");
    }

void displayNODEdebug(NODE *n,FILE *fp,void (*d)(FILE *,void *))
    {
    fprintf(fp,"[[");
    d(fp,n->value);
    fprintf(fp,"@%p->%p]]",n,n->next);
    }

void
freeNODE(NODE *n,void (*release)(void *))
    {
    if (release != 0) release(n->value);
    free(n);
    }
