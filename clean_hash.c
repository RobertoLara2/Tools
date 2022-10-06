#include <stdio.h>
#include <stdlib.h>

void main(int argc, char *argv[])
{
        FILE *file_read,*file_write;
        char c;

        file_read = fopen(argv[1],"r");
        file_write = fopen(argv[2],"w");

        if(argv[1][0] == '-' && argv[1][1] == 'h')
        {
                printf("./clean hash_with_space_and_new_line.txt new_file.txt\n");
                exit(1);
        }
        else
        {
                if ((file_read == NULL || file_write == NULL) && argc == 3)
                {
                        printf("Error File\n");
                        exit(1);
                }
        }
        do
        {
                c = fgetc(file_read);
                while(c == 32 || c == 10)
                {
                        c = fgetc(file_read);
                }
                if(c != EOF)
                {
                        fputc(c, file_write);
                }
        }while(c != EOF);

        fputc('\n', file_write);
        fclose(file_read);
        fclose(file_write);
        printf("Done.\n");
}
