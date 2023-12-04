#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h> 
#include <unistd.h>
#include <time.h>

void file_read(){
    const char* filepath = "./book.txt";
    printf("About to read your great book from \"%s\"\n", filepath);
    if(access(filepath, F_OK) != -1){
        printf("File found! About to do some important prep\n");
        sleep(3);
        int fd;
        FILE* fd_book; 
        if((fd = open(filepath, O_RDONLY | O_NOFOLLOW, 0400)) == -1){
            perror("Error while opening file!");
            exit(EXIT_FAILURE);
        }
        if((fd_book = fdopen(fd, "r")) == NULL){
            perror("Error while opening file!");
            exit(EXIT_FAILURE);
        }
        char c;
        while((c = fgetc(fd_book)) != EOF)
            printf("%c", c);
        fclose(fd_book);
    } else{
        printf("File not found! Perhaps you could pick up a paperback.\n");
    }
}

int main(){
    file_read();
    return 0;
}
