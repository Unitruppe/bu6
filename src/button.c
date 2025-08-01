#include "button.h"
#include "delay.h"

#include "pins.h"

static uint8_t ledStatus;

static void initLED() {
    // set LED status
    ledStatus = 0;

    // initialize PF5 as input and activate pullup resistor
    BUTTON_LEFT_DDR &= ~(1 << BUTTON_LEFT_PIN);
    BUTTON_LEFT_PCR |= (1 << BUTTON_LEFT_PIN);


    // initialize blue Led
    LED_BLUE_DDR |= (1 << LED_BLUE_PIN); // Configure blue LED pin as output.
    LED_BLUE_DOR |= (1 << LED_BLUE_PIN); // Turn LED off.
}

/**
 * Returns true (1) if the button is pressed
 */
static int isButtonPressed() {
    return !(BUTTON_LEFT_DIR & (1 << BUTTON_LEFT_PIN));
}

/**
 *  Changes the status of the blue LED.
 */
static void toggleBlueLED() {
    // invert value of LEDStatus
    ledStatus = ledStatus ? 0 : 1;
}

/**
 *  Sets the blue LED to its status.
 */
static void setBlueLED(uint8_t status) {
    if (status) {
        LED_BLUE_DOR &= ~(1 << LED_BLUE_PIN);
    } else {
        LED_BLUE_DOR |= (1 << LED_BLUE_PIN);
    }
    
}

void ButtonToggleBlueLED() {
    // Initialization
    initLED();

    const uint32_t sleepTime = 100000;

    while (1) {
        // if button pressed toggle ledStatus and wait unitl button is released
        // set LED
        while(!isButtonPressed()) {}
        toggleBlueLED();
        setBlueLED(ledStatus);
        while(isButtonPressed()) {}
        cppp_microDelay(sleepTime);
    }
}

void ButtonHoldBlueLEDOn() {
    // initialization
    initLED();

    const uint32_t sleepTime = 100000;
    while (1) {
        while(!isButtonPressed()) {}
        // while button pressed turn LED on
        // delay of 0,01s
        setBlueLED(1);
        cppp_microDelay(sleepTime);

        while(isButtonPressed()) {}
        // normal case LED is off
        // delay of 0,01s
        setBlueLED(0);
        cppp_microDelay(sleepTime);
    }
}


