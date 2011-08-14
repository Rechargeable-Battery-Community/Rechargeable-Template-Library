/**
 * \file bit_set.hpp
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

#ifndef RECHARGEABLE_DETAIL_BIT_SET_HPP_INCLUDED
#define RECHARGEABLE_DETAIL_BIT_SET_HPP_INCLUDED

#include <rtl/flags/detail/config.hpp>

namespace rtl { namespace detail
{
	//----------------------------------------------------------------------
	// Generic collection
	//----------------------------------------------------------------------

	/**
	 * Stores a collection of bits.
	 *
	 * \author Don Olmstead
	 * \version 0.1
	 */
	template <std::int32_t Bits>
	struct bit_set
	{
		private:

			/// The size of the underlying array
			static const std::int32_t __arraySize = ((Bits + 7) & ~7) >> 3;

		public:

			/**
			 * Gets the size of the underlying array.
			 *
			 * \returns The size of the underlying array.
			 */
			static std::int32_t size()
			{
				return __arraySize;
			}

			/// The container holding the bits
			std::uint8_t _bit_array[__arraySize];

	} ; // end struct bit_set<Bits>

	/**
	 * Initializes the bit container.
	 *
	 * \tparam Bits The number of bits in the container.
	 * \param set The collection of bits.
	 */
	template <std::int32_t Bits>
	inline void clear_bit_set(bit_set<Bits>& set)
	{
		const std::int32_t size = bit_set<Bits>::size();

		for (std::int32_t i = 0; i < size; ++i)
			set._bit_array[i] = 0;
	}

	/**
	 * Sets the bit at the given location.
	 *
	 * \tparam Bits The number of bits in the container.
	 * \param set The collection of bits.
	 * \param location The bit to set.
	 */
	template <std::int32_t Bits>
	inline void set_bit(bit_set<Bits>& set, std::int32_t location)
	{
		RECHARGEABLE_ASSERT((location >= 0) && (location < Bits), "Invalid location");

		const std::int32_t index = (((location + 8) & ~7) >> 3) - 1;
		const std::int32_t bit = location - (8 * index);

		// Set the bit
		set._bit_array[index] |= (1 << bit);
	}

	/**
	 * Clears the bit at the given location.
	 *
	 * \tparam Bits The number of bits in the container.
	 * \param set The collection of bits.
	 * \param location The bit to clear.
	 */
	template <std::int32_t Bits>
	inline void clear_bit(bit_set<Bits>& set, std::int32_t location)
	{
		RECHARGEABLE_ASSERT((location >= 0) && (location < Bits), "Invalid location");

		const std::int32_t index = (((location + 8) & ~7) >> 3) - 1;
		const std::int32_t bit = location - (8 * index);

		// Clear the bit
		set._bit_array[index] &= ~(1 << bit);
	}

	/**
	 * Toggles the bit at the given location.
	 *
	 * \tparam Bits The number of bits in the container.
	 * \param set The collection of bits.
	 * \param location The bit to clear.
	 */
	template <std::int32_t Bits>
	inline void toggle_bit(bit_set<Bits>& set, std::int32_t location)
	{
		RECHARGEABLE_ASSERT((location >= 0) && (location < Bits), "Invalid location");

		const std::int32_t index = (((location + 8) & ~7) >> 3) - 1;
		const std::int32_t bit = location - (8 * index);

		// Clear the bit
		set._bit_array[index] ^= (1 << bit);
	}

	/**
	 * Queries whether a bit is set
	 *
	 * \tparam Bits The number of bits in the container.
	 * \param set The collection of bits.
	 * \param location The bit to query.
	 */
	template <std::int32_t Bits>
	inline bool is_bit_set(const bit_set<Bits>& set, std::int32_t location)
	{
		RECHARGEABLE_ASSERT((location >= 0) && (location < Bits), "Invalid location");

		const std::int32_t index = (((location + 8) & ~7) >> 3) - 1;
		const std::int32_t bit = location - (8 * index);

		// Check the bit
		const std::int32_t mask = (1 << bit);
		return (set._bit_array[index] & mask) == mask;
	}

	//----------------------------------------------------------------------
	// Function macros
	//
	// The specializations of the bit_set class use built in types
	// rather than a byte array. The code for all these specializations
	// is the same so macros are used to create the implementations.
	//----------------------------------------------------------------------

	/**
	 * Creates the clear_bit_set function for a template specialization.
	 *
	 * \param N The number of bits.
	 */
	#define RECHARGEABLE_CLEAR_BIT_SET(N) \
	template <> \
	inline void clear_bit_set(bit_set<N>& set) \
	{ \
		set._bit_array = 0; \
	}

	/**
	 * Creates the set_bit function for a template specialization.
	 *
	 * \param N The number of bits.
	 */
	#define RECHARGEABLE_SET_BIT(N) \
	template <> \
	inline void set_bit(bit_set<N>& set, std::int32_t location) \
	{ \
		RECHARGEABLE_ASSERT((location >= 0) && (location < N), "Invalid location"); \
		\
		set._bit_array |= (1 << location); \
	}

	/**
	 * Creates the clear_bit function for a template specialization.
	 *
	 * \param N The number of bits.
	 */
	#define RECHARGEABLE_CLEAR_BIT(N) \
	template <> \
	inline void clear_bit(bit_set<N>& set, std::int32_t location) \
	{ \
		RECHARGEABLE_ASSERT((location >= 0) && (location < N), "Invalid location"); \
		\
		set._bit_array &= ~(1 << location); \
	}

	/**
	 * Creates the toggle_bit function for a template specialization.
	 *
	 * \param N The number of bits.
	 */
	#define RECHARGEABLE_TOGGLE_BIT(N) \
	template <> \
	inline void toggle_bit(bit_set<N>& set, std::int32_t location) \
	{ \
		RECHARGEABLE_ASSERT((location >= 0) && (location < N), "Invalid location"); \
		\
		set._bit_array ^= (1 << location); \
	}

	/**
	 * Creates the is_bit_set function for a template specialization.
	 *
	 * \param N The number of bits.
	 */
	#define RECHARGEABLE_IS_BIT_SET(N) \
	template <> \
	inline bool is_bit_set(const bit_set<N>& set, std::int32_t location) \
	{ \
		RECHARGEABLE_ASSERT((location >= 0) && (location < N), "Invalid location"); \
		\
		const std::int32_t mask = (1 << location); \
		return (set._bit_array & mask) == mask; \
	}

	#define RECHARGEABLE_SET_VALUE(N, Type) \
	inline void set_bit_values(bit_set<N>& set, Type value) \
	{ \
		set._bit_array = value; \
	}

	#define RECHARGEABLE_GET_VALUE(N, Type) \
	inline Type get_bit_values(const bit_set<N>& set) \
	{ \
		return set._bit_array; \
	}

	//----------------------------------------------------------------------
	// 8-bit implementation
	//----------------------------------------------------------------------

	template <>
	struct bit_set<8>
	{
		public:

			/**
			 * Gets the size of the underlying array.
			 *
			 * \returns The size of the underlying array.
			 */
			static std::int32_t size()
			{
				return 1;
			}

			/// The container holding the bits
			std::uint8_t _bit_array;

	} ; // end struct bit_set<8>

	RECHARGEABLE_CLEAR_BIT_SET(8)
	RECHARGEABLE_SET_BIT(8)
	RECHARGEABLE_CLEAR_BIT(8)
	RECHARGEABLE_TOGGLE_BIT(8)
	RECHARGEABLE_IS_BIT_SET(8)
	RECHARGEABLE_SET_VALUE(8, std::uint8_t)
	RECHARGEABLE_GET_VALUE(8, std::uint8_t)

	//----------------------------------------------------------------------
	// 16-bit implementation
	//----------------------------------------------------------------------

	template <>
	struct bit_set<16>
	{
		public:

			/**
			 * Gets the size of the underlying array.
			 *
			 * \returns The size of the underlying array.
			 */
			static std::int32_t size()
			{
				return 2;
			}

			/// The container holding the bits
			std::uint16_t _bit_array;

	} ; // end struct bit_set<16>

	RECHARGEABLE_CLEAR_BIT_SET(16)
	RECHARGEABLE_SET_BIT(16)
	RECHARGEABLE_CLEAR_BIT(16)
	RECHARGEABLE_TOGGLE_BIT(16)
	RECHARGEABLE_IS_BIT_SET(16)
	RECHARGEABLE_SET_VALUE(16, std::uint16_t)
	RECHARGEABLE_GET_VALUE(16, std::uint16_t)

	//----------------------------------------------------------------------
	// 32-bit implementation
	//----------------------------------------------------------------------

	template <>
	struct bit_set<32>
	{
		public:

			/**
			 * Gets the size of the underlying array.
			 *
			 * \returns The size of the underlying array.
			 */
			static std::int32_t size()
			{
				return 4;
			}

			/// The container holding the bits
			std::uint32_t _bit_array;

	} ; // end struct bit_set<32>

	RECHARGEABLE_CLEAR_BIT_SET(32)
	RECHARGEABLE_SET_BIT(32)
	RECHARGEABLE_CLEAR_BIT(32)
	RECHARGEABLE_TOGGLE_BIT(32)
	RECHARGEABLE_IS_BIT_SET(32)
	RECHARGEABLE_SET_VALUE(32, std::uint32_t)
	RECHARGEABLE_GET_VALUE(32, std::uint32_t)

} } // end namespace rtl::detail

#endif // end RECHARGEABLE_DETAIL_BIT_SET_HPP_INCLUDED
