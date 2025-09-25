#include "Account.hpp"


Account::Account()
{

}

Account::~Account()
{

}

/* getter for static methods and mumbers 
    static methods can only access static private members
    static members -> are created once , and shared by objects
*/
int Account::getNbAccounts(void){ return _nbAccounts;}
int Account::getTotalAmount(void) {return _totalAmount;}
int Account::getNbDeposits(void) {return _totalNbDeposits;}
int Account::getNbWithdrawals(void) { return _totalNbWithdrawals;}

void Account::displayAccountsInfos(void)
{



}



