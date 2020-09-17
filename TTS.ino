#include "Talkie.h"
#include "Vocab_US_Large.h"
#include "Vocab_Special.h"

Talkie voice;

void setup() {
}
void loop() 
{
    voice.say(spPAUSE2);
    voice.say(sp2_DANGER);
    voice.say(sp3_STORM);
    voice.say(sp3_IN);
    voice.say(sp3_THE);
    voice.say(sp3_NORTH);
  
     voice.say(sp2_ENTER);
     voice.say(sp2_FROM);
     voice.say(sp2_WEST);
     voice.say(sp4_PLEASE);
     voice.say(sp2_GO);
     voice.say(sp2_SLOW);
     voice.say(sp2_AND);
    voice.say(sp2_ENTER);
    voice.say(sp3_EAST);
    voice.say(sp2_GO);
     voice.say(sp4_SPEED);
}
