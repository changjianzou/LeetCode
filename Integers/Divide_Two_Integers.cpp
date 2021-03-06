#include<climits>
#include<iostream>

using namespace std;
int divide(int dividend, int divisor) {


    long long dvd = dividend;
    long long div = divisor;
    bool sign = ( dvd >= 0 && div >= 0 ) || (dvd <= 0 && div <= 0) ? true : false;
    dvd = dvd > 0 ? dvd : -dvd;
    div = div > 0 ? div : -div;

    if(div == 0) return sign ? INT_MAX : INT_MIN;

    long long Q = 0;

    while(dvd >= div)
    {
        int i = -1;
        while(dvd >= div<<(i+1))
        {
            i++;
        }
        Q |= i == -1 ? 0 : 1<<i;
        dvd -= i == -1 ? 0 : div<<i;
    }

    if((int) (Q - 1) == INT_MAX)
    {
        return sign ? INT_MAX : INT_MIN;
    }

    return sign ? Q : -Q;
    }

void test(){
	int dividend = 1, divisor = 2;
	cout<<divide(dividend, divisor)<<endl;
}

int main(){
	test();
}
