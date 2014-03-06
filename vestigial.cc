#include <iostream>
#include <memory>
using namespace std;

class Sample {
public:

private:
	friend class SampleOwner;
	Sample() {};
};

class SampleOwner {
public:
	static Sample* createSample() {
		return new Sample();
	}
};

int main(int argc, char const *argv[])
{
	cout << "suppose I work\n";
	unique_ptr<Sample> s(SampleOwner::createSample());
	/* code */
	return 0;
}
