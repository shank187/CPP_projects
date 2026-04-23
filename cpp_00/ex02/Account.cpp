#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;


Account::Account( int initial_deposit )
{
    _amount = initial_deposit;
    _totalAmount += initial_deposit;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    _displayTimestamp();
    _accountIndex = _nbAccounts;
    std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
    _nbAccounts++;
}

Account::~Account(void)
{
    _totalAmount -= _amount;
    _nbAccounts--;
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

void Account::_displayTimestamp(void)
{
    std::time_t now = std::time(NULL);
    std::tm *ltm = std::localtime(&now);
    char buffer[20];
    std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S]", ltm);
    std::cout << buffer;
}

int Account::getNbAccounts(void)
{
    return _nbAccounts;
}
int Account::getTotalAmount(void)
{
    return _totalAmount;
}
int Account::getNbDeposits(void)
{
    return _totalNbDeposits;
}
int Account::getNbWithdrawals(void)
{
    return _totalNbWithdrawals;
}

void	Account::makeDeposit(int deposit)
{
    int p_amount = _amount;
    _amount += deposit;
    _totalAmount += deposit;
    _totalNbDeposits++;
    _nbDeposits++;
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";p_amount:" << p_amount << ";deposit:" << deposit << ";amount:" << _amount << ";nb_deposits:" <<  _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
    int p_amount = _amount;
    _amount -= withdrawal;
    if (_amount < 0)
    {
        _amount += withdrawal;
        _displayTimestamp();
        std::cout << " index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:refused" << std::endl;
        return false;
    }
    _displayTimestamp();
    _totalNbWithdrawals++;
    _nbWithdrawals++;
    _totalAmount -= withdrawal;
    std::cout << " index:" << _accountIndex << ";p_amount:" << p_amount << ";withdrawal:" << withdrawal <<  ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
    return true;
}

int		Account::checkAmount(void) const
{
    return(_amount);
}

void	Account::displayStatus(void) const
{
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void Account::displayAccountsInfos(void)
{
    _displayTimestamp();
    std::cout << " accounts:" << _nbAccounts << ";total:" << _totalAmount << ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

