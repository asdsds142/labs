#include "Matrix.h"

int main()
{
    Matrix<int64_t> m_first = Matrix<int64_t>(cin);
    m_first.show();

    try
    {
        Matrix<int64_t> m_second = m_first * m_first;
        m_second.show();
    }
    catch(const std::exception& e)
    {
        std::cout << "что-то сломалосб" << endl;
        std::cerr << e.what() << '\n';
    }
    
    

}