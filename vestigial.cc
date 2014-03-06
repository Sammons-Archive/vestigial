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
	virtual string get_name() const = 0 ;
protected:
	string m_name;
private:

	mutable int getCounter = 0; 
};


class childA : parent {
public:
	~childA() {
		cout << this->get_name() << "child" << endl;
	}

	childA(const string name) : parent(name) {}
private:
	friend class factory;
};

class childC : childA {
public:
	~childC() {
		cout << this->get_name() << "child" << endl;
	}
	string get_name() const {
		return "no access";
	}
private:
	friend class factory;
	childC(const string name) : childA(name) {}
};

class childB : parent {
public:
	~childB() {
		cout << this->get_name();
	}
	string get_name() const {
		return this->get_name();
	}
private:
	friend class factory;
	childB(const string name) : parent(name) {}
};

class factory {
public:
	// parent* createParent(const string name) {
	// 	return new parent(name);
	// }
	childC* createChildC(const string name) {
		return new childC(name);
	}
	childB* createChildB(const string name) {
		return new childB(name);
	}
};

int main(int argc, char const *argv[])
{
	cout << "suppose I work\n";
	factory f;
	//unique_ptr<parent> par(f.createParent("james"));
	// unique_ptr<childA> p (f.createChildA("ben"));
	/* code */
	return 0;
}
