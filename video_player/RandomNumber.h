#pragma once

#include <random>
#include <functional>


class RandomNumber
{

public:
	RandomNumber() = default;
    RandomNumber(double min, double max);
    RandomNumber(int min, int max);
    
    double get_random_double();
    double get_random_double(const double& min, const double& max);
    int get_random_int();
    int get_random_int(const int& min, const int& max);
    size_t get_random_size_t(const size_t& min, const size_t& max);
   /* auto createRandomGenerator(const double& min, const double& max)
    {
        std::random_device seeder;
        std::default_random_engine generator{ seeder() };
        std::uniform_real_distribution distribution{ min, max };
        auto final_value{ std::bind(distribution, generator) };
        distribution.reset();
        return final_value;
    }
    double& random_double(const double& min, const double& max)
    {
        static auto random{ createRandomGenerator(min, max) };
        auto random_value{ random() };
        return random_value;
    }*/


private:
    double m_min_double{};
    double m_max_double{};
    int m_min_int{};
    int m_max_int{};

    std::random_device m_seeder;
    std::default_random_engine m_generator;
    std::default_random_engine m_engine;
    std::uniform_real_distribution<double> m_double_distribution;
    std::uniform_int_distribution<int> m_int_distribution;

    auto createRandomDoubleBinding();
    auto createRandomIntGenerator();
    
};

