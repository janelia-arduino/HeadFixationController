// ----------------------------------------------------------------------------
// Constants.h
//
//
// Authors:
// Peter Polidoro polidorop@janelia.hhmi.org
// ----------------------------------------------------------------------------
#ifndef HEAD_FIXATION_CONTROLLER_CONSTANTS_H
#define HEAD_FIXATION_CONTROLLER_CONSTANTS_H
#include <ConstantVariable.h>

#include <ModularServer.h>


namespace head_fixation_controller
{
namespace constants
{
//MAX values must be >= 1, >= created/copied count, < RAM limit
enum{PROPERTY_COUNT_MAX=1};
enum{PARAMETER_COUNT_MAX=1};
enum{FUNCTION_COUNT_MAX=1};
enum{CALLBACK_COUNT_MAX=2};

extern ConstantString device_name;

extern ConstantString firmware_name;
extern const modular_server::FirmwareInfo firmware_info;

// Pins

// Units

// Properties
// Property values must be long, double, bool, long[], double[], bool[], char[], ConstantString *, (ConstantString *)[]
extern const long channel_count;

extern const long steps_per_position_units_element_default;

extern const long velocity_max_element_default;

extern const long velocity_min_element_default;

extern const long acceleration_max_element_default;

extern const bool right_switches_enabled_default;

extern const bool right_switch_stop_enabled_element_default;

extern const long home_velocity_element_default;

extern const long invert_driver_direction_element_0_default;
extern const long invert_driver_direction_element_1_default;

extern const long run_current_element_default;

extern const long hold_current_element_default;

extern const long hold_delay_element_default;

extern const long microsteps_per_step_element_default;

extern const long stage_position_min_element_default;

extern const long stage_position_max_element_default;

extern ConstantString fixation_position_property_name;
extern const long fixation_position_min;
extern const long fixation_position_max;
extern const long fixation_position_default;

// Parameters

// Functions

// Callbacks
extern ConstantString retract_callback_name;
extern ConstantString fixate_callback_name;

// Errors
}
}
#include "5x3.h"
#include "3x2.h"
#endif
