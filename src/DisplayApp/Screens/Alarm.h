#pragma once

#include <FreeRTOS.h>
#include <timers.h>

#include <cstdint>
#include <chrono>
#include <libs/lvgl/src/lv_core/lv_style.h>
#include <libs/lvgl/src/lv_core/lv_obj.h>
#include <Components/Alarm/AlarmController.h>
#include "Screen.h"

namespace Pinetime {
  namespace Applications {
    namespace Screens {
      class Alarm: public Screen{
        public:

            Alarm(DisplayApp* app, 
            Controllers::DateTime &dateTimeController,
            Controllers::AlarmController &alarmController
            );
            ~Alarm() override;
            bool Refresh() override;
            bool OnButtonPushed() override;

            //bool OnTouchEvent(TouchEvents event) override;
            //functions
            void nextDDList();

       
        private:
            bool running = true;
            Controllers::DateTime& dateTimeController;
            Controllers::AlarmController &alarmController;

            //pointers to LVGL objects
            lv_obj_t* dd;
            lv_obj_t* label;
            lv_obj_t* btn1;

            //timer variable declaration
            TimerHandle_t alarmTimer;

            //variables for alarm information
            char month[9];
            int day;
            int hour;
            int minute;

            bool monthinputted = false;
            bool dayinputted = false;
            bool hourinputted = false;


      };
    }
  }
}