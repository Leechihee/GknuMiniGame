# GknuMiniGame.sln으로 들어가서 빌드하기!!!!!!!!
# 1. 실행 화면
## 메인 메뉴
![image](https://github.com/user-attachments/assets/9a44f036-45d1-46b6-8828-faf04092bfe3)
### 지뢰찾기 설정
![image](https://github.com/user-attachments/assets/c8a86cac-0f4b-42b1-ac10-ed2cc5b417d3)
##### 메인 메뉴소스코드 
[main.cpp](https://github.com/Leechihee/GknuMiniGame/blob/master/main.cpp)
#### 지뢰찾기
![image](https://github.com/user-attachments/assets/1964da6f-903f-49c1-997f-c2b1e33a974f)
![image](https://github.com/user-attachments/assets/a0dedc0b-d935-40cb-a370-7204eb6a76d8)
![image](https://github.com/user-attachments/assets/97bf6034-6ba4-4de9-bd25-918c4a2fbff3)
![image](https://github.com/user-attachments/assets/d232bd9c-8786-490b-9b84-deda97981fca)
![image](https://github.com/user-attachments/assets/a6d5cd15-ac56-45c3-863c-3975ad9c1a71)
###### 지뢰찾기 소스코드
[minesweeper.cpp](https://github.com/Leechihee/GknuMiniGame/blob/master/minesweeper.cpp)
### CatchTheCoin 메인 화면
![image](https://github.com/user-attachments/assets/1eb49b92-70f5-4f84-a0a6-7e7b344366b1)
#### CatchTheCoin 실행
![image](https://github.com/user-attachments/assets/4dd9b306-8fc9-48a6-811f-6345a62d7d06)
![image](https://github.com/user-attachments/assets/18358376-72c7-4648-8256-ab1ed3818748)
##### CatchTheCoin 소스코드
[catchthecoin.cpp](https://github.com/Leechihee/GknuMiniGame/blob/master/catchthecoin.cpp)
# 2. 시나리오
**1. 기획 의도  
이 프로그램은 누구나 쉽게 즐길 수 있는 두 가지 미니게임을 하나의 플랫폼에서 선택하여 플레이할 수 있도록 제작된 C++ 기반의 그래픽 게임 모음입니다. 사용자에게는 다양한 게임을 제공함으로써 재미와 몰입도를 높이고 개발자에게는 c++과 그래픽스 프로그래밍을 학습하는 데 목적이 있습니다.**
  
**2. 게임별 주요 기능 및 이용 방법**
<br>
**1) 코인 수집 게임**
  
**주요 기능:  
마우스를 클릭 후 드래그를 이용하여 플레이어(중앙 원)가 이동할 수 있습니다. 랜덤 위치에 생성되는 코인을 먹으면 스코어가 증가합니다. 1판 당 30초라는 제한 시간을 두었습니다.**
  
  
**이용 방법:  
마우스로 중앙의 원을 클릭해 이동하여 화면 곳곳에 등장하는 코인을 수집. 제한 시간 종료 시 총 점수 표시**
  
**2) 지뢰찾기 게임**
  
**주요 기능:  
2차원 배열 기반 지뢰 배치 및 셀 열기, 지뢰 판정, 지뢰찾기의 깃발 표시(!로 표현) 구현, 승패 조건 구현을 하였습니다. 셀 선택은 마우스 클릭을 통해 할 수 있습니다.**
  
**이용 방법:  
마우스로 원하는 셀을 클릭하여 오픈을 할 수 있습니다.  
지뢰가 없으면 숫자 또는 빈 칸으로 표시를 하였고  지뢰 클릭 시 게임 오버, 모든 지뢰 외 셀을 열면 승리하는 방식입니다.**


**3. 프로그램 진행 방식  
프로그램이 실행되면 게임 선택 화면이 나타납니다. 사용자 인터페이스는 raylib 라이브러리를 사용하여 제작하였으며 사용자는 1번 게임과 2번 게임 중 원하는 게임을 선택할 수 있습니다.**
  
**게임 선택:  
"1. 지뢰찾기" 또는 "2. 캐치 더 코인" 옵션을 제공하는 메뉴가 나타납니다.  
사용자는 키보드로 선택을 클릭하여 원하는 게임을 시작할 수 있습니다.**
  
**게임 플레이:  
선택한 게임이 실행되며 각 게임은 키보드의 1번, 2번 키를 이용하여 사용자가 화면에서 직접 상호작용할 수 있게 합니다.**

**게임 종료 후:
게임이 종료되면 "메인 화면으로 돌아가기" 버튼이 표시됩니다. 사용자는 이를 클릭하여 다시 게임을 선택할 수 있습니다.**
# 3. 소감
## 20220938 이치희 
**raylib를 이용하여 간단한 지뢰찾기를 만들면서 2D 그래픽에 대한 접근성이 전보다 눈에 띄게 늘어났다는 것을 체험하였습니다.  
지뢰찾기에 필요한 알고리즘과 개념을 알고 있어서 콘솔로 지뢰찾기를 만들 줄 알았지만 GUI로 보이는 지뢰찾기는 외부 라이브러리 사용에 대한 부담감이 있었기 때문에 만들지 못하였습니다.  
하지만 이번 기회에 그 부담감을 덜어낼 수 있는 강의와 팀프로젝트를 통해 부담감을 줄였습니다.  
성유현과 저는 각각 게임 하나씩 만들고 메인 창을 이윤재가 담당함으로써 역할분담을 하였고 서로 결과물에 대한 피드백을 하여 더 좋은 결과물을 만들기 위해 노력하였습니다.
마지막으로 소감을 정리하자면 외부 라이브러리 사용의 부담감을 줄였고 팀 역할분담을 통해 개개인의 부담을 줄이며 각자의 결과물에 대한 피드백을 통해 더 좋은 방향으로 성장을 했습니다.  
이번 팀프로젝트를 통해 여러 경험을 할 수 있었습니다.**

## 20240950 이윤재
**오랜만에 하게 된 팀플이었다. 이번 팀플에서는 수업시간 때 배운 raylib를 사용하여 예제를 만드는 것을 하였다.  
그래픽스와 관련된 것들을 찾아보면서 무엇을 할까 고민하던 중 게임을 만들자는 아이디어가 나오게 되어 게임을 만들게 되었다.  
게임을 직접 만들어보면서 C++ 문법뿐만 아니라 그래픽스를 다루는 감각도 많이 익히고 게임을 직접 우리가 만들었다는 성취감도 느낄 수 있었다.  
이번 팀플을 통해 다양한 경험들을 할 수 있게 되어 좋은 경험이 되었다.**

## 20250673 성유현
**c언어로 raylib를 사용해서 블록깨기 게임을 만들 때는 구현하고 싶은것은 많았지만 한계가 있었습니다. 하지만 cpp을 사용해서 클래스를 만들어 사용해 코인에 훨씬 다양한 능력들을 넣을 수 있었습니다.  
처음 c언어와 cpp을 배울때는 기존 문법에도 어려움을 겪어 raylib의 문법이 많이 어색했지만 팀프로젝트를 하며 raylib의 문법에 이해하고 cpp의 클래스 사용에 조금은 더 가까워질 수 있었습니다.  
아직은 어렵고 숙련되었다고 표현할 수는 없겠지만 조금은 cpp에 대한 이해도가 생김을 확인할 수 있는 경험이 되었습니다.**

LMS : https://lms.andong.ac.kr/ilos/st/course/project_team_detail_view_form.acl?PROJECT_SEQ=3500561&TEAM_CD=36974&SHARE_YN=N&MY_TEAM_CD=36974&display=1&start=1&week=
