//
// Created by tally on 09/09/24.
//

#include "View.h"
#include "../Controller/Controller.h"
#include "SDL_Const.h"
#include "iostream"

View::View(Controller* controller) : lastFrameTime_(0), controller_(controller)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        exit(SDL_EXIT_ERROR);
    }

    sdl_window_ = SDL_CreateWindow(SDL_WINDOW_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SDL_WINDOW_WIDTH, SDL_WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    if (sdl_window_ == nullptr) {
        std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        exit(SDL_EXIT_ERROR);
    }

    sdl_renderer_ = SDL_CreateRenderer(sdl_window_, SDL_RENDERER_INDEX, SDL_RENDERER_ACCELERATED);
    if (sdl_renderer_ == nullptr) {
        std::cerr << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        exit(SDL_EXIT_ERROR);
    }
}

View::~View()
= default;


void View::input() const {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT || (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)) {
            controller_->stopRunning();
        }
    }
}

void View::draw() const
{
    drawBackground(0, 0, 0, 255);
    drawFoods();
    drawCells();
    Render();
}

void View::waitFrame(float &dt) {
    const auto currentTime = static_cast<float>(SDL_GetTicks());
    dt = currentTime - lastFrameTime_;
    if (const float timeToWait = SDL_FRAME_TIME - dt; timeToWait > 0) {
        SDL_Delay(static_cast<Uint32>(timeToWait));
        dt += timeToWait;
    }
    lastFrameTime_ = currentTime;
}


void View::drawBackground(const int r, const int g, const int b, const int a) const {
    SDL_SetRenderDrawColor(sdl_renderer_, r, g, b, a);
    SDL_RenderClear(sdl_renderer_);
}


void View::Render() const{
    SDL_RenderPresent(sdl_renderer_);
}

void View::drawCells() const
{
    SDL_SetRenderDrawColor(sdl_renderer_, 255, 0, 0, 255);
    float x, y;
    controller_->getCellPos(x, y);
    fillCircle(x, y, CELL_SIZE);
}

void View::drawFoods() const
{
    SDL_SetRenderDrawColor(sdl_renderer_, 0, 255, 0, 255);
    float x, y;
    controller_->getFoodPos(x, y);
    fillCircle(x, y, FOOD_SIZE);
}


void View::fillCircle(const float x, const float y, const float r) const {
    int cx = static_cast<int>(r);
    int cy = 0;
    int radiusError = 1 - cx;

    while (cx >= cy) {
        for (int i = static_cast<int>(x) - cx; i <= static_cast<int>(x) + cx; i++) {
            SDL_RenderDrawPoint(sdl_renderer_, i, static_cast<int>(y) + cy);
            SDL_RenderDrawPoint(sdl_renderer_, i, static_cast<int>(y) - cy);
        }
        for (int i = static_cast<int>(x) - cy; i <= static_cast<int>(x) + cy; i++) {
            SDL_RenderDrawPoint(sdl_renderer_, i, static_cast<int>(y) + cx);
            SDL_RenderDrawPoint(sdl_renderer_, i, static_cast<int>(y) - cx);
        }

        cy++;

        if (radiusError < 0) {
            radiusError += 2 * cy + 1;
        } else {
            cx--;
            radiusError += 2 * (cy - cx + 1);
        }
    }
}