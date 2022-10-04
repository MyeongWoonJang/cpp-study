# Pull Request

## Table of contents
- [Pull Request의 목적](#pull-request의-목적)
- [Pull Request 방법](#pull-request-방법)
- [Contributor의 Pull Request 방법](#contributor의-pull-request-방법)
- [Pull Request 시 발생하는 Conflict 해결법](#pull-request-시-발생하는-conflict-해결법)
- [Pull Request Review](#pull-request-review)
- [Pull Request Merge](#pull-request-merge)

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

## Pull Request Review

## Pull Request Merge
  
  ![conflict 발생 메시지](https://user-images.githubusercontent.com/73771162/193803494-39829359-5f8c-4dcb-8fd9-2a97456f5eba.PNG)

  ![Resolve conflict](https://user-images.githubusercontent.com/73771162/193803518-334de234-0fbe-4695-a6f2-ebc04ba63be8.PNG)

  ![conflict 해결 화면](https://user-images.githubusercontent.com/73771162/193803531-4c4f5d3b-211e-45a5-bfcb-6164a5859dc5.PNG)

  ![conflict 해결 화면2](https://user-images.githubusercontent.com/73771162/193803540-0807e26c-0704-4283-b6df-ba170e5917dc.PNG)

  ![conflict 해결 화면3](https://user-images.githubusercontent.com/73771162/193803553-2367e626-84d8-455d-8e32-72fe874707df.PNG)

  ![merge 가능해진 PR](https://user-images.githubusercontent.com/73771162/193803569-d25b6931-3e78-4873-a0e4-27ae1a884907.PNG)

  ![merge 커밋 메시지](https://user-images.githubusercontent.com/73771162/193803573-1fbe080c-ffad-4519-93b5-a6392a11fb07.PNG)

  ![PR 후 딜리트](https://user-images.githubusercontent.com/73771162/193803585-0c6e9a5b-a71a-4937-b46e-b14cad725c9f.PNG)

  
  

