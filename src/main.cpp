#include "constants.hpp"
#include "fumo_ecs/global_state.hpp"
//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
std::unique_ptr<GlobalState> global;
// void ecs_test();
// void add_an_entity();
int main(void) {

    InitWindow(screenWidth, screenHeight, "THIS... is a BUCKET.");
    global = std::make_unique<GlobalState>();
    global->initialize();

    SetTargetFPS(144);
    // ecs_test();
    // int count = 0;
    // int counted = 4;
    while (!WindowShouldClose()) {
        ClearBackground(BLACK);
        BeginDrawing();

        global->frametime = GetFrameTime();
        global->ECS.run_systems();

        // count++;
        // if (count % 10 == 0) [[likely]] {
        //     counted++;
        //     TraceLog(LOG_DEBUG, "entity count: %d", counted);
        //     add_an_entity();
        // }
        EndDrawing();
    }
    //--------------------------------------------------------------------------------------
    CloseWindow(); // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
