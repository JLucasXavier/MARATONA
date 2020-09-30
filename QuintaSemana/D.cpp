#include <iostream>
#include <math.h>

using namespace std;

double distancia(int x1,int y1,int x2,int y2){
    double tmp1=pow((x2-x1),2);
    double tmp2=pow((y2-y1),2);
    return sqrt(tmp1+tmp2);
}

int main(){
    printf("a distancia eh %0.2lf\n",distancia(150,750,0,600));
    printf("a distancia eh %0.2lf\n",distancia(0,600,0,300));
}