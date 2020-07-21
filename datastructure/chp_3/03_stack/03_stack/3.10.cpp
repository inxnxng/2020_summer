#include<iostream>
#include<stack>
using namespace std;

const int MAX = 6;

char map[MAX][MAX] = {
	{'1','1','1','1','1','1'},
	{'e','0','1','0','0','1'},
	{'1','0','0','0','1','1'},
	{'1','0','1','0','1','1'},
	{'1','0','1','0','0','x'},
	{'1','1','1','1','1','1'}
};

struct Location {
	int row;
	int col;
	Location(int r = 0, int c = 0)
		:row(r), col(c) {}
	bool isNeighbor(Location& p) {
		return((row == p.row && (col == p.col - 1 || col == p.col + 1))
			|| (col == p.col && (row == p.row - 1 || row == p.row + 1)));
	}
	bool operator== (Location& p) {
		return row == p.row && col == p.col;
	}
};

bool isValid(int r, int c) {
	if (r < 0 || r >= MAX || c < 0 || c >= MAX) { return false; }
	else return map[r][c] == '0' || map[r][c] == 'x';		//������ �´´ٸ� true�� �ƴ϶�� false��
}

void main() {
	//stack<Location> lost;		//��ġ ���� ��ü ����
	//lost.push(Location(1, 0));	//��ġ(1,0)�� push
	//Location p = lost.top();	//�ֱ� ��ġ p�� ����
	//lost.pop();					//�ֱ� ��ġ�� ����
	stack<Location> lost;
	Location entry(1, 0);
	lost.push(entry);

	while (lost.empty() == false) {
		Location here = lost.top();
		lost.pop();

		int r = here.row;
		int c = here.col;

		cout << "���� ��ġ�� (" << r << ", " << c << ")" << endl;
		if (map[r][c] == 'x') { cout << "�ⱸ ã��" << endl; return; }
		else {
			map[r][c] = '.';
			if (isValid(r-1, c)) lost.push(Location(r-1, c));
			if (isValid(r+1, c)) lost.push(Location(r+1, c));
			if (isValid(r, c-1)) lost.push(Location(r, c-1));
			if (isValid(r, c+1)) lost.push(Location(r, c+1));
		}
	}
	cout << "�̷� Ž�� ����" <<endl;
}