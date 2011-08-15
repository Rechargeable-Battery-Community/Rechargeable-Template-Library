/**
 * \file class_info.hpp
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

#ifndef RECHARGEABLE_CLASS_INFO_HPP_INCLUDED
#define RECHARGEABLE_CLASS_INFO_HPP_INCLUDED

namespace rtl
{
	/**
	 * Contains class information.
	 *
	 * Holds runtime type information on a class.
	 *
	 * \author Don Olmstead
	 * \version 0.1
	 */
	class class_info
	{
		public:

			/**
			 * Initializes an instance of the class_info class.
			 *
			 * \param name The name of the class.
			 * \param base The base class of the instance.
			 */
			class_info(const char* name, const class_info* base);

			/**
			 * Gets the name of the class.
			 *
			 * \returns The name of the class.
			 */
			inline const char* name() const
			{
				return _name;
			}

			/**
			 * Determines if the class is exactly the same as the given class_info.
			 *
			 * \param type The class_info instance to compare against.
			 * \returns \b true \b if the instance's are the same; \b false \b otherwise.
			 */
			inline bool is_exactly(const class_info& type) const
			{
				return &type == this;
			}

			/**
			 * Determines if the instance is derived from the given class_info.
			 *
			 * Traverses the hierarchy to determine if the instance is derived from the
			 * given class_info.
			 *
			 * \param type The class_info instance to compare against.
			 * \returns \b true \b if the instance derives from the class; \b false \b otherwise.
			 */
			bool is_derived(const class_info& type) const;

		private:

			/// Pointer to the base class
			const class_info* _base;
			/// The name of the class
			const char* _name;

	} ; // end class class_info

} // end namespace rtl

#endif // end RECHARGEABLE_CLASS_INFO_HPP_INCLUDED
