#pragma once

#include "TwiMaster.h"

#define HRS3300_STATE_ENABLED   = 0b00000001 /* Device is on */
#define HRS3300_STATE_SLEEP     = 0b00000010 /* Sensor in low-current sleep */
#define HRS3300_STATE_INTERRUPT = 0b00000100 /* Interrupt triggered by slave */
#define HRS3300_STATE_READING   = 0b00001000 /* Currently reading */
#define HRS3300_STATE_WRITING   = 0b00010000 /* Currently writing */
#define HRS3300_STATE_ERROR     = 0b10000000 /* Error that requires restart */

namespace Pinetime {
  namespace Drivers {
    /**
     * Hrs3300.h
     *
     * Driver for the HRS3300 heart rate sensor. The intention is to provide very
     * simple information to the caller. This class handles twi send/receive,
     * conversion and even power management.
     **/
    class Hrs3300{
      public:
        struct Measurement{
          uint8_t bpm;
          uint32_t timestamp;
        };

      private:
        uint8_t state;
        Measurement measure;

      public:
        /**
         * Hrs3300()
         *
         * Initialise the variables required for running the heart rate sensor.
         *
         * @param master Access to the twi driver.
         * @param address The twi address of the slave device.
         **/
        Hrs3300(Pinetime::Drivers::TwiMaster& master, uint8_t address);

        /**
         * ~Hrs3300()
         *
         * Release resources allocated to this driver.
         **/
        ~Hrs3300();

        /**
         * init()
         *
         * Allow the device to be initialized.
         **/
        void init();

        /**
         * update()
         *
         * Allow the device to perform any required updates.
         **/
        void update();

        /**
         * getState()
         *
         * Get the current state of the heart rate sensor.
         *
         * @return Get the state of the heart rate sensor.
         **/
        uint8_t getState();

        /**
         * getMeasurement()
         *
         * Allow the latest measurement data to be read.
         *
         * @return The timestamped measurement data.
         **/
        Measurement getMeasurement();
    };
  }
}
