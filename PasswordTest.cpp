/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PasswordTest : public ::testing::Test
{
	protected:
		PasswordTest(){} //constructor runs before each test
		virtual ~PasswordTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PasswordTest, single_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1, actual);
}
TEST(PasswordTest, has_mixed_case_true)
{
    Password my_password;
    bool actual = my_password.has_mixed_case("Abc");
    ASSERT_TRUE(actual); // expects true because "Abc" has both uppercase and lowercase letters
}

TEST(PasswordTest, has_mixed_case_false_all_uppercase)
{
    Password my_password;
    bool actual = my_password.has_mixed_case("ABC");
    ASSERT_FALSE(actual); // expects false because "ABC" has no lowercase letters
}

TEST(PasswordTest, has_mixed_case_false_all_lowercase)
{
    Password my_password;
    bool actual = my_password.has_mixed_case("abc");
    ASSERT_FALSE(actual); // expects false because "abc" has no uppercase letters
}

TEST(PasswordTest, has_mixed_case_false_empty)
{
    Password my_password;
    bool actual = my_password.has_mixed_case("");
    ASSERT_FALSE(actual); // expects false because an empty string has no uppercase or lowercase letters
}

TEST(PasswordTest, has_mixed_case_false_single_character)
{
    Password my_password;
    bool actual = my_password.has_mixed_case("A");
    ASSERT_FALSE(actual); // expects false because "A" only has one uppercase letter (no lowercase letter)
}

TEST(PasswordTest, has_mixed_case_true_mixed_case)
{
    Password my_password;
    bool actual = my_password.has_mixed_case("aA");
    ASSERT_TRUE(actual); // expects true because "aA" contains both uppercase and lowercase letters
}