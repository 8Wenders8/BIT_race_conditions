#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h> 
#include <unistd.h>
#include <sys/stat.h>
#include <time.h>

void super_secure_permission_set(){
    const char* filepath = "./book.txt";
    printf("About to make your great book public from \"%s\"\n", filepath);
    if(access(filepath, F_OK) != -1){
        printf("File found! About to do some important prep\n");
        sleep(3);
        // Set chmod 777
        mode_t new_perms = S_IRUSR | S_IWUSR | S_IXUSR | S_IRGRP | S_IWGRP | S_IXGRP | S_IROTH | S_IWOTH | S_IXOTH;
        if(chmod(filepath, new_perms) == 0){
            printf("Permission of %s changed successfully.\n", filepath);
        } else {
            perror("Error changing permissions");
            exit(EXIT_FAILURE);
        }
    } else{
        printf("File not found! Write it first and then come back.\n");
    }
}

int main(){
    super_secure_permission_set();
    return 0;
}
