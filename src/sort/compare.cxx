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

#include <filesystem>

#include "ztd/internal/types.hxx"

#include "ztd/internal/string_utils.hxx"

#include "ztd/internal/sort/compare.hxx"

i64
ztd::sort::compare(const std::string_view l, const std::string_view r) noexcept
{
    return ztd::compare(l, r);
}

i64
ztd::sort::filesystem::compare(const std::filesystem::path& l, const std::filesystem::path& r) noexcept
{
    return ztd::compare(l.string(), r.string());
}
