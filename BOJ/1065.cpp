#include <iostream>

int count = 0;

void Calc(int num) {
    int temp = num, chun = 0, bak = 0, sip = 0, il = 0, width;
    
    chun = temp / 1000;
    bak = (temp = temp - chun * 1000) / 100;
    sip = (temp = temp - bak * 100) / 10;
    il = temp - sip * 10;
    
    width = il - sip;
    
    
    if (num < 100 || (num >= 100 && (bak == (sip - width))) && num != 1000)
        count++;
}

int main(int argc, char* argv[]) {
    int number;
    
    scanf("%d", &number);
    
    for (int a = 1; a < number + 1; ++a) {
        Calc(a);
    }
    
    printf("%d\n", count);
    
    return 0;
}