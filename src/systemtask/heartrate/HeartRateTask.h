#pragma once

#include "drivers/Hrs3300.h"
#include "components/heartrate/HeartRateController.h"

namespace Pinetime{
  /**
   * TODO
   **/
  class HeartRateTask{
    private:
      Pinetime::Drivers::Hrs3300& heartRateSensor;
      Pinetime::Controllers::HeartRate heartRateController;

    public:
      /**
       * TODO
       **/
      HeartRateTask(Pinetime::Drivers::Hrs3300& heartRateSensor);

      /**
       * TODO
       **/
      Pinetime::Controllers::HeartRate& getController();
  };
}
