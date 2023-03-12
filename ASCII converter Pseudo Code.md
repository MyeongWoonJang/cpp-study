## Convert

픽셀 행렬을 받아 아스키아트로 변환하는 알고리즘이다.   

<div align="center"><img src="https://user-images.githubusercontent.com/73771162/224539502-87517c38-37ef-4779-b43d-e9a61ed35849.png"></div>

- precondition: rows(M) > c<sub>1</sub>y, cols(M) > c<sub>2</sub>x (c<sub>1</sub>과 c<sub>2</sub>는 구현 중 적절한 값을 결정)
- M: 원본 픽셀 행렬
- C: 후보 문자 집합
- x: 변환된 아스키아트가 가질 x축 방향 해상도
- y: 변환된 아스키아트가 가질 y축 방향 해상도
- rows(M): M의 행 수를 반환하는 함수
- cols(M): M의 열 수를 반환하는 함수
- R<sub>ij</sub>: M을 r * c 크기의 부분행렬들로 분할했을 때 i행 j열의 부분행렬
- L = (l<sub>ij</sub>): R<sub>ij</sub>를 가장 잘 표현하는 아스키 문자들의 행렬, 해상도는 x * y
- METRIC(A, B): 두 행렬 A, B 사이의 거리를 나타내는 어떤 함수
- RENDER(A): 아스키 문자를 r * c 크기의 픽셀 행렬로 그리는 함수

> 이미지의 픽셀과 아스키 문자는 일대일로 대응되지 않는다.    
> n개의 픽셀이 1개의 아스키 문자로 대응되는 n:1 관계를 가져야 적절한 아스키아트를 만들 수 있다.   
> 따라서 M을 (R<sub>ij</sub>)로 표현하여 R<sub>ij</sub> (r x c 행렬)을 1개의 아스키 문자로 변환하는 것으로,   
> x * y 해상도의 아스키 문자 행렬을 얻는다.