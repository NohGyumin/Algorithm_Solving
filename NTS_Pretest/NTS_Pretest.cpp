
// 2018 NTS 동계인턴 SW 개발부문 Pre-test
// 지원자 : 노규민
// 파일명 : Pretest.cpp
// OS : Windows10
// 사용 언어 : C++
// IDE : Visual Studio 2015

// 재정의 : 십의자리 이상이면서 숫자1 발음은 자리수만 발음
// (예 : 10000 - 일만X 만O,   30100 - 삼만일백X, 삼만백O,   1 - 일O)

#include <cstdio>
#include <string>
using namespace std;

string Su[10] = { "","일","이","삼","사","오","육","칠","팔","구" }; // 수 배열
string Jari[5] = { "","십","백","천","만" };  // 자리 배열

string Solve(int Num) //입력 숫자를 한글 구음으로 변환
{
	string result = ""; // 리턴값
	string temp[5];		// 임시 저장 배열(스택처럼 활용)
	int i;
	for (i = 0; i < 5 && Num > 0; i++) // 만자리수 까지, Num이 존재할때까지 (결국 i는 자리수)
	{
		int n = Num % 10;
		if (n != 1 || i == 0) // n이 십의자리 이상이면서 '일' 발음이면 숫자 발음 추가 안함
		{
			temp[i] = Su[n];
		}
		if (n != 0)   // 수가 0인 경우에는 자리수 발음 생략
		{
			temp[i] += Jari[i];
		}
		Num /= 10; // 다음 자리로 포커스 이동
	}
	while (i--) // 자리수만큼
	{
		result += temp[i]; // 결과값 역순으로 저장
	}
	return result; // 결과값 리턴
}

int main()
{
	int T, Num;
	scanf("%d", &T);  // 테스트 개수 입력
	for (int TC = 1; TC <= T; TC++)
	{
		scanf("%d", &Num);  // 숫자 입력 (1~99999)
		printf("%s\n\n", Solve(Num).c_str()); // 숫자 출력 
	}
}