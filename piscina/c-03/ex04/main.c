#include <stdio.h>
#include <string.h>
#include "ft_strstr.c"

int main()
{
    char primera[] = "jty";
    char segunda[] = "ty";
    
    printf("%s\n",strstr(primera,segunda));
    printf("%s",ft_strstr(primera,segunda));
}