#include <iostream>
#include <memory>
#include <string>
#include <vector>
using namespace std;

class gorgeous {
public:
private:
};

class parent {
public:
	~parent() {
		cout << m_name << endl;
	}
	parent(const string name) {
		m_name = name;
	};
	string get_name() const {
		getCounter++;
		return m_name;
	}
private:
	string m_name;
	mutable int getCounter = 0; 
};

class childA : parent {
public:
	~childA() {
		cout << this->get_name() << "child" << endl;
	}
private:
	friend class factory;
	childA(const string name) : parent(name) {}
};

class childB : parent {
public:
	~childB() {
		cout << this->get_name();
	}

private:
	friend class factory;
	childB(const string name) : parent(name) {}
};

class factory {
public:
	childA* createChildA(const string name) {
		return new childA(name);
	}
	childB* createChildB(const string name) {
		return new childB(name);
	}
};

int main(int argc, char const *argv[])
{
	cout << "suppose I work\n";
	factory f;
	unique_ptr<childA> p (f.createChildA("ben"));
	/* code */
	return 0;
}
