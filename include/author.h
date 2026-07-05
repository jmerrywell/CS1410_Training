#ifndef __AUTHOR_H__
#define __AUTHOR_H__

#include <iostream>
#include <string>


class Author {
private:
    std::string name, nationality;

public:
    Author(const std::string& name, const std::string& nationality);

    std::string getName() const;
    std::string getNationality() const;

    void setName(const std::string& name);
    void setNationality(const std::string& nat);

};

#endif
