#include "HeartRateController.h"

using namespace Pinetime::Controllers;

HeartRate::HeartRate(Pinetime::HeartRateTask& heartRateTask) :
  heartRateTask{heartRateTask}{
  /* TODO */
}

void HeartRate::init(){
  updated = true; // TODO
  /* TODO: Implement this. */
}

void HeartRate::update(){
  /* TODO: Implement this. */
}

bool HeartRate::isUpdated(){
  return updated;
}

uint8_t HeartRate::getBpm(){
  /* TODO: Implement this. */
  return 69;
}
