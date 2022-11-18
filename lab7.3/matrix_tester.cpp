#include "Matrix.h"

int main()
{
    auto input_stream = ifstream("matrix1");
    auto m_first = Matrix<int64_t>(input_stream);
    cout << m_first;
    try
    {
        auto m_second = m_first * m_first;
        m_second.show();
        m_second += m_second;
        m_second = m_first;
        cout << m_second << m_first;

        auto m_third = Matrix<int64_t>(7, 7);
        cout << m_third;
        m_third = m_second;
        cout << m_third;

        auto second_input_stream = ifstream("matrix2");
        second_input_stream >> m_third;
        cout << m_third;
        m_third *= 26;
        cout << m_third;
        m_third = -m_third;
        m_third.show();
    }
    catch(const std::exception& e)
    {
        std::cerr << "что-то сломалосб" << endl;
        std::cerr << e.what() << '\n';
    }    
}

