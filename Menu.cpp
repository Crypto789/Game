#include "MENU.h"
#include <string>
#include <iostream>
#include "renderer.h"
#include "Functionality.h"
#include "game.h"

void MENU::Prompt() {

    constexpr std::size_t kFramesPerSecond{ 60 },
        kMsPerFrame{ 1000 / kFramesPerSecond },
        kScreenWidth{ 1080 }, kScreenHeight{ 720 },
        kGridWidth{ 32 },
        kGridHeight{ 32 };
    Functionality controller;
    Game game(kGridWidth, kGridHeight);
    Renderer mRenderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);

        int user_Choice = 0;
        std::cout << "1. START GAME:\n2.EXIT:" << std::endl;
        std::cin >> user_Choice;
        while (user_Choice != 0)
        {
            switch (user_Choice)
            {
            case 0:
                std::cout << "Game has terminated successfully!\n";
                std::cout << "Score: " << game.GetScore() << "\n";
                std::cout << "Size: " << game.GetSize() << "\n";
                break;
            case 1:
                game.Run(controller, mRenderer, kMsPerFrame);
                continue;

            } 
        }
};