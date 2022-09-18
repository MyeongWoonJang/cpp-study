# Jira 사용법

`Jira`는 프로젝트 관리 툴로, 10명 이하의 팀에게 무료로 클라우드 공간을 제공합니다.   
`Jira`는 애자일 방법론을 따라 개발하는 데 효과적인 툴입니다.   
우리는 `Jira`에서 제공하는 방식 중 `scrum` 방식을 이용해 개발합니다.

## 먼저 읽기
- [애자일 방법론](https://github.com/MyeongWoonJang/cpp-study/blob/main/readme/agile_methodology.md)   
- [스크럼](https://github.com/MyeongWoonJang/cpp-study/blob/main/readme/scrum.md)   

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

<div align="center"><image src="https://user-images.githubusercontent.com/73771162/190897764-92e6f746-e82d-4630-9dfb-b079345f649d.PNG"></div>

  
- `이슈`를 클릭하면 세부 정보 창을 볼 수 있습니다.

<div align="center"><image width="600" height="580" src="https://user-images.githubusercontent.com/73771162/190896711-66ecc4e1-c51c-4187-aa12-27019d96017a.PNG"></div>

- `하위 이슈`들의 상태를 변경할 수 있습니다.
  - 각 `하위 이슈`들을 완료하십시오.
- 진척률을 확인할 수 있습니다.
  
## Issue와 Github Branch 연동

- 추후 작성 예정
  
# 스프린트 계획 단계

<div align="center"><image width="1000" height="360" src="https://user-images.githubusercontent.com/73771162/190898901-d366e37a-c7cb-4d60-8d15-6bdcd6c52541.PNG"></div>
  
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
  
- 첫 번째 방법은, 위에 있는 `만들기` 버튼을 클릭하는 겁니다.
  
<div align="center"><image width="600" height="650" src="https://user-images.githubusercontent.com/73771162/190898951-eba2fdc7-0199-4712-9f57-2be6b1fab92b.PNG"></div>

  - `이슈` 생성 팝업 창이 뜹니다.
  - 이 팝업 창엔 `에픽 추가`나 `하위 이슈` 추가 버튼이 없기 때문에 생성 후 추가적으로 설정해야 합니다.
  
- 두 번째 방법은, 아래의 `+` 버튼을 클릭해서 간단하게 이슈를 만들고, 이슈의 세부 정보를 수정하는 겁니다.
  
<div align="center"><image width="350" height="620" src="https://user-images.githubusercontent.com/73771162/190899210-e037f87f-64f9-4f65-b2f9-f3aa6ed8897d.PNG"></div>
  
  - `+` 버튼을 통해 간단하게 `이슈` 유형, 제목, 담당자를 설정할 수 있습니다.
  - 그 외 나머지 정보는 세부 정보 창에서 추가합니다.
  
    - `에픽 추가`는 `이슈`가 어떤 `에픽`과 연관되는지 설정합니다.   
      (`에픽`은 장기 목표에 해당하는 `이슈`로, 여러 `스프린트`에 걸쳐 달성되는 목표입니다.)
    - `이슈`의 진척률은 달성된 `하위 이슈`들의 비율이므로, 여러 개의 `하위 이슈`를 두십시오.

## 스프린트 생성 방법

- `스프린트 만들기` 버튼을 클릭하면 새 스프린트가 만들어집니다.
- 만들어진 `스프린트`에서 `스프린트 편집` 버튼을 누릅니다.

![캡처_2022_09_18_20_30_42_675](https://user-images.githubusercontent.com/73771162/190900024-7b2d613a-ae01-44a2-9b62-bcb284646920.png)

- 그러면 다음과 같은 팝업 창이 뜹니다.
  
![스프린트](https://user-images.githubusercontent.com/73771162/190900027-bb96579f-096f-4066-a552-25494eac802d.PNG)

- `스프린트`의 제목과 기한, 목표를 설정하고 편집을 완료합니다.

## Reference
[\[티스토리 코딩수련장\] Jira 지라 사용법](https://11001.tistory.com/120) \(snowman95\)   
[\[앵그리 비버's IT를 부탁해\] JIRA 처음 사용하기](https://hanminwoo.com/60)   
[\[Atlassian JIRA\] 지라 클라우드(JIRA Cloud) 와 깃허브(github) 연동하기](https://www.lesstif.com/jira/jira-cloud-github-125305615.html)
