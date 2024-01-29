/*
 * test.cpp
 *
 *  Created on: Dec 17, 2021
 *      Author: magnus
 */

#include <gtest/gtest.h>

TEST(CPPTemplate, testing)
{
	EXPECT_EQ("blue", "blue");
}

int main(int argc, char **argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
