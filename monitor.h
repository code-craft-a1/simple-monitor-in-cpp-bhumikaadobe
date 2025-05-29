#pragma once

bool isTemperatureOk(float temperature);  // check temperatue normal range

bool isPulseRateOk(float pulseRate);  // check pulse normal range

bool isSpo2Ok(float spo2);  // check spo2 normal range

int isVitalsOk(float temperature, float pulseRate, float spo2);  // check vitals normal range

void Alert(VitalStatus status);

enum class VitalStatus {
    OK,
    TempOutOfRange,
    PulseOutOfRange,
    Spo2OutOfRange
};
