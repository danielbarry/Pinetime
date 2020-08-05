#pragma once

#include <FreeRTOS.h>
#include <timers.h>
#include <libs/lvgl/src/lv_core/lv_style.h>
#include <libs/lvgl/src/lv_core/lv_obj.h>
#include <Components/VibrationMotor/VibrationMotorController.h>
#include "Screen.h"

namespace Pinetime {
  namespace Applications {
    namespace Screens {
      class Alarm: public Screen{
        public:

            Alarm(DisplayApp* app, Controllers::VibrationMotorController& vibrationmotor);
            ~Alarm() override;
            bool Refresh() override;
            bool OnButtonPushed() override;
            int month_number(char month_input[10]);
            int month_days(int num_of_month, int year);
            //bool OnTouchEvent(TouchEvents event) override;

       
        private:
            bool running = true;
            Controllers::VibrationMotorController& vibrationmotor;

            //functions
            void nextDDList();
            void alarmStart();
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