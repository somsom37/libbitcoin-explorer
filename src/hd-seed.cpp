/**
 * Copyright (c) 2011-2014 sx developers (see AUTHORS)
 *
 * This file is part of sx.
 *
 * sx is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License with
 * additional permissions to the one published by the Free Software
 * Foundation, either version 3 of the License, or (at your option)
 * any later version. For more information see LICENSE.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */
#include <iostream>
#include <wallet/wallet.hpp>
#include <sx/command/hd-seed.hpp>
#include <sx/serializer/hd_private.hpp>
#include <sx/utility/console.hpp>

using namespace libwallet;
using namespace sx;
using namespace sx::extension;
using namespace sx::serializer;

// TODO: test
console_result hd_seed::invoke(std::istream& input, std::ostream& output,
    std::ostream& cerr)
{
    // Bound parameters.
    data_chunk seed = get_seed_argument();
    const bool testnet = get_general_testnet_setting();

    const size_t fill_seed_size = 32;
    if (seed.size() == 0)
        seed = random_fill(fill_seed_size);

    const hd_private_key private_key(seed, testnet);

    std::cout << hd_private(private_key) << std::endl;
    return console_result::okay;
}

