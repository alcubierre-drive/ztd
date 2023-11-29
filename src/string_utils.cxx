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

#include <string_view>

#include <span>

#include <algorithm>
#include <ranges>

#include "ztd/internal/types.hxx"

#include "ztd/internal/string_utils.hxx"

i32
ztd::compare(const std::string_view str1, const std::string_view str2) noexcept
{
    return str1.compare(str2);
}

bool
ztd::contains(const std::string_view str, const std::string_view sub) noexcept
{
    return str.contains(sub);
}

bool
ztd::contains(const std::string_view str, const std::string_view sub, usize start, usize end) noexcept
{
    if (start >= end)
    {
        return false;
    }
    return str.substr(start, end).contains(sub);
}

bool
ztd::contains(const std::string_view str, const std::span<const std::string_view> subs) noexcept
{
    const auto check = [str](const std::string_view sub) { return str.contains(sub); };
    return std::ranges::any_of(subs, check);
}

bool
ztd::contains(const std::string_view str, const std::span<const std::string> subs) noexcept
{
    const auto check = [str](const std::string_view sub) { return str.contains(sub); };
    return std::ranges::any_of(subs, check);
}

struct __contains_fn
{
    template<std::input_iterator I, std::sentinel_for<I> S,
             class T, class Proj = std::identity>
    requires std::indirect_binary_predicate<std::ranges::equal_to, std::projected<I, Proj>,
                                            const T*>
    constexpr bool operator()(I first, S last, const T& value, Proj proj = {}) const
    {
        return std::ranges::find(std::move(first), last, value, proj) != last;
    }

    template<std::ranges::input_range R, class T, class Proj = std::identity>
    requires std::indirect_binary_predicate<std::ranges::equal_to,
                                            std::projected<std::ranges::iterator_t<R>, Proj>,
                                            const T*>
    constexpr bool operator()(R&& r, const T& value, Proj proj = {}) const
    {
        return (*this)(std::ranges::begin(r), std::ranges::end(r), std::move(value), proj);
    }
};
inline constexpr __contains_fn ztd_contains {};

bool
ztd::contains(const std::span<const std::string> subs, const std::string_view str) noexcept
{
    return ztd_contains(subs, str);
}

bool
ztd::contains(const std::span<const std::string_view> subs, const std::string_view str) noexcept
{
    return ztd_contains(subs, str);
}

bool
ztd::same(const std::string_view str1, const std::string_view str2) noexcept
{
    return (str1.compare(str2) == 0);
}
