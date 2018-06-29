// ----------------------------------------------------------------------------
// Constants.cpp
//
//
// Authors:
// Peter Polidoro polidorop@janelia.hhmi.org
// ----------------------------------------------------------------------------
#include "Constants.h"


namespace head_fixation_controller
{
namespace constants
{
CONSTANT_STRING(device_name,"head_fixation_controller");

CONSTANT_STRING(firmware_name,"HeadFixationController");
// Use semantic versioning http://semver.org/
const modular_server::FirmwareInfo firmware_info =
{
  .name_ptr=&firmware_name,
  .version_major=1,
  .version_minor=0,
  .version_patch=0,
};

// Pins

// Units

// Properties
const long steps_per_position_units_element_default = 1;

const long velocity_max_element_default = 4000;

const long velocity_min_element_default = 100;

const long acceleration_max_element_default = 4000;

const bool right_switches_enabled_default = false;

const bool right_switch_stop_enabled_element_default = false;

const long home_velocity_element_default = -1500;

const long invert_driver_direction_element_0_default = false;
const long invert_driver_direction_element_1_default = true;

const long run_current_element_default = 20;

const long hold_current_element_default = 10;

const long hold_delay_element_default = 50;

const long microsteps_per_step_element_default = 16;

const long stage_position_min_element_default = 0;

const long stage_position_max_element_default = 1190;

CONSTANT_STRING(fixation_position_property_name,"fixationPosition");
const long fixation_position_min = 500;
const long fixation_position_max = stage_position_max_element_default;
const long fixation_position_default = fixation_position_max;

// Parameters

// Functions

// Callbacks
CONSTANT_STRING(retract_callback_name,"retract");
CONSTANT_STRING(fixate_callback_name,"fixate");

// Errors
}
}
