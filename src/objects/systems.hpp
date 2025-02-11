// #ifndef SYSTEMS_HPP
// #define SYSTEMS_HPP
// #include "fumo_ecs/system_base.hpp"
// #include "objects/components.hpp"
// #include <climits>
//
// // TODO: BodyMovement shouldnt be registered? (undecided atm)
// // SOLVED: created an unscheduled option in Scheduler
// class BodyMovement : public System {
//     // prefer making a body movement system, instead of
//     // adding a move_towards() method to the Body component
//     // (its really pointless to add methods to components id say,
//     // and might be inconvenient later, so follow the intended ECS design)
//   public:
//     void sys_call() override;
//     void move_towards(Body& body, Body& target);
// };
//
// class HandleInput : public System {
//     // generic interface aggregate for all input handling
//   public:
//     virtual ~HandleInput() = default;
// };
//
// class HandleInputLevelEditor : HandleInput {
//   public:
//     void sys_call() override { handle_input(); }
//     void handle_input();
//
//   private:
//     BodyMovement body_movement;
//     void move_celestial_body(Vector2 mouse_position);
// };
//
// #endif
