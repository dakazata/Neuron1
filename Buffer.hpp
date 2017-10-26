#ifndef BUFFER_H
#define BUFFER_H

#include <vector>
#include "Constants.hpp"

class Buffer
{
	private:
		std::vector<unsigned int> buffer_; //stores ints and then we multiply by j_amp
		
	public:
		//Constructor
		Buffer();
		
		//Destructor
		~Buffer() = default;
		
		void resetValue(long time);
		
		void addJ(unsigned long);			//add a transmission spike
		
		unsigned int getJ(long);
		
		unsigned int getSize() const;		//getter de la taille
	
		unsigned int index(long time);
	
		void afficher() const;
	
};

#endif