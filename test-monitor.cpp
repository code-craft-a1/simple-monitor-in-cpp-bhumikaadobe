#include <gtest/gtest.h>
#include "./monitor.h"

TEST(Monitor, NotOkWhenAnyVitalIsOffRange) {
  ASSERT_FALSE(vitalsOk(99, 102, 70));
  ASSERT_TRUE(vitalsOk(98.1, 70, 98));
}

TEST(Monitor, ValidateTemperature) 
{
    EXPECT_TRUE(isTemperatureOk(102.0));
    EXPECT_TRUE(isTemperatureOk(100.0));
    EXPECT_FALSE(isTemperatureOk(94.9));
    EXPECT_FALSE(isTemperatureOk(102.1));
}

TEST(Monitor, ValidatePulse) 
{
    EXPECT_TRUE(isPulseRateOk(65));
    EXPECT_TRUE(isPulseRateOk(99));
    EXPECT_FALSE(isPulseRateOk(59));
    EXPECT_FALSE(isPulseRateOk(101));
}

TEST(Monitor, ValidateSpo2) 
{
    EXPECT_TRUE(isSpO2Ok(92.0));
    EXPECT_FALSE(isSpO2Ok(89.9));
    EXPECT_TRUE(isSpO2Ok(90.0));
}
