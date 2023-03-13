```
***
@use $Sampler::src 샘플링할 원본 행렬
@use $Sampler::context 샘플링 방법을 서술한 매개변수 객체
    [srcRegion: 참조할 원본 영역
        [beginRow: 시작행
         beginCol: 시작열
         endRow: 끝행
         endCol: 끝열]
     rowStride: $return의 한 행으로 덮을 수 있는 $Sampler::src의 행 수
     colStride: $return의 한 열로 덮을 수 있는 $Sampler::src의 열 수
     bRepeat: $srcRegion의 외부 참조 시 반복 확장 해석 여부
     bInterpolation: 겹선형보간 여부
     resRow: $return의 행 수
     resCol: $return의 열 수
     clearValue: ${bRepeat} == true일 경우 $srcRegion의 외부 참조 시 출력할 값]
@return $Sampler::src를 $Sampler::context에 따라 샘플링한 행렬
@pre $Sampler::src != null
***
Sampler::sample() -> Matrix:
    Create resRow x resCol Matrix, res
    # indices are zero-base
    for each pixel(i, j) in res:
         refRow := beginRow + (i-1) * rowStride
         refCol := beginCol + (j-1) * colStride
         
         if refRow > endRow:
            if bRepeat is true:
                refRow := { (refRow - beginRow) mod (endRow - beginRow) } + beginRow
            else:
                pixel(i, j) := clearValue
                continue to next loop
                
         if refCol > endCol:
            if bRepeat is true:
                refCol := { (refCol - beginCol) mod (endCol - endCol) } + beginCol
            else:
                pixel(i, j) := clearValue
                continue to next loop
         
         if bInterpolation is true:
            pixel(i, j) := linear interpolation of range
                [refRow - rowStride/2, refRow + rowStride/2]
                [refCol - colStride/2, refCol + colStride/2]
                in src
         else:
            pixel(i, j) := closest pixel of range
                [refRow - rowStride/2, refRow + rowStride/2]
                [refCol - colStride/2, refCol + colStride/2]
                in src
    return res

Sampler::setSrc(ref Matrix src):
    Sampler::src := src

Sampler::setContext(SampleContext context):
    Sampler::context := context
```

```
***
@brief RGB행렬을 회색조로 변환한다.
    사용할 회색조 변환 알고리즘은 $gsm에 의해 결정된다.
@use $GrayScaler::src 회색조로 변환할 원본 행렬
@use $GrayScaler::gsm 사용할 회색조 변환 알고리즘을 나타내는 식별자
@return 회색조로 변환된 RGB행렬
***
GrayScaler::grayScale() -> Matrix:
    Create res as copy of src
    for each pixel in res:
        set pixel's value via the algorithm specified by gsm.
    return res
    
***
////
아래의 함수들은 GrayScaler::grayScale에서 각 픽셀의 값을 결정하는 데 사용되는 알고리즘들이다.
https://tannerhelland.com/2011/10/01/grayscale-image-algorithm-vb6.html
위 링크에서 알고리즘을 차용했다.
////
***

GrayScaler::averaging(Pixel p) -> Pixel:
    gray := average value of p's RGB
    return Pixel [R: gray, G: gray, B: gray]

GrayScaler::luma(Pixel p) -> Pixel:
    return lumaBT601(p)
    
GrayScaler::lumaBT709(Pixel p) -> Pixel:
    gray := p.R * 0.2126 + p.G * 0.7152 + p.B * 0.0722
    return Pixel [R: gray, G: gray, B: gray]

GrayScaler::lumaBT601(Pixel p) -> Pixel:
    gray := p.R * 0.299 + p.G * 0.587 + p.B * 0.114
    return Pixel [R: gray, G: gray, B: gray]
    
GrayScaler::desaturation(Pixel p) -> Pixel:
    mx = max value of { p.R, p.G, p.B }
    mn = min value of { p.R, p.G, p.B }
    gray := (mx + mn) / 2
    return Pixel [R: gray, G: gray, B: gray]

GrayScaler::maxDecomposition(Pixel p) -> Pixel:
    gray := max value of { p.R, p.G, p.B }
    return Pixel [R: gray, G: gray, B: gray]

GrayScaler::minDecomposition(Pixel p) -> Pixel:
    gray := min value of { p.R, p.G, p.B }
    return Pixel [R: gray, G: gray, B: gray]

GrayScaler::rOnly(Pixel p) -> Pixel:
    return Pixel [R: p.R, G: p.R, B: p.R]
    
GrayScaler::gOnly(Pixel p) -> Pixel:
    return Pixel [R: p.G, G: p.G, B: p.G]
    
GrayScaler::bOnly(Pixel p) -> Pixel:
    return Pixel [R: p.B, G: p.B, B: p.B]
```