#include "../header/UserProfile.h"

UserProfile::UserProfile(const std::string& firstName, const std::string& lastName, const std::string& dob)
    : firstName(firstName), lastName(lastName), dob(dob) {}

void UserProfile::setFirstName(const std::string& firstName) 
{
    this->firstName = firstName;
}

void UserProfile::setLastName(const std::string& lastName) 
{
    this->lastName = lastName;
}

void UserProfile::setDOB(const std::string& dob) 
{
    this->dob = dob;
}

std::string UserProfile::getFirstName() const 
{
    return firstName;
}

std::string UserProfile::getLastName() const 
{
    return lastName;
}

std::string UserProfile::getDOB() const 
{
    return dob;
}
