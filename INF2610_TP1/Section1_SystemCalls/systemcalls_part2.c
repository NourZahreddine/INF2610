/*
 * Ecole Polytechnique Montreal - GIGLL
 * Hiver 2025
 * SystemCalls - part2.c
 *
 * Abou-Saada Serena, 2270553
 * Nour Zahreddine, 2167661
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


void part21 ()
{
    //appel printf
    char *messagePrintf = "77dbcb01f572f1c32p196c3a7d27f62e (printed using printf)";
    for (int i = 0; messagePrintf[i] != '\0'; i++) {
        fprintf(stdout,"%c", messagePrintf[i]);
    }

    // appel write 
    char *messageWrite = "77dbcb01f572f1c32p196c3a7d27f62e (printed using write)\n";
    write(STDOUT_FILENO, messageWrite, strlen(messageWrite));

    fprintf(stdout, "\n");
}

void part22 ()
{
    if(setvbuf(stdout, NULL, _IONBF, 0) != 0) {
        fprintf(stdout, "setvbuf error\n");
        return;
    };
    part21();
}

int main (int argc, char* argv[])
{
    
    if (argc!=2)
    {   printf("Le programme a un seul paramètre : 1 ou 2\n");
        return 1;
    }
    switch (atoi(argv[1])) {
         case 1:        part21();
                        break;
         case 2:        part22();
                        break;
        default:        printf(" Le paramètre du programme est invalide\n");
                        return 1;
    }
    return 0;
}
