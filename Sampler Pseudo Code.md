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
                
@use $Sampler::sample()
@param gsm RGB 픽셀을 회색조 픽셀로 변환하는데 사용할 알고리즘
@return $Sampler::sample()을 회색조로 변환한 행렬
Sampler::graySample(GrayScaleMethod gsm) -> Matrix:
    res := sample()
    for each pixel(i, j) in res:
        make pixel(i, j) gray
    return res

Sampler::setSrc(ref Matrix src):
    Sampler::src := src

Sampler::setContext(SampleContext context):
    Sampler::context := context
```