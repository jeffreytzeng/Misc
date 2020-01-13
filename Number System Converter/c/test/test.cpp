#include <iostream>
#include "bdconverter.h"
#include "gtest/gtest.h"

class NumberConvertCheck : public testing::Test
{
	protected:
		virtual void SetUp(){}
		virtual void TearDown() {}
};

TEST(NumberConvertCheck, one_digit) {
	char input[10] = "5";
	// Compare cstring by capture stdout.
	char expect[20] = "DEC 5 = 0101\n";

	testing::internal::CaptureStdout();
	ShowD2B(input);
	std::string out = testing::internal::GetCapturedStdout();

	EXPECT_STREQ(expect, out.c_str());

	// Or compare cstring directly.
//	char *expect = D2B(input, expect, 4);
	// 1. Using strcmp to comapre two cstrings.
//	EXPECT_TRUE(strcmp("0101", expect) == 0);
	// 2. Using STREQ to compare two cstrings.
//	EXPECT_STREQ("0101", expect);
//	free(expect);
}

TEST(NumberConvertCheck, two_digits) {
	char input[10] = "12";
	char expect[20] = "DEC 12 = 1100\n";

	testing::internal::CaptureStdout();
	ShowD2B(input);
	std::string out = testing::internal::GetCapturedStdout();

	EXPECT_STREQ(expect, out.c_str());
}

TEST(NumberConvertCheck, three_digits) {
	char input[10] = "123";
	char expect[20] = "DEC 123 = 1111011\n";

	testing::internal::CaptureStdout();
	ShowD2B(input);
	std::string out = testing::internal::GetCapturedStdout();

	EXPECT_STREQ(expect, out.c_str());
}

TEST(NumberConvertCheck, sixteen_bits) {
	char input[10] = "188";
	char expect[40] = "DEC 188 = 10111100\n";

	testing::internal::CaptureStdout();
	ShowD2B(input);
	std::string out = testing::internal::GetCapturedStdout();

	EXPECT_STREQ(expect, out.c_str());
}
