#ifndef ADABOOST_CORE_DATA_STRUCTURES_HPP
#define ADABOOST_CORE_DATA_STRUCTURES_HPP

namespace adaboost
{
    namespace core
    {
        template <class data_type_matrix>
        class Matrix;

        template <class data_type_vector>
        class Vector
        {
            private:

                data_type_vector *data;

                unsigned int size;

                static data_type_vector*
                _reserve_space(unsigned int _size);

            public:

                Vector();

                Vector(unsigned int _size);

                void product(const Vector<data_type_vector>& vec,
                             data_type_vector& result);

                void product(const Matrix<data_type_vector>& mat,
                             Vector<data_type_vector>& result);

                data_type_vector at(unsigned int index);

                void set(data_type_vector value,
                         unsigned int index);

                unsigned int get_size();

                ~Vector();

        };

        template <class data_type_matrix>
        class Matrix
        {
            private:

                unsigned int rows, cols;

                data_type_matrix **data;

                static data_type_matrix**
                _reserve_space(unsigned int _rows,
                               unsigned int _cols);

            public:

                Matrix();

                Matrix(unsigned int _rows,
                        unsigned int _cols);

                void product(const Matrix<data_type_matrix>& mat,
                             Matrix<data_type_matrix>& result);

                data_type_matrix at(unsigned int x,
                                    unsigned int y);

                void set(data_type_matrix value,
                        unsigned int x,
                        unsigned int y);

                unsigned int get_rows();

                unsigned int get_cols();

                ~Matrix();
        };
    } // namespace core
} // namespace adaboost

#include "data_structures_impl.hpp"

#endif
