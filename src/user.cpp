#include "user.hpp"
#include <iostream>

void User::setUserType(int userType)
{
    this->m_iuserType = userType;
}

int User::getUserType()
{
    return this->m_iuserType;
}