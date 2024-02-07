#include "Game.h"
#include <SDL2/SDL.h>
#include <iostream>

Game::Game(){
    std::cout << "Game constructor called" << std::endl;
    isRunning = false;
}

Game::~Game(){
    std::cout << "Game destructor called" << std::endl;
}

void Game::Initialize(){
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0){
        std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return;
    }
    window = SDL_CreateWindow(
        NULL, 
        SDL_WINDOWPOS_CENTERED, 
        SDL_WINDOWPOS_CENTERED, 
        800, 
        600, 
        SDL_WINDOW_BORDERLESS);
    
    if(!window){
        std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        return;
    }
    renderer = SDL_CreateRenderer(window, -1, 0);
    if(!renderer){
        std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        return;
    }
    isRunning = true;
}

void Game::Run(){
    while(isRunning){
        ProcessInput();
        Update();
        Render();
    }
}

void Game::ProcessInput(){
    SDL_Event event;
    SDL_PollEvent(&event);
    switch(event.type){
        case SDL_QUIT:
            isRunning = false;
            break;
        case SDL_KEYDOWN:
            if(event.key.keysym.sym == SDLK_ESCAPE){
                isRunning = false;
            }
            break;
    }

}

void Game::Update(){}

void Game::Render(){
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
}

void Game::Destroy(){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    std::cout << "Game destroyed" << std::endl;
}