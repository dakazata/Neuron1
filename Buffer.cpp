#include "Buffer.hpp"
#include <iostream>

using namespace std;

Buffer::Buffer()
	: delay_(5)
{
	for (int i(0); i <= delay_ ; i++)
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
	buffer_[index(time + delay_)] += 1;
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
	return time % (delay_ + 1);
}

void Buffer::afficher() const
{
	for (size_t i(0) ; i < buffer_.size() ; i++)
	{
		cout << i << "-" << buffer_[i] << "   ";
	}
	cout << endl;
}