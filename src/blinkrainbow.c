#include "blinkrainbow.h"

#include <stdint.h>
#include "delay.h"
#include "s6e2ccxj.h"
#include "mcu.h"


int BlinkRainbowMain() {
    LED_BLUE_DDR |= (1 << LED_BLUE_PIN); // Configure blue LED pin as output.
    LED_BLUE_DOR |= (1 << LED_BLUE_PIN); // Turn LED off.

    LED_RED_DDR |= (1 << LED_RED_PIN); // Configure blue LED pin as output.
    LED_RED_DOR |= (1 << LED_RED_PIN); // Turn LED off.

    LED_GREEN_DDR |= (1 << LED_GREEN_PIN); // Configure blue LED pin as output.
    LED_GREEN_DOR |= (1 << LED_GREEN_PIN); // Turn LED off.

    const uint32_t sleepTime = 1000000;
    // Main loop. Color order: red, green, blue
    while (1) {
        // Clear bit -> Switch LED on
        LED_RED_DOR &= ~(1 << LED_RED_PIN);
        cppp_microDelay(sleepTime);

        // Set bit -> Switch LED off
        LED_RED_DOR |= (1 << LED_RED_PIN);
        cppp_microDelay(sleepTime);

        // Clear bit -> Switch LED on
        LED_GREEN_DOR &= ~(1 << LED_GREEN_PIN);
        cppp_microDelay(sleepTime);

        // Set bit -> Switch LED off
        LED_GREEN_DOR |= (1 << LED_GREEN_PIN);
        cppp_microDelay(sleepTime);

        // Clear bit -> Switch LED on
        LED_BLUE_DOR &= ~(1 << LED_BLUE_PIN);
        cppp_microDelay(sleepTime);

        // Set bit -> Switch LED off
        LED_BLUE_DOR |= (1 << LED_BLUE_PIN);
        cppp_microDelay(sleepTime);
    }
}
