#include "Matrix.h"

int main()
{
    auto input_stream = ifstream("matrix1");
    //auto m_first = Matrix<int64_t>(input_stream);
    //m_first.show();
    Matrix<int64_t>* m_array[2];
    m_array[0] = new Matrix<int64_t>(input_stream);

    try
    {
        m_array[1] = new Matrix<int64_t>(*m_array[0] * 3);

        m_array[0]->show();
        m_array[1]->show();

        cout << endl << m_array[0]->column_sum(0) << ' ' << m_array[1]->column_sum(0) << endl;

        auto output_stream = ofstream("matrix2");
        output_stream << *m_array[1];
    }
    catch(const std::exception& e)
    {
        std::cerr << "что-то сломалосб" << endl;
        std::cerr << e.what() << '\n';
    }    

    delete m_array[0];
    delete m_array[1];
    cout << sizeof(Matrix<int64_t>);
}

