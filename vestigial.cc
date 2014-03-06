#include <iostream>
#include <memory>
#include <string>
#include <vector>
using namespace std;

class Sample {
public:
	~Sample(){
		cout << name << " died " << endl;
	};
	void what() {
		cout << name << " hat" << endl;
	}
	Sample() {};
private:
	Sample(const string n) {
		name = n;
	};
	friend class SampleOwner;
	string name;
};


class SampleOwner {
public:
	static Sample* createSample(const string n) {
		return new Sample(n);
	}
};

class ExtraSample : Sample {
public:
private:
	ExtraSample() {};
};

int main(int argc, char const *argv[])
{
	cout << "suppose I work\n";
	unique_ptr<Sample> s(SampleOwner::createSample("a"));
	unique_ptr<Sample> s2(SampleOwner::createSample("b"));
	s.reset(SampleOwner::createSample("c"));
	s.swap(s2);
	/* code */
	return 0;
}
