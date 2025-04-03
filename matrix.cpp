
#include "matrix.hpp"

Matrix::Matrix(std::size_t N) : N(N), data(N, std::vector<int>(N, 0)) {}

Matrix::Matrix(std::vector<std::vector<int>> nums) : N(nums.size()), data(std::move(nums)) {}

std::pair<Matrix, Matrix> Matrix::load_from_file(const std::string &filename) {
    std::ifstream file(filename);
    if (!file) {
        throw std::runtime_error("Error opening file");
    }
    
    std::size_t N;
    file >> N;
    std::vector<std::vector<int>> mat1(N, std::vector<int>(N));
    std::vector<std::vector<int>> mat2(N, std::vector<int>(N));
    
    for (auto &row : mat1) for (auto &val : row) file >> val;
    for (auto &row : mat2) for (auto &val : row) file >> val;
    
    return {Matrix(mat1), Matrix(mat2)};
}

Matrix Matrix::operator+(const Matrix &rhs) const {
    std::vector<std::vector<int>> result(N, std::vector<int>(N));
    for (std::size_t i = 0; i < N; ++i)
        for (std::size_t j = 0; j < N; ++j)
            result[i][j] = data[i][j] + rhs.data[i][j];
    return Matrix(result);
}

Matrix Matrix::operator*(const Matrix &rhs) const {
    std::vector<std::vector<int>> result(N, std::vector<int>(N, 0));
    for (std::size_t i = 0; i < N; ++i)
        for (std::size_t j = 0; j < N; ++j)
            for (std::size_t k = 0; k < N; ++k)
                result[i][j] += data[i][k] * rhs.data[k][j];
    return Matrix(result);
}

void Matrix::set_value(std::size_t i, std::size_t j, int n) { data[i][j] = n; }

int Matrix::get_value(std::size_t i, std::size_t j) const { return data[i][j]; }

std::size_t Matrix::get_size() const { return N; }

int Matrix::sum_diagonal_major() const {
    int sum = 0;
    for (std::size_t i = 0; i < N; ++i)
        sum += data[i][i];
    return sum;
}

int Matrix::sum_diagonal_minor() const {
    int sum = 0;
    for (std::size_t i = 0; i < N; ++i)
        sum += data[i][N - i - 1];
    return sum;
}

void Matrix::swap_rows(std::size_t r1, std::size_t r2) { std::swap(data[r1], data[r2]); }

void Matrix::swap_cols(std::size_t c1, std::size_t c2) {
    for (std::size_t i = 0; i < N; ++i)
        std::swap(data[i][c1], data[i][c2]);
}

void Matrix::print_matrix() const {
    for (const auto &row : data) {
        for (int val : row)
            std::cout << std::setw(4) << val;
        std::cout << '\n';
    }
}
