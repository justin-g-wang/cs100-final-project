#ifndef USERPROFILE_H
#define USERPROFILE_H

#include <string>

class UserProfile {

private:
    std::string firstName;
    std::string lastName;
    std::string dob; //  YYYY-MM-DD

public:
// default user profile
    UserProfile() = default;
    // userprofile , has firstname , last name , and dob
    UserProfile(const std::string& firstName, const std::string& lastName, const std::string& dob);

// setters for profile
    void setFirstName(const std::string& firstName);
    void setLastName(const std::string& lastName);
    void setDOB(const std::string& dob);

// getters for profiles
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getDOB() const;
};

#endif // USERPROFILE_H
