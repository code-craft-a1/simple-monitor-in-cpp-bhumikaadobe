#include <gtest/gtest.h>
#include "./monitor.h"

TEST(Monitor, NotOkWhenAnyVitalIsOffRange) {
  ASSERT_FALSE(vitalsOk(99, 102, 70));
  ASSERT_TRUE(vitalsOk(98.1, 70, 98));
}

TEST(Monitor, ValidateTemperature) {
    EXPECT_TRUE(isTemperatureOk(102.0));
    EXPECT_TRUE(isTemperatureOk(100.0));
    EXPECT_FALSE(isTemperatureOk(94.9));
    EXPECT_FALSE(isTemperatureOk(102.1));
}

TEST(Monitor, ValidatePulse) {
    EXPECT_TRUE(isPulseRateOk(65));
    EXPECT_TRUE(isPulseRateOk(99));
    EXPECT_FALSE(isPulseRateOk(59));
    EXPECT_FALSE(isPulseRateOk(101));
}

TEST(Monitor, ValidateSpo2) {
    EXPECT_TRUE(isSpo2Ok(92.0));
    EXPECT_FALSE(isSpo2Ok(89.9));
    EXPECT_TRUE(isSpo2Ok(90.0));
}

TEST(Monitor, Vitals) {
  ASSERT_TRUE(isVitalsOk(95, 60, 90));
  ASSERT_TRUE(isVitalsOk(102, 100, 90));
  ASSERT_FALSE(isVitalsOk(92.0, 65, 99));
  ASSERT_FALSE(isVitalsOk(102.1, 65, 96));
  ASSERT_FALSE(isVitalsOk(96, 59, 100));
  ASSERT_FALSE(isVitalsOk(97, 101, 99));
}
