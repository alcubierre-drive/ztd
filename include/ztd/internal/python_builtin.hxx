/**
 * Copyright (C) 2023 Brandon Zorn <brandonzorn@cock.li>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <https://www.gnu.org/licenses/>.
 */

#pragma once

#include <algorithm>
#include <tuple>
#include <vector>

#include "types.hxx"

namespace ztd
{
    /**
     * @brief Sorted
     *
     * - Sort containers
     *
     * @param[in] container The container to sort
     * @param[in] reverse The returned container will be reversed
     *
     * @return a new sorted container from the items in container
     */
    constexpr auto
    sorted(auto&& container, bool reverse = false)
    {
        std::ranges::sort(container);
        if (reverse)
        {
            std::ranges::reverse(container);
        }
        return container;
    };

    /**
     * @brief enumerate
     *
     * - iterate over a container with index values
     *
     * @param[in] container The container to iterate over
     *
     * @return [index, value]
     */
    template<typename T, typename Iter = decltype(std::cbegin(std::declval<T>())),
             typename = decltype(std::cend(std::declval<T>()))>
    constexpr auto
    enumerate(T&& container)
    {
        struct iterator
        {
            usize i;
            Iter iter;

            bool
            operator!=(const iterator& other) const
            {
                return iter != other.iter;
            }

            void
            operator++()
            {
                ++i;
                ++iter;
            }

            auto
            operator*() const
            {
                return std::tie(i, *iter);
            }
        };

        struct iterable_wrapper
        {
            T container;

            auto
            begin()
            {
                return iterator{0, std::cbegin(container)};
            }

            auto
            end()
            {
                return iterator{0, std::cend(container)};
            }
        };

        return iterable_wrapper{std::forward<T>(container)};
    }

    /**
     * @brief range
     *
     * - a sequence of integers
     *
     * @param[in] stop The ending value, not inclusive, starts at zero
     *
     * @return a sequence of integers to be iterated over
     */
    const std::vector<i64> range(i64 stop);

    /**
     * @brief range
     *
     * - a sequence of integers
     *
     * @param[in] start The starting value, inclusive
     * @param[in] stop The ending value, not inclusive
     * @param[in] step increment to increase by, must not be zero,
     * if is zero throws std::invalid_argument.
     *
     * @return a sequence of integers to be iterated over
     */
    const std::vector<i64> range(i64 start, i64 stop, i64 step = 1);
} // namespace ztd
