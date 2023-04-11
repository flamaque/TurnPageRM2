#include <stdio.h>
#include <stdlib.h>
#include "ui.h"
#include "version.h"
#include "gestures.h"
#include "eventreader.h"
#include "keyinjector.h"


bool verbose = true;
int main() {
    printf("touchinjector %s\n",VERSION);
    //todo: option parsing
    verbose = true; 

    injector_init(); 
	ui_init();

    process_touch(&recognize_gestures);
   while(1){
    delay(2000);
    SwipePage();
    delay(2000);
   }
    return 0;
}
