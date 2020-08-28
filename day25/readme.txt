셋업 실행하기 
python ex02_setup.py build_ext --inplace

셋업파일이 DLL(pyd) 파일을 만들어 줍니다.

python 인터프리터에서 실행하기

import _ex02
print(_ex02.__doc__)
_ex02.hello()


opencv vs2019

프로잭트속성->vc++ 디랙토리 -> 포함디랙토리 -> opencv압푹푼디랙토리/include
예> C:\Users\User\Desktop\mywork\opencv\build\include

프로잭트속성->vc++ 디랙토리 -> 라이브러리 디랙토리 -> 라이브러리 경로 추가
예> C:\Users\User\Desktop\mywork\opencv\build\x64\vc15\lib

프로잭트속성->링커->추가 종속성-> 라이브러리 파일추가
예> opencv_world440.lib opencv_world440d.lib

텐서 프로우

설치 : pip install tensorflow

xor
0 0 0
1 0 1
0 1 1
1 1 0