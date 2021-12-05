
//
//  Created by Alejandro Regalado 1001596630 on 9/12/21.
//  Word_Start.c

#include <stdio.h>

int main(int argc, const char * argv[])
{
    char word[20];
    printf("Please enter a word: ");
    scanf("%s",word);
    
    if(word[0]=='a'||word[0]=='A'||word[0]=='e'||word[0]=='E'||word[0]=='i'||word[0]=='I'||word[0]=='o'||word[0]=='O'||word[0]=='u'||word[0]=='U')
    {
        printf("%s starts with a vowel.\n",word);
    }
    
    else if((word[0]>='a'&&word[0]<='z')||(word[0]>='A'&&word[0]<='Z'))
    {
        printf("%s starts with a consonant\n",word);
    }
    
    else
    {
        printf("%s starts with neither a vowel nor a consonant.\n",word);
    }
    
    
}
