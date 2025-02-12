
#ifndef SYSTEM_BASE_HPP
#define SYSTEM_BASE_HPP
#include "engine_constants.hpp"
#include <set>
// all systems should inherit from this system
class System {
  public:
    std::set<EntityId> sys_entities{};
    // sys_call is a generic method, required to sort systems by priority at the end.
    // it is necessary to work around this method by storing variables in the system
    // if needed for subsequent function calls
    virtual void sys_call() = 0;
};
#endif
