// ----------------------------------------------------------------------------
// HeadFixationController.cpp
//
//
// Authors:
// Peter Polidoro peterpolidoro@gmail.com
// ----------------------------------------------------------------------------
#include "../HeadFixationController.h"


using namespace head_fixation_controller;

HeadFixationController::HeadFixationController()
{
}

void HeadFixationController::setup()
{
  // Parent Setup
  StageController::setup();

  // Reset Watchdog
  resetWatchdog();

  // Variable Setup

  // Set Device ID
  modular_server_.setDeviceName(constants::device_name);

  // Add Hardware

  // Pins

  // Add Firmware
  modular_server_.addFirmware(constants::firmware_info,
    properties_,
    parameters_,
    functions_,
    callbacks_);

  // Properties
  modular_server::Property & channel_count_property = modular_server_.property(step_dir_controller::constants::channel_count_property_name);
  channel_count_property.setDefaultValue(constants::channel_count);
  channel_count_property.setRange(constants::channel_count,constants::channel_count);

  setChannelCountHandler();

  modular_server::Property & steps_per_position_units_property = modular_server_.property(step_dir_controller::constants::steps_per_position_units_property_name);
  steps_per_position_units_property.setDefaultValue(constants::steps_per_position_units_default);

  modular_server::Property & velocity_max_property = modular_server_.property(step_dir_controller::constants::velocity_max_property_name);
  velocity_max_property.setDefaultValue(constants::velocity_max_default);

  modular_server::Property & velocity_min_property = modular_server_.property(step_dir_controller::constants::velocity_min_property_name);
  velocity_min_property.setDefaultValue(constants::velocity_min_default);

  modular_server::Property & acceleration_max_property = modular_server_.property(step_dir_controller::constants::acceleration_max_property_name);
  acceleration_max_property.setDefaultValue(constants::acceleration_max_default);

  modular_server::Property & right_switches_enabled_property = modular_server_.property(step_dir_controller::constants::right_switches_enabled_property_name);
  right_switches_enabled_property.setDefaultValue(constants::right_switches_enabled_default);

  modular_server::Property & right_switch_stop_enabled_property = modular_server_.property(step_dir_controller::constants::right_switch_stop_enabled_property_name);
  right_switch_stop_enabled_property.setDefaultValue(constants::right_switch_stop_enabled_default);

  modular_server::Property & home_velocity_property = modular_server_.property(step_dir_controller::constants::home_velocity_property_name);
  home_velocity_property.setDefaultValue(constants::home_velocity_default);

  modular_server::Property & invert_driver_direction_property = modular_server_.property(stepper_controller::constants::invert_driver_direction_property_name);
  invert_driver_direction_property.setDefaultValue(constants::invert_driver_direction_default);

  modular_server::Property & run_current_property = modular_server_.property(stepper_controller::constants::run_current_property_name);
  run_current_property.setDefaultValue(constants::run_current_default);

  modular_server::Property & hold_current_property = modular_server_.property(stepper_controller::constants::hold_current_property_name);
  hold_current_property.setDefaultValue(constants::hold_current_default);

  modular_server::Property & hold_delay_property = modular_server_.property(stepper_controller::constants::hold_delay_property_name);
  hold_delay_property.setDefaultValue(constants::hold_delay_default);

  modular_server::Property & microsteps_per_step_property = modular_server_.property(stepper_controller::constants::microsteps_per_step_property_name);
  microsteps_per_step_property.setDefaultValue(constants::microsteps_per_step_default);

  modular_server::Property & stage_position_min_property = modular_server_.property(stage_controller::constants::stage_position_min_property_name);
  stage_position_min_property.setDefaultValue(constants::stage_position_min_default);

  modular_server::Property & stage_position_max_property = modular_server_.property(stage_controller::constants::stage_position_max_property_name);
  stage_position_max_property.setDefaultValue(constants::stage_position_max_default);

  modular_server::Property & fixation_position_property = modular_server_.createProperty(constants::fixation_position_property_name,constants::fixation_position_default);
  fixation_position_property.setRange(constants::fixation_position_min,constants::fixation_position_max);

  // Parameters

  // Functions

  // Callbacks
  modular_server::Callback & retract_callback = modular_server_.createCallback(constants::retract_callback_name);
  retract_callback.attachFunctor(makeFunctor((Functor1<modular_server::Pin *> *)0,*this,&HeadFixationController::retractHandler));
  retract_callback.attachTo(modular_device_base::constants::bnc_a_pin_name,modular_server::constants::pin_mode_interrupt_falling);
  retract_callback.attachTo(modular_device_base::constants::btn_a_pin_name,modular_server::constants::pin_mode_interrupt_falling);

  modular_server::Callback & fixate_callback = modular_server_.createCallback(constants::fixate_callback_name);
  fixate_callback.attachFunctor(makeFunctor((Functor1<modular_server::Pin *> *)0,*this,&HeadFixationController::fixateHandler));
#if defined(__MK64FX512__)
  fixate_callback.attachTo(modular_device_base::constants::btn_b_pin_name,modular_server::constants::pin_mode_interrupt_falling);
#endif

}

void HeadFixationController::retract()
{
  homeStage();
}

void HeadFixationController::fixate()
{
  if (stageHomed())
  {
    PositionArray fixation_position = getFixationPosition();
    moveStageTo(fixation_position);
  }
}

HeadFixationController::PositionArray HeadFixationController::getFixationPosition()
{
  long fixation_position;
  modular_server_.property(constants::fixation_position_property_name).getValue(fixation_position);

  PositionArray fixation_position_array;
  fixation_position_array.push_back(fixation_position);
  fixation_position_array.push_back(fixation_position);

  return fixation_position;
}

// Handlers must be non-blocking (avoid 'delay')
//
// modular_server_.parameter(parameter_name).getValue(value) value type must be either:
// fixed-point number (int, long, etc.)
// floating-point number (float, double)
// bool
// const char *
// ArduinoJson::JsonArray
// ArduinoJson::JsonObject
// const ConstantString *
//
// For more info read about ArduinoJson parsing https://github.com/janelia-arduino/ArduinoJson
//
// modular_server_.property(property_name).getValue(value) value type must match the property default type
// modular_server_.property(property_name).setValue(value) value type must match the property default type
// modular_server_.property(property_name).getElementValue(element_index,value) value type must match the property array element default type
// modular_server_.property(property_name).setElementValue(element_index,value) value type must match the property array element default type

void HeadFixationController::retractHandler(modular_server::Pin * pin_ptr)
{
  retract();
}

void HeadFixationController::fixateHandler(modular_server::Pin * pin_ptr)
{
  fixate();
}
