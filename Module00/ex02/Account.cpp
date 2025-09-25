#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// constructor
Account::Account(int initial_deposit)
{
    _displayTimestamp();

    _accountIndex = _nbAccounts;
    _nbAccounts++;
    _amount = initial_deposit;
    _totalAmount += initial_deposit;
    // user still frech account
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    // time stamp if the account creation using _displayTimeStamp
    // __displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;

}

// destructor 
Account::~Account()
{
    _displayTimestamp();

	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

/* getter for static methods and mumbers 
    static methods can only access static private members
    static members -> are created once , and shared by objects
*/
// int Account::getNbAccounts(void){ return _nbAccounts;}
// int Account::getTotalAmount(void) {return _totalAmount;}
// int Account::getNbDeposits(void) {return _totalNbDeposits;}
// int Account::getNbWithdrawals(void) { return _totalNbWithdrawals;}

/* to make 
    -makeDeposit (deposit) -> the amount that the user want to put in the bank 
    -makeWithdrawal (withrawal) -> the amount the user want to withraw
    -checkAmount (void) -> how much money the user have in the bank
    -displayStatus (void) -> index; amount ; deposit ; withdawal
    -displayAcountInfos (void) -> account ; total ; deposits ; withdrawal
    -_timestamp() -> 1900 + year << month << day << hours << min << sec ;
*/

void Account::makeDeposit(int deposit)
{   
    _displayTimestamp();
     
    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";deposit:" << deposit;
    _amount += deposit;
    _totalAmount += deposit;
    _nbDeposits++;
    _totalNbDeposits++;
    // client amount and nbr deposit after makeDesposit
    std::cout << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
    _displayTimestamp();

    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount;
    if (withdrawal > _amount)
    {
        std::cout << ";withdrawal:" << "refused" << std::endl;
        return false;
    }
    _amount -= withdrawal;
    _totalNbWithdrawals++;
    _totalAmount -= withdrawal;
    _nbWithdrawals++;
    std::cout << ";withdrawal:" << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
    return true;
}

int Account::checkAmount(void) const
{
    return _amount;
}

void Account::displayStatus(void) const
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void Account::displayAccountsInfos(void)
{
    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount << ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void Account::_displayTimestamp()
{
    time_t now = time(0);
    tm *ltm = localtime(&now);

    std::cout << "["
              << 1900 + ltm->tm_year
              << std::setw(2) << std::setfill('0') << 1 + ltm->tm_mon
              << std::setw(2) << std::setfill('0') << ltm->tm_mday
              << "_"
              << std::setw(2) << std::setfill('0') << ltm->tm_hour
              << std::setw(2) << std::setfill('0') << ltm->tm_min
              << std::setw(2) << std::setfill('0') << ltm->tm_sec
              << "] ";
}