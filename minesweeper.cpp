#include "minesweeper.h"

using namespace std;

// �Ű��������� ���̱� ���� ����������
int boardSize; // ����ã�⺸�� �Ѻ��� ����
vector<vector<int>> board; // ����ã�⺸�� (2�����迭)
// 0 = �������� , 1 = ���� , 2 = ��������
vector<vector<bool>> check; // ã�� ���ڸ� �����ϱ� ���� 2���� �迭
// DFS ����ϱ� ���� 1�����迭��
vector<int> dx = { -1,0,1,0,-1,-1,1,1 }; 
vector<int> dy = { 0,-1,0,1,-1,1,-1,1 }; 
bool flag; // ���ڸ� ���� ���ӿ��������� �˸��� ���� �⺻�� false
int MineCount; // ���� ���� ���� ����
int Ground; // ���� ���� ���� ����

// main.cpp�� �ִ� �Լ� ������Ÿ��
void mainWindow();

// ���� �����Ҷ� ���ڼ���
//void setMine(int Mine)
//{
//    srand(time(0));
//    int seccSetMine = 0;
//    while (seccSetMine != Mine)
//    {
//        int x = rand() % boardSize; int y = rand() % boardSize;
//        if (board[x][y] == 1)
//            continue;
//        board[x][y] = 1;
//        seccSetMine++;
//    }
//}

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

// DFS ��� �˰������� �ѹ� ������ �� ����Ǿ��ִ� ���������� �� Ž���Ͽ� �ѹ��� �������� �ϱ�
// ���� ó�� Ž���� ������ ���ڿ��ٸ� false ����, �ƴ϶�� true ����
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

// �������� �ֺ��� �ִ� ���� ������ Ž���ϰ� ǥ���ϴ� �Լ�
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

// ����ã�� ���� �Լ�
int MineSweeper(int boardLen, int Mines)
{
    // ������ ���������� �� �ʱ�ȭ�ϱ�
    boardSize = boardLen;
    MineCount = Mines;
    Ground = boardSize * boardSize - MineCount;
    flag = true;
    board = vector<vector<int>>(boardSize, vector<int>(boardSize, 0));
    check = vector<vector<bool>>(boardSize, vector<bool>(boardSize, false));

    // ������ �����ϱ� �� ���ڼ�ġ�ϱ�
    setMine(MineCount);

    // ����ã�� â�� ũ�� ������ ���� ��ĭ�� ũ�� ���ϱ�
    const int cellSize = 40; // �� ĭ�� �ȼ� ũ��
    const int screenWidth = boardSize * cellSize;
    const int screenHeight = boardSize * cellSize + 60;

    InitWindow(screenWidth, screenHeight, "Mine Sweeper");

    char MCount[100] = ""; // ���� ���� ����
    char GCount[100] = ""; // ���� �������� ����

    bool ReTry = true; // �������� �� �ٽ� �õ��Ұ��� ����� ����

    while (!WindowShouldClose() && ReTry)
    {
        Vector2 mouse = GetMousePosition();
        // ������ �¸��� ������ �ʾ��� ��
        if (!(MineCount == 0 && Ground == 0) && flag)
        {
            // ���콺 ���ʹ�ư�� ������ �ش� ������ ������������ Ȯ���ϴ� ���ǹ�
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                int mx = mouse.x / cellSize;
                int my = (mouse.y - 60) / cellSize;
                if (mx >= 0 && mx < boardSize && my >= 0 && my < boardSize)
                {
                    if (!IsSafetyArea(mx, my)) // ù Ž���� ���ڿ��ٸ�
                        flag = false; // ���� �й�
                }
            }
            // ������ ������ Ŭ���� �Ѵٸ� �ش� ������ !�� �ִٸ� ���ְ� ���ٸ� ����� �ϴ� ���ǹ�
            else if (IsMouseButtonPressed(MOUSE_RIGHT_BUTTON))
            {
                int mx = mouse.x / cellSize;
                int my = (mouse.y - 60) / cellSize;
                if (board[mx][my] != 2 && mx >= 0 && mx < boardSize && my >= 0 && my < boardSize)
                {
                    // �ش� ������ !�� �ִٸ�
                    if (check[mx][my] == true)
                    {
                        check[mx][my] = false; // !�� ���ְ�
                        MineCount++; // ã�ƾ��� ���� ����
                    }
                    else // !�� ���ٸ�
                    {
                        check[mx][my] = true; // !�� �߰��ϰ�
                        MineCount--; // ã�ƾ��� ���� ����
                    }
                }
            }
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        // ������ ���ڿ��� �ٲٱ� ���� stringstream ����
        stringstream ss;
        ss << MineCount;
        ss >> MCount;
        ss.clear();
        ss << Ground;
        ss >> GCount;
        DrawText(GCount, 30, 5, 50, BLACK);
        DrawText(MCount, screenWidth - 95, 5, 50, RED);

        for (int i = 0; i < boardSize; i++)
        {
            for (int j = 0; j < boardSize; j++)
            {
                int x = i * cellSize;
                int y = j * cellSize + 60;

                // ���콺�� �� ĭ ���� �ִ��� Ȯ��
                bool mouseOver = (mouse.x >= x && mouse.x < x + cellSize &&
                    mouse.y >= y && mouse.y < y + cellSize);


                Color color = mouseOver ? BLACK : LIGHTGRAY;
                color = flag ? color : LIGHTGRAY;

                // �ش� ������ ���������̶��
                if (board[i][j] == 2)
                {
                    char count[2] = " "; // �ϴ� ��ĭ���� ä���
                    count[0] = CountMine(i, j); // �ֺ��� ���� ������ ã�� �ִٸ� ����
                    DrawRectangle(x, y, cellSize, cellSize, GRAY); //ȸ�� ���簢�� ĭ��
                    DrawText(count, x + 15, y, 40, BLACK); // �ֺ� ���� ������ �ִ´�
                }
                // �ش� ������ �����̸� ���� �й踦 �ߴٸ�
                else if (board[i][j] == 1 && !flag)
                {
                    DrawRectangle(x, y, cellSize, cellSize, RED); // �ش� ������ ���������� ó���ϰ�
                    DrawText("ReTry : R", screenWidth/4 , screenHeight/2-50, 40, GREEN); // �ٽ� �õ��Ұ���?
                    DrawText("Exit : ESC", screenWidth / 4, screenHeight/2+50, 40, GREEN); // �ƴϸ� �����Ұ���?
                    if (IsKeyPressed(KEY_ESCAPE)) // Ű �Է����� �����Ѵ�. ESC�� ������ ����
                        ReTry = false;
                    else if (IsKeyPressed(KEY_R)) // R�� ������ ��õ�
                    {
                        EndDrawing();
                        CloseWindow();
                        MineSweeper(boardLen, Mines);
                    }
                    // �ƹ� ��찡 �ƴ� ��� ��� ǥ��
                } 
                // �ش� ������ �����̰� ���� �¸���
                else if (board[i][j] == 1 && MineCount == 0 && Ground == 0)
                    DrawRectangle(x, y, cellSize, cellSize, GREEN); // �ʷϻ����� ó��
                else if (check[i][j] == true) // �ش� ������ ���������̶�� �����ȴٸ�
                {
                    DrawRectangle(x, y, cellSize, cellSize, LIGHTGRAY); // ���� ȸ������ ĭ�� ä���
                    DrawText("!", x + 17, y + 2, 40, BLACK); // !�� �ִ´�
                }
                // ��� ��찡 �ƴ϶�� ���� Ȯ������ ���� �����̹Ƿ�
                else 
                    DrawRectangle(x, y, cellSize, cellSize, color); // color ������ ������ �ִ´�
                DrawRectangleLines(x, y, cellSize, cellSize, DARKGRAY); // ���ڰ��� ������ ��輱
            }
        }
        EndDrawing();
    }
    CloseWindow();
    mainWindow();
    return 0;
}