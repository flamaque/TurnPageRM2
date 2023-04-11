#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <unistd.h>
#include <fcntl.h>
#include <linux/input.h>
#include <time.h>
#include "ui.h"
#include "keyinjector.h"
#include "gestures.h"
#include "gesture_definition.h"
#include "config.h"

enum Key {Left=105, Right=106, Home=102,Power=116, Up=103, Down=108, Esc=1};

enum TouchStatus {Disabled, Gestures};

static enum TouchStatus touch_status = Disabled;


static int f;
static int w;
void injector_init() {
    f = open(BUTTONS,O_WRONLY);
    if (!f){
        fprintf(stderr, "cannot open buttons");
        exit(1);
    }

    /* w = open(WACOM, O_WRONLY); */
    /* if (!w){ */
    /*     fprintf(stderr, "cannot open digitizer"); */
    /*     exit(1); */
    /* } */
}

extern bool verbose;
void press_button(int code);
void press_pen(int x, int y, long time);
void move_pen(int x, int y, long time);
void SwipePage(int x, int y, long time);

void interpret_gesture(struct Gesture *g){
    if (g->type == TwoTapWide) {
        touch_status = ((int)touch_status + 1) % 2; //cycle the states
        switch(touch_status) {
            case Disabled:
                show("touch disabled");
                break;
            case Gestures:
                show("gestures enabled");
                break;
        }
        return;
    }

    time_t rawtime;
    time(&rawtime);
    switch(g->type) {
        case SwipeDownLong:
            {
            struct tm* timeinfo = localtime(&rawtime);
            char buffer[100];
            strftime(buffer,sizeof(buffer), "%Y-%m-%d %H:%M:%S", timeinfo);
            show(buffer);
            }
            break;

        default:
            break;

    }

    if (touch_status == Disabled)
        return;

    //require touch enabled
    switch(g->type){
        case SwipeUpLong:
            if (verbose)
                printf("execute custom script\n");
            system("~/scripts/swipeup.sh");
            break;
        default:
            break;

    }
}


//todo: wip
void move_pen(int x, int y, long time)
{
    struct input_event key_input_event;

    memset(&key_input_event, 0, sizeof(key_input_event));
    key_input_event.type = EV_ABS;
    key_input_event.code = ABS_X;
    key_input_event.value = x;
    key_input_event.time.tv_sec = time;
    write(w, &key_input_event,sizeof(key_input_event));


    memset(&key_input_event, 0, sizeof(key_input_event));
    key_input_event.type = EV_ABS;
    key_input_event.code = ABS_Y;
    key_input_event.value = y;
    key_input_event.time.tv_sec = time;
    write(w, &key_input_event,sizeof(key_input_event));

    memset(&key_input_event, 0, sizeof(key_input_event));
    key_input_event.type = EV_ABS;
    key_input_event.code = ABS_DISTANCE;
    key_input_event.value = 16;
    key_input_event.time.tv_sec = time;
    write(w, &key_input_event,sizeof(key_input_event));

    memset(&key_input_event, 0, sizeof(key_input_event));
    key_input_event.type = EV_ABS;
    key_input_event.code = 24;
    key_input_event.value = 3000;
    key_input_event.time.tv_sec = time;
    write(w, &key_input_event,sizeof(key_input_event));

    memset(&key_input_event, 0, sizeof(key_input_event));
    key_input_event.type = EV_SYN;
    key_input_event.code = SYN_REPORT;
    key_input_event.time.tv_sec = time;
    write(w, &key_input_event,sizeof(key_input_event));

}
void press_pen(int x, int y, long time){
    struct input_event key_input_event;

    memset(&key_input_event, 0, sizeof(key_input_event));
    key_input_event.type = 1;
    key_input_event.code = 320;
    key_input_event.value = 1;
    key_input_event.time.tv_sec = time;
    write(w, &key_input_event,sizeof(key_input_event));


    memset(&key_input_event, 0, sizeof(key_input_event));
    key_input_event.type = EV_ABS;
    key_input_event.code = ABS_X;
    key_input_event.value = x;
    key_input_event.time.tv_sec = time;
    write(w, &key_input_event,sizeof(key_input_event));


    memset(&key_input_event, 0, sizeof(key_input_event));
    key_input_event.type = EV_ABS;
    key_input_event.code = ABS_Y;
    key_input_event.value = y;
    key_input_event.time.tv_sec = time;
    write(w, &key_input_event,sizeof(key_input_event));

    memset(&key_input_event, 0, sizeof(key_input_event));
    key_input_event.type = EV_ABS;
    key_input_event.code = ABS_DISTANCE;
    key_input_event.value = 16;
    key_input_event.time.tv_sec = time;
    write(w, &key_input_event,sizeof(key_input_event));

    memset(&key_input_event, 0, sizeof(key_input_event));
    key_input_event.type = EV_SYN;
    key_input_event.code = SYN_REPORT;
    key_input_event.time.tv_sec = time;
    write(w, &key_input_event,sizeof(key_input_event));

    memset(&key_input_event, 0, sizeof(key_input_event));
    key_input_event.type = 1; //touch
    key_input_event.code = 330;
    key_input_event.value = 1;
    key_input_event.time.tv_sec = time;
    write(w, &key_input_event,sizeof(key_input_event));

    memset(&key_input_event, 0, sizeof(key_input_event));
    key_input_event.type = EV_ABS;
    key_input_event.code = ABS_X;
    key_input_event.value = x;
    key_input_event.time.tv_sec = time;
    write(w, &key_input_event,sizeof(key_input_event));

    memset(&key_input_event, 0, sizeof(key_input_event));
    key_input_event.type = EV_ABS;
    key_input_event.code = ABS_Y;
    key_input_event.value = y;
    key_input_event.time.tv_sec = time;
    write(w, &key_input_event,sizeof(key_input_event));

    memset(&key_input_event, 0, sizeof(key_input_event));
    key_input_event.type = EV_ABS;
    key_input_event.code = 24;
    key_input_event.value = 3300;
    key_input_event.time.tv_sec = time;
    write(w, &key_input_event,sizeof(key_input_event));

    memset(&key_input_event, 0, sizeof(key_input_event));
    key_input_event.type = EV_ABS;
    key_input_event.code = 25;
    key_input_event.value = 21;
    key_input_event.time.tv_sec = time;
    write(w, &key_input_event,sizeof(key_input_event));

    memset(&key_input_event, 0, sizeof(key_input_event));
    key_input_event.type = EV_ABS;
    key_input_event.code = 26;
    key_input_event.value = 800;
    key_input_event.time.tv_sec = time;
    write(w, &key_input_event,sizeof(key_input_event));

    memset(&key_input_event, 0, sizeof(key_input_event));
    key_input_event.type = EV_ABS;
    key_input_event.code = 27;
    key_input_event.value = -100;
    key_input_event.time.tv_sec = time;
    write(w, &key_input_event,sizeof(key_input_event));

    memset(&key_input_event, 0, sizeof(key_input_event));
    key_input_event.type = EV_SYN;
    key_input_event.code = SYN_REPORT;
    key_input_event.time.tv_sec = time;
    write(w, &key_input_event,sizeof(key_input_event));
}

void press_button(int code){
    struct input_event key_input_event;
    memset(&key_input_event, 0, sizeof(key_input_event));

    debug_print("inject button %d \n", code);

    key_input_event.type = EV_KEY;
    key_input_event.code = code;
    key_input_event.value = 1;
    write(f, &key_input_event,sizeof(key_input_event));

    memset(&key_input_event, 0, sizeof(key_input_event));
    key_input_event.type = EV_SYN;
    key_input_event.code = SYN_REPORT;
    write(f, &key_input_event,sizeof(key_input_event));

    memset(&key_input_event, 0, sizeof(key_input_event));
    key_input_event.type = EV_KEY;
    key_input_event.code = code;
    write(f, &key_input_event,sizeof(key_input_event));


    memset(&key_input_event, 0, sizeof(key_input_event));
    key_input_event.type = EV_SYN;
    key_input_event.code = SYN_REPORT;
    write(f, &key_input_event,sizeof(key_input_event));
}

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