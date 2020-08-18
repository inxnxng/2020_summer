#include"11.1.h"

int main() {
	AdjMatGraph g;
	for (int i = 0; i < 4; i++) g.insertVertex('A' + i);
	g.insertEdge(0,1);
	g.insertEdge(0,3 );
	g.insertEdge(1,2 );
	g.insertEdge(1,3 );
	g.insertEdge(2,3);
	cout << "그래프 보여주기 " << endl;
	g.display();
	cout << endl;

	g.store("graph.txt");
	g.reset();
	g.load("graph.txt");
	cout << "저장된 그래프" << endl;
	g.display();
	return 0;
}