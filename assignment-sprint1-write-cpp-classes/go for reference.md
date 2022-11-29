## 레퍼런스 소개

`reference(참조자)`는 자동으로 `dereference(역참조)`되는 `pointer`입니다.

여러분의 코드에서 난잡한 `&(addressof operator)`, `*(dereference operator)`를 지워버릴 도구죠.   

다른 `function scope`의 메모리를 참조하는 게 `pointer`의 주된 용도입니다.   
(`memory access`를 `run time` 정보에 따라 다르게 구현할 때에도 쓰입니다.)   
(`scope`는 범위 혹은 유효 범위라는 뜻으로, `C++` `code` 상에서   
어떠한 `identifier(식별자, 예를 들어 변수나 함수의 이름)`의 `access` 가능 지역을    
제한하는 모든 종류의 양식을 가리킵니다.   
`{ }` 기호를 통해 나타내며, 흔히들 말하는 `지역`이라는 개념을 포함합니다.)

`reference`는 `pointer`를 이용해 구현되는 만큼 용도도 비슷합니다.   

여전히 다른 `function scope`의 메모리를 참조하는 게 `reference`의 주된 용도이지요.

## 포인터와 레퍼런스의 차이

`reference`는 이렇게 이용합니다.

```cpp
void inc_one(int& num)
{
    ++num;
}

int main()
{
    int n = 99;
    inc_one(n);

    std::cout << n;     // 100이 출력됩니다.
}
```

위 `code`는 `pointer`를 이용했다면 다음과 같이 구현됩니다.

```cpp
void inc_one(int* num)
{
    ++*num;
}

int main()
{
    int n = 99;
    inc_one(&n);

    std::cout << *n;    // 100이 출력됩니다.
}
```

다시 위를 살펴보세요.   
`pointer` 버전에서 발견된 `*`, `&`가 `reference` 버전에서는 존재하지 않습니다.   

`pointer`와 구별되는 `reference`의 원리를 설명하기 전에,   
다음과 같은 코드는 분명 여러분이 원하는대로 동작하지 않을 것이란 걸 알고 넘어갑시다.

```cpp
void inc_one(int num)       // 포인터도 아니고, 레퍼런스도 아닙니다.
{
    ++num;
}

int main()
{
    int n = 99;
    inc_one(n);

    std::cout << n;     // 99가 출력됩니다.
}
```

`function`은 다른 `function scope`의 `variable`을 `access`할 수 없습니다.   
오로지 자신의 `local variable`과 `global variable`만 `access` 가능하죠.   

**`function`의 `parameter(매개변수)`는 전부 `argument(인자)`의 사본으로 `initialize`됩니다.**   
**이 명제는 항상 참이니 명심하세요.**

`pointer`나 `reference`가 다른 `function scope`의 메모리를 참조할 수 있는 것은,   
원본 `variable`에 대한 `access` 권한이 있기 때문이 아니라,   
원본 `variable`의 `memory address` 사본을 저장하기 때문입니다.   

`value`의 사본을 받아오면(`pass-by-value`) 사본을 아무리 `write`해봐야 원본은 그대로입니다.   
`memory address`의 사본을 받아오는 경우도(`pass-by-reference`) `memory address` 자체는 사본입니다.   
사본 `memory address`를 아무리 수정해도 원본의 `memory address`는 그대로입니다.   
그러나 사본 `memory address`에 담긴 `value`는, 원본이죠.   

집을 복사하냐, 집 주소를 복사하냐의 문제입니다.  
집을 복사하면 집이 두 개가 되는데,   
집 주소는 복사해봐야 집이 하나죠.   

<br>

자 이제, `pointer`와 구별되는 `reference`의 원리를 알아봅시다.

## 레퍼런스의 특성

- 여러분의 `compiler`가 자동으로 `*`, `&`를 적어줍니다.

  - `initialization(초기화)` 시에 `argument`의 앞에 `&`를 붙여줍니다.
  - `initialization` 이후 `access` 시에 `identifier(식별자, 이름)`의 앞에 `*`를 붙여줍니다.

```cpp
int a = 3;
int& b = /* 여기에 자동으로 & 삽입 */a;
/* 여기에 자동으로 * 삽입 */b += 2;

std::cout << a << '\n';     // output: 5
```

`reference`는 자동으로 `dereference`되는 `pointer`라는 말의 의미가 와닿나요?

다시 위로 올라가 `inc_one`의 `pointer` 버전과 `reference` 버전을 비교해보세요.   
우리 눈에는 다르게 보이지만 `compiler`는 두 코드를 똑같이 해석합니다.   
`compiler`만의 자동화 작업에 의해서요.

<br>

그래서, `reference`는 다음과 같은 특성이 있습니다.

- 한번 `initalize`되면, 참조하는 `memory address`를 바꿀 수 없습니다.

  - `initialization` 이후 `access` 시에는 자동으로 `dereference`되기 때문에,   
  아무리 `reference(l-value reference)`를 `write`해봐야 `value`가 바뀌지   
  `memory address`는 바뀌지 않습니다.

  ```cpp
  template <class T>
  class ListNode
  {
  public:
      ListNode(const T& _data, ListNode* _next, ListNode* _prev)
          : data{ _data }, next{ _next }, prev{ _prev } {}

      ...

      ListNode* get_next() { return next; }
      ListNode* get_prev() { return prev; }
      void set_next(ListNode* _next) { next = _next; }
      void set_prev(ListNode* _prev) { prev = _prev; }
      T& operator*() { return data; }
      
      ...

  private:
      T data;
      ListNode* next;
      ListNode* prev;
  };
  ```

  - 상당히 이른 내용들을 가져와 예시를 보여드리지만,   
    어쩔 수 없었다는 점을 양해해주시기 바랍니다.   
    <br>
    이것은 `linked list(연결 리스트)` `data structure(자료구조)`의 `node(노드)` 구현입니다.   
    (`lineked list`는 연속된 `memory address`를 가지지 않은 메모리 블록들이   
    자신의 앞 메모리 블록과 뒤 메모리 블록의 `memory address`를 담는 `pointer`를 가짐으로써   
    마치 메모리 블록들이 서로 연결된 듯한 효과를 내는 `data structure`입니다.   
    여기에 쓰이는 개별 메모리 블록들을 `linked list`의 `node`라고 합니다.)   
    <br>
    `set_next`와 `set_prev`를 보시면, `next`와 `prev`를 다른 `memory address`로 변경하고 있습니다.   
    만약에 `next`와 `prev`가 `reference(l-value reference)`였다면,   
    `node`간 연결은 `initialization` 시점에 굳어지고 이후에 변경할 수 없을 겁니다.   
    다른 `node`로의 연결은 다른 `memory address`로의 연결인데,   
    `reference`는 참조하고 있는 `memory address`를 `initialization` 이후에 변경할 수 없으니까요.   
    <br>
    `node`간 연결을 바꿀 일이 없다고 해도, 대입 동작을 구현하려는 순간 막혀버릴 겁니다.   
    `next`와 `prev`를 우리가 원하는대로 대입할 수 있는 방법이 없어요.   
    자동으로 `dereference`되어 `memory address`를 수정할 방법은 꿈에도 없으니까요.

- `function call`의 외형만 보고서는 더이상,   
  `function argument`로 전달된 `variable`의 `value`가 바뀔지 안 바뀔지 알 수 없습니다.

  - 위쪽의 `inc_one`은 `reference` 버전에선 증가되었고,   
    `pass-by-value` 버전에선 변하지 않았죠.   
    `argument`의 참조성이 `caller`뿐만 아니라 이제는 `callee`에게도 달려있기 때문입니다.   
    (`function call`의 참조성이 `function parameter`가 `reference`인지 아닌지에도 의존하게 되었다는 겁니다.)

    ```cpp
    dosomething(a);
    ```

    위 코드는 `C`에서는 절대 `a`의 값을 수정할 수 없음이 보장되지만,   
    `C++`에서는 아니라구요.   
    `dosomething`이 `a`를 `reference` 타입의 `parameter`에 `bind`하는 순간   
    `a`는 수정될 가능성이 생깁니다.

  - 이때문에 `C++` 세상에서는 `const(constant, 상수, 읽기전용)`라는 `keyword`가   
    굉장히 중요해지게 됩니다.   
    (다음 과제에서 다루게 될 겁니다.)

## TODO

- [X] swap 구현

- [X] 레퍼런스 반환

## Reference