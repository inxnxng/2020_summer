#include"9.1.h"

int main() {
	BinSrchTree tree;

	tree.insert(new BinaryNode(35));
	tree.insert(new BinaryNode(18));
	tree.insert(new BinaryNode(7));
	tree.insert(new BinaryNode(26));
	tree.insert(new BinaryNode(12));
	tree.insert(new BinaryNode(3));
	tree.insert(new BinaryNode(68));
	tree.insert(new BinaryNode(22));
	tree.insert(new BinaryNode(30));
	tree.insert(new BinaryNode(99));

	cout << tree.getCount() << endl;
	cout << tree.getLeafCount() << endl;
	cout << tree.getHeight() << endl;

	tree.inorder();
	tree.preorder();
	tree.postorder();
	tree.levelorder();

	tree.search(26);
	tree.search(25);

	cout << endl << endl << endl;

	tree.remove(3);
	tree.levelorder();
	tree.remove(68);
	tree.levelorder();
	tree.remove(29);

	return 0;
}