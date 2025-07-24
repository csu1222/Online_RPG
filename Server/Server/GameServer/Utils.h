#pragma once
#include <random>
#include <string>
class Utils
{
public:
	template<typename T>
	static T GetRandom(T min, T max)
	{
		// �õ尪�� ��� ���� random_device ����
		std::random_device randomDevice;
		// random_device �� ���� ���� ���� ������ �ʱ�ȭ �Ѵ�.
		std::mt19937 generator(randomDevice());
		// �յ��ϰ� ��Ÿ���� �������� �����ϱ� ���� �յ� ���� ����

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