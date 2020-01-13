#include <iostream>
#include "bdconverter.h"
#include "gtest/gtest.h"

class NumberConvertCheck : public testing::Test
{
	protected:
		virtual void SetUp(){}
		virtual void TearDown() {}
};

TEST(NumberConvertCheck, D2B_5) {
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

TEST(NumberConvertCheck, D2B_12) {
	char input[5] = "12";
	char expect[20] = "DEC 12 = 1100\n";

	testing::internal::CaptureStdout();
	ShowD2B(input);
	std::string out = testing::internal::GetCapturedStdout();

	EXPECT_STREQ(expect, out.c_str());
}

TEST(NumberConvertCheck, D2B_123) {
	char input[5] = "123";
	char expect[20] = "DEC 123 = 1111011\n";

	testing::internal::CaptureStdout();
	ShowD2B(input);
	std::string out = testing::internal::GetCapturedStdout();

	EXPECT_STREQ(expect, out.c_str());
}

TEST(NumberConvertCheck, D2B_188) {
	char input[5] = "188";
	char expect[40] = "DEC 188 = 10111100\n";

	testing::internal::CaptureStdout();
	ShowD2B(input);
	std::string out = testing::internal::GetCapturedStdout();

	EXPECT_STREQ(expect, out.c_str());
}

TEST(NumberConvertCheck, B2D_5) {
	char input[5] = "0101";
	char expect[40] = "BIN 0101 = 5\nDEC 0101 = 1100101\n";

	testing::internal::CaptureStdout();
	ShowB2D(input);
	std::string out = testing::internal::GetCapturedStdout();

	EXPECT_STREQ(expect, out.c_str());
}

TEST(NumberConvertCheck, B2D_12) {
	char input[5] = "1100";
	char expect[80] = "BIN 1100 = 12\nDEC 1100 = 10001001100\n";

	testing::internal::CaptureStdout();
	ShowB2D(input);
	std::string out = testing::internal::GetCapturedStdout();

	EXPECT_STREQ(expect, out.c_str());
}

TEST(NumberConvertCheck, B2D_123) {
	char input[10] = "1111011";
	char expect[80] = "BIN 1111011 = 123\nDEC 1111011 = 100001111001111100011\n";

	testing::internal::CaptureStdout();
	ShowB2D(input);
	std::string out = testing::internal::GetCapturedStdout();

	EXPECT_STREQ(expect, out.c_str());
}

TEST(NumberConvertCheck, B2D_188) {
	char input[10] = "10111100";
	char expect[100] = "BIN 10111100 = 188\nDEC 10111100 = 100110100100100001111100\n";

	testing::internal::CaptureStdout();
	ShowB2D(input);
	std::string out = testing::internal::GetCapturedStdout();

	EXPECT_STREQ(expect, out.c_str());
}