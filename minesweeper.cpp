#include "minesweeper.h"

using namespace std;

// 매개변수들을 줄이기 위한 전역변수들
int boardSize; // 지뢰찾기보드 한변의 길이
vector<vector<int>> board; // 지뢰찾기보드 (2차원배열)
// 0 = 미지구역 , 1 = 지뢰 , 2 = 안전구역
vector<vector<bool>> check; // 찾은 지뢰를 저장하기 위한 2차원 배열
// DFS 사용하기 위한 1차원배열들
vector<int> dx = { -1,0,1,0,-1,-1,1,1 }; 
vector<int> dy = { 0,-1,0,1,-1,1,-1,1 }; 
bool flag; // 지뢰를 눌러 게임오버됬음을 알리는 변수 기본값 false
int MineCount; // 현재 남은 지뢰 개수
int Ground; // 현재 미지 구역 개수

// main.cpp에 있는 함수 프로토타입
void mainWindow();

// 게임 시작할때 지뢰설정
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

// DFS 기반 알고리즘으로 한번 눌렀을 때 연결되어있는 안전구역을 다 탐색하여 한번에 열리도록 하기
// 만약 처음 탐색한 구역이 지뢰였다면 false 리턴, 아니라면 true 리턴
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

// 안전구역 주변에 있는 지뢰 개수를 탐색하고 표기하는 함수
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

// 지뢰찾기 메인 함수
int MineSweeper(int boardLen, int Mines)
{
    // 선언한 전역변수에 값 초기화하기
    boardSize = boardLen;
    MineCount = Mines;
    Ground = boardSize * boardSize - MineCount;
    flag = true;
    board = vector<vector<int>>(boardSize, vector<int>(boardSize, 0));
    check = vector<vector<bool>>(boardSize, vector<bool>(boardSize, false));

    // 게임을 시작하기 전 지뢰설치하기
    setMine(MineCount);

    // 지뢰찾기 창의 크기 설정과 구역 한칸의 크기 정하기
    const int cellSize = 40; // 각 칸의 픽셀 크기
    const int screenWidth = boardSize * cellSize;
    const int screenHeight = boardSize * cellSize + 60;

    InitWindow(screenWidth, screenHeight, "Mine Sweeper");

    char MCount[100] = ""; // 남은 지뢰 갯수
    char GCount[100] = ""; // 남은 안전구역 갯수

    bool ReTry = true; // 실패했을 때 다시 시도할건지 물어보는 변수

    while (!WindowShouldClose() && ReTry)
    {
        Vector2 mouse = GetMousePosition();
        // 게임이 승리로 끝나지 않았을 때
        if (!(MineCount == 0 && Ground == 0) && flag)
        {
            // 마우스 왼쪽버튼을 누르면 해당 구역이 안전구역인지 확인하는 조건문
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                int mx = mouse.x / cellSize;
                int my = (mouse.y - 60) / cellSize;
                if (mx >= 0 && mx < boardSize && my >= 0 && my < boardSize)
                {
                    if (!IsSafetyArea(mx, my)) // 첫 탐색이 지뢰였다면
                        flag = false; // 게임 패배
                }
            }
            // 오른쪽 오른쪽 클릭을 한다면 해당 구역에 !가 있다면 없애고 없다면 생기게 하는 조건문
            else if (IsMouseButtonPressed(MOUSE_RIGHT_BUTTON))
            {
                int mx = mouse.x / cellSize;
                int my = (mouse.y - 60) / cellSize;
                if (board[mx][my] != 2 && mx >= 0 && mx < boardSize && my >= 0 && my < boardSize)
                {
                    // 해당 구역에 !가 있다면
                    if (check[mx][my] == true)
                    {
                        check[mx][my] = false; // !를 없애고
                        MineCount++; // 찾아야할 지뢰 증가
                    }
                    else // !가 없다면
                    {
                        check[mx][my] = true; // !를 추가하고
                        MineCount--; // 찾아야할 지뢰 감소
                    }
                }
            }
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        // 정수를 문자열로 바꾸기 위한 stringstream 선언
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

                // 마우스가 이 칸 위에 있는지 확인
                bool mouseOver = (mouse.x >= x && mouse.x < x + cellSize &&
                    mouse.y >= y && mouse.y < y + cellSize);


                Color color = mouseOver ? BLACK : LIGHTGRAY;
                color = flag ? color : LIGHTGRAY;

                // 해당 구역이 안전구역이라면
                if (board[i][j] == 2)
                {
                    char count[2] = " "; // 일단 빈칸으로 채우고
                    count[0] = CountMine(i, j); // 주변에 지뢰 개수를 찾고 있다면 삽입
                    DrawRectangle(x, y, cellSize, cellSize, GRAY); //회색 정사각형 칸에
                    DrawText(count, x + 15, y, 40, BLACK); // 주변 지뢰 개수를 넣는다
                }
                // 해당 구역이 지뢰이며 게임 패배를 했다면
                else if (board[i][j] == 1 && !flag)
                {
                    DrawRectangle(x, y, cellSize, cellSize, RED); // 해당 구역을 빨간색으로 처리하고
                    DrawText("ReTry : R", screenWidth/4 , screenHeight/2-50, 40, GREEN); // 다시 시도할건지?
                    DrawText("Exit : ESC", screenWidth / 4, screenHeight/2+50, 40, GREEN); // 아니면 종료할건지?
                    if (IsKeyPressed(KEY_ESCAPE)) // 키 입력으로 결정한다. ESC를 누르면 종료
                        ReTry = false;
                    else if (IsKeyPressed(KEY_R)) // R을 누르면 재시도
                    {
                        EndDrawing();
                        CloseWindow();
                        MineSweeper(boardLen, Mines);
                    }
                    // 아무 경우가 아닌 경우 계속 표시
                } 
                // 해당 구역이 지뢰이고 게임 승리면
                else if (board[i][j] == 1 && MineCount == 0 && Ground == 0)
                    DrawRectangle(x, y, cellSize, cellSize, GREEN); // 초록색으로 처리
                else if (check[i][j] == true) // 해당 구역에 안전구역이라고 생각된다면
                {
                    DrawRectangle(x, y, cellSize, cellSize, LIGHTGRAY); // 밝은 회색으로 칸을 채우고
                    DrawText("!", x + 17, y + 2, 40, BLACK); // !를 넣는다
                }
                // 모든 경우가 아니라면 아직 확인하지 않은 구역이므로
                else 
                    DrawRectangle(x, y, cellSize, cellSize, color); // color 변수의 색상을 넣는다
                DrawRectangleLines(x, y, cellSize, cellSize, DARKGRAY); // 지뢰게임 보드판 경계선
            }
        }
        EndDrawing();
    }
    CloseWindow();
    mainWindow();
    return 0;
}