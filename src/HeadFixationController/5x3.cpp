// ----------------------------------------------------------------------------
// 5x3.cpp
//
//
// Authors:
// Peter Polidoro peter@polidoro.io
// ----------------------------------------------------------------------------
#include "5x3.h"


#if defined(__MK64FX512__)

namespace head_fixation_controller
{
namespace constants
{
// Pins

// Units

// Properties
const long channel_count = CHANNEL_COUNT;

const long steps_per_position_units_default[CHANNEL_COUNT] =
{
  steps_per_position_units_element_default,
  steps_per_position_units_element_default,
};

const long velocity_max_default[CHANNEL_COUNT] =
{
  velocity_max_element_default,
  velocity_max_element_default,
};

const long velocity_min_default[CHANNEL_COUNT] =
{
  velocity_min_element_default,
  velocity_min_element_default,
};

const long acceleration_max_default[CHANNEL_COUNT] =
{
  acceleration_max_element_default,
  acceleration_max_element_default,
};

const bool right_switches_enabled_default[CONTROLLER_COUNT] =
{
  right_switches_enabled_element_default,
};

const bool right_switch_stop_enabled_default[CHANNEL_COUNT] =
{
  right_switch_stop_enabled_element_default,
  right_switch_stop_enabled_element_default,
};

const long stage_position_min_default[CHANNEL_COUNT] =
{
  stage_position_min_element_default,
  stage_position_min_element_default,
};

const long home_velocity_default[CHANNEL_COUNT] =
{
  home_velocity_element_default,
  home_velocity_element_default,
};

const bool invert_driver_direction_default[CHANNEL_COUNT] =
{
  invert_driver_direction_element_0_default,
  invert_driver_direction_element_1_default,
};

const long run_current_default[CHANNEL_COUNT] =
{
  run_current_element_default,
  run_current_element_default,
};

const long hold_current_default[CHANNEL_COUNT] =
{
  hold_current_element_default,
  hold_current_element_default,
};

const long hold_delay_default[CHANNEL_COUNT] =
{
  hold_delay_element_default,
  hold_delay_element_default,
};

const long microsteps_per_step_default[CHANNEL_COUNT] =
{
  microsteps_per_step_element_default,
  microsteps_per_step_element_default,
};

const long stage_position_max_default[CHANNEL_COUNT] =
{
  stage_position_max_element_default,
  stage_position_max_element_default,
};

// Parameters

// Functions

// Callbacks

// Errors
}
}
#endif
