#include "./monitor.h"
#include <iostream>
#include <thread>
#include <chrono>

using std::cout, std::flush, std::this_thread::sleep_for, std::chrono::seconds;

bool isTemperatureOk(float temperature) {
  return temperature >= 95 && temperature <= 102;
}

bool isPulseRateOk(float pulseRate) {
  return pulseRate >= 60 && pulseRate <= 100;
}

bool isSpo2Ok(float spo2) {
  return spo2 >= 90;
}

void showMessage(VitalStatus status) {
    switch (status) {
        case VitalStatus::TempOutOfRange:
            cout << "Temperature is critical!\n";
            break;
        case VitalStatus::PulseOutOfRange:
            cout << "Pulse Rate is out of range!\n";
            break;
        case VitalStatus::Spo2OutOfRange:
            cout << "Oxygen Saturation out of range!\n";
            break;
        default:
            return;
    }
}

void Alert(VitalStatus status) {
    showMessage(status);
    for (int i = 0; i < 6; i++) {
        cout << "\r* " << flush;
        sleep_for(seconds(1));
        cout << "\r *" << flush;
        sleep_for(seconds(1));
    }
}

int isVitalsOk(float temperature, float pulseRate, float spo2) {
  if(isTemperatureOk(temperature) && isPulseRateOk(pulseRate) && isSpo2Ok(spo2))
    return 1;
  if (!isTemperatureOk(temperature))
    Alert(VitalStatus::TempOutOfRange);
  if (!isPulseRateOk(pulseRate))
    Alert(VitalStatus::PulseOutOfRange);
  if (!isSpo2Ok(spo2))
    Alert(VitalStatus::Spo2OutOfRange);
  return 0;
}

