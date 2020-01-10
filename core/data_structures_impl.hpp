#ifndef ADABOOST_CORE_DATA_STRUCTURES_IMPL_HPP
#define ADABOOST_CORE_DATA_STRUCTURES_IMPL_HPP

namespace adaboost
{
    namespace core
    {
        template <class data_type_vector>
        Vector::Vector()
        {}

        template <class data_type_vector>
        Vector::_reserve_space(unsigned int _size)
        {
            static_assert(_size > 0,
            "The size of the vector should be positive.");
            data_type_vector* pointer = new data_type_vector(_size);
            return pointer;
        }

        template <class data_type_vector>
        Vector::Vector(unsigned int _size):
        data(_reserve_space(_size)),
        size(_size)
        {
        }
    } // namespace core
} // namespace adaboost

#endif
