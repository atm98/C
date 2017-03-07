#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
int main(void)
{

        DIR* dirp;
        struct dirent* direntp;
        dirp = opendir("/home/student1");
        if(dirp == NULL){
                perror("can't open /home");
        }
        else{
                for(;;){
                        direntp = readdir( dirp );
                        if(direntp == NULL ){
                                break;
                        }
                        printf("%s \n",direntp->d_name );
                }
        }
        closedir(dirp);

}
