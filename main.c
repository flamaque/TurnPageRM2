#include <stdio.h>
#include <stdlib.h>
#include "ui.h"
#include "version.h"
#include "gestures.h"
#include "eventreader.h"
#include "keyinjector.h"
#include <memory.h>
#include <unistd.h>
#include <fcntl.h>
#include <linux/input.h>
#include <time.h>
#include "config.h"

bool verbose = false;
extern bool verbose;
void SwipePage(int x, int y, long time);

void SwipePage(int x, int y, long time)
{   //Misschien niet nodig om telkens EV_SYN op te roepen
    struct input_event key_input_event;
    //1
    memset(&key_input_event, 0, sizeof(key_input_event));
    key_input_event.type = EV_ABS;
    key_input_event.code = ABS_X; //ABS_MT_POSITION_X //53
    key_input_event.value = 1271;
    key_input_event.time.tv_sec = time;
    write(w, &key_input_event,sizeof(key_input_event));

    memset(&key_input_event, 0, sizeof(key_input_event));
    key_input_event.type = EV_ABS;
    key_input_event.code = ABS_Y; //ABS_MT_POSITION_Y //58
    key_input_event.value = 922;
    key_input_event.time.tv_sec = time;
    write(w, &key_input_event,sizeof(key_input_event));

    memset(&key_input_event, 0, sizeof(key_input_event));
    key_input_event.type = EV_ABS;
    key_input_event.code = ABS_MT_PRESSURE; //58
    key_input_event.value = 52;
    key_input_event.time.tv_sec = time;
    write(w, &key_input_event,sizeof(key_input_event));

    memset(&key_input_event, 0, sizeof(key_input_event));
    key_input_event.type = EV_ABS;
    key_input_event.code = ABS_MT_TOUCH_MINOR; //49
    key_input_event.value = 17;
    key_input_event.time.tv_sec = time;
    write(w, &key_input_event,sizeof(key_input_event));

    memset(&key_input_event, 0, sizeof(key_input_event));
    key_input_event.type = EV_ABS;
    key_input_event.code = ABS_MT_ORIENTATION; //52
    key_input_event.value = 2;
    key_input_event.time.tv_sec = time;
    write(w, &key_input_event,sizeof(key_input_event));

    memset(&key_input_event, 0, sizeof(key_input_event));
    key_input_event.type = EV_SYN;
    key_input_event.code = SYN_REPORT;
    key_input_event.time.tv_sec = time;
    write(w, &key_input_event,sizeof(key_input_event));
    //2
    memset(&key_input_event, 0, sizeof(key_input_event));
    key_input_event.type = EV_ABS;
    key_input_event.code = ABS_X; //ABS_MT_POSITION_X //53
    key_input_event.value = 1265;
    key_input_event.time.tv_sec = time;
    write(w, &key_input_event,sizeof(key_input_event));

    memset(&key_input_event, 0, sizeof(key_input_event));
    key_input_event.type = EV_ABS;
    key_input_event.code = ABS_Y; //ABS_MT_POSITION_Y //58
    key_input_event.value = 923;
    key_input_event.time.tv_sec = time;
    write(w, &key_input_event,sizeof(key_input_event));

    memset(&key_input_event, 0, sizeof(key_input_event));
    key_input_event.type = EV_ABS;
    key_input_event.code = ABS_MT_PRESSURE; //58
    key_input_event.value = 54;
    key_input_event.time.tv_sec = time;
    write(w, &key_input_event,sizeof(key_input_event));

    memset(&key_input_event, 0, sizeof(key_input_event));
    key_input_event.type = EV_SYN;
    key_input_event.code = SYN_REPORT;
    key_input_event.time.tv_sec = time;
    write(w, &key_input_event,sizeof(key_input_event));
    //3
    memset(&key_input_event, 0, sizeof(key_input_event));
    key_input_event.type = EV_ABS;
    key_input_event.code = ABS_X; //ABS_MT_POSITION_X //53
    key_input_event.value = 1257;
    key_input_event.time.tv_sec = time;
    write(w, &key_input_event,sizeof(key_input_event));

    memset(&key_input_event, 0, sizeof(key_input_event));
    key_input_event.type = EV_ABS;
    key_input_event.code = ABS_Y; //ABS_MT_POSITION_Y //58
    key_input_event.value = 926;
    key_input_event.time.tv_sec = time;
    write(w, &key_input_event,sizeof(key_input_event));

    memset(&key_input_event, 0, sizeof(key_input_event));
    key_input_event.type = EV_ABS;
    key_input_event.code = ABS_MT_PRESSURE; //58
    key_input_event.value = 53;
    key_input_event.time.tv_sec = time;
    write(w, &key_input_event,sizeof(key_input_event));

    memset(&key_input_event, 0, sizeof(key_input_event));
    key_input_event.type = EV_ABS;
    key_input_event.code = ABS_MT_TOUCH_MINOR; //49
    key_input_event.value = 8;
    key_input_event.time.tv_sec = time;
    write(w, &key_input_event,sizeof(key_input_event));

    memset(&key_input_event, 0, sizeof(key_input_event));
    key_input_event.type = EV_ABS;
    key_input_event.code = ABS_MT_ORIENTATION; //52
    key_input_event.value = 1;
    key_input_event.time.tv_sec = time;
    write(w, &key_input_event,sizeof(key_input_event));

    memset(&key_input_event, 0, sizeof(key_input_event));
    key_input_event.type = EV_SYN;
    key_input_event.code = SYN_REPORT;
    key_input_event.time.tv_sec = time;
    write(w, &key_input_event,sizeof(key_input_event));
    //3
    memset(&key_input_event, 0, sizeof(key_input_event));
    key_input_event.type = EV_ABS;
    key_input_event.code = ABS_X; //ABS_MT_POSITION_X //53
    key_input_event.value = 1244;
    key_input_event.time.tv_sec = time;
    write(w, &key_input_event,sizeof(key_input_event));

    memset(&key_input_event, 0, sizeof(key_input_event));
    key_input_event.type = EV_ABS;
    key_input_event.code = ABS_Y; //ABS_MT_POSITION_Y //58
    key_input_event.value = 928;
    key_input_event.time.tv_sec = time;
    write(w, &key_input_event,sizeof(key_input_event));

    memset(&key_input_event, 0, sizeof(key_input_event));
    key_input_event.type = EV_ABS;
    key_input_event.code = ABS_MT_PRESSURE; //58
    key_input_event.value = 50;
    key_input_event.time.tv_sec = time;
    write(w, &key_input_event,sizeof(key_input_event));

    memset(&key_input_event, 0, sizeof(key_input_event));
    key_input_event.type = EV_SYN;
    key_input_event.code = SYN_REPORT;
    key_input_event.time.tv_sec = time;
    write(w, &key_input_event,sizeof(key_input_event));
    //4
    memset(&key_input_event, 0, sizeof(key_input_event));
    key_input_event.type = EV_ABS;
    key_input_event.code = ABS_X; //ABS_MT_POSITION_X //53
    key_input_event.value = 1226;
    key_input_event.time.tv_sec = time;
    write(w, &key_input_event,sizeof(key_input_event));

    memset(&key_input_event, 0, sizeof(key_input_event));
    key_input_event.type = EV_ABS;
    key_input_event.code = ABS_Y; //ABS_MT_POSITION_Y //58
    key_input_event.value = 934;
    key_input_event.time.tv_sec = time;
    write(w, &key_input_event,sizeof(key_input_event));

    memset(&key_input_event, 0, sizeof(key_input_event));
    key_input_event.type = EV_ABS;
    key_input_event.code = ABS_MT_PRESSURE; //58
    key_input_event.value = 54;
    key_input_event.time.tv_sec = time;
    write(w, &key_input_event,sizeof(key_input_event));

    memset(&key_input_event, 0, sizeof(key_input_event));
    key_input_event.type = EV_ABS;
    key_input_event.code = ABS_MT_TOUCH_MINOR; //49
    key_input_event.value = 8;
    key_input_event.time.tv_sec = time;
    write(w, &key_input_event,sizeof(key_input_event));

    memset(&key_input_event, 0, sizeof(key_input_event));
    key_input_event.type = EV_ABS;
    key_input_event.code = ABS_MT_ORIENTATION; //52
    key_input_event.value = 2;
    key_input_event.time.tv_sec = time;
    write(w, &key_input_event,sizeof(key_input_event));

    memset(&key_input_event, 0, sizeof(key_input_event));
    key_input_event.type = EV_SYN;
    key_input_event.code = SYN_REPORT;
    key_input_event.time.tv_sec = time;
    write(w, &key_input_event,sizeof(key_input_event));
    //5
    memset(&key_input_event, 0, sizeof(key_input_event));
    key_input_event.type = EV_ABS;
    key_input_event.code = ABS_X; //ABS_MT_POSITION_X //53
    key_input_event.value = 1205;
    key_input_event.time.tv_sec = time;
    write(w, &key_input_event,sizeof(key_input_event));

    memset(&key_input_event, 0, sizeof(key_input_event));
    key_input_event.type = EV_ABS;
    key_input_event.code = ABS_Y; //ABS_MT_POSITION_Y //58
    key_input_event.value = 931;
    key_input_event.time.tv_sec = time;
    write(w, &key_input_event,sizeof(key_input_event));

    memset(&key_input_event, 0, sizeof(key_input_event));
    key_input_event.type = EV_ABS;
    key_input_event.code = ABS_MT_PRESSURE; //58
    key_input_event.value = 57;
    key_input_event.time.tv_sec = time;
    write(w, &key_input_event,sizeof(key_input_event));

    memset(&key_input_event, 0, sizeof(key_input_event));
    key_input_event.type = EV_SYN;
    key_input_event.code = SYN_REPORT;
    key_input_event.time.tv_sec = time;
    write(w, &key_input_event,sizeof(key_input_event));
    //6
    memset(&key_input_event, 0, sizeof(key_input_event));
    key_input_event.type = EV_ABS;
    key_input_event.code = ABS_X; //ABS_MT_POSITION_X //53
    key_input_event.value = 1181;
    key_input_event.time.tv_sec = time;
    write(w, &key_input_event,sizeof(key_input_event));

    memset(&key_input_event, 0, sizeof(key_input_event));
    key_input_event.type = EV_ABS;
    key_input_event.code = ABS_Y; //ABS_MT_POSITION_Y //58
    key_input_event.value = 934;
    key_input_event.time.tv_sec = time;
    write(w, &key_input_event,sizeof(key_input_event));

    memset(&key_input_event, 0, sizeof(key_input_event));
    key_input_event.type = EV_ABS;
    key_input_event.code = ABS_MT_PRESSURE; //58
    key_input_event.value = 61;
    key_input_event.time.tv_sec = time;
    write(w, &key_input_event,sizeof(key_input_event));

    memset(&key_input_event, 0, sizeof(key_input_event));
    key_input_event.type = EV_ABS;
    key_input_event.code = ABS_MT_TOUCH_MINOR; //49
    key_input_event.value = 17;
    key_input_event.time.tv_sec = time;
    write(w, &key_input_event,sizeof(key_input_event));

    memset(&key_input_event, 0, sizeof(key_input_event));
    key_input_event.type = EV_ABS;
    key_input_event.code = ABS_MT_ORIENTATION; //52
    key_input_event.value = 2;
    key_input_event.time.tv_sec = time;
    write(w, &key_input_event,sizeof(key_input_event));

    memset(&key_input_event, 0, sizeof(key_input_event));
    key_input_event.type = EV_SYN;
    key_input_event.code = SYN_REPORT;
    key_input_event.time.tv_sec = time;
    write(w, &key_input_event,sizeof(key_input_event));
    //7
    memset(&key_input_event, 0, sizeof(key_input_event));
    key_input_event.type = EV_ABS;
    key_input_event.code = ABS_X; //ABS_MT_POSITION_X //53
    key_input_event.value = 1108;
    key_input_event.time.tv_sec = time;
    write(w, &key_input_event,sizeof(key_input_event));

    memset(&key_input_event, 0, sizeof(key_input_event));
    key_input_event.type = EV_ABS;
    key_input_event.code = ABS_Y; //ABS_MT_POSITION_Y //58
    key_input_event.value = 922;
    key_input_event.time.tv_sec = time;
    write(w, &key_input_event,sizeof(key_input_event));

    memset(&key_input_event, 0, sizeof(key_input_event));
    key_input_event.type = EV_ABS;
    key_input_event.code = ABS_MT_PRESSURE; //58
    key_input_event.value = 61;
    key_input_event.time.tv_sec = time;
    write(w, &key_input_event,sizeof(key_input_event));

    memset(&key_input_event, 0, sizeof(key_input_event));
    key_input_event.type = EV_SYN;
    key_input_event.code = SYN_REPORT;
    key_input_event.time.tv_sec = time;
    write(w, &key_input_event,sizeof(key_input_event));
    //8
    memset(&key_input_event, 0, sizeof(key_input_event));
    key_input_event.type = EV_ABS;
    key_input_event.code = ABS_X; //ABS_MT_POSITION_X //53
    key_input_event.value = 1066;
    key_input_event.time.tv_sec = time;
    write(w, &key_input_event,sizeof(key_input_event));

    memset(&key_input_event, 0, sizeof(key_input_event));
    key_input_event.type = EV_ABS;
    key_input_event.code = ABS_Y; //ABS_MT_POSITION_Y //58
    key_input_event.value = 939;
    key_input_event.time.tv_sec = time;
    write(w, &key_input_event,sizeof(key_input_event));

    memset(&key_input_event, 0, sizeof(key_input_event));
    key_input_event.type = EV_SYN;
    key_input_event.code = SYN_REPORT;
    key_input_event.time.tv_sec = time;
    write(w, &key_input_event,sizeof(key_input_event));
    //9
    memset(&key_input_event, 0, sizeof(key_input_event));
    key_input_event.type = EV_ABS;
    key_input_event.code = ABS_X; //ABS_MT_POSITION_X //53
    key_input_event.value = 1018;
    key_input_event.time.tv_sec = time;
    write(w, &key_input_event,sizeof(key_input_event));

    memset(&key_input_event, 0, sizeof(key_input_event));
    key_input_event.type = EV_ABS;
    key_input_event.code = ABS_Y; //ABS_MT_POSITION_Y //58
    key_input_event.value = 940;
    key_input_event.time.tv_sec = time;
    write(w, &key_input_event,sizeof(key_input_event));

    memset(&key_input_event, 0, sizeof(key_input_event));
    key_input_event.type = EV_ABS;
    key_input_event.code = ABS_MT_PRESSURE; //58
    key_input_event.value = 62;
    key_input_event.time.tv_sec = time;
    write(w, &key_input_event,sizeof(key_input_event));

    memset(&key_input_event, 0, sizeof(key_input_event));
    key_input_event.type = EV_SYN;
    key_input_event.code = SYN_REPORT;
    key_input_event.time.tv_sec = time;
    write(w, &key_input_event,sizeof(key_input_event));
    //10
    memset(&key_input_event, 0, sizeof(key_input_event));
    key_input_event.type = EV_ABS;
    key_input_event.code = ABS_X; //ABS_MT_POSITION_X //53
    key_input_event.value = 971;
    key_input_event.time.tv_sec = time;
    write(w, &key_input_event,sizeof(key_input_event));

    memset(&key_input_event, 0, sizeof(key_input_event));
    key_input_event.type = EV_ABS;
    key_input_event.code = ABS_Y; //ABS_MT_POSITION_Y //58
    key_input_event.value = 941;
    key_input_event.time.tv_sec = time;
    write(w, &key_input_event,sizeof(key_input_event));

    memset(&key_input_event, 0, sizeof(key_input_event));
    key_input_event.type = EV_SYN;
    key_input_event.code = SYN_REPORT;
    key_input_event.time.tv_sec = time;
    write(w, &key_input_event,sizeof(key_input_event));
    //11
     memset(&key_input_event, 0, sizeof(key_input_event));
    key_input_event.type = EV_ABS;
    key_input_event.code = ABS_X; //ABS_MT_POSITION_X //53
    key_input_event.value = 930;
    key_input_event.time.tv_sec = time;
    write(w, &key_input_event,sizeof(key_input_event));

    memset(&key_input_event, 0, sizeof(key_input_event));
    key_input_event.type = EV_ABS;
    key_input_event.code = ABS_Y; //ABS_MT_POSITION_Y //58
    key_input_event.value = 942;
    key_input_event.time.tv_sec = time;
    write(w, &key_input_event,sizeof(key_input_event));

    memset(&key_input_event, 0, sizeof(key_input_event));
    key_input_event.type = EV_ABS;
    key_input_event.code = ABS_MT_PRESSURE; //58
    key_input_event.value = 56;
    key_input_event.time.tv_sec = time;
    write(w, &key_input_event,sizeof(key_input_event));

    memset(&key_input_event, 0, sizeof(key_input_event));
    key_input_event.type = EV_SYN;
    key_input_event.code = SYN_REPORT;
    key_input_event.time.tv_sec = time;
    write(w, &key_input_event,sizeof(key_input_event));

    //Not sure if needed
    memset(&key_input_event, 0, sizeof(key_input_event));
    key_input_event.type = EV_ABS;
    key_input_event.code = ABS_MT_TRACKING_ID; //57
    key_input_event.value = -1;
    key_input_event.time.tv_sec = time;
    write(w, &key_input_event,sizeof(key_input_event));

    memset(&key_input_event, 0, sizeof(key_input_event));
    key_input_event.type = EV_SYN;
    key_input_event.code = SYN_REPORT;
    key_input_event.time.tv_sec = time;
    write(w, &key_input_event,sizeof(key_input_event));
    
}


int main() {
    printf("touchinjector %s\n",VERSION);
   
    verbose = true; 

   while(1){
    delay(2000);
    SwipePage();
    delay(2000);
   }
    return 0;
} 
