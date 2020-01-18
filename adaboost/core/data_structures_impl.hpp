#ifndef ADABOOST_CORE_DATA_STRUCTURES_IMPL_HPP
#define ADABOOST_CORE_DATA_STRUCTURES_IMPL_HPP

#include<cassert>

#define check(exp, msg) assert(((void)msg, exp))

namespace adaboost
{
    namespace core
    {
        template <class data_type_vector>
        Vector<data_type_vector>::Vector()
        {}

        template <class data_type_vector>
        data_type_vector*
        Vector<data_type_vector>::_reserve_space(unsigned int _size)
        {
            check(_size > 0,
            "The size of the vector should be positive.");
            data_type_vector* pointer = new data_type_vector[_size];
            return pointer;
        }

        template <class data_type_vector>
        Vector<data_type_vector>::Vector(unsigned int _size):
        data(_reserve_space(_size)),
        size(_size)
        {
        }

        template <class data_type_vector>
        void Vector<data_type_vector>::
        product(const Vector<data_type_vector>& vec, data_type_vector& result)
        {
            result = 0;
            for(unsigned int i = 0; i < vec.get_size(); i++)
            {
                result += (this->at(i)*vec.at(i));
            }
        }

        template <class data_type_vector>
        void Vector<data_type_vector>::
        product(const Matrix<data_type_vector>& mat,
                Vector<data_type_vector>& result)
        {
            for(unsigned int j = 0; j < mat.get_cols(); j++)
            {
                result[j] = 0;
                for(unsigned int i = 0; i < mat.get_rows(); i++)
                {
                    result[j] += (this->at(i)*mat.at(i, j));
                }
            }
        }

        template <class data_type_vector>
        data_type_vector Vector<data_type_vector>::
        at(unsigned int index)
        {
            check(index > 0 && index < this->_size,
                          "Index out of range.");
            return this->data[index];
        }

        template <class data_type_vector>
        void Vector<data_type_vector>::
        set(data_type_vector value, unsigned int index)
        {
            check(index > 0 && index < this->_size,
                          "Index out of range.");
            this->data[index] = value;
        }

        template <class data_type_vector>
        unsigned int Vector<data_type_vector>::get_size()
        {
            return this->_size;
        }

        template <class data_type_vector>
        Vector<data_type_vector>::
        ~Vector()
        {
            delete [] this->data;
        }

        template <class data_type_matrix>
        data_type_matrix**  Matrix<data_type_matrix>::
        _reserve_space(unsigned int _rows, unsigned int _cols)
        {
            check(_rows > 0, "Number of rows should be positive.");
            check(_cols > 0, "Number of cols should be positive.");
            data_type_matrix** new_data = new data_type_matrix*[_rows];
            for(unsigned int i = 0; i < _rows; i++)
            {
                new_data[i] = new data_type_matrix[_cols];
            }
            return new_data;
        }

        template <class data_type_matrix>
        Matrix<data_type_matrix>::
        Matrix(unsigned int _rows, unsigned int _cols):
        data(_reserve_space(_rows, _cols)),
        rows(_rows),
        cols(_cols)
        {
        }

        template <class data_type_matrix>
        void Matrix<data_type_matrix>::
        product(const Matrix<data_type_matrix>& mat,
                Matrix<data_type_matrix>& result)
        {
            check(this->get_cols() == mat.get_rows(),
                          "Order of matrices don't match.");
            unsigned int common_cols = this->get_cols();
            for(unsigned int i = 0; i < result.get_rows(); i++)
            {
                for(unsigned int j = 0; j < result.get_cols(); j++)
                {
                    result[i][j] = 0;
                    for(unsigned int k = 0; k < common_cols; k++)
                    {
                        result[i][j] += (this->at(i, k)*mat.at(k, j));
                    }
                }
            }
        }

        template <class data_type_matrix>
        data_type_matrix Matrix<data_type_matrix>::
        at(unsigned int x, unsigned int y)
        {
            check(x > 0 && x < this->get_rows(),
                          "Row index out of range.");
            check(y > 0 && y < this->get_cols(),
                          "Column index out of range.");
            return this->data[rows][cols];
        }

        template <class data_type_matrix>
        void Matrix<data_type_matrix>::
        set(data_type_matrix value,
            unsigned int x,
            unsigned int y)
        {
            check(x > 0 && x < this->get_rows(),
                          "Row index out of range.");
            check(y > 0 && y < this->get_cols(),
                          "Column index out of range.");
            this->data[rows][cols] = value;
        }

        template <class data_type_matrix>
        unsigned int Matrix<data_type_matrix>::
        get_rows()
        {
            return this->rows;
        }

        template <class data_type_matrix>
        unsigned int Matrix<data_type_matrix>::
        get_cols()
        {
            return this->cols;
        }

        template <class data_type_matrix>
        Matrix<data_type_matrix>::
        ~Matrix()
        {
            for(unsigned int i = 0; i < this->_rows; i++)
            {
                delete [] this->data[i];
            }
        }

    } // namespace core
} // namespace adaboost

#endif
