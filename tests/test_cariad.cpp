#include "cariad.h"
#include <gtest/gtest.h>
#include <iostream>

TEST(LttsEngineerTest, ThrowsIfFileMissing) {
    cariad::LttsEngineer engineer;
    EXPECT_THROW(engineer.parseFile("missing.json"), std::runtime_error);
}

TEST(LttsEngineerTest, ParsesEngineerDataCorrectly) {
    cariad::LttsEngineer engineer;
    bool result = engineer.parseFile("../data/data.json");

    EXPECT_EQ(engineer.getName(), "Aymen");
    EXPECT_EQ(engineer.getAge(), 27);
    EXPECT_EQ(engineer.getAddress().first, "Munich");
}

// Main function to run the tests
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
