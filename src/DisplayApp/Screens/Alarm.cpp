#include <cstdio>
#include <libs/date/includes/date/date.h>
#include <Components/DateTime/DateTimeController.h>

#include <libraries/log/nrf_log.h>
#include <libs/lvgl/lvgl.h>
#include "Alarm.h"
#include "../DisplayApp.h"


using namespace Pinetime::Applications::Screens;

int month_number(char month_input[10]) {

    
    if (strcmp(month_input, "January") == 0)
        return 1;
    else if (strcmp(month_input, "February") == 0)
        return 2;
    else if (strcmp(month_input, "March") == 0)
        return 3;
    else if (strcmp(month_input, "April") == 0)
        return 4;
    else if (strcmp(month_input, "May") == 0)
        return 5;
    else if (strcmp(month_input, "June") == 0)
        return 6;
    else if (strcmp(month_input, "July") == 0)
        return 7;
    else if (strcmp(month_input, "August") == 0)
        return 8;
    else if (strcmp(month_input, "September") == 0)
        return 9;
    else if (strcmp(month_input, "October") == 0)
        return 10;
    else if (strcmp(month_input, "November") == 0)
        return 11;
    else if (strcmp(month_input, "December") == 0)
        return 12;
    else
        return 0;            
}

int month_days(int num_of_month, int year) {
    if (num_of_month == 1 || num_of_month == 3 || num_of_month == 5 || num_of_month == 7 || num_of_month == 8 || num_of_month == 10 || num_of_month == 12)
        return 31;
    else if (num_of_month == 2) {
        if (year % 4 == 0)
            return 29;
        else
            return 28;
    }
    else
        return 30;
}

void xtimerCallback(TimerHandle_t xTimer){
    NRF_LOG_INFO("TIMER CALLED AFTER ONE MINUTE");
    auto alarm = static_cast<Alarm *>(pvTimerGetTimerID(xTimer));
    alarm ->alarmStart();
}

void nextdd_event(lv_obj_t* dropdown, lv_event_t event) {
    NRF_LOG_INFO("button pressed");
    if (event == LV_EVENT_RELEASED) {
        
        auto* ddList = static_cast<Alarm*>(dropdown->user_data);
        ddList->nextDDList();
    }    

}





Alarm::Alarm(Pinetime::Applications::DisplayApp* app, Controllers::VibrationMotorController& vibrationmotor, Controllers::DateTime& dateTimeController) : Screen(app), vibrationmotor{vibrationmotor}, dateTimeController{dateTimeController} {


    dd = lv_ddlist_create(lv_scr_act(), NULL);
    lv_obj_set_width(dd, LV_DPI * 2);
    lv_obj_set_height(dd, 50);
    lv_ddlist_set_options(dd, "January\nFebruary\nMarch\nApril\nMay\nJune\nJuly\nAugust\nSeptember\nOctober\nNovember\nDecember");
    lv_ddlist_set_fix_height(dd, 135);
    lv_obj_align(dd, NULL, LV_ALIGN_IN_TOP_MID, 0, 25);
    
    
    btn1 = lv_btn_create(lv_scr_act(), NULL);
    lv_obj_set_user_data(btn1, this);
    lv_obj_set_event_cb(btn1, nextdd_event);
    lv_obj_align(btn1, NULL, LV_ALIGN_IN_BOTTOM_MID, 0, -20);
    lv_btn_set_fit2(btn1, LV_FIT_TIGHT, LV_FIT_TIGHT);

    label = lv_label_create(btn1, NULL);
    lv_label_set_text(label, "Next");

}

void Alarm::nextDDList(){
    
        if (monthinputted == false) {

            lv_ddlist_get_selected_str(dd, month, 0);

            lv_ddlist_set_options(dd, "1\n2\n3\n4\n5\n6\n7\n8\n9\n10\n11\n12\n13\n14\n15\n16\n17\n18\n19\n20\n21\n22\n23\n24\n25\n26\n27\n28\n29\n30\n31");
            //lv_obj_set_style_local_value_str(dd, LV_CONT_PART_MAIN, LV_STATE_DEFAULT, "Day");
            monthinputted = true;
            NRF_LOG_INFO("%d", strlen(month));
            NRF_LOG_INFO("next");
        }
        else if (dayinputted == false) {
            char daystr[10];
            lv_ddlist_get_selected_str(dd, daystr, 0);
            day = atoi(daystr);
            
            lv_ddlist_set_options(dd, "0\n1\n2\n3\n4\n5\n6\n7\n8\n9\n10\n11\n12\n13\n14\n15\n16\n17\n18\n19\n20\n21\n22\n23");
            //v_obj_set_style_local_value_str(dd, LV_CONT_PART_MAIN, LV_STATE_DEFAULT, "Hour");
            dayinputted = true;
            NRF_LOG_INFO("%d", day);
            NRF_LOG_INFO("next");
        }
        else if (hourinputted == false) {
            char hourstr[10];
            lv_ddlist_get_selected_str(dd, hourstr, 0);
            hour = atoi(hourstr);

            lv_ddlist_set_options(dd, "00\n01\n02\n03\n04\n05\n06\n07\n08\n09\n10\n11\n12\n13\n14\n15\n16\n17\n18\n19\n20\n21\n22\n23\n24\n25\n26\n27\n28\n29\n30\n31\n32\n33\n34\n35\n36\n37\n38\n39\n40\n41\n42\n43\n44\n45\n46\n47\n48\n49\n50\n51\n52\n53\n54\n55\n56\n57\n58\n59");
            //lv_obj_set_style_local_value_str(dd, LV_CONT_PART_MAIN, LV_STATE_DEFAULT, "Minute");
            lv_label_set_text(label, "Set Alarm");
            hourinputted = true;
            NRF_LOG_INFO("%d", hour);
            
        }
        else {
            char minstr[10];
            lv_ddlist_get_selected_str(dd, minstr, 0);
            minute = atoi(minstr);

            uint8_t curmonth_num = dateTimeController.Month();
            uint8_t curday = dateTimeController.Day();
            uint8_t curhour = dateTimeController.Hours();
            uint8_t curmin = dateTimeController.Minutes();
            uint16_t curyear = dateTimeController.Year();
            /*char curmonth[10] = "January";
            int curday = 1;
            int curhour = 0;
            int curmin = 0;
            int curyear = 1970;
            int curmonth_num = month_number(curmonth);*/
            int month_num = month_number(month);
            int diff_mins = 0;
            int cur_num_minutes = (60*curhour)+curmin;
            int num_minutes = (60 * hour) + minute;
            
            if (curmonth_num < month_num) {
                diff_mins += month_days(curmonth_num, curyear) - curday;
                diff_mins += day;
                int i;
                for (i = curmonth_num + 1; i < month_num; i++) {
                    diff_mins += month_days(i, curyear);
                }
                diff_mins = (diff_mins * 24 * 60) - cur_num_minutes + num_minutes;
                NRF_LOG_INFO("%d", diff_mins);

            }
            else if (curmonth_num == month_num) {
                if (day > curday) {
                    diff_mins = day - curday;
                    diff_mins = (diff_mins * 24 * 60) - cur_num_minutes + num_minutes;

                }
                else if (day == curday) {

                    if (hour == curhour) {
                        if (minute > curmin) {
                            diff_mins = minute - curmin;
                        }
                        else if (minute == curmin) {
                            if ((curyear + 1) % 4 == 0)
                                diff_mins = 366 * 24 * 60;
                            else
                                diff_mins = 365 * 24 * 60;
                        }
                        else {
                            if ((curyear + 1) % 4 == 0)
                                diff_mins = ((24 * 60) - cur_num_minutes) + (365 * 24 * 60) + num_minutes;
                            else
                                diff_mins = ((24 * 60) - cur_num_minutes) + (365 * 24 * 60) + num_minutes;
                        }
                    }
                    else if (hour > curhour) {
                        diff_mins = num_minutes - cur_num_minutes;
                        NRF_LOG_INFO("%d", diff_mins);
                    }
                    else {
                        if((curyear + 1)%4 ==0)
                            diff_mins = ((24 * 60) - cur_num_minutes) + (365 * 24 * 60) + num_minutes;
                        else
                            diff_mins = ((24 * 60) - cur_num_minutes) + (365 * 24 * 60) + num_minutes;
                    }
                }
                else {
                    diff_mins += month_days(curmonth_num, curyear) - curday;
                    diff_mins += day;
                    int i;
                    for (i = curmonth_num + 1; i <= 12; i++) {
                        diff_mins += month_days(i, curyear);
                    }
                    for (i = 1; i < month_num; i++) {
                        diff_mins += month_days(i, curyear+1);
                    }
                    diff_mins = (diff_mins * 24 * 60) - cur_num_minutes + num_minutes;
                    NRF_LOG_INFO("%d", diff_mins);
                }
                NRF_LOG_INFO("%d", diff_mins);
            }
            else {
                diff_mins += month_days(curmonth_num, curyear) - curday;
                diff_mins += day;
                int i;
                for (i = curmonth_num + 1; i <= 12; i++) {
                    diff_mins += month_days(i, curyear);
                }
                for (i = 1; i < month_num; i++) {
                    diff_mins += month_days(i, curyear+1);
                }
                diff_mins = (diff_mins * 24 * 60) - cur_num_minutes + num_minutes;
                NRF_LOG_INFO("%d", diff_mins);
            }


            alarmTimer = xTimerCreate ("alarmTimer", pdMS_TO_TICKS(diff_mins*60*1000), pdFALSE, this, xtimerCallback);
            xTimerStart(alarmTimer, 0);
            NRF_LOG_INFO("alarm started");

        }

    
}

void Alarm::alarmStart(){
    vibrationmotor.TurnOn();
    NRF_LOG_INFO("vibration motor turned on");



}


Alarm::~Alarm() {
  lv_obj_clean(lv_scr_act());
}

bool Alarm::Refresh() {
  return running;
}

bool Alarm::OnButtonPushed() {
  running = false;
  return true;
}