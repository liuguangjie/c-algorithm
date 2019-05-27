#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
void printDir(const char *path) {
    DIR *dir;
    struct dirent *ptr;
    char base[1000];
    // 判断目录是不是存在
    dir = opendir(path);
    if(dir == NULL) {
        //printf("目录不存在\n");
        return;
    }

    while ((ptr = readdir(dir)) != NULL) 
    {
        if(strcmp(ptr->d_name,".")==0 || strcmp(ptr->d_name,"..")==0)    ///current dir OR parrent dir
        {   
            continue;
        }
        if (ptr->d_type == 4) // 4 目录 8 文件 10 链接文件
         {
            memset(base,'\0',sizeof(base)); // 初始化
            strcpy(base,path); // 追加 到 base
            strcat(base,"/"); // 追加 到 base
            strcat(base,ptr->d_name); // 追加 到 base
            printf("目录 %s\n", base);
            printDir(base);
        }
    }
}

int main()
{
    printDir("/usr");
    printf("hello world\n");
    return 0;
}