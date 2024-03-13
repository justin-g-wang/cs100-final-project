#include "UserApplication.h"
#include "UserProfile.h"
#include "UserStorage.h"
#include "UserAuthentication.h"
#include <gtest/gtest.h>

TEST(UserProfileTest, CheckGetters&Setters) 
{
    // Creates A User Profile
    UserProfile user("John", "Doe", "1990-01-01");
    
    // Check Inital Values
    ASSERT_EQ(user.getFirstName(), "John");
    ASSERT_EQ(user.getLastName(), "Doe");
    ASSERT_EQ(user.getDOB(), "1990-01-01");
    
    // Change values
    user.setFirstName("Jane");
    user.setLastName("Smith");
    user.setDOB("1991-02-02");
    
    // Verify If Changes Worked
    ASSERT_EQ(user.getFirstName(), "Jane");
    ASSERT_EQ(user.getLastName(), "Smith");
    ASSERT_EQ(user.getDOB(), "1991-02-02");
}

int main(int argc, char **argv) 
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}