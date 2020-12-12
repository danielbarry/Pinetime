#include "HeartRateTask.h"

using namespace Pinetime;

HeartRateTask::HeartRateTask(Pinetime::Drivers::Hrs3300& heartRateSensor) :
  heartRateSensor{heartRateSensor},
  heartRateController{*this}{
  /* TODO */
}

Pinetime::Controllers::HeartRate& HeartRateTask::getController(){
  return heartRateController;
}
