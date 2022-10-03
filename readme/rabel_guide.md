# 라벨 
* **어떠한 종류의 `Issue`인지 한 눈에 식별할 수 있도록, 모든 `Issue`에는 라벨을 부착합니다.**
* **`Issue` 제목은 라벨별로 번호를 정리해서 작성합니다.**   
라벨의 앞 두 글자를 대문자, 소문자 순으로 적어 라벨을 식별합니다.   
번호는 `001`부터 시작해서 누적 증가하는 정수입니다.   
예를 들어 현재 세 개의 `bug issues`, 두 개의 `documentation issues`가 있는데 발생 순서가 뒤섞여있다면

   >Bu003 세 번째 버그 이슈 제목   
   >Bu002 두 번째 문서화 이슈 제목   
   >Do002 두 번째 질문 이슈 제목   
   >Bu001 첫 번째 버그 이슈 제목   
   >Do001 첫 번째 문서화 이슈 제목   

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;와 같은 경우가 있을 수 있습니다.   

</br>

## 라벨 설명 바로가기
[1. good first issue](#1-good-first-issue)   
[2. bug](#2-bug)   
[3. documentation](#3-documentation)   
[4. duplicate](#4-duplicate)   
[5. enhancement](#5-enhancement)   
[6. help wanted](#6-help-wanted)   
[7. invalid](#7-invalid)   
[8. question](#8-question)  

</br>

# 라벨의 종류

## 1. good first issue
![good first issue](https://user-images.githubusercontent.com/73771162/190851817-2e23caa6-edec-487c-ba77-4c364e14681b.png)

- Readme에 해당하는 라벨입니다.
- 처음 방문한 분들을 위한 안내 라벨입니다.


## 2. bug
![bug](https://user-images.githubusercontent.com/73771162/190851920-dc231a87-a216-4120-87d4-18c21c8ea1a9.png)

- 코드의 버그를 발견했을 시 보고하는 라벨입니다.
- 다음을 포함해주십시오.

  - 버그가 발견된 브랜치와 파일명
  - 버그를 일으키는 코드 부분에 대한 스크린샷들
  - 버그 내용이 포함된 실행 결과



(여기에 예시 이미지 부착 예정)


## 3. documentation
![documentation](https://user-images.githubusercontent.com/73771162/190851926-b7b5874a-b0c2-4d98-b9fd-2244990f59b5.png)

- 문서화가 필요할 시/문서화 오류, 문서 오탈자를 발견했을 시 보고하는 라벨입니다.
- 다음을 포함해주십시오.

   - (문서화가 필요할 시) 문서화가 필요한 브랜치와 파일명
   - (문서화 오류, 문서 오탈자를 발견했을 시) 해당 부분의 스크린샷


## 4. duplicate
![duplicate](https://user-images.githubusercontent.com/73771162/190851930-6360e706-cc0f-4ed2-be82-efa8831e526b.png)

- 동일한 기능을 하는 클래스나 함수, 내용이 중복된 코드를 발견했을 시 보고하는 태그입니다.
- 다음을 포함해주십시오.

   - 중복이 발견된 브랜치와 파일명
   - 중복으로 여겨지는 코드 부분 전부에 대한 스크린샷들 (중복이니 최소 두 개)

(여기에 예시 이미지 부착 예정)


## 5. enhancement
![enhancement](https://user-images.githubusercontent.com/73771162/190851933-a82e9cc9-1cde-42bf-b82a-878fb2a5251d.png)

- 코드 리팩터링, 기능 개선, 최적화 등을 통해 더 나은 코드를 생성했을 시 보고하는 라벨입니다.
- 다음을 포함해주십시오.

   - 개선한 브랜치와 파일명
   - 변경된 부분들을 알 수 있도록 해당 내용이 포함된 전/후 스크린샷들 (전/후이니 최소 두 개)
   - 개선을 확인할 수 있는 실행 결과물 (없을 경우 생략)
   - 기대 효과


## 6. help wanted
![help wanted](https://user-images.githubusercontent.com/73771162/190851936-3ca33d1e-e6d7-4d91-9214-09d01a65d543.png)

- 프로그래밍 중 난항이 생겨 도움이 필요할 때 보고하는 라벨입니다.
- 다음을 포함해주십시오.

   - 난항을 겪고 있는 브랜치와 파일명
   - 난항을 겪고 있는 부분에 대한 스크린샷
   - 난항을 겪고 있는 부분에 대한 실행 결과 스크린샷 (실행이 불가능할 경우 오류창과 디버그 메시지가 포함된 스크린샷, 무한루프/렉일 경우 해당 상황이 발생하기 직전 라인넘버)


## 7. invalid
![invalid](https://user-images.githubusercontent.com/73771162/190851938-8e308bc0-8fbf-497d-8d3d-bdac26d09c7d.png)

- 무의미한 코드를 발견했을 시 보고하는 라벨입니다.
- 다음을 포함해주십시오.

   - 무의미한 코드가 포함된 브랜치와 파일명
   - 무의미한 부분에 대한 스크린샷


## 8. question
![question](https://user-images.githubusercontent.com/73771162/190851942-4ab44d4d-0f5e-4057-8516-a5482cc1a5dd.png)

- 코드 리뷰중 궁금한 사항이 생겨 질문하고 싶을 때 이용하는 라벨입니다.
- 다음을 포함해주십시오.

   - 궁금한 사항이 발생한 브랜치와 파일명
   - 궁금한 사항이 발생한 부분에 대한 스크린샷
   - 답변자가 질문을 이해하는 데 도움을 주는 참고자료
