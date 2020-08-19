#include <cstring>
#include <cstdlib>
#include "AlarmController.h"
#include <SystemTask/SystemTask.h>

using namespace Pinetime::Controllers;

void xtimerCallback(TimerHandle_t xTimer){
    NRF_LOG_INFO("TIMER CALLED ");
    auto alarm = static_cast<AlarmController *>(pvTimerGetTimerID(xTimer));
    alarm ->alarmCallback();
}

AlarmController::AlarmController(Pinetime::System::SystemTask& systemTask, 
    Controllers::VibrationMotorController &vibrationmotor) : 
    systemTask{systemTask}, vibrationmotor{vibrationmotor} {

}

void AlarmController::setxTimer(int diff) {
    alarmTimer = xTimerCreate ("alarmTimer", pdMS_TO_TICKS(diff*60*1000), pdFALSE, this, xtimerCallback);
    xTimerStart(alarmTimer, 0);
    NRF_LOG_INFO("alarm started");
}

void AlarmController::alarmCallback() {
    NRF_LOG_INFO("vibration motor turned on");
    vibrationmotor.TurnOn();
    systemTask.PushMessage(Pinetime::System::SystemTask::Messages::OnAlarmGoOff);
}

