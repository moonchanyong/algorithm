// codeground_battery
/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <iostream>
#include <malloc.h>
using namespace std;

float Answer;
float absi(float a)
{
	if (a < 0)
		return -a;
	else
		return a;
}
struct point
{
	float x;
	float y;
	int check = 0;
	point(float a, float b)
	{
		x = a;
		y = b;
	}
	point(float a, float b, int c)
	{
		x = a;
		y = b;
		check = c;
	}
	point() {
		x = -1;
		y = -1;
	}

};
struct line
{
	int p1x = -1;
	int p1y = -1;
	int p2x = -1;
	int p2y = -1;
	char check;
	float distance(float x, float y) // 거리구하는 함수 
	{
		// 가까운점 지정 
		if (absi(p1x - x) + absi(p1y - y) > absi(p2x - x) + absi(p2y - y)) // p1이 더 멀어서 p2가 더 가까울때 			
																		   // 거리 계산 
		{
			if (absi(p2x - x) > absi(p2y - y))
			{
				check = 'x';
				return absi(p2x - x);

			}
			else
			{
				check = 'y';
				return absi(p2y - y);
			}
		}
		else
			// 거리 계산 
			if (absi(p1x - x) > absi(p1y - y))
			{
				check = 'x';
				return absi(p1x - x);
			}
			else
			{
				check = 'y';
				return absi(p1y - y);
			}


	}

};


struct queue_node {
	point data;

	queue_node* next;
};

struct queue {
	queue_node* front;
	queue_node* rear;
	int sz;
	queue() {
		front = rear = NULL;
		sz = 0;
	}

};
int queue_size(queue &q) {
	return q.sz;
}
bool queue_empty(queue &q) {
	return queue_size(q) == 0;
}
void queue_enqueue(queue& q, point val) {
	queue_node *newNode = (queue_node*)malloc(sizeof(queue_node));
	newNode->data = val;
	newNode->next = 0;
	q.sz++;
	if (q.rear == NULL && q.front == NULL) {
		q.rear = q.front = newNode;
		return;
	}
	q.rear->next = newNode;
	q.rear = newNode;
}
void queue_dequeue(queue& q) {
	if (queue_empty(q))
		return;
	queue_node *nextHead = q.front->next;
	free(q.front);
	if (q.front == q.rear) q.front = q.rear = 0;
	q.front = nextHead;
	q.sz--;
}
point queue_front(queue& q) {

	return q.front->data;
}

int main(int argc, char** argv)
{
	int T, test_case;
	/*
	The freopen function below opens input.txt file in read only mode, and afterward,
	the program will read from input.txt file instead of standard(keyboard) input.
	To test your program, you may save input data in input.txt file,
	and use freopen function to read from the file when using cin function.
	You may remove the comment symbols(//) in the below statement and use it.
	Use #include<cstdio> or #include <stdio.h> to use the function in your program.
	But before submission, you must remove the freopen function or rewrite comment symbols(//).
	*/

	// freopen("input.txt", "r", stdin);

	cin >> T;
	for (test_case = 0; test_case < 15; test_case++)
	{

		queue q;
		line lines[100];
		Answer = 199999999;
		/////////////////////////////////////////////////////////////////////////////////////////////

		int startx = 100000000;
		int starty = 100000000;
		int n = 0;
		cin >> n; // 선분 개수 
		for (int i = 0; i < n; i++)
		{

			cin >> lines[i].p1x >> lines[i].p1y >> lines[i].p2x >> lines[i].p2y;
			if (lines[i].p1x < startx)
				startx = lines[i].p1x;
			if (lines[i].p2x < startx)
				startx = lines[i].p2x;
			if (lines[i].p1y < starty)
				starty = lines[i].p1x;
			if (lines[i].p2y < starty)
				starty = lines[i].p2y;


		} // 입력부 종료 

		point temp;
		temp.x = startx;
		temp.y = starty;
		temp.check = 1;
		char check;
		queue_enqueue(q, temp);

		while (!queue_empty(q))
		{

			float tempdis = 0; //최대전원거리 일시값 
			temp = queue_front(q);
			queue_dequeue(q);

			// 이 지점에서 최대전원거리 구하기 
			for (int i = 0; i < n; i++)
			{
				if (tempdis < lines[i].distance(temp.x, temp.y)) // 최대전원거리 tempdis에 저장 
				{
					tempdis = lines[i].distance(temp.x, temp.y);
					check = lines[i].check;
				}
			}

			if (Answer >= tempdis) // 다른거보다 작다면 
			{
				Answer = tempdis;
				if (check == 'x')
					queue_enqueue(q, point(temp.x + 0.5, temp.y));
				else if (check == 'y')
					queue_enqueue(q, point(temp.x, temp.y + 0.5));
			}

		}


		/////////////////////////////////////////////////////////////////////////////////////////////

		// Print the answer to standard output(screen).
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}



	return 0;//Your program should return 0 on normal termination.
}