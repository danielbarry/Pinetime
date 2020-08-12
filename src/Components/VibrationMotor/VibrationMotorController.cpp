#include <hal/nrf_gpio.h>
#include <libraries/log/nrf_log.h>
#include "VibrationMotorController.h"

using namespace Pinetime::Controllers;


void VibrationMotorController::Init() {
  nrf_gpio_cfg_output(pinVibrationMotor);
  Set(level);
}

void VibrationMotorController::Set(VibrationMotorController::Level level) {
  this->level = level;
  switch(level) {
    default:
    case Level::On:
      nrf_gpio_pin_clear(pinVibrationMotor);

      break;
    case Level::Off:
      nrf_gpio_pin_set(pinVibrationMotor);

      break;
  }
}

void VibrationMotorController::TurnOff() {
  //NRF_LOG_INFO("turnoff function called");
  switch(level) {
    case Level::On: Set(Level::Off); break;

    default: break;
  }
}

void VibrationMotorController::TurnOn() {
  switch(level) {
    case Level::Off: Set(Level::On); break;

    default: break;
  }
}

VibrationMotorController::Level VibrationMotorController::GetLevel() const {
  return level;
}

void VibrationMotorController::Backup() {
  backupLevel = level;
}

void VibrationMotorController::Restore() {
  Set(backupLevel);
}