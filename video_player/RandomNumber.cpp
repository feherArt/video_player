//#include "stdafx.h"
#include "RandomNumber.h"

RandomNumber::RandomNumber(double min, double max) : m_min_double{ min }, m_max_double{ max },
m_double_distribution{ m_min_double, m_max_double }, m_generator{ m_seeder() }
{
  
}

RandomNumber::RandomNumber(int min, int max) : m_min_int{min}, m_max_int{max}
{


}



double RandomNumber::get_random_double()
{
    std::random_device seeder;
    std::default_random_engine generator{ seeder() };
    std::uniform_real_distribution distribution{ m_min_double, m_max_double };
    double random_double_value{ distribution(generator) };
    return random_double_value;
}

double RandomNumber::get_random_double(const double& min, const double& max)
{
    std::random_device seeder;
    std::default_random_engine generator{ seeder() };
    std::uniform_real_distribution distribution{ min, max};
    double random_double_value{ distribution(generator) };
    return random_double_value;
    
}

int RandomNumber::get_random_int()
{
    std::random_device seeder;
    std::default_random_engine generator{ seeder() };
    std::uniform_int_distribution distribution{ m_min_int, m_max_int };
    int random_int_value{ distribution(generator) };
    return random_int_value;

}

int RandomNumber::get_random_int(const int& min, const int& max)
{
    std::random_device seeder;
    std::default_random_engine generator{ seeder() };
    std::uniform_int_distribution distribution{ min, max };
    int random_int_value{ distribution(generator) };
    return random_int_value;
}

size_t RandomNumber::get_random_size_t(const size_t& min, const size_t& max)
{
    std::random_device seeder;
	std::default_random_engine generator{ seeder() };
	std::uniform_int_distribution<size_t> distribution{ min, max };
	size_t random_size_t_value{ distribution(generator) };
	return random_size_t_value;
}
