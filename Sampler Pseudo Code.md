```
@param src 샘플링할 원본 행렬
@param context 샘플링 방법을 서술한 매개변수 객체
    [beginRow: $src로부터 처음으로 읽을 행
     beginCol: $src로부터 처음으로 읽을 열
     stride: $src의 한 픽셀에 대한 $return의 한 픽셀의 길이 비
     endRow: $src로부터 마지막으로 읽을 행 + 1
     endCol: $src로부터 마지막으로 읽을 열 + 1
     bRepeat: 
     bInterpolation:
     resRow:
     resCol:]
@return: 회색조로 샘플링된 행렬
Sampler::graySample(ref Matrix src, SampleContext context) -> Matrix:

Sampler::stretch() -> Matrix:

Sampler::postManipulate(ref Matrix stretched, int row, int col) -> ref Matrix:
```