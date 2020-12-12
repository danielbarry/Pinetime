#pragma once

#include <cstdint>

namespace Pinetime{
  class HeartRateTask;
  namespace Controllers{
    /**
     * HeartRate
     *
     * Allow information about the state of the heart rate sensor to be used in
     * the UI.
     **/
    class HeartRate{
      private:
        Pinetime::HeartRateTask& heartRateTask;
        bool updated;
        uint8_t bpm;

      public:
        /**
         * TODO
         **/
        HeartRate(Pinetime::HeartRateTask& heartRateTask);

        /**
         * init()
         *
         * Allow the heart rate sensor to be initialized.
         **/
        void init();

        /**
         * update()
         *
         * Allow the heart rate sensor to be updated.
         **/
        void update();

        /**
         * isUpdated()
         *
         * Test whether the values have been updated.
         *
         * @return True if the values have been updated, otherwise false.
         **/
        bool isUpdated();

        /**
         * getBpm()
         *
         * Get the current heart rate value (beats per minute).
         *
         * @return The current heart rate value.
         **/
        uint8_t getBpm();
    };
  }
}
