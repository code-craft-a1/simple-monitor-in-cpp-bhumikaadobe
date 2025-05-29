#pragma once

bool isTemperatureOk(float temperature); //check temperatue normal range

bool PulseRateOk(float pulseRate); //check pulse normal range

bool isSpo2Ok(float spo2);  //check spo2 normal range

int vitalsOk(float temperature, float pulseRate, float spo2); //check vitals normal range
