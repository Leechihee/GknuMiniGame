#include "minesweeper.h"
#include "catchthecoin.h"
#include "raylib.h"
#include <string>
#include <cctype>

// 게임 메뉴 화면 프로토타입
void mainWindow();

// 입력받기 위한 함수
void InputValue(std::string& str, bool& PressedKey)
{
    int key = GetCharPressed();
    while (key > 0)
    {
        if (std::isdigit(key))
            str += (char)key;
        key = GetCharPressed();
    }

    if (IsKeyPressed(KEY_BACKSPACE) && !str.empty())
        str.pop_back();

    if (IsKeyPressed(KEY_ENTER) && !str.empty())
        PressedKey = true;
    if (IsKeyPressed(KEY_ESCAPE))
    {
        CloseWindow();
        mainWindow();
    }
}

// 게임 메뉴 화면 1 누르면 지뢰찾기, 2 누르면 CatchTheCoin 게임 화며 띄우기
void mainWindow()
{
    InitWindow(720, 480, "GknuMiniGame");
    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawText("GknuMiniGame", 27, 50, 100, BLACK);
        DrawText("1.  MineSweeper", 50, 240, 50, BLACK);
        DrawText("2. CatchTheCoin", 50, 320, 50, BLACK);
        EndDrawing();

        if (IsKeyPressed(KEY_ONE) || IsKeyPressed(KEY_KP_1))
        {
            std::string boardWidth = "";
            bool PressedEnter = false;
            while (!PressedEnter && !WindowShouldClose())
            {
                BeginDrawing();
                ClearBackground(RAYWHITE);
                DrawText("MineSweeper Setting", 40, 40, 40, BLACK);
                DrawText("Input BoardWidth : ", 40, 120, 30, BLACK);
                DrawText(boardWidth.c_str(), 400, 120, 30, BLUE);
                EndDrawing();
                InputValue(boardWidth,PressedEnter);
            }

            PressedEnter = false;
            std::string Mines = "";
            while (!PressedEnter && !WindowShouldClose())
            {
                BeginDrawing();
                ClearBackground(RAYWHITE);
                DrawText("MineSweeper Setting", 40, 40, 40, BLACK);
                DrawText("Input BoardWidth : ", 40, 120, 30, BLACK);
                DrawText(boardWidth.c_str(), 400, 120, 30, BLUE);
                DrawText("Input Mine Count : ", 40, 200, 30, BLACK);
                DrawText(Mines.c_str(), 400, 200, 30, BLUE);
                EndDrawing();
                InputValue(Mines, PressedEnter);
            }

            CloseWindow();
            MineSweeper(stoi(boardWidth),stoi(Mines));
        }
        else if (IsKeyPressed(KEY_TWO) || IsKeyPressed(KEY_KP_2))
        {
            CloseWindow();
            CatchTheCoin();
        }
    }
    CloseWindow();
}

int main() {
    mainWindow();
    return 0;
}
