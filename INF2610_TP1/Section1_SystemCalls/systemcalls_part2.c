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
    char *messagePrint = "77dbcb01f572f1c32p196c3a7d27f62e (printed using printf)";
    for (int i = 0; i< strlen(messagePrint);i++) {
        printf("%c", messagePrint[i]);
    }
    printf("\n");

    // appel write 
    char *message = "77dbcb01f572f1c32p196c3a7d27f62e (printed using write)\n";
    write(STDOUT_FILENO, message, strlen(message)); 

}

void part22 ()
{
    setvbuf(stdout, NULL, _IONBF, 0);
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
