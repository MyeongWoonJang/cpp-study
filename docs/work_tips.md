# Work Tips
[@Woon2](https://github.com/Woon-2)의 자잘한 업무 팁들을 소개합니다.   
저는 싱글 모니터 환경에서 작업하기 때문에, 듀얼 모니터를 사용하시는 분들을 위한 팁은 준비하지 못했습니다.

## Table of contents

- [업무 시작 루틴](#업무-시작-루틴)
- [마크다운 문서 작성 팁](#마크다운-문서-작성-팁)
- [이미지 첨부 팁](#이미지-첨부-팁)
- [코드 첨부 팁](#코드-첨부-팁)
- [연관된 커밋/게시글 링크를 첨부해 정보 접근성 높이기](#연관된-커밋게시글-링크를-첨부해-정보-접근성-높이기)
- [커밋 메시지로 이슈 닫기](#커밋-메시지로-이슈-닫기)
- [Reference](#reference)

## 업무 시작 루틴

<div align="center"><image width="800" height="540" src="https://user-images.githubusercontent.com/73771162/191002635-df06619b-45ae-409f-ba0f-1be5b4c3fd21.PNG"></div>

- 먼저 `Github Desktop`을 켜 작업할 `Branch`에서 `Fetch`를 실행합니다.

<div align="center"><image src="https://user-images.githubusercontent.com/73771162/194732748-724df83b-a070-4a57-944b-dc73713f2597.PNG"></div>

- 저는 `Chrome`을 두 개의 세션을 띄워 하나는 최대화하고 하나는 축소해서 사용합니다.

  - 최대화된 세션은, 작업중인 `Github`와 `Jira Board` 단 두 개의 탭만 띄워놓습니다.
  - 축소된 세션은 여러 탭을 이용해 정보를 찾거나 링크 `복사/붙여넣기`, `업로드/다운로드` 등을 하기 위한 용도입니다.

    - `Github`만 적어도 두 탭은 띄워놓습니다.

## 마크다운 문서 작성 팁

<div align="center"><image width="700" height="609" src="https://user-images.githubusercontent.com/73771162/194733630-7cec9394-7a76-48b3-8ffc-244a83a95c8c.PNG"></image></div>

- 줄넘김

  - 처음 마크다운 문서를 작성할 때에는 많이 애먹죠.   
  문자열 끝에 `<br>`을 적거나 `3 spaces`를 입력하는데, 저는 `3 spaces`를 선호합니다.
  - 단락을 구분할 때에는 `Enter`를 한 번 더 입력해 빈 줄을 사이에 둡니다.

    - 가독성을 위해 1~3 문장 정도로 짧게 단락을 구성합니다.
    - 추가로 간격이 필요할 때에는 빈 줄 + `<br>`만 적힌 줄들 + 빈 줄과 같이 구성합니다.   
      (`Enter`로 빈 줄을 아무리 만들어봐야 빈 줄 하나만 만들어져서 소용없기 때문입니다.)

  - 이미지를 삽입한 경우에 이미지 앞뒤로 `Enter`를 입력해 빈 줄을 둡니다.

- `header` 작성

  - `#` - 큰 제목
  - `##` - 항목 (목차에 적어놓을 항목들)
  - `###` - 소항목 (`##`만큼 클 필요는 없다고 생각되는 것들) (목차에 적기도, 안 적기도)
  
    - `###`은 `header`에 밑줄이 그어지지 않으므로 `Enter` + `___` + `Enter`를 삽입해 밑줄을 긋습니다.

  - `####` ~ `######` - 잘 이용하지 않습니다.

- `list` 작성

  - 대부분의 설명에 `list`를 이용합니다.
  - `-` 기호를 사용하며, 수준을 낮출 때에는 `2 spaces`를 입력합니다.
  - 수준이 달라질 때에는 `Enter`를 한 번 더 입력해 빈 줄을 사이에 둡니다. (높아질 때와 낮아질 때 모두)
  - "다음의 ~~~를 ...합니다."와 같은 서술을 하고,   
  수준을 낮추어 여러 내용을 정리하는 경우가 많습니다.

- `code block` 장식

  - `로 문자열을 둘러싸면 네모난 블럭이 됩니다.
  - 주요 용어들을 `이와 같이` `code block`으로 만듭니다.
  - 링크 텍스트나, 인용문 안에도 `code block`을 삽입할 수 있어 애용합니다.

## 이미지 첨부 팁

- `Github` 상에서 문서를 작성할 때에는 `Drag&Drop`으로 간단히 이미지를 올릴 수 있습니다.
- 로컬에서 작성할 때에는, 아까 띄워놓은 작은 `Chrome` 세션 있죠?   
  거기에 `Github` 아무 게시글이나 `edit` 모드로 들어가서 `Drag&Drop`으로 이미지를 올린 뒤, 링크를 복사해옵니다.

  - 이미지를 `Drag&Drop`하는 순간 글 저장을 하든 안하든, 이미지는 업로드되거든요.
  - `http://user-images.githubusercontent.com`에 이미지가 업로드 및 보관됩니다.   
  우리는 여기에 있는 우리의 이미지 `URL`을 따와서 이용하는 겁니다.

- `div` 태그와 `image` 태그를 이용해 가운데 정렬을 꼭 해줍니다.

  - `<div align="center"><image src="이미지 URL"></div>` 와 같이 작성합니다.
  - 여러 개의 이미지를 첨부할 때, 처음 한 번만 직접 작성하고 다음부터는 줄을 통째로 복사한 뒤 이미지 `URL`만 수정합니다.

- 이미지 크기를 조절할 땐 다음과 같이 합니다.

  - 이미지를 그림판으로 열어 `크기 조절`을 클릭한 후,   
  `가로 세로 비율 유지`가 활성화된 채로 가로 픽셀을 원하는 수치로 수정합니다.
  - 변경된 가로 픽셀 수와 세로 픽셀 수를 기억합니다.
  - `image` 태그에 `width`와 `height` 속성을 설정합니다.
  
    - `<div align="center"><image width="가로" height="세로" src="이미지 URL"></div>` 와 같이 작성합니다.

## 코드 첨부 팁

- 직접 작업중인 코드를 복사할 때

  - `code block`을 만든 후, 그 안에 코드를 `복사&붙여넣기` 합니다.
  - 이런 느낌이 됩니다.
  ``` cpp
  #include <iostream>

  int main()
  {
      std::cout << "Hello, World!\n";
  }
  ```

- 특정 `Commit`의 코드를 복사할 때

  <div align="center"><image src="https://user-images.githubusercontent.com/73771162/194734246-be06b35c-24fc-47c0-ab18-d006e74962c5.PNG"></div>

  - 복사할 영역을 설정합니다.

    - 복사하고 싶은 부분의 시작 `Line Number`를 클릭합니다.
    - 복사하고 싶은 부분의 끝 `Line Number`를 `Shift`를 누른 채로 클릭합니다.
    - 노란색 영역이 만들어졌을 겁니다. 

  - 왼쪽 `...` 버튼을 클릭합니다.
  - `Copy permalink` 버튼을 클릭합니다.
  - 이제 원하는 곳에 `붙여넣기` 하면 됩니다.
  - 이런 느낌이 됩니다.

  https://github.com/Woon-2/cpp-study/blob/2b98231f2ef9b0c7e0a503aa3016b80e2a049b1a/base_app.cpp#L3-L11

  - 여기서 잠깐, 여러분이 `Github` `Repository`의 `Code` 항목에서 파일을 클릭하고 코드를 복사하는 것도 특정 `Commit`의 코드를 복사하는 것입니다.    
  
    - `Github` `Repository`의 `Code` 항목은 가장 최근 `Commit`(`HEAD`가 가리키는 대상)을 보여주는 것이죠.

## 연관된 커밋/게시글 링크를 첨부해 정보 접근성 높이기

- `Hyperlink`는 우리에게 주어진 선물입니다.
- `Repository`에 있는 모든 파일/외부 웹사이트/`Commit`/`Issue`/`Discussion`/`Pull Request`가 링크 가능합니다.
- `Commit Message`나 글의 본문, 댓글을 통해서 링크합니다.

  - 특히, `Commit Message`에 링크를 첨부하는 게 꽤나 효과적인 것 같습니다.

- 종류별 링크 방법은 다음과 같습니다.

  - `Repository`에 있는 모든 파일 및 외부 웹사이트

    - `[링크 텍스트](URL)`의 형태로 작성합니다.

      - 링크 텍스트는 []로 여닫기 때문에, 문자 `[`와 `]`를 쓰려면 \를 붙여서 `\[`, `\]`와 같이 입력해야 합니다.
      - `[\[티스토리 Woon2World\]](https://jartlife.tistory.com/)`와 같이 작성합니다.   
        [\[티스토리 Woon2World\]](https://jartlife.tistory.com/) 이렇게 만들어집니다.

    - `Github`에서 파일을 클릭하면 위쪽에 `URL`이 바뀌죠?   
      `Repository` 내의 파일도 각각 `URL`이 있습니다.
    - `[Github Desktop 사용법](https://github.com/Woon-2/cpp-study/blob/main/docs/github_desktop_guide.md)`와 같은 예시가 있습니다.

  - `Commit`

    <div align="center"><image src="https://user-images.githubusercontent.com/73771162/194735030-ebeb10cf-78a6-4823-8676-83222b579033.PNG"></image></div>

    - `Github`의 `Commit History`에서 `복사` 버튼을 클릭합니다.
    - 원하는 곳에 `붙여넣기` 합니다.

    <div align="center"><image width="800" height="540" src="https://user-images.githubusercontent.com/73771162/194735109-0eca7fe9-db13-4ab7-9106-a60e3e90a0f5.png"></div>
  
    - `Github Desktop`의 `Commit History`에서 `Copy SHA` 버튼을 클릭해도 복사가 가능합니다.
    - 원하는 곳에 `붙여넣기` 합니다.

  - `Issue` 및 `Discussion` 및 `Pull Request`

    <div align="center"><image src="https://user-images.githubusercontent.com/73771162/194735334-d313cdc1-8b7e-4d37-820c-3b78e4f86b0e.png"></div>
    
    - 이들은 `#n` 형태의 태그 번호가 있습니다.
    - 요약 정보에도 나와 있고, 마우스를 가져다 대면 나오는 `tooltip`에도 나와 있습니다.
    - `#n`과 같이 태그 번호만 적으면, 알아서 링크됩니다.

> `Commit Message`에 `#n`이나 `2b98231f2ef9b0c7e0a503aa3016b80e2a049b1a` 같은 걸 적었는데,   
> 링크가 제대로 안 되면 어쩌나 걱정하실 수도 있을 겁니다.
> 
> #n만 적어도 게시글들이 아주 잘 링크 되고,
> 저렇게 긴 커밋 해시코드도 `2b98231`과 같이 짧게 표시되고 자연스럽게 `Commit`이 링크됩니다.

## 커밋 메시지로 이슈 닫기

- `Commit Message`에 `종료 키워드`와 `Issue` `number`를 넣으면 `Issue`를 닫을 수 있습니다.

  <div align="center"><image width="800" height="540" src="https://user-images.githubusercontent.com/73771162/194735635-f41cebb7-b75f-4769-96aa-c920880a01b5.png"></div>

  - `Github Desktop`의 `Commit Message`에 `#`을 입력하면, `Open` `Issue` 목록이 나타납니다.

- `종료 키워드`는 다음과 같습니다.

  - `close`
  - `closes`
  - `closed`
  - `fix`
  - `fixes`
  - `fixed`
  - `resolve`
  - `resolves`
  - `resolved`

- 그리고 한 `Commit`에 여러 개의 `Issue` `number`가 있는 경우, 같이 종료하게 됩니다.

  - `fixed XSS Vulnerability - #20, #21, #23`와 같은 `Commit Message`가 가능합니다.

## Reference

[마크다운 문법 - Jinkyu Kim](https://github.com/jinkyukim-me/markdown_ko)   
[\[Hanwul\] Git commit으로 Issue 종료하기(Closing issue with commit)](https://www.hahwul.com/2018/07/27/closing-git-issue-with-commit/)   
