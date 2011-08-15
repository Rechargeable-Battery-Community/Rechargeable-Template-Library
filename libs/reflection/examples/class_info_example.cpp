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

#include <rtl/reflection/class_info.hpp>
#include <iostream>
using namespace rtl;

namespace
{
	class_info A("A",  0);
	class_info B("B", &A);
	class_info C("C", &A);

	void is_exactly(const class_info& class1, const class_info& class2)
	{
		if (class1.is_exactly(class2))
			std::cout << class1.name() << " is exactly " << class2.name() << std::endl;
		else
			std::cout << class1.name() << " is not exactly " << class2.name() << std::endl;
	}

	void is_derived(const class_info& class1, const class_info& class2)
	{
		if (class1.is_derived(class2))
			std::cout << class1.name() << " is derived " << class2.name() << std::endl;
		else
			std::cout << class1.name() << " is not derived " << class2.name() << std::endl;
	}

}

int main()
{
	is_exactly(A, A);
	is_exactly(B, A);
	is_exactly(C, A);
	is_exactly(C, B);

	is_derived(A, A);
	is_derived(B, A);
	is_derived(C, A);
	is_derived(C, B);
}
