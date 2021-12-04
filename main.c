

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//updated file
int get_available_items(char file[], char string[])
{
    FILE *fp;
    char line[30], ans[20], mode[]="r";
    int counter=0;
    fp=fopen(file,mode);
    if(fp==NULL)
    {
    printf("No file found.\n");
    }
    else
    {
        if(strcmp(string,"type")&&strcmp(string,"stone")&&strcmp(string,"authentic"))
        {
            printf("Unknown parameter to check...");
            counter=-1;
        }
        else
        {
            printf("I see that -%s- is important in this shipment. Any specific %s to count? ",string,string);
            fgets(ans,20,stdin);
            printf("Ok, I will keep count of the number of the following that I find: %s",ans);
            while(fgets(line, 30, fp)!=NULL)
            {
                if(!strcmp(string,"stone"))
                {
                    if(!strcmp(line,"diamond")||!strcmp(line,"ruby")||!strcmp(line,"sapphire"))
                    {
                        printf("%s",line);
                        if(!strcmp(line,ans))
                        {
                            counter++;
                        }
                    }
                }
                else if(!strcmp(string,"type"))
                {
                    if(!strcmp(line,"necklace")||!strcmp(line,"ring")||!strcmp(line,"bracelet"))
                    {
                        printf("%s",line);
                        if(!strcmp(line,ans))
                        {
                            counter++;
                        }
                    }
                }
                else if(!strcmp(string,"authentic"))
                {
                    if(!strcmp(line,"real")||!strcmp(line,"fake"))
                    {
                        printf("%s",line);
                        if(!strcmp(line,ans))
                        {
                            counter++;
                        }
                    }
                }
            }
        }
    }
    fclose(fp);
    return counter;
}
int main(int argc, char**argv)
{
    printf("This is to check the git push system\n");
    printf("%d\n",get_available_items("jewelry1.txt","stone"));
}
