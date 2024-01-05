#include "modes/GBFV.hpp"

GBFV::GBFV(socd::SocdType socd_type) : ControllerMode(socd_type) {
    _socd_pair_count = 1;
    _socd_pairs = new socd::SocdPair[_socd_pair_count]{
        socd::SocdPair{&InputState::left, &InputState::right},
    };
}

void GBFV::HandleSocd(InputState &inputs) {
    if (inputs.down && (inputs.mod_x || inputs.c_up)) {
        inputs.down = false;
    }
    InputMode::HandleSocd(inputs);
}

void GBFV::UpdateDigitalOutputs(InputState &inputs, OutputState &outputs) {
    // Directions
    outputs.dpadLeft = inputs.left;
    outputs.dpadRight = inputs.right;
    outputs.dpadDown = inputs.down;
    outputs.dpadUp = inputs.mod_x || inputs.mod_y;

    // Menu keys
    outputs.start = inputs.start;
    outputs.select = inputs.c_down;
    outputs.home = inputs.home;

    // Right hand bottom row
    outputs.a = inputs.b;
    outputs.b = inputs.x;
    outputs.triggerRDigital = inputs.z; // Block
    outputs.triggerLDigital = inputs.up; // Dash

    // Right hand top row
    outputs.x = inputs.r;
    outputs.y = inputs.y;
    outputs.buttonR = inputs.midshield || inputs.l || inputs.a || inputs.c_left; // Skill
    outputs.buttonL = inputs.lightshield; // Grab

    
    

    // Training mode settings
    outputs.leftStickClick = inputs.select;
    outputs.rightStickClick = inputs.c_up;
}

void GBFV::UpdateAnalogOutputs(InputState &inputs, OutputState &outputs) {
    outputs.leftStickX = 128;
    outputs.leftStickY = 128;
    outputs.rightStickX = 128;
    outputs.rightStickY = 128;
}
