#include "LRUCache.h"

#include <algorithm>



using namespace std;



LRUCache::LRUCache(int capacity)

{

	this->capacity=capacity;
	lru.resize(capacity);
	lru.shrink_to_fit();

}



vector<int> LRUCache::processRequests(vector<int> requestsNo)

{

	
    vector<int> solve;
	for(unsigned int i = 0; i < requestsNo.size(); i++){    //am pus unsisgned int pentru a nu avea warnings.

        solve.push_back(requestsNo[i]);
	}

    //int k = 0;
	reverse(solve.begin(), solve.end());
	auto it=solve.begin();
    for(unsigned int i = 0; i < lru.capacity(); i++)
        {

            lru.at(i) = *it;  //lru avea capacity deja 4, fiecare element fiind initializat cu 0. Pentru a inlocui acele elemente, am folosit 'at'
            it++;
			solve.pop_back();
        }


    return lru;

}



int LRUCache::getCapacity()

{

	return this->capacity;

}



int LRUCache::getSize()

{

	return this->size;

	//throw("undefined");

}



vector<int> LRUCache::getLRU()

{

	return this->lru;

}



int LRUCache::getLRUCapacity()

{

	return this->getCapacity();

	//throw("undefined");

}



void LRUCache::setCapacity(int capacity)

{

	this->capacity=capacity;

	//throw("undefined");

}



void LRUCache::setLRU(vector<int> aux)

{

	this->lru=aux;

}


