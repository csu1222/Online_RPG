#pragma once
#include <random>
#include <string>
class Utils
{
public:
	template<typename T>
	static T GetRandom(T min, T max)
	{
		// 시드값을 얻기 위한 random_device 생성
		std::random_device randomDevice;
		// random_device 를 통해 난수 생성 엔진을 초기화 한다.
		std::mt19937 generator(randomDevice());
		// 균등하게 나타나는 난수열을 생성하기 위해 균등 분포 정의

		if constexpr (std::is_integral_v<T>)
		{
			std::uniform_int_distribution<T> distribution(min, max);
			return distribution(generator);
		}
		else
		{
			std::uniform_real_distribution<T> distribution(min, max);
			return distribution(generator);
		}
	}

	static std::string FloatToString(float value)
	{
		std::string str = std::to_string(value);
		return str;
	}

	static float CalculateDistance(float x1, float y1, float x2, float y2)
	{
		return std::sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
	}
};