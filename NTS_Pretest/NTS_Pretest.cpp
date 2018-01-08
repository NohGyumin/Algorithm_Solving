
// 2018 NTS �������� SW ���ߺι� Pre-test
// ������ : ��Թ�
// ���ϸ� : Pretest.cpp
// OS : Windows10
// ��� ��� : C++
// IDE : Visual Studio 2015

// ������ : �����ڸ� �̻��̸鼭 ����1 ������ �ڸ����� ����
// (�� : 10000 - �ϸ�X ��O,   30100 - �︸�Ϲ�X, �︸��O,   1 - ��O)

#include <cstdio>
#include <string>
using namespace std;

string Su[10] = { "","��","��","��","��","��","��","ĥ","��","��" }; // �� �迭
string Jari[5] = { "","��","��","õ","��" };  // �ڸ� �迭

string Solve(int Num) //�Է� ���ڸ� �ѱ� �������� ��ȯ
{
	string result = ""; // ���ϰ�
	string temp[5];		// �ӽ� ���� �迭(����ó�� Ȱ��)
	int i;
	for (i = 0; i < 5 && Num > 0; i++) // ���ڸ��� ����, Num�� �����Ҷ����� (�ᱹ i�� �ڸ���)
	{
		int n = Num % 10;
		if (n != 1 || i == 0) // n�� �����ڸ� �̻��̸鼭 '��' �����̸� ���� ���� �߰� ����
		{
			temp[i] = Su[n];
		}
		if (n != 0)   // ���� 0�� ��쿡�� �ڸ��� ���� ����
		{
			temp[i] += Jari[i];
		}
		Num /= 10; // ���� �ڸ��� ��Ŀ�� �̵�
	}
	while (i--) // �ڸ�����ŭ
	{
		result += temp[i]; // ����� �������� ����
	}
	return result; // ����� ����
}

int main()
{
	int T, Num;
	scanf("%d", &T);  // �׽�Ʈ ���� �Է�
	for (int TC = 1; TC <= T; TC++)
	{
		scanf("%d", &Num);  // ���� �Է� (1~99999)
		printf("%s\n\n", Solve(Num).c_str()); // ���� ��� 
	}
}