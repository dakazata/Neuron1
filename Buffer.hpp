#ifndef BUFFER_H
#define BUFFER_H

#include <vector>

class Buffer
{
	private:
		std::vector<unsigned int> buffer_; //stores ints and then we multiply by j_amp
		const double delay_;
		
	public:
		//Constructor
		Buffer();
		
		//Destructor
		~Buffer() = default;
		
		void addJ(unsigned long);			//add a transmission spike
		
		unsigned int getJ(unsigned int) const;
		unsigned int getSize() const;		//getter de la taille
	
		unsigned int index(long time);
	
	
};
