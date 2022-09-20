# Github Desktop 사용법

`Github Desktop`은 `GUI(Graphic User Interface)`로 쉽게 `Git`을 이용할 수 있도록 해주는 소프트웨어입니다.   
`CLI(Command Line Interface)`를 통해 `Git` 명령어를 직접 입력하는 것보다 훨씬 간편하게 `Git`을 이용할 수 있습니다.

- `Git`의 주요 기능들을 전부 마우스 클릭 한 번으로 실행할 수 있습니다.
  - [`Fetch`](#fetch) ★
  - [`Pull`](#pull) ★
  - [`Commit`](#commit) ★
  - [`Push`](#push) ★
  - [`Amend Commit`](#amend-commit)
  - [`Revert Commit`](#revert-commit)
  - `Create Branch` ★
  - `Checkout Branch` ★
  - `Merge Branch` ★
  - `Create Pull Request` ★
- `Changes` 목록에서 작업 내용을 한 눈에 볼 수 있습니다.
- `History` 목록에서 과거 작업 내용을 한 눈에 볼 수 있습니다.

## 자신의 브랜치에서 작업하기

`Git`의 진정한 힘은 협업에서 발휘되지만, 혼자서 작업할 때에도 유용합니다.
이 항목에서는 혼자서 작업할 때 `Github Desktop`을 통해 `Git`을 이용하는 법을 소개합니다.

### Fetch

<div align="center"><image width="800" height="540" src="https://user-images.githubusercontent.com/73771162/191002635-df06619b-45ae-409f-ba0f-1be5b4c3fd21.PNG"></div>

- `Fetch`는 `Remote Repository`로부터 변동 사항을 가져옵니다.
- 업데이트가 필요한 내용이 있는지 확인하는 과정입니다.
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
- `Commit`은 변경된 항목들을 `Local Repository`에 하나의 단위 작업으로서 기록합니다.
- 변경 사항이 발생할 때마다(예를 들면, 작업 중 `Ctrl+S`를 누를 때마다) 매번 기록하기는 번거로우니,   
  몇 개의 작업을 묶어서 일괄적으로 기록하는 겁니다.
- **`Commit Message`를 작성하고, `Commit`을 실행합니다.**   
  
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

- 보고 싶은 커밋을 클릭하면 그 `Commit`의 내용을 볼 수 있습니다.  

<div align="center"><image src="https://user-images.githubusercontent.com/73771162/191241490-b0fccb2c-855a-4b32-ae81-09e40e31b5ab.PNG"></div>

- 이 커밋과 같이, 간단한 커밋들은 메시지(제목)만 작성하고 세부 내용은 작성하지 않아도 괜찮습니다.
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
