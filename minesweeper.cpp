#include "minesweeper.h"

using namespace std;

int boardSize;
vector<vector<int>> board;
vector<vector<bool>> check;
vector<int> dx = { -1,0,1,0,-1,-1,1,1 };
vector<int> dy = { 0,-1,0,1,-1,1,-1,1 };
bool flog = true;
int MineCount;
int Ground;

void mainWindow();

void setMine(int Mine)
{
    srand(time(0));
    int seccSetMine = 0;
    while (seccSetMine != Mine)
    {
        int x = rand() % boardSize; int y = rand() % boardSize;
        if (board[x][y] == 1)
            continue;
        board[x][y] = 1;
        seccSetMine++;
    }
}

bool IsSafetyArea(int curX, int curY)
{
    if (board[curX][curY] == 1)
        return false;
    else if (board[curX][curY] == 2)
        return true;
    board[curX][curY] = 2;
    Ground--;
    for (int i = 0; i < 4; i++)
    {
        int nextX = curX - dx[i];
        int nextY = curY - dy[i];
        if (nextX < 0 || nextX >= boardSize || nextY < 0 || nextY >= boardSize)
            continue;
        IsSafetyArea(nextX, nextY);
    }
    return true;
}

char CountMine(int x, int y)
{
    int count = 0;
    for (int i = 0; i < dx.size(); i++)
    {
        int nextX = x - dx[i];
        int nextY = y - dy[i];
        if (nextX < 0 || nextX >= boardSize || nextY < 0 || nextY >= boardSize)
            continue;
        if (board[nextX][nextY] == 1)
            count++;
    }
    char ret = ' ';
    if (count != 0)
        ret = char(count + 48);
    return ret;
}

int MineSweeper(int boardLen, int Mines)
{
    boardSize = boardLen;
    MineCount = Mines;
    Ground = boardSize * boardSize - MineCount;
    board = vector<vector<int>>(boardSize, vector<int>(boardSize, 0));
    check = vector<vector<bool>>(boardSize, vector<bool>(boardSize, false));
    setMine(MineCount);

    const int cellSize = 40; // 각 칸의 픽셀 크기
    const int screenWidth = boardSize * cellSize;
    const int screenHeight = boardSize * cellSize + 60;

    InitWindow(screenWidth, screenHeight, "Mine Sweeper");
    char MCount[100] = "";
    char GCount[100] = "";

    while (!WindowShouldClose())
    {
        Vector2 mouse = GetMousePosition();
        if (!(MineCount == 0 && Ground == 0) && flog)
        {
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                int mx = mouse.x / cellSize;
                int my = (mouse.y - 60) / cellSize;
                if (mx >= 0 && mx < boardSize && my >= 0 && my < boardSize)
                {
                    if (!IsSafetyArea(mx, my))
                        flog = false;
                }
            }
            else if (IsMouseButtonPressed(MOUSE_RIGHT_BUTTON))
            {
                int mx = mouse.x / cellSize;
                int my = (mouse.y - 60) / cellSize;
                if (board[mx][my] != 2 && mx >= 0 && mx < boardSize && my >= 0 && my < boardSize)
                {
                    if (check[mx][my] == true)
                    {
                        check[mx][my] = false;
                        MineCount++;
                    }
                    else
                    {
                        check[mx][my] = true;
                        MineCount--;
                    }
                }
            }
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        stringstream ss;
        ss << MineCount;
        ss >> MCount;
        ss.clear();
        ss << Ground;
        ss >> GCount;
        DrawText(GCount, 30, 5, 50, BLACK);
        DrawText(MCount, screenWidth - 95, 5, 50, BLACK);

        for (int i = 0; i < boardSize; i++)
        {
            for (int j = 0; j < boardSize; j++)
            {
                int x = i * cellSize;
                int y = j * cellSize + 60;

                // 마우스가 이 칸 위에 있는지 확인
                bool mouseOver = (mouse.x >= x && mouse.x < x + cellSize &&
                    mouse.y >= y && mouse.y < y + cellSize);


                Color color = mouseOver ? BLACK : LIGHTGRAY;

                if (board[i][j] == 2)
                {
                    char count[2] = " ";
                    count[0] = CountMine(i, j);
                    DrawRectangle(x, y, cellSize, cellSize, GRAY);
                    DrawText(count, x + 15, y, 40, BLACK);
                }
                else if (board[i][j] == 1 && !flog)
                    DrawRectangle(x, y, cellSize, cellSize, RED);
                else if (board[i][j] == 1 && MineCount == 0 && Ground == 0)
                    DrawRectangle(x, y, cellSize, cellSize, GREEN);
                else if (check[i][j] == true)
                {
                    DrawRectangle(x, y, cellSize, cellSize, LIGHTGRAY);
                    DrawText("!", x + 17, y + 2, 40, BLACK);
                }
                else
                    DrawRectangle(x, y, cellSize, cellSize, color);
                DrawRectangleLines(x, y, cellSize, cellSize, DARKGRAY);
            }
        }
        EndDrawing();
    }
    CloseWindow();
    mainWindow();
    return 0;
}