#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h> 
#include <unistd.h>
#include <sys/stat.h>
#include <time.h>

void permission_set(){
    const char* filepath = "./book.txt";
    printf("About to make your great book public from \"%s\"\n", filepath);
    if(access(filepath, F_OK) == -1){
        printf("File not found! Write it first and then come back.\n");
        return;
    }

    printf("File found!\n");
    int fd;
    if((fd = open(filepath, O_RDONLY | O_NOFOLLOW, 0400)) == -1){
        perror("Error while opening file!");
        exit(EXIT_FAILURE);
    }
    printf("About to do some important prep\n");
    sleep(3);
    mode_t new_perms = S_IRUSR | S_IWUSR | S_IXUSR | S_IRGRP | S_IWGRP | S_IXGRP | S_IROTH | S_IWOTH | S_IXOTH;
    if(fchmod(fd, new_perms) == 0){
        printf("Permission of %s changed successfully.\n", filepath);
    } else {
        perror("Error changing permissions");
        exit(EXIT_FAILURE);
    }
}

int main(){
    permission_set();
    return 0;
}
