#include "author.h"

Author::Author(const std::string& name, const std::string& nationality): name(name), nationality(nationality) {}

std::string Author::getName() const{return name;}
std::string Author::getNationality() const{return nationality;}

void Author::setName(const std::string& name) {this->name = name;}
void Author::setNationality(const std::string& nat) {nationality = nat;}