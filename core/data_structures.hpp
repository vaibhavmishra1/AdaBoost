#ifndef ADABOOST_CORE_DATA_STRUCTURES_HPP
#define ADABOOST_CORE_DATA_STRUCTURES_HPP

namespace adaboost
{
    namespace core
    {
        template <class data_type_matrix2d>
        class Matrix2D;

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

                void product(const Vector& vec,
                            unsigned int& result);

                void product(const Matrix2D& vec,
                            unsigned int& result);

                data_type_vector at(unsigned int index);

                void set(data_type_vector value,
                        unsigned int index);

                unsigned int get_size();

                ~Vector();

        };

        template <class data_type_matrix2d>
        class Matrix2D
        {
            private:

                unsigned int rows, cols;

                data_type_matrix2d **data;

                static data_type_matrix2d**
                _reserve_space(unsigned int _rows,
                               unsigned int _cols);

            public:

                Matrix2D();

                Matrix2D(unsigned int _rows,
                        unsigned int _cols);

                void product(const Matrix2D& mat,
                            Matrix2D int& result);

                data_type_matrix2d at(unsigned int x,
                                    unsigned int y);

                void set(data_type_matrix2d value,
                        unsigned int x,
                        unsigned int y);

                unsigned int get_rows();

                unsigned int get_cols();

                ~Matrix2D();
        };
    } // namespace core
} // namespace adaboost

#include "data_structures_impl.hpp"

#endif
