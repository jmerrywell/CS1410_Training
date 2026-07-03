/*
 * PLAN
 * ----
 * Class choice:     BankAccount — models a real bank account.
 * Data members:     id (std::string)          — unique account ID
 *                   ownerName (std::string)   — account holder name
 *                   balance (double)          — current balance
 *                   interestRate (double)     — annual interest rate (%)
 *                   accountType (std::string) — "Checking", "Savings", etc.
 *                   isActive (bool)           — whether the account is open
 * Constructors:     (1) No-arg: all defaults/empty.
 *                   (2) id, ownerName.
 *                   (3) id, ownerName, balance.
 *                   (4) id, ownerName, balance, interestRate, accountType.
 * Design decision:  I chose BankAccount because these fields naturally fit
 *                   together and could be used in a real finance app. I added
 *                   isActive to represent whether the account is open.
 */

#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <string>
#include <sstream>

class BankAccount {
private:
  std::string id;
  std::string ownerName;
  double balance;
  double interestRate;
  std::string accountType;
  bool isActive;

public:
  BankAccount()
      : id(""), ownerName(""), balance(0.0), interestRate(0.0),
        accountType(""), isActive(false) {}

  BankAccount(const std::string& i, const std::string& o)
      : id(i), ownerName(o), balance(0.0), interestRate(0.0),
        accountType(""), isActive(false) {}

  BankAccount(const std::string& i, const std::string& o, double b)
      : id(i), ownerName(o), balance(b), interestRate(0.0),
        accountType(""), isActive(false) {}

  BankAccount(const std::string& i, const std::string& o,
              double b, double ir, const std::string& at)
      : id(i), ownerName(o), balance(b), interestRate(ir),
        accountType(at), isActive(true) {}

  ~BankAccount() = default;

  const std::string& getId() const { return id; }
  const std::string& getOwnerName() const { return ownerName; }
  double getBalance() const { return balance; }
  double getInterestRate() const { return interestRate; }
  const std::string& getAccountType() const { return accountType; }
  bool getIsActive() const { return isActive; }

  void setId(const std::string& i) { id = i; }
  void setOwnerName(const std::string& o) { ownerName = o; }
  void setBalance(double b) { balance = b; }
  void setInterestRate(double ir) { interestRate = ir; }
  void setAccountType(const std::string& at) { accountType = at; }
  void setIsActive(bool active) { isActive = active; }

  std::string str() const {
    std::ostringstream out;
    out << "          ID: " << id              << "\n"
        << "    OWNER NAME: " << ownerName     << "\n"
        << "       BALANCE: " << balance       << "\n"
        << " INTEREST RATE: " << interestRate  << "\n"
        << "   ACCOUNT TYPE: " << accountType  << "\n"
        << "       IS ACTIVE: " << (isActive ? "true" : "false") << "\n";
    return out.str();
  }
};

#endif
