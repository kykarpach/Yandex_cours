#include<iostream>
#include<vector>

int main(){

    int m,n,k;
    std::cin >> m >> n >> k;
    std::vector<std::vector<int>> field(m, std::vector<int>(n));
    
    for(auto d = 0; d < k; ++d){
        int x,y;
        std::cin >> x >> y;
        field[x-1][y-1] = 9;
    }
    // Теперь надо добавить к каждому числу вокруг мины 1 за одну мину
    for(int i = 0; i < m ; ++i){
        for(int j = 0; j < n; ++j){

            int help = 0;

            // Проверка на попадане в ячайку с миной
            if(field[i][j] == 9){
                continue;
            }   

            // Проверка все 8 ячеек вокруг
            for(int di = -1; di <= 1; ++di){
                for(int dj = -1; dj <= 1; ++dj){

                    int ni = i + di;
                    int nj = j + dj;

                    if(ni >= 0 && ni < m && nj >= 0 && nj < n && field[ni][nj] == 9){
                        ++help;
                    }
                }               
            }

            field[i][j] = help;

        }
    }

    // Печать поля
    for(size_t i = 0; i < field.size(); ++i) {
        for(size_t j = 0; j < field[i].size(); ++j) {
            if(j != 0) {
                std::cout << ' ';
            }
            if(field[i][j] == 9) {
                std::cout << '*';
            } else {
                std::cout << field[i][j];
            }
        }
        std::cout << '\n';
    }
}