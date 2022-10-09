# Pull Request

## Table of contents
- [`Pull Request`의 목적](#pull-request의-목적)
- [`Pull Request` 방법](#pull-request-방법)
- [`Contributor`의 `Pull Request` 방법](#contributor의-pull-request-방법)
- [`Pull Request` 시 발생하는 `Conflict` 해결법](#pull-request-시-발생하는-conflict-해결법)
- [`Pull Request` `Review`](#pull-request-review)
- [`Pull Request` `Review` 작성법](#pull-request-review-작성법)
- [`Pull Request`에 추가로 `Commit`하기](#pull-request에-추가로-commit하기)
- [`Pull Request` `Merge`](#pull-request-merge)
- [Reference](#reference)

## Pull Request의 목적

`PR`이라고 줄여서 부르기도 하는 `Pull Request`는 `Github`를 이용하는 여러 오픈소스 프로젝트에 기여하기 위해서 몰라서는 안 될 중요한 기능입니다.   

`Collaborator`분들은 직접 `Branch`에서 작업하고 `Merge`까지도 가능하지만,   
`Contributor`분들은 프로젝트 내의 그 어떤 `Branch`에도 `Write` 권한이 없습니다.   

익명의 사용자들에게 프로젝트를 마음껏 수정할 수 있도록 하면, 악의적인 행위를 하는 사용자도 있을 수 있으니까요.   
  
<br>
  
**`Pull Request`는 여러분의 `Branch`를 특정 `Branch`에 `Merge`해달라고 요청하는 것입니다.**

- **자신만이 이용하는 `Branch`가 아닌 경우에는, 직접 `Commit`하지 않고 `Pull Request` 하기를 권장합니다.**   
  
  - A `Branch`에 추가하고 싶은 내용이 있다면, B `Branch`를 만들어 작업한 후,   
  `Merge B into A`를 `Pull Request`하는 겁니다.
  
- **`Contributor`분들은 `Pull Request`를 통해야만 프로젝트의 코드나 리소스에 직접적인 기여를 할 수 있습니다.**

  - `Issue`와 `Discussion`을 통한 기여도 존재하지만, 직접 내용물을 작업하는 것은 아니죠.

## Pull Request 방법
  
<div align="center"><image src="https://user-images.githubusercontent.com/73771162/193556941-4a29c062-dd60-40f8-97ca-911d4e754e3e.PNG"></div>

- `Github` `Repository` 페이지에서 `Pull requests` 항목을 누르면 위와 같은 화면이 나타납니다.
- `Issue`와 비슷하게, 처리되지 않은 `Pull Request`는 `Open` 상태이고, 처리된 `Pull Request`는 `Closed` 상태입니다.
- 새로운 `Pull Request`를 만드려면 `New pull request` 버튼을 클릭합니다.
  
<div align="center"><image src="https://user-images.githubusercontent.com/73771162/193557116-f76e5382-a09c-41e0-ad34-e340ef8efb4f.PNG"></div>

- `New pull request` 버튼을 클릭하면 나타나는 화면입니다.
  
  - `base:`라고 되어있는 게 `Target Branch`, `compare:`라고 되어있는 게 `Source Branch`입니다.
  - 해당 `Pull Request`로 인한 `Conflict` 발생 여부를 확인할 수 있습니다.
  - 해당 `Pull Request`로 인해 반영되는 `Commit` 목록을 확인할 수 있습니다.
  
- `Target Branch`와 `Source Branch` 설정이 완료되었다면 `Create pull request` 버튼을 클릭합니다.

  
<div align="center"><image src="https://user-images.githubusercontent.com/73771162/193557156-20fc9015-1345-464b-b770-f855b2dcb322.PNG"></div>

  - `Create pull request` 버튼을 클릭하면 나타나는 화면입니다.
  
    - 간단한 제목과 내용 작성 후 최종적으로 `Pull Request`를 생성할 수 있습니다.
  
      - `Reviewer`는 해당 `Pull Request`를 검토하여, `Merge`할 것인지 말 것인지 결정합니다.
  
    - 해당 `Pull Request`를 검토할 `Reviewers`를 설정할 수 있습니다.
    - 해당 `Pull Request`를 담당하는 `Assignees`를 설정할 수 있습니다.

## Contributor의 Pull Request 방법

`Contributor` 분들은 다음의 과정을 따라야 합니다.
- 기여하고 싶은 `Remote Repository`를 `Fork`해 자신만의 `Remote Repository`를 만듭니다.
  
  - `Fork`된 `Remote Repository`는 여러분의 것이기 때문에 `Write`가 가능합니다!
  
- `Fork`된 `Remote Repository`를 여러분의 `Local Repository`로 `Clone`합니다.   
  (`Clone`은 `Remote Repository`를 `Local Repository`로 복사해오는 일이고,   
  `Fork`는 다른 사람의 `Remote Repository`를 가져와 내 `Remote Repository`를 만드는 일입니다.)
- 새로운 `Branch`를 만들어 여러분들이 하고 싶은 작업을 합니다.
- 작업을 `Commit`하고 `Push`하면 `Fork`된 `Remote Repository`가 업데이트 되었겠죠?
- `Fork`된 `Remote Repository`에서 여러분이 만든 `Branch`를 원본 `Remote Repository`에 `Pull Request` 할 수 있습니다!
  
[잘 설명이 된 링크가 있으니, 한번 보시기 바랍니다.](https://wayhome25.github.io/git/2017/07/08/git-first-pull-request-story/)

## Pull Request 시 발생하는 Conflict 해결법

<div align="center"><image src="https://user-images.githubusercontent.com/73771162/193803494-39829359-5f8c-4dcb-8fd9-2a97456f5eba.PNG"></div>
  
- `Conflict`가 발생할 경우 위와 같은 메시지가 나타납니다.
  
<div align="center"><image src="https://user-images.githubusercontent.com/73771162/193803518-334de234-0fbe-4695-a6f2-ebc04ba63be8.PNG"></div>
 
- `Conflict`가 해결되기 전까지 해당 `Pull Request`를 `Merge`할 수 없습니다.
- `Resolve Conflict` 버튼을 클릭합니다.
  
<div align="center"><image src="https://user-images.githubusercontent.com/73771162/193803531-4c4f5d3b-211e-45a5-bfcb-6164a5859dc5.PNG"></div>
  
- 위와 같은 화면이 나타납니다.
- [`Merge Branch`에서의 `Conflict`를 해결하는 요령](https://github.com/MyeongWoonJang/cpp-study/blob/main/docs/branch.md#%EC%B6%A9%EB%8F%8C-conflict)으로 `Conflict`를 해결합니다.
- `Conflict`를 해결하기 전까진, `Mark as resolved` 버튼이 활성화되지 않습니다.
  
<div align="center"><image src="https://user-images.githubusercontent.com/73771162/193803540-0807e26c-0704-4283-b6df-ba170e5917dc.PNG"></div>
  
- `Conflict`를 해결했다면 `Mark as resolved` 버튼을 클릭합니다.
  
<div align="center"><image src="https://user-images.githubusercontent.com/73771162/193803553-2367e626-84d8-455d-8e32-72fe874707df.PNG"></div>
  
- `Commit Merge` 버튼을 클릭합니다.
  
  - 해당 해결 내용을 `Pull Request`에 `Commit`으로서 추가합니다.
  
- `Pull Request`에 `Merge Commit`을 추가하는 것이지 `Pull Request`를 `Merge`하는 것이 아니므로,   
  이후 [`Pull Request`에 추가적인 `Commit`](#pull-request에-추가로-commit하기)을 할 수 있습니다.
  
  - 말이 참 헷갈리죠?   
  `Pull Request`가 `Conflict` 해결 `Commit` 추가로 인해 살짝 두꺼워진다고 생각하시면 됩니다.
  
<div align="center"><image src="https://user-images.githubusercontent.com/73771162/193803569-d25b6931-3e78-4873-a0e4-27ae1a884907.PNG"></div>
  
- `Merge`가 가능해졌습니다!
  
## Pull Request Review

- `Pull Request`는 `Review`를 거쳐 `Merge`됩니다.

  - `Reviewer`로 설정된 사람들이 해당 `Pull Request`를 `Review`해 다음 세 가지 결정 중 하나를 내립니다.
  
    - `Comment`
  
      - 별다른 효력은 없는, 그냥 댓글입니다.
      - 질문이나 간단한 소통을 하려 했을 것입니다.
      - 어쩌면 해당 `Pull Request`가 별로라서 그냥 `Close` 하겠다는 통보를 남길 수도 있습니다.
  
    - `Approve`
  
      - `Pull Request`를 승인합니다.
      - 해당 `Pull Request`가 만족스러웠을 것입니다.
  
    - `Request Changes`
  
      - `Pull Request`에 수정 사항을 요청합니다.
      - 해당 `Pull Request`의 어딘가에 아쉬운 부분이 있었나 봅니다.
  
  - 현재 프로젝트에서 `Reviewer`로 설정된 사람의 `Review` 없이도 `Merge`는 가능합니다.   
    그러나, 자제하는게 좋습니다.
  
## Pull Request Review 작성법
  
<div align="center"><image src="https://user-images.githubusercontent.com/73771162/194303453-84f5b975-95f3-4f9f-967c-9b59df6f565f.PNG"></div>
  
- 개별 `Pull Request` 화면에서 위의 `Add your review` 버튼이나, `Files changed` 항목을 클릭해 `Review`를 작성할 수 있습니다.
  
  - `Files changed` 항목 클릭을 이용한 `Review` 작성은 `Pull Request`가 `Closed`인 상태에서도 작성할 수 있고,   
  `Reviewer`가 아니어도 작성할 수 있습니다.
  
<div align="center"><image src="https://user-images.githubusercontent.com/73771162/194306607-6a84494a-493f-4ed5-9c47-335bbffa8aee.png"></div>
  
 - `Add your review` 버튼, 혹은 `Files changed` 항목을 클릭했을 때 나오는 화면입니다.
 - 왼쪽에 `추가`/`변경`/`삭제`된 파일 목록이 있고, 오른쪽에서 파일별 내역을 확인할 수 있습니다.
 - 다음의 과정을 통해 Review를 작성합니다.
  
   - 내역의 `Line number` 오른쪽에 마우스를 가져다대면 `+` 버튼이 활성화됩니다.
  
     - 어떠한 내용을 콕 집어서 `Review Comment`를 남기고 싶을 때가 있을 것입니다.
     - `+` 버튼을 클릭하고 아래로 드래그해, `Review Comment`를 남길 부분을 설정할 수 있습니다.
  
   - `Add single comment` 혹은, `Start a review` 버튼을 클릭해 `Review Comment`를 남길 수 있습니다.
  
     - `Add single comment`는 `Comment`를 빠르고 간편하게 남기기 위한 버튼입니다.
  
       - `Review`와는 독립적으로, 해당 `Comment`가 바로 `Conversation` 항목에 등록됩니다.
  
    - `Start a review` 버튼은 여러 `Review Comment`들을 묶어 최종적으로 `Comment`/`Approve`/`Request Changes` 하기 위한 버튼입니다.
  
       - `Start a review` 버튼으로 `Review Comment`를 하나 남기면, 다음 `Review Comment`를 작성할 때에는   
       `Add review comment` 버튼이 나타납니다.
       - 여러 `Review Comment`들을 `Add`합시다.
  
   - 내역을 `Review`한 파일들은 `Viewed` 항목을 체크합니다.

   <div align="center"><image src="https://user-images.githubusercontent.com/73771162/194310204-b1cc6ac8-70d8-4c42-aa43-9dfd64b80eb0.PNG"></div>

    - `Review`를 마치기 위해 `Review changes` 버튼을 클릭합니다.
      
      - 모든 파일들에 `Viewed` 체크했는지 확인합니다.
      - 간단한 요약과 함께, `Comment`/`Approve`/`Request Changes` 중 하나의 유형을 선택합니다.
      - `Submit review` 버튼을 클릭합니다.

<div align="center"><image src="https://user-images.githubusercontent.com/73771162/194311635-4646ad5d-19b0-4335-b8e9-842c9cbb3722.PNG"></div>
  
- `Conversation` 항목을 보면 `Review`가 등록되어 있습니다.
- `Resolve Conversation`을 통해 `Pull Request` 요청자가 `Review`를 확인하고 문제를 해결했음을 나타낼 수 있습니다.

  
## Pull Request에 추가로 Commit하기

- `Github Desktop`을 이용하여 `Pull Request`에 `Commit`을 추가할 수 있습니다.
  
  - `Pull Request`를 수정할 일이 있다면, 번거롭게 삭제했다가 다시 만들지 말고, `Commit`을 추가합시다.
  - `Reviewer`가 `Request Changes` 판정을 내렸다면, 해당 요청 사항을 반영한 `Commit` 후에 다시 `Review`를 요청합시다.
  
## Pull Request Merge
  
<div align="center"><image src="https://user-images.githubusercontent.com/73771162/193803569-d25b6931-3e78-4873-a0e4-27ae1a884907.PNG"></div>
  
- 개별 `Pull Request` 화면에서 `Merge pull request` 버튼을 클릭해 최종적으로 `Pull Request`를 `Merge`합니다.
  
<div align="center"><image src="https://user-images.githubusercontent.com/73771162/193803573-1fbe080c-ffad-4519-93b5-a6392a11fb07.PNG"></div>
  
- `Target Branch` 입장에서는, 해당 `Pull Request`의 `Merge`로 인해 `Commit`들이 추가되는 것이므로,   
  `Merge Commit Message`를 남겨주어야 합니다.
  
<div align="center"><image src="https://user-images.githubusercontent.com/73771162/193803585-0c6e9a5b-a71a-4937-b46e-b14cad725c9f.PNG"></div>
  
- `Source Branch`가 `main`/`master` `Branch`가 아니라면, 화면 아래에 `Delete Branch` 버튼이 활성화됩니다.
  
  - `Merge`로 인해 재역할을 다한 `Branch`를 간편하게 삭제할 수 있는 기능입니다.

## Reference
  
[\[티스토리 zel0rd\] git conflict(충돌) 해결하기](https://zel0rd.tistory.com/126)   
[\[초보몽키의 개발공부로그\] git 초보를 위한 풀리퀘스트(pull request) 방법](https://wayhome25.github.io/git/2017/07/08/git-first-pull-request-story/)   
[\[티스토리 DevScroll\] \[GIT\] ⚡️ 깃헙 Pull Request 보내는 방법 - 알기 쉽게 정리](https://inpa.tistory.com/entry/GIT-%E2%9A%A1%EF%B8%8F-%EA%B9%83%ED%97%99-PRPull-Request-%EB%B3%B4%EB%82%B4%EB%8A%94-%EB%B0%A9%EB%B2%95-folk-issue)   
[\[티스토리 PlanB의 백엔드 엔지니어링\] \[Git\] Pull request에서 발생하는 충돌 해결하기](https://planbs.tistory.com/190)

