#ifndef PASSWORDRECOVERY_H
#define PASSWORDRECOVERY_H

#include "UserStorage.h"
#include <string>

class PasswordRecovery 
{
private:

    UserStorage& storage;

public:
    PasswordRecovery(UserStorage& storage);
    void resetPassword();
};

#endif // PASSWORDRECOVERY_H
