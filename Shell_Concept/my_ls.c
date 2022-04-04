#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>

#define FILENAME "/etc/passwd"

struct dirent
{
    ino_t d_ino;             /* inode number */
    off_t d_off;             /* not an offset; see NOTES */
    unsigned short d_reclen; /* length of this record */
    unsigned char d_type;    /* type of file; not supported
                                by all filesystem types */
    char d_name[256];        /* filename */
};

void my_ls(char[]);

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        my_ls(".");
    }
    else
    {
        while (--argc)
        {
            printf("arg=%s\n", *++argv);
            my_ls(*argv);
        }
    }
    return 0;
}

void my_ls(char dir_entry[])
{
    DIR *pDir;
    struct dirent *pCurDir;
    if ((pDir = opendir(dir_entry)) == NULL)
    {
        perror("read dir");
        exit(-1);
    }
    else
    {
        while ((pCurDir = readdir(pDir)) != NULL)
        {
            printf("%s\n", pCurDir->d_name);
        }
    }
}

