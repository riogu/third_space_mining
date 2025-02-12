// clang-format off
#include "../constants.hpp"
#include "fumo_engine/component_array.hpp"
#include "fumo_engine/global_state.hpp"
#include "systems.hpp"
#include "raylib.h"
#include "raymath.h"
// clang-format on
extern std::unique_ptr<GlobalState> global;

void HandleInputLevelEditor::handle_input() {
    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
        move_planet();
    } else if (IsKeyPressed(KEY_S)) {
        spawn_planet();
    } else if (IsKeyPressed(KEY_D)) {
        delete_planet();
    } else if (IsKeyPressed(KEY_R)) {
        resize_planet(0.5f);
    } else if (IsKeyPressed(KEY_E)) {
        resize_planet(2.0f);
    } else if (IsKeyPressed(KEY_ONE)) {
        debug_print();
    }
}
void HandleInputLevelEditor::debug_print() { global->debug_prints(); }
void HandleInputLevelEditor::spawn_planet() {
    Vector2 mouse_position = GetMousePosition();
    DrawCircleLinesV(mouse_position, mouse_radius, GREEN);
    auto planet_factory_ptr = global->ECS.get_system<PlanetFactory>();
    planet_factory_ptr->create_default_planet(mouse_position);
}

void HandleInputLevelEditor::resize_planet(float resize) {
    Vector2 mouse_position = GetMousePosition();
    DrawCircleLinesV(mouse_position, mouse_radius, GREEN);
    for (auto entity_id : sys_entities) {
        auto& body = global->ECS.get_component<Body>(entity_id);
        auto& circle_shape = global->ECS.get_component<CircleShape>(entity_id);
        float distance = Vector2Distance(mouse_position, body.position);
        if (mouse_radius + circle_shape.radius > distance) {
            circle_shape.radius /= resize;
            body.mass *= resize * resize * resize * resize;
            return;
        }
    }
}
void HandleInputLevelEditor::delete_planet() {
    Vector2 mouse_position = GetMousePosition();
    DrawCircleLinesV(mouse_position, mouse_radius, GREEN);
    for (auto entity_id : sys_entities) {
        auto& body = global->ECS.get_component<Body>(entity_id);
        auto& circle_shape = global->ECS.get_component<CircleShape>(entity_id);
        float distance = Vector2Distance(mouse_position, body.position);
        if (mouse_radius + circle_shape.radius > distance) {
            global->ECS.destroy_entity(entity_id);
            return;
        }
    }
}
void HandleInputLevelEditor::move_planet() {
    Vector2 mouse_position = GetMousePosition();
    DrawCircleLinesV(mouse_position, mouse_radius, GREEN);
    for (auto entity_id : sys_entities) {
        auto& body = global->ECS.get_component<Body>(entity_id);
        auto& circle_shape = global->ECS.get_component<CircleShape>(entity_id);
        float distance = Vector2Distance(mouse_position, body.position);
        if (mouse_radius + circle_shape.radius > distance) {
            auto body_movement_ptr = global->ECS.get_system<BodyMovement>();
            body_movement_ptr->move_towards_position(body, GetMousePosition());
            // FIXME: think if its okay to update position here
            body.position += body.velocity * global->frametime;
            return;
        }
    }
}
