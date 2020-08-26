vs2019 SDL 설정법

1. sdl 싸이트에서 vc용 개발 툴킷을 내려받는다 => 확장 라이브러리 ttf image mixer 도 같이 받는다.
2. 콘솔 어플리 캐이션으로 프로잭트 생성

3. '프로잭트속성-> vc++디랙토리-> 포함디랙토리' 에 헤더파일 경로를 설정한다.
예>C:\Users\User\Desktop\mywork\SDL2-2.0.12\include
4. '프로잭트속성-> vc++디랙토리-> 라이브러리디랙토리' 에 라이브러리 경로를 설정한다.
예>C:\Users\User\Desktop\mywork\SDL2-2.0.12\lib\x86

5. '프로잭트속성->링커->입력-> 추가 종속성' 에 라이브러리 파일추가 
(SDL2.lib,SDL2main.lib,SDL2_image.lib,SDL2test.lib,SDL2_ttf.lib,SDL2_mixer.lib)


6. 만약 컴파일하는중에 4996 에러가 뜨면 '프로잭트속성->c++ -> 특정경고사용안함' 4996 추가

