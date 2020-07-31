#include <hal/nrf_gpio.h>
#include "VibrationMotorController.h"

using namespace Pinetime::Controllers;


void VibrationMotorController::Init() {
  nrf_gpio_cfg_output(pinVibrationMotor);
  Set(level);
}

void VibrationMotorController::Set(VibrationMotorController::Levels level) {
  this->level = level;
  switch(level) {
    default:
    case Levels::On:
      nrf_gpio_pin_clear(pinVibrationMotor);

      break;
    case Levels::Off:
      nrf_gpio_pin_set(pinVibrationMotor);

      break;
  }
}

void VibrationMotorController::TurnOff() {
  switch(level) {
    case Levels::On: Set(Levels::Off); break;

    default: break;
  }
}

void VibrationMotorController::TurnOn() {
  switch(level) {
    case Levels::Off: Set(Levels::On); break;

    default: break;
  }
}

VibrationMotorController::Levels VibrationMotorController::Level() const {
  return level;
}

void VibrationMotorController::Backup() {
  backupLevel = level;
}

void VibrationMotorController::Restore() {
  Set(backupLevel);
}