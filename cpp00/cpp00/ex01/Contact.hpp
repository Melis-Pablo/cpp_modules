#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <iomanip>

class Contact {
private:
    std::string _firstName;
    std::string _lastName;
    std::string _nickname;
    std::string _phoneNumber;
    std::string _darkestSecret;
    int         _index;

    std::string _printLen(std::string str) const;
    std::string _getInput(std::string str) const;

public:
    Contact();
    ~Contact();
    void    init(void);
    void    view(int index) const;
    void    display(int index) const;
    void    setIndex(int i);
};

#endif