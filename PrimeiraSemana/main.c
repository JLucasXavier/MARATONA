#include <stdio.h>
#include "data.h"

int main()
{
    Data *d=dt_cria(10,9,2020);
    Data *r=dt_cria(1012016);
    
    printf("%s  %s\n",dt_to_string (d),dt_to_string (r));
    printf("%d\n",dt_comp(d,r));
    printf("%d\n",dt_difData (r,d));

    return 0;
}
