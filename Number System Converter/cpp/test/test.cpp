#include "gtest/gtest.h"
#include "bdconverter.hpp"

// Member function pointer.
typedef void (BDConverter::*fptr)();

class BDTester : public testing::Test
{
	public:
		void Check(fptr f) {
			::testing::internal::CaptureStdout();
			[&](BDConverter *b) { (b->*f)();}(bd_);
			output_ = ::testing::internal::GetCapturedStdout();
		}
			
	protected:
		virtual void SetUp() override {
			bd_ = new BDConverter;
		}
		virtual void TearDown() override {
			delete bd_;
		}

		BDConverter *bd_;
		std::string output_;
};

TEST_F(BDTester, B2D_5) {
	bd_->GetInput("0101");
	Check(bd_->ShowB2D);
	EXPECT_STREQ("BIN 0101 = 5\nDEC 0101 = 1100101\n", output_.c_str());
}

TEST_F(BDTester, B2D_12) {
	bd_->GetInput("1100");
	Check(bd_->ShowB2D);
	EXPECT_STREQ("BIN 1100 = 12\nDEC 1100 = 10001001100\n", output_.c_str());
}

TEST_F(BDTester, B2D_123) {
	bd_->GetInput("01111011");
	Check(bd_->ShowB2D);
	EXPECT_STREQ("BIN 01111011 = 123\nDEC 01111011 = 100001111001111100011\n", output_.c_str());
}

TEST_F(BDTester, B2D_188) {
	bd_->GetInput("10111100");
	Check(bd_->ShowB2D);
	EXPECT_STREQ("BIN 10111100 = 188\nDEC 10111100 = 100110100100100001111100\n", output_.c_str());
}


TEST_F(BDTester, D2B_5) {
	bd_->GetInput("5");
	Check(bd_->ShowD2B);
	EXPECT_STREQ("DEC 5 = 101\n", output_.c_str());
}

TEST_F(BDTester, D2B_12) {
	bd_->GetInput("12");
	Check(bd_->ShowD2B);
	EXPECT_STREQ("DEC 12 = 1100\n", output_.c_str());
}

TEST_F(BDTester, D2B_123) {
	bd_->GetInput("123");
	Check(bd_->ShowD2B);
	EXPECT_STREQ("DEC 123 = 1111011\n", output_.c_str());
}

TEST_F(BDTester, D2B_188) {
	bd_->GetInput("188");
	Check(bd_->ShowD2B);
	EXPECT_STREQ("DEC 188 = 10111100\n", output_.c_str());
}