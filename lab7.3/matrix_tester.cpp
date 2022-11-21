#include "Matrix.h"

int main()
{
    auto input_stream = ifstream("matrix1");
    auto m_first = Matrix<int64_t>(input_stream);
    m_first.show();
    try
    {
        auto m_second = m_first * m_first;

        m_first.show();
        m_second.show();

        auto second_input_stream = ifstream("matrix2");

        cout << endl << m_second.column_sum(0) << ' ' << m_first.column_sum(0) << endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "что-то сломалосб" << endl;
        std::cerr << e.what() << '\n';
    }    
}

