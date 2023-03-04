```
@param src 샘플링할 원본 행렬
@param context 샘플링 방법을 서술한 매개변수 객체
    [srcRegion: 
     bRepeat: 
     bInterpolation:
     resRow:
     resCol:]
@return: 회색조로 샘플링된 행렬
Sampler::graySample(ref Matrix src, SampleContext context) -> Matrix:

Sampler::stretch() -> Matrix:

Sampler::postManipulate(ref Matrix stretched, int row, int col) -> ref Matrix:
```