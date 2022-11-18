#include <iostream>
#include <queue>
#include <stack>
using namespace std;
int main() {//ввод начат
	int n, u, t; cin >> n;
	int** a = new int* [n];
	stack <int> way; //стек, чтобы проще было перевернуть путь (тк поиск будет из конечной в начальную) 
	int* visited = new int[n];
	for (int i = 0; i < n; i++) {
		visited[i] = -1;
		a[i] = new int[n];
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	cin >> u >> t;
	u--;
	t--;
  //ввод закончен
  //сам bfs
	queue <int> q; //создать очередь, чтобы понимать в каком порядке мы обходим вершины
	q.push(u); //начать с заданной вершины
	visited[u] = u;
	while (!q.empty()) { //цикл, пока все вершины не пройдены
		int v = q.front();
		q.pop(); //достать первый элемент из очереди
		for (int i = 0; i < n; i++) { //пройти по строке этого элемента
			if (a[v][i] != 0 && visited[i] == -1) { //если есть ребро и вершина не посещена
				q.push(i); 
				visited[i] = v; //чтобы потом было проще искать путь
			}
		}
	}
	
	int v = t, counter = 0, nope = -1; 
	way.push(t);
	for (int i = 0; i < n; i++) {
		if (visited[i] == -1 && (u == i || t == i)) { //поиск в массиве visited вершину, в которую нельзя добраться (защита от бесконечного цикла)
			nope = i;
		}
	}
	while (v != u && u != nope && t != nope) { //цикл, пока не попадется вершина из которой вышел поиск
		int temp = v;
		v = visited[temp];
		way.push(v); //добавление в стек
		counter++;
	}
	if (t == u) { //всяческие проверки
		cout << 0;
	} else if (counter == 0) {
		cout << -1;
	}
	else { //проверки пройдены, вывод
		cout << counter << endl;
		while (!way.empty()) {
			cout << way.top() + 1 << ' ';
			way.pop();
		}
	}
	return 0;
}
