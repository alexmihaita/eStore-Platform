#include "Address.h"

using namespace std;

Address::Address()
{
	this->number=0;
	this->apartment=0;
}

Address::Address(const Address &address)
{
	county=address.county;
	locality=address.locality;
	street=address.street;
	number=address.number;
	apartment=address.apartment;
	block=address.block;
}

Address::Address(const string &jud, const string &loc, const string &str, int nr, const string &bl, int ap)
{
	this->county=jud;
	this->locality=loc;
	this->street=str;
	this->number=nr;
	this->apartment=ap;
	this->block=bl;
}

const Address &Address::operator=(const Address &adr)
{
	county=adr.county;
	locality=adr.locality;
	street=adr.street;
	number=adr.number;
	apartment=adr.apartment;
	block=adr.block;
	return *this;
}

void Address::setStrada(const string &str)
{
	this->street=str;
}

void Address::setNumber(int nr)
{
	this->number=nr;
}

void Address::setBlock(const string &bl)
{
	this->block=bl;
}

void Address::setApartment(int ap)
{
	this->apartment=ap;
}

void Address::setCounty(const string &jud)
{
	this->county=jud;
}

void Address::setLocality(const string &loc)
{
	this->locality=loc;
}

string &Address::getStreet()
{
	return street;
}

int Address::getNumber()
{
	return number;
}
string &Address::getBlock()
{
	return block;
}

int Address::getApartment()
{
	return apartment;
}

string &Address::getCounty()
{
	return county;
}

string &Address::getLocality()
{
	return locality;
}

bool Address::operator==(const Address &address)
{
	return (this->locality==address.locality && this->apartment==address.apartment && this->block==address.block && this->street==address.street && this->county == address.county && this->number == address.number );
}

bool Address::operator!=(const Address &address)
{
	return !(this->locality==address.locality && this->apartment==address.apartment && this->block==address.block && this->street==address.street && this->county == address.county && this->number == address.number );
}

ostream &operator<<(ostream &os, const Address &a)
{
	os<<a.apartment;
	os<<a.block;
	os<<a.county;
	os<<a.locality;
	os<<a.number;
	os<<a.street;

	return os;
}

json Address::toJSON()
{
	return json(*this);
}