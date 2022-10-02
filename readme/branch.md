# Branch

<div align="center"><image width="800" height="574" src="https://user-images.githubusercontent.com/73771162/193435758-a3541681-0073-4917-a53e-e449b84d0269.png"></div>

<div align="center">
  
source: [Git Notes for Professionals](https://books.goalkicker.com/GitBook/)
  
</div>
  
<br>
`Branch(분기)`는 `Git`의 강력한 기능 중 하나입니다.   
협업 과정에서 없어서는 안 될 요소이며, `Branch`가 없다면 굉장히 비효율적인 작업 과정을 거쳐야 할 것입니다.   

`Branch`가 왜 필요한지, 어떤 기능을 하는지 이 글을 통해 소개하도록 하겠습니다.

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

  
___
### 분기 전환 (Checkout Branch)

  
<div align="center"><image src="https://user-images.githubusercontent.com/73771162/193436467-d358df8a-e028-48ab-8c3f-ff892647721f.PNG"></div>

  
___

### 분기 합병 (Merge Branch)

<div align="center"><image src="https://user-images.githubusercontent.com/73771162/193436456-8ec49b97-f01f-448b-92ff-f36b76d97a17.PNG"></div>

  
merge해도 원래 branch가 사라지진 않는다는 점


`Merge`는 합병이라는 뜻입니다.   
서로 다른 두 `Branch`를 하나의 `Branch`로 합칩니다.
  
- 한 `Branch`에 `A`, `B`, `C`라는 파일이 있고 다른 `Branch`에 `D`, `E`라는 파일이 있다면   
`Merge`된 `Branch`에는 `A`, `B`, `C`, `D`, `E`라는 파일이 있습니다.
 
- 중요한 경우는 한 `Branch`에도 `A`라는 파일이 있고, 다른 `Branch`에도 `A`라는 파일이 있는 경우입니다.   
이 상황을 `Conflict`가 발생했다고 합니다.  
  
  - `Git`은 훌륭하게도, `Merge`된 `Branch`의 `A` 파일에 차이점을 분석해서 요약합니다, 무엇의 차이점을요?   
  `Merge` 되기 전 서로 달랐던 두 `A` 파일의 차이점을요.   
  - 여러분은 그 요약을 보고 차이점들을 수동으로 합친 다음 `Git`이 생성한 요약을 지워주시면 됩니다.   
  그러면 `Conflict`가 해결됩니다.

#### 충돌 (Conflict)

예시 사진이 필요할 듯

___

## Branch의 추가적인 활용

### Pull Request

Pull Request도 따로 게시글로 만들기

___

### 프로젝트에 여러 작업 흐름을 두기

gitflow 소개

## Reference
