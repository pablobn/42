#include "Serializer.hpp"

int	main()
{
	Data data;
	uintptr_t raw = Serializer::serialize(&data);
	Data *ptr = Serializer::deserialize(raw);

	data.name = "Manuel";
	data.age = 17;

	std::cout << "Serializer = " << raw << std::endl;
	std::cout << "Deserializer =  " << ptr << std::dec << std::endl;
	std::cout << "data.name = " << data.name << " data.age =  " << data.age << std::endl;
	std::cout << "ptr->name = " << ptr->name << " ptr->age =  " << ptr->age << std::endl;

	return(0);
}