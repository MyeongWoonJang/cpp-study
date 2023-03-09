```
@brief m x n 크기의 픽셀 행렬 $ASCIIConverter::src를 p x q 크기의 아스키문자 행렬 R로 변환한다.
    임의의 행렬 A에 대한 i행 j열 원소를 A<i, j>라 하고,
    |$ASCIIConverter::src|<i, j>
    = { { $ASCIIConverter::src<u, v> | ⌊ u / (m/p) ⌋ = i } | ⌊ v / (n/q) ⌋ = j }라 할 때,
    m/p x m/q 픽셀 행렬을 입력으로 받고 한 개의 아스키문자를 출력하는 변환함수 f에 대하여
    R<i, j> = f( |$ASCIIConverter::src|<i, j> )를 만족한다.
@use $ASCIIConverter::src ASCII 문자로 변환할 픽셀 행렬
@return $ASCIIConverter::src를 아스키아트로 변환한 행렬, 이때 변환된 행렬의 해상도는
    $ASCIIConverter::resolution을 따른다.
ASCIIConverter::convert():
    
```