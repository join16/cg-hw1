
# CG Homework 1

## 2013147544 조인

1. 프로젝트 설명

	* src/lib/: custom classes
	* src/main.cpp: 처음에 제공된 main.cpp 탬플릿
	* build/: 중간 컴파일 결과물들이 생김
	* output: executable
	* CMakeLists.txt, bin/output: cmake 기반의 빌드파일.

2. 실행방법

	- Makefile 사용:

		* make: 컴파일 후 실행
		* make clean: 컴파일 결과물 삭제 (build/)
		* make output: executable 컴파일

	- cmake 사용:
		* cmake가 설치되어 있을 경우 사용
		* bin/output: 컴파일 후 실행 (build/ 에 컴파일 결과물 생김)

3. 비고
    + gcc 컴파일러 기준으로 작성됨.
    + OS X 기준으로 library link 적용함. Linux 및 기타 운영체제에서 돌릴 시 문제가 발생할 수 있습니다.