#include <iostream>
#include <array>
#include "bankaccount.h"

int main() {
  BankAccount a1;
  a1.setId("A001");
  a1.setOwnerName("Alice");
  a1.setBalance(1000.0);
  a1.setInterestRate(1.5);
  a1.setAccountType("Checking");
  a1.setIsActive(true);

  BankAccount a2("A002", "Bob");
  a2.setBalance(2500.0);
  a2.setInterestRate(2.0);
  a2.setAccountType("Savings");
  a2.setIsActive(true);

  BankAccount a3("A003", "Charlie", 500.0);
  a3.setInterestRate(0.75);
  a3.setAccountType("Checking");
  a3.setIsActive(false);

  BankAccount a4("A004", "Dana", 3000.0, 3.0, "Savings");
  a4.setIsActive(true);

  BankAccount* h1 = new BankAccount();
  h1->setId("H001");
  h1->setOwnerName("Eve");
  h1->setBalance(1500.0);
  h1->setInterestRate(1.2);
  h1->setAccountType("Checking");
  h1->setIsActive(true);

  BankAccount* h2 = new BankAccount("H002", "Frank");
  h2->setBalance(800.0);
  h2->setInterestRate(0.9);
  h2->setAccountType("Savings");
  h2->setIsActive(false);

  BankAccount* h3 = new BankAccount("H003", "Grace", 2200.0);
  h3->setInterestRate(2.5);
  h3->setAccountType("Money Market");
  h3->setIsActive(true);

  BankAccount* h4 = new BankAccount("H004", "Henry", 4000.0, 3.5, "Savings");
  h4->setIsActive(true);

  std::array<BankAccount, 8> accounts = {
    a1, a2, a3, a4,
    *h1, *h2, *h3, *h4
  };

  for (auto& acc : accounts) {
    std::cout << acc.str() << std::endl;
  }

  delete h1;
  delete h2;
  delete h3;
  delete h4;

  return 0;
}
