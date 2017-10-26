#include "Buffer.hpp"
#include <iostream>
#include <cassert>


using namespace std;

Buffer::Buffer()
{
	for (int i(0); i <= D_STEPS ; i++)
	{
		buffer_.push_back(0);
	}
}

void Buffer::resetValue(long time)
{
	buffer_[index(time)] = 0;
}

//add a transmission spike
void Buffer::addJ(unsigned long time)
{
	assert(index(time + D_STEPS) <= buffer_.size());
	buffer_[index(time + D_STEPS)] += 1;
}			

unsigned int Buffer::getJ(long time)
{
	return buffer_[index(time)];
}

//getter du size du buffer	
unsigned int Buffer::getSize() const
{
	return buffer_.size();
}		

unsigned int Buffer::index(long time)
{
	return time % (D_STEPS+ 1);
}

void Buffer::afficher() const
{
	for (size_t i(0) ; i < buffer_.size() ; i++)
	{
		cout << i << "-" << buffer_[i] << "   ";
	}
	cout << endl;
}