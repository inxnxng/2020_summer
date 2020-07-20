#include<iostream>
#include<string>
using namespace std;

class Base{};
class Derived:public Base{};


//���� override�� ���������� ���� �����ϰԲ� �ٲٷ���
// virtual double area() const = 0 ; 
// ��  0���� �ɾ��ָ� �ȴ�
class Text {
	string text;
public:
	Text(const string& s) :text(s) {}
	virtual string get() const { return text; }
	virtual void append(const string& extra) { text += extra; }
};


class FancyText : public Text {
	string left;
	string right;
	string con;
public:
	FancyText(const string& t, const string& l, const string& r, const string& c)
		:Text(t), left(l), right(r), con(c) {}

	string get() const override {
		return left + Text::get() + right;
	}

	void append(const string& extra) override {
		Text::append(con + extra);
	}
};

class FixedText : public Text {
public:
	FixedText() : Text("FIXED") {}
	void append(const string&) override {}
};

int main() {
	Text t1("plain");
	FancyText t2("fancy", "<<", ">>", "***");
	FixedText t3;
	std::cout << t1.get() << '\n';
	std::cout << t2.get() << '\n';
	std::cout << t3.get() << '\n';
	std::cout << "-------------------------\n";
	t1.append("A");
	t2.append("A");
	t3.append("A");
	std::cout << t1.get() << '\n';
	std::cout << t2.get() << '\n';
	std::cout << t3.get() << '\n';
	std::cout << "-------------------------\n";
	t1.append("B");
	t2.append("B");
	t3.append("B");
	std::cout << t1.get() << '\n';
	std::cout << t2.get() << '\n';
	std::cout << t3.get() << '\n';
}