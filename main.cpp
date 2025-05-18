#include "minesweeper.h"
#include "catchthecoin.h"
#include "raylib.h"
#include <string>
#include <cctype>

// ���� �޴� ȭ�� ������Ÿ��
void mainWindow();

// �Է¹ޱ� ���� �Լ�
void InputValue(std::string& str, bool& PressedEnter, bool& PressedESC)
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
        PressedEnter = true;
    if (IsKeyPressed(KEY_ESCAPE))
        PressedESC = true;
}

// ���� �޴� ȭ�� 1 ������ ����ã��, 2 ������ CatchTheCoin ���� ȭ�� ����
void mainWindow()
{
    InitWindow(720, 480, "GknuMiniGame");
    SetExitKey(0); // ESC�� â�� ������ �ʰ� �ϱ� ���� �Լ�
    SetTargetFPS(60);

    Color BackgroundColor = BLACK;
    Color TextColor = LIGHTGRAY;

    bool loop = true;

    while (!WindowShouldClose() && loop)
    {
        BeginDrawing();
        ClearBackground(BackgroundColor);

        DrawText("GknuMiniGame", 27, 50, 100, TextColor);
        DrawText("1.  MineSweeper", 50, 240, 50, TextColor);
        DrawText("2. CatchTheCoin", 50, 320, 50, TextColor);
        EndDrawing();

        if (IsKeyPressed(KEY_ONE) || IsKeyPressed(KEY_KP_1))
        {
            std::string boardWidth = "";
            bool pressedEnter = false;
            bool pressedESC = false;
            while (!pressedEnter && !pressedESC && !WindowShouldClose())
            {
                BeginDrawing();
                ClearBackground(BackgroundColor);
                DrawText("MineSweeper Setting", 40, 40, 40, TextColor);
                DrawText("Input BoardWidth : ", 40, 120, 30, TextColor);
                DrawText(boardWidth.c_str(), 400, 120, 30, BLUE);
                EndDrawing();
                InputValue(boardWidth, pressedEnter, pressedESC);
            }

            if (pressedESC) continue;

            pressedEnter = false;
            std::string Mines = "";
            while (!pressedESC && !pressedEnter && !WindowShouldClose())
            {
                BeginDrawing();
                ClearBackground(BackgroundColor);
                DrawText("MineSweeper Setting", 40, 40, 40, TextColor);
                DrawText("Input BoardWidth : ", 40, 120, 30, TextColor);
                DrawText(boardWidth.c_str(), 400, 120, 30, BLUE);
                DrawText("Input Mine Count : ", 40, 200, 30, TextColor);
                DrawText(Mines.c_str(), 400, 200, 30, BLUE);
                EndDrawing();
                InputValue(Mines, pressedEnter, pressedESC);
            }

            if (pressedESC) continue;

            CloseWindow();
            MineSweeper(stoi(boardWidth), stoi(Mines));
        }
        else if (IsKeyPressed(KEY_TWO) || IsKeyPressed(KEY_KP_2))
        {
            CloseWindow();
            CatchTheCoin();
        }
        else if (IsKeyPressed(KEY_ESCAPE))
            loop = false;
    }
    CloseWindow();
}

int main() {
    mainWindow();
    return 0;
}
