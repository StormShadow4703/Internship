#include <stdio.h>
#include <stdint.h>

// Define the LEDSettings structure
typedef struct {
    uint8_t state;       // ON/OFF state of the LED (1 for ON, 0 for OFF)
    uint8_t brightness;  // Brightness level (0 to 255)
    uint32_t color;      // Color value encoded in RGB format
} LEDSettings;

// Define the LEDGroup structure
typedef struct {
    LEDSettings singleLED;  // Individual LED settings
    uint8_t groupState;     // Collective state of a group of LEDs (1 for all ON, 0 for all OFF)
    uint8_t groupBrightness;// Collective brightness adjustment for the group
} LEDGroup;

// Function to initialize the LED group with default values
void initLEDGroup(LEDGroup *group) {
    group->singleLED.state = 0;          // All LEDs OFF
    group->singleLED.brightness = 0;     // Minimum brightness
    group->singleLED.color = 0x000000;   // Color (black)
    group->groupState = 0;               // Group OFF
    group->groupBrightness = 0;          // Minimum brightness for the group
}

// Function to update LED group settings
void updateLEDGroupSettings(LEDGroup *group, uint8_t groupState, uint8_t groupBrightness, uint8_t state, uint8_t brightness, uint32_t color) {
    group->groupState = groupState;
    group->groupBrightness = groupBrightness;
    group->singleLED.state = state;
    group->singleLED.brightness = brightness;
    group->singleLED.color = color;
}

// Function to display the current status of the LED group
void displayLEDGroupStatus(const LEDGroup *group) {
    printf("Individual LED Status:\n");
    printf("State: %s\n", group->singleLED.state ? "ON" : "OFF");
    printf("Brightness: %u\n", group->singleLED.brightness);
    printf("Color: #%06X\n", group->singleLED.color);
    
    printf("Group Status:\n");
    printf("Group State: %s\n", group->groupState ? "ON" : "OFF");
    printf("Group Brightness: %u\n", group->groupBrightness);
}

int main() {
    LEDGroup myLEDGroup;

    // Initialize the LED group
    initLEDGroup(&myLEDGroup);

    // Update the LED group settings
    updateLEDGroupSettings(&myLEDGroup, 0, 128, 1, 200, 0xFF5733);

    // Display the current status of the LED group
    displayLEDGroupStatus(&myLEDGroup);

    return 0;
}
