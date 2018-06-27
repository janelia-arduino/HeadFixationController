// ----------------------------------------------------------------------------
// HeadFixationController.h
//
//
// Authors:
// Peter Polidoro polidorop@janelia.hhmi.org
// ----------------------------------------------------------------------------
#ifndef HEAD_FIXATION_CONTROLLER_H
#define HEAD_FIXATION_CONTROLLER_H
#include <ArduinoJson.h>
#include <JsonStream.h>
#include <Array.h>
#include <Vector.h>
#include <ConstantVariable.h>
#include <Functor.h>

#include <ModularServer.h>
#include <ModularDeviceBase.h>
#include <Parent.h>

#include "HeadFixationController/Constants.h"


class HeadFixationController : public Parent
{
public:
  HeadFixationController();
  virtual void setup();

private:
  modular_server::Property properties_[head_fixation_controller::constants::PROPERTY_COUNT_MAX];
  modular_server::Parameter parameters_[head_fixation_controller::constants::PARAMETER_COUNT_MAX];
  modular_server::Function functions_[head_fixation_controller::constants::FUNCTION_COUNT_MAX];
  modular_server::Callback callbacks_[head_fixation_controller::constants::CALLBACK_COUNT_MAX];

  // Handlers

};

#endif
