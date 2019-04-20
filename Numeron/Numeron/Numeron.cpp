/**
* @file Numeron.cpp
* @brief Numeronのソースファイル
* @author shion-sagawa
*/

#include<stdio.h>  //printf関数、scanf_s関数に使う
#include<stdlib.h> //srand関数、rand関数に使う
#include<time.h>   //time関数に使う

int main()
{
	//ゲーム説明を提示
	printf("\n\t＜　ヌメロン　＞\n\n");
	printf(" ゲーム説明  :  コンピュータがランダムで選んだ3桁の数字を当てるゲーム。\n\t\tまずプレイヤーは相手の数字を予想して3桁の数字を入力してください。\n\t\tただし、「同じ数字」または「数字以外」は入力しないでください。\n\t\tその提示した3桁の数字をもとにヒントが出される。\n\t\tそれをもとに正解を導こう。\n\n");

	//hun(百の位),ten(十の位),one(一の位)
	int hun, ten, one;

	//同じ乱数パターンにならないように、時間から乱数の種を作る
	srand((unsigned int)time(NULL));

	while (true)
	{
		hun = rand() % 10;
		ten = rand() % 10;
		one = rand() % 10;

		//被っている数字がなくなるまで繰り返す
		if (hun == ten || ten == one || one == hun)
		{
			continue;
		}
		else
		{
			break;
		}
	}

	while (true) {


		//player number hundred,player number ten,player number oneの略称
		int pnh, pnt, pno;
		int playerNumber;
		scanf_s("%3d", &playerNumber);

		//playerNumberを百の位、十の位、一の位と分ける計算式
		pnh = playerNumber / 100;
		pnt = playerNumber % 100 / 10;
		pno = playerNumber % 10;

		//scanf_sで入力した文字が０１２～９８７の間以外、または同じ数字を２回以上使うと繰り返す
		if (playerNumber < 12 || playerNumber > 987 || pnh == pnt || pnh == pno || pnt == pno)
		{
			printf("入力が間違っています。\n\n");
			continue;
		}


		//何ターン目かを保存する、後で何ターンで成功できたかを知らせるため
		static int turnResult = 0;
		turnResult++;

		//イートの数を求める
		int eat = 0;
		if (pnh == hun) eat++;
		if (pnt == ten) eat++;
		if (pno == one) eat++;
		//バイトの数を求める
		int byte = 0;
		if (pnh == ten || pnh == one) byte++;
		if (pnt == hun || pnt == one) byte++;
		if (pno == hun || pno == ten) byte++;

		//何イート何バイトかの結果を知らせる
		printf("→　%dイート　%dバイト　\n", eat, byte);

		//正解していたら終了
		if (eat == 3)
		{
			printf("おめでとう！！　正解です！！\n");
			printf("%dターンで正解を導けたね！！", turnResult);
			break;
		}
		else
		{
			//正解以外は繰り返す
			continue;
		}
	}

	while (true);
	return 0;
}
