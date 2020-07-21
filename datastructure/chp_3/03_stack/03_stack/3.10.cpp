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
	else return map[r][c] == '0' || map[r][c] == 'x';		//조건이 맞는다면 true를 아니라면 false를
}

void main() {
	//stack<Location> lost;		//위치 스택 객체 생성
	//lost.push(Location(1, 0));	//위치(1,0)을 push
	//Location p = lost.top();	//최근 위치 p에 복사
	//lost.pop();					//최근 위치를 삭제
	stack<Location> lost;
	Location entry(1, 0);
	lost.push(entry);

	while (lost.empty() == false) {
		Location here = lost.top();
		lost.pop();

		int r = here.row;
		int c = here.col;

		cout << "현재 위치는 (" << r << ", " << c << ")" << endl;
		if (map[r][c] == 'x') { cout << "출구 찾음" << endl; return; }
		else {
			map[r][c] = '.';
			if (isValid(r-1, c)) lost.push(Location(r-1, c));
			if (isValid(r+1, c)) lost.push(Location(r+1, c));
			if (isValid(r, c-1)) lost.push(Location(r, c-1));
			if (isValid(r, c+1)) lost.push(Location(r, c+1));
		}
	}
	cout << "미로 탐색 실패" <<endl;
}