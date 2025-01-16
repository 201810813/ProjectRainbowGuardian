# 🌈Project_RainbowGuardian
- **프로젝트**
    -  
    - **🌈레인보우 가디언**
      
- **프로젝트 개요**
    -  
    -  플레이어가 8가지 컨셉으로 구성된 미로형 타워를 탐험하며, 층마다 고유한 테마와 몬스터를 마주하는 **콘솔 텍스트 기반 RPG 게임 프로젝트** 입니다. 주요 시스템으로는 전투, 상점, 제단 등 다양한 장소와 아이템 수집 및 최종 보스를 공략하는 도전 요소가 포함되어 있습니다.  
  
- **메인 스토리**
    -  
  - *프롤로그*
    
        > 색을 먹어치우는 저주가 세상을 덮치기 시작했따.
        > 모든 것이 흑백으로 변해가는 가운데, 유일하게 탑 상층부가 빛나는 거대한 탑이 나타났따.
        > 탑의 각 층에는 색채 구슬이 봉인되어 있다고 한다.
        > 각 층마다 색채 구슬을 얻어내면 옥탑으로 올라갈 수 있게 된다. 옥탑에는 레인보우 드래곤이 있따.
        > 주인공은 마지막 색채 검사로서 투명 드래곤보다 더 짱쎈 🌈레인보우 드래곤🌈에게 소원을 빌어 세상의 색을 되찾아야 하는데...

  - **엔딩** : 탑의 정상에서 주인공은 충격적인 진실을 마주하게 된다. 색을 다 먹어치운 것이 사실은 소원을 빌러간 **레인보우 드래곤**이었던 것... 
용을 물리치고 탑을 정화하면, 세상은 다시 색을 되찾게 된다.
  
- **주요 기능 요약**
    -  
  - **콘솔 기반 UI**: 입력 및 출력을 활용한 간단한 텍스트 기반 게임 인터페이스.
  - **층 탐험 및 진행**: 8가지 컨셉으로 구성된 미로형 타워에서 각 층의 테마와 난이도에 따라 진행.
    - **랜덤 씬 생성**: 배틀, 제단, 상점 등 다양한 씬을 랜덤하게 생성하여 플레이어에게 예측 불가한 경험 제공. 
    -     7 [🐲] : 옥탑 씬 - Final
          6 [❓] : 미탐험
          5 [🛒] : 상점 씬 - ShopScene
          4 [⛲] : 제단 씬 - AltarScene
          3 [⚔️] : 전투 씬 - Scene3F
          2 [⚔️] : 전투 씬 - Scene2F
          1 [⚔️] : 전투 씬 - Scene1F
  - **전투 시스템**: 몬스터와의 기본 전투 기능 구현. 8층에서 최종 보스를 물리치는 도전 요소 제공.

| 층/위치        | 이름(의미)                   | 주요 몬스터            | 특징                               |
|:--------------:|:---------------------------:|:----------------------:|:-----------------------------------:|
| **1층**       | **붉은 분노의 층**           | 불도깨비              | 화염 기반                           |
| **2층**       | **주황 욕망의 층**           | 아이언 골렘           | 금속 기반                           |
| **3층**       | **노란 환희의 층**           | 전기사마귀            | 전기 기반                           |
| **4층**       | **녹색 생명의 층**           | 독덩쿠리              | 독 기반                             |
| **5층**       | **파란 고독의 층**           | 고드름치              | 얼음 기반                           |
| **6층**       | **남색 슬픔의 층**           | 안개마녀              | 안개 기반                           |
| **7층**       | **보라 환영의 층**           | 똑닮은 환영           | 환영 기반                           |
| **옥상(옥탑)** | **무지개 색의 옥탑** *(레벨10 미만 진입 불가)* | 최종 보스: 레인보우 드래곤 | 7가지 컬러 마블을 모두 모으면 해금, 최종 보스전! |

  - **아이템 수집 및 관리**: 전투나 상점에서 획득 가능한 아이템을 통해 플레이어 강화.
  - **C++ 라이브러리 및 STL 활용**
      - 표준 라이브러리(STL)
        - `vector`: 씬 관리 및 데이터 구조 구성.
        - `shared_ptr`: 메모리 관리를 위한 스마트 포인터 활용.
        - `algorithm`: 데이터 검색 및 정렬 같은 다양한 알고리즘 지원.
      - 사용한 라이브러리
        - `FMOD`: 게임 및 기타 인터랙티브 미디어를 위한 오디오 엔진 및 미들웨어 솔루션을 사용.

- **프로젝트 팀원 및 역할**
    -  

| **이름** | **역할**                         | **담당 업무**                                                 |
|:-------:|:--------------------------------:|:-----------------------------------------------------------:|
| **지성현** | 리드 프로그래머 | - 콘솔 레이아웃 설계<br>- 스크립트/키 매니저 구현<br>- 아스키코드 인트로 및 몬스터 애니메이션<br>- 플레이어 스탯 동기화 |
| **차정민** | 게임 디자이너 & 씬 매니저           | - 세계관, 게임 로직, 디자인 기획<br>- 배틀 씬(1F~8F), 상점 씬, 제단 씬 구현<br>- 맵 아이콘 및 텍스트 컬러 시스템<br>- 문서 정리 |
| **지승현** | 몬스터 & 아이템 엔지니어           | - 몬스터 클래스 구현<br>- 아이템 클래스 및 인벤토리 시스템 구현 |
| **김동근** | 플레이어 로직 & 배경 디자이너        | - 플레이어 클래스 구현<br>- 아스키코드 기반 배경 그림 디자인<br>- 메인 씬 문자 컬러 효과 |
 
- **개발 기간**
    -  
    -  2025.01.10 ~ 2025.01.16
    -  일정 관리 : `노션`, `슬랙`을 활용하여 일정과 커뮤니케이션 관리

- **개발 환경**
    -  
    - 개발 언어 및 도구
        - 개발 언어: C++
        - 컴파일러: Microsoft Visual C++ Compiler
        - IDE: Visual Studio 2022
        - 빌드 도구: MSBuild (Visual Studio 내장)
        - 운영 체제: Windows 11
     
- **빌드/실행 방법**
    -  
    - 프로젝트 다운로드
        - GitHub 또는 팀 프로젝트 저장소에서 `ProjectRainbowGuardia`폴더를 통째로 다운로드(또는 클론)합니다.
        - 다운로드(클론)된 폴더를 Visual Studio에서 열 수 있도록 준비합니다.
    - 빌드 도구/개발 환경 준비
        - Windows 11에서 Visual Studio 2022를 실행 후, `파일(File) > 열기(Open) > 폴더(Open Folder)...`를 클릭해 프로젝트 폴더를 엽니다.
            - 혹은 `.sln`(솔루션) 파일이 있다면, 해당 파일을 더블 클릭하여 솔루션을 직접 열어도 됩니다.
    - 빌드
        - Visual Studio 메뉴 상단에서 **빌드(Build)**를 누르고 **솔루션 빌드(Build Solution)**를 선택합니다.
        - 빌드 과정에서 오류가 없으면, 빌드가 성공적으로 완료됩니다.
    - 실행 및 게임 시작
        - 빌드 성공 후, Visual Studio에서 `Ctrl + F5(디버깅 없이 시작) 또는 디버그(Debug) > 디버깅 시작(Start Debugging)` 메뉴를 클릭하면 콘솔 창이 열립니다.
        - 실행 후 콘솔에 표시되는 메뉴를 따라 게임을 시작합니다.
        - 캐릭터 이름 설정 → 마을(안전지대) 진입 → 게임 진행(탑을 오를지 말지 선택) 등의 흐름으로 게임을 플레이할 수 있습니다. 
             
- **게임 진행 구조**
    -  
    - 마을(안전지대)
      - 플레이어가 **탑(컬러 던전)**에 오를지 말지를 선택하는 공간입니다.
        - 만약 탑(컬러 던전)에서 사망(Dead)하면 마을로 리셋됩니다.
          - 컬러 마블(색 구슬) 리셋 
      - 컬러 던전(사냥터)
        - 컬러 컨셉별로 구분된 던전이며, 각 색에 맞는 몬스터와 테마가 존재합니다.
        - 몬스터 난이도는 점진적으로 상승합니다.
        - 경험치와 골드를 획득할 수 있고, 던전을 클리어하면 해당 색깔의 마블을 얻을 수 있습니다.
        - 턴제로 게임이 진행되며, 공격/아이템 사용 등은 플레이어가 액션을 선택하는 방식입니다.
        - 7가지의 컬러 마블을 전부 모아야 **Final Scene(보스 씬)**에 접근 가능합니다.
      - 보스(레인보우 드래곤)
        - 7가지 컬러 마블을 모두 모은 후 진입할 수 있는 최종 보스 전투입니다.
        - 보스를 클리어하면 게임 엔딩 크레딧을 볼 수 있습니다.
- **프로젝트 구조**
    -  

            RAINBOW_GUARDIAN_PROJECT
             ┣ Sorce
             ┃ ┣ Main.cpp              // 메인 함수가 위치, 프로그램 시작점
             ┃ ┗ Game                  // 게임 관련 코드 저장 디렉토리
             ┃   ┣ Player.h            // 캐릭터 시스템 헤더
             ┃   ┣ Player.cpp          // 캐릭터 시스템 구현
             ┃   ┣ Scene1F.h           // 던전(미궁) 관련 헤더
             ┃   ┣ Scene1F.cpp         // 던전(미궁) 관련 구현
             ┃   ┣ ShopScene.h         // 상점 관련 헤더
             ┃   ┗ ShopScene.cpp       // 상점 관련 구현
             ┃   ┗ ...            
             ┣ Test
             ┃ ┣ Test.cpp    // 테스트 코드
             ┃ ┗ ...
             ┣ Resources
             ┃ ┗ ...                   // 추가 리소스 파일(데이터, 이미지, 사운드 등)
             ┗ CMakeLists.txt (또는 Makefile)

- **핵심 로직/클래스 설명**
    -  
    - Player 클래스 (`player.h` / `player.cpp`)
    - 주요 멤버 변수: name (이름), level (레벨), hp (체력) 등
    - 주요 기능:
        - 캐릭터 상태 저장/로드
        - 전투 시 공격, 방어, 스킬 사용 로직
        - 레벨 업 시 능력치 증가 기능
    - Scene 클래스 (`Scene0F.h` / `Scene0F.cpp` / `Scene1F.h` / `Scene1F.cpp` / `AltarScene.h` / `AltarScene.cpp` 등)
        - 주요 멤버 변수: currentFloor(현재 층), - 등
        - 주요 기능:
            - 층(floor) 이동 관리
            - 몬스터 생성/배치
            - 전투 종료 후 보상(경험치, 골드) 지급
    - Shop 클래스 (`shop.h` / `shop.cpp`)
        - 주요 멤버 변수:
            - inventory (상점에서 판매하는 아이템 목록)
        - 주요 기능:
            - 포션 구매 (일시적 능력 강화, 회복용)
            - 주문서, 장비 등 아이템 구매/판매(추가 기능 가능)
    - GameManager
        - 게임 전체 흐름을 제어하는 핵심 컨트롤러
        - 마을 → 던전 → 랜덤(제단 or 상점) 등 장면(Scene)을 전환하고, 각 장면에서의 상태를 관리
        - 유저 입력(메뉴 선택 등)을 받아서 로직을 호출

- **추가 구현 사항**
    -  
  1. 제단 씬 구현
        - 일정 골드를 소모하면 캐릭터(플레이어) 체력이 최대치로 회복되는 시스템을 추가했습니다.
  2. 배틀 씬 랜덤
        - 무작위로 색깔 방(던전)이 등장하도록 하여, 게임 플레이마다 다양한 색 던전을 경험하도록 했습니다.
  3. 컬러 마블 7종 수집 후 보스 방 오픈
        - 7가지 컬러 마블을 모두 모으면 최종 보스 씬(레인보우 드래곤)에 도전할 수 있습니다.
  4. 아스키(ASCII) 코드를 이용한 몬스터 애니메이션
        - 콘솔 환경에서 몬스터가 움직이는 듯한 효과를 내도록, 텍스트 기반의 간단한 애니메이션을 구현했습니다.
  5. 인트로 씬
        - 게임 시작 시 분위기를 살릴 수 있는 간단한 연출(제목, 간단한 그래픽, 음악)을 도입했습니다.
  6. 커서 시스템 구현
        - 콘솔 화면에서 메뉴 선택을 강조하기 위해 커서 제어(위치 이동)를 적용했습니다.
  7. **이모지와 컬러(글자색) 활용**
        - 단순한 텍스트만 있는 콘솔 게임을 넘어서, 이모지와 텍스트 색상을 다양하게 사용해 디자인적 재미 요소를 더했습니다!

- **주의사항**
    -  
    - 빌드 환경 이슈
        - Windows 환경에서 콘솔 인코딩(한글 깨짐) 문제가 생길 수 있습니다. Visual Studio를 사용할 때는 프로젝트 속성에서 유니코드 설정을 확인하세요.
    - 호환성
        - C++17 표준 라이브러리를 사용했으므로, 오래된 컴파일러는 호환이 되지 않을 수 있습니다.
        - 시스템 자원이 낮은 환경(예: 저사양 PC)에서는 프레임 드롭이 발생할 수 있지만, 콘솔 기반이라 큰 문제는 없습니다.
