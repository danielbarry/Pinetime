#include "Hrs3300.h"

//#include "TwiMaster.cpp"

using namespace Pinetime::Drivers;

Hrs3300::Hrs3300(TwiMaster& master, uint8_t address){
  state = 0;
  measure.bpm = 0;
  measure.timestamp = 0;
  /* TODO: Initialise the variables associated with this driver. */
}

Hrs3300::~Hrs3300(){
  /* TODO: Release the allocated resources. */
}

void Hrs3300::init(){
  /* TODO: Initialise device. */
}

void Hrs3300::update(){
  /* TODO: Perform the update. */
}

uint8_t Hrs3300::getState(){
  return state;
}

Hrs3300::Measurement Hrs3300::getMeasurement(){
  return measure;
}
