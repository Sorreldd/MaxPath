#include <iostream>

using namespace std;
const int MAXN = 1000;

int u, v, ans = 0, n, m, g[MAXN][MAXN], use[MAXN][MAXN];

void findPath(int x, int ln) {
    ans = max(ans, ln); // выбираем максимальный путь
    for(int i = 0; i < n; i++) {
        if(g[x][i] && use[x][i] == false) { // если есть ребро и не использовали его
            use[x][i] = use[i][x] = true; //то говорим, что теперь используем(чтобы снова его не взять) из x в i и обратное
            findPath(i, ln + 1); // запускаем поиск пути от вершины i
            use[x][i] = use[i][x] = false; // говорим, что ребро снова можно использовать
        }
    }
}
//НОМЕРА ВЕРШИН ВВОДИТЬ С 1
int main() {
    cin >> n >> m; // количество вершин, количество ребер
    for(int i = 0; i < m; i++) {
        cin >> u >> v; // считываем ребро
        --u; --v; // Уменьшаем, так как вводятся с 1
        g[u][v] = g[v][u] = 1; // матрица смежности
    }
    for(int i = 0; i < n; i++) { // перебираем вершинку начала пути
        findPath(i, 0); // запускаем рекурсию от вершины i и длину 0
    }
    cout << ans;
    return 0;
}
