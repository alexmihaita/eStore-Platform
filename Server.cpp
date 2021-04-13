#include "Server.h"

using namespace std;

/* NU MODIFICATI */
Server::Server(){}

/* NU MODIFICATI */
Server *Server::GetInstance()
{
	if (!instance)
	{
		instance = new Server;
	}

	return instance;
}

/* NU MODIFICATI */
Server::~Server()
{
	if (instance != NULL)
		instance = NULL;

	if (!__UserID__ProductsCart__.empty())
		__UserID__ProductsCart__.clear();
}

void Server::set__UserID__ProductsCart__()
{
	/*list<User*>::iterator it;
	for( it = usr.begin(); it!=usr.end(); ++it) {
		 ShoppingCart* ob = new ShoppingCart(); 
		 User* temp=new User(*it);
		 //this->__UserID__ProductsCart__.insert(pair<int, ShoppingCart*>((*it).getUserId(), ob));
		 }*/

	ShoppingCart *shop = new ShoppingCart;
	for (auto it = this->usr.begin(); it != this->usr.end(); it++)
		this->__UserID__ProductsCart__.insert({(*it)->getUserID(), shop});
}

list<Product*>& Server::getProductsList()
{
	return this->prod;
	//throw("undefined");
}

list<User*>& Server::getUsersList()
{
	return this->usr;
	//throw("undefined");
}

map<int, ShoppingCart*> Server::get__UserID__ProductsCart__()
{
	return this->__UserID__ProductsCart__;
//	throw("undefined");
}

bool Server::requestAddProduct(int userID, int productID, int quantity)
{
	//throw("undefined");
}

bool Server::requestDeleteProduct(int userID, int productID, int quantity)
{
	//throw("undefined");
}

/* NU MODIFICATI */
void Server::populateProducts(const json &input)
{
	prod = ObjectFactory::getProductList(input["shoppingCart"]);
}

/* NU MODIFICATI */
void Server::populateUsers(const json &input)
{
	usr = ObjectFactory::getUserList(input["useri"]);
}