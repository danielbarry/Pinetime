#pragma once

#include <libs/lvgl/src/lv_core/lv_style.h>
#include <libs/lvgl/src/lv_core/lv_obj.h>
#include "Screen.h"

namespace Pinetime {
  namespace Applications {
    namespace Screens {
      class Alarm: public Screen{
        public:

            Alarm(DisplayApp* app);
            ~Alarm() override;
            bool Refresh() override;
            bool OnButtonPushed() override;
            int month_number(char month_input[10]);
            int month_days(int num_of_month, int year);
            //void nextdd_event(lv_obj_t* button, lv_event_t event);
       
        private:

            bool running = true;
            //pointers to LVGL objects





            


    
            
      };
    }
  }
}