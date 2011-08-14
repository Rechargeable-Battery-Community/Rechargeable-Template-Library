#include <rtl/flags.hpp>

namespace Test
{
	enum Type
	{
		Test1,
		Test2,
		Test3,
		Size
	} ;

	struct Names
	{
		std::uint32_t Test1:1;
		std::uint32_t Test2:1;
		std::uint32_t Test3:1;
	} ;
} ;

int main()
{
	std::uint8_t testing = 2;
	rtl::flag_set<Test::Type, Test::Size, Test::Names> flags(testing);

	flags.set(Test::Test1);
	flags.set(Test::Test3);

	std::uint8_t value = flags;
}
