#include<iostream>
#include<ctime>
using namespace std;


int sumAlgorithmA(int al) {
    int result = 0;
    result = al*(al+1)/2;
    return result;
}

int sumAlgorithmB(int a) {
    int result = 0;
    for (int i = 1; i <= a; i++) {
        result += i;
    }
    return result;
}

int sumAlgorithmC(int a) {
    int result = 0;
    for (int i = 0; i <= a; i++) {
        for (int j = 0; j < i; j++) {
            result++;
        }
    }
    return result;
}

int main() {
    double start, end, dif;
    start = clock();
    cout << "result A" << sumAlgorithmA(6000) << endl;
    end = clock();
    dif = end - start;
    cout << dif << endl;
    start = clock();
    cout << "result B" << sumAlgorithmB(6000) << endl;
    end = clock();
    dif = end - start;
    cout << dif << endl;
    start = clock();
    cout << "result C" << sumAlgorithmC(6000) << endl;
    end = clock();
    dif = end - start;
    cout << dif << endl;
}
