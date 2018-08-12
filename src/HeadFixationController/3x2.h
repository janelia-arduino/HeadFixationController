// ----------------------------------------------------------------------------
// 3x2.h
//
//
// Authors:
// Peter Polidoro peterpolidoro@gmail.com
// ----------------------------------------------------------------------------
#ifndef HEAD_FIXATION_CONTROLLER_3X2_CONSTANTS_H
#define HEAD_FIXATION_CONTROLLER_3X2_CONSTANTS_H
#include "Constants.h"


#if defined(__MK20DX256__)

namespace head_fixation_controller
{
namespace constants
{
enum{CHANNEL_COUNT=1};

// Pins

// Units

// Properties
// Property values must be long, double, bool, long[], double[], bool[], char[], ConstantString *, (ConstantString *)[]
extern const long steps_per_position_units_default[CHANNEL_COUNT];

extern const long velocity_max_default[CHANNEL_COUNT];

extern const long velocity_min_default[CHANNEL_COUNT];

extern const long acceleration_max_default[CHANNEL_COUNT];

extern const bool right_switch_stop_enabled_default[CHANNEL_COUNT];

extern const long home_velocity_default[CHANNEL_COUNT];

extern const bool invert_driver_direction_default[CHANNEL_COUNT];

extern const long run_current_default[CHANNEL_COUNT];

extern const long hold_current_default[CHANNEL_COUNT];

extern const long hold_delay_default[CHANNEL_COUNT];

extern const long microsteps_per_step_default[CHANNEL_COUNT];

extern const long stage_position_min_default[CHANNEL_COUNT];

extern const long stage_position_max_default[CHANNEL_COUNT];

// Parameters

// Functions

// Callbacks

// Errors
}
}
#endif
#endif
