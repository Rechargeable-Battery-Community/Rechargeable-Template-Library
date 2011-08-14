/**
 * \file bit_union.hpp
 * 
 * \section COPYRIGHT
 *
 * Rechargeable Template Library
 *
 * ---------------------------------------------------------------------
 *
 * Copyright (c) 2011, Don Olmstead
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *  1. Redistributions of source code must retain the above copyright notice,
 *     this list of conditions and the following disclaimer.
 *
 *  2. Redistributions in binary form must reproduce the above copyright notice,
 *     this list of conditions and the following disclaimer in the documentation
 *     and/or other materials provided with the distribution.
 *
 *  3. Neither the name of organization nor the names of its contributors may be
 *     used to endorse or promote products derived from this software without
 *     specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO
 * EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef RECHARGEABLE_DETAIL_BIT_UNION_HPP_INCLUDED
#define RECHARGEABLE_DETAIL_BIT_UNION_HPP_INCLUDED

#include <rtl/flags/detail/bit_set.hpp>

namespace rtl { namespace detail
{
	template <std::int32_t Bits, typename Names>
	struct bit_union
	{
		public:

			typedef bit_set<Bits> container_type;
			typedef Names name_type;

			union
			{
				container_type _rep;
				name_type _names;
			} ;

	} ; // end class bit_union<Bits, Names>

	/**
	 * Initializes the bit container.
	 *
	 * \tparam Bits The number of bits in the container.
	 * \tparam Names The debug names.
	 * \param set The collection of bits.
	 */
	template <std::int32_t Bits, typename Names>
	inline void clear_bit_set(bit_union<Bits, Names>& set)
	{
		clear_bit_set(set._rep);
	}

	/**
	 * Sets the bit at the given location.
	 *
	 * \tparam Bits The number of bits in the container.
	 * \tparam Names The debug names.
	 * \param set The collection of bits.
	 * \param location The bit to set.
	 */
	template <std::int32_t Bits, typename Names>
	inline void set_bit(bit_union<Bits, Names>& set, std::int32_t location)
	{
		set_bit(set._rep, location);
	}

	/**
	 * Clears the bit at the given location.
	 *
	 * \tparam Bits The number of bits in the container.
	 * \tparam Names The debug names.
	 * \param set The collection of bits.
	 * \param location The bit to clear.
	 */
	template <std::int32_t Bits, typename Names>
	inline void clear_bit(bit_union<Bits, Names>& set, std::int32_t location)
	{
		clear_bit(set._rep, location);
	}

	/**
	 * Toggles the bit at the given location.
	 *
	 * \tparam Bits The number of bits in the container.
	 * \tparam Names The debug names.
	 * \param set The collection of bits.
	 * \param location The bit to clear.
	 */
	template <std::int32_t Bits, typename Names>
	inline void toggle_bit(bit_union<Bits, Names>& set, std::int32_t location)
	{
		toggle_bit(set._rep, location);
	}

	/**
	 * Queries whether a bit is set
	 *
	 * \tparam Bits The number of bits in the container.
	 * \tparam Names The debug names.
	 * \param set The collection of bits.
	 * \param location The bit to query.
	 */
	template <std::int32_t Bits, typename Names>
	inline bool is_bit_set(const bit_union<Bits, Names>& set, std::int32_t location)
	{
		return is_bit_set(set._rep, location);
	}

	//----------------------------------------------------------------------
	// 8-bit implementation
	//----------------------------------------------------------------------

	template <typename Names>
	inline void set_bit_values(bit_union<8, Names>& set, std::uint8_t value)
	{
		set_bit_values(set._rep, value);
	}

	template <typename Names>
	inline std::uint8_t get_bit_values(const bit_union<8, Names>& set)
	{
		return get_bit_values(set._rep);
	}

	//----------------------------------------------------------------------
	// 16-bit implementation
	//----------------------------------------------------------------------

	template <typename Names>
	inline void set_bit_values(bit_union<16, Names>& set, std::uint16_t value)
	{
		set_bit_values(set._rep, value);
	}

	template <typename Names>
	inline std::uint16_t get_bit_values(const bit_union<16, Names>& set)
	{
		return get_bit_values(set._rep);
	}

} } // end namespace rtl::detail

#endif // end RECHARGEABLE_DETAIL_BIT_UNION_HPP_INCLUDED
