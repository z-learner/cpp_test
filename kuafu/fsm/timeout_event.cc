#include "fsm/timeout_event.h"

namespace kuafu {

TimeoutEvent::TimeoutEvent(const MachineSetSharedPtr& machine_set,
            const MachineType& machine_type,
            const std::string& machine_name)
:EventTemplate<TimeoutEventType>(TimeoutEventType::TET_TIMEOUT,
            machine_set)
,machine_type_(machine_type)
,machine_name_(machine_name) {
}

const MachineType& TimeoutEvent::GetMachineType() const {
  return machine_type_;
}

const std::string& TimeoutEvent::GetMachineName() const {
  return machine_name_;
}

std::ostream& TimeoutEvent::ToStream(std::ostream& str) const {
  str << static_cast<const char*>("TimeoutEvent[") << machine_type_.GetName()
    << static_cast<const char*>(", ") << machine_name_ 
    << static_cast<const char*>("]");

  return str;
}

std::string TimeoutEvent::ToString() const {
   std::stringstream str;
   str << static_cast<const char*>("TimeoutEvent[") << machine_type_.GetName()
      << static_cast<const char*>(", ") << machine_name_ 
      << static_cast<const char*>("]");

   return str.str();
}

}//namespace kuafu
