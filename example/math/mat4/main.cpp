#include <cstdlib>
#include <functional>
#include <fstream>

#include "math/constant.hpp"
#include "math/vec3.hpp"
#include "math/mat3.hpp"
#include "math/mat4.hpp"

#include <random>

int main(void)
{
    std::mt19937_64 engine;
    std::uniform_real_distribution<float> distribution(0.0f, 1.0f);
    auto random = std::bind(distribution, engine);
    // s_bias.open("bias.txt", std::fstream::out);
    std::fstream write;

    write.open("mat4.txt", std::fstream::out);

    float angle1 = random();
    float angle2 = random();

    mat4 m0 = rotate(pi(1.0f) * angle1, vec3(0.0f, 1.0f, 0.0f));
    mat4 m1 = rotate(pi(0.5f) * angle2, vec3(0.0f, 1.0f, 0.0f));

    mat4 m2 = m0 * m1;

    for (size_t i = 0; i < 16; i++)
    {
        write << m2[i] << std::endl;
    }

    write.close();
}
