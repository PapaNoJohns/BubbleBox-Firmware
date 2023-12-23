#ifndef _MODES_GBFV_HPP
#define _MODES_GBFV_HPP

#include "core/ControllerMode.hpp"
#include "core/socd.hpp"
#include "core/state.hpp"

class GBFV : public ControllerMode {
  public:
    GBFV(socd::SocdType socd_type);

  private:
    void HandleSocd(InputState &inputs);
    void UpdateDigitalOutputs(InputState &inputs, OutputState &outputs);
    void UpdateAnalogOutputs(InputState &inputs, OutputState &outputs);
};

#endif
