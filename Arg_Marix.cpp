#include <vector>
#include <utility>

std::pair<size_t, size_t> MatrixArgMax(const std::vector<std::vector<int>>& matrix){

    int max = matrix[0][0];
    std::pair<size_t, size_t> pozition = {0, 0};
    for(size_t i = 0; i < matrix.size(); ++i){
        for(size_t j = 0; j < matrix[i].size(); ++j){
            if(matrix[i][j] > max){
                max = matrix[i][j];
                pozition.first = i;
                pozition.second = j;
            }
        }
    }
    return pozition;
}