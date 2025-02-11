// // clang-format off
// #include "../constants.hpp"
// #include "systems.hpp"
// #include "fumo_ecs/global_state.hpp"
// #include "objects/components.hpp"
// #include "raymath.h"
// #include <memory>
// // clang-format on
//
// extern std::unique_ptr<GlobalState> global;
// void HandleInputLevelEditor::handle_input() {
//     // FIXME: finish input handling
//     if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
//         Vector2 mouse_position = GetMousePosition();
//         move_celestial_body(mouse_position);
//         DrawCircleLinesV(mouse_position, mouse_radius, GREEN);
//     }
// }
// void HandleInputLevelEditor::move_celestial_body(Vector2 mouse_position) {
//     for (auto entity_id : sys_entities) {
//         auto& body = global->ECS.get_component<Body>(entity_id);
//         auto& circle_shape = global->ECS.get_component<CircleShape>(entity_id);
//         float distance = Vector2Distance(mouse_position, body.position);
//         if ( + circle_shape.radius > distance) {
//             auto body_movement_ptr = global->ECS.get_system<BodyMovement>();
//             body_movement_ptr->move_towards(body, );
//         }
//     }
// }
// void BodyMovement::move_towards(Body& body, Body& target) {
//     Vector2 direction = Vector2Normalize(target.position - body.position);
//     float sqr_distance = Vector2DistanceSqr(target.position, body.position);
//     body.velocity = direction *  sqr_distance;
// }
