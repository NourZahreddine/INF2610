/*
Ecole Polytechnique Montreal - GIGL
Hiver 2025
SystemCalls - part1.c*
Abou-Saada Serena, 2270553
Nour Zahreddine, 2167661
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h> 


int main () {
    int fd;
    char buffer; 

    fd = open("systemcalls_output2.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror("Appel système open a échoué");
        exit(EXIT_FAILURE);
    }

    printf("Saisissez votre texte suivi de CTRL-D :\n");

    while(read(STDIN_FILENO, &buffer, 1) > 0){ 
        if (write(fd, &buffer, 1) == -1) {
            perror("Appel système write a échoué"); 
            close(fd); 
            exit(EXIT_FAILURE);
        }
    }

    if(close(fd) == -1){
        perror("Appel système close a échoué");
        exit(EXIT_FAILURE);
    }

    return 0;
}