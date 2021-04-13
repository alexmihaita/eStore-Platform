#include "Product.h"
using namespace std;

Product::~Product() {}

bool Product::checkQuantity(int requestedQuantity)
{
	throw("undefined");
}

Product::Product(const string &category, int id, const string &name, int quantity)
{
	this->category=category;
	this->id=id;
	this->name=name;
	this->quantity=quantity;
}

Product::Product(const Product &p)
{
	category=p.category;
	id=p.id;
	name=p.name;
	quantity=p.quantity;
}

Product::Product()
{
	id=0;
	quantity=0;
}

void Product::decreaseQuantity(int requestedQuantity)
{
	throw("undefined");
}

void Product::increaseQuantity(int requestedQuantity)
{
	throw("undefined");
}

void Product::setCategory(const string &category)
{
	this->category=category;
}

void Product::setId(int id)
{
	this->id=id;
}

void Product::setQuantity(int quantity)
{
	this->quantity=quantity;
}

void Product::setName(const string &name)
{
	this->name=name;
}

string &Product::getCategory()
{
	return category;
}

int Product::getQuantity()
{
	return quantity;
}

int Product::getId()
{
	return id;
}

string &Product::getName()
{
	return name;
}

const Product &Product::operator=(const Product &a)
{
	category=a.category;
	quantity=a.quantity;
	id=a.id;
	name=a.name;
	return *this;
}

json Product::toJSON()
{
	return json(*this);
}