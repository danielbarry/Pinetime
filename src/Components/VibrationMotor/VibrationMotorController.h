#pragma once

#include <cstdint>

namespace Pinetime {
  namespace Controllers {
    class VibrationMotorController {
    public:
      enum class Level {Off, On};
      void Init();

      void Set(Level level);
      Level GetLevel() const;
      void TurnOn();
      void TurnOff();

      void Backup();
      void Restore();

    private:
      static constexpr uint8_t pinVibrationMotor = 16;

      Level level = Level::Off;
      Level backupLevel = Level::Off;
    };
  }
}