#include<iostream>
using namespace std;

//막대 from에 놓여잇는 n개의 원판을 막대 tmp를 사용하여 막대 to로 옮긴다
void hanoiTower(int n, char from, char tmp, char to) {
	if (n == 1){
		cout << "원판 1을 " << from << "에서 " << to << "로 옮긴다." << endl; }
	else {
		hanoiTower(n - 1, from, to, tmp);
		cout << "원판 " <<n<< "을 "<< from << "에서 " << to << "로 옮긴다." << endl;
		hanoiTower(n - 1, tmp, from, to);
	}
}

int main() {
	hanoiTower(7, 'A', 'B', 'C');
}