#pragma once

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
        private:

            bool running = true;
            //pointers to LVGL objects
            lv_obj_t* dd;

            //UI functions
            void nextdd_event(lv_obj_t* button, lv_event_t event);
            void dd_change(lv_obj_t* roller, lv_event_t event);
            int month_number(char month_input[10]);
            int month_days(int num_of_month, int year);
            
            //Variables for alarm information
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