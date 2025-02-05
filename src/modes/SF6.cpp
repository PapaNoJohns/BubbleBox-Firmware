#include "modes/SF6.hpp"

SF6::SF6(socd::SocdType socd_type) : ControllerMode(socd_type) {
    _socd_pair_count = 1;
    _socd_pairs = new socd::SocdPair[_socd_pair_count]{
        socd::SocdPair{&InputState::left, &InputState::right},
    };
}

void SF6::HandleSocd(InputState &inputs) {
    if (inputs.down && (inputs.mod_x || inputs.c_up)) {
        inputs.down = false;
    }
    InputMode::HandleSocd(inputs);
}

void SF6::UpdateDigitalOutputs(InputState &inputs, OutputState &outputs) {
    // Directions
    outputs.dpadLeft = inputs.left;
    outputs.dpadRight = inputs.right;
    outputs.dpadDown = inputs.down;
    outputs.dpadUp = inputs.mod_x || inputs.mod_y;

    // Menu keys
    outputs.start = inputs.start;
    outputs.select = inputs.c_down;
    outputs.home = inputs.c_up;

    // Right hand bottom row
    outputs.a = inputs.b;
    outputs.b = inputs.x;
    outputs.triggerRDigital = inputs.z;

    // Right hand top row
    outputs.x = inputs.r;
    outputs.y = inputs.y;
    outputs.buttonR = inputs.midshield;

    // Drive Impact and parry
    outputs.buttonL = inputs.l; // DI
    outputs.triggerLDigital = inputs.up || inputs.a || inputs.c_left; // Parry
}

void SF6::UpdateAnalogOutputs(InputState &inputs, OutputState &outputs) {
    outputs.leftStickX = 128;
    outputs.leftStickY = 128;
    outputs.rightStickX = 128;
    outputs.rightStickY = 128;
}
