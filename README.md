# 실행 화면
## 메인 메뉴
![image](https://github.com/user-attachments/assets/717fbb3b-3d6a-46e6-b569-2369b6fd6fd4)
##### 소스코드 
https://github.com/Leechihee/GknuMiniGame/blob/master/main.cpp
### 지뢰찾기 설정
![image](https://github.com/user-attachments/assets/f4f75da1-ff85-4d43-b342-2a17245d9d37)
#### 지뢰찾기
![image](https://github.com/user-attachments/assets/bd8712b0-5c38-4e97-8c2f-62f6780ca630)
![image](https://github.com/user-attachments/assets/a26437ff-6f4a-4c83-be9a-e3bbede9a73d)
![image](https://github.com/user-attachments/assets/aa75801f-cf3b-4b94-9c20-4dd72e769945)
![image](https://github.com/user-attachments/assets/0871a620-3116-4c34-8d1b-e81f8da6f32f)
###### 소스코드
[minesweeper.cpp](https://github.com/Leechihee/GknuMiniGame/blob/master/minesweeper.cpp)
### CatchTheCoin 메인 화면
![image](https://github.com/user-attachments/assets/1eb49b92-70f5-4f84-a0a6-7e7b344366b1)
#### CatchTheCoin 실행
![image](https://github.com/user-attachments/assets/4dd9b306-8fc9-48a6-811f-6345a62d7d06)
##### 소스코드
https://github.com/Leechihee/GknuMiniGame/blob/master/catchthecoin.cpp
# 시나리오
1. 기획 의도 
이 프로그램은 누구나 쉽게 즐길 수 있는 두 가지 미니게임을 하나의 플랫폼에서 선택하여 플레이할 수 있도록 제작된 C++ 기반의 그래픽 게임 모음입니다. 사용자에게는 다양한 게임을 제공함으로써 재미와 몰입도를 높이고 개발자에게는 c++과 그래픽스 프로그래밍을 학습하는 데 목적이 있습니다.

2. 게임별 주요 기능 및 이용 방법
1) 코인 수집 게임

주요 기능:
마우스를 클릭 후 드래그를 이용하여 플레이어(중앙 원)가 이동할 수 있습니다. 랜덤 위치에 생성되는 코인을 먹으면 스코어가 증가합니다. 1판 당 30초라는 제한 시간을 두었습니다.


이용 방법:
마우스로 중앙의 원을 클릭해 이동하여 화면 곳곳에 등장하는 코인을 수집. 제한 시간 종료 시 총 점수 표시

2) 지뢰찾기 게임

주요 기능:
2차원 배열 기반 지뢰 배치 및 셀 열기, 지뢰 판정, 지뢰찾기의 깃발 표시(!로 표현) 구현, 승패 조건 구현을 하였습니다. 셀 선택은 마우스 클릭을 통해 할 수 있습니다.

이용 방법:
마우스로 원하는 셀을 클릭하여 오픈을 할 수 있습니다.
지뢰가 없으면 숫자 또는 빈 칸으로 표시를 하였고  지뢰 클릭 시 게임 오버, 모든 지뢰 외 셀을 열면 승리하는 방식입니다.


3. 프로그램 진행 방식
프로그램이 실행되면 게임 선택 화면이 나타납니다. 사용자 인터페이스는 raylib 라이브러리를 사용하여 제작하였으며 사용자는 1번 게임과 2번 게임 중 원하는 게임을 선택할 수 있습니다.

게임 선택:
"1. 지뢰찾기" 또는 "2. 캐치 더 코인" 옵션을 제공하는 메뉴가 나타납니다.
사용자는 마우스로 선택을 클릭하여 원하는 게임을 시작할 수 있습니다.

게임 플레이:
선택한 게임이 실행되며 각 게임은 키보드의 1번, 2번 키를 이용하여 사용자가 화면에서 직접 상호작용할 수 있게 합니다.

게임 종료 후:
게임이 종료되면 "메인 화면으로 돌아가기" 버튼이 표시됩니다. 사용자는 이를 클릭하여 다시 게임을 선택할 수 있습니다.

#소감

## 20240950 이윤재
오랜만에 팀플을 하였다. 이번 팀플에서는 수업시간 때 배운 raylib를 사용하여 예제를 만드는 것을 하였다. 그래픽스와 관련된 것들을 찾아보면서 무엇을 할까 고민하던 중 게임을 만들자는 아이디어가 나오게 되어 게임을 만들게 되었다. 게임을 직접 만들어보면서 C++ 문법뿐만 아니라 그래픽스를 다루는 감각도 많이 익히고 게임을 직접 우리가 만들었다는 성취감도 느낄 수 있었다. 이번 팀플을 통해 다양한 경험들을 할 수 있게 되어 좋은 경험을 얻었다고 생각한다.

## 20250673 성유현
