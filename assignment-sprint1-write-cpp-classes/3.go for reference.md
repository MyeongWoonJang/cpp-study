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

- 이번 과제에선 완성된 프로그램을 작성하기 때문에,   
  실행까지도 시켜볼 수 있을 겁니다.   
  <br>
  "go_for_reference.cpp"를 생성하고, `<iostream>`을 `include`하세요.

- [X] swap 구현

  - `C` 프로그래머일 경우 사용하게 될, `pointer` 버전 `swap`을 만들어봅시다.      
  (`swap`에 쓰일 `data type`은 `int`로 한정합시다.)
  
  ```cpp
  void swap(int* lhs, int* rhs)
  {
      // lhs: left hand side, rhs: right hand side
      // lhs에 rhs의 값을 대입하고 나면,
      // lhs와 rhs의 값이 같아집니다.
      // 기존의 lhs 값은 대입으로 인해 사라지고 말죠.
      // 이에 따라 기존의 lhs 값을 기억할 임시 변수 tmp(temporary)가 필요합니다.

      // 1. tmp에 lhs의 값을 대입합니다.
      // 2. lhs에 rhs의 값을 대입합니다.
      // 3. rhs에 tmp의 값을 대입합니다.

      // tmp가 rhs를 저장하는 방식으로 구현해도 상관없습니다.
      // 우항이었던 변수가 다음 줄에서 좌항이 된다는 점을 기억하세요.
  }
  ```

  - 그리고 `main`을 다음과 같이 구성합시다.

  ```cpp
  int main()
  {
      int a = 3;
      int b = 5;

      swap(&a, &b);

      std::cout << "a = " << a << ", b = " << b << '\n'; // output: a = 5, b = 3
  }
  ```

  - 프로그램을 실행시켜서 `a = 5, b = 3`이 출력되는지 확인해보세요.   
    정확히 만드셨다면 출력이 위와 같아야 합니다.

  - 이제 `C++` 세상으로 넘어왔습니다.   
    `main`을 다음과 같이 구성하고,   
    실행 시 이전과 같은 결과를 내도록 `swap`을 수정해보세요.   
    `lhs`와 `rhs`가 `pointer`가 아닌 `reference`가 된다는 것이 힌트입니다.

  ```cpp
  int main()
  {
      int a = 3;
      int b = 5;
  
      swap(a, b);

      std::cout << "a = " << a << ", b = " << b << '\n'; // output: a = 5, b = 3
  }
  ```

- [X] 레퍼런스 반환

  - 메모리 요구치가 큰 타입을 `function argument`나 `return value`로 전달하려는 경우,   
  `pass-by-value`보단 `pass-by-reference`를 선호하라는 말이 있습니다.   
  <br>
  `function parameter`를 `reference`로 `declare(선언)`하는 것은 위에서 보셨으나,   
  `return type`을 `reference`로 `declare`하는 것은 아직 못 보셨죠.   
  <br>
  `pointer`를 `return`하는 것에 대해 어느정도 능숙한 사람들도,   
  `reference`를 반환하는 건 언제여야 하는지 잘 모르는 사람들이 많습니다.  
  <br> 
  `reference`가 자동으로 `dereference`되는 `pointer`라는 점을 간과하고,   
  괜히 `reference`를 사용하면 메모리 이용 효율이 올라갈 것 같아   
  `pointer`가 전혀 쓰일 수 없는 맥락에서까지 `reference`를 사용하곤 하죠.

  - 일단, `reference`를 `return`하면 안 되는 예시를 봅시다.   
    예시를 보여드리는 것이니, 직접 `code`를 작성하시진 않으셔도 됩니다.

  ```cpp
  int& add(int a, int b)
  {
      return a + b;
  }

  int main()
  {
      int a = 10, b = 20;

      std::cout << add(a, b) << '\n';
  }
  ```

  - 다행히도, 위와 같은 `code`는 `compile`조차 불가합니다.   
  <br>
  `a + b`는 우리가 명시적으로 `declare`한 `variable`이 아니죠.   
  그러나 어쨌든 연산 결과는 저장됩니다.   
  `temporary variable(임시 변수)`에 말이죠.   
  `a + b`의 결과를 `access`함은, 바로 그 `temporary variable`을 `access`함을 의미합니다.   
  <br>
  `temporary variable`은 우리가 이름을 주지 않았기 때문에,   
  그것이 생성된 라인을 넘어가면 `access`할 수 없습니다.   

  ```cpp
  std::cout << add(a, b);   // add(a, b)가 만들어낸 임시 변수가 std::cout에 출력되고 있습니다.
  int result = add(a, b);   // add(a, b)가 만들어낸 임시 변수를 result에 저장하네요.
                            // 임시 변수는 단명하지만, result는 유효 범위 내내 생존합니다.
  ```

  - 그리고 이러한 `temporary variable`의 주소를 취하는 것은 금지되어 있습니다.   
    위의 `code`가 `compile`이 불가했던 이유이지요.   
    <br>
    그런데 살짝만 `code`를 비틀면, 문제를 간직한 채로 `compile`이 가능하게 만들어버릴 수 있습니다.   
    <br>
    바로 위의 `add(a, b)`를 `result`에 저장했던 사례를 응용하는 것입니다.

  ```cpp
  int& add(int a, int b)
  {
    int result = a + b;
    return result;
  }

  int main()
  {
    int a = 10, b = 20;

    std::cout << add(a, b) << '\n';
  }
  ```

  - 몇몇 `compiler`들은 옵션 설정에 따라 위의 `code`를 `compile` 거부할 수도 있지만,   
  그렇지 않은 경우도 있습니다.   
  <br>
  `compile` 가능한 경우, 실행 결과는 정의되어있지 않습니다. (`undefined`)   
  다른 `compiler`를 사용할 일이 전혀 없다 해도   
  여러분의 `IDE`를 업데이트했더니 돌아가던 게 안 돌아갈 수도 있고,   
  협업자의 실행 결과와 여러분의 실행 결과가 다를 수 있습니다.   
  <br>
  `result`는 `temporary variable`이 아닙니다. (우리가 명시적으로 `declare`했죠.)    
  `add`가 종료되면 사라지는, `add`의 `scope` 안에 있는 `local variable`을   
  `reference`로 `return`한다니, 참으로 위험한 행동입니다.   
  <br>
  `add(a, b)`로 인해 만들어진 `temporary variable`은 `result`의 `reference`인데,   
  `result`는 `add`가 종료되자마자 사라지죠.   
  <br>
  그렇게 사라진 `result`를 `(empty)`라고 하면,   
  `temporary variable`은 `(empty)`를 담고 있는 것입니다.   
  <br>
  `std::cout << (empty) << '\n'`이라는 `code`가 실행되고 있는 거라구요.   
  
  - 이렇게 위험한 행동을 하지 않기 위해서는,   
  `pointer`나 `reference` 타입으로 `declare`된 `parameter`를 `return`할 때에만 `reference`를 이용해야 합니다.   

    - `parameter`로 `declare`된 `variable`을 `return`해야 하고
    - 그 `parameter`가 `pointer`나 `reference`여야 합니다.

  - 두 번씩이나 강조한 것은,   
    `class`를 이용하는 순간 `reference`는 밥먹듯이 보게 될 친구이고,   
    `member function`의 암묵적 `parameter`인 `this pointer`를 `dereference`해 반환하는 일이   
    불가피한 순간이 반드시 오기 때문입니다.   
    <br>
    혹여 이 항목에서 `code`를 수정해가며 실험해보셨다면,   
    위의 `swap` 구현 항목에서 모든 과정을 끝낸 마지막 상태로 다시 `code`를 되돌립시다.

  - 다음 `structure`를 여러분의 `code`에 추가해주세요.
  
  ```cpp
  struct TestScore
  {
      int math;
      int english;
      int physics;
      int chemicals;
  };
  ```

  - `main`에 다음의 `code`를 추가하세요.

  ```cpp
  TestScore a{20, 50, 30, 40};
  TestScore b{40, 60, 90, 70};
  TestScore c{10, 30, 60, 60};

  if (&a != &min(a, b) ||
      &c != &min(b, c) ||
      &a != &min(a, c))
  {
      std::cout << "min의 구현이 잘못되었습니다.\n";
  }

  if (&b != &max(a, b) ||
      &b != &max(b, c) ||
      &c != &max(a, c))
  {
      std::cout << "max의 구현이 잘못되었습니다.\n";
  }

  if (&c != &median_of_three(a, b, c))
  {
      std::cout << "median_of_three의 구현이 잘못되었습니다.\n";
  }

  std::cout << "\"...의 구현이 잘못되었습니다.\" 출력이 안 나왔다면 성공!\n";
  ```

  - 다음의 함수들을 작성해 `main`이 올바르게 실행되도록 해봅시다.   
    아직 만들지 않은 `function`을 이용하는 `main`의 `code`는 주석처리 하는 것으로,   
    `function`을 만들 때마다 따로따로 테스트해볼 수 있습니다.

    - `TestScore` 두 개 중 모든 `member variable`의 합이 작은 것을 `return`하는 `min`
    - `TestScore` 두 개 중 모든 `member variable`의 합이 큰 것을 `return`하는 `max`
    - `TestScore` 세 개 중 `member variable`의 합에 대해   
    중간값을 가진 `TestScore`를 `return`하는 `median_of_three`

  - 저라면, `TestScore`의 `code`를 변경할 수 없고,   
    짧은 시간에 많이 수행되는(=성능이 중요한) `function`이 아니라는 가정 하에   
    다음과 같은 `code`를 작성했을 것입니다.   
    <br>
    컨닝은 힘들 겁니다.   
    `function overloading`, `const`, `const_cast`, `inline`, `auto`, `decltype`, `noexcept`   
    이런 개념들을 알아야 이해할 수 있을 거거든요.

    ```cpp
    inline
    const auto
    sum(const TestScore& ts) noexcept
    {
        return ts.math + ts.english + ts.physics + ts.chemicals;
    }
      
    inline
    decltype(auto)
    __min_impl(const TestScore& lhs, const TestScore& rhs) noexcept
    {
        return sum(lhs) < sum(rhs) ? lhs : rhs;
    }
      
    inline
    decltype(auto)
    min(TestScore& lhs, TestScore& rhs) noexcept
    {
        return const_cast<decltype(lhs)>(__min_impl(lhs, rhs));
    }

    inline
    decltype(auto)
    min(const TestScore& lhs, const TestScore& rhs) noexcept
    {
        return __min_impl(lhs, rhs);
    }

    inline
    decltype(auto)
    __max_impl(const TestScore& lhs, const TestScore& rhs) noexcept
    {
        return &min(lhs, rhs) == &lhs ? rhs : lhs;
    }

    inline
    decltype(auto)
    max(TestScore& lhs, TestScore& rhs) noexcept
    {
        return const_cast<decltype(lhs)>(__max_impl(lhs, rhs));
    }

    inline
    decltype(auto)
    max(const TestScore& lhs, const TestScore& rhs) noexcept
    {
        return __max_impl(lhs, rhs);
    }

    inline
    decltype(auto)
    __median_of_three_impl(const TestScore& a, const TestScore& b,
                           const TestScore& c) noexcept
    {
        return max(min(a, b), min(b, c));
    }

    inline
    decltype(auto)
    median_of_three(TestScore& a, TestScore& b,
                    TestScore& c) noexcept
    {
        return const_cast<decltype(a)>(
          __median_of_three_impl(a, b, c));
    }

    inline
    decltype(auto)
    median_of_three(const TestScore& a, const TestScore& b,
                    const TestScore& c) noexcept
    {
        return __median_of_three_impl(a, b, c);
    }
    ```


## Reference

- Scott Meyers, 『Effective C++』, 곽용재 옮김, (3판, 프로텍미디어, 2015)
- Scott Meyers, 『Effective Modern C++』, 류광 옮김, (인사이트, 2015)