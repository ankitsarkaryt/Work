#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

main(int argc, char * argv[])
{
    FILE *fp;
    char ch;
    int sc = 0;

    fp = fopen(argv[1],"r");

    if(fp==NULL)
    {
        printf("Unable to open the flie",argv[1]);
    }

    else
    {
        while(!feof(fp))
        {
            ch = fgetc(fp);
            if(ch==' ')
            {
                sc++;
            }
        }
        printf("Number of spaces = %d",sc);
        printf("\n");
        fclose(fp);
    }

}