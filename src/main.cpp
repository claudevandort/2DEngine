#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <glm/glm.hpp>
#include <imgui/imgui.h>
#include <sol/sol.hpp>

int main(){
    sol::state lua;
    lua.open_libraries(sol::lib::base);

    glm::vec2 velocity(1.0f, 0.0f);
    velocity = glm::normalize(velocity);

    SDL_Init(SDL_INIT_EVERYTHING);
    std::cout << "Hello World!" << std::endl;
    return 0;
}