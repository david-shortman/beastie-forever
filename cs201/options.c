#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

/* options */
int Special = 0;    /* option -s      */
int Number = 0;     /* option -n XXXX */
char* Name1 = 0;     /* option -N YYYY ZZZZ */
char* Name2 = 0;

int ProcessOptions(int,char **);
void Fatal(char *,...);

int
main(int argc,char **argv)
    {
    int argIndex;

    if (argc == 1) Fatal("%d arguments!\n",argc-1);

    argIndex = ProcessOptions(argc,argv);

    printf("Special is %s\n", Special == 0? "false" : "true");
    printf("Number is %d\n", Number);
    printf("First Name is %s\n", Name1 == 0? "missing" : Name1);
    printf("Last Name is %s\n", Name2 == 0? "missing" : Name2);

    if (argIndex == argc)
        printf("No arguments\n");
    else
        {
        int i;
        printf("Remaining arguments:\n");
        for (i = argIndex; i < argc; ++i)
            printf("    %s\n",argv[i]);
        }

    return 0;
    }

void
Fatal(char *fmt, ...)
    {
    va_list ap;

    fprintf(stderr,"An error occured: ");
    va_start(ap, fmt);
    vfprintf(stderr, fmt, ap);
    va_end(ap);

    exit(-1);
    }

/* only -oXXX  or -o XXX options */

int
ProcessOptions(int argc, char **argv)
    {
    int start,argIndex;
    int argsUsed;
    char *arg;

    argIndex = 1;

    while (argIndex < argc && *argv[argIndex] == '-')
        {
        /* check if stdin, represented by "-" is an argument */
        /* if so, the end of options has been reached */
        if (argv[argIndex][1] == '\0') return argIndex;

        argsUsed = 0;
        start = argIndex;


        /* advance argIndex to point to the first argument to the option */
        if (argv[start][2] == '\0')
            {
            arg = argv[start+1];
            ++argIndex;
            }
        else
            {
            /* first arg is connected to option, so don't advance */
            arg = argv[start]+2;
            }

        switch (argv[start][1])
            {
            /*
             * when option has an argument, do this
             *
             *     examples are -m4096 or -m 4096
             *
             *     case 'm':
             *         MemorySize = atol(arg);
             *         argsUsed = 1;
             *         break;
             *
             * when option has multiple arguments, do this
             *
             *     examples are -r4096 1280 or -r 4096 1280
             *
             *     case 'r':
             *         Rows = atoi(arg);
             *         Cols = atoi(argv[argIndex+1]);
             *         argsUsed = 2;
             *         break;
             *
             * when option does not have an argument, do this
             *
             *     example is -a
             *
             *     case 'a':
             *         PrintActions = 1;
             *         break;
             */

            case 'n':
                Number = atoi(arg);
                argsUsed = 1;
                break;
            case 'N':
                Name1 = arg;
                Name2 = argv[argIndex+1];
                argsUsed = 2;
                break;
            case 's':
                Special = 1;
                break;
            default:
                fprintf(stderr,"option %s not understood\n",argv[start]);
                exit(-1);
            }

        argIndex += argsUsed;
        }

    return argIndex;
    }
