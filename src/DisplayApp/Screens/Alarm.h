#pragma once

#include <FreeRTOS.h>
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
            //void nextdd_event(lv_obj_t* button, lv_event_t event);
            //bool OnTouchEvent(TouchEvents event) override;

       
        private:

            bool running = true;
            Controllers::VibrationMotorController& vibrationmotor;
            //pointers to LVGL objects





            


    
            
      };
    }
  }
}