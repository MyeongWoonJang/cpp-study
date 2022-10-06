# Branch

<div align="center"><image width="800" height="574" src="https://user-images.githubusercontent.com/73771162/193435758-a3541681-0073-4917-a53e-e449b84d0269.png"></div>

<div align="center">
  
source: [Git Notes for Professionals](https://books.goalkicker.com/GitBook/)
  
</div>
  
<br>

`Branch(분기)`는 `Git`의 강력한 기능 중 하나입니다.   
협업 과정에서 없어서는 안 될 요소이며, `Branch`가 없다면 굉장히 비효율적인 작업 과정을 거쳐야 할 것입니다.   

`Branch`가 무엇인지, 왜 필요한지, 어떤 기능을 하는지 이 글을 통해 소개하도록 하겠습니다.

## Table of contents
- [Branch란](#branch란)
- Branch의 필요성
  
  - [작업들의 독립성](#작업들의-독립성)
  - [독립적인 작업들을 동시에 진행하기](#독립적인-작업들을-동시에-진행하기)
  
- Branch 기능
  
  - [분기 생성 (Create Branch)](#분기-생성-create-branch)
  - [분기 전환 (Checkout Branch)](#분기-전환-checkout-branch)
  - [분기 합병 (Merge Branch)](#분기-합병-merge-branch)
  
    - [충돌 (Conflict)](#충돌-conflict)

  - [분기 삭제 (Delete Branch)](#분기-삭제-delete-branch)
  
- Branch의 추가적인 활용
  
  - [Pull Request](#pull-request)
  - [프로젝트에 여러 작업 흐름을 두기](#프로젝트에-여러-작업-흐름을-두기)
  
- Reference(#reference)
  
## Branch란

`Branch`는 독립적인 작업 공간입니다.   
여러 사람이 작업을 분배해 각자의 `Branch`에서 타인에게 방해받지 않고 작업하게 됩니다.   
  
온라인 작업 공간이기 때문에   
만드는 것도 0 코스트, 삭제하는 것도 0 코스트라는 강력한 장점이 있습니다.
  
무한정으로 만들었다가, 순식간에 모두 없애버릴 수도 있죠.
  
## Branch의 필요성

### 작업들의 독립성

프로젝트의 많은 작업들은 서로 독립적입니다.   

가령 `로봇`을 만드는 프로젝트가 있다고 생각해봅시다.    
하나의 큰 작업을 독립적인 작은 작업들로 분리할 수 있습니다.

- `로봇` 만들기

  - `팔` 만들기
  
    - `손` 만들기
    
      - `손가락` 만들기
      - `손바닥` 만들기
      - `손목` 만들기
      
    - `팔꿈치` 만들기
    - `팔 몸통` 만들기
    
      - `윗팔` 만들기
      - `아랫팔` 만들기
      
  - `다리` 만들기
  - `몸통` 만들기
  - `머리` 만들기

`다리`와 `몸통`, `머리`의 하위 작업은 생략했습니다.

`로봇` 만들기 프로젝트는 결국 `손가락` 장인과 `손바닥` 장인, `손목` 장인이 자신의 결과물들을 합쳐 `손`을 만드는 일들의 반복입니다.   
`손가락`과 `손바닥`, `손목`은 완전히 따로따로 만들 수 있는 것들이죠.   
독립적인 작업이라는 뜻입니다.   

`팔`과 `다리`는 두 말 할 것 없습니다.

___

### 독립적인 작업들을 동시에 진행하기

프로젝트의 많은 작업들이 서로 독립적이라는 게 왜 중요할까요?   
그것은, **동시에 진행할 수 있기 때문입니다.**

10명이서 협업하는데, 1명의 작업이 끝나야만 또 다른 1명의 작업이 시작될 수 있다면 협업하는 의미가 있을까요?   
멀티코어 cpu와 멀티스레드 프로그램처럼, 팀은 멀티 작업을 해야 합니다.   

앞선 `로봇` 만들기 프로젝트를 살펴보면, `손가락`과 `손바닥`, `손목`은 독립적인 부품이니 동시에 만들 수 있죠.   
`손가락` 작업이 끝나길 기다리고, `손바닥` 작업이 끝나길 기다리고, `손목` 작업이 끝나길 기다릴 필요 없이     
다 동시에 진행한 뒤 합쳐서 `손`이란 부품으로 조립하면 됩니다.

`Branch`가 이것을 가능하게 합니다.   
독립적인 작업 공간을 만들어서 병렬적으로 작업하고, 나중에 합칠 수 있는겁니다.
- `Create Branch(분기 생성)` : 독립적인 작업 공간, `Branch`를 만드는 일입니다.
- `Merge Branch(분기 합병)` : 서로 다른 `Branch`를 합치는 일입니다.

## Branch 기능

### 분기 생성 (Create Branch)
  
<div align="center"><image src="https://user-images.githubusercontent.com/73771162/193435981-a7c0d3f6-443c-44cb-b2d5-02ad27054451.PNG"></div>

- 특정 `Branch`에서 새로운 `Branch`를 파생시킬 수 있습니다.
- 파생의 기반이 되는 `Branch`를 `Base Branch`라고 합니다.
  
  - 새로운 `Branch`는 `Base Branch`의 `Snapshot`을 갖습니다.
  - 새로운 `Branch`와 `Base Branch`는 독립적인 작업 흐름을 갖게 됩니다.

<br>

>윈도우에서 폴더를 복사한다고 생각해봅시다.   
>복사를 위해선 원본 폴더가 있어야겠죠.   
><div align="center"><image src="https://user-images.githubusercontent.com/73771162/193512259-e2efa865-3d88-42b6-b72c-0c8f94c5f877.PNG"></div>
><div align="center"><image src="https://user-images.githubusercontent.com/73771162/193512374-64272ca0-8d44-4e4e-bb84-c3420b630a77.PNG"></div>
>복사, 붙여넣기를 하고 나면 사본 폴더가 생성됩니다.<br>
>붙여넣기를 한 시점의 원본 폴더와 사본 폴더의 내용물은 동등합니다.    
><div align="center"><image src="https://user-images.githubusercontent.com/73771162/193512430-aa2f9231-977b-4a74-96c1-a9ee318110dd.PNG"></div>
>하지만, 그 뒤로 사본 폴더에서 어떤 파일을 수정한다고 하면?<br>
>원본 폴더와 사본 폴더는 독립적이기 때문에, 원본 폴더의 파일들은 아무런 변함이 없습니다.
><div align="center"><image src="https://user-images.githubusercontent.com/73771162/193512629-4917322a-155e-424d-86f2-7083f7b3a9fc.PNG"></div>
><div align="center"><image src="https://user-images.githubusercontent.com/73771162/193512374-64272ca0-8d44-4e4e-bb84-c3420b630a77.PNG"></div>


  
___
### 분기 전환 (Checkout Branch)

  
<div align="center"><image src="https://user-images.githubusercontent.com/73771162/193436467-d358df8a-e028-48ab-8c3f-ff892647721f.PNG"></div>

- 우리는 어느 한 `Branch`를 선택해서 작업합니다.
  
  - `main`, `master`는 `Git` 프로젝트 생성 시 기본으로 만들어지는 최초의 `Branch`입니다.
  
- `Git`에는 각 `Branch`들의 마지막 `Commit`을 가리키는 `HEAD`라는 포인터가 있습니다.
  
  - `Branch`를 전환한다 함은, `Git`이 보고 있는 `HEAD`를 다른 `HEAD`로 전환하겠다는 뜻입니다.
  
    - 다른 `HEAD`의 `Commit`은 다른 `History`를 갖고 있습니다.   
    따라서 여러분의 `Local Repository`는 다른 `History`의 내용물들로 바뀔 것입니다.
    - `HEAD`를 갱신하지 않고서(=작업 내용을 `Commit`하지 않고서) `Branch`를 전환하면, `Commit`들이 날아가겠죠?   
    따라서 `Branch`를 전환하기 전, 반드시 현재 `Branch`의 작업들을 `Commit`해야 합니다.


___

### 분기 합병 (Merge Branch)

<div align="center"><image src="https://user-images.githubusercontent.com/73771162/193436456-8ec49b97-f01f-448b-92ff-f36b76d97a17.PNG"></div>


- `Merge`는 합병이라는 뜻입니다.   
  서로 다른 두 `Branch`를 하나의 `Branch`로 합칩니다.
  
  - 동등하게 합친다기보다, 한 `Branch`에 다른 `Branch`를 덮어씌운다고 생각하시면 되겠습니다.
  - 한 `Branch`의 `Commit`들을 다른 `Branch`에 적용합니다.
  
    - `Merge A into B`라고 했을 때, A를 `Source Branch`, B를 `Target Branch`라고 합니다.   
    A의 `Commit`들을 B에 복사하는 것이죠.
  
    - `Merge`가 이루어졌다고 해서 `Source Branch`나 `Target Branch`가 사라지고 새로운 `Branch`가 생성되지는 않습니다.   
    `Target Branch`의 내용이 조금 바뀌었을 뿐이죠.


#### 충돌 (Conflict)

- `Source Branch`에 `A`, `B`, `C`라는 파일이 있고 다른 `Target Branch`에 `D`, `E`라는 파일이 있다면   
`Merge`된 `Target Branch`에는 `A`, `B`, `C`, `D`, `E`라는 파일이 있습니다.
 
  - 중요한 경우는 한 `Source Branch`에도 `A`라는 파일이 있고, 다른 `Target Branch`에도 `A`라는 파일이 있는 경우입니다.   
  이 상황을 `Conflict`가 발생했다고 합니다.  
  
    - `Git`은 훌륭하게도, `Merge` 실행 시 `Target Branch`의 `A` 파일에 차이점을 분석해서 요약합니다.    
    무엇의 차이점을요?    
    `Merge` 되기 전 서로 달랐던 두 `A` 파일의 차이점을요.   
    - 여러분은 그 요약을 보고 차이점들을 수동으로 합친 다음 `Git`이 생성한 요약을 지워주시면 됩니다. 

>다음은 `Conflict`의 예시입니다.
><div align="center"><image src="https://user-images.githubusercontent.com/73771162/193516489-76624a67-3ce0-4485-b4c3-0c1632cad689.PNG"></div>
>
>`<<<<<<< HEAD` 다음에 있는 내용은 `HEAD`가 가리키는 `Target Branch`에 있던 파일의 내용입니다.   
>`>>>>>>>merge-test` 다음에 있는 내용은 `merge-test`라는 `Source Branch`에 있던 파일의 내용입니다.   
>
>두 `Branch` 모두 `a.txt`라는 파일을 가지고 있었는데, 그 내용이 달라 `Conflict`가 발생했네요.
>
>`Git`이 둘의 차이점을 요약해줬으니, 우리가 적절하게 수정해서 `Merge`된 파일 내용을 만들어야겠네요.
><div align="center"><image src="https://user-images.githubusercontent.com/73771162/193517499-f95f00a1-4303-4303-9193-ede85c017954.PNG"></div>
>
>위와 같이 수정했습니다!
>이제 `Merge` 시 `Conflict`와 그 해결 방법에 대해 감이 오시나요?
  
___
  
### 분기 삭제 (Delete Branch)
  
- `Branch`를 생성하기만 하면 프로젝트가 갈수록 혼잡해지겠죠.
- 제 역할을 다 한 `Branch`는 삭제해야 합니다.
  
  - `Merge`는 두 `Branch`를 한 `Branch`로 합치는 게 아닙니다.   
  `Merge` 후에도 여전히 두 `Branch`가 남아있죠.
  - `Merge`에 쓰인 `Source Branch`가 삭제할 `Branch`의 유력 후보입니다.
  
___

## Branch의 추가적인 활용

### Pull Request

[Pull Request](https://github.com/MyeongWoonJang/cpp-study/blob/main/readme/pull_request.md) (제가 작성한, Pull Request를 설명하는 글입니다.)
  
- 다른 사람의 허락을 얻고 `Merge`하는 것이 `Pull Request`입니다.
- 프로젝트의 내용물을 직접 수정할 수 없는 `Contributor`분들이 기여하는 방법이기도 합니다.
  
  - 타인의 `Repository`를 자신의 `Repository`로 `Fork`해 자신만의 `Branch`를 만들어 작업한 후,   
    그 `Branch`를 `Pull Request` 하죠.
  
___

### 프로젝트에 여러 작업 흐름을 두기

[\[우아한형제들 기술블로그\] 우린 Git-flow를 사용하고 있어요](https://techblog.woowahan.com/2553/)   
[\[유튜브 코딩애플\] (알아두면 개발팀장가능) GitFlow vs Trunk-based 협업방식](https://www.youtube.com/watch?v=EV3FZ3cWBp8)   
[\[화해 블로그\] 브랜치 전략 수립을 위한 전문가의 조언들](http://blog.hwahae.co.kr/all/tech/tech-tech/9507/)   

여러 개의 `Branch`를 두어
- 실제 프로젝트를 운영중인 `Branch`
- 출시 및 테스트용 `Branch`
- 개발용 `Branch`
- 핫픽스용 `Branch`
등으로 활용할 수 있습니다.
  
보다 체계적인 관리를 통해 `Issue`들에 효과적으로 대응할 수 있게 됩니다.
  
## Reference

[Git Notes for Professionals](https://books.goalkicker.com/GitBook/)   
[\[git-scm\] 3.1 Git 브랜치 - 브랜치란 무엇인가](https://git-scm.com/book/ko/v2/Git-%EB%B8%8C%EB%9E%9C%EC%B9%98-%EB%B8%8C%EB%9E%9C%EC%B9%98%EB%9E%80-%EB%AC%B4%EC%97%87%EC%9D%B8%EA%B0%80)   
[\[화해 블로그\] 브랜치 전략 수립을 위한 전문가의 조언들](http://blog.hwahae.co.kr/all/tech/tech-tech/9507/)   
[\[Github Blog\] Commits are snapshots, not diffs](https://github.blog/2020-12-17-commits-are-snapshots-not-diffs/)   
[\[티스토리 lks의 코딩일기\] \[git\] git snapshot](https://coding-lks.tistory.com/162)   
[\[sae1013.log\] git HEAD 란?](https://velog.io/@sae1013/git-HEAD-%EB%9E%80)   
[\[티스토리 zel0rd\] git conflict(충돌) 해결하기](https://zel0rd.tistory.com/126)
[\[온라인 코딩스쿨 코드잇\] Git에서 conflict(충돌) 해결하기](https://blog.naver.com/PostView.naver?blogId=codeitofficial&logNo=221938658754&redirect=Dlog&widgetTypeCall=true&directAccess=false)   
[\[누구나 쉽게 이해할 수 있는 Git 입문\] 6. 병합할 때 발생하는 충돌 해결하기](https://backlog.com/git-tutorial/kr/stepup/stepup2_7.html)   
[\[초보몽키의 개발공부로그\] git 초보를 위한 풀리퀘스트(pull request) 방법](https://wayhome25.github.io/git/2017/07/08/git-first-pull-request-story/)   
[\[티스토리 DevScroll\] \[GIT\] ⚡️ 깃헙 Pull Request 보내는 방법 - 알기 쉽게 정리](https://inpa.tistory.com/entry/GIT-%E2%9A%A1%EF%B8%8F-%EA%B9%83%ED%97%99-PRPull-Request-%EB%B3%B4%EB%82%B4%EB%8A%94-%EB%B0%A9%EB%B2%95-folk-issue)   
[\[우아한형제들 기술블로그\] 우린 Git-flow를 사용하고 있어요](https://techblog.woowahan.com/2553/)   
[\[유튜브 코딩애플\] (알아두면 개발팀장가능) GitFlow vs Trunk-based 협업방식](https://www.youtube.com/watch?v=EV3FZ3cWBp8)   
