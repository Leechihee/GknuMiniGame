#include "minesweeper.h"
#include "catchthecoin.h"
#include "raylib.h"
#include <string>


std::string InputValue()
{

    std::string temp;
    int key = GetCharPressed();
    while (key > 0)
    {
        if (key >= '0' && key <= '9')
            temp += (char)key;
        key = GetCharPressed();
    }

    if (IsKeyPressed(KEY_BACKSPACE))
        if (!temp.empty()) temp.pop_back();

    if (IsKeyPressed(KEY_ENTER))
    {
        if (!temp.empty())
        {
            return temp;
        }
    }
}

void mainWindow()
{
    InitWindow(720, 480, "GknuMiniGame");
    SetTargetFPS(60);
    bool flag = true;
    while (!WindowShouldClose()) {
        if (flag)
        {
            BeginDrawing();
            ClearBackground(RAYWHITE);

            DrawText("GknuMiniGame", 27, 50, 100, BLACK);
            DrawText("1.  MineSweeper", 50, 240, 50, BLACK);
            DrawText("2. CatchTheCoin", 50, 320, 50, BLACK);
            EndDrawing();

            if (IsKeyPressed(KEY_ONE) || IsKeyPressed(KEY_KP_1))
            {
                flag = false;
                BeginDrawing();
                ClearBackground(RAYWHITE);
                DrawText("MineSweeper Setting", 40, 40, 40, BLACK);
                DrawText("Input BoardWidth : ", 40, 120, 30, BLACK);
                std::string boardWidth = InputValue();
                DrawText(boardWidth.c_str(), 400, 120, 30, BLUE);
                DrawText("Input Mine Count : ", 40, 200, 30, BLACK);
                std::string Mines = InputValue();
                DrawText(Mines.c_str(), 500, 200, 30, BLUE);
                EndDrawing();
            }
            else if (IsKeyPressed(KEY_TWO) || IsKeyPressed(KEY_KP_2))
            {
                CatchTheCoin();
                CloseWindow();
            }
        }
    }

    CloseWindow();
}

int main() {
    mainWindow();
    return 0;
}
