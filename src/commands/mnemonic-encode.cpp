/**
 * Copyright (c) 2011-2014 libbitcoin developers (see AUTHORS)
 *
 * This file is part of libbitcoin-explorer.
 *
 * libbitcoin-explorer is free software: you can redistribute it and/or
 * modify it under the terms of the GNU Affero General Public License with
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

#include <bitcoin/explorer/commands/mnemonic-encode.hpp>

#include <iostream>
#include <string>
#include <bitcoin/bitcoin.hpp>
#include <bitcoin/explorer/define.hpp>

using namespace bc;
using namespace bc::explorer;
using namespace bc::explorer::commands;

console_result mnemonic_encode::invoke(std::ostream& output,
    std::ostream& error)
{
    // Bound parameters.
    const data_chunk& seed = get_seed_argument();

    if (seed.size() < minimum_seed_size)
    {
        error << BX_EC_MNEMONIC_ENCODE_SHORT_SEED << std::endl;
        return console_result::failure;
    }

    // TODO: change implementation from Electrum to BIP39.

    const auto sentence = join(encode_mnemonic(seed));

    output << sentence << std::endl;
    return console_result::okay;
}

