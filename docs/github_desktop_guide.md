# Github Desktop 사용법

`Github Desktop`은 `GUI(Graphic User Interface)`로 쉽게 `Git`을 이용할 수 있도록 해주는 소프트웨어입니다.   
`CLI(Command Line Interface)`를 통해 `Git` 명령어를 직접 입력하는 것보다 훨씬 간편하게 `Git`을 이용할 수 있습니다.

- `Git`의 주요 기능들을 전부 마우스 클릭 한 번으로 실행할 수 있습니다.
- `Changes` 목록에서 작업 내용을 한 눈에 볼 수 있습니다.
- `History` 목록에서 과거 작업 내용을 한 눈에 볼 수 있습니다.

## Table of contents

- [`Github Desktop` 설치하기](#github-desktop-설치하기)
- [`Clone Repository`](#clone-repository)
- [`Local Repository`에서 작업하기](#local-repository에서-작업하기) 

  - ★ [`Fetch`](#fetch)
  - ★ [`Pull`](#pull)
  - ★ [`Commit`](#commit)
  - ★ [`Push`](#push)
  - [`Amend Commit`](#amend-commit)
  - [`Revert Commit`](#revert-commit)

- [타인과 협업하기](#타인과-협업하기)
- 
  - ★ [`Create Branch`](#create-branch)
  - ★ [`Checkout Branch`](#checkout-branch)
  - ★ [`Merge Branch`](#merge-branch)
  - ★ [`Create Pull Request`](#create-pull-request)

## Github Desktop 설치하기

- [desktop.github.com](https://desktop.github.com/)에서 `Github Desktop`을 다운로드하세요.

<div align="center"><img width="800" height="478" src="https://user-images.githubusercontent.com/73771162/192845534-8b7f41ff-f8b8-4e34-b7d8-5ab1e23ea409.PNG"></div>

- `Download for Windows` 버튼을 클릭하여 다운로드 후, `Github Desktop`을 설치합니다.
                                                                                                                           
<div align="center"><image width="200" height="203" src="https://user-images.githubusercontent.com/73771162/192853114-976bf45a-89c9-4f19-bd5a-d734af1af64b.png"></div>

<div align="center"><image width="600" height="324" src="https://user-images.githubusercontent.com/73771162/192853336-a9404530-79f7-4c4e-a01f-09ac2aa735ed.png"></div>

- 메뉴 바의 `File`-`Options...`를 클릭하여 옵션 창을 엽니다.
- `Accounts` 항목의 `Github`-`Sign in` 버튼을 클릭해 로그인 창을 엽니다.
  
  - `Github` 아이디로 로그인하시면 됩니다.

## Clone Repository

- `Remote Repository`를 복제해 `Local Repository`를 만드는 일입니다.

  - `Remote Repository(원격 저장소)`는 여러분이 `Github` 상에서 보실 수 있는, 프로젝트의 원본이 저장되어 있는 곳입니다.   
    쉽게 말하자면, 여러분의 프로젝트 홈페이지입니다.
  - `Local Repository(지역 저장소)`는 여러분의 컴퓨터 상에 여러분이 설정하는, 여러분만의 작업 공간입니다.   
    쉽게 말하자면, 단순한 폴더입니다.   
    홈페이지에서 여러분의 프로젝트를 다운받아 폴더에 저장해야겠죠.
  - 실시간으로 프로젝트 원본을 수정하면서 작업하지 않고,    
  여러분만의 작업 공간에서 일정량의 작업을 마친 후에 원본에 반영할 수 있도록 해줍니다.
  
    - 그것은 `Commit`이라는 작업 기록의 단위가 됩니다.
    - 작업들이 요약된 `Commit`으로 쉽게 프로젝트의 흐름을 파악하고, 버전을 관리할 수 있습니다.
  
- 여러분들은 `Remote Repository`를 여러분의 개인적인 `Local Repository`로 복제해 와서,   
`Local Repository`에서의 작업을 완료한 뒤 `Remote Repository`에 그 작업 내용을 업로드해야 합니다.   
(결국 `Remote Repository`를 `Local Repository`로 복사해서 작업한 뒤, `Local Repository`를 `Remote Repository`로 복사하는 겁니다.)
  
- 하나의 `Remote Repository`에 대해 여러 `Local Repository`를 만들 수 있습니다.
  
  - 협업 시 서로 다른 운영체제 계정, 서로 다른 컴퓨터마다 `Local Repository`를 만들어 개인이 관리할 수 있습니다.
  
<br>

<div align="center"><image width="800" height="555" src="https://user-images.githubusercontent.com/73771162/192854319-4ecb07e0-ce1a-40c5-91a5-154baf82ca32.PNG"></div>

<div align="center"><image width="200" height="203" src="https://user-images.githubusercontent.com/73771162/192854338-83686689-1e51-4781-a21d-3f99adfd0471.png"></div>

- 화면의 `Clone a repository from the Internet...` 또는 메뉴 바의 `File`-`Clone repository`를 클릭합니다.

<div align="center"><image width="800" height="555" src="https://user-images.githubusercontent.com/73771162/192854917-3f2ff7e6-4192-4799-8f4a-186c82ae0fc8.PNG"></div>

- `Remote Repository`의 `URL`을 지정하고, `Local Repository`의 `Path`를 지정합니다.
  
  - `GitHub.com`이나 `URL` 둘 중 아무 곳에서나 입력해도 됩니다.
  - `Remote Repository`의 `URL`은 `Github`에서 여러분의 `Repository` 페이지를 들어가서 `Code` 항목이 보이는 그 상태의 `URL`입니다.

<div align="center"><image width="1000" height="520" src="https://user-images.githubusercontent.com/73771162/192855774-59479145-a588-4b92-acef-4f6f8e8449c7.PNG"></div>
  
    - 항목의 `Code` 말고, 오른쪽의 초록색 `Code` 버튼을 클릭하면 `Remote Repository`의 `URL`과 `복사 버튼`이 나옵니다.
    - 웹 창 상단의 `URL`을 복사해도 좋습니다.
    - 보시면 아시겠지만, `Github`에서 바로 `Open with GitHub Desktop` 버튼을 눌러 `Clone`을 할 수도 있습니다.   
      이 경우, `Github Desktop`에서 자동으로 `Clone Repository` 창이 열리고 `URL`까지 자동 작성됩니다.   
      `Local Path`만 작성하면 되니, 훨씬 간편해질 것입니다.

## Local Repository에서 작업하기

[`Clone Repository`](#clone-repository)를 수행했다면 `Local Repository`가 마련되었을 겁니다.   
이 항목에서는 혼자서 작업할 때 `Github Desktop`을 통해 `Git`을 이용하는 법을 소개합니다.

### Fetch

<div align="center"><image width="800" height="540" src="https://user-images.githubusercontent.com/73771162/191002635-df06619b-45ae-409f-ba0f-1be5b4c3fd21.PNG"></div>

- `Fetch`는 `Remote Repository`로부터 변동 사항을 가져옵니다.
- `Remote Repository`와 `Local Repository`를 비교하여 업데이트가 필요한 내용이 있는지 확인하는 과정입니다.
- 게임을 실행하려니 업데이트를 해야 할 때, 그 **업데이트 알림**까지가 `Fetch`에 해당됩니다.
  
___
  
### Pull
  
<div align="center"><image src="https://user-images.githubusercontent.com/73771162/191002749-58ad053d-6191-4cb7-8b38-e047ceb14ad5.PNG"></div>

- `Fetch`를 통해 변동 사항을 확인하면, `Fetch` 버튼이 `Pull` 버튼으로 바뀝니다.
- 이 때, `Pull`을 실행합니다.
- `Remote Repository`의 변동 사항을 `Local Repository`에 적용하는 일입니다.
- 게임을 실행하려니 업데이트를 해야 할 때, `실제 업데이트`가 이루어지는 부분이 `Pull`에 해당됩니다.   
  </br>
- **Fetch와 Pull은 여러분들이 실제 작업을 시작하기 전에 이루어져야 하는 일들입니다.**
  
___

이 위는 여러분들이 실제로 프로그래밍을 하고 리소스 작업을 하기 전 시점입니다.
  
여기서 여러분들의 단위 작업이 이루어집니다.
  
이 아래는 여러분들의 매 단위 작업이 끝난 뒤 시점입니다.
___
  
### Commit

**`Git`을 이용함에 있어 가장 중요한 부분입니다.**
  
<div align="center"><image width="800" height="540" src="https://user-images.githubusercontent.com/73771162/191234291-55fa663d-9b17-4915-b839-b3d49ad50cc9.PNG"></div>

- 여러분들의 단위 작업이 끝나면, `Changes`에 변경된 항목들이 나타날 것입니다.
- **`Commit`은 변경된 항목들을 `Local Repository`에 하나의 단위 작업으로서 요약, 기록하는 행위입니다.**
  
  - 변경 사항이 발생할 때마다(예를 들면, 작업 중 `Ctrl+S`를 누를 때마다) 매번 기록하면 버전 관리가 불편하니,   
    몇 개의 작업을 묶어서 일괄적으로 기록하는 겁니다.
  
- **`Commit`을 요약하는 `Commit Message`를 작성하고, `Commit`을 실행합니다.**   
  
- 이전의 `Commit`들은 `History`를 통해 추적할 수 있습니다.
- 다른 사람들은 여러분들의 `Commit History`를 보고 작업 흐름을 파악합니다.   
  그런 만큼, 작업의 흐름이 제대로 눈에 보이도록 언제 `Commit`할지를 잘 정해야 겠죠.

<div align="center"><image width="800" height="540" src="https://user-images.githubusercontent.com/73771162/191240341-bd91e322-f5ed-4ac7-aada-24eae1ec7ebd.PNG"></div>

- 이전 `Commit`들은 `History`에서 확인할 수 있습니다.
  
   
  </br>
 
`Github`에선 다음과 같이 `Commit History`를 확인합니다.

![깃헙](https://user-images.githubusercontent.com/73771162/191240646-209dd91d-897c-4339-bf6a-47754f3010be.PNG)

- `Code` 항목을 눌렀을 때, 파일 목록의 위에 가장 최근의 `Commit Message`와 현재까지의 `Commit` 개수가 나타납니다.
- 화면에 떠있는 `Commit Message`를 클릭하면 그 `Commit`의 내용을 볼 수 있습니다.
- `Commit History`는 `Commit` 개수가 적혀있는 부분을 클릭해서 확인할 수 있습니다.   
  아래의 화면이 나타납니다.
  
![커히](https://user-images.githubusercontent.com/73771162/191241330-da211914-d506-4a15-919b-fa61cd5d1876.PNG)

- 보고 싶은 `Commit`을 클릭하면 그 `Commit`의 내용을 볼 수 있습니다.  

<div align="center"><image src="https://user-images.githubusercontent.com/73771162/191241490-b0fccb2c-855a-4b32-ae81-09e40e31b5ab.PNG"></div>

- 이 `Commit`과 같이, 간단한 `Commit`들은 `Commit Message(제목)`만 작성하고 세부 설명은 작성하지 않아도 괜찮습니다.
___
  
### Push

![푸시](https://user-images.githubusercontent.com/73771162/191242567-adc82f88-a779-4c06-b274-c081a9f2b7bd.PNG)

- `Commit`이 끝나면, `Fetch` 버튼이 `Push` 버튼으로 바뀝니다.
- 이 때, `Push`를 실행합니다.
- `Local Repository`의 변동 사항을 `Remote Repository`에 적용하는 일입니다.
- `Pull`과 `Push`는 단어의 원래 의미처럼, 정확히 반대인 일을 하는 명령어라고 할 수 있죠.
- **`Commit`은 `Local Repository`에 `Snapshot`을 기록하는 명령어지, `Remote Repository`에 업로드하는 명령어가 아닙니다.**   
  **따라서 `Commit`만으로는 `Remote Repository`에 변화를 줄 수 없습니다.**   
  **`Push`를 해야 합니다.**
___
  
### Amend Commit
  
<div align="center"><image width="800" height="540" src="https://user-images.githubusercontent.com/73771162/191248246-f6096307-bb12-4ee8-840b-b5228dd02b8e.png"></div>
  
<div align="center"><image width="800" height="540" src="https://user-images.githubusercontent.com/73771162/191248251-545911b7-3f1b-4ada-a854-706aa7d3a338.png"></div>

  
- `Amend Commit`은 가장 최근의 `Commit`을 수정하는 기능입니다.
- `Amend Commit` 이후 추가 작업한 내용은, 새로운 `Commit`으로 기록되지 않고 기존 `Commit`에 합쳐집니다.
- 빼먹은 내용이 있어서 추가를 해야 할 때 유용합니다.
- `Local Repository`가 가장 최근 `Commit` 이전 상태로 돌아가는 것이 아닙니다.   
  그것은 밑에서 살펴볼 `Revert Commit`입니다.   
  `Amend Commit`은 쉽게 말하면, 지금 새로 작업하는 내용을 가장 최근의 `Commit`에 합치겠다는 겁니다.
___
  
### Revert Commit

<div align="center"><image width="800" height="540" src="https://user-images.githubusercontent.com/73771162/191248660-c3388f7b-2118-41fa-bf94-21a04d24b222.png"></div>
  
- `Revert Commit`은 특정 `Commit`을 취소하는 기능입니다.
- 해당 `Commit`의 변경 사항들이 취소되어, 변경 이전으로 되돌아갑니다.
- 어느 시점의 Commit이든 상관 없이 `Revert`할 수 있습니다.
- **`Revert Commit` 또한 하나의 `Commit`이므로, 반드시 `Push` 한 이후에 새로운 작업을 하시기 바랍니다.**
  
  - 안 그러면 후회할 일이 많을 겁니다...
  - `Revert Commit`을 `Revert`하면, 아무 일도 없던 것처럼 원상복구됩니다, 마치 ~~A = A인 것처럼.   
  그 커밋의 이름은 `Revert Revert Commit`이 됩니다.
  
## 타인과 협업하기
  
`Git`은 타인과의 협업을 아주 효율적으로 도와주죠.   
그것엔 [`Branch`](https://github.com/MyeongWoonJang/cpp-study/blob/main/readme/branch.md)의 공이 아주 큽니다.   
  
`Branch`는 독립적인 작업 공간입니다.   
여러 사람이 작업을 분배해 각자의 `Branch`에서 타인에게 방해받지 않고 작업하게 됩니다.   
  
온라인 작업 공간이기 때문에   
만드는 것도 0 코스트, 삭제하는 것도 0 코스트라는 강력한 장점이 있습니다.
  
무한정으로 만들었다가, 순식간에 모두 없애버릴 수도 있죠.
  
<br>
  
작업을 하면서 여러 `Branch`를 넘나들 일이 있을 것입니다.
  
**자신만이 이용하는 `Branch`가 아닌 경우에는, 직접 `Commit`하지 않고 [`Pull Request`](https://github.com/MyeongWoonJang/cpp-study/blob/main/readme/pull_request.md)하기를 권장합니다.**
  
<br>
  
이 항목에선 타인과 협업할 때 `Github Desktop`, `Branch`를 통해 `Git`을 이용하는 법을 소개합니다.
  
### Create Branch

<div align="center"><image width="800" height="540" src="https://user-images.githubusercontent.com/73771162/191769143-9cb6f4ee-913b-49e3-92fb-83c2e5f82ee3.png"></div>

- `메뉴 바`의 `Branch` - `New Branch`를 클릭하면
이름만 지어서 바로 새 `Branch`를 만들 수 있습니다.
- **만들어진 `Branch`는 `Current Branch`의 파일들이 복사됩니다.**   
  (실제 복사는 아니고, `Current Branch`의 `Snapshot`을 갖는 것입니다.)
  
  - 새로운 `Branch`에서의 작업은 기존 `Branch`에 아무런 영향을 주지 않고 독립적입니다.
  
___
  
### Checkout Branch

<div align="center"><image width="800" height="540" src="https://user-images.githubusercontent.com/73771162/191770974-a3ebf508-d989-4f6a-a3bc-d64d0fe9cb25.png"></div>
  
- `Branch`들은 독립적인 작업 공간이니, 서로 다른 `Branch`로 전환해서 작업해야 할 필요도 있을 겁니다.   
  (`Git`의 `HEAD`를 다른 `Branch`로 `Checkout` 하는 일입니다.)
- `Current Branch`를 클릭하면 `Branch` 목록이 나옵니다.
- 전환하고 싶은 `Branch`를 한 번 클릭하는 것으로, 바로 전환할 수 있습니다.
  
___

### Merge Branch
 
<div align="center"><image width="800" height="540" src="https://user-images.githubusercontent.com/73771162/194208077-42c94e51-1f89-4918-b4fd-c5179b09271a.png"></div>
  
<div align="center"><image src="https://user-images.githubusercontent.com/73771162/193528157-4d9fce20-9fd1-4839-b4d5-ecd92b1c333d.PNG"></div>

- `메뉴 바`의 `Branch` - `Merge into current branch`를 클릭하면 `Merge`를 실행할 수 있습니다.
  
  - `Source Branch`를 설정하는 창이 뜹니다.
  
    - [`Checkout Branch`](#checkout-branch)에서 처럼 `Branch` 목록에서 하나를 클릭하면 됩니다.
  
  - `Current Branch`가 `Target Branch`가 됩니다.
  
- **자신만이 이용하는 `Branch`가 아닌 경우에는, 함부로 `Merge`를 실행하면 안 됩니다.**
  
  - [`Pull Request`](https://github.com/MyeongWoonJang/cpp-study/blob/main/readme/pull_request.md)를 활용하면 좋을 것입니다.
  
- `Merge`로 인한 `Conflict` 발생이 예상될 시 몇 개의 파일에서 `Conflict`가 발생하는지 경고 메시지를 보여줍니다.
  
  - `Conflict`를 해결하려면 일단 `Create a merge commit` 버튼을 누릅니다.
  
<div align="center"><image src="https://user-images.githubusercontent.com/73771162/193528174-d97ae228-d109-4a79-b82d-4163249b4421.png"></div>

- 어느 한 `Branch`의 파일로 다른 `Branch`의 파일을 덮어씌우려면 `Use the added file from ...(브랜치명)`을 클릭합니다.
  
  - 간단하게 `Conflict`를 해결할 수 있습니다.
  
- 직접 수정할 경우, `Open in editor` 버튼이 활성화되어 있다면 해당 버튼을 누릅니다.   
  그렇지 않다면, `...`에서 `Open with default program`을 누릅니다.
  
  <div align="center"><image src="https://user-images.githubusercontent.com/73771162/193528197-4a8070ec-33d6-4400-bc33-647333ce6288.PNG"></div>
  
  - [`Merge Branch`에서의 `Conflict`를 해결하는 요령](https://github.com/MyeongWoonJang/cpp-study/blob/main/readme/branch.md#%EC%B6%A9%EB%8F%8C-conflict)으로 `Conflict`를 해결합니다.
    
___
    
### Create Pull Request

<div align="center"><image src="https://user-images.githubusercontent.com/73771162/194335593-8a731ae6-e0cd-4d67-a953-e4996c67e50b.PNG"></div>
  
- `main`/`master` `Branch`를 제외한 `Branch`에서 작업할 때에는,   
  실행해야 할 `Git` 명령어가 남아있지 않을 때 `Create Pull Request` 버튼이 활성화됩니다.
  
  - 해당 버튼을 클릭하면, `Github`에 있는 여러분의 `Repository` 페이지의 `Pull requests` 항목에서 `New pull request` 버튼을 누른 효과입니다.
  
  <div align="center"><image src="https://user-images.githubusercontent.com/73771162/194337496-c1c17348-2fc6-4a15-94d3-eb0fabea71bc.PNG"></div>

  
  - 무조건 `Current Branch`가 `Source Branch`, `main`/`master`가 `Target Branch`로 설정됩니다.
  
    - `Source Branch`와 `Target Branch` 설정까지 영리하게는 되지 않습니다.
    - `New pull request`의 바로가기 버튼이라고 생각하시면 좋습니다.



    
    
    
    
