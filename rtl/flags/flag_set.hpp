/**
 * \file flag_set.hpp
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

#ifndef RECHARGEABLE_FLAG_SET_HPP_INCLUDED
#define RECHARGEABLE_FLAG_SET_HPP_INCLUDED

#include <rtl/flags/detail/bit_union.hpp>

namespace rtl
{
	template <typename Enum, std::int32_t Size, typename Names>
	class flag_set
	{
		private:

			static const std::int32_t Bits = (((Size + 7) & ~7) >> 3) * 8;

		public:

			typedef detail::bit_union<Bits, Names> union_type;
			typedef detail::bit_set<Bits> container_type;

			/**
			 * Creates an instance of the flag_set class.
			 *
			 * All flags are initially cleared.
			 */
			flag_set()
			{
				clear_bit_set(_set);
			}

			flag_set(std::uint8_t value)
			{
				static_assert(Bits == 8, "The underlying container is not a uint8_t");

				set_bit_values(_set, value);
			}

			flag_set(std::uint16_t value)
			{
				static_assert(Bits == 16, "The underlying container is not a uint16_t");

				set_bit_values(_set, value);
			}

			flag_set(std::uint32_t value)
			{
				static_assert(Bits == 16, "The underlying container is not a uint32_t");

				set_bit_values(_set, value);
			}


			inline operator std::uint8_t() const
			{
				return get_bit_values(_set);
			}

			inline operator std::uint16_t() const
			{
				return get_bit_values(_set);
			}

			void set(Enum flag)
			{
				set_bit(_set, flag);
			}

			void set_values(std::uint8_t values)
			{
				set_bit_values(_set, values);
			}

			void set_values(std::uint16_t values)
			{
				set_bit_values(_set, values);
			}

			void clear(Enum flag)
			{
				clear_bit(_set, flag);
			}

			void toggle(Enum flag)
			{
				toggle_bit(_set, flag);
			}

			bool is_set(Enum flag) const
			{
				return is_bit_set(_set, flag);
			}

		private:

		#ifdef RECHARGEABLE_USE_BIT_UNION
			union_type _set;
		#else
			container_type _set;
		#endif

	} ; // end class flag_set<Enum>

} // end namespace rtl

#endif // end RECHARGEABLE_FLAG_SET_HPP_INCLUDED
