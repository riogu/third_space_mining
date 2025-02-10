#include "constants.hpp"
#include "ecs_hell/global_state.hpp"
//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
std::unique_ptr<GlobalState> global;
int main(void) {

    InitWindow(screenWidth, screenHeight, "THIS... is a BUCKET.");
    global = std::make_unique<GlobalState>();
    global->initialize();

    SetTargetFPS(60);
    while (!WindowShouldClose()) {
        ClearBackground(BLACK);
        BeginDrawing();

        global->frametime = GetFrameTime();
        global->run_systems();

        EndDrawing();
    }
    //--------------------------------------------------------------------------------------
    CloseWindow(); // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}




