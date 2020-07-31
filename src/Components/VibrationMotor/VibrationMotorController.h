#pragma once

#include <cstdint>

namespace Pinetime {
  namespace Controllers {
    class VibrationMotorController {
    public:
      enum class Levels {Off, On};
      void Init();

      void Set(Levels level);
      Levels Level() const;
      void TurnOn();
      void TurnOff();

      void Backup();
      void Restore();

    private:
      static constexpr uint8_t pinVibrationMotor = 16;

      Levels level = Levels::Off;
      Levels backupLevel = Levels::Off;
    };
  }
}