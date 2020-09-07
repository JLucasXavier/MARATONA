#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str[100];

    while(1)
    {

        gets(str);
        printf("Normal: %s\n",str);
        str[0] = '\0';
        printf("Zerada: %s\n",str);
    }

    return 0;
}