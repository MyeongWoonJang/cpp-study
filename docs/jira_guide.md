# Jira 사용법

`Jira`는 프로젝트 관리 툴로, 10명 이하의 팀에게 무료로 클라우드 공간을 제공합니다.   
`Jira`는 애자일 방법론을 따라 개발하는 데 효과적인 툴입니다.   
우리는 `Jira`에서 제공하는 방식 중 `scrum` 방식을 이용해 개발합니다.

## 먼저 읽기
- [애자일 방법론](https://github.com/MyeongWoonJang/cpp-study/blob/main/docs/agile_methodology.md)   
- [스크럼](https://github.com/MyeongWoonJang/cpp-study/blob/main/docs/scrum.md)   

## Table of contents
- 스프린트 단계

  - [Issue](#issue)
  - [Issue와 Github Branch 연동](#issue와-github-branch-연동)

- 스프린트 계획 단계

  - [스프린트 계획 절차](#스프린트-계획-절차)
  - [이슈 생성 방법](#이슈-생성-방법)
  - [스프린트 생성 방법](#스프린트-생성-방법)

- [Reference](#reference)

# 스프린트 단계

## Issue
- `Jira`의 `이슈(Issue)`는 `작업 카드(Task Card)`입니다.   
(`Jira`의 `이슈(Issue)`는 `Github`의 `이슈(Issue)`와 같은 개념이 아닙니다.)
- `이슈`는 네 가지 상태를 가집니다.
  - `할 일(TODO)`
  - `진행 중(IN PROGRESS)`
  - `검토 및 피드백(REVIEW & FEEDBACK)`
  - `완료(DONE)`

- **`보드(Board)`의 `이슈`들을 오른쪽으로 한 칸씩 옮겨, 최종적으로 모든 `이슈`를 완료하는 것이 우리의 목표입니다.**

  - `우선순위(Priority)`가 높은 `이슈`부터 처리합시다.

<div align="center"><image src="https://user-images.githubusercontent.com/73771162/192572158-36aa89d9-3c5a-4c61-ba0d-b1a1f2595095.PNG"></div>

   
- `이슈`를 클릭하면 세부 정보 창을 볼 수 있습니다.

<div align="center"><image width="770" height="580" src="https://user-images.githubusercontent.com/73771162/192571016-1ec8c78c-cc0c-41a7-9f71-8798884459d5.PNG"></div>

- **`하위 이슈`들의 상태를 변경할 수 있습니다.**
  - **각 `하위 이슈`들을 완료하십시오.**
- 진척률을 확인할 수 있습니다.
   
- `제목`과 `내용`을 변경할 수 있지만, 팀 업무에 혼동을 줄 수 있으니 신중해야 합니다.
- `이슈`의 `우선 순위`를 변경할 수 있지만, 팀 업무에 혼동을 줄 수 있으니 신중해야 합니다.
  
## Issue와 Github Branch 연동

- 추후 작성 예정
  
# 스프린트 계획 단계
  
## 스프린트 계획 절차

<div align="center"><image width="1000" height="452" src="https://user-images.githubusercontent.com/73771162/192577548-0f47344e-3ad1-4914-9889-d571e62f9649.png"></div>
  
1. `백로그`를 갱신합니다.
  
    - 새롭게 요구되는 `이슈`를 작성합니다.
    - 요구 사항이 바뀐 `이슈`를 수정합니다.
  
2. `스프린트`를 목표와 기한을 설정하여 생성합니다.
  
    - 지금 당장, 동시에 진행했을 때 효용이 높은 `이슈`들이 `스프린트` 생성의 힌트입니다.
    - `스프린트`가 끝나면 눈에 보이는 결과물이 있어야 합니다.
    - `스프린트` 주기(1~4주)를 감안하여 목표를 설정합니다.
  
3. 생성한 스프린트의 목표에 부합하는 `백로그`의 `이슈`들을 `스프린트`로 올립니다.

    - `프로덕트 백로그(Product Backlog)`를 `스프린트 백로그(Sprint Backlog)`로 옮기는 과정입니다.

## 이슈 생성 방법
  
- 위에 있는 `만들기` 버튼이나, 아래의 `이슈 만들기` 버튼을 클릭합니다.

<div align="center"><image width="560" height="649" src="https://user-images.githubusercontent.com/73771162/192579944-fbd585a9-1329-484b-a443-f67079f4571f.PNG"></div>

  - `이슈` 생성 팝업 창이 뜹니다.
  - 이 팝업 창엔 `에픽 추가`나 `하위 이슈` 추가 버튼이 없기 때문에 생성 후 추가적으로 설정해야 합니다.

    - 만들어진 `이슈`를 다시 클릭합니다.

<div align="center"><image width="350" height="558" src="https://user-images.githubusercontent.com/73771162/192581950-f7268aa3-6f45-4ac1-871f-04f5a6bd20e9.PNG"></div>

  - `세부 정보` 탭이 활성화됩니다.
  - `에픽 추가`는 `이슈`가 어떤 `에픽`과 연관되는지 설정합니다.   
    (`에픽`은 장기 목표에 해당하는 `이슈`로, 여러 `스프린트`에 걸쳐 달성되는 목표입니다.)
  
    - `스프린트`는 팀 작업의 진행 단위일 뿐이므로,   
      한 `스프린트`에 여러 목표가 있을 수도 있고 어떤 목표는 여러 `스프린트`를 거쳐야 완수되기도 합니다.   
      이는 `스프린트`와 구분되어, `에픽`이라는 개념이 됩니다.
  
  - `하위 이슈`는 하나의 `이슈`를 완수하는데 필요한 과정들입니다.
  
    - `이슈`의 진척률은 달성된 `하위 이슈`들의 비율이므로, 여러 개의 `하위 이슈`를 두십시오.

## 스프린트 생성 방법

- `스프린트 만들기` 버튼을 클릭하면 새 스프린트가 만들어집니다.
- 만들어진 `스프린트`에서 `스프린트 편집` 버튼을 누릅니다.

<div align="center"><image src="https://user-images.githubusercontent.com/73771162/190900024-7b2d613a-ae01-44a2-9b62-bcb284646920.png"></div>

- 그러면 다음과 같은 팝업 창이 뜹니다.
  
<div align="center"><image src="https://user-images.githubusercontent.com/73771162/190900027-bb96579f-096f-4066-a552-25494eac802d.PNG"></div>

- `스프린트`의 제목과 기한, 목표를 설정하고 편집을 완료합니다.

## Reference
[\[티스토리 코딩수련장\] Jira 지라 사용법](https://11001.tistory.com/120) \(snowman95\)   
[\[앵그리 비버's IT를 부탁해\] JIRA 처음 사용하기](https://hanminwoo.com/60)   
[\[Atlassian JIRA\] 지라 클라우드(JIRA Cloud) 와 깃허브(github) 연동하기](https://www.lesstif.com/jira/jira-cloud-github-125305615.html)
