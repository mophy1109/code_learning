#include <iostream>
#include <stdio.h>

using namespace std;

#pragma pack(16)

typedef union {
    short i;
    int k[5];
    char c;
} Mat;

typedef struct {
    int i;
    Mat j;
    double k;
}Like;

int main()
{
    // printf("%d",sizeof(Like)+sizeof(Mat));
    long long res = (long long)2*3*5*7*11*13*17*19*23*29*31*37*41*43*47;
    cout << res <<endl;
}