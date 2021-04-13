#include "ShoppingCart.h"



ShoppingCart::ShoppingCart()

{

	this->payMethod = "-";

}



ShoppingCart::ShoppingCart(const string &payMethod)

{

	this->payMethod=payMethod;

}



string &ShoppingCart::getPayMethod()

{

	return payMethod;

}



void ShoppingCart::setPayMethod(const string &payMethod)

{

	this->payMethod=payMethod;

}



void ShoppingCart::addProduct(int id, int quantity)

{

	this->shoppingCart[id]=quantity;

}



void ShoppingCart::raiseQuantity(int id, int quantity)

{
    int quantity1=this->shoppingCart[id];

	this->shoppingCart[id]=quantity1+quantity;

}



void ShoppingCart::lowerQuantity(int id, int quantity)

{
    int quantity1=this->shoppingCart[id];
    this->shoppingCart[id]=quantity1-quantity;

	//throw("undefined");

}



int ShoppingCart::getQuantity(int productID)

{
	if(shoppingCart[productID]==0)
		return -1;
	else
		return this->shoppingCart[productID];

}



void ShoppingCart::deleteProduct(int productID)

{

	shoppingCart.erase(productID);

}



map<int, int> &ShoppingCart::getShoppingCart()

{

	return shoppingCart;

}



void ShoppingCart::displayShoppingCart()

{

	//throw("undefined");

}

json ShoppingCart::toJSON()
{
  return json(*this);
}