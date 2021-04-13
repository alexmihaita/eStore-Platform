#include "QuerySolver.h"

using namespace std;

/* NU MODIFICATI */
QuerySolver::QuerySolver() 
{
  server = Server::GetInstance();
}

/* NU MODIFICATI */
QuerySolver::~QuerySolver()
{
  if (server != nullptr) 
  {
    server = nullptr;
  }
}

list<Product*> QuerySolver::Query_3a(){
  list<Product*> :: iterator it;
  list<Product*> solve;
  Product* produs= new DiscountedProduct;
  for(it=server->getProductsList().begin();it!=server->getProductsList().end();++it) {
    if((*it)->getCategory()=="espressor" && (*it)->getProductType()=="redus" ) {
     // DiscountedProduct redus=(*it)->;                         //metoda 1
   
     produs=*it;
     solve.push_back(produs);
     
      
    }

  }
  return solve;
/*for(it=server->getProductsList().begin();it!=server->getProductsList().end();it++) {
  if((*it)->getCategory().compare("espressor")!=0 || (*it)->getProductType().compare("redus")!=0) {          //metoda 2
    produs=*it;
    solve.remove(produs);
  }
}
return solve;*/
}

list<User*> QuerySolver::Query_3b(){
  list<User*> :: iterator it;
  list<User*> user;
  User* nonpremium= new BasicUser;
  float comp=11.5;
  for(it=server->getUsersList().begin();it!=server->getUsersList().end();++it) {
    if((*it)->getTransportCost()<=comp && (*it)->getUserType()=="basic") {
      nonpremium=*it;
      user.push_back(nonpremium);
    }
  }
  return user;
}

list<Product*> QuerySolver::Query_3c(){
  list<NonFoodProduct*>solve;
  list<Product*>solve1;
  for(auto it=server->getProductsList().begin();it!=server->getProductsList().end();it++) {
    if((*it)->getProductType()=="resigilat") {
  
      ResealedProduct *x = dynamic_cast<ResealedProduct*>(*it);
      if(x->getReason()=="lipsa_accesorii" ) {
        solve.push_back(x);
      }
  }
  }
   solve.sort(Utility::compareProduct);
   for(auto it1=solve.begin();it1!=solve.end();it1++) {
     solve1.push_back(*it1);
   }
   return solve1;
}

list<Product*> QuerySolver::Query_3d(){
  list<FoodProduct*>alimente;
  list<Product*>alimente_returnate;
  for(auto it=server->getProductsList().begin();it!=server->getProductsList().end();it++) {
    if((*it)->getProductType()=="alimentar") {
      FoodProduct *x=dynamic_cast<FoodProduct*>(*it);
      alimente.push_back(x);
    }
  }
  alimente.sort(Utility::compareFood);
  for(auto it1=alimente.begin();it1!=alimente.end();it1++) {
    alimente_returnate.push_back(*it1);
  }
  return alimente_returnate;

}

string QuerySolver::countRepetition()
{ 

    unordered_map<string, int> mp; 

    for (auto it=server->getUsersList().begin(); it!=server->getUsersList().end(); it++)  {

        mp[(*it)->getDeliveryData().getCounty()]++; 
    }

    int valoare = 0;
    string key;
for(auto it = mp.cbegin(); it != mp.cend(); ++it ) {
    if (it ->second > valoare) {
        key = it->first;
        valoare = it->second;
    }
}
return key;
}

list<User*> QuerySolver::Query_3e(){
  list<int> m;
  list<User*> useri;
  for(auto it=server->getUsersList().begin();it!=server->getUsersList().end();it++) {
    if(((*it)->getDeliveryData().getBlock()=="-" || (*it)->getBillingData().getBlock()=="-") && ((*it)->getDeliveryData().getCounty()==this->countRepetition() && (*it)->getBillingData().getCounty()==this->countRepetition())) {
      useri.push_back(*it);
    }
  }
  useri.sort(Utility::compareUser);
  return useri;
}

list < User* > QuerySolver::Query_3f() {

    list < User* > utilizatori_noi;
    for (auto it_utilizator = server->getUsersList().begin(); it_utilizator != server->getUsersList().end(); it_utilizator++) {

        if ((*it_utilizator)->getUserType() == "premium") {
            User* user = new PremiumUser;
            PremiumUser* utilizator_premium;
            user = *it_utilizator;
            utilizator_premium = dynamic_cast <PremiumUser*> (user);
            for (auto it_produs = server->getProductsList().begin(); it_produs != server->getProductsList().end(); it_produs++) {
                for (auto it_discount = utilizator_premium->getDiscounts().begin(); it_discount != utilizator_premium->getDiscounts().end(); it_discount++) {
                    if (((*it_produs)->getCategory() == "telefon" || (*it_produs)->getCategory() == "imprimanta") && (it_discount->first == (*it_produs)->getId())){
                        utilizatori_noi.push_back((*it_utilizator));
                             break;
                             
                    }
                    //break;
                }
                //break;
            }    
            utilizatori_noi.unique();
             // break;
              //jump:;
            
              
        }
    }
    return utilizatori_noi;
}