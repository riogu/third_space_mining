#ifndef SYSTEMS_HPP
#define SYSTEMS_HPP
#include "fumo_engine/constants_using.hpp"
#include "fumo_engine/system_base.hpp"
#include "objects/components.hpp"

// TODO: BodyMovement shouldnt be registered? (undecided atm)
// SOLVED: created an unscheduled option in Scheduler
class BodyMovement : public System {
    // prefer making a body movement system, instead of
    // adding a move_towards() method to the Body component (follow ECS logic)
  public:
    void sys_call() override;
    void move_towards(Body& body, Body& target);
    void move_towards_position(Body& body, Vector2 position);
};

class HandleInput : public System {
    // generic interface aggregate for all input handling
  public:
    virtual ~HandleInput() = default;
};

class HandleInputLevelEditor : HandleInput {
  public:
    void sys_call() override { handle_input(); }
    void handle_input();

  private:
    void spawn_planet();
    void move_planet();
    void delete_planet();
    void resize_planet(float resize);
};

// NOTE: this is an interface for all factory spawner classes
class EntityFactory : public System {
    // this factory method will hold a bunch of functions for spawning various entities
    // maybe we will give it some parameters so we can easily spawn many types of entities
  public:
    virtual ~EntityFactory() = default;
};
class PlanetFactory : public EntityFactory {
  public:
    void sys_call() override;
    EntityId create_default_planet(Vector2 position);
    EntityId create_planet(float radius, float mass, Vector2 velocity,
                                   Vector2 position, Color color);
};

#endif
