#include "matrix.hpp"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <filename>\n";
        return 1;
    }
    
    try {
        auto [matrix1, matrix2] = Matrix::load_from_file(argv[1]);
        
        std::cout << "Matrix 1:\n";
        matrix1.print_matrix();
        std::cout << "\nMatrix 2:\n";
        matrix2.print_matrix();
        
        std::cout << "\nMatrix 1 + Matrix 2:\n";
        (matrix1 + matrix2).print_matrix();
        
        std::cout << "\nMatrix 1 * Matrix 2:\n";
        (matrix1 * matrix2).print_matrix();
        
        std::cout << "\nSum of Matrix 1 Major Diagonal: " << matrix1.sum_diagonal_major() << '\n';
        std::cout << "Sum of Matrix 1 Minor Diagonal: " << matrix1.sum_diagonal_minor() << "\n\n";
        
        std::cout << "Swapping rows 0 and 1 in Matrix 1:\n";
        matrix1.swap_rows(0, 1);
        matrix1.print_matrix();
        
        std::cout << "\nSwapping columns 0 and 1 in Matrix 1:\n";
        matrix1.swap_cols(0, 1);
        matrix1.print_matrix();
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << '\n';
        return 1;
    }
    
    return 0;
}
