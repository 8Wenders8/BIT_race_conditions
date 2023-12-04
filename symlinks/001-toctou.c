#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h> 
#include <unistd.h>
#include <time.h>

void super_secure_file_read(){
    const char* filepath = "./book.txt";
    printf("About to read your great book from \"%s\"\n", filepath);
    if(access(filepath, F_OK) != -1){
        printf("File found! About to do some important prep\n");
        sleep(3);
        FILE* fd_book; 
        if((fd_book = fopen(filepath, "r")) == NULL){
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
    super_secure_file_read();
    return 0;
}
