# Jira Issue를 Git과 연동하기
`Jira` `Issue`에 연관된 `Git` `Branch`와 `Git` `Commit`을 표시할 수 있습니다.   

- `Jira` `Issue`가 `Git` `Commit`와 유기적으로 연동되어 업무 진척이 훨씬 잘 보일 것입니다.

  - `Jira`의 `Issue`는 해야 할 일들이 알기 쉽게 요약되어있죠.
  - `Git`의 `Commit`은 실제적이고, 구체적인 우리의 작업들입니다.
  - `Github`에서 `Commit History`를 보아도 일련의 `Commit`들이 어떤 목적인지 보이지 않습니다.
  - 해야 할 일이 요약된 `Issue`별로 그 실제 처리 작업인 `Commit`이 분류되어 보인다면,업무 진척이 한 눈에 들어오겠죠.

## Table of contents

- [Jira Issue를 Git과 연동하기](#jira-issue를-git과-연동하기)
  - [Table of contents](#table-of-contents)
  - [Issue Key](#issue-key)
  - [Jira Issue에 연관된 Git Branch 표시하기](#jira-issue에-연관된-git-branch-표시하기)
  - [Jira Issue에 연관된 Git Commit 표시하기](#jira-issue에-연관된-git-commit-표시하기)
  - [Reference](#reference)

## Issue Key

- `Jira`의 `Issue`들은 모두 독립적인 `Issue Key`라는 것을 갖고 있습니다.

  <div align="center"><image width="900" height="410" src="https://user-images.githubusercontent.com/73771162/194705954-e522d207-88ed-475e-be92-1446ad053c52.PNG"></image></div>

  - `Board`의 `Issue` `Card` 왼쪽 아래에 `Issue Key`가 표시되어 있습니다.

  <div align="center"><image width="580" height="497" src="https://user-images.githubusercontent.com/73771162/194706052-201b132e-3d44-4d60-9740-3094d616b061.PNG"></image></div>  

  - `Issue`를 클릭하면 나오는 세부 정보 창의 위쪽에 `Issue Key`가 표시되어 있습니다.

## Jira Issue에 연관된 Git Branch 표시하기

- `Git` `Branch`의 이름에 `Jira` `Issue Key`가 포함되면, 해당 `Git` `Branch`와 해당 `Jira` `Issue`가 연동됩니다.

<div align="center"><image width="700" height="485" src="https://user-images.githubusercontent.com/73771162/194706247-bd6f4e85-3cb6-4ad7-93d0-44d840ba83c7.png"></div>
<div align="center"><image width="800" height="651" src="https://user-images.githubusercontent.com/73771162/194706248-3024f668-5b32-4d87-99f1-2ce0bf750261.png"></image></div>
<div align="center">source: Atlassian JIRA</div>

  - 이름만 바꾸면 연동이 된다니, 쉽죠?
  - 예시 사진의 `Issue Key`는 `BUG-8`이니, 다음과 같은 이름들이 가능할 겁니다.
    
    - `BUG-8`
    - `BUG-8-1234`
    - `Documentation-BUG-8`
    - `test-BUG-8`

- 한 `branch`를 여러 개의 `Jira` `Issue`와 연동할 수도 있습니다.
  
  - 연동하려는 `Jira` `Issue`의 `Issue Key`만 이름에 들어가 있으면 그 개수는 상관이 없습니다.

  <div align="center"><image src="https://user-images.githubusercontent.com/73771162/197695049-7c07e443-a43f-4deb-8b8d-0c3ceb40eedc.PNG"></div>
  <div align="center"><image width="800" height="175" src="https://user-images.githubusercontent.com/73771162/197695899-6193ba13-472d-403c-8526-8ac25f08a33f.PNG"></div>
  <div align="center"><image width="800" height="179" src="https://user-images.githubusercontent.com/73771162/197695908-a9a3c613-4173-4310-aac2-5738d9987a4b.PNG"></div>

  - 2022-10-25 기준 cpp-study `Repository`에서 여러 개의 `Jira` `Issue`와 연동된 `branch`들을 확인할 수 있습니다.

## Jira Issue에 연관된 Git Commit 표시하기

<div align="center"><image width="700" height="554" src="https://user-images.githubusercontent.com/73771162/194706752-f71ef5b8-630e-47ee-aa39-fa41ae56df7b.png"></image></div>
<div align="center"><image width="700" height="453" src="https://user-images.githubusercontent.com/73771162/194706746-12809fa2-a7b4-4fff-9d5c-09151ccff40c.png"></image></div>
<div align="center">source: Atlassian JIRA</div>

- `Git` `Commit Message`에 `Jira` `Issue Key`가 포함되면, 해당 `Git` `Commit`과 해당 `Jira` `Issue`가 연동됩니다.

  - 예시 사진처럼, `Issue Key`를 포함해서 여러분이 적고 싶은 `Commit Message`를 작성하시면 됩니다.
  - 여러 개의 `Issue Key`를 포함하면, 여러 개의 `Jira` `Issue`와 연동됩니다.
  - `Commit Message`의 `extended description`에 `Issue Key`를 적어도 문제 없이 반영됩니다.

  <div align="center"><image src="https://user-images.githubusercontent.com/73771162/197697166-e2a87f93-cc1b-4894-9982-9fa34008615e.PNG"></image></div>
  <div align="center"><image width="800" height="314" src="https://user-images.githubusercontent.com/73771162/197697169-747be0e8-323a-4118-b18b-7372c4f7af98.PNG"></image></div>

## Reference

[\[Atlassian JIRA\] 지라 클라우드(JIRA Cloud) 와 깃허브(github) 연동하기](https://www.lesstif.com/jira/jira-cloud-github-125305615.html)
