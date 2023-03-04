```
@param src 샘플링할 원본 행렬
@param context 샘플링 방법을 서술한 매개변수 객체
    [srcRegion: 참조할 원본 영역, (시작행, 시작열, 끝행, 끝열)
     bRepeat: $srcRegion의 외부 참조 시 반복 확장 해석 여부
     bInterpolation: 겹선형보간 여부
     resRow: $return의 행 수
     resCol: $return의 열 수
     clearValue: ${bRepeat} == true일 경우 $srcRegion의 외부 참조 시 출력할 값]
@return $src를 회색조로 샘플링한 행렬
@pre $src != null
Sampler::graySample(ref Matrix src, GraySampleContext context) -> Matrix:

Sampler::sample(ref Matrix src, ColorSampleContext context) -> Matrix:

Sampler::stretch() -> Matrix:

Sampler::postManipulate(ref Matrix stretched, int row, int col) -> ref Matrix:
```