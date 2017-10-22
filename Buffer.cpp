#include "Buffer.h"

Buffer::Buffer()
	: delay_(5)
{
	for (size_t i(0); i <= delay_ ; i++)
	{
		buffer_.push_back(0);
	}
}

//add a transmission spike
void Buffer::addJ(unsigned long time)
{
	buffer_[index(time + delay_)] += 1;
}			

unsigned int Buffer::getJ(unsigned int time) const
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
	return time%(delay_ + 1);
}
